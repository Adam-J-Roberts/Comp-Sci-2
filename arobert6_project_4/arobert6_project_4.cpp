#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>  
#include "Animal.h"
#include "Dog.h"
#include "Cat.h"
#include "Bird.h"
#include "Donation.h"
using namespace std;

void print_menu();
double get_selection();
void input_new_animal(Animal** &animals, int (&animal_count), int (&animal_size));
void input_new_donation(Donation** &donations, int(&donor_count), int(&donor_size));
void print_all(Animal** &animals, int (&animal_count), int (&animal_size));
void print_by_type(Animal** &animals, int (&animal_count), int (&animal_size));
void print_donations(Donation** &donations, int(&donor_count), int(&donor_size));
string assign_id(Animal** &animals, int animal_count);
void save_animals(Animal** &animals, int(&animal_count), int(&animal_size));
void load_animals(Animal** &animals, int(&animal_count), int(&animal_size));
void save_donations(Donation** &donations, int(&donor_count));
void load_donations(Donation** &donations, int(&donor_count), int(&donor_size));
void resize_animal_arrays(Animal** &original, int count, int (&size));
void resize_donor_arrays(Donation** &original, int count, int (&size));
void delete_donor(Donation** &donations, int(&donor_count), int(&donor_size));
void delete_animal(Animal** &animals, int (&animal_count), int (&animal_size));
//void copy_animal_array(char* &animal, char* &gender, int* &age, string* &name, int* &id_num, int (&animal_count), int (&animal_size));
//void copy_donor_array(string* &donor, string* &donation, int (&donor_count), int (&donor_size));


int main()
{
	// char animal[a];
	// char gender[a];
	// int age[a] = { 0 };
	//string name[a];
	//int id_num[a] = { 0 };
	int animal_count = 0; // a is for animal count
	int donor_count = 0; // d is for donor count
	int animal_size = 5;
	int donor_size = 5;

	Animal** animals = new Animal*[animal_size];
	Donation** donations = new Donation*[donor_size];
	/*string* donor = new string[donor_size];
	string* donation = new string[donor_size];
	char* animal = new char[animal_size];
	char* gender = new char[animal_size];
	int* age = new int[animal_size];
	string* name = new string[animal_size];
	int* id_num = new int[animal_size];*/


	int choice1 = 0;

	do {
		choice1 = get_selection();                        //This is just to get the selection
			if (choice1 == 1)
			{
				input_new_animal(animals, animal_count, animal_size);
				++animal_count;
			
			}
			else if (choice1 == 2)
			{
				input_new_donation(donations, donor_count, donor_size);
			}
			else if (choice1 == 3)
			{
				print_all(animals, animal_count, animal_size);
			}
			else if (choice1 == 4)
			{
				print_by_type(animals, animal_count, animal_size);
			}
			else if (choice1 == 5)
			{
				print_donations(donations, donor_count, donor_size);
			}
			else if (choice1 == 6)
			{
				save_animals(animals, animal_count, animal_size);
			}
			else if (choice1 == 7)
			{
				load_animals(animals, animal_count, animal_size);
			}
			else if (choice1 == 8)
			{
				save_donations(donations, donor_count);
			}
			else if (choice1 == 9)
			{
				load_donations(donations, donor_count, donor_size);
			}
			else if (choice1 == 10)
			{
				delete_animal(animals, animal_count, animal_size);
			}
			else if (choice1 == 11)
			{
				delete_donor(donations, donor_count, donor_size);
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
void input_new_animal(Animal** &animals, int (&animal_count), int (&animal_size)) //Maybe fix the gender select Its cumbersome.
{
    char animal1;
	bool gender1;
	string name1;
	string id1;
	size_t age1;
	string breed;
	char type;


	resize_animal_arrays(animals, animal_count, animal_size);
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

	id1 = assign_id(animals, animal_count);


	if (animal1 == 'd' || animal1 == 'D')
	{
		cout << "What breed is your dog? : ";
		getline(cin, breed);
		Dog* d = new Dog(name1, age1, gender1, id1, type, breed);
		animals[animal_count] = d;
	}
	if (animal1 == 'c' || animal1 == 'C')
	{
		Cat* d = new Cat(name1, age1, gender1, id1, type);
		animals[animal_count] = d;
	}
	if (animal1 == 'b' || animal1 == 'B')
	{
		Bird* d = new Bird(name1, age1, gender1, id1, type);
		animals[animal_count] = d;
	}
	
	cout << "=================================" << endl;
	cout << "Your pets new name is " << id1 << "." << endl;  
	cout << "=================================" << endl;
	
}
string assign_id(Animal** &animals, int animal_count) //Need to make sure number is not used!!
{
	int id;
	string id1;
	int count;

	srand(time(NULL));
	
		do {
			id = rand()%1000000000;
			stringstream ss;
			ss << id;
			id1 = ss.str();
			count = 10 - id1.length();
			id1.insert(0, count, '0');
			for (int i = 0; i < animal_count; i++)
			{
				if (id1 == animals[i]->get_id())
				{
					id1 = "0";
					break;
				}
			}
		}while (id1 == "0");

	return id1;
}
void input_new_donation(Donation** &donations, int(&donor_count), int(&donor_size))  //**Resize array
{
	string sucker;
	string contribution;
	int i = donor_count;

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
	donations[donor_count] = d;

	cout << "Both I and your carpets at home thank you!" << endl;
	++donor_count;
	
	resize_donor_arrays(donations, donor_count, donor_size);

}
void print_all(Animal** &animals, int(&animal_count), int(&animal_size)) //**DONE**
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

	if (animal_count > 0)
	{
		do {
			animals[i]->print_info();
			++i;
		} while (i < animal_count);
	}
}
void print_donations(Donation** &donations, int(&donor_count), int(&donor_size))  //**DONE**
{
	int i = 0;

	cout << endl << endl << "                                 DONATIONS" << endl;
	cout << "================================================================================" << endl;
	cout << "Donation               Donor                     Date                 " << endl;
	cout << "================================================================================" << endl;
	do {

		cout << left << setfill(' ') << setw(23);
		cout << donations[i]->get_item();
		cout << left << setfill(' ') << setw(26);
		cout << donations[i]->get_name();
		cout << donations[i]->get_date();
		cout << endl;


		++i;
	} while (i < donor_count);

}
void print_by_type(Animal** &animals, int (&animal_count), int (&animal_size))  //**DONE**
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
			if (animals[i]->get_type() == 'd' || animals[i]->get_type() == 'D')
			{
				animals[i]->print_info();

			}
			++i;
		} while (i != animal_count);
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
			if (animals[i]->get_type() == 'c' || animals[i]->get_type() == 'C')
			{
				animals[i]->print_info();
			}
			++i;
		} while (i != animal_count);
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
			if (animals[i]->get_type() == 'b' || animals[i]->get_type() == 'B')
			{
				animals[i]->print_info();
			}
			++i;
		} while (i != animal_count);
	}

}

