#ifndef OVERLOADS_H
#define OVERLOADS_H

#include <iostream>
#include "CustomTypesAndAliases.h"
// Operator overload to print values from Smell enum
std::ostream& operator<<(std::ostream& cout, CustomTypes::Smells smell);

// Operator overload to print values from DoorType enum
std::ostream& operator<<(std::ostream& cout, CustomTypes::DoorType door);


#endif // !OVERLOADS_H
