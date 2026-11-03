#pragma once

#include <vector>
#include <iostream>

namespace Utils{
    template<class T>
    static void PrintArr(std::vector<T> arr){
        for(T elem : arr)
            std::cout << elem <<  " " << std::endl; 
    }
}