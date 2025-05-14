#include <iostream>
#include <vector>
using namespace std;

int knapsack(int n, int X, vector<pair<int, int>>& items) {
    vector<int> dp(X + 1, 0); 

    for (auto& item : items) { // Duyệt từng vật phẩm
        int w = item.first;
        int v = item.second;
        for (int j = X; j >= w; j--) { // Duyệt ngược từ X về w
            if (dp[j - w] + v > dp[j]) { // So sánh giá trị mới và cũ
                dp[j] = dp[j - w] + v; // Cập nhật nếu tốt hơn
            }
        }
    }
    return dp[X]; // Trả về giá trị lớn nhất
}

int main() {
    int n, X;
    cin >> n >> X;
    vector<pair<int, int>> items(n);

    for (int i = 0; i < n; i++) {
        cin >> items[i].first >> items[i].second;
    }

    cout << knapsack(n, X, items);
    return 0;
}