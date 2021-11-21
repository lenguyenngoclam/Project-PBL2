#ifndef SET_TEMPLATE_H
#define SET_TEMPLATE_H

#include <initializer_list>
#include <iostream>

using namespace std;

template<typename T>
class Set{
    private :
        size_t max_size;
        size_t size;
        T* arr;
        
        size_t curr;
    public :
        Set(int n = 3);
        Set(const Set<T>& s);

        Set<T>& operator=(const Set<T>&);
        
        ~Set();

        void free();
        void insert(T data);
        void erase(T data);
        T begin();
        T end();
        size_t findEle(const T& data);
        size_t getSize() { return size; }

        T& operator[](const size_t& index);

        ostream& getInfo(ostream& os) const;
};

template<typename T>
ostream& operator<<(ostream& os, const Set<T>& s){
    s.getInfo(os);
    return os;
}

#endif