#include <iostream>
#include <vector>



// Реализация функции бинарного посика

template<typename T>
int binarySearch(std::vector<T>& vector, T search_value){
    uint32_t l = 0;
    uint32_t r = vector.size() - 1;
    uint32_t mid;

    if(vector.empty())
        return -1;

    while(l <= r){
        mid = (l + r)/2;
        if (vector[mid] == search_value)
            return mid;
        if (vector[mid] > search_value)
            r = mid - 1;
        else
            l = mid + 1;
    }

    return -1;
}


int main(){

    int size = 0;
    std::vector<int> massive;
    int needle;

    std::cin >> size;

    massive.resize(size);

    for(auto& t: massive){
        std::cin >> t;
    }

    std::cin >> needle;

    if (binarySearch(massive, needle) > 0)
        std::cout << "true";
    else
        std::cout << "false";

    return 0;
}

