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
    ll n;
    cin >> n;
    vector <pair<ll,ll> > v(n);
    vector <pair<ll,ll> > v_copy(n);
    for(ll i = 0;i < n;i++){
        pair <ll,ll> x;
        cin >> x.first >> x.second;
        v[i] = x;
        v_copy[i] = x;
    }
    std::sort(v.begin(), v.end(), comparepair);
    //print_pair_v(v);
    ll l=INF,r=-1;
    for(ll i = 0;i < n;i++){
        if(v[i].first < l) l = v[i].first;
        if(v[i].second > r) r = v[i].second;
    }
    //cout << l << " " << r << endl << endl;
    //print_pair_v(v_copy);
    for(ll i = 0;i < n;i++){
        ll l_i = v_copy[i].first;
        ll r_i = v_copy[i].second;
        if(l_i <= l && r_i >= r){
            //cout << "ANS: " << l_i << " " << r_i << endl;
            cout << i + 1;
            return 0;
        }
    }
    cout << -1;
    return 0;
}

/*
7
1 5
2 3
1 10
7 20
7 7
10 10
10 15
*/