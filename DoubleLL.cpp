#include "DoubleLL.h"

DoubleLL::DoubleLL(){
    this->tail = this->head = nullptr;
    size = 0;
}

DoubleLL::~DoubleLL()
{
    while (!isEmpty()){
        pull();
    }
}

int DoubleLL::length() {
    return this->size;
}

bool DoubleLL::isEmpty() {
    return this->size == 0;
}

void DoubleLL::push(Entrada* data) {
    if (isEmpty()){
        this->head = this->tail = new Node(data);
    }else{
        this->tail = this->tail->next = new Node(data, nullptr, this->tail);
    }
    this->size++;
}

void DoubleLL::pull() {
    if (!isEmpty()) {
        Node *current = this->head;
        this->head = this->head->next;
        this->size--;
        if (isEmpty()){
            this->tail = nullptr;
        }else{
            this->head->prev = nullptr;
        }
        delete current->data;
        delete current;
    }else {
        throw invalid_argument("Empty list");
    }
}