
#include <iostream>
#include <vector>
#include <algorithm>

/// Дан массив целых чисел, вывести число которое встречается больше половины раз

int main(){

    std::vector<int> vector(10, 0);

    int size = 0;
    int digit = 0;

    std::cin >> size;

    for (int i = 0; i < size; ++i) {
        std::cin >> digit;
        if(digit < 10 && digit >= 0)
            vector[digit]++;
    }

    auto max = std::max_element(vector.begin(), vector.end());
    if(*max > size / 2)
        std:: cout << std::distance(vector.begin(), max) << std::endl;
    else
        std::cout << -1 << std::endl;


    return 0;
}
