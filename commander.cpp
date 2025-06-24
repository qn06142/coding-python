#include <iostream>
#include <opencv2/opencv.hpp>
#include <deque>
#include <thread>
#include <chrono>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

using namespace std;
using namespace cv;

const string host           = "0.0.0.0";
const int    port           = 8000;
const int    target_width   = 160;
const int    target_height  = 160;
const int    colred         = 16;

void clear_line(int n = 1) {
    for (int i = 0; i < n; ++i) {
        cout << "\033[1A" << "\x1b[2K";
    }
}

/// Scale to fit, then center-pad into a target_w × target_h canvas
Mat resize_and_pad_centered(const Mat& img, int target_w, int target_h) {
    float scale = min(float(target_h) / img.rows, float(target_w) / img.cols);
    Size  new_size(int(ceil(img.cols * scale)), int(ceil(img.rows * scale)));

    Mat small;
    resize(img, small, new_size);

    Mat canvas = Mat::zeros(target_h, target_w, img.type());
    int x = (target_w  - small.cols) / 2;
    int y = (target_h - small.rows) / 2;
    small.copyTo(canvas(Rect(x, y, small.cols, small.rows)));

    return canvas;
}

/// Compute pixel-wise difference, then threshold on the gray channel
vector<Point> get_diff_pixels(const Mat& ref_img, const Mat& curr_img) {
    Mat diff_color, diff_gray, diff_bin;
    absdiff(ref_img, curr_img, diff_color);
    cvtColor(diff_color, diff_gray, COLOR_BGR2GRAY);
    threshold(diff_gray, diff_bin, 1, 255, THRESH_BINARY);

    vector<Point> pts;
    for (int y = 0; y < diff_bin.rows; ++y) {
        for (int x = 0; x < diff_bin.cols; ++x) {
            if (diff_bin.at<uchar>(y, x))
                pts.emplace_back(x, y);
        }
    }
    return pts;
}

void draw(int x, int y, int col, int /*count*/, deque<string>& buffer) {
    buffer.push_back(
      "DRAW\n" +
      to_string(x) + "\n" +
      to_string(y) + "\n" +
      to_string(col) + "\n"
    );
}

void flushbuffer(deque<string>& buffer, int sock) {
    for (auto& msg : buffer)
        send(sock, msg.c_str(), msg.size(), 0);
    buffer.clear();
    send(sock, "FLSH", 4, 0);
}

int rgbtohex(const Vec3b& color, int colred) {
    int r = (color[2] / colred) * colred;
    int g = (color[1] / colred) * colred;
    int b = (color[0] / colred) * colred;
    return (r << 16) | (g << 8) | b;
}

int main() {
    // --- Socket setup ---
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        cerr << "Failed to create socket!\n";
        return -1;
    }

    sockaddr_in server_addr{};
    server_addr.sin_family      = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(host.c_str());
    server_addr.sin_port        = htons(port);

    if (bind(server_socket, (sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        cerr << "Bind failed!\n";
        return -1;
    }
    if (listen(server_socket, 5) < 0) {
        cerr << "Listen failed!\n";
        return -1;
    }

    int client_socket = accept(server_socket, nullptr, nullptr);
    if (client_socket < 0) {
        cerr << "Accept failed!\n";
        return -1;
    }

    // --- Open video ---
    VideoCapture cap("/home/wheatley/Alohaii - Heart Of Glass (feat. Rachie) [Music Video] [f6FRYyOYNhA].webm");
    if (!cap.isOpened()) {
        cerr << "Error opening video stream!\n";
        return -1;
    }

    // --- Prepare ---
    Mat ref = Mat::zeros(target_height, target_width, CV_8UC3);
    Mat frame, resized_frame;
    deque<string> buffer;
    int count = 0;

    // Send resolution info
    string res_msg = "RESO" + to_string(target_width) + "\n"
                   + to_string(target_height) + "\n";
    send(client_socket, res_msg.c_str(), res_msg.size(), 0);

    // --- Main loop ---
    while (true) {
        auto t0 = chrono::high_resolution_clock::now();
        if (!cap.read(frame) || frame.empty())
            break;

        // 1) resize & letterbox
        resized_frame = resize_and_pad_centered(frame, target_width, target_height);

        // 2) diff against last frame
        auto diff_indices = get_diff_pixels(ref, resized_frame);

        // 3) enqueue DRAW commands
        for (auto& p : diff_indices) {
            Vec3b color = resized_frame.at<Vec3b>(p);
            int   col   = rgbtohex(color, colred);
            draw(p.x, p.y, col, count++, buffer);
        }

        // 4) send them
        flushbuffer(buffer, client_socket);

        // 5) fps throttle + display in console
        auto t1 = chrono::high_resolution_clock::now();
        double frame_time   = chrono::duration<double>(t1 - t0).count();
        double target_time  = 1.0 / cap.get(CAP_PROP_FPS);
        if (frame_time < target_time)
            this_thread::sleep_for(chrono::duration<double>(target_time - frame_time));

        double actual_fps = 1.0 / frame_time;
        double err        = actual_fps - cap.get(CAP_PROP_FPS);
        clear_line();
        cout << "Actual FPS: " << actual_fps
             << ", Error Rate: " << err << endl;

        // 6) update reference
        ref = resized_frame.clone();
    }

    send(client_socket, "END ", 4, 0);
    close(client_socket);
    close(server_socket);
    return 0;
}
