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

void DoubleLL::quickSort() {
    quickSort(this->head, this->tail);
}

void DoubleLL::quickSort(Node* ini, Node* fin) {
    if (fin && ini != fin && fin->next != ini) {
        Node* piv = particionar(ini, fin);
        quickSort(ini, piv->prev);
        quickSort(piv->next, fin);
    }
}

Node* DoubleLL::particionar(Node* ini, Node* fin) {
    unsigned long long piv = ini->data->getIp();
    Node *i = ini->next,
         *j = i;
    while (j != fin->next) {
        if (j->data->getIp() < piv) {
            swap(i, j);
            i = i->next;
        }
        j = j->next;
    }
    swap(ini, i->prev);
    return i->prev;
}

void DoubleLL::swap(Node* a, Node* b) {
    Entrada* temp = b->data;
    b->data = a->data;
    a->data = temp;
}

void DoubleLL::print(ostream &stream, int ini, int fin) {
    //int cont = ini;
    Node* current = this->head;
    for (int i = 0; i < ini; i++){
        current = current->next;
    }
    for (int i = ini; i <= fin; i++){
        current->data->print(stream);
        cout << endl;
        current = current->next;
    }
}

int DoubleLL::busqueda(unsigned long long ip, bool reverse) {
    Node* current;
    int pos;
    if (!reverse){
        current = this->head;
        pos = 0;
        while (current != nullptr){
            unsigned long long ipAux = current->data->getIp() / 10000;
            if (ipAux >= ip){
                return pos;
            }else{
                current = current->next;
                pos++;
            }
        }
    }else{
        current = this->tail;
        pos = this->size - 1;
        while (current != nullptr){
            unsigned long long ipAux = current->data->getIp() / 10000;
            if (ipAux <= ip){
                return pos;
            }else{
                current = current->prev;
                pos--;
            }
        }
    }
    return -1;
}