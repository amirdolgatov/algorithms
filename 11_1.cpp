

/*!
 * Дано бинарное дерево поиска в виде массива. Необходимо найти произведение минимального и максимального значений.
 * Для этого необходимо вспомнить как бинарное дерево размещается в массиве
 * Примечание: первая строка во вводе - число элементов в массиве
 * Формат входных данных
 * Первая строка содержит одно целое число - количество элементов в массиве
 * Вторая строка содержит не отсортированный массив целых чисел
 */


#include <iostream>
#include <vector>

/*!
 * Простое дерево
 * @tparam T
 */
template<class T>
class Tree {
public:

    struct Node{
        Node(const T& val):value{val}{}
        T value{0};
        Node* right{nullptr};
        Node* left{nullptr};
    };

    Node *head{nullptr};
    uint32_t tree_size{0};

    /*!
     * Добавиим новый узел
     * @param value
     */
    void add(const T& value) {
        if(head == nullptr){
            head = new Node{value};
        }
        else{
            Node** ptr = &head;
            Node* node = head;
            while (node != nullptr) {
                if (value > node->value){
                    ptr = &node->right;
                    node = *ptr;
                }
                else
                {
                    ptr = &node->left;
                    node = *ptr;
                }
            }
            *ptr = new Node{value};
            ++tree_size;
        }

    }

    uint32_t size(){
        return tree_size;
    }

    /*!
     * Метод распечатает элементы дерева в удобном виде
     * @param h указатель на корень
     * @param depth глубина узла (потомка)
     * @param offsetVector (вектор, хранящий отступы)
     * @param left флаг - левый узел или правый
     * @return
     */
    void visit(Node* h, int depth, std::vector<int>& offsetVector, bool left){
        if(h == nullptr)
            return;

        printNode(h, offsetVector, left);
        if(h->left){
            offsetVector.push_back(depth);
        }
        ++depth;
        visit(h->right, depth, offsetVector, false);
        visit(h->left, depth, offsetVector, true);
    }

    /*!
     * Печать узла
     * @param node указатель на узел
     * @param offsetVector вектор с отступами
     * @param left флаг левого потомка
     */
    void printNode(Node* node, std::vector<int>& offsetVector, bool left){
        if(!left){
            std::cout << "____" << node->value;
            return;
        }
        else{
            int prev = 0;
            std::cout << std::endl << "    ";
            for(int i: offsetVector){
                for (int j = prev; j < 6 * i - 1 ; ++j) {
                    std::cout << " ";
                }
                std::cout << "|";
                prev = 6 * i;

            }
            std::cout << "____" << node->value;
        }
        if(offsetVector.size() > 1)
            offsetVector.pop_back();
    }


    void printTree(){
        std::vector<int> offsetVector;
        visit(this->head, 0, offsetVector, false);
    }

};



/*!
 * Дерево в виде массива
 * @tparam T
 */
template<typename T>
class Massive_Tree {

public:

    /*!
     * Подайте на вход вектор с линеаризованным деревом
     * @param massive
     */
    Massive_Tree(std::vector<T>& massive){
        this->massive.reserve(massive.size());
        for(auto it: massive){
            this->massive.push_back(it);
        }
    }

    Massive_Tree() = default;

    T max(int n){
        while(right(n) > 0){
            n = right(n);
        }
        return massive[n];
    }

    T min(int n){
        while(left(n) > 0){
            n = left(n);
        }
        return massive[n];
    }

    /*!
     * Переход на левого потомка
     * @param i
     * @return индекс ячейки с левым потомком
     */
    int left(int i){
        if( int offset = 2 * i + 1; offset < massive.size())
            return offset;
        return  -1;
    }

    /*!
     * Переход на левого потомка
     * @param i
     * @return индекс ячейки с левым потомком
     */
    int right(int i){
        if( int offset = 2 * i + 2; offset < massive.size())
            return offset;
        return  -1;
    }

    uint32_t size(){
        return massive.size();
    }

    std::vector<T> massive;

};

int main(){

    int size = 0;
    std::vector<int> massive;

    std::cin >> size;

    massive.resize(size);

    for(auto& t: massive){
        std::cin >> t;
    }

    Massive_Tree<int> tree(massive);

    std::cout << tree.max(0) * tree.min(0) << std::endl;

    return 0;
}


