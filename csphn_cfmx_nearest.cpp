#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cstdlib>
using namespace std;

struct Point {
    int x, y;
    int idx;
};

struct Node {
    Point pt;
    Node* left;
    Node* right;
    int minX, maxX, minY, maxY;  
};

inline int manhattan(const Point &a, const Point &b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

inline int boxDistance(const Point &query, const Node* node) {
    if (!node) return INT_MAX;
    int dx = 0, dy = 0;
    if(query.x < node->minX) dx = node->minX - query.x;
    else if(query.x > node->maxX) dx = query.x - node->maxX;
    if(query.y < node->minY) dy = node->minY - query.y;
    else if(query.y > node->maxY) dy = query.y - node->maxY;
    return dx + dy;
}

Node* buildKDTree(vector<Point>::iterator begin, vector<Point>::iterator end, int depth) {
    if (begin >= end) return nullptr;
    auto mid = begin + (end - begin) / 2;

    if(depth % 2 == 0) {
        nth_element(begin, mid, end, [](const Point &a, const Point &b) {
            return a.x < b.x;
        });
    } else {
        nth_element(begin, mid, end, [](const Point &a, const Point &b) {
            return a.y < b.y;
        });
    }
    Node* node = new Node;
    node->pt = *mid;
    node->left  = buildKDTree(begin, mid, depth + 1);
    node->right = buildKDTree(mid + 1, end, depth + 1);

    node->minX = node->maxX = node->pt.x;
    node->minY = node->maxY = node->pt.y;
    if(node->left) {
        node->minX = min(node->minX, node->left->minX);
        node->maxX = max(node->maxX, node->left->maxX);
        node->minY = min(node->minY, node->left->minY);
        node->maxY = max(node->maxY, node->left->maxY);
    }
    if(node->right) {
        node->minX = min(node->minX, node->right->minX);
        node->maxX = max(node->maxX, node->right->maxX);
        node->minY = min(node->minY, node->right->minY);
        node->maxY = max(node->maxY, node->right->maxY);
    }
    return node;
}

void kdSearch(Node* node, const Point &query, int depth, int &bestDist, int &bestIdx) {
    if (node == nullptr) return;

    int d = manhattan(query, node->pt);
    if (query.idx != node->pt.idx && d < bestDist) {
        bestDist = d;
        bestIdx = node->pt.idx;
    }

    Node* first = nullptr;
    Node* second = nullptr;
    if (depth % 2 == 0) {  
        if (query.x < node->pt.x) {
            first = node->left;
            second = node->right;
        } else {
            first = node->right;
            second = node->left;
        }
    } else {  
        if (query.y < node->pt.y) {
            first = node->left;
            second = node->right;
        } else {
            first = node->right;
            second = node->left;
        }
    }

    kdSearch(first, query, depth + 1, bestDist, bestIdx);
    if (second) {
        int dbox = boxDistance(query, second);
        if (dbox < bestDist)
            kdSearch(second, query, depth + 1, bestDist, bestIdx);
    }
}

void freeTree(Node* node) {
    if (!node) return;
    freeTree(node->left);
    freeTree(node->right);
    delete node;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<Point> points(n);
    for (int i = 0; i < n; i++){
        cin >> points[i].x >> points[i].y;
        points[i].idx = i; 
    }

    vector<Point> pts = points;
    Node* root = buildKDTree(pts.begin(), pts.end(), 0);

    vector<int> ans(n, -1);
    for (int i = 0; i < n; i++){
        int bestDist = INT_MAX;
        int bestIdx = -1;
        kdSearch(root, points[i], 0, bestDist, bestIdx);
        ans[points[i].idx] = bestIdx + 1;  
    }

    for (int i = 0; i < n; i++){
        cout << ans[i] << " ";
    }
    cout << "\n";

    freeTree(root);
    return 0;
}