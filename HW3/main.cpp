//
// Created by alicee on 02.10.2023.
//
//main.cpp
#include <iomanip>
#include <iostream>
#include <vector>
#include <random>

typedef long long ll;
typedef std::vector<int> vec;

//Consts
#define PI 3.1415926535897932384626433832795l
const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

// FUNC DECLARATION
void merge_rec(std::vector<int> &v, int left, int right);

void rnd_v(std::vector<int> &out, int sz, int max_el_size);
std::vector<int> inp(int vec_size);

void out(std::vector<int> &v);

void merger(vec &v, int left, int middle, int right);

void rnd_v(std::vector<int> &out, int sz, int max_el_size) { // max_el_size = 1eX - максимальная длина элемента
    std::mt19937 rnd(time(NULL));
    for (int i = 0; i < sz; i++) {
        out.push_back(rnd() % max_el_size);
    }
}
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

// MAIN PART
void merger(vec &v, int left, int middle, int right) {

}


void merge_rec(vec &v, int left, int right) {
    if (left < right) {
        int middle = (left + right) / 2;
        for (int i = left; i < right + 1; i++) { std::cout << v[i] << " "; }
        std::cout << std::endl;
        merge_rec(v, left, middle);
        merge_rec(v, middle + 1, right);
        // MERGE
    }
}


int main() {
    // CPP SPEEDUP
    setlocale(LC_ALL, "Russian");
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    // MAIN MAIN
    std::vector<int> a = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    //rnd_v(a,10,10e4);
    merge_rec(a, 0, a.size() - 1);
    std::cout << "________" << std::endl;
    out(a);

    return 0;
}