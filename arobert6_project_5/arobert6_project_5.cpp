#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <ofstream>
#include <string>
#include <sstream>
#include <vector>  

using namespace std;

void print_menu();
double get_selection();
void input_new_animal(vector<Entry*> &entries);
void input_new_donation(vector<Entry*> &entries);
void print_all(vector<Entry*> &entries);
void print_by_type(vector<Entry*> &entries);
void print_donations(vector<Entry*> &entries);
string assign_id();
void save_animals(vector<Entry*> &entries);
void load_animals(vector<Entry*> &entries);
void save_donations(vector<Entry*> &entries);
void load_donations(vector<Entry*> &entries);
void delete_animal(vector<Entry*> &entries);
void delete_donor(vector<Entry*> &entries);



int main()
{

	vector<Entry*> entries;


	int choice1 = 0;

	do {
		choice1 = get_selection();                        //This is just to get the selection
			if (choice1 == 1)
			{
				input_new_animal(entries);
			}
			else if (choice1 == 2)
			{
				input_new_donation(entries);
			}
			else if (choice1 == 3)
			{
				print_all(entries);
			}
			else if (choice1 == 4)
			{
				print_by_type(entries);
			}
			else if (choice1 == 5)
			{
				print_donations(entries);
			}
			else if (choice1 == 6)
			{
				save_animals(entries);
			}
			else if (choice1 == 7)
			{
				load_animals(entries);
			}
			else if (choice1 == 8)
			{
				save_donations(entries);
			}
			else if (choice1 == 9)
			{
				load_donations(entries);
			}
			else if (choice1 == 10)
			{
				delete_animal(entries);
			}
			else if (choice1 == 11)
			{
				delete_donor(entries);
			}

	} while (choice1 != 12);

	cout << endl << endl << endl;

	return 0;

}

