#include <iostream>
#include <vector>
using namespace std;
vector<int> mergeSort(vector<int>& v,int &count);
void out(std::vector<int> &v);

int main() {
    vector<int>a = {8,3,5,1,8,9,1,4,2,5};
    int n = 0; // counter
    mergeSort(a,n);
    cout << "Количество интересных пар за log n: " << n;
}


vector<int> mergeSort(vector<int> &v,int &count) {
    if (v.size() <= 1) return v;

    // Позаимствовал у Михаила супер крутую конструкцию auto
    // Сразу и размер и заполненение веткора
    auto r_arr = vector<int>(
            v.begin() + (v.size() / 2),
            v.end()
    );

    auto l_arr = vector<int>(
            v.begin(),
            v.end() - v.size() % 2 - (v.size() / 2)
    );

    vector<int> Left = mergeSort(l_arr,count);
    vector<int> Right = mergeSort(r_arr,count);

    int l = 0,r = 0,k = 0;
    vector<int> C(v.size());

    while (l < Left.size() && r < Right.size()) {
        if (Left[l] <= Right[r]) {
            C[k] = Left[l];
            l += 1;
        } else {
            C[k] = Right[r];
            r += 1;
            // Все что справа больше -> прибавляем длину - позиция элемента
            count += Left.size() - l;
        }
        k += 1;
    }

    while (l < Left.size()) {
        C[k] = Left[l];
        l += 1;
        k += 1;
    }

    while (r < Right.size()) {
        C[k] = Right[r];
        r += 1;
        k += 1;
    }
    //out(C); // Отсортирован
    return C;
}

void out(std::vector<int> &v) {
    for (auto i: v) {
        std::cout << i << ' ';
    }
    std::cout << std::endl;
}
