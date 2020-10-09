#include "Registro.h"

Registro::Registro(string fileName)
{
    ifstream archivo;
    string line;
    archivo.open(fileName);

    while(getline(archivo,line)){
        bitacora.push(); // Revisar implementacion en DoubleLL
    }
    archivo.close();
}

void Registro::quickSort()
{
    bitacora.quickSort();
}

void Registro::guardar(string fileName)
{
    ofstream archivo;
    archivo.open(fileName);
    print(archivo);
    archivo.close();
}
// ipIni e ipFin no contienen el puerto. Ejemplo: 423.2.230.77
void Registro::busqueda(string ipIni, string ipFin)
{
    vector<string> ini = {"","","",""};
    vector<string> fin = {"","","",""};
    unsigned long long ip1, ip2;

    separar(ini,ipIni);
    separar(fin,ipFin);

    ip1 = stoi(ini[3]) * pow(10,4);
    ip1 += stoi(ini[2]) * pow(10,6);
    ip1 += stoi(ini[1]) * pow(10,9);
    ip1 += stoi(ini[0]) * pow(10,11);

    ip2 = stoi(fin[3]) * pow(10,4);
    ip2 += stoi(fin[2]) * pow(10,6);
    ip2 += stoi(fin[1]) * pow(10,9);
    ip2 += stoi(fin[0]) * pow(10,11);

    int indiceIni = bitacora.busqueda(ip1,0); //Revisar implementacion en DoubleLL
    int indiceFin = bitacora.busqueda(ip2,1);

    print(cout,indiceIni,indiceFin);
}

void Registro::print(ostream& stream)
{
    for(auto i : this->bitacora){ //Revisar implementacion en DoubleLL
    i->print(stream);
    }
}

void Registro::print(ostream& stream, int ini, int fin)
{
    this->bitacora.print(cout,ini,fin);
}

void Registro::separar(vector<string> &datos, string linea)
{
    int espacios = 0;
    for(auto j : linea){
        if(j == '.'){
            espacios++;
        }
        else{
            datos[espacios] += j;
        }
    }
}
