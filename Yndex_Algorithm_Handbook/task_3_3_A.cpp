#include <iostream>
#include <list>


/*!
 * 
 * Камни
 * Вы играете в игру "Камни": игру для двух игроков с двумя наборами камней по n и 𝑚 штук. 
 * 
 * С каждым ходом один игрок может взять один камень (из любого набора) или два камня (по одному из обоих). 
 * [1, 0], [0, 1], [1, 1] 
 * 
 * Когда камень забрали, он выходит из игры. Побеждает игрок, который заберет последний камень. Первый ход за вами.
 * Вы и ваш оппонент играете оптимально
 * 
 */



/*!
 * Функция вернет указатель на двумерный массив
 * @tparam T тип данных массива
 * @param m первое измерение
 * @param n второе измерение
 * @return указатель на начало блока
 */
template<typename T>
T** two_dim_massive(int m, int n){
    auto R = new T*[m];
    for (int i = 0; i < m; ++i) {
        R[i] = new T[n];
    }
    return R;
}

/*!
 * Освободить память двумерного массива
 * @tparam T тип данных
 * @param ptr указатель на данные
 * @param m первое измерение
 * @param n второе измерение
 */
template<typename T>
void delete_two_dim_massive(T** ptr, int m, int n){
    for (int i = 0; i < m; ++i) {
        delete(ptr[i]);
    }
    delete(ptr);
}


/*!
 * Построить таблицу ходов
 * @param m количество камней в первом наборе
 * @param n количество камней во втором наборе
 * @return может ли победить ходящий?
 */
bool rocks(int m, int n){

    auto R = two_dim_massive<bool>(m + 1, n + 1);

    R[0][0] = 0;

    for (int i = 1; i <= m; ++i) {
        if(R[i - 1][0] == false)
            R[i][0] = true;
        else
            R[i][0] = false;
    }

    for (int j = 1; j <= n; ++j) {
        if(R[0][j - 1] == false)
            R[0][j] = true;
        else
            R[0][j] = false;
    }

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if(R[i][j - 1] && R[i - 1][j] && R[i - 1][j - 1])
                R[i][j] = false;
            else
                R[i][j] = true;
        }
    }
//  Print table
//    for (int i = 0; i <= m; ++i) {
//        for (int j = 0; j <= n; ++j) {
//            std::cout << R[i][j] << " ";
//        }
//        std::cout << std::endl;
//    }

    auto ret = R[m][n];
    delete_two_dim_massive<bool>(R, m + 1, n + 1);

    return ret;

}

int main() {

    int m, n;
    std::cin >> m;
    std::cin >> n;

    if(rocks(m, n))
        std::cout << "Win";
    else
        std::cout << "Lose";

    return 0;

}

