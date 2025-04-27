#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, s, t;
    cin >> N >> M >> s >> t; 

    vector<vector<int>> graph(N + 1);
    for (int i = 0; i < M; i++){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }

    for (int i = 1; i <= N; i++){
        sort(graph[i].begin(), graph[i].end());
    }

    vector<bool> visited(N + 1, false);
    vector<int> parent(N + 1, -1);
    queue<int> q;

    int source = s; 
    visited[source] = true;
    parent[source] = -1; 
    q.push(source);

    bool found = false;
    while (!q.empty()){
        int current = q.front();
        q.pop();

        if (current == t){
            found = true;
            break;  
        }

        for (int next : graph[current]){
            if (!visited[next]){
                visited[next] = true;
                parent[next] = current;
                q.push(next);
            }
        }
    }

    if (!found){
        cout << "No path" << "\n";
        return 0;
    }

    vector<int> path;
    for (int cur = t; cur != -1; cur = parent[cur]){
        path.push_back(cur);
    }

    reverse(path.begin(), path.end());

    for (int i = 0; i < path.size(); i++){
        cout << path[i] << (i < path.size() - 1 ? " " : "\n");
    }

    return 0;
}