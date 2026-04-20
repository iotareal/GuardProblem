#include <iostream>
#include "GuardLogic.h"
#include "Overloads.h"


int main() {
    while (true) {
        Universe* currentWorld = new Universe();

        const int doorNumber = mainGuard(currentWorld);

        const auto* chosenDoor = currentWorld->inspectDoor(doorNumber);

        if (!chosenDoor) {
            std::cout << " --- [SYSTEM]: Guard picked an invalid door! --- \n";
            break;
        }

        if (chosenDoor->checkDoorType(CustomTypes::DoorType::safe)) {
            std::cout << " --- [SYSTEM]: Guard picked safe exit --- \n";
            break;
        }
        else if (chosenDoor->checkDoorType(CustomTypes::DoorType::start)) {
            std::cout << " --- [SYSTEM]: Guard picked starting door --- \n";
            std::cout << " --- [RESET] --- \n";
            delete currentWorld;
            currentWorld = nullptr;
            continue;
        }
        else {
            std::cout << " --- [SYSTEM]: Guard picked the wrong door --- \n";
        }
        delete currentWorld;
        currentWorld = nullptr;
    }
    return 0;
}