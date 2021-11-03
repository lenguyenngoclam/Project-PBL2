#include <iostream>
#include <string>

using namespace std;


template<typename T> class Node{
    T data;
    Node<T> *next;
    public :
        Node(){
            next = NULL;
        }
        void setData(T new_data){
            data = new_data;
        }
        Node<T>* &getNext(){
            return next;
        }
        T getData(){
            return data;
        }
        bool operator!= (const Node<T> *n){
            return (next == n->next && data == n -> data);
        }
};

template<typename T> class LinkedList{
    private :
        Node<T> *head = NULL;
        Node<T> **head_ref = &head;
    public :
        /*
        LinkedList(){
            head_ref = new Node<T>*;
            (*head_ref) = NULL;
        }
        */
        ~LinkedList(){
            deleteList();
        }
        void insert(T data){
            Node<T> *new_node = new Node<T>;
            new_node -> setData(data);
            if((*head_ref) == NULL || (*head_ref) -> getData() > data){
                new_node -> getNext() = (*head_ref);
                (*head_ref) = new_node;
            } else {
                if((*head_ref) -> getData() != data){
                    Node<T> *current = *head_ref;
                    while(current -> getNext() != NULL && current -> getNext() -> getData() < data){
                        current = current -> getNext();
                    }
                    new_node -> getNext() = current -> getNext();
                    current -> getNext() = new_node;
                }
            }
        }
        void printList(){
            Node<T> *current = (*head_ref);
            while(current != NULL){
                cout << current -> getData() << " ";
                current = current -> getNext();
            }
        }
        Node<T>* getHead() const{
            return (*head_ref);
        }
        void deleteList(){
            Node<T> *current = (*head_ref);
            Node<T> *next;
            while(current != NULL){
                next = current -> getNext();
                delete current;
                current = next;
            }
            (*head_ref) = NULL;
        }

        bool findEle(T x){
            Node<T> *current = *head_ref;
            while(current != NULL){
                if(current -> getData() == x)
                    return true;
                current = current -> getNext();
            }
            return false;
        }

        void getInfo(T x){
            Node<T> *current = *head_ref;
            while(current != NULL){
                if(current -> getData() == x){
                    cout << current -> getData();
                    break;
                }
                current = current -> getNext();
            } 
        }

        void deleteNode(T key){
            Node<T> *temp = *head_ref, *prev;
            if(temp != NULL && temp -> getData() == key){
                *head_ref = temp -> getNext();
                delete temp;
                return;
            }

            while(temp != NULL && temp -> getData() != key){
                prev = temp;
                temp = temp -> getNext();
            }

            if(temp == NULL)
                return;
            prev -> getNext() = temp -> getNext();
            
            delete temp;
        }

        LinkedList<T> &operator=(const LinkedList<T>& l){
            deleteList();
            Node<T> *current = l.getHead();
            while(current != NULL){
                insert(current -> getData());
                current = current -> getNext();
            }
            return (*this);
        }
};

