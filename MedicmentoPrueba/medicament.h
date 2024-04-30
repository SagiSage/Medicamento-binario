#ifndef MEDICAMENT_H
#define MEDICAMENT_H

#include <iostream>
#include <string>
#include <cstring>
#include <fstream>

#include "medicamentData.h"

class Medicament{
private:
    MedicamentData myData;
public:
    Medicament();
    Medicament(const MedicamentData&);
    Medicament(const Medicament&);

    void setCode(const char*);
    void setName(const char*);

    const char* getName();
    const char* getCode();

    void setData(const MedicamentData&);
    MedicamentData getData();

    Medicament& operator = (const Medicament&);

    bool operator==(const Medicament&) const;
    bool operator!=(const Medicament&) const;
    bool operator<(const Medicament&) const;
    bool operator>(const Medicament&) const;
    bool operator<=(const Medicament&) const;
    bool operator>=(const Medicament&) const;

    std::string toString();

    void writeToDisk(const int&);
    Medicament readFromDisk(const int&);
};

#endif // MEDICAMENT_H
