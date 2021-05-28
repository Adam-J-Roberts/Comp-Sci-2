#ifndef Donation_H
#define Donation_H
#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>  

using namespace std;

class Donation 
{
    private:
		string name;
		string item;
		string date;

    public:
		Donation();
		Donation(string date);
		Donation(string name, string item, string date);
		string get_name();
		string get_item();
		string get_date();
		void modify_donation_info(string name, string item, string date);
};
#endif 