void print_menu()  //*DONE**
{
	cout << endl << endl << endl << "Welcome to Gladys's Only-Kill Animal Shelter" << endl;
	cout << "Where we make your little accident disapear." << endl;
	cout << "What woukd you like to do today?" << endl;
	cout << "1.  Send your little one to the big farm in the sky." << endl;
	cout << "2.  Help fund our dream of keeping houses pet free." << endl;
	cout << "3.  Print all animals slated for the guilotines." << endl;
	cout << "4.  Print all by animal type?" << endl;
	cout << "5.  See how much our little non-for-profit organization is pulling in." << endl;
	cout << "6.  Save animals (Dont get excited.. Just into a file)." << endl;
	cout << "7.  Load animals." << endl;
	cout << "8.  Save donations." << endl;
	cout << "9.  Load donations." << endl;
	cout << "10. Delete an animal." << endl;
	cout << "11. Delete a donor" << endl;
	cout << "12. Leave in disgust." << endl << endl;
}
double get_selection() //**DONE**
{
	int choice;

	print_menu();
	do {
		cout << "Please select one. : ";
		cin >> choice;
	} while (choice > 0 && choice > 13);


	return choice;
}
void input_new_animal(vector<Entry*> &entries) //Maybe fix the gender select Its cumbersome.
{
    char animal1;
	bool gender1;
	string name1;
	string id1;
	size_t age1;
	string breed;
	char type;


	//resize_animal_arrays(animals, animal_count, animal_size);
	do {
		cout << endl << endl << "Please enter d/D for dog, c/C for cat, and b/B for bird. : ";
		cin >> animal1;
		type = animal1;
	} while (animal1 != 'd' && animal1 != 'D' && animal1 != 'c' && animal1 != 'C' && animal1 != 'b' && animal1 != 'B');

	//do {
			cout << "Is your pet 1)male or 0)female?";
			cin >> gender1;
	//} while (gender1 != 't' && gender1 != 'T' && gender1 != 'f' && gender1 != 'F');
	
	cout << "How old is your beast? : ";
	cin >> age1;

	cout << "What did your pets name use to be? : ";
	cin.ignore();
	getline(cin, name1);

	id1 = assign_id();


	if (animal1 == 'd' || animal1 == 'D')
	{
		cout << "What breed is your dog? : ";
		getline(cin, breed);
		Dog* d = new Dog(name1, age1, gender1, id1, type, breed);
		entries.push_back(d);
		entries.at(entries.size() - 1) -> type = false;
	}
	if (animal1 == 'c' || animal1 == 'C')
	{
		Cat* d = new Cat(name1, age1, gender1, id1, type);
		entries.push_back(d);
		entries.at(entries.size() - 1) -> type = false;
	}
	if (animal1 == 'b' || animal1 == 'B')
	{
		Bird* d = new Bird(name1, age1, gender1, id1, type);
		entries.push_back(d);
		entries.at(entries.size() - 1) -> type = false;
		
		//animals[animal_count] = d;
	}
	
	cout << "=================================" << endl;
	cout << "Your pets new name is " << id1 << "." << endl;  
	cout << "=================================" << endl;
	
}
string assign_id() //Need to make sure number is not used!!
{
	int id;
	string id1;
	int count;

	srand(time(NULL));
	
			id = rand()%1000000000;
			stringstream ss;
			ss << id;
			id1 = ss.str();
			count = 10 - id1.length();
			id1.insert(0, count, '0');

	return id1;
}
void input_new_donation(vector<Entry*> &entries)
{
	string sucker;
	string contribution;
	//int i = donor_count;

	cout << endl << endl << "You want to make a donation to us do you?" << endl;
	cout << "You know it's not tax deductable, right?" << endl;
	cout << "Ok, what's your name sucker? ";
	cin.ignore();
	getline(cin, sucker);

	cout << "What would you like to donate? ";
	getline(cin, contribution);

   	time_t rawtime;
	struct tm * timeinfo;
	char buffer[80];

	time (&rawtime);
	timeinfo = localtime(&rawtime);

	strftime(buffer,sizeof(buffer),"%m/%d/%Y  %H:%M",timeinfo);
	string date(buffer);

    
	Donation* d = new Donation(sucker, contribution, date);
	entries.push_back(d);
	entries.at(entries.size() - 1) -> type = true;

	cout << "Both I and your carpets at home thank you!" << endl;
	//++donor_count;
	
	//resize_donor_arrays(donations, donor_count, donor_size);

}
void print_all(vector<Entry*> &entries) //**DONE**
{
	int i = 0;

	cout << endl << endl << "                                      PETS" << endl;
	cout << "================================================================================" << endl;
	cout << "ID";
	cout << setfill(' ') << setw(15) << " ";
	cout << "Age";
	cout << setfill(' ') << setw(6) << " ";
	cout << "Animal Type";
	cout << setfill(' ') << setw(6) << " ";
	cout << "Gender";
	cout << setfill(' ') << setw(6) << " ";
	cout << "Name" << endl;
	cout << "================================================================================" << endl;

	do {
			if (entries.size() == 0 ){ break;}
			if (entries.at(i)-> type == false)
			{
				static_cast<Animal*>(entries.at(i))->print_info();
				//entries[i]->print_info();
				++i;
			}
			else
			{
				++i;
			}
	}while (i < entries.size());
	
}
void print_donations(vector<Entry*> &entries)  //**DONE**
{
	int i = 0;

	cout << endl << endl << "                                 DONATIONS" << endl;
	cout << "================================================================================" << endl;
	cout << "Donation               Donor                     Date                 " << endl;
	cout << "================================================================================" << endl;
	do {
		if (entries.size() == 0 ){ break;}
		if (entries.at(i)-> type == true)
			cout << left << setfill(' ') << setw(23);
			cout << static_cast<Donation*>(entries.at(i))->get_item();
			//cout << entries[i]->get_item();
			cout << left << setfill(' ') << setw(26);
			cout << static_cast<Donation*>(entries.at(i))->get_name();
			cout << static_cast<Donation*>(entries.at(i))->get_date();
			cout << endl;


			++i;
	} while (i != entries.size());

}
void print_by_type(vector<Entry*> &entries)  //**DONE**
{
	int type = 0;
	int i = 0; //god, why can i never get for loops to work!?

	do {
		cout << "What animal would you like to see?" << endl;
		cout << "1) Dog" << endl;
		cout << "2) Cat" << endl;
		cout << "3) Bird" << endl;
		cin >> type;
	} while (type < 1 || type > 3);


	if (entries.at(i)-> type == false)
	{
		if (type == 1)
		{
			cout << endl << endl << "                                      DOGS" << endl;
			cout << "================================================================================" << endl;
			cout << "ID";
			cout << setfill(' ') << setw(15) << " ";
			cout << "Age";
			cout << setfill(' ') << setw(6) << " ";
			cout << "Animal Type";
			cout << setfill(' ') << setw(6) << " ";
			cout << "Gender";
			cout << setfill(' ') << setw(6) << " ";
			cout << "Name"<< endl;
			cout << "================================================================================" << endl;
			do {	
				if (entries.size() == 0 ){ break;}		
				if (static_cast<Animal*>(entries.at(i))->get_type() == 'd' || static_cast<Animal*>(entries.at(i))->get_type() == 'D')
				{
					static_cast<Animal*>(entries.at(i))->print_info();

				}
				++i;
			} while (i != entries.size());
		}
		else if (type == 2)
		{
			cout << endl << endl << "                                      CATS" << endl;
			cout << "================================================================================" << endl;
			cout << "ID";
			cout << setfill(' ') << setw(15) << " ";
			cout << "Age";
			cout << setfill(' ') << setw(6) << " ";
			cout << "Animal Type";
			cout << setfill(' ') << setw(6) << " ";
			cout << "Gender";
			cout << setfill(' ') << setw(6) << " ";
			cout << "Name"<< endl;
			cout << "================================================================================" << endl;
			do {
				if (entries.size() == 0 ){ break;}
				if (static_cast<Animal*>(entries.at(i))->get_type()  == 'c' || static_cast<Animal*>(entries.at(i))->get_type()  == 'C')
				{
					static_cast<Animal*>(entries.at(i))->print_info();
				}
				++i;
			} while (i != entries.size());
		}
		else if (type == 3)
		{
			cout << endl << endl << "                                     BIRDS" << endl;
			cout << "================================================================================" << endl;
			cout << "ID";
			cout << setfill(' ') << setw(15) << " ";
			cout << "Age";
			cout << setfill(' ') << setw(6) << " ";
			cout << "Animal Type";
			cout << setfill(' ') << setw(6) << " ";
			cout << "Gender";
			cout << setfill(' ') << setw(6) << " ";
			cout << "Name"<< endl;
			cout << "================================================================================" << endl;
			do {
				if (entries.size() == 0 ){ break;}
				if (static_cast<Animal*>(entries.at(i))->get_type()  == 'b' || static_cast<Animal*>(entries.at(i))->get_type()  == 'B')
				{
					static_cast<Animal*>(entries.at(i))->print_info();
				}
				++i;
			} while (i != entries.size());
		}
	}
}
void load_animals(vector<Entry*> &entries) // **Need to resize**
{
	string text;
	//int i = animal_count;    //moves to next slot in array
 	string name1;
	size_t age1;
	bool gender1;
	string id1;
	char type1;
	string breed1;
	string dummy;

	//cout << animal_count << endl;
	cout << "What *.txt file would you like to load? ";
	cin >> text;
	text += ".txt";      //adds .txt to name selected
	cout << text << endl;
	ifstream infile;		//
	infile.open (text.c_str());      //opens file named previously

	if (infile.is_open())			//Verifying file exists
	{	
		cout << "File successfully loaded" << endl;  	 
		while (infile >> age1)
        {
			infile >> gender1 >> type1 >> id1;
			getline( infile, dummy );
			getline( infile, name1 );
			getline( infile, breed1 );
			
			if (type1 == 'd' || type1 == 'D')
			{
				Dog* d = new Dog(name1, age1, gender1, id1, type1, breed1);
				entries.push_back(d);
				entries.at(entries.size() - 1) -> type = false;
				//++animal_count;
			}
			if (type1 == 'c' || type1 == 'C')
			{
				Cat* c = new Cat(name1, age1, gender1, id1, type1);
				entries.push_back(c);
				entries.at(entries.size() - 1) -> type = false;;
				//++animal_count;
			}
			if (type1 == 'b' || type1 == 'B')
			{
				Bird* b = new Bird(name1, age1, gender1, id1, type1);
				entries.push_back(b);
				entries.at(entries.size() - 1) -> type = false;
				//++animal_count;
			}
		}
	}		
	else
	{
		cout << "Error opening file";
	}
//Closing file
infile.close();

}
void load_donations(vector<Entry*> &entries)
{
	string text;
	string donor;
	string donation;
	string date1;
	
	cout << "What *.txt file would you like to load? ";
	cin >> text;
	text += ".txt";
	cout << text << endl;
	ifstream infile;
	infile.open (text.c_str());

	if (infile.is_open())
	{
	  cout << "File successfully loaded";
	  	while (getline(infile, donor))
	  	{
			//getline(infile, donor);
			getline(infile, donation);
			getline(infile, date1);
			
			Donation* d = new Donation(donor, donation, date1);
			entries.push_back(d);
			entries.at(entries.size() - 1) -> type = true;
		}
	}
	else
	{
	  cout << "Error opening file";
	}

	infile.close();
	//--donor_count;
}
void save_animals(vector<Entry*> &entries) //**DONE**
{
	string text;
	int i = 0;
	char type1;



	cout << "What would you like to name your *.txt file as? ";
	cin >> text;
	text += ".txt";
	cout << text << endl;
	ofstream outfile;
	outfile.open (text.c_str());
	//Verifies file opens properly. Probably not needed.
	if (outfile.is_open())
	{
	  cout << "File successfully saved";
	}
	else
	{
		cout << "Error saving file";
	}
	do {
		if (entries.at(i)-> type == false)
		{
			if (static_cast<Animal*>(entries.at(i))->get_type() == 'd' || static_cast<Animal*>(entries.at(i))->get_type() == 'D')
			{
				
				
				outfile << static_cast<Animal*>(entries.at(i))->get_age() << endl;
				outfile << static_cast<Animal*>(entries.at(i))->get_gender() << endl;
				outfile << static_cast<Animal*>(entries.at(i))->get_type() << endl;
				outfile << static_cast<Animal*>(entries.at(i))->get_id() << endl;
				outfile << static_cast<Animal*>(entries.at(i))->get_name() << endl;
				outfile << static_cast<Dog*>(entries.at(i))->get_breed() << endl;
				// animals[i].get_breed() << '\n';
				++i;
			}
			else
			{
				outfile << static_cast<Animal*>(entries.at(i))->get_age() << endl;
				outfile << static_cast<Animal*>(entries.at(i))->get_gender() << endl;
				outfile << static_cast<Animal*>(entries.at(i))->get_type() << endl;
				outfile << static_cast<Animal*>(entries.at(i))->get_id() << endl;
				outfile << static_cast<Animal*>(entries.at(i))->get_name() << endl;
				outfile << "breed" << endl;
				++i;
			}
		}
		else
		{
			++i;
		}
	} while (i < entries.size());    
		outfile.close();
}

