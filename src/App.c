/**
*
* @author Elvin Valiyev - elvin.valiyev@sakarya.edu.tr
* @since 18.05.2025
* <p>
* Main
* </p>
*
*/


#include "Simulator.h"

int main() {
    Simulator* simulator = Construct_Simulator();
    if (!simulator) {
        printf("Simulator oluşturulamadı.\n");
        return 1;
    }

    simulator->ProgramStartFunc(simulator);

    return 0;
}