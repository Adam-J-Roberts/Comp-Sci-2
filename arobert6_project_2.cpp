#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

void print_menu();
double get_selection();
void input_new_animal(char* &animal, char* &gender, int* &age, string* &name, int* &id_num, int (&animal_count), int (&animal_size));
void input_new_donation(string* &donor, string* &donation, int (&donor_count), int(&donor_size));
void print_all(string* &name, char* &animal, int* &id_num, int animal_count);
void print_by_type(string* &name, int* &age, char* &animal, int* &id_num, int animal_count);
void print_donations(string* &donor, string* &donation, int donor_count);
int assign_id(int* &id_num, int animal_count);
void save_animals(char* &animal, char* &gender, int* &age, string* &name, int* &id_num, int animal_count);
void load_animals(char* &animal, char* &gender, int* &age, string* &name, int* &id_num, int (&animal_count), int (&animal_size));
void save_donations(string* &donor, string* &donation, int donor_count);
void load_donations(string* &donor, string* &donation, int (&donor_count), int (&donor_size));
void resize_animal_arrays(int* &age, int* &id_num, string* &name, char* &animal, char* &gender, int (&animal_count), int (&animal_size));
void resize_donor_arrays(string* &donor, string* &donation, int (&donor_count), int (&donor_size));
void resize_int_array(int* &original, int (&size), int (&length));
void resize_char_array(char* &original, int (&size), int (&length));
void resize_string_array(string* &original, int (&size), int (&length));
void delete_donor(string* &donor, string* &donation, int (&donor_count), int (&donor_size));
void delete_animal(char* &animal, char* &gender, int* &age, string* &name, int* &id_num, int (&animal_count), int (&animal_size));
void copy_animal_array(char* &animal, char* &gender, int* &age, string* &name, int* &id_num, int (&animal_count), int (&animal_size));
void copy_donor_array(string* &donor, string* &donation, int (&donor_count), int (&donor_size));


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

	string* donor = new string[donor_size];
	string* donation = new string[donor_size];
	char* animal = new char[animal_size];
	char* gender = new char[animal_size];
	int* age = new int[animal_size];
	string* name = new string[animal_size];
	int* id_num = new int[animal_size];


	int choice1 = 0;

	do {
		choice1 = get_selection();                        //This is just to get the selection
			if (choice1 == 1)
			{
				input_new_animal(animal, gender, age, name, id_num, animal_count, animal_size);
				++animal_count;
			
			}
			else if (choice1 == 2)
			{
				input_new_donation(donor, donation, donor_count, donor_size);
			}
			else if (choice1 == 3)
			{
				print_all(name, animal, id_num, animal_count);
			}
			else if (choice1 == 4)
			{
				print_by_type(name, age, animal, id_num, animal_count);
			}
			else if (choice1 == 5)
			{
				print_donations(donor, donation, donor_count);
			}
			else if (choice1 == 6)
			{
				save_animals(animal, gender, age, name, id_num, animal_count);
			}
			else if (choice1 == 7)
			{
				load_animals(animal, gender, age, name, id_num, animal_count, animal_size);
			}
			else if (choice1 == 8)
			{
				save_donations(donor, donation, donor_count);
			}
			else if (choice1 == 9)
			{
				load_donations(donor, donation, donor_count, donor_size);
			}
			else if (choice1 == 10)
			{
				delete_animal(animal, gender, age, name, id_num, animal_count, animal_size);
			}
			else if (choice1 == 11)
			{
				delete_donor(donor, donation, donor_count, donor_size);
			}

	} while (choice1 != 12);

	cout << endl << endl << endl;

	return 0;

}

