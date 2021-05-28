#ifndef Animal_H
#define Animal_H
#include "Entry.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>  

using namespace std;

class Animal : public Entry
{
	private: 
		string name;
		size_t age;
		bool gender;
		string id;
		char type;

	public:
		Animal ();
		Animal (string name, size_t age, bool gender, string id, char type);
		virtual void modify_animal_info(string name, size_t age, bool gender, string id);
        virtual void print_info();
		string get_name();
		size_t get_age();
		bool get_gender();
		char get_type();
		string get_id();
};
#endif 
