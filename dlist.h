#ifndef DLIST_H
#define DLIST_H

#include "iterator.h"
using namespace std;
template <typename T>
class DListIterator : public Iterator<T> {     
    public: 
        DListIterator() : Iterator<T>() {};
        DListIterator(Node<T> *current) : Iterator<T>(current) {};
        DListIterator<T> operator++(){
            this->current = this->current->next;
            //es para que sepa que es de la misma
            //current = current->next;
            //devueleve el mismo objeto
            return *this;
        }
        DListIterator<T> operator--(){
            this->current = this->current->prev;
            return *this;
        }
};

template <typename Tr>
class DList {     
    public:
        typedef typename Tr::T T;
        typedef DListIterator<T> iterator;
      
    private:
        Node<T>* head;
        Node<T>* tail;
        int nodes;
              
    public:
        DList() {
            head =nullptr;
            tail= nullptr;
            nodes=0;
        };

        void push_front(T data) {
            Node<T> *nuevo= new Node<T>();
            nuevo->data= data;

            if(head== nullptr){
                head = nuevo;
                tail=nuevo;
            }
            else{
                nuevo->next=head;
                head->prev=nuevo;
                head=nuevo;
            }
            nodes++;
        }

        void push_back(T data) {
            Node<T> *nuevo= new Node<T>();
            nuevo->data= data;

            if(head== nullptr){
                head = nuevo;
                tail= nuevo;
            }
            else{
                tail->next=nuevo;
                nuevo->prev=tail;
                tail=nuevo;
                }
            nodes++;
        }
             
        void pop_front() {
            auto* aux=head;
            if(head== nullptr){
                std::cout<<"lista vacia"<<endl;
            }
            else if(nodes==1){
                auto* aux=head;
                tail= nullptr;
                head= nullptr;
                delete aux;
              }
              else {
                auto* aux=head;
                head=head->next;
                head->prev= nullptr;
                aux->next= nullptr;
                delete aux;

            }
            nodes--;
        }
             
        void pop_back() {
            if(head== nullptr){
                cout<<"lista vacia"<<endl;
            }
            else if(nodes==1){
                auto* aux=head;
                tail= nullptr;
                head= nullptr;
                delete aux;
            }
            else {
                auto* aux=tail;
                tail=tail->prev;
                tail->next= nullptr;
                aux->prev= nullptr;
                delete aux;

            }
            nodes--;
        }
             
        iterator begin() {
            return(Iterator<T>(head));
        }
             
        iterator end() {
            return(Iterator<T>(tail));
        }
             
        ~DList() {
            if (head) {
                head->killSelf();
            } 
        }         
};

#endif