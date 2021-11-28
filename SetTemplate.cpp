#include "SetTemplate.h"

using namespace std;

template<typename T>
Set<T>::Set(int n){
    max_size = n + 3;
    size = n;

    arr = new T[max_size]();

    curr = 0;
}

template<typename T> 
Set<T>::Set(const Set& s) : max_size(s.max_size), size(s.size){

    arr = new T[max_size]();
    for(size_t i = 0; i != size; i++)
        arr[i] = s.arr[i]; 
    
    curr = s.curr;
}

template<typename T>
Set<T>& Set<T>::operator =(const Set& s){

    T *temp = new T[s.max_size];
    for(size_t i = 0; i != s.size; i++)
        temp[i] = s.arr[i];

    delete[] arr;

    max_size = s.max_size;
    size = s.size;
    arr = new T[max_size]();
    for(size_t i = 0; i != s.size; i++)
        arr[i] = temp[i];

    curr = s.curr;

    return *this;
}

template<typename T>
ostream& Set<T>::getInfo(ostream& os) const{
    for(size_t i = 0; i != curr; i++)
        os << arr[i] << " ";
    return os;
}

template<typename T>
Set<T>::~Set(){
    delete[] arr;
}

template<typename T>
void Set<T>::free(){
    delete[] arr;
}

template<typename T>
void Set<T>::insert(T data){
    if(curr == max_size){
        Set temp(max_size + 3);
        for(size_t i = 0; i != size; i++)
            temp.arr[i] = arr[i];
        free();
        (*this) = temp;
    }
    if(curr == size) 
        size++;
    arr[curr] = data;
    curr++;
}

template<typename T>
void Set<T>::erase(T data){
    //Kiểm tra nếu tập hợp rỗng
    if(curr == 0)
        return;

    int index = 0;
    while(index != size && arr[index + 1] != data){
        index++;
    }

    for(int i = index + 1; i != size; i++)
        arr[i] = arr[i + 1];
    
    if(curr >= index + 1) curr--;
    size--;
}

template<typename T> 
T& Set<T>::operator [](const size_t& index){
    return arr[index];
}

template<typename T> 
T Set<T>::begin(){
    return arr[0];
}

template<typename T>  
T Set<T>::end(){
    return arr[size - 1];
}

template<typename T>
size_t Set<T>::findEle(const T& data){
    for(size_t index = 0; index != size; index++)
        if(arr[index] == data)
            return index;
    return -1;
}

