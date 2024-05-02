//
// Created by alexp on 01/05/2024.
//

#ifndef HOSPITALBINARIO_MEDICAMENTFILE_H
#define HOSPITALBINARIO_MEDICAMENTFILE_H

#include <fstream>
#include <string>
#include <list>

#include "medicament.h"
#include "tuple.h"

class MedicamentFile{
private:
    int cont;

    std::fstream dataFile;
    std::fstream primaryIdxFile;

    std::string dataFileName;
    std::string codesFileName;

    std::list<Tuple<const char*>> idxByCodeList;
public:
    MedicamentFile();
    MedicamentFile(const std::string&);

    ~MedicamentFile();

    void writeToDisk(const Medicament&, const int&);
    Medicament readFromDisc(const int&);

    Medicament getRecord(const int&);

    void addRecord(const Medicament&);
    void delRecord(const Medicament&, const int&);

    void editRecord(const Medicament&, const int&);

    int searchRecord(const Medicament&) const;
    int searchRecord(const char*) const;

    void reindex();
    void compress();
    void clear();
};


#endif //HOSPITALBINARIO_MEDICAMENTFILE_H
