#include "Addons.hpp"
/*
 За линию (3 балла)
    ▶ Выполните сортировку для массива A, состоящего из n чисел, принадлежащих интервалу от 0 до n3 − 1 за время O(n).
    ▶ Для инициализации массива используйте std::uniform_int_distribution
 */

int UnformDistributionNumber(int min, int max) {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<> dis(min, max);
    return dis(mt);
}

void UnformDistributionArray(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = UnformDistributionNumber(0, n * n * n - 1);
    }
}

void countSort(int *arr, int arr_size, int exp) {
    int res_out[arr_size];

    int count[arr_size];
    for (int i = 0; i < arr_size; i++) count[i] = 0;

    for (int i = 0; i < arr_size; i++)
        count[(arr[i] / exp) % arr_size]++;

    for (int i = 1; i < arr_size; i++)
        count[i] += count[i - 1];


    for (int i = arr_size - 1; i >= 0; i--) {
        res_out[count[(arr[i] / exp) % arr_size] - 1] = arr[i];
        count[(arr[i] / exp) % arr_size]--;
    }


    for (int i = 0; i < arr_size; i++)
        arr[i] = res_out[i];
}

void radixsort(int *arr, int n) {
    // Вместо 10-разрядной системы счисления используем n-разрядную
    for (int exp = 1; exp <= n * n; exp *= n) {
        cout << "EXPONENT : " << exp << endl;
        countSort(arr, n, exp);
    }
}

int main() {
    // CPP SPEEDUP
    setlocale(LC_ALL, "Russian");
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    // MAIN MAIN

    // IN TEST CASE I WILL USE 128 INSTEAD OF 1024 IN arr_size
    int arr_size = UnformDistributionNumber(1, 128); // uint32 - 32 bits -> sqrt3(2^32-1) = 1024*1.6 ~ 1024
    int arr[arr_size];

    UnformDistributionArray(arr, arr_size);
    cout << "UNSORTED: ";
    print(arr, arr_size);
    cout << endl;
    radixsort(arr, arr_size);
    cout << "SORTED:   ";
    print(arr, arr_size);
    cout << endl;
    return 0;
}