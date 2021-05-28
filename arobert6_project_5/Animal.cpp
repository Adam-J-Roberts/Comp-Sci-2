#include "Animal.h"
#include "Entry.h"

Animal::Animal(){}
Animal::Animal (string name, size_t age, bool gender, string id, char type)
{
	this->name = name;
	this->age = age;
	this->gender = gender;
	this->id = id;
	this->type = type;
}
void Animal::modify_animal_info(string name, size_t age, bool gender, string id)
{
	this->name = name;
	this->age = age;
	this->gender = gender;
	this->id = id;			
}
void Animal::print_info()
{
	string age1;
	int count;
	
	cout << id;
	cout << setfill(' ') << setw(7) << " ";
		stringstream ss;
		ss << age;
		age1 = ss.str();
		count = 5 - age1.length();
		age1.append(count, ' ');
	cout << age1;
	cout << setfill(' ') << setw(4) << " ";
	
	if (type == 'D' || type == 'd')
	{
		cout << "Dog";
		cout << setfill(' ') << setw(14) << " ";
	}
	else if (type == 'C' || type == 'c')
	{
		cout << "Cat";
		cout << setfill(' ') << setw(14) << " ";
	}
	else if (type == 'B' || type == 'b')
	{
		cout << "Bird";
		cout << setfill(' ') << setw(13) << " ";
	}
	if (gender == 1)
	{
		cout << "Male";
		cout << setfill(' ') << setw(8) << " ";
	}
		if (gender == 0)
	{
		cout << "Female";
		cout << setfill(' ') << setw(6) << " ";
	}
	
	cout << name << endl;

}
string Animal::get_name() 
{
	return name;
}
size_t Animal::get_age()
{
	return age;
}
bool Animal::get_gender()
{
	return gender;
}
char Animal::get_type()
{
	return type;
}
string Animal::get_id()
{
	return id;
}





