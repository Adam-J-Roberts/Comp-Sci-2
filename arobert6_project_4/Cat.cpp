#include "Animal.h"
#include "Cat.h"

	
Cat::Cat(){}
Cat::Cat(string name, size_t age, bool gender, string id, char type)
	: Animal (name, age, gender, id, type)
{
}
//Cat::Cat(string id)
//{
//	Cat : Animal::get_id(id);
//}
void Cat::print_info()
{
	this->Animal::print_info();
}
void Cat::modify_animal_info(string name, size_t age, bool gender, string id)
{
	this->Animal::modify_animal_info(name, age, gender, id);
}
string Cat::get_name()
{
	return this->Animal::get_name();
}
size_t Cat::get_age()
{
	return this->Animal::get_age();
}
bool Cat::get_gender()
{
	return this->Animal::get_gender();
}
char Cat::get_type()
{
	return this->Animal::get_type();
}
string Cat::get_id()
{
	return this->Animal::get_id();
}
