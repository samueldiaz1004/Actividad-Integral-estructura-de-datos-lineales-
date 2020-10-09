#include "Registro.h"

Registro::Registro(string fileName)
{
    ifstream archivo;
    string line;
    archivo.open(fileName);

    while(getline(archivo,line)){
        bitacora.push(new Entrada(line));
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

    ip1 = stoi(ini[3]);
    ip1 += stoi(ini[2]) * pow(10,2);//Comprobar potencias
    ip1 += stoi(ini[1]) * pow(10,5);
    ip1 += stoi(ini[0]) * pow(10,7);

    ip2 = stoi(fin[3]);
    ip2 += stoi(fin[2]) * pow(10,2);
    ip2 += stoi(fin[1]) * pow(10,5);
    ip2 += stoi(fin[0]) * pow(10,7);

    int indiceIni = bitacora.busqueda(ip1,false);
    int indiceFin = bitacora.busqueda(ip2,true);

    print(cout,indiceIni,indiceFin);
}

void Registro::print(ostream& stream)
{
    bitacora.print(stream, 0, bitacora.length() - 1);
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
