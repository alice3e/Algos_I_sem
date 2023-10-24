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

void print_str_v(std::vector<string> &v) {
    for (auto i: v) {
        std::cout << i << ' ';
    }
    std::cout << std::endl;
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

void radix_sort_lsd_withNull(vector <string> &v, const int max_str_len) {
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

void radix_sort_lsd_firstletter(vector <string> &v, const int max_str_len) {
    // [a, b, .... ]
    int size = v.size();
    for(int i = 0;i < max_str_len;i++){
        vector<vector<string>> letters(27);
        for(int j = 0;j<size;j++){
            int pos;
            if(i < v[j].size()){
                char l = v[j][ v[j].size() - i - 1];
                pos = int(l)-97+1;
            }else{
                // MAIN CHANGE
                // ЕСЛИ БУКВ НЕ ОСТАЛОСЬ В СТРОКЕ, СЛОВО ПРОСТО СОРТИРУЕМ ПО ЕГО ПЕРВОЙ БУКВЕ
                char l = v[j][0]; // [0](first letter) instead of Null
                pos = int(l)-97+1;
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

int main() {
    // CPP SPEEDUP
    setlocale(LC_ALL, "Russian");
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    // MAIN MAIN
    // ВСЕ ПИШЕМ В ll иначе тесты не проходит
    vector <string>  radixsort_withNull_arr, radixsort_firstletter_arr,std_arr;
    radixsort_withNull_arr = {"abc","bcd", "cde", "def", "a", "abz", "bc"};//random_str(10,10);
    radixsort_firstletter_arr = radixsort_withNull_arr;
    std_arr = radixsort_withNull_arr;
    const int max_string_len = max_str_len(radixsort_withNull_arr);
    cout << "Original:          ";print_str_v(radixsort_withNull_arr);
    // sorts
    radix_sort_lsd_withNull(radixsort_withNull_arr,max_string_len);
    radix_sort_lsd_firstletter(radixsort_firstletter_arr,max_string_len);
    std::sort(std_arr.begin(),std_arr.end());

    cout << "Radix with NUll :      "; print_str_v(radixsort_withNull_arr);
    cout << "Radix first letter :   "; print_str_v(radixsort_firstletter_arr);
    cout << "std::sort :            "; print_str_v(std_arr);

    return 0;
}