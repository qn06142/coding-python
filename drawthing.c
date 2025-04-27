#include <SDL2/SDL.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HOST "127.0.0.1"
#define PORT 8000
#define RECV_BUFFER_SIZE 8192

int main(int argc, char* argv[]) {
    /* 1. Setup TCP connection to server */
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) { perror("socket"); return EXIT_FAILURE; }
    struct sockaddr_in serv_addr = {0};
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    if (inet_pton(AF_INET, HOST, &serv_addr.sin_addr) <= 0) { perror("inet_pton"); return EXIT_FAILURE; }
    if (connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect");
        return EXIT_FAILURE;
    }

    /* 2. Receive initial resolution from server: "RESO <width> <height>" */
    char recvbuf[RECV_BUFFER_SIZE];
    int len = recv(sock, recvbuf, sizeof(recvbuf) - 1, 0);
    if (len <= 0) { perror("recv"); return EXIT_FAILURE; }
    recvbuf[len] = '\0';

    int width = 0, height = 0;
    float hf;
    if (sscanf(recvbuf, "RESO %d %d", &width, &height) < 2) {
        if (sscanf(recvbuf, "RESO %d %f", &width, &hf) == 2) {
            height = (int)hf;
        } else {
            fprintf(stderr, "Invalid RESO message: %s\n", recvbuf);
            return EXIT_FAILURE;
        }
    }
    printf("Server resolution: %dx%d\n", width, height);

    /* 3. Initialize SDL and create window/surface */
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        fprintf(stderr, "SDL_Init Error: %s\n", SDL_GetError());
        return EXIT_FAILURE;
    }
    SDL_Window* window = SDL_CreateWindow(
        "SDL Network Drawing",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        width, height, 0
    );
    if (!window) {
        fprintf(stderr, "SDL_CreateWindow Error: %s\n", SDL_GetError());
        return EXIT_FAILURE;
    }
    SDL_Surface* surface = SDL_GetWindowSurface(window);
    if (!surface) {
        fprintf(stderr, "SDL_GetWindowSurface Error: %s\n", SDL_GetError());
        return EXIT_FAILURE;
    }

    /* 4. Main loop: read commands until "FLSH", draw pixels, then ACK with "DONE" */
    char command_buf[RECV_BUFFER_SIZE * 4] = {0};
    int command_len = 0;

    while (1) {
        /* Read until we see FLSH or END */
        int mode = 0;
        while (!mode) {
            len = recv(sock, recvbuf, sizeof(recvbuf) - 1, 0);
            if (len <= 0) goto cleanup;
            recvbuf[len] = '\0';
            if (command_len + len >= sizeof(command_buf)) {
                fprintf(stderr, "Command buffer overflow\n");
                goto cleanup;
            }
            memcpy(command_buf + command_len, recvbuf, len + 1);
            command_len += len;

            if (strstr(command_buf, "FLSH")) mode = 1;
            else if (strstr(command_buf, "END")) mode = 2;
        }

        /* Handle END: exit loop */
        if (mode == 2) {
            send(sock, "BYE", 3, 0);
            break;
        }

        /* Tokenize and process DRAW commands */
        char* saveptr;
        char* token = strtok_r(command_buf, " ", &saveptr);
        while (token) {
            if (strcmp(token, "DRAW") == 0) {
                char* xs = strtok_r(NULL, " ", &saveptr);
                char* ys = strtok_r(NULL, " ", &saveptr);
                char* cols = strtok_r(NULL, " ", &saveptr);
                if (!xs || !ys || !cols) break;

                int x = atoi(xs);
                int y = atoi(ys);
                unsigned int col = (unsigned int)strtoul(cols, NULL, 10);

                /* Map server color to SDL pixel format */
                Uint8 r = (col >> 0) & 0xFF;
                Uint8 g = (col >> 8) & 0xFF;
                Uint8 b = (col >> 16) & 0xFF;
                Uint32 pixel = SDL_MapRGB(surface->format, r, g, b);

                /* Draw to surface's pixel buffer directly */
                if (x >= 0 && x < surface->w && y >= 0 && y < surface->h) {
                    Uint32* pixels = (Uint32*)surface->pixels;
                    pixels[y * surface->w + x] = pixel;
                }

            } else if (strcmp(token, "FLSH") == 0) {
                break;
            }
            token = strtok_r(NULL, " ", &saveptr);
        }

        /* Update window and acknowledge */
        SDL_UpdateWindowSurface(window);
        send(sock, "DONE", 4, 0);

        /* Remove processed portion up to FLSH */
        char* p = strstr(command_buf, "FLSH");
        if (p) {
            int tail = command_len - (p - command_buf) - 4;
            memmove(command_buf, p + 4, tail);
            command_len = tail;
            command_buf[command_len] = '\0';
        } else {
            command_len = 0;
            command_buf[0] = '\0';
        }

        /* Handle SDL events to allow window closing */
        SDL_Event e;
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) goto cleanup;
        }
    }

cleanup:
    SDL_DestroyWindow(window);
    SDL_Quit();
    close(sock);
    return 0;
}

/*
 * Compilation:
 *   gcc sdl_client.c -o sdl_client $(sdl2-config --cflags --libs)
 * Usage:
 *   ./sdl_client
 */
