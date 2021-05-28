#ifndef Bird_H
#define Bird_H
#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>  
#include "Animal.h"

using namespace std;

class Bird : public Animal
{
    private:

    public:
		Bird();
		//Bird(string id);
		Bird(string name, size_t age, bool gender, string id, char type);
		void print_info();
		void modify_animal_info(string name, size_t age, bool gender, string id);
		string get_name();
		size_t get_age();
		bool get_gender();
		char get_type();
		string get_id();
};
#endif 
