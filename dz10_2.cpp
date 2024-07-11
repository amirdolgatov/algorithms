
#include <iostream>
#include <vector>

// Указать минимальный под-массив, содержащий заданное число 

template<typename T>
std::pair<size_t , size_t> search(std::vector<T>& vector, T needle){
    if(needle < vector.front() || needle > vector.back())
        return {0, 0};
    size_t border = 1;

    while(needle > vector[border] && border < vector.size()){
        border = border * 2;
    }

    if(border > vector.size() - 1)
        return {border/2, vector.size() - 1};

    return {border/2, border};

}

int main(){

    std::vector<int> vector;

    int size = 0;
    int needle = 0;

    std::cin >> size;

    vector.resize(size);

    for (int i = 0; i < size; ++i) {
        std::cin >> vector[i];
    }

    std::cin >> needle;

    auto [begin, end] = search(vector, needle);

    std:: cout << begin << " " << end << std::endl;

    return 0;
}
