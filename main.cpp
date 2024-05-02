#include <iostream>

#include "medicamentmenu.h"

int main() {
    MedicamentFile myMedicamentFileRef("medicament");

    new MedicamentMenu(myMedicamentFileRef);
}
