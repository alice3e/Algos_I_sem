
#include "Radix_MSD_VS_std_sort.h"

RadixFL::RadixFL(std::vector <std::string> &inp){
    for(int i = 0; i <  inp.size();i++){
        v.push_back(inp[i]);
    }
}

std::vector <std::string> RadixFL::GetV() {
    return v;
}

int RadixFL::MSL(){
    int out = 0;
    for(int i = 0; i < v.size();i++){
        out = std::max(out,(int)v[i].size());
    }
    return out;
}



void RadixFL::Radix_MSD(int l, int r, int d)
{

    int max = MSL();
    if(d > max || l + 1 >= r)
        return;
    int cnt[26] = {0};

    for(int i = l; i < r; i++){
        if(v[i].size() > d){
            int j = (int)v[i].at(d);
            j -= 97;
            cnt[j]++;
        }

    }

    int n = r - l;

    for(int i = 25; i > -1; i--){
        n -= cnt[i];
        cnt[i] = n;
    }

    std::string ans[r - l];

    for(size_t i = l; i < r; i++){
        int j = (int)v[i].at(d);
        j -= 97;
        ans[cnt[j]] = v[i]; // Ставим на нужное место по d-ому разряду
        cnt[j]++;
    }

    for(size_t i = 0; i < r - l; i++){
        v[l + i] = ans[i];
    }

    int j = 0;

    for(size_t i = 0; i < 26; i++){
        if(j != cnt[i]){
            Radix_MSD(l + j, l + cnt[i], d + 1); // Сортируем поддиапозоны с одинаковым суффиксом
            j = cnt[i];
        }
    }
    return;
}

void RadixFL::print_v() {
    for(int i = 0;i < v.size();i++){
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
}