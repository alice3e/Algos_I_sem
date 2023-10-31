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
    for (int i = 0; i < v.size();i++) {
        std::cout << v[i] << ' ';
    }
}

void print_str_matrix(vector<vector<string> >  &v){
    for(int j = 0; j < v.size();j++){
        cout << "[ ";
        print_str_v(v[j]);
        cout << " ] ,";
    }
    std::cout << std::endl;
}

void radix_sort_lsd_withNull(vector <string> &v, const int max_str_len) {
    // [NULL, a, b, .... ]
    int size = v.size();
    for(int i = 0;i < max_str_len;i++){
        vector<vector<string> > letters(27);
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
        vector<vector<string> > letters(27);
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

int max_str_len(vector<string> &v){
    int out = 0;
    for(int i = 0; i < v.size();i++){
        out = max(out,(int)v[i].size());
    }
    return out;
}

int MSD_sort(vector<string>& a, int l, int r, int d){
    int max = max_str_len(a);
    if(d > max || l + 1 >= r)
        return 0;
    int cnt[26] = {0};

    for(int i = l; i < r; i++){
        if(a[i].size() > d){
            int j = (int)a[i].at(d);
            j -= 97;
            cnt[j]++;
        }

    }

    int n = r - l;

    for(int i = 25; i > -1; i--){
        n -= cnt[i];
        cnt[i] = n;
    }

    string ans[r - l];

    for(size_t i = l; i < r; i++){
        int j = (int)a[i].at(d);
        j -= 97;
        ans[cnt[j]] = a[i]; // Ставим на нужное место по d-ому разряду
        cnt[j]++;
    }

    for(size_t i = 0; i < r - l; i++){
        a[l + i] = ans[i];
    }

    int j = 0;

    for(size_t i = 0; i < 26; i++){
        if(j != cnt[i]){
            int q = MSD_sort(a, l + j, l + cnt[i], d + 1); // Сортируем поддиапозоны с одинаковым суффиксом
            j = cnt[i];
        }
    }
    return 0;
}


int main() {
    // CPP SPEEDUP
    setlocale(LC_ALL, "Russian");
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    // MAIN MAIN
    // ВСЕ ПИШЕМ В ll иначе тесты не проходит
    std::vector < std::string >  radixsort_withNull_arr, radixsort_firstletter_arr,std_arr,MSD_sort_arr, MSD_sort_arr2;
    std::vector < std::string > inp;
    radixsort_withNull_arr = random_str(10,10);
    radixsort_firstletter_arr = radixsort_withNull_arr;
    std_arr = radixsort_withNull_arr;
    MSD_sort_arr = radixsort_withNull_arr;
    MSD_sort_arr2 = radixsort_withNull_arr;
    const int max_string_len = max_str_len(radixsort_withNull_arr);
    cout << "Original:              ";print_str_v(radixsort_withNull_arr);std::cout << std::endl;
    // sorts
    radix_sort_lsd_withNull(radixsort_withNull_arr,max_string_len);
    radix_sort_lsd_firstletter(radixsort_firstletter_arr,max_string_len);
    std::sort(std_arr.begin(),std_arr.end());
    MSD_sort(MSD_sort_arr,0,MSD_sort_arr.size(),0);

    cout << "Radix with NUll :      "; print_str_v(radixsort_withNull_arr);std::cout << std::endl;
    cout << "Radix first letter :   "; print_str_v(radixsort_firstletter_arr);std::cout << std::endl;
    cout << "std::sort :            "; print_str_v(std_arr);std::cout << std::endl;
    cout << "MSD RADIX sort :       "; print_str_v(MSD_sort_arr);std::cout << std::endl;
    if(MSD_sort_arr == std_arr){
        cout << "WORKS" << endl;
    }else{
        cout << "DOESNT WORK!" << endl;
    }
    return 0;
}