void load_animals(Animal** &animals, int(&animal_count), int(&animal_size)) // **Need to resize**
{
	string text;
	int i = animal_count;    //moves to next slot in array
 	string name1;
	size_t age1;
	bool gender1;
	string id1;
	char type1;
	string breed1;
	string dummy;

	cout << animal_count << endl;
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
				animals[animal_count] = d;
				++animal_count;
			}
			if (type1 == 'c' || type1 == 'C')
			{
				Cat* c = new Cat(name1, age1, gender1, id1, type1);
				animals[animal_count] = c;
				++animal_count;
			}
			if (type1 == 'b' || type1 == 'B')
			{
				Bird* b = new Bird(name1, age1, gender1, id1, type1);
				animals[animal_count] = b;
				++animal_count;
			}
			resize_animal_arrays(animals, animal_count, animal_size);
		}
	}		
	else
	{
		cout << "Error opening file";
	}

//Closing file
infile.close();

}
void load_donations(Donation** &donations, int(&donor_count), int(&donor_size))
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
	  	do{
			getline(infile, donor);
			getline(infile, donation);
			getline(infile, date1);
			
			Donation* d = new Donation(donor, donation, date1);
			donations[donor_count] = d;
			
			++donor_count;
			resize_donor_arrays(donations, donor_count, donor_size);
		}while (!infile.eof());
	}
	else
	{
	  cout << "Error opening file";
	}

	infile.close();
	--donor_count;
}
void save_animals(Animal** &animals, int(&animal_count), int(&animal_size)) //**DONE**
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
		
		if (animals[i]->get_type() == 'd' || animals[i]->get_type() == 'D')
		{
			
			
			outfile << animals[i]->get_age() << endl;
			outfile << animals[i]->get_gender() << endl;
			outfile << animals[i]->get_type() << endl;
			outfile << animals[i]->get_id() << endl;
			outfile << animals[i]->get_name() << endl;
			outfile << static_cast<Dog*>(animals[i])->get_breed() << endl;
			// animals[i].get_breed() << '\n';
			++i;
		}
		else
		{
			outfile << animals[i]->get_age() << endl;
			outfile << animals[i]->get_gender() << endl;
			outfile << animals[i]->get_type() << endl;
			outfile << animals[i]->get_id() << endl;
			outfile << animals[i]->get_name() << endl;
			outfile << "breed" << endl;
			++i;
		}
	} while (i < animal_count);    //Will need to change this to animal count for future projects
		outfile.close();
}

