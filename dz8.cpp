#include <iostream>
#include <vector>

template<typename T>
int binarySearch(std::vector<T>& vector, T needle) {
    int l = 0;
    int r = vector.size() - 1;
    int mid;

    if(needle > vector[r])
        return r + 1;
    if(needle < vector[l])
        return l;

    /*!
     *  l-------mid---------r
     */

    while (l <= r) {
        mid = (l + r) / 2;
        if (vector[mid] == needle)
            return mid;
        if (vector[mid] > needle)
            r = mid - 1;
        if (vector[mid] < needle)
            l = mid + 1;
    }
    return r + 1;
}

int main(){

    int size = 0;
    int needle = 0;
    std::vector<int> massive;

    std::cin >> size;

    massive.resize(size);

    for(auto& t: massive){
        std::cin >> t;
    }

    std::cin >> needle;

    std::cout << binarySearch(massive, needle);
    
    return 0;

}
