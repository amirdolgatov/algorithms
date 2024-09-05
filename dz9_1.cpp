#include <iostream>
#include <vector>

// Решить задачу
// Задана строка, некоторые символы в ней повторяются, найти максимальное количество повторений

class hash_table{

public:

    struct Node{
        char key{0};
        int value;
    };

    hash_table(size_t _capacity_ = 300):capacity{_capacity_}
    {
        table = new Node* [capacity];
        not_null.reserve(10);
    }

    ~hash_table(){
        for(auto p: not_null){
            delete p;
        }
        delete table;
    }

    void insert(char key){
        if(table[key] == nullptr){
            auto new_ptr = new Node{key, 1};
            table[key] = new_ptr;
            not_null.push_back(new_ptr);
        }
        else
            table[key]->value++;
    }

    int& get(char key){
        if(table[key] != nullptr)
            return table[key]->value;
        else
            throw std::string{"Can't find element!"};
    }

    int getMax(){
        auto max = not_null.begin();
        for(auto p = not_null.begin() + 1; p != not_null.end(); p++)
            if( (*p)->value > (*max)->value)
                max = p;
        return (*max)->value;
    }

    std::vector<Node*>& getNotNull(){
        return this->not_null;
    }

    size_t size(){
        return this->not_null.size();
    }

private:

    size_t capacity{0};
    Node** table{nullptr};
    std::vector<Node*> not_null;
};



int main(){

    std::string str;

    hash_table table;

    std::getline(std::cin, str);

    for (auto c: str) {
        table.insert(c);
    }

    std::cout << table.getMax() << std::endl;

    return 0;
}
