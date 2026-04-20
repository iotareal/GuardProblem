#ifndef CUSTOMTYPESANDALIASES_H
#define CUSTOMTYPESANDALIASES_H
class Conditions;
// Type aliases to avoid type mismatches
namespace TypeAliases {
	using Celcius = double;
	using Decibel = double;
}

// Custom Types includes scoped enums for custom literals
namespace CustomTypes {

	// scoped enum for smells
	enum class Smells : short
	{
		nothing = 0,
		grass,
		machineOils,
		unknown,
	};

	enum class DoorType : short
	{
		unknown = 0,
		trap,
		start,
		safe,
	};
}

#endif // !CUSTOMTYPESANDALIASES_H
