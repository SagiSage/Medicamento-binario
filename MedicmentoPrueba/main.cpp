#include <iostream>

#include "medicament.h"
#include "medicamentData.h"

using namespace std;

int main()
{
    int cont = 0;
    int pos;
    char opc;
    do{
    cout << "1.-Aniadir registro" << endl;
    cout << "2.-Buscar registro" << endl;
    cout << "3.-Salir" << endl;
    cin >> opc;
    cin.ignore();
    switch(opc){
        case '1':{
            MedicamentData myData;
            Medicament  myMedicament;
            cout << "Codigo: ";
            cin.getline(myData.codigo, 10);
            cout << "Nombre; ";
            cin.getline(myData.nombre, 50);
            myMedicament.setData(myData);
            myMedicament.writeToDisk(cont);
            cont++;
            cout << "Medicameto agregado" << endl;
            cout << "Presione enter para continuar" << endl;
            getchar();
            break;

        }
        case '2':{
            MedicamentData myData;
            Medicament myMedicament;
            cout << "Numero de registro: ";
            cin >> pos;
            myMedicament = myMedicament.readFromDisk(pos);
            cout << myMedicament.toString();
            cout << "\nMedicamento encontrado" << endl;
            cout << "Presione enter para continuar" << endl;
            getchar();
            break;
        }
    }
    }while(opc != '3');
}
