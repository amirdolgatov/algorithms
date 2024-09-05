#include <iostream>
#include <list>

/*!

Бронирование переговорки
Задано n интервалов. Требуется найти максимальное количество взаимно непересекающихся интервалов.

Два интервала пересекаются, если они имеют хотя бы одну общую точку.

Формат ввода
В первой строке задано одно число 

Формат вывода
Выведите ответ на задачу.

Пример 1
Ввод
3
1 3
2 3
4 5
Вывод
2

*/

struct Segment{

    Segment(int left, int right):left{left}, right{right}
    {}

    Segment() = default;

    int left{0};
    int right{0};

    bool no_intersection(Segment& other){
        if(this->left < other.left)
            return this->right < other.left;
        if(this->left > other.left)
            return this->left > other.right;
        else
            return false;
    }

    // |--------|   |------|
    // l1       r1  l2     r2               r1 < l2
    // |--------|   |------|
    // l2       r2  l1     r1               r1 < l2
};


std::pair<bool, Segment> find_chemp(std::list<Segment>& segments){
    if(segments.empty())
        return {false, Segment{}};

    auto chemp_ptr = segments.begin();
    for (auto iterator = ++segments.begin(); iterator != segments.end(); iterator++) {
        if(iterator->right < chemp_ptr->right)
            chemp_ptr = iterator;
    }
//    вариант удаления в find_chemp
//    auto chemp = *chemp_ptr;
//    segments.erase(chemp_ptr);

    return {true, *chemp_ptr};
}

void delete_intersection(std::list<Segment>& segments, Segment& segment){
    for (auto iterator = segments.begin(); iterator != segments.end(); ) {
        if(!iterator->no_intersection(segment))
            iterator = segments.erase(iterator);
        else
            ++iterator;
    }
}

int main() {

    int segmentNumber = 0;
    int res = 0;
    std::list<Segment> segments;


    std::cin >> segmentNumber;

    int left, right;
    for(int i = 0; i < segmentNumber; ++i){
        std::cin >> left;
        std::cin >> right;
        segments.emplace_back(left, right);
    }


    while (!segments.empty()){
        auto result = find_chemp(segments);
        res++;
        delete_intersection(segments, result.second);
    }

    std::cout << res << std::endl;

}
