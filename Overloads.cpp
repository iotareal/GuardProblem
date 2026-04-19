#include "Overloads.h"
std::ostream& operator<<(std::ostream& cout, CustomTypes::Smells smell) {
switch (smell)
{
case CustomTypes::Smells::machine_oils:
	cout << "machine_oils";
	break;
case CustomTypes::Smells::grass:
	cout << "grass";
	break;
default:
	cout << "nothing?";
	break;
}
return cout;
}