#ifndef MEDICAMENTFILE_H
#define MEDICAMENTFILE_H

#include <fstream>
#include <list>
#include <sstream>
#include <filesystem>

#include "medicament.h"
#include "tuple.h"

class MedicamentFile {
private:
    std::fstream dataFile;
    std::fstream idxByCodeFile;

    std::string fileName;
    std::string idxFileName;

    std::list<Tuple<const char[10]>> idxByCodeList;

public:
    MedicamentFile();

    MedicamentFile(const std::string&);

    ~MedicamentFile();

    Medicament getRecord(const int&);

    void addRecord(const Medicament&);
    void delRecord(const int&);

    int findRecord(const Medicament&);
    int findRecord(const std::string&);
    std::list<int> findRecordName(const Medicament&);
    std::list<int> findRecordName(const std::string&);

    void clear();
    void reindex();
    void compress();
};


#endif // MEDICAMENTFILE_H
