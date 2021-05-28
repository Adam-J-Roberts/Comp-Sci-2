#ifndef Cat_H
#define Cat_H
#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>  
#include "Animal.h"

using namespace std;

class Cat : public Animal
{
    private:	

    public:		
		Cat();
		Cat(string name, size_t age, bool gender, string id, char type);
		//Cat(string id);
		void print_info();
		void modify_animal_info(string name, size_t age, bool gender, string id);
		string get_name();
		size_t get_age();
		bool get_gender();
		char get_type();
		string get_id();
};
#endif 
