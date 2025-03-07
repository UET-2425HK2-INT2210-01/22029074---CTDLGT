#include <iostream>
using namespace std;

long long power_iterative(int N) {
    long long result = 1; // Kh?i t?o k?t qu? l� 1
    for (int i = 1; i <= N; i++) {
        result *= 2; // Nh�n d?n v?i 2
    }
    return result;
}

int main() {
    int N;
    cin >> N;
    cout << power_iterative(N);
    return 0;
}


// M� GI?:
// H�M power_iterative(N)
//     KHAI B�O result = 1
//     L?P i t? 1 d?n N
//         result = result * 2
//     TR? V? result

// CHUONG TR�NH CH�NH
//     NH?P N
//     HI?N TH? power_iterative(N)


// �? ph?c t?p thu?t to�n O(log(n)).
