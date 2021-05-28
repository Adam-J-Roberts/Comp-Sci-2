#include "Animal.h"
#include "Dog.h"


Dog::Dog(){}
Dog::Dog(string name, size_t age, bool gender, string id, char type, string breed) 
	: Animal (name, age, gender, id, type)
{
	this->breed = breed;	
}
//Dog::Dog(string id) 
//{
//	Dog : Animal::get_id (id);
//}
void Dog::print_info()
{
		this->Animal::print_info();
		//cout << breed << endl;
}
void Dog::modify_animal_info(string name, size_t age, bool gender, string id)
{
	this->Animal::modify_animal_info(name, age, gender, id);
}
string Dog::get_name()
{
	return this->Animal::get_name();
}
size_t Dog::get_age()
{
	return this->Animal::get_age();
}
bool Dog::get_gender()
{
	return this->Animal::get_gender();
}
char Dog::get_type()
{
	return this->Animal::get_type();
}
string Dog::get_id()
{
	return this->Animal::get_id();
}
string Dog::get_breed()
{
	return breed;
}
