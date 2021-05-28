#ifndef Entry_H
#define Entry_H
#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>  


using namespace std;

class Entry 
{

	protected:
		string entry_id; // a random 5 digit number set when an entry is created
	
	public:
		bool type; // this should be set to tell us if the entry is an Animal or Donation
		Entry();
 		string get_entry();
 		bool set_breed();
 		
};
#endif 
