#include "Animal.h"
#include "Dog.h"


Dog::Dog(){}
Dog::Dog(string name, size_t age, bool gender, string id, char type, string breed) 
	: Animal (name, age, gender, id, type)
{
	this->breed = breed;	
}
/*Dog::Dog(string id) 
{
	this->string = string
{*/
void Dog::print_info()
{
		this->Animal::print_info();
		//cout << breed << endl; Work this in!
}
void Dog::modify_animal_info(string name, size_t age, bool gender, string id)
{
	this->Animal::modify_animal_info(name, age, gender, id);
}
string Dog::get_breed()
{
	return breed;
}

