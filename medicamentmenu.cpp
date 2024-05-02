//
// Created by alexp on 01/05/2024.
//

#include "medicamentmenu.h"

using namespace std;

void MedicamentMenu::mainMenu() {
    char opc;
    do{
    cout << "1.-Agregar" << endl;
    cout << "2.-Buscar" << endl;
    cout << "3.-Salir" << endl;
    cin >> opc;
    cin.ignore();
    switch (opc){
        case '1':{
            addRecord();
            break;
        }
        case '2':{
            findRecord();
            break;
        }
        case '3':{
            break;
        }
        default:{
            cout << "Opcion invalida" << endl;
            enterToContinue();
        }
    }
    }while(opc != '3');
}

void MedicamentMenu::addRecord(){
    Medicament myMedicament;
    char myChar[30];
    cout << "Codigo: ";
    cin.getline(myChar, 10);
    myMedicament.setCodigo(myChar);
    cout << "Nombre: ";
    cin.getline(myChar, 30);
    myMedicament.setNombre(myChar);
    myMedicamentFileRef->addRecord(myMedicament);
    cout << "Medicamento agregado" << endl;
    enterToContinue();
}

void MedicamentMenu::editRecord() {

}

void MedicamentMenu::delRecord() {

}

void MedicamentMenu::findRecord() {
    int pos;
    char miChar[10];
    cout << "Codigo a buscar: ";
    cin.getline(miChar, 10);
    pos = myMedicamentFileRef->searchRecord(miChar);
    if(pos == -1){
        cout << "Medicamento no encontrado" << endl;
        enterToContinue();
        return;
    }
    cout << "Medicamento encontrado" << endl;
    cout << myMedicamentFileRef->getRecord(pos).toString() << endl;
    enterToContinue();
    cout << myMedicamentFileRef->getRecord(0).toString() << endl;
}

void MedicamentMenu::enterToContinue() {
    cout << "Presione enter para continuar";
    getchar();
}

MedicamentMenu::MedicamentMenu(MedicamentFile& m) : myMedicamentFileRef(&m){
    mainMenu();
}
