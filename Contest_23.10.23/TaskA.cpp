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

void input_v(vec &v){
    int x;
    for(int i = 0; i < v.size(); i++){
        cin >> x;
        v[i] = x;
    }
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





int main() {
    // CPP SPEEDUP
    setlocale(LC_ALL, "Russian");
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // MAIN MAIN
    // ВСЕ ПИШЕМ В ll иначе тесты не проходит
    int t;
    cin >> t;
    for(int k = 0; k < t; k++){
        int n;
        cin >> n;
        vec v(n);
        input_v(v);
        sort(v.begin(),v.end());
        if(n==1)cout<<"YES"<<endl;
        else{
            int counter = 1; // тк последний не удаляется
            for(int i = 0; i < n-1;i++){
                if(abs(v[i] - v[i+1]) > 1){
                    counter += 1;
                }
            }
            if(counter == 1){
                cout << "YES" << endl;
            }else cout << "NO" << endl;
        }
    }
    return 0;
}