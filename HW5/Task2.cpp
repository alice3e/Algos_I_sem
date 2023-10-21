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

vector <long long> random_ll(int sz,int max_el_size){ // max_el_size = 1eX - максимальная длина элемента
    mt19937 rnd(time(NULL));
    vector <long long> out;
    for(int i = 0;i<sz;i++){
        out.push_back(rnd()%max_el_size);
    }
    return out;
}

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

void print_int_v(std::vector<ll> &v) {
    for (auto i: v) {
        std::cout << i << ' ';
    }
    std::cout << std::endl;
}

void print_str_v(std::vector<string> &v) {
    for (auto i: v) {
        std::cout << i << ' ';
    }
}

void print_str_matrix(vector <vector <string>> &m){
    for(int i = 0; i < m.size(); i++){
        cout << "[ ";
        print_str_v(m[i]);
        cout << " ], ";
    }
}

int max_str_len(vector <string> &v){
    int x = 0;
    for(auto i: v){
        if(i.size() > x){
            x = i.size();
        }
    }
    return x;
}

void radix_sort_lsd(vector <string> &v, const int max_str_len) {
    // [NULL, a, b, .... ]
    int size = v.size();
    for(int i = 0;i < max_str_len;i++){
        vector<vector<string>> letters(27);
        for(int j = 0;j<size;j++){
            int pos;
            if(i < v[j].size()){
                char l = v[j][ v[j].size() - i - 1];
                pos = int(l)-97+1;
            }else{
                pos = 0;
            }
            letters[pos].push_back(v[j]);
        }
        v.clear();
        for(int j = 0;j < letters.size();j++){
            for(int k = 0; k < letters[j].size(); k++){
                v.push_back(letters[j][k]);
            }
        }
    }
}


// Функция для сравнения времени выполнения двух других функций
bool compareStrings(const std::string &a, const std::string &b) {
    if (a.length() == b.length()) {
        return a < b; // Если длины равны, сравниваем строки лексикографически
    }
    return a.length() < b.length(); // Сначала сравниваем длины строк
}
void time_test(auto &v, void (*test_srt)(vector <string>&x,const int n)){

    const auto start_std{std::chrono::steady_clock::now()};
    auto vec_stdsort = v;
    std::sort(vec_stdsort.begin(), vec_stdsort.end(), compareStrings);
    const auto end_std{std::chrono::steady_clock::now()};
    const std::chrono::duration<double> elapsed_seconds_std{end_std - start_std};
    std::cout <<"std::sort time is equal to: " << elapsed_seconds_std.count()  << " seconds"<< endl;
    const auto start_f{std::chrono::steady_clock::now()};
    test_srt(v, max_str_len(v));
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



int main() {
    // CPP SPEEDUP
    setlocale(LC_ALL, "Russian");
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    // MAIN MAIN
    // ВСЕ ПИШЕМ В ll иначе тесты не проходит
    vector <string>  init_arr;
    init_arr = random_str(100,100);
    const int max_string_len = max_str_len(init_arr);
    //cout << "Init arr: ";print_str_v(init_arr);
    cout << endl;
    time_test(init_arr,radix_sort_lsd);
    return 0;
}