#ifndef SLIST_H
#define SLIST_H

#include "iterator.h"

template <class T>
class SListIterator : public Iterator<T> {     
    public: 
        SListIterator() : Iterator<T>() {};
        SListIterator(Node<T> *current) : Iterator<T>(current) {};
        SListIterator<T> operator++(){
            this->current = this->current->next;
            return *this;
        }
};

template <typename Tr>
class SList {     
    public:
        typedef typename Tr::T T;
        typedef typename Tr::Operation Operation;
        typedef SListIterator<T> iterator;
      
    private:
        Node<T>* head;
        Operation cmp;
              
    public:
        SList() {
            head = nullptr;
        };

        bool find(T search, Node<T> **&pointer) {
            auto* pointer=&head;
            while ((*pointer)->next!= nullptr){
                if ((*pointer)->data==search){
                    return true;
                }
                else if(cmp(search,(*pointer)->data)){
                   return false;
                }
                pointer=&((*pointer)->next);
            }
            return false;
        }
             
        bool insert(T data) {

            Node<T> **pointer;
            auto* nodo= new Node<T>(data);
            if(find(data, head)== true){
                return false;
            }
            auto* pointer=&head;
            while(cmp(data, (*pointer)->data)){
                pointer = &((*pointer)->next);
            }

            if (head== nullptr){
                *pointer=nodo;
                nodo->next= nullptr;
                return true;
            }
            else{
                *pointer=nodo;
                nodo->next=*pointer;
                return true;

            }


            //            // omp(search, valor que comp)
        }
             
        bool remove(T item) {
            Node<T> **pointer;
            auto* nodo= new Node<T>(data);
            if(find(data, head)== true){
                return false;
            }
            else{

                auto **pointer=&head;
                while(cmp(data, (*pointer)->data)){
                    pointer = &((*pointer)->next);
                }

                *pointer=nodo;
                delete temp;
                return true;

            }
        }  
             
        iterator begin() {
            return(Iterator(head));
        }
             
        iterator end() {
            auto* temp=head;
            while(temp!= nullptr){
                temp=temp->next;
            }
            return(Iterator(temp));
        }
             
        ~SList() {
            if (head) {
                head->killSelf();
            } 
        }         
};

#endif