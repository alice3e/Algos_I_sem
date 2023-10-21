//
// Created by alicee on 02.10.2023.
//
//main.cpp
#include <iomanip>
#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <string>
#ifdef _WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif
// Вывод ull в норм формате: cout << (LLD , a);
using namespace std;
typedef long long ll;
typedef vector<long long> vec;
static const char space = ' ';
//Consts
#define PI 3.1415926535897932384626433832795l
const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e10;

vec generateRandomVector(int n) {
    vec randomVector;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> distribution(0, n * n * n - 1);

    for (int i = 0; i < n; i++) {
        ll random_number = distribution(gen);
        if(random_number<0) random_number *= -1;
        randomVector.push_back(random_number);
    }
    return randomVector;
}

void print_int_v(vector<ll> &v) {
    for (auto i: v) {
        cout << i << ' ';
    }
    cout << endl;
}

// Функция для нахождения максимальной цифры в числе
int getMaxDigit(int num) {
    int maxDigit = 0;
    while (num > 0) {
        int digit = num % 10;
        if (digit > maxDigit) {
            maxDigit = digit;
        }
        num /= 10;
    }
    return maxDigit;
}

// Функция для сортировки вектора с использованием сортировки по разрядам
void radixSort(vec& arr, int maxElement) {
    int maxDigit = getMaxDigit(maxElement);

    for (int exp = 1; maxElement / exp > 0; exp *= 10) {
        int n = arr.size();
        vector<int> output(n);
        vector<int> count(10, 0);

        for (int i = 0; i < n; i++) {
            count[(arr[i] / exp) % 10]++;
        }

        for (int i = 1; i < 10; i++) {
            count[i] += count[i - 1];
        }

        for (int i = n - 1; i >= 0; i--) {
            output[count[(arr[i] / exp) % 10] - 1] = arr[i];
            count[(arr[i] / exp) % 10]--;
        }

        for (int i = 0; i < n; i++) {
            arr[i] = output[i];
        }
    }
}

// Функция для сравнения времени выполнения двух других функций
void time_test(auto &v, void (*test_srt)(vec &x,const int max_el)){

    const auto start_std{chrono::steady_clock::now()};
    auto vec_stdsort = v;
    sort(vec_stdsort.begin(), vec_stdsort.end());
    const auto end_std{chrono::steady_clock::now()};
    const chrono::duration<double> elapsed_seconds_std{end_std - start_std};

    ll max_el = v.size()*v.size()*v.size()-1;
    const auto start_f{chrono::steady_clock::now()};
    test_srt(v, max_el);
    const auto end_f{chrono::steady_clock::now()};
    const chrono::duration<double> elapsed_seconds_f{end_f - start_f};
    if(v==vec_stdsort){
        cout<<"TEST SORT == STD::SORT" << endl;
        cout <<"sort time is equal to: " << elapsed_seconds_std.count()  << " seconds"<< endl;
        cout <<  "Test_sort time is equal to: " << elapsed_seconds_f.count() << " seconds" << endl;

        // Conclusion
        if(elapsed_seconds_std < elapsed_seconds_f){
            double speedup = elapsed_seconds_f / elapsed_seconds_std;
            cout << "sort is " << speedup << " times faster than Test_sort." << endl;
            cout << "sort is " << speedup*100 << "% faster than Test_sort." << endl;
        }else{
            double speedup = elapsed_seconds_std / elapsed_seconds_f;
            cout << "Test_sort is " << speedup << " times faster than Test_sort." << endl;
            cout << "Test_sort is " << speedup*100 << "% faster than Test_sort." << endl;
        }
    }else{
        cout<<"ERROR IN TEST OR STD SORT" << endl;
    }

}



int main() {
    // CPP SPEEDUP
    setlocale(LC_ALL, "Russian");
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // MAIN MAIN
    // ВСЕ ПИШЕМ В ll иначе тесты не проходит
    vec init_arr;
    init_arr = generateRandomVector(100);
    print_int_v(init_arr);
    time_test(init_arr,radixSort);
    return 0;
}