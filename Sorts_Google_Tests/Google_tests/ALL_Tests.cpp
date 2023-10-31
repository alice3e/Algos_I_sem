//
// Created by alicee on 25.10.2023.
//
#include "gtest/gtest.h"
#include "Radix_MSD_VS_std_sort.h"
#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <random>

std::vector <std::string> random_str(int n,int max_str_len){ // int n - кол-во строк, int max_str_len - максимальная длина строеи
    std::mt19937 rnd(time(NULL));
    std::vector <std::string> out;
    for(int i = 0;i<n;i++){
        int curr_len = (rnd()%(max_str_len-5) + 4)%max_str_len ;
        std::string s = "";
        for(int j = 0;j < curr_len;j++){
            int x = ((rnd()%25 + 97)%122);
            s.push_back(char( x ));
        }
        out.push_back(s);
    }
    return out;
}

void text_output_of_vector(std::vector <std::string> &v){
    std::cout << "{ ";
    for(int i = 0;i < v.size();i++){
        std::cout << "\"" << v[i] << "\" , ";
    }
    std::cout << " }" << std::endl;
}


TEST(RadixFL_TEST, zerostring_test){
    std::vector <std::string> std_arr{};
    RadixFL v1 = std_arr;
    v1.Radix_MSD(0,std_arr.size(),0);
    std::sort(std_arr.begin(),std_arr.end());
    ASSERT_EQ(v1.GetV(),std_arr);
}

TEST(RadixFL_TEST, one_elementstring_test){
    std::vector <std::string> std_arr{"z"};
    RadixFL v1 = std_arr;
    v1.Radix_MSD(0,std_arr.size(),0);
    std::sort(std_arr.begin(),std_arr.end());
    ASSERT_EQ(v1.GetV(),std_arr);
}

TEST(RadixFL_TEST, random_elementstring_1x10_test){
    std::vector <std::string> std_arr = random_str(1,10);
    RadixFL v1 = std_arr;
    v1.Radix_MSD(0,std_arr.size(),0);
    std::sort(std_arr.begin(),std_arr.end());
    ASSERT_EQ(v1.GetV(),std_arr);
}

TEST(RadixFL_TEST, random_elementstring_10x10_test){
    std::vector <std::string> std_arr = random_str(10,10);
    RadixFL v1 = std_arr;
    v1.Radix_MSD(0,std_arr.size(),0);
    std::sort(std_arr.begin(),std_arr.end());
    ASSERT_EQ(v1.GetV(),std_arr);
}

TEST(RadixFL_TEST, random_elementstring_100x10_test){
    std::vector <std::string> std_arr = random_str(100,10);
    RadixFL v1 = std_arr;
    v1.Radix_MSD(0,std_arr.size(),0);
    std::sort(std_arr.begin(),std_arr.end());
    ASSERT_EQ(v1.GetV(),std_arr);
}

TEST(RadixFL_TEST, random_elementstring_50x50_test){
    std::vector <std::string> std_arr = random_str(50,50);
    RadixFL v1 = std_arr;
    v1.Radix_MSD(0,std_arr.size(),0);
    std::sort(std_arr.begin(),std_arr.end());
    ASSERT_EQ(v1.GetV(),std_arr);
}

TEST(RadixFL_TEST, random_elementstring_100x100_test){
    std::vector <std::string> std_arr = random_str(100,100);
    RadixFL v1 = std_arr;
    v1.Radix_MSD(0,std_arr.size(),0);
    std::sort(std_arr.begin(),std_arr.end());
    ASSERT_EQ(v1.GetV(),std_arr);
}

TEST(RadixFL_TEST, random_elementstring_1000x1000_test){
    std::vector <std::string> std_arr = random_str(1000,1000);
    RadixFL v1 = std_arr;
    v1.Radix_MSD(0,std_arr.size(),0);
    std::sort(std_arr.begin(),std_arr.end());
    ASSERT_EQ(v1.GetV(),std_arr);
}

TEST(RadixFL_TEST, random_elementstring_10000x10000_test){
    std::vector <std::string> std_arr = random_str(10000,10000);
    RadixFL v1 = std_arr;
    v1.Radix_MSD(0,std_arr.size(),0);
    std::sort(std_arr.begin(),std_arr.end());
    ASSERT_EQ(v1.GetV(),std_arr);
}