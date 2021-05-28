#include <iostream>
#include <cstdlib>	
#include <ctime>	
#include <iomanip>
#include <fstream>  
#include <string>
using namespace std;

//Function prototypes
void print_menu();
double get_selection();
void input_new_animal(char animal[], char gender[], int age[], string name[], int id_num[], int a);
void input_new_donation(string donor[], string donation[], int d);
void print_all(string name[], char animal[], int id_num[]);
void print_by_type(string name[], int age[], char animal[], int id_num[]);
void print_donations(string donor[], string donation[], int d);
int assign_id(int id_num[], int input);
void save_animals(char animal[], char gender[], int age[], string name[], int id_num[]);
void load_animals(char animal[], char gender[], int age[], string name[], int id_num[], int (&a));
void save_donations(string donor[], string donation[], int d);
void load_donations(string donor[], string donation[], int (&d));


int main()
{
	char animal[50]; 
	char gender[50];
	int age[50] = { 0 };
	string name[50];
	int id_num[50] = { 0 };
	string donor[100];
	string donation[100];



	int a = 0; // a is for animal counts
	int d = 0; // d is for donor counts
	int choice1 = 0;

	do {
		choice1 = get_selection();                        //This is just to get the selection
			if (choice1 == 1)
			{
				input_new_animal(animal, gender, age, name, id_num, a);
				++a;
			}
			else if (choice1 == 2)
			{
				input_new_donation(donor, donation, d);
				++d;
			}
			else if (choice1 == 3)
			{
				print_all(name, animal, id_num);
			}
			else if (choice1 == 4)
			{
				print_by_type(name, age, animal, id_num);
			}
			else if (choice1 == 5)
			{
				print_donations(donor, donation, d);
			}
			else if (choice1 == 6)
			{
				save_animals(animal, gender, age, name, id_num);
				cout << "All animals have been saved-ish." << endl;
			}
			else if (choice1 == 7)
			{
				load_animals(animal, gender, age, name, id_num, a);
			}
			else if (choice1 == 8)
			{
				save_donations(donor, donation, d);
			}
			else if (choice1 == 9)
			{
				load_donations(donor, donation, d);
			}

	} while (choice1 != 10);

	cout << endl << endl << endl;

	return 0;

}

