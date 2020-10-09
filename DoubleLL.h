#ifndef DOUBLELL_H
#define DOUBLELL_H

#include "Entrada.h"

struct Node{
    Entrada* data;
    Node* next;
    Node* prev;

    Node(Entrada* data, Node* next, Node* prev){
        this->data = data;
        this->next = next;
        this->prev = prev;
    }
    Node(Entrada* data):Node(data, nullptr, nullptr){}
};

class DoubleLL
{
    public:
        DoubleLL();
        ~DoubleLL();
        void push(Entrada* data);
        int length();
        bool isEmpty();
        void quickSort();
        int busqueda(unsigned long long ip, bool reverse);
        void print(ostream& stream, int ini, int fin);

    private:
        Node* head;
        Node* tail;
        int size;
        void pull();
        void quickSort(Node* ini, Node* fin);
        void swap(Node* a, Node* b);
        Node* particionar(Node* ini, Node* fin);
};

#endif
