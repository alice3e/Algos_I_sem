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
// Вывод ull в норм формате: cout << (LLD , a);

typedef long long ll;
typedef std::vector<long long> vec;
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

vector <long long> rnd_v(int sz,int max_el_size){ // max_el_size = 1eX - максимальная длина элемента
    mt19937 rnd(time(NULL));
    vector <long long> out;
    for(int i = 0;i<sz;i++){
        out.push_back(rnd()%max_el_size);
    }
    return out;
}

void out(std::vector<ll> &v) {
    for (auto i: v) {
        std::cout << i << ' ';
    }
    std::cout << std::endl;
}

// Функция для сравнения времени выполнения двух других функций
void time_test(vec &v, void (*test_srt)(vec&,int n)){

    const auto start_std{std::chrono::steady_clock::now()};
    vector <long long> vec_stdsort = v;
    sort(vec_stdsort.begin(),vec_stdsort.end());
    const auto end_std{std::chrono::steady_clock::now()};
    const std::chrono::duration<double> elapsed_seconds_std{end_std - start_std};
    std::cout <<"std::sort time is equal to: " << elapsed_seconds_std.count()  << " seconds"<< endl;

    const auto start_f{std::chrono::steady_clock::now()};
    test_srt(v,v.size());
    const auto end_f{std::chrono::steady_clock::now()};
    const std::chrono::duration<double> elapsed_seconds_f{end_f - start_f};
    std::cout <<  "Test_sort time is equal to: " << elapsed_seconds_f.count() << " seconds" << endl;

    // Conclusion

    if(elapsed_seconds_std < elapsed_seconds_f){
        double speedup = elapsed_seconds_f / elapsed_seconds_std;
        std::cout << "std::sort is " << speedup << " times faster than Test_sort." << std::endl;
        std::cout << "std::sort is " << speedup*100 << "% faster than Test_sort." << std::endl;
    }else{
        double speedup = elapsed_seconds_std / elapsed_seconds_f;
        std::cout << "Test_sort is " << speedup << " times faster than Test_sort." << std::endl;
        std::cout << "Test_sort is " << speedup*100 << "% faster than Test_sort." << std::endl;
    }
}



void print_tree(vec& vec) { // ONLY BINARY
    if (vec.empty()) {
        cout << "Вектор пуст." << endl;
        return;
    }

    int height = static_cast<int>(log2(vec.size() + 1)) + 1;
    int currentIndex = 0;

    for (int level = 0; level < height; level++) {
        int elementsInCurrentLevel = pow(2, level);
        int elementsToPrint = min(elementsInCurrentLevel, static_cast<int>(vec.size()) - currentIndex);

        for (int i = 0; i < elementsToPrint; i++) {
            // Выводим элемент с соответствующим индексом
            cout << vec[currentIndex] << "(" << currentIndex << ")";

            // Добавляем отступ между элементами на одном уровне
            if (i < elementsToPrint - 1) {
                cout << " ";
            }

            currentIndex++;
        }

        // Переходим на следующий уровень
        cout << endl;
    }
}

void make_heap(vec &v, int n, int i)
{
    int largest = i;
    int l = 3*i + 1; // левый = 3*i + 1
    int r = 3*i + 3; // правый = 3*i + 3
    int m = 3*i + 2; // средний = 3*i + 2
    // Если левый дочерний элемент больше корня
    if (l < n && v[l] > v[largest])
        largest = l;

    // Если правый дочерний элемент больше, чем самый большой элемент на данный момент
    if (r < n && v[r] > v[largest])
        largest = r;

    // Если средний дочерний элемент больше, чем самый большой элемент на данный момент
    if (m < n && v[m] > v[largest])
        largest = m;


    if (largest != i)
    {
        swap(v[i], v[largest]);

        make_heap(v, n, largest);
    }
}


void heapSort(vec &v, int n)
{
    // Делим на три тк тернарное дерево
    for (int i = n / 3 - 1; i >= 0; i--)
        make_heap(v, n, i);

    for (int i=n-1; i>=0; i--)
    {
        // Перемещаем текущий корень в конец
        swap(v[0], v[i]);
        // вызываем процедуру make_heap на n-1 куче
        make_heap(v, i, 0);
    }
}



int main() {
    // CPP SPEEDUP
    setlocale(LC_ALL, "Russian");
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    // MAIN MAIN
    // ВСЕ ПИШЕМ В ll иначе тесты не проходит
    vec init_arr = rnd_v(10e5,10e5); //rnd_v(15,100);
    time_test(init_arr,heapSort);
    return 0;
}