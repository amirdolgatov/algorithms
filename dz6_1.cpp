#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <algorithm>

/*!

	Дан массив не отсортированных целых чисел. 
	Написать функцию, которая вернет первое с конца четное число. 
	При написании кода используйте принцип стека. 
	Если массив не содержит четного числа возвращать -1.

	Примечание: первая строка во вводе - число элементов в массиве
	 
	Формат входных данных
	Первая строка содержит одно целое число - количество элементов в массиве
	Вторая строка содержит не отсортированный массив целых чисел

*/

template<typename T>
class Stack{
public:

    void reserve(size_t _size){
        storage.reserve(_size);

        stack_ptr = _size - 1;

    }

    bool push(T& data){
        if(size < storage.capacity()){
            storage[stack_ptr--] = data;
            ++size;
            return true;
        }
        return false;
    }

    std::pair<bool, T> pop(){
        if(size > 0){
            stack_ptr++;
            size--;
            return {true, storage[stack_ptr]};
        }
        return {false, T()};
    }

    size_t getSize(){
        return this->size;
    }


private:

    size_t stack_ptr{0};
    size_t size{0};
    std::vector<T> storage;

};

int main(){

    int size = 0;
    int empty = -1;
    Stack<int> stack;

    std::cin >> size;

    stack.reserve(size);

    for (int i = 0, k; i < size; ++i) {
        std::cin >> k;
        if(k % 2 == 0)
            stack.push(k);
    }

    if(auto res = stack.pop(); res.first)
        std::cout << res.second << std::endl;
    else
        std::cout << empty << std::endl;


    return 0;
}
