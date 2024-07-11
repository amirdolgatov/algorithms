#include <iostream>
#include <vector>
#include <string>

/*

Дана строка s. Строка состоит из английских букв в нижнем регистре.Необходимо из строки удалить все рядом стоящие повторяющиеся буквы. 
Например, в строке xyyx мы должны удалить yy, а после и оставшиеся xx и того после должна получиться пустая строка. 
Или же в строке fqffqzzsd после удаления остануться только fsd. 
Первыми удаляться ff, являющимися третьими и четвертыми символами, затем qq и после уже zz.

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

    T front(){
        return storage[stack_ptr + 1];
    }

    size_t getSize(){
        return this->size;
    }

    bool isEmpty(){
        return this->size == 0;
    }


private:

    size_t stack_ptr{0};
    size_t size{0};
    std::vector<T> storage;

};


int main(){

    std::string str, new_str;

    Stack<char> stack;

    getline(std::cin, str);

    stack.reserve(str.size());

    for(auto c: str){
        if(!stack.isEmpty()){
            if(stack.front() == c)
                stack.pop();
            else
                stack.push(c);
        }
        else
            stack.push(c);
    }

    new_str.resize(stack.getSize());

    int k;
    while( (k = stack.getSize()) > 0){
        new_str[k - 1] = stack.pop().second;
    }

    std::cout << new_str << std::endl;

    return 0;
}
