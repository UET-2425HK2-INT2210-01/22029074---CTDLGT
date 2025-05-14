#include <bits/stdc++.h> 
using namespace std; 

void quickSort(vector<double>& arr, int left, int right) {
    int i = left, j = right; // i và j là hai chỉ số dùng để quét từ hai đầu đoạn [left, right]
    double pivot = arr[(left + right) / 2]; // Chọn phần tử ở giữa làm chốt (pivot)

    // Phân đoạn mảng sao cho phần tử nhỏ hơn pivot nằm bên trái, lớn hơn nằm bên phải
    while (i <= j) {
        while (arr[i] < pivot) i++; // Di chuyển i sang phải đến khi gặp phần tử >= pivot
        while (arr[j] > pivot) j--; // Di chuyển j sang trái đến khi gặp phần tử <= pivot
        if (i <= j) {
            swap(arr[i], arr[j]); // Đổi chỗ hai phần tử sai vị trí
            i++; j--;             // Tiếp tục quét các phần còn lại
        }
    }

    // Đệ quy sắp xếp hai phần của mảng (trái và phải của pivot)
    if (left < j) quickSort(arr, left, j);   // Sắp xếp đoạn bên trái
    if (i < right) quickSort(arr, i, right); // Sắp xếp đoạn bên phải
}

int main() {
    int n;
    cin >> n;

    vector<double> numbers(n); // Tạo vector chứa n số thực
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }

    quickSort(numbers, 0, n - 1);

    for (size_t i = 0; i < numbers.size(); ++i) {
        cout << fixed << setprecision(6) 
             << numbers[i]               
             << (i < n - 1 ? " " : "\n"); 
    }

    return 0;
}