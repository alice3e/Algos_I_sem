#ifndef UNITTESTING_RADIX_FIRSTLETTER_H
#define UNITTESTING_RADIX_FIRSTLETTER_H
#include <vector>
#include <string>
#include <iostream>
#include <iomanip>
#include <random>
#include <algorithm>

class RadixFL{
protected:
    std::vector <std::string> v;
public:
    RadixFL(std::vector <std::string> &inp); // Init of RadixFL obj
    std::vector <std::string> GetV(); // returns v
    void Radix_MSD(int lo, int hi, int d); // radix sort first letter
    int MSL(); // max_str_len of v
    void print_v();
};


#endif