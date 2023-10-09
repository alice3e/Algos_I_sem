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
const ll INF = 1e9;

std::vector<int> inp(int vec_size) {
    std::vector<int> v(vec_size);
    for (int i = 0; i < vec_size; i++) {
        std::cin >> v[i];
    }
    return v;
}

void out(std::vector<int> &v) {
    for (auto i: v) {
        std::cout << i << ' ';
    }
    std::cout << std::endl;
}


int main() {
    // CPP SPEEDUP
    setlocale(LC_ALL, "Russian");
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    // MAIN MAIN
    int n;
    cin >> n;
    int num_elem = 0,level = 0;
    while(num_elem <= n){
        level += 1;
        num_elem = ((1 + level)*level)/2;
        n -= num_elem;
        //cout << num_elem << space << level << space << n << endl;
    }
    cout << level;

    return 0;
}