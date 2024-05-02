//
// Created by alexp on 01/05/2024.
//

#ifndef HOSPITALBINARIO_MEDICAMENTMENU_H
#define HOSPITALBINARIO_MEDICAMENTMENU_H

#include <iostream>
#include <string>

#include "medicamentfile.h"

class MedicamentMenu {
private:
    MedicamentFile* myMedicamentFileRef;

    void mainMenu();

    void addRecord();

    void editRecord();

    void delRecord();

    void findRecord();

    void enterToContinue();

public:
    MedicamentMenu(MedicamentFile&);
};


#endif //HOSPITALBINARIO_MEDICAMENTMENU_H
