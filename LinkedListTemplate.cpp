#include "LinkedListTemplate.h"

using namespace std;

template<typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& ls){
    head = NULL;
    curr = ls.curr;
    Node<T>* current = ls.head;
    while(current != NULL){
        Node<T>* new_node = new Node<T>();
        new_node -> setData(current -> getData());
        new_node -> setNext(head);

        if(head != NULL)
            head -> setPrev(new_node);
        
        head = new_node;

        current = current -> getNext();
    }
}

template<typename T>  
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& rhs){

    Node<T>* current = rhs.head;
    LinkedList<T> temp;
    while(current != NULL){
        temp.insert(current -> getData());
        current = current -> getNext();
    }

    current = head;
    while(current != NULL){
        Node<T>* t = current -> getNext();
        delete current;
        current = t;
    }

    current = temp.head;
    while(current != NULL){
        Node<T>* t = current -> getNext();
        insert(current -> getData());
        delete current;
        current = t;
    }
    
    return *this;
}

template<typename T> 
void LinkedList<T>::insert(T data){
    curr++;
    Node<T>* new_node = new Node<T>();
    new_node -> setData(data);

    Node<T>* last = head;

    if(head == NULL){
        head = new_node;
        return;
    }

    while(last -> getNext() != NULL)
        last = last -> getNext();

    last -> getNext() = new_node;
    new_node->setPrev(last);

}

template<typename T> 
void LinkedList<T>::erase(T data){
    if(curr == 0)
        return;
    if(*head == data)
        head = head -> getNext();

    Node<T>* current = head;
    while(current != NULL && current -> getData() != data)
        current = current -> getNext();

    if(current == NULL)
        return;
    
    if(current -> getNext() != NULL)
        current -> getNext() -> getPrev() = current -> getPrev();
    if(current -> getPrev() != NULL)
        current -> getPrev() -> getNext() = current -> getNext();
    
    delete current;
}

template<typename T>
size_t LinkedList<T>::findEle(const T& data){
    Node<T>* current = head;
    for(size_t i = 0; i != curr; i++){
        if(current -> getData() == data)
            return i;
        current = current -> getNext();
    }

    return -1;
}

template<typename T>
T& LinkedList<T>::operator[](const size_t& index){
    Node<T>* current = head;
    for(int i = 0; i != index; i++){
        current = current -> getNext();
    }
    return current -> getData();
}

template<typename T> 
ostream& LinkedList<T>::getInfo(ostream& os) const{
    Node<T>* current = head;
    while(current != NULL) {
        cout << current -> getData() << endl;
        current = current -> getNext();
    }
    return os;
}