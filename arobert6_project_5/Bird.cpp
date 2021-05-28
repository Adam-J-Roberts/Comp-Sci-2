#include "Animal.h"
#include "Bird.h"


Bird::Bird(){}
/*Bird::Bird(string id)
{
	this->string = string
}*/
Bird::Bird(string name, size_t age, bool gender, string id, char type)
	: Animal (name, age, gender, id, type)
{
}
void Bird::modify_animal_info(string name, size_t age, bool gender, string id)
{
	this->Animal::modify_animal_info(name, age, gender, id);
}


