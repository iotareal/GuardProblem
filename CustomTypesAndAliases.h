#ifndef CUSTOMTYPESANDALIASES_H
#define CUSTOMTYPESANDALIASES_H
class Conditions;
// Type aliases
namespace TypeAliases {
	using Celcius = double;
	using Decibel = double;
}

// Custom Types
namespace CustomTypes {

	// scoped enum for smells
	enum class Smells : short
	{
		nothing = 0,
		grass,
		machine_oils,
	};

	struct Universe 
	{
		Conditions *door_1{ nullptr };
		Conditions *door_2{ nullptr };
		Conditions *door_3{ nullptr };
	};
}

#endif // !CUSTOMTYPESANDALIASES_H
