//
// Created by alicee on 17.12.2023.
//
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

typedef long long ll;
typedef std::vector<long long> vec;
using namespace std;
static const char space = ' ';
//Consts
#define PI 3.1415926535897932384626433832795l
const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e10;

// вывод вида: int value = 1; //Распечатает следующее: {value}: 1
#define PrintExpression(Expression)\
     std::cout << "{" #Expression "}: " << (Expression) <<\
     		std::endl;

vector <string> random_str(int n,int max_str_len){ // max_el_size = 1eX - максимальная длина элемента
    mt19937 rnd(time(NULL));
    vector <string> out;
    for(int i = 0;i<n;i++){
        //rnd()%max_el_size
        int curr_len = (rnd()%(max_str_len-5) + 4)%max_str_len ;
        string s = "";
        for(int j = 0;j < curr_len;j++){
            int x = ((rnd()%25 + 97)%122);
            //cout << x << endl;
            s.push_back(char( x ));
        }
        out.push_back(s);
    }
    return out;
}

vector <long long> random_ll(int sz,int max_el_size){ // max_el_size = 1eX - максимальная длина элемента
    mt19937 rnd(time(NULL));
    vector <long long> out;
    for(int i = 0;i<sz;i++){
        out.push_back(rnd()%max_el_size);
    }
    return out;
}

template <typename T>
std::vector <T> input(int n) {
    std::vector <T> out;
    std::cout << "Введите значения (" << n << " раз) для вектора: ";
    for (int i = 0; i < n; i++) {
        T a;
        cin >> a;
        out.push_back(a);
    }
    return out;
}

template <typename T> // for vector
void print(const T &x)
{
    for(int i = 0; i < x.size(); i++){
        std::cout << x[i] << ' ';
    }
    std::cout << std::endl;
}

template <typename T> // for arr[]
void print(const T arr[],const int n){ // YOU SHOULD SEND ARR SIZE
    for(int i = 0; i < n;i++){
        std::cout << arr[i] << ' ';
    }
    std::cout << std::endl;
}