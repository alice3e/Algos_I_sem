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
     
    void ost(int n){
        if(n == 5){cout << 2 << space << 4 << endl;}
        for(int i = 2; i < n/2;i++){
            int a = i;
            int ost_a = n%a;
            int b = (n-ost_a)/a;
            int ost_b = n%b;
            //cout << n << space <<  a << space << b << endl;
            if(ost_a==ost_b && b*a < n){
                cout << a << space << b << endl;
                break;
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
        int n;
        cin >> n;
        vec v;
        v.push_back(1);
        for(int j = 0;j < n;j++){
            int x;
            cin >> x;
            v.push_back(v[j]+x);
        }
        v[0] = 0;
        //out(v);
        int k;
        cin >> k;
     
        for(int j = 0;j < k;j++){
            int x;
            cin >> x;
            int lowr = (lower_bound(v.begin(), v.end(), x+1) - v.begin());
            cout << lowr << endl;
     
        }
        return 0;
    }