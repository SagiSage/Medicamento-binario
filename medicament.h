//
// Created by alexp on 01/05/2024.
//

#ifndef HOSPITALBINARIO_MEDICAMENT_H
#define HOSPITALBINARIO_MEDICAMENT_H

#include <iostream>
#include <string>
#include <cstring>

class Medicament {
private:
    char codigo[10];
    char nombre[30];

public:
    Medicament();
    Medicament(const Medicament&);
    Medicament(const char*, const char*);

    const char* getCodigo() const;
    const char* getNombre() const;

    void setCodigo(const char*);
    void setNombre(const char*);

    std::string toString() const;

    Medicament& operator = (const Medicament&);

    bool operator==(const Medicament&) const;
    bool operator!=(const Medicament&) const;
    bool operator<(const Medicament&) const;
    bool operator>(const Medicament&) const;
    bool operator<=(const Medicament&) const;
    bool operator>=(const Medicament&) const;

};


#endif //HOSPITALBINARIO_MEDICAMENT_H
