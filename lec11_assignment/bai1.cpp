#include <iostream>
#include <fstream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

const int INF = INT_MAX / 2;

void bellmanFord(int n, int s, vector<vector<pair<int, int>>>& adj, vector<int>& dist, vector<int>& prev) {
    dist.assign(n + 1, INF); // Khởi tạo mảng khoảng cách
    prev.assign(n + 1, -1); // Khởi tạo mảng truy vết 
    dist[s] = 0;
    
    for (int i = 1; i <= n - 1; i++) { // Lặp 
        for (int u = 1; u <= n; u++) { // Duyệt từng đỉnh đã có khoảng cách
            if (dist[u] == INF) continue;
            for (auto& edge : adj[u]) { // Duyệt từng cạnh từ danh sách kề 
                int v = edge.first; 
                int w = edge.second; // Đỉnh và trọng số
                if (dist[v] > dist[u] + w) { // Cập nhật nếu khoảng cách đến v qua u ngắn hơn
                    dist[v] = dist[u] + w;
                    prev[v] = u; // Lưu đỉnh để truy vết
                }
            }
        }
    }
}

void floydWarshall(int n, vector<vector<int>>& dist) {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dist[i][k] < INF && dist[k][j] < INF) { // Lấy k làm đỉnh trung gian
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]); // So sánh và cập nhật khoảng cách i và j 
                }
            }
        }
    }
}

vector<int> reconstructPath(int s, int e, const vector<int>& prev) {
    vector<int> path; // Mảng lưu đường đi
    for (int v = e; v != -1; v = prev[v]) {
        path.push_back(v); // Truy vết ngược từ e
    }
    reverse(path.begin(), path.end()); // Đảo ngược mảng 
    if (path[0] != s) return {};
    return path;
}

int main() {
    ifstream fin("dirty.txt");
    ofstream fout("dirty.out");
    int n, m, s, e;
    fin >> n >> m >> s >> e;

    vector<vector<pair<int, int>>> adj(n + 1); // Khai báo ma trận kề
    vector<vector<int>> dist(n + 1, vector<int>(n + 1, INF)); // Khởi tạo ma trận khoảng cách 
    for (int i = 1; i <= n; ++i) {
        dist[i][i] = 0;
    }
    for (int i = 0; i < m; ++i) {
        int u, v, d;
        fin >> u >> v >> d;
        adj[u].push_back({v, d}); // Cập nhật cạnh 
        dist[u][v] = d; // Cập nhật khoảng cách 
    }
    
    // Task a
    vector<int> dist_bf, prev;
    bellmanFord(n, s, adj, dist_bf, prev); // Gọi BellmanFord
    if (dist_bf[e] == INF) {
        fout << "INF\n";
    } else {
        fout << dist_bf[e] << "\n";
    }
    
    vector<int> path = reconstructPath(s, e, prev); // Truy vêt đường đi
    if (path.empty()) {
        fout << "No path\n";
    } else {
        for (size_t i = 0; i < path.size(); i++) {
            if (i > 0) fout << " ";
            fout << path[i];
        }
        fout << "\n";
    }
    
    // Task b
    floydWarshall(n, dist); // Gọi FloydWarshall
    
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (j > 1) fout << " ";
            if (dist[i][j] == INF) {
                fout << "INF";
            } else {
                fout << dist[i][j];
            }
        }
        fout << "\n";
    }
    
    fin.close();
    fout.close();
    return 0;
}