void print_menu()
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
double get_selection()
{
	int choice;

	print_menu();
	do {
		cout << "Please select one. : ";
		cin >> choice;
	} while (choice > 0 && choice > 13);


	return choice;
}
void input_new_animal(char* &animal, char* &gender, int* &age, string* &name, int* &id_num, int (&animal_count), int (&animal_size))
{
    char animal1;
	char gender1;
	string name1;
	int id1;
	int age1;



	resize_animal_arrays(age, id_num, name, animal, gender, animal_count, animal_size);
	do {
		cout << endl << endl << "Please enter d/D for dog, c/C for cat, and b/B for bird. : ";
		cin >> animal1;
	} while (animal1 != 'd' && animal1 != 'D' && animal1 != 'c' && animal1 != 'C' && animal1 != 'b' && animal1 != 'B');

	do {
			cout << "Is your pet a (m)ale or (f)emale? : ";
			cin >> gender1;
	} while (gender1 != 'm' && gender1 != 'M' && gender1 != 'f' && gender1 != 'F');

	animal[animal_count] = animal1;



	gender[animal_count] = gender1;

	cout << "How old is your beast? : ";
	cin >> age1;

	age[animal_count] = age1;

	cout << "What did your pets name use to be? : ";
	cin.ignore();
	getline(cin, name1);

	name[animal_count] = name1;

	id1 = assign_id(id_num, animal_count);

	cout << endl << "=================================" << endl;
	cout << "Your pets new name is " << setfill('0') << setw(10) << id1 << "." << endl;  //setfill and setw to make sure number is 10 digits
	cout << "=================================" << endl;

}
int assign_id(int* &id_num, int a)
{

	int id=0;


	srand(time(NULL));

	do {
		id = rand()%1000000000;
		for (int k = 0; k < a; k++)
		{
			if (id == id_num[k])
			{
				id = 0;
				break;
			}
		}
	} while (id == 0);
	id_num[a] = id;

	return id;

}
void input_new_donation(string* &donor, string* &donation, int(&donor_count), int(&donor_size))
{
	string sucker;
	string contribution;
	int i = donor_count;

	cout << endl << endl << "You want to make a donation to us do you?" << endl;
	cout << "You know it's not tax deductable, right?" << endl;
	cout << "Ok, what's your name sucker? ";
	cin.ignore();
	getline(cin, sucker);

	donor[donor_count] = sucker;

	cout << "What would you like to donate? ";
	getline(cin, contribution);

	donation[donor_count] = contribution;
	cout << "Both I and your carpets at home thank you!" << endl;
	++donor_count;
	resize_donor_arrays(donor, donation, donor_count, donor_size);

}
void print_all(string* &name, char* &animal, int* &id_num, int animal_count)
{

	int i = 0;

	cout << endl << endl << "                                      PETS" << endl;
	cout << "================================================================================" << endl;
	cout << "ID";
	cout << setfill(' ') << setw(20) << " ";
	cout << "Animal Type";
	cout << setfill(' ') << setw(20) << " ";
	cout << "Name" << endl;

	cout << "================================================================================" << endl;
	do {
		if (id_num[i] > 0)
		{
			cout << setfill('0') << setw(10) << id_num[i];
			cout << setfill(' ') << setw(12) << " ";
		}
		if (animal[i] == 'd' || animal[i] == 'D')
		{
			cout << "Dog";
			cout << setfill(' ') << setw(28) << " ";
		}
		else if (animal[i] == 'c' || animal[i] == 'C')
		{
			cout << "Cat";
			cout << setfill(' ') << setw(28) << " ";
		}
		else if (animal[i] == 'b' || animal[i] == 'B')
		{
			cout << "Bird";
			cout << setfill(' ') << setw(27) << " ";
		}
		cout << name[i] << endl;
		++i;
	} while (i < animal_count);

}
void print_donations(string* &donor, string* &donation, int donor_count)
{
	int i = 0;

	cout << endl << endl << "                                 DONATIONS" << endl;
	cout << "================================================================================" << endl;
	cout << "Donation                    Donor" << endl;
	cout << "================================================================================" << endl;
	do {
		//cout.width(28) << cout << left << donation[i]; //Use this for print all
		cout << left << setfill(' ') << setw(28);
		cout << donation[i];
		cout << donor[i] << endl;


		++i;
	} while (i < donor_count);

}
void print_by_type(string* &name, int* &age, char* &animal, int* &id_num, int animal_count)
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
		cout << "ID		  	        Age			Name " << endl;
		cout << "================================================================================" << endl;
		do {
			if (animal[i] == 'd' || animal[i] == 'D')
			{
				cout << setfill('0') << setw(10) << id_num[i];
				cout << "			" << age[i] << "			" << name[i] << endl;

			}
			++i;
		} while (i != animal_count);


		//for(int i = 0; animal[i] == 'd' && i != 51 || animal[i] == 'D' && i != 51; ++i)
		//{

		//}
	}
	else if (type == 2)
	{
		cout << endl << endl << "                                      CATS" << endl;
		cout << "================================================================================" << endl;
		cout << "ID		  	        Age			Name " << endl;
		cout << "================================================================================" << endl;
		do {
			if (animal[i] == 'c' || animal[i] == 'C')
			{
				cout << setfill('0') << setw(10) << id_num[i];
				cout << "			" << age[i] << "			" << name[i] << endl;

			}
			++i;
		} while (i != animal_count);
	}
	else if (type == 3)
	{
		cout << endl << endl << "                                      BIRDS" << endl;
		cout << "================================================================================" << endl;
		cout << "ID		  	        Age			Name " << endl;
		cout << "================================================================================" << endl;
		do {
			if (animal[i] == 'b' || animal[i] == 'B')
			{
				cout << setfill('0') << setw(10) << id_num[i];
				cout << "			" << age[i] << "			" << name[i] << endl;

			}
			++i;
		} while (i != animal_count);
	}

	//	} while (i < 51);

}
void load_animals(char* &animal, char* &gender, int* &age, string* &name, int* &id_num, int (&animal_count), int (&animal_size))
{
	string text;
	int i = animal_count;    //moves to next slot in array
	int firstInt;
    char firstChar;
    char secondChar;
    int secondInt;
    string theString;


	cout << "What *.txt file would you like to load? ";
	cin >> text;
	text += ".txt";      //adds .txt to name selected
	cout << text << endl;
	ifstream infile;		//
	infile.open (text.c_str());      //opens file named previously

	if (infile.is_open())			//Verifying file exists
	{
	  cout << "File successfully loaded" << endl;
	  //loads animals from file while there is something there, also loads first line.
	  
	 
	  while (infile >> id_num[animal_count])  			
	  {		
		  infile >> animal[animal_count] >> gender[animal_count] >> age[animal_count];
		  getline( infile, theString );          
		  getline( infile, name[animal_count] ); 

			  ++animal_count;			//adjusts animal count for new intakes.     
			  resize_animal_arrays(age, id_num, name, animal, gender, animal_count, animal_size);	  	  
	  }
  
	}
	else
	{
	  cout << "Error opening file";
	}
	
	//Closing file
	infile.close();  

}
void load_donations(string* &donor, string* &donation, int (&donor_count), int (&donor_size))
{
	string text;
	//int i = donor_count;    //moves to next slot in array
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
			getline(infile, donor[donor_count]);
			getline(infile, donation[donor_count]);
			++donor_count;
			resize_donor_arrays(donor, donation, donor_count, donor_size);
		}while (!infile.eof());
		//
	}
	else
	{
	  cout << "Error opening file";
	}

	infile.close();
	--donor_count;
}
void save_animals(char* &animal, char* &gender, int* &age, string* &name, int* &id_num, int animal_count)
{

	string text;
	int i = 0;

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
		if (id_num[i] > 0)
		{
			outfile << id_num[i] << '\n';
			outfile << animal[i] << '\n';
			outfile << gender[i] << '\n';
			outfile << age[i] << '\n';
			outfile << name[i] << '\n';
			++i;
		}
	} while (i < animal_count);    //Will need to change this to animal count for future projects

		outfile.close();
}
void save_donations(string* &donor, string* &donation, int donor_count)
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
		outfile << donor[i];
		outfile << '\n';
		outfile << donation[i];
		outfile << '\n';
		i++;
	} while (donor_count > i);

	outfile.close();
}
void resize_animal_arrays(int* &age, int* &id_num, string* &name, char* &animal, char* &gender, int (&animal_count), int (&animal_size))
{
	resize_int_array(age, animal_count, animal_size);
	resize_int_array(id_num, animal_count, animal_size);
	resize_string_array(name, animal_count, animal_size);
	resize_char_array(animal, animal_count, animal_size);
	resize_char_array(gender, animal_count, animal_size);
}
void resize_donor_arrays(string* &donor, string* &donation, int(&donor_count), int(&donor_size))
{
	resize_string_array(donor, donor_count, donor_size);
	resize_string_array(donation, donor_count, donor_size);
}
void resize_int_array(int* &original, int (&count), int (&size))
{
	if (size < (count + (count/2)) || size > count*2 || size > 4)
	{
		size = (count * 2);
		int i = 0;
		int* resized = new int[size];
		for (int i = 0; i < count; i++)
			resized[i] = original[i];
		delete[] original;
		original = resized;
	}


}
void resize_string_array(string* &original, int (&count), int (&size))
{
	if (size < (count + (count/2)) || size > count*2 || size > 4)
	{
		size = (count * 2);
		int i = 0;
		string* resized = new string[size];
		for (int i = 0; i < count; i++)
			resized[i] = original[i];
		delete[] original;
		original = resized;
	}
}
void resize_char_array(char* &original, int (&count), int (&size))
{
	if (size < (count + (count/2)) || size > count*2 || size > 4)
	{
		size = (count * 2);
		int i = 0;
		char* resized = new char[size];
		for (int i = 0; i < count; i++)
			resized[i] = original[i];
		delete[] original;
		original = resized;
	}
}
void delete_animal(char* &animal, char* &gender, int* &age, string* &name, int* &id_num, int (&animal_count), int (&animal_size))
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
		else if (name[i] != to_be_deleted)
		{
			++i;
		}
		else if (name[i] == to_be_deleted)
		{
			cout << "Does your " << name[i] << " have an id # of " << id_num[i] << " ? Y/N :";
			cin >> choice;
			if (choice == 'y' || choice == 'Y')
			{
				--animal_count;
				name[i] = name[animal_count];
				age[i] = age[animal_count];
				animal[i] = animal[animal_count];
				id_num[i] = id_num[animal_count];
				copy_animal_array(animal, gender, age, name, id_num, animal_count, animal_size);
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
void delete_donor(string* &donor, string* &donation, int (&donor_count), int (&donor_size))
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
		else if (donor[i] != to_be_deleted)
		{
			++i;
		}
		else if (donor[i] == to_be_deleted)
		{
			cout << "Did " << donor[i] << " donate " << donation[i] << " ? Y/N :";
			cin >> choice;
			if (choice == 'y' || choice == 'Y')
			{
				
				--donor_count;
				cout << donor_count << " " << i << endl;
				donor[i] = donor[donor_count];
				donation[i] = donation[donor_count];
				copy_donor_array(donor, donation, donor_count, donor_size);

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
void copy_animal_array(char* &animal, char* &gender, int* &age, string* &name, int* &id_num, int (&animal_count), int (&animal_size))
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
