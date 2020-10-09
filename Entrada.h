#ifndef ENTRADA_H
#define ENTRADA_H

#include <iostream>
#include <vector>
#include <math.h>
#include <string>

using namespace std;

class Entrada
{
    public:
        Entrada(string linea);
        unsigned long long getIp();
        void print(ostream &stream);

    private:
        string mes;
        string dia;
        string hora;
        string ip;
        string mensaje;
        unsigned long long id;
        void separacion(vector<string> &datos, string linea);
        void separacionIp(vector<string> &datos, string linea);
        void convertirIp(vector<string> datosIp);

};

#endif
