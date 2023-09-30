#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
// Лучший в СПбГУ Леонид Романович


vector <int> rand_vec(int vec_size){
    srand(time(NULL));
    vector <int> v(vec_size);
    for(int i = 0;i<vec_size;i++){
        v[i] = rand();
    }
    return v;
}

vector <int> bubble(vector <int> v){
    int s = v.size();
    for(int i = 1; i < s;i++){
        for(int j = 0;j < s - i;j++){
            if(v[j] > v[j+1]){ swap(v[j],v[j+1]); }
        }
    }
    return v;
}

bool check(vector <int> original, vector <int> check){
    vector <int> tr = original;
    sort(tr.begin(),tr.end());
    if(tr==check){return 1;}
    else{return 0;}
}

int main() {
    vector <int> original = rand_vec(10);
    vector <int> srt = bubble(original);
    
    if(check){ cout << "Сортировка сработала верно!" << endl; }
    else{ cout << "Ошибка в алгоритме(" << endl; }

    return 0;
}
