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

vector<ll> input_vec(ll vec_size) {
    std::vector<ll> v(vec_size);
    for (int i = 0; i < vec_size; i++) {
        std::cin >> v[i];
    }
    return v;
}

void print_str_v(std::vector<string> &v) {
    for (auto i: v) {
        std::cout << i << ' ';
    }
}

void print_int_v(vec &v) {
    for (auto i: v) {
        std::cout << i;
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


int main() {
    // CPP SPEEDUP
    setlocale(LC_ALL, "Russian");
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    // MAIN MAIN
    // ВСЕ ПИШЕМ В ll иначе тесты не проходит
    ll n;
    cin >> n;
    vec t1,t2,t1_ans(n),t2_ans(n);
    vector <pair <ll,ll> > merge;
    for(int i = 0; i < n;i++){
        ll a,b;
        cin >> a >> b;
        t1.push_back(a);
        t2.push_back(b);
        merge.push_back(pair <ll, ll >{a,i+1});
        merge.push_back(pair <ll, ll >{b,-1*i-1});
    }

    sort(merge.begin(),merge.end());

    for(int i = 0; i < n;i++){
        int elem = merge[i].first,ind = merge[i].second;
        if(ind < 0){
            t2_ans[abs(ind) - 1] = 1;
        }else{
            t1_ans[abs(ind) - 1] = 1;
        }
    }

    for(int i = 0;i < n/2;i++){
        t2_ans[i] = 1;
        t1_ans[i] = 1;
    }
    print_int_v(t1_ans);
    print_int_v(t2_ans);
    return 0;
}