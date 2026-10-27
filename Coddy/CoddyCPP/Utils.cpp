#include <vector>

namespace Utils{
    template<class T>
    static void PrintArr(std::vector<T> arr){
        for(T elem : arr)
            std::cout << elem <<  " " << std::endl; 
    }
}