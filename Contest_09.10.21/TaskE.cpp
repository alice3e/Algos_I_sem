//
// Created by alicee on 02.10.2023.
//
//main.cpp
#include <iomanip>
#include <iostream>
#include <vector>
#include <random>
#include <algorithm>


typedef long long ll;
typedef std::vector<int> vec;
using namespace std;
static const char space = ' ';
//Consts
#define PI 3.1415926535897932384626433832795l
const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e10;

vector<ll> inp(ll vec_size) {
    std::vector<ll> v(vec_size);
    for (int i = 0; i < vec_size; i++) {
        std::cin >> v[i];
    }
    return v;
}

void out(std::vector<ll> &v) {
    for (auto i: v) {
        std::cout << i << ' ';
    }
    std::cout << std::endl;
}

int factorial(ll n){
    if(n == 0){
        return 1;
    }
    else return factorial(n-1) * n;
}

int main() {
    // CPP SPEEDUP
    setlocale(LC_ALL, "Russian");
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    // MAIN MAIN
    // ВСЕ ПИШЕМ В ll иначе тесты не проходит
    long long n, min_quantity = 0, max_quantity = 0, diff, number, k;
    int mn = INT_MAX, mx = 0;
    cin >> n;
    vector <int> v;
    for (int i = 0; i < n; i++){
        cin >> k;
        v.push_back(k);
        mn = min(mn, v[i]);
        mx = max(mx, v[i]);

    }
    for (int i = 0; i < n; i++){
        if (v[i] == mx)
            max_quantity = max_quantity + 1;
        if (v[i] == mn)
            min_quantity = min_quantity + 1;
    }


    diff = mx - mn;
    if (mx == mn)
        number = n * (n - 1) / 2;
    else
        number = min_quantity * max_quantity;
    cout << diff << " " << number;

    return 0;
}