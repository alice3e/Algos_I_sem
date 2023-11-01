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

vector <long long> input_vec(ll n) {
    vec out(n);
    for (int i = 0; i < n; i++) {
        std::cin >> out[i];
    }
    return out;
}

void print_str_v(std::vector<string> &v) {
    for (auto i: v) {
        std::cout << i << ' ';
    }
}

void print_int_v(vec &v) {
    for (auto i: v) {
        std::cout << i << ' ';
    }
    std::cout << std::endl;
}

void print_pair_v(vector <pair < ll , ll > > &v) {
    for (auto i: v) {
        std::cout << "[ " << i.first << "," << i.second << " ] ";
    }
    std::cout << std::endl;
}

void print_str_matrix(vector<vector<string>> &v){
    for(int j = 0; j < v.size();j++){
        cout << "[ ";
        print_str_v(v[j]);
        cout << " ] ,";
    }
    std::cout << std::endl;
}

void print_int_matrix(vector<vector<ll>> &v){
    for(int j = 0; j < v.size();j++){
        print_int_v(v[j]);
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
    // ВСЕ ПИШЕМ В ll иначе тесты не проходит
    ll n,ans;
    cin >> n;
    vec inp = input_vec(n);
    vector < vector <ll> > v;
    vector <ll> k(3);
    for(int i = 0;i<n;i++) v.push_back(k);
    if(inp[0]==1 || inp[0]==3){
        v[0][1] = 1;
    }
    if(inp[0]==2 || inp[0]==3){
        v[0][2] = 1;
    }

    for(int i = 1; i < n; i ++){
        v[i][0] = max(max( v[i-1][0], v[i-1][1] ),v[i-1][2]);
        if(inp[i]==1 || inp[i]==3){
            v[i][1] = max(v[i-1][0],v[i-1][2]) + 1;
        }
        if(inp[i]==2 || inp[i]==3){
            v[i][2] = max(v[i-1][0],v[i-1][1]) + 1;
        }
    }
    ans = n - (max(max( v[n-1][0], v[n-1][1] ),v[n-1][2]));
    cout << ans << endl;
    return 0;
}