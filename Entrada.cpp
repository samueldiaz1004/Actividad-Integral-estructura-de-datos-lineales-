#include "Entrada.h"

Entrada::Entrada(string linea)
{
    vector<string> segmento{"","","","",""};
    vector<string> segmentoIp{"","","","",""};

    separacion(segmento,linea);
    separacionIp(segmentoIp,segmento[3]);

    this->mes = segmento[0];
    this->dia = segmento[1];
    this->hora = segmento[2];
    this->ip = segmento[3];
    this->mensaje = segmento[4];

    convertirIp(segmentoIp);
}

unsigned long long Entrada::getIp()
{
    return this->id;
}

void Entrada::print(ostream &stream)
{
    stream << this->mes << " "
           << this->dia << " "
           << this->hora << " "
           << this->ip << " "
           << this->mensaje;
}

void Entrada::separacion(vector<string> &datos, string linea)
{
    int espacios = 0;
    for(auto j : linea){
        if(j == ' ' && espacios < 4){
            espacios++;
        }
        else{
            datos[espacios] += j;
        }
    }
}

void Entrada::separacionIp(vector<string> &datos, string linea)
{
    int espacios = 0;
    for(auto j : linea){
        if(j == '.' || j == ':'){
            espacios++;
        }
        else{
            datos[espacios] += j;
        }
    }
}

void Entrada::convertirIp(vector<string> datosIp)
{
    this->id = stoi(datosIp[4]);
    this->id += stoi(datosIp[3]) * pow(10,4);
    this->id += stoi(datosIp[2]) * pow(10,6);
    this->id += stoi(datosIp[1]) * pow(10,9);
    this->id += stoi(datosIp[0]) * pow(10,11);
}
