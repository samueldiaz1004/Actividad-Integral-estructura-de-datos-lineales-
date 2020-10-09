#include <iostream>
#include "Registro.h"
using namespace std;

int main()
{
    Registro r("bitacora.txt");
    r.quickSort();
    //r.busqueda("1.5.180.51", "1.29.485.71");
    r.print(cout);
    return 0;
}
