#include <iostream>
using namespace std;

long long power_iterative(int N) {
    long long result = 1; // Kh?i t?o k?t qu? là 1
    for (int i = 1; i <= N; i++) {
        result *= 2; // Nhân d?n v?i 2
    }
    return result;
}

int main() {
    int N;
    cin >> N;
    cout << power_iterative(N);
    return 0;
}


// MÃ GI?:
// HÀM power_iterative(N)
//     KHAI BÁO result = 1
//     L?P i t? 1 d?n N
//         result = result * 2
//     TR? V? result

// CHUONG TRÌNH CHÍNH
//     NH?P N
//     HI?N TH? power_iterative(N)


// Ð? ph?c t?p thu?t toán O(log(n)).
