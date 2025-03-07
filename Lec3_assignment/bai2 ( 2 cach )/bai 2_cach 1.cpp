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
// H�M bitleft(n)
//     Khai b�o bien result ki?u s? th?c
//     N?u n >= 0
//         result = 1 d?ch tr�i n bit
//     Ng�?c l?i
//         result = 1 d?ch tr�i |n| bit
//         result = 1 / result
//     Tr? v? result

// CH��NG TR?NH CH�NH
//     Khai b�o bi?n n ki?u s? nguy�n
//     Nh?p n t? ng�?i d�ng
//     Hi?n th? k?t qu? c?a h�m bitleft(n)
//     K?t th�c ch��ng tr?nh

// �? ph?c t?p thu?t to�n O(1).
