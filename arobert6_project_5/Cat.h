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
		void modify_animal_info(string name, size_t age, bool gender, string id);

};
#endif 
