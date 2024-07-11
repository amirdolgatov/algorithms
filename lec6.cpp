#include <iostream>
#include <stdlib.h>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>


/*

  Простая реализация стека
  Решение задачи о последовательностях из скобок

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

bool seq_brackets(const std::string& str){

    std::unordered_map<char, char> brackets{
            {'[', ']'},
            {'(', ')'},
            {'{', '}'},
    };

    Stack<char> stack;

    stack.reserve(str.size());

    for(auto c: str){
        if (brackets.count(c) != 0)  ///< если скобка открывающая, записываем ее в стек
            stack.push(c);
        else{
            if(auto [b, val] = stack.pop(); b){  ///< если скобка закрывающая и стек не пуст,
                if(brackets[val] != c)            ///< то если верхний элемент стека не соотвествует скобке, цепочка некорректна
                    return false;
            }
            else
                return false;                    ///< если стек пуст цепочка некорректна
        }
    }
    return true;
}

int main(){

    std::string str;

    getline(std::cin, str);


    if (seq_brackets(str))
        std::cout << "yes" << std::endl;
    else
        std::cout << "no" << std::endl;

    return 0;
}
