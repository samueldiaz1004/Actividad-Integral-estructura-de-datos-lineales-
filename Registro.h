#ifndef REGISTRO_H
#define REGISTRO_H

#include "DoubleLL.h"
#include <fstream>
#include <string>

class Registro
{
    public:
        Registro(string fileName);
        void quickSort();
        void guardar(string fileName);
        void busqueda(string ipIni, string ipFin);
        void print(ostream& stream);

    private:
        DoubleLL bitacora;
        void print(ostream& stream, int ini, int fin);
        void separar(vector<string> &datos, string linea);

};

#endif
