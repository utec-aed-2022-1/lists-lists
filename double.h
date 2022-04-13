#ifndef DOUBLY_H
#define DOUBLY_H
#include <iostream>
#include "list.h"

// TODO: Implement all methods
template <typename T>
class DoubleList : public List<T> {
private:
    Node<T>* head;
    Node<T>* tail;
    int nodes;
public:
    DoubleList() : List<T>() {


        head= new Node<T>;
        head->next= nullptr;
        head->prev= nullptr;
        tail=head;

    }

    ~DoubleList(){
        delete head;
        delete tail;
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
        if(tail==nullptr){
            return 0;
        }
        else {
            return tail->data;
        }
    }

    T& operator[](int pos){

        Node<T>* temp = head;
        T  i = 0;
        while(i++ < pos - 1) {temp = temp->next;}
        return temp->data;


    }


    void push_front(T data){

        if (head == nullptr & tail == nullptr){
            Node<T>* nuevo= new Node<T>;
            nuevo->data=  data;
            head = nuevo;
            tail = nuevo;
        }

        Node<T>* nuevo = new Node<T>;
        nuevo->data = data;
        nuevo ->prev = nullptr;
        nuevo->next = head;
        head->prev=head;
        head = nuevo;
    }


    void push_back(T data){

        if (head == nullptr & tail == nullptr){
            Node<T>* nuevo= new Node<T>;
            nuevo->data=data;
            head = nuevo;
            tail = nuevo;
        }
        else{
            Node<T>* nuevo = new Node<T>;
            nuevo->data = data;
            nuevo ->prev = tail;
            nuevo->next = nullptr;
            tail->next=nuevo;
            tail = nuevo;
        }
    }

    T pop_front() {


        Node<T>* temp = head;
        head = head->next;
        int i=temp->next->data;
        delete temp;
        head->prev= nullptr;
        return i;

    }
    T pop_back() {


        Node<T>* temp = tail;
        tail = tail->prev;
        int i=temp->prev->data;
        delete temp;
        tail->next= nullptr;
        return i;

    }

    void insert(T data, int pos){
        Node<T>* nuevo = new Node<T>;
        nuevo ->data=data;
        Node<T>* temp = head;
        int i = 0;
        while(i++ < pos -1) {temp = temp->next;}
        Node<T>* temp2 = temp->next;
        temp->next=nuevo;
        nuevo->prev=temp;
        nuevo->next=temp2;
        temp2->prev=nuevo;
    }

    void remove(int pos){
        Node<T>* temp = head;
        if (head== nullptr){ return;}
        else if(temp->next == nullptr || pos==0){T f=pop_front(); return;}
        else {
            int i = 0;
            while (i++ < pos - 1) { temp = temp->next; }

            Node<T>* temp3= temp->next;
            temp ->next=temp->next->next;
            Node<T>* temp2= temp->next;
            temp2->prev= temp2->prev->prev;
            delete temp3;
        }

    }
    bool is_empty(){
        if (head != nullptr){ return false;}
        else { return true;}
    }
    T size(){
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

                T aux = temp1->data;
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

        Node<T>* temp2=head;
        Node<T>* temp3=temp2->next;
        temp2->next= nullptr;
        temp2->prev=temp3;

        while (temp3 != nullptr){

            temp3->prev=temp3->next;
            temp3->next= temp2;
            temp2 = temp3;
            temp3= temp3->prev;
        }

        head=temp2;
    }
    std::string name(){
        return "DoubleList";
    }
};
#endif