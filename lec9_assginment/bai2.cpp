#include <iostream>
#include <vector>
using namespace std;

bool checkSum(vector<int>& ages, int X) {
    vector<bool> dp(X + 1, false); // Khởi tạo mảng 
    dp[0] = true;
    
    for (int age : ages) { // Duyệt từng tuổi trong danh sách
        for (int j = X; j >= age; j--) { // Duyệt tùng phần tử trong mảng
            if (dp[j - age]) {
                dp[j] = true; // Câp nhật lại mảng 
            }
        }
    }
    
    return dp[X]; // Trả về true nếu tồn tại tập con có tổng bằng X
}

int main() {
    int n, X;
    cin >> n >> X;
    vector<int> ages(n);
    
    for (int i = 0; i < n; i++) {
        cin >> ages[i];
    }
    
    if (checkSum(ages, X)) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    
    return 0;
}