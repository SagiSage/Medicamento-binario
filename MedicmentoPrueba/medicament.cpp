#include "medicament.h"

using namespace std;

Medicament::Medicament(){

}
void Medicament::setData(const MedicamentData& d){
    strcpy(myData.codigo, d.codigo);
    strcpy(myData.nombre, d.nombre);
}
MedicamentData Medicament::getData(){
    return myData;
}

string Medicament::toString(){
    string myStr;
    myStr = "Codigo: ";
    myStr += myData.codigo;
    myStr += "|Nombre: ";
    myStr += myData.nombre;
    return myStr;
}

Medicament::Medicament(const MedicamentData& d){
    myData = d;
}

Medicament::Medicament(const Medicament& m){
    *this = m;
}

void Medicament::setCode(const char* c){
    strcpy(myData.codigo, c);
}

void Medicament::setName(const char* n){
    strcpy(myData.codigo, n);
}

const char* Medicament::getName(){
    return myData.nombre;
}

const char* Medicament::getCode(){
    return myData.codigo;
}

Medicament &Medicament::operator=(const Medicament& m){
    strcpy(myData.codigo, m.myData.codigo);
    strcpy(myData.nombre, m.myData.nombre);
    return *this;
}


bool Medicament::operator==(const Medicament& m) const{
    return strcmp(myData.codigo, m.myData.codigo);
}

bool Medicament::operator!=(const Medicament& m) const{
    return !(*this == m);

}

bool Medicament::operator<(const Medicament& m) const{
    return strcmp(myData.codigo, m.myData.codigo) > 0;

}

bool Medicament::operator>(const Medicament& m) const{
    return !(*this <= m);
}

bool Medicament::operator<=(const Medicament& m) const{
    return *this < m || *this == m;

}

bool Medicament::operator>=(const Medicament& m) const{
    return !(*this < m);
}

void Medicament::writeToDisk(const int& p){
    fstream doc;
    doc.open("medicamentData.bin", ios::app);
    if(!doc.is_open()){
        cout << "Error al crear o abrir el archivo" << endl;
    }
    doc.close();
    doc.open("medicamentData.bin", ios::in | ios::out | ios::binary);
        if(!doc.is_open()){
        cout << "Error al abrir el archivo" << endl;
    }

    doc.seekp(p*sizeof(myData), ios::beg);
    doc.write((char *) &myData, sizeof(myData));
    doc.close();
}

Medicament Medicament::readFromDisk(const int& p){
    fstream doc;
    Medicament myMedicament;
    doc.open("medicamentData.bin", ios::in | ios::binary);
    if(!doc.is_open()){
        cout << "Error al abrir el archivo" << endl;
    }
    doc.seekg(p*sizeof(myData), ios::beg);
    doc.read((char*) &myData, sizeof(myData));
    myMedicament.setData(myData);
    doc.close();
    return myMedicament;
}

