#include <iostream>
#include <iomanip>
#include <vector>
#include <math.h>
#include <random>
using namespace std;
typedef long long ll;
// credits: Andrei Sulimov tg: @alice3e
// More info: https://alicee3e.notion.site/25-09-23-8a92453ea285444e8684d6c4ac56191b?pvs=4
void vout(vector <int> &v){
    for (auto i : v){
        cout << i << " ";
    }
    cout << endl;
}

void vin(vector <int> &v,int n){
    for(int i = 0; i < n;i++){
        int x;
        cin >> x;
        v.push_back(x);
    }
}

void rnd_v(vector <int> &out,int sz,int max_el_size){ // max_el_size = 1eX - максимальная длина элемента
    mt19937 rnd(time(NULL));
    for(int i = 0;i<sz;i++){
        out.push_back(rnd()%max_el_size);
    }
}

int vmax(vector <int> &v){
    int n = -1;
    for (auto i : v){
        n = max(n,i);
    }
    return n;
}

vector <int> count_sort(vector <int> &v){
    int n = v.size();
    vector <int> out(vmax(v));
    for(auto i: v){
        out[i] += 1;
    }
    return out;
}

void hash_v(vector <int> &v){
    int n = v.size();
    for(int i = 0;i<n;i++){
        if(i!=0){
            v[i] += v[i-1];
        }
    }
}

int interval(vector <int> &v,int &l,int &r){
    int left;
    if(l == 0){
        left = 0;
    }else{
        left = v[l-1];
    }
    int right = v[r];
    //cout << "values: " <<  right << ' ' << left << endl;
    return right - left;
}

int main(){
    vector <int> v;
    int sz,max_el;
    cout << "Введите размерность и максимальный элемент случайного вектора: ";
    cin >> sz >> max_el;
    rnd_v(v,sz,max_el);
    cout << "Сгенерированный вектор: ";
    vout(v);
    vector <int> sorted = count_sort(v);
    cout << "Отсортированный подсчетом вектор: ";
    vout(sorted);
    cout << "Хэш таблица вектора: ";
    hash_v(sorted);
    vout(sorted);
    int q;
    cout << "Введите количество будущих запросов: ";
    cin >> q;
    cout << endl;
    for(int i = 0;i<q;i++){
        cout << "Введите левую и правую границы через пробел: ";
        int l,r;
        cin >> l >> r;
        cout << "Количество чисел в промежутке [l;r] равно: " << interval(sorted,l,r) << endl;
    }
    return 0;
}

