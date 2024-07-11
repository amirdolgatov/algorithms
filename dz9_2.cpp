#include <iostream>
#include <vector>

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

    void erase(char key){

    }

    int& get(char key){
        if(table[key] != nullptr)
            return table[key]->value;
        else
            throw std::string{"Can't find element!"};
    }

    bool contain(char key){
        return table[key] != nullptr;
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

    std::string str1, str2;

    hash_table table1;
    hash_table table2;

    std::cin >> str1;
    std::cin >> str2;

    for (auto c: str1) {
        table1.insert(c);
    }

    for (auto c: str2) {
        table2.insert(c);
    }

    if(table1.size() != table2.size()){
        std::cout << "false" << std::endl;
        return 0;
    }

    auto c = str1.begin();
    for( ; c != str1.end(); c++){
        if(table2.contain(*c)){
            if (table1.get(*c) != table2.get(*c))
                break;
        }
        else
            break;


    }

    if (c == str1.end())
        std::cout << "true" << std::endl;
    else
        std::cout << "false" << std::endl;


    return 0;
}