void print_menu()
{
	cout << endl << endl << endl << "Welcome to Gladys's Only-Kill Animal Shelter" << endl;
	cout << "Where we make your little accident disapear." << endl;
	cout << "What woukd you like to do today?" << endl;
	cout << "1. Send your little one to the big farm in the sky." << endl;
	cout << "2. Help fund our dream of keeping houses pet free." << endl;
	cout << "3. Print all animals slated for the guilotines." << endl;
	cout << "4. Print all by animal type?" << endl;
	cout << "5. See how much our little non-for-profit organization is pulling in." << endl;
	cout << "6. Save animals (Dont get excited.. Just into a file)." << endl;
	cout << "7. Load animals." << endl;
	cout << "8. Save donations." << endl;
	cout << "9. Load donations." << endl;
	cout << "10. Leave in disgust." << endl << endl;
}
double get_selection()
{
	int choice;

	print_menu();
	do {
		cout << "Please select one. : ";
		cin >> choice;
	} while (choice > 0 && choice > 11);   //verify selection is one of the options


	return choice;
}
void input_new_animal(char animal[], char gender[], int age[], string name[], int id_num[50], int a)
{
	char animal1;
	char gender1;
	string name1;
	int id1;
	int age1;
	int j;

	do {
		cout << endl << endl << "Please enter d/D for dog, c/C for cat, and b/B for bird. : ";
		cin >> animal1;
	} while (animal1 != 'd' && animal1 != 'D' && animal1 != 'c' && animal1 != 'C' && animal1 != 'b' && animal1 != 'B');

	do {
			cout << "Is your pet a (m)ale or (f)emale? : ";
			cin >> gender1;
	} while (gender1 != 'm' && gender1 != 'M' && gender1 != 'f' && gender1 != 'F');

	animal[a] = animal1;



	gender[a] = gender1;

	cout << "How old is your beast? : ";
	cin >> age1;

	age[a] = age1;

	cout << "What did your pets name use to be? : ";
	cin.ignore();
	getline(cin, name1);

	name[a] = name1;

	id1 = assign_id(id_num, a);

	cout << endl << "=================================" << endl;
	cout << "Your pets new name is " << setfill('0') << setw(10) << id1 << "." << endl;  //setfill and setw to make sure number is 10 digits
	cout << "=================================" << endl;

}
int assign_id(int id_num[], int index)
{

	int id=0;


	srand(time(NULL));   //sets random numbers to base off time

	do {cout << "All animals have been saved-ish." << endl;
		id = rand()%1000000000;      // makes sure random bumber is with-in range
		for (int k = 0; k < 50; k++)         //50 because that is current size of array
		{
			if (id == id_num[k])             //makes sure id is not already in use
			{
				id = 0;
				break;
			}
		}
	} while (id == 0);				
	id_num[index] = id;

	return id;

}
void input_new_donation(string donor[], string donation[], int d)
{
	string sucker;
	string contribution;

	cout << endl << endl << "You want to make a donation to us do you?" << endl;
	cout << "You know it's not tax deductable, right?" << endl;
	cout << "Ok, what's your name sucker? ";
	cin.ignore();              //clears buffer
	getline(cin, sucker);		//getline incase name is more than on cluster

	donor[d] = sucker;

	cout << "What would you like to donate? ";
	getline(cin, contribution);

	donation[d] = contribution;

	cout << "Both I and your carpets at home thank you!" << endl;

}
void print_all(string name[], char animal[], int id_num[])
{

	int i = 0;

	cout << endl << endl << "                                      PETS" << endl;
	cout << "================================================================================" << endl;
	cout << "ID";
	cout << setfill(' ') << setw(20) << " ";     //THis whole bit is just to make things line up and look nice.
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
	} while (id_num[i] > 0);

}
void print_donations(string donor[], string donation[], int d)
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
	} while (i < (d + 1));

}
void print_by_type(string name[], int age[], char animal[], int id_num[])
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
		} while (i != 50);
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
		} while (i != 50);
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
		} while (i != 50);
	}

}
void load_animals(char animal[], char gender[], int age[], string name[], int id_num[], int (&a))
{
	string text;
	int i = a;    //moves to next slot in array
	int firstInt;
    char firstChar;
    char secondChar;
    int secondInt;
    string theString;
    int dummy;

	cout << "What *.txt file would you like to load? ";
	cin >> text;
	text += ".txt";      //adds .txt to name selected
	cout << text << endl;
	ifstream infile;		//
	infile.open (text.c_str());      //opens file named previously

	if (infile.is_open())			//Verifying file exists
	{
	  cout << "File successfully loaded";
	  //loads animals from file while there is something there, also loads first line.
	  while (infile >> firstInt)  			
	  {		
		  infile >> firstChar >> secondChar >> secondInt;
		  getline( infile, theString );          
		  getline( infile, theString ); 
		  
		  cout << firstChar << " " << secondChar << " " << firstInt
				<< " " << secondInt << " " << theString  << "\n";
			  
			  id_num[i] = firstInt; 
			  animal[i] = firstChar;
			  gender[i] = secondChar;
			  name[i] = theString;
			  age[i] = secondInt;
			  ++i;
	  }
  
	}
	else
	{
	  cout << "Error opening file";
	}
	a = --i;     //adjusts animal count for new intakes.
	//Closing file
	infile.close();  
}
void load_donations(string donor[], string donation[], int (&d))
{
	string text;
	int i = d;    //moves to next slot in array
	
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
			getline(infile, donor[i]);
			getline(infile, donation[i]);
			i++;
	
		}while (!infile.eof());
	d = --i;
	}
	else
	{
	  cout << "Error opening file";
	}

	infile.close();
}
void save_animals(char animal[], char gender[], int age[], string name[], int id_num[])
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
	} while (id_num[i] > 0);    //Will need to change this to animal count for future projects

		outfile.close();


}
void save_donations(string donor[], string donation[], int d)
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
	} while (d > i);

	outfile.close();
}
