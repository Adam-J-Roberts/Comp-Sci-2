#include "Animal.h"
#include "Bird.h"


Bird::Bird(){}
//Bird::Bird(string id)
//{
//	Bird : Animal::get_id (id);
//}
Bird::Bird(string name, size_t age, bool gender, string id, char type)
	: Animal (name, age, gender, id, type)
{
}
void Bird::print_info()
{
	this->Animal::print_info();
}
void Bird::modify_animal_info(string name, size_t age, bool gender, string id)
{
	this->Animal::modify_animal_info(name, age, gender, id);
}
string Bird::get_name()
{
	return this->Animal::get_name();
}
size_t Bird::get_age()
{
	return this->Animal::get_age();
}
bool Bird::get_gender()
{
	return this->Animal::get_gender();
}
char Bird::get_type()
{
	return this->Animal::get_type();
}
string Bird::get_id()
{
	return this->Animal::get_id();
}
