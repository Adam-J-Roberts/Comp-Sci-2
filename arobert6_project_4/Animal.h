#ifndef Animal_H
#define Animal_H
#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>  

using namespace std;

class Animal
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
		virtual string get_name();
		virtual size_t get_age();
		virtual bool get_gender();
		virtual char get_type();
		virtual string get_id();
};
#endif 
