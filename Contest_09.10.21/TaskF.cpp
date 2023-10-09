//
// Created by alicee on 02.10.2023.
//
//main.cpp
#include <iomanip>
#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include<stdio.h>

#ifdef _WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif


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
    unsigned long long n;
    cin >> n;
    unsigned long long a = ((pow(2, n/2)) * (n % 2 == 0));
    cout << (LLD , a);
    return 0;
}