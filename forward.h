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
    ForwardList() : List<T>() {

        head= new Node<T>;
        head->next= nullptr;

    }

    ~ForwardList(){
        delete head;
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
        Node<T>* temp = head;
        head = head->next;
        T i=temp->next->data;
        delete temp;
        return i;
    }

    T pop_back(){
        if(head->next == nullptr)
        {
            T  i= head->data;
            delete head;
            head = nullptr;
            return i;
        }
        else {

            Node<T>* temp = head;
            while (temp->next->next != nullptr)
            {  temp = temp->next;}
            int i=temp->data;
            delete temp->next;
            temp->next = nullptr;
            return i;
        }
    }

    void insert(T data, int pos){
        Node<T>* nuevo = new Node<T>;
        nuevo ->data=data;
        Node<T>* temp = head;
        int i = 0;
        while(i++ < pos -1) {temp = temp->next;}
        nuevo->next = temp->next;
        temp->next = nuevo;
    }

    void remove(int pos){
        Node<T> *temp = head;
        if (head== nullptr){ return;}
        else if(temp->next == nullptr || pos==0){T f=pop_front(); return;}
        else {
            int i = 0;
            while (i++ < pos - 1) { temp = temp->next; }

            Node<T> * temp2=temp->next;
            temp->next=temp->next->next;
            delete temp2;
        }
    }

    T& operator[](int pos){

        Node<T>* temp = head;
        T  i = 0;
        while(i++ < pos - 1) {temp = temp->next;}
        return temp->data;


    }

    bool is_empty(){
        if (head != nullptr){ return false;}
        else { return true;}
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
        Node<T>* temp2 = head->next;

        while (temp1->next != nullptr)
        {
            if (temp1->data > temp2->data)
            {

                int aux = temp1->data;
                temp1->data= temp2-> data;
                temp2->data= aux;
                temp1 = head;
                temp2 = head->next;

            }
            temp1 = temp1->next;
            temp2 = temp2->next;

            if(head->data > head->next->data){
                temp1 = head;
                temp2 = head->next;
            }
        }
    }

    bool is_sorted(){
        Node<T>* temp1 = head;
        Node<T>* temp2 = head->next;
        while (temp1->next != nullptr){

            if (temp1->data > temp2->data)
            {
                return false;
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        return true;
    }

    void reverse(){
        Node<T>* temp1 = nullptr;
        Node<T>* temp2=head;
        Node<T>*  temp3;

        while (temp2 != nullptr){

            temp3=temp2->next;
            temp2->next=temp1;
            temp1= temp2;
            temp2 = temp3;


        }

        head=temp1;

        head=temp1;
    }

    std::string name(){
        return "ForwardList";
    }

};

#endif