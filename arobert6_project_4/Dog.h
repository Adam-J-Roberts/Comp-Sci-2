#ifndef Dog_H
#define Dog_H
#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>  
#include "Animal.h"

using namespace std;

class Dog : public Animal
{
    private:
        string breed;

    public:
		Dog();
		Dog(string name, size_t age, bool gender, string id, char type, string breed);
		//Dog(string id);
		void print_info();
		void modify_animal_info(string name, size_t age, bool gender, string id);
		string get_name();
		size_t get_age();
		bool get_gender();
		char get_type();
		string get_id();
		string get_breed();

};
#endif 
