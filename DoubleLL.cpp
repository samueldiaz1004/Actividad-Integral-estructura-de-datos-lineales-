#include "DoubleLL.h"

DoubleLL::DoubleLL(){
    this->tail = this->head = nullptr;
    size = 0;
}

DoubleLL::~DoubleLL()
{
    //dtor
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
}