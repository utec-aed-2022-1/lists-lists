#ifndef FORWARD_H
#define FORWARD_H
#include <iostream>
#include "list.h"

// TODO: Implement all methods
template <typename T>
class ForwardList : public List<T> {
    private:
        Node<T>* head;
        int nodes;

    public:
        ForwardList() : List<T>() {}

        ~ForwardList(){ 
         	// TODO            
        }

     T front(){
        if(head==nullptr){
            return 0;
        }
        else{
           return head->data;
        }
    }

    T back(){
        if(head==nullptr){
            return 0;
        }
        else{
            Node<T>* temp= head;
            while (temp->next != nullptr)
            {
                temp = temp->next;

            }
            return temp->data;
        }
    }

    void push_front(T data){
        Node<T>* nuevo = new Node<T>;
        nuevo->data = data;
        nuevo->next = head;
        head = nuevo;
    }

    void push_back(T data){
        Node<T>* nuevo = new Node<T>;
        nuevo->data = data;
        Node<T>* temp = head;
        while (temp->next != nullptr)
        {temp = temp->next;}
        temp->next = nuevo;
        nuevo->next = nullptr;
    }

    T pop_front(){
        Node<T> *temp = head;
        head = head->next;
        delete temp;
    }

    T pop_back(){
        if(head->next == nullptr)
        {
            delete head;
            head = nullptr;
        }
        else {

            Node<T>* temp = head;
            while (temp->next->next != nullptr)
            {  temp = temp->next;}
            delete temp->next;
            temp->next = nullptr;
        }
    }

    T insert(T data, int pos){
        Node<T>* nuevo = new Node<T>(data);
        Node<T>* temp = head;
        int i = 0;
        while(i++ < pos - 1) {temp = temp->next;}
        nuevo->next = temp->next;
        temp->next = nuevo;
    }

    bool remove(int pos){
        if (head== nullptr){ return 0;}
        else {
            Node<T> *temp = head;
            int i = 0;
            while (i++ < pos - 1) { temp = temp->next; }
            delete temp;
        }
    }

    T& operator[](int pos){

        Node<T>* temp = head;
        int i = 0;
        while(i++ < pos - 1) {temp = temp->next;}
        return temp->data;


    }

    bool is_empty(){
        if (head== nullptr){ return true;}
        else { return false;}
    }

    int size(){
        Node<T>* temp = head;
        int i = 1;
        if (head == nullptr){return 0;}
        else {
            while (temp->next != nullptr) {
                temp = temp->next;
                i++;
            }
        }
        return i;
    }

    void clear(){
        while(head != nullptr)
        {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void sort(){

        Node<T>* temp1 = head;
        Node<T>* temp2 = temp1->next;
        Node<T>* temp3 = temp2;
        while (temp1->next != nullptr)
        {
          if (temp1->data > temp2->data & temp2!= nullptr)
          {

              temp2->data= temp1->data;
              temp1->data= temp3-> data;
              temp1=head;
          }
            temp1 = temp1->next;
        }
    }

        bool is_sorted(){
            throw ("sin definir");
        }

        void reverse(){
            throw ("sin definir");
        }

        std::string name(){
            return "ForwardList";
        }
        
};

#endif