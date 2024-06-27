#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>


////// Задание - реализовать сортировку слиянием

    template<typename T>
    void merge(std::vector<T>& arr, const int l, const int mid, const int r){
        const int n1 = mid - l + 1;
        const int n2 = r - mid;
        std::vector<T> left(n1), right(n2);
        for(int i = 0; i < n1; i++)
            left[i] = arr[l + i];
        for(int i = 0; i < n2; i++)
            right[i] = arr[mid + 1 + i];

        int i = 0, j = 0, k = l;

        while(i < n1 && j < n2){
            if (left[i] <= right[j])
                arr[k] = left[i++];
            else
                arr[k] = right[j++];
            k++;
        }

        while(i < n1)
            arr[k++] = left[i++];
        while(j < n2)
            arr[k++] = right[j++];
    }

    template<typename T>
    void mergeSort(std::vector<T>& arr, const int l, const int r){
        if(l >= r)
            return;

        const int mid = l + (r - l)/2;

        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);

        merge(arr, l, mid, r);

    }

    template<typename T>
    void printVector(std::vector<T>& vec){
        if (vec.size() != 0)
        {
            std::cout << "vector: " << std::endl;
            for (auto t: vec)
                std::cout << t << " ";
            std::cout << std::endl;
        }
        else
            std::cout << "Empty!" << std::endl;
    }



    struct Book{

        long isbn;
        std::string name;
        int year;

        bool operator<(const Book& rhs) const{
            if (this->year < rhs.year)
                return true;
            else if(this->year == rhs.year)
                if(this->name < rhs.name)
                    return true;
                else
                    return false;
        }

        bool operator>(const Book& rhs) const{
            return rhs < *this;
        }

        bool operator==(const Book& rhs) const{
            return !(*this < rhs || *this > rhs);
        }

        bool operator<=(const Book& rhs) const{
            return !(*this > rhs);
        }

        bool operator>=(const Book& rhs) const{
            return !(*this < rhs);
        }



    };

    Book splitString(std::string& str){
        Book book;

        int start = 0;
        int i = 0;

        for(  ; std::isdigit(str[i]); ++i)
            ;
        book.isbn = std::stol(str.substr(start, i - start));

        for(  ; str[i] != '"' ; ++i)
            ;
        start = i++;
        for(  ; str[i] != '"' ; ++i)
            ;
        book.name = str.substr(start, i - start + 1);


        for(  ; !std::isdigit(str[i]); ++i)
            ;
        start = i;
        for(  ; std::isdigit(str[i]); ++i)
            ;
        book.year = std::stol(str.substr(start, i - start));

        return book;
    }


    template<>
    void printVector(std::vector<Book>& vec){
        for (auto t: vec)
            std::cout << t.isbn << " " << t.name << " " << t.year << std::endl;
    }


    int main(int argc, char const *argv[])
    {
        int size = 0;
        std::vector<Book> massive;
        std::string temp;
        char ws;

        getline(std::cin, temp);
        size = std::stoi(temp);


        for(int i = 0; i < size; i++){
            getline(std::cin, temp);
            massive.emplace_back(splitString(temp));
        }



         mergeSort(massive, 0, massive.size() - 1);

         printVector(massive);

        return 0;
    }
