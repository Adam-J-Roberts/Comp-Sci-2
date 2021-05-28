#include "Animal.h"
#include "Cat.h"

	
Cat::Cat(){}
Cat::Cat(string name, size_t age, bool gender, string id, char type)
	: Animal (name, age, gender, id, type)
{
}
/*Cat::Cat(string id)
{
	this->string = string;
}*/
void Cat::modify_animal_info(string name, size_t age, bool gender, string id)
{
	this->Animal::modify_animal_info(name, age, gender, id);
}