void save_donations(vector<Entry*> &entries)
{
	string text;
	int i = 0;
	
	cout << "What would you like to name your *.txt file as? ";
	cin >> text;
	text += ".txt";
	cout << text << endl;
	ofstream outfile;
	outfile.open (text.c_str());


	if (outfile.is_open())
	{
	  cout << "File successfully saved";
	}
	else
	{
	  cout << "Error saving file";
	}
	

	do {
		if (entries.at(i)-> type == true)
		{
			outfile << static_cast<Donation*>(entries.at(i))->get_name();
			outfile << '\n';
			outfile << static_cast<Donation*>(entries.at(i))->get_item();
			outfile << '\n';
			outfile << static_cast<Donation*>(entries.at(i))->get_date();
			outfile << '\n';
			i++;
		}
		else
		{
				i++;
		}
	} while (i < entries.size());

	outfile.close();
}
void delete_animal(vector<Entry*> &entries)
{
	int i = 0;
	string to_be_deleted;
	char choice;
	int stop;

	cout << "What animal do you want to delete? ";
	cin.ignore();
	getline(cin, to_be_deleted);
	
	do{
		if(i = entries.size())
		{
			cout << "Sorry, it appears the animal you are looking for does not exist." << endl;
			stop = 1;
		}
		else if (static_cast<Animal*>(entries.at(i))->get_name() != to_be_deleted)
		{
			++i;
		}
		else if (static_cast<Animal*>(entries.at(i))->get_name() == to_be_deleted)
		{
			cout << "Does your " << static_cast<Animal*>(entries.at(i))->get_name()  << " have an id # of " << static_cast<Animal*>(entries.at(i))->get_id()  << " ? Y/N :";
			cin >> choice;
			if (choice == 'y' || choice == 'Y')
			{
				//animals[i] = animals[animal_count]; 
				entries.erase(entries.begin()+i);
				cout << to_be_deleted << " has been deleted!" << endl;
				stop = 1;
			}
			else
			{
				++i;
			}
		}
		
	}while (stop != 1);
	
}
void delete_donor(vector<Entry*> &entries)
{
	int i = 0;
	string to_be_deleted;
	char choice;
	int stop;

	cout << "What donor do you want to delete? ";
	cin.ignore();
	getline(cin, to_be_deleted);
	
	do{
		if(i = entries.size())
		{
			cout << "Sorry, it appears the donor you are looking for does not exist." << endl;
			stop = 1;
		}
		else if (static_cast<Donation*>(entries.at(i))->get_name() != to_be_deleted)
		{
			++i;
		}
		else if (static_cast<Donation*>(entries.at(i))->get_name() == to_be_deleted)
		{
			cout << "Did " << static_cast<Donation*>(entries.at(i))->get_name() << " donate " << static_cast<Donation*>(entries.at(i))->get_item() << " ? Y/N :";
			cin >> choice;
			if (choice == 'y' || choice == 'Y')
			{
				entries.erase(entries.begin()+i);
				cout << to_be_deleted << " has been deleted!" << endl;
				stop = 1;
			}
			else
			{
				++i;
			}
		}
		
	}while (stop != 1);


}

