//
// Created by alexp on 01/05/2024.
//

#include "medicament.h"

using namespace std;

Medicament::Medicament() {

}

Medicament::Medicament(const Medicament& m) {

}

Medicament::Medicament(const char *, const char *) {

}

const char* Medicament::getCodigo() const {
    return codigo;
}

const char* Medicament::getNombre() const {
    return nombre;
}

void Medicament::setCodigo(const char* c) {
    strcpy(codigo, c);
}

void Medicament::setNombre(const char* n) {
    strcpy(nombre, n);
}

string Medicament::toString() const{
    string myStr;

    myStr += "Codigo: ";
    myStr += codigo;
    myStr += "|Nombre: ";
    myStr += nombre;

    return myStr;
}

Medicament& Medicament::operator=(const Medicament& m){
    strcpy(codigo, m.codigo);
    strcpy(nombre, m.nombre);
    return *this;
}


bool Medicament::operator==(const Medicament& m) const{
    return strcmp(codigo, m.codigo) == 0;
}

bool Medicament::operator!=(const Medicament& m) const{
    return !(*this == m);

}

bool Medicament::operator<(const Medicament& m) const{
    return strcmp(codigo, m.codigo) > 0;

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