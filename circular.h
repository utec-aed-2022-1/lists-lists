#ifndef CIRCULAR_H
#define CIRCULAR_H
#include <iostream>
#include "list.h"

// TODO: Implement all methods
template <typename T>
class CircularList : public List<T> {
private:
    Node<T>* head;//sentinel
    int nodes;
public:
    CircularList() : List<T>() {

        head= new Node<T>;
        head->next=head;
        head->prev=head;
    }

    ~CircularList(){
        delete head;
    }



    T front(){

    }

    T back(){

    }

    void push_front(T data){

        Node<T>* nuevo = new Node<T>;
        nuevo->data=data;
        nuevo->next=head->next;
        nuevo->prev=head;
        head->next->prev=nuevo;
        head->next=nuevo;

    }

    void push_back(T data){

    }

    T pop_front(){

    }

    T pop_back(){

    }

    void insert(T data, int pos){

    }

    void remove(int pos){

    }

    T& operator[](int pos){

    }

    bool is_empty(){

    }

    int size(){

    }

    void clear(){

    }

    void sort(){

    }

    bool is_sorted(){

    }

    void reverse(){

    }

    std::string name(){
        return "CircularList";
    }

};

#endif