void save_donations(Donation** &donations, int(&donor_count))
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
		outfile << donations[i]->get_name();
		outfile << '\n';
		outfile << donations[i]->get_item();
		outfile << '\n';
		outfile << donations[i]->get_date();
		outfile << '\n';
		i++;
	} while (donor_count > i);

	outfile.close();
}

void resize_animal_arrays(Animal** &original, int count, int (&size))
{
	if (size < (count + (count/2)) || size > count*2 || size > 4)
	{
		size = (count * 2);
		int i = 0;
		Animal** resized = new Animal*[size];
		for (int i = 0; i < count; i++)
			resized[i] = original[i];
		delete[] original;
		original = resized;
	}
}

void resize_donor_arrays(Donation** &original, int count, int (&size))
{
	if (size < (count + (count/2)) || size > count*2 || size > 4)
	{
		size = (count * 2);
		int i = 0;
		Donation** resized = new Donation*[size];
		for (int i = 0; i < count; i++)
			resized[i] = original[i];
		delete[] original;
		original = resized;
	}
}
void delete_animal(Animal** &animals, int (&animal_count), int (&animal_size))
{
	int i = 0;
	string to_be_deleted;
	char choice;
	int stop;

	cout << "What animal do you want to delete? ";
	cin.ignore();
	getline(cin, to_be_deleted);
	
	do{
		if(i > animal_count)
		{
			cout << "Sorry, it appears the animal you are looking for does not exist." << endl;
			stop = 1;
		}
		else if (animals[i]->get_name() != to_be_deleted)
		{
			++i;
		}
		else if (animals[i]->get_name() == to_be_deleted)
		{
			cout << "Does your " << animals[i]->get_name()  << " have an id # of " << animals[i]->get_id()  << " ? Y/N :";
			cin >> choice;
			if (choice == 'y' || choice == 'Y')
			{
				--animal_count;
				animals[i] = animals[animal_count]; 

				//copy_animal_array(animal, gender, age, name, id_num, animal_count, animal_size);
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
void delete_donor(Donation** &donations, int(&donor_count), int(&donor_size))
{
	int i = 0;
	string to_be_deleted;
	char choice;
	int stop;

	cout << "What donor do you want to delete? ";
	cin.ignore();
	getline(cin, to_be_deleted);
	
	do{
		if(i > donor_count)
		{
			cout << "Sorry, it appears the donor you are looking for does not exist." << endl;
			stop = 1;
		}
		else if (donations[i]->get_name() != to_be_deleted)
		{
			++i;
		}
		else if (donations[i]->get_name() == to_be_deleted)
		{
			cout << "Did " << donations[i]->get_name() << " donate " << donations[i]->get_item() << " ? Y/N :";
			cin >> choice;
			if (choice == 'y' || choice == 'Y')
			{
				
				--donor_count;
				donations[i] = donations[donor_count];
				resize_donor_arrays(donations, donor_count, donor_size);
				//copy_donor_array(donor, donation, donor_count, donor_size);

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
/*void copy_animal_array(char* &animal, char* &gender, int* &age, string* &name, int* &id_num, int (&animal_count), int (&animal_size))
{
	char* temp_animal = new char[animal_count];
	char* temp_gender = new char[animal_count];
	int* temp_age = new int[animal_count];
	string* temp_name = new string[animal_count];
	int* temp_id = new int[animal_count];


	int i = 0;
	
	do {
		temp_animal[i] = animal[i];
		temp_gender[i] = gender[i];
		temp_age[i] = age[i];
		temp_name[i] = name[i];
		temp_id[i] = id_num[i];
		++i;
	} while (i != animal_count);
	
	delete[] animal;
	animal = temp_animal;
	temp_animal = NULL;
	
	delete[] gender;
	gender = temp_gender;
	temp_gender = NULL;

	delete[] age;
	age = temp_age;
	temp_age = NULL;

	delete[] name;
	name = temp_name;
	temp_name = NULL;

	delete[] id_num;
	id_num = temp_id;
	temp_id = NULL;
}
void copy_donor_array(string* &donor, string* &donation, int (&donor_count), int (&donor_size))
{
	string* temp_donor = new string[donor_count];
	string* temp_donation = new string[donor_count];



	int i = 0;
	
	do {
		temp_donation[i] = donation[i];
		temp_donor[i] = donor[i];
		++i;
	} while (i != donor_count);
	
	delete[] donor;
	donor = temp_donor;
	temp_donor = NULL;
	
	delete[] donation;
	donation = temp_donation;
	temp_donation = NULL;
}
*/
