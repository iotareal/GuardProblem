#ifndef DECISIONMAKER_H
#define DECISIONMAKER_H

#include "Conditions.h"

bool isDoorSafe(Conditions& door);
bool isDoorStart(Conditions& door);
bool isDoorTrap(Conditions& door);
bool isDoorUnknown(Conditions& door);

#endif // !DECISIONMAKER_H
