#include <iostream>
#include <vector>
#include <chrono> // Untuk mengukur waktu eksekusi

using namespace std;
using namespace std::chrono;

// 1. Constant Time - O(1)
// Waktu eksekusi tetap sama, berapapun jumlah datanya.
void constantTime(int arr[]) {
    int element = arr[0]; // Hanya mengambil elemen pertama
    cout << "O(1) - Elemen pertama: " << element << endl;
}

// 2. Linear Time - O(n)
// Waktu eksekusi bertambah secara linear sesuai jumlah data.
void linearTime(int n) {
    long long counter = 0;
    for (int i = 0; i < n; i++) {
        counter++;
    }
    cout << "O(n) selesai untuk n = " << n << endl;
}

// 3. Quadratic Time - O(n^2)
// Sering ditemukan pada nested loop (loop di dalam loop).
void quadraticTime(int n) {
    long long counter = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            counter++;
        }
    }
    cout << "O(n^2) selesai untuk n = " << n << endl;
}

int main() {
    int n;
    cout << "Masukkan jumlah data (n): ";
    cin >> n;

    int arr[] = {10, 20, 30, 40, 50};

    // Mengukur O(1)
    auto start = high_resolution_clock::now();
    constantTime(arr);
    auto stop = high_resolution_clock::now();
    cout << "Waktu: " << duration_cast<microseconds>(stop - start).count() << " ms\n\n";

    // Mengukur O(n)
    start = high_resolution_clock::now();
    linearTime(n);
    stop = high_resolution_clock::now();
    cout << "Waktu: " << duration_cast<microseconds>(stop - start).count() << " ms\n\n";

    // Mengukur O(n^2)
    // Hati-hati: jika n terlalu besar (misal 100.000), ini akan sangat lama!
    if (n <= 10000) {
        start = high_resolution_clock::now();
        quadraticTime(n);
        stop = high_resolution_clock::now();
        cout << "Waktu: " << duration_cast<microseconds>(stop - start).count() << " ms\n\n";
    } else {
        cout << "n terlalu besar untuk O(n^2) simulasi.\n";
    }

    return 0;
}
