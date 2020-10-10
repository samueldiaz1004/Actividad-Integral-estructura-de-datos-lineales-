#include <iostream>
#include "Registro.h"
using namespace std;

int main()
{
    bool opcion;
    string ipIni;
    string ipFin;
    Registro bitacora("bitacora.txt");
    bitacora.quickSort();
    bitacora.guardar("bitacoraOrdenada.txt");
    do{
        cout << "Selecciona una opcion:" << endl;
        cout << "1. Realizar busqueda" << endl;
        cout << "0. Salir del programa" << endl;
        cin >> opcion;
        if(opcion){
            cin.ignore();
            cout << "Ip inicio: ";
            getline(cin,ipIni);
            cout << "Ip fin: ";
            getline(cin,ipFin);
            cout << "Resultados" << endl;
            bitacora.busqueda(ipIni,ipFin);
            cout << endl;
        }
    }
    while(opcion);
    return 0;
}
