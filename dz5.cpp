#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <algorithm>


/*!
 *	
 Дан не отсортированный массив целых чисел. Необходимо перенести в начало массива все четные числа. 
 При этом последовательность четных чисел должна быть сохранена. 
 То есть если 8 стояла после 6, то после переноса в начало, она по-прежнему должна стоять после 6.
 
 
 Формат входных данных
Первая строка содержит одно целое число - количество элементов в массиве
Вторая строка содержит неотсортированный массив целых чисел

7
3 2 4 1 11 8 9

Выходные данные

2 4 8 1 11 3 9

В примере мы видим, что все четные числа перешли вперед сохраняя свое расположение относительно друг друга
 
 
 */

void printVector(std::vector<int>& vec) {
    for (auto t: vec)
        std::cout << t << " ";
}

void mydecision(){
    int size = 0;
    std::vector<int> massive;

    std::cin >> size;

    massive.resize(size);

    for(auto& t: massive){
        std::cin >> t;
    }

    int count = 0;

    int t = std::count_if(massive.begin(), massive.end(), [](int k){ return k % 2 == 1; });
    for (int i = massive.size() - 1; i > -1 && count != t; --i) {
        if (massive[i] % 2){
            if(i == massive.size() - 1){
                ++count;
                continue;
            }
            else{
                for (int j = i; j < massive.size() - 1 - count; ++j) {
                    std::swap(massive[j], massive[j + 1]);
                }
                ++count;
            }
        }
    }

    printVector(massive);
}

int main(){

    int size = 0;
    std::vector<int> massive;

    std::cin >> size;

    massive.resize(size);

    for(auto& t: massive){
        std::cin >> t;
    }

    

    printVector(massive);

    return 0;
}
