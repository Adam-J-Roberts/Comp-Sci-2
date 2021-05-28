#include "Donation.h"
#include "Entry.h"


Donation::Donation(){}
Donation::Donation(string name, string item, string date)
{
	this->name = name;
	this->item = item;
	this->date = date;
}
Donation::Donation(string date)
{
	this->date = date;
}
string Donation::get_name()
{
       return name;
}
string Donation::get_item()
{
        return item;
}   
string Donation::get_date()
{
        return date;
}
void Donation::modify_donation_info(string name, string item, string date)
{
	this->name = name;
	this->item = item;
	this->date = date;
}
