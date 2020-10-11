/*/
Implementacion de la clase DoubleLL

Owen Jauregui Borbon - A01638122
Luis Humberto Sanchez Vaca - A0163129
Samuel Alejandro Diaz del Guante Ochoa - A01637592
/*/
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

// Funcion de preparacion para el ordenamiento por algoritmo 
// de ordenamiento "Quick Sort"
// No recibe parametros
// No devuelve ningun valor
void DoubleLL::quickSort() {
    // Se pasan los punteros de inicio y fin de la Double Linked List
    quickSort(this->head, this->tail);
}

// Funcion recursiva para el ordenamiento por el algoritmo "Quick Sort"
// Recibe dos punteros a Node para el inicio y fin del segmento
// que se va a ordenar para cada recursion
// No devuelve ningun valor
void DoubleLL::quickSort(Node* ini, Node* fin) {
    // Condicional para saber si el inicio esta antes que el fin
    // y si el fin aun sigue siendo un puntero valido
    if (fin != nullptr && ini != fin && fin->next != ini) {
        // Llamada a la funcion "particionar"
        Node* piv = particionar(ini, fin);
        // Recursion para ordenar los datos a la izquierda y a
        // la derecha del pivote
        quickSort(ini, piv->prev);
        quickSort(piv->next, fin);
    }
}

// Funcion para realizar la separacion de numeros mayores y 
// menores con respecto a un pivote (en este caso, el primer 
// elemento del segmento). Los numeros mayores se acomodan a la
// derecha del pivote, mientras los menores se colocan a su izquierda
// Recibe dos punteros a Node para el inicio y fin del segmento
// en el que se realizara la division
Node* DoubleLL::particionar(Node* ini, Node* fin) {
    // El nodo "ini" se selecciona como el pivote
    // Se toma la ip del primer elemento para las comparaciones
    unsigned long long piv = ini->data->getIp();
    // Se definen las variables i y j que serviran como indicadores
    // para los segmentos de elementos desordenados, los mayores 
    // al pivote y los menores al pivote
    Node *i = ini->next,
         *j = i;
    // Se hace un ciclo hasta que j llegue al final del segmento
    // a separar
    while (j != fin->next) {
        // en caso de que la Ip del dato en el puntero j sea menor
        // o igual al del pivote, se manda al segmento de los
        // elementos menores
        if (j->data->getIp() <= piv) {
            swap(i, j);
            // En caso de que i->next sea valido, se asigna el
            // puntero del siguiente siguiente nodo a i. De lo
            // contrario significa que pasamos el final de la
            // Double Linked List, por lo tanto se le asigna el
            // puntero al nodo "fin"
            i = (i->next == nullptr)? fin : i->next;
        }
        // Se avanza j, pasando al siguiente nodo a comparar
        j = j->next;
    }
    // En caso de que el elemento que sigue de i sea invalido,
    // se hace un intercambio del pivote (ini) con i, debido a 
    // que tuvimos que retroceder retroceder un elemento. 
    // Normalmente se haría el intercambio con el anterior a i
    if (i->next != nullptr){
        swap(ini, i->prev);
    } else {
        swap(ini, i);
    }
    return i->prev;
}

// Funcion para intercambiar los punteros a Entrada que contienen
// dos objetos de tipo Node distintos
// Recibe dos punteros a objetos de tipo Node
// No devuelve ningun valor
void DoubleLL::swap(Node* a, Node* b) {
    // Se guarde el data de b en una variable temporal
    Entrada* temp = b->data;
    // Se intercambian los valores de data con el uso de la
    // variable temporal
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
        stream << endl;
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