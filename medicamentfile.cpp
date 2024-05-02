//
// Created by alexp on 01/05/2024.
//

#include "medicamentfile.h"

using namespace std;

MedicamentFile::MedicamentFile() {
    cont = 0;
}

MedicamentFile::MedicamentFile(const string& fn) : dataFileName(fn + ".bin"), codesFileName(fn + "idx.bin") {
    dataFile.open(dataFileName, ios::app);
    if (!dataFile.is_open()) {
        throw ios_base::failure("No se pudo crear el archivo");
    }
    dataFile.open(dataFileName, ios::in | ios::out | ios::binary);
    if (!dataFile.is_open()) {
        throw ios_base::failure("No se puede abrir el archivo");
    }

    primaryIdxFile.open(codesFileName, ios::in);
    if (primaryIdxFile.is_open()){
        primaryIdxFile.clear();

        primaryIdxFile.seekg(0);
        while(primaryIdxFile.peek() != EOF) {
            Tuple<const char *> myTuple;
            primaryIdxFile.read((char *) &myTuple, sizeof(myTuple));

            idxByCodeList.push_back(myTuple);

            cont ++;
        }
        primaryIdxFile.close();
    }else{
        reindex();
    }
}

MedicamentFile::~MedicamentFile() {
    compress();
}

void MedicamentFile::writeToDisk(const Medicament& m, const int& p){
    dataFile.clear();

    dataFile.seekp(p*sizeof(Medicament), ios::beg);

    dataFile.write((char*) &m, sizeof(m));

}

Medicament MedicamentFile::readFromDisc(const int& p){
    Medicament myMedicament;

    dataFile.seekg(p*sizeof(Medicament), ios::beg);
    dataFile.read((char*) &myMedicament, sizeof(myMedicament));

    return myMedicament;
}

Medicament MedicamentFile::getRecord(const int& p){
    return readFromDisc(p);
}

void MedicamentFile::addRecord(const Medicament& m){
    writeToDisk(m, cont);
    Tuple<const char*> myTuple(cont, m.getCodigo());
    idxByCodeList.push_back(myTuple);
    cont ++;
}

void MedicamentFile::delRecord(const Medicament&, const int &) {

}

void MedicamentFile::editRecord(const Medicament& m, const int& p) {
    writeToDisk(m, p);
}

int MedicamentFile::searchRecord(const Medicament& m) const{
    auto it(idxByCodeList.begin());
    idxByCodeList;
    while(strcmp(m.getCodigo(), it->getData()) != 0){
        if(strcmp(m.getCodigo(), it->getData()) == 0)
            return it->getIndex();

        it++;
    }
    return -1;
}

int MedicamentFile::searchRecord(const char* c) const{
    Medicament myMedicaemnt;
    myMedicaemnt.setCodigo(c);
    return searchRecord(myMedicaemnt);
}

void MedicamentFile::reindex(){
    Medicament myMedicament;
    int pos = 0;

    dataFile.clear();
    dataFile.seekg(0);

    primaryIdxFile.open(codesFileName, ios_base::out | ios_base::trunc);
    if(!primaryIdxFile.is_open()){
        throw ios_base::failure("Error al abrir el archivo de indices");
    }
    if(!dataFile.is_open()){
        throw ios_base::failure("Error al abrir el archivo de data");
    }
    idxByCodeList.clear();

    while(dataFile.tellg() != EOF){
        myMedicament = readFromDisc(pos);
        Tuple<const char*> myTuple(pos, myMedicament.getCodigo());

        primaryIdxFile.seekp(pos*sizeof(Medicament), ios::beg);

        primaryIdxFile.write((char*) &myTuple, sizeof(myTuple));
        idxByCodeList.push_back(myTuple);
        pos++;
    }
    cont = pos;
    primaryIdxFile.close();
}

void MedicamentFile::compress() {

}

void MedicamentFile::clear() {

}
