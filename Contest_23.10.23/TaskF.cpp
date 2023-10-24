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

void print_pair_v(vector <pair<ll,ll> > &v) {
    for (auto i: v) {
        cout << i.first << ' ' << i.second << endl;
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

bool comparepair(const pair<int,int> &a, const pair<int,int> &b) {
    if (a.first == b.first) {
        return a.second < b.second; // Если длины равны, сравниваем строки лексикографически
    }
    return a.first < b.first; // Сначала сравниваем длины строк
}



int main() {
    // CPP SPEEDUP
    setlocale(LC_ALL, "Russian");
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // MAIN MAIN
    // ВСЕ ПИШЕМ В ll иначе тесты не проходит
    ll n,m;
    cin >> n >> m;
    vec v(n);
    input_v(v);
    for(int k = 0;k<m;k++){
        ll left_ind,right_ind,elem_ind, l_max = 0, r_min = 0,elem = 0;
        cin >> left_ind >> right_ind >> elem_ind;
        left_ind -= 1; right_ind -= 1; elem_ind -= 1;
        elem = v[elem_ind];
        for(int i = left_ind;i < elem_ind;i++){
            if(v[i] > elem) l_max += 1;
        }
        for(int i = elem_ind + 1;i < right_ind + 1;i++){
            if(v[i] < elem) r_min += 1;
        }
        //cout << "l_max: " << l_max << " | r_min: " << r_min << endl;
        if(abs(r_min - l_max) == 0) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}
