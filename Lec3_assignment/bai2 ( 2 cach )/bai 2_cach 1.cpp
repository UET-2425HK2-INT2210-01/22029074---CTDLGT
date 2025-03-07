#include <iostream>
using namespace std;

double bitleft(int n){
    double result;
    if (n>=0){
        result = 1 <<n;
    } else {
        result = 1 << -(n);
        result = 1/result;
    }
    return result;
}

int main(){
    int n;
    cin >> n;
    cout << bitleft(n);
    return 0;
}

// Ma gia:
// HÀM bitleft(n)
//     Khai báo bien result ki?u s? th?c
//     N?u n >= 0
//         result = 1 d?ch trái n bit
//     Ngý?c l?i
//         result = 1 d?ch trái |n| bit
//         result = 1 / result
//     Tr? v? result

// CHÝÕNG TR?NH CHÍNH
//     Khai báo bi?n n ki?u s? nguyên
//     Nh?p n t? ngý?i dùng
//     Hi?n th? k?t qu? c?a hàm bitleft(n)
//     K?t thúc chýõng tr?nh

// Ð? ph?c t?p thu?t toán O(1).
