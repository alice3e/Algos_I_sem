#include <iostream>
#include <iomanip>
#include <vector>
#include <math.h>
#include <set>
#include <random>
#include <chrono>
using namespace std;
set<long long> smth;
// Credits: Andrei Sulimov, tg: @alice3e
void out_s(set<long long> v) {
    for (auto i: v) {
        cout << i << ' ';
    }
    cout << endl;
}

void out_v(vector<long long> &v) {
    for (auto i: v) {
        cout << i << ' ';
    }
    cout << endl;
}

long long smooth(long long cur_el,long long len_v){
    if(cur_el < len_v){
        smth.insert(cur_el);
        smooth(cur_el*2,len_v);
        smooth(cur_el*3,len_v);
    }else{
        return 0;
    }
}

vector <long long> rnd_v(int sz,int max_el_size){ // max_el_size = 1eX - максимальная длина элемента
    mt19937 rnd(time(NULL));
    vector <long long> out;
    for(int i = 0;i<sz;i++){
        out.push_back(rnd()%max_el_size);
    }
    return out;
}

void shell_sort(vector<long long> &v){
    long long n = v.size();
    smooth(1,n/3);
    vector <long long> v_s (smth.begin(),smth.end());  // set<long long> smth - vector of 3-smooth numbrs;
    //out_v(v_s);
    while(v_s.size()>0){
        int h = v_s[v_s.size()-1];
        v_s.pop_back();
        for(int i = h; i < n;i++){
            long long temp = v[i];
            int j = i;
            for(; j >= h && v[j - h] > temp ; j -= h){
                v[j] = v[j - h];
            }
            v[j] = temp;
        }
    }

}

void test(vector<long long> &v, void (*test_srt)(vector<long long>&)){

    const auto start_std{std::chrono::steady_clock::now()};
    vector <long long> vec_stdsort = v;
    sort(vec_stdsort.begin(),vec_stdsort.end());
    const auto end_std{std::chrono::steady_clock::now()};
    const std::chrono::duration<double> elapsed_seconds_std{end_std - start_std};
    std::cout <<"std::sort time is equal to: " << elapsed_seconds_std.count()  << " seconds"<< endl;

    const auto start_f{std::chrono::steady_clock::now()};
    test_srt(v);
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

void test_generator(vector <int> sizes){
    for(int i = 0; i < sizes.size(); i++){
        cout << endl  << "TEST FOR VECTOR SIZE OF 10^" << sizes[i] << " ELEMENTS" << endl << endl;
        long long n = pow(10,sizes[i]);
        vector<long long> ms = rnd_v(n,1e8); // max element = 10^8
        test(ms,shell_sort);
        cout << "___________" << endl;
    }
}


int main(){
    vector <int> k{3,4,5,6,7}; // for sort of 10^7 elements wait for 10 sec.
    test_generator(k);
}
