#ifndef LinkedListTemplate_h
#define LinkedListTemplate_h

#include <iostream>

using namespace std;

template<typename T>
class Node{
    private :
        T data;
        Node* next = NULL;
        Node* prev = NULL;
    public :
        Node() = default;

        ~Node() = default;

        Node(const Node<T>& rhs) : data(rhs.data), next(rhs.next), prev(rhs.prev) {};
        
        Node<T>& operator= (const Node<T>& rhs){
            if(rhs != *this){
                delete next;
                delete prev;
                next = rhs.next;
                prev = rhs.prev;
            }
            return *this;
        }

        Node<T>*& getNext() { return next; }
        Node<T>*& getPrev() { return prev; }
        T& getData() { return data; }

        void setData(T new_data) {
            data = new_data;
        }

        void setNext(Node<T>*& new_next){
            next = new_next;
        }
        void setPrev(Node<T>*& new_prev){
            prev = new_prev;
        }
};

template<typename T> 
class LinkedList{
    private :
        Node<T>* head = nullptr;
        size_t curr = 0;
    public :

        LinkedList() = default;

        ~LinkedList() {
            deleteList();
        }

        LinkedList(const LinkedList<T>& ls);

        LinkedList& operator=(const LinkedList<T>& rhs);

        void insert(T data);
        void erase(T data);
        void deleteList();
        size_t findEle(const T& data);
        size_t getCurr() { return curr; }

        T& operator [](const size_t& index);

        ostream& getInfo(ostream& os) const;
};

template<typename T>
ostream& operator<<(ostream& os, const LinkedList<T>& ls){
    ls.getInfo(os);
    return os;
}

#endif