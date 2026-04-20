#ifndef DOORGENERATOR_H
#define DOORGENERATOR_H
#include "DoorParameters.h"
#include "CustomTypesAndAliases.h"
#include "Random.h"
#include "Constants.h"
// generates door and sets "DoorParameters" based on its type
DoorParameters* getDoor(CustomTypes::DoorType type);



#endif // !UNIVERSEGENERATOR_H
