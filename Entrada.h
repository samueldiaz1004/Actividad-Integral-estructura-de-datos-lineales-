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
        int getIp();
        void print(ostream &stream);

    private:
        string ip;
        string mensaje;
        string mes;
        string dia;
        string hora;
        int id;
        void separacion(vector<string> &datos, string linea, string chars);
        int convertirIp(string ip);
        void separacionIp(vector<string> &datos, string linea);

};

#endif
