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