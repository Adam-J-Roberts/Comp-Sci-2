#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

void print_menu();
double get_selection();
void input_new_animal(char (&animal)[50], char (&gender)[50], int (&age)[50], string (&name)[50], int (&mark_of_the_beast)[50], int a);
void input_new_donation(string (&donor)[100], string (&donation)[100], int d);
void print_all(string name[], char animal[], int mark_of_the_beast[]);
void print_by_type(string name[], int age[], char animal[], int mark_of_the_beast[]);
void print_donations(string donor[], string donation[], int d);
int assign_id(int (&mark_of_the_beast)[50], int input);

int main()
{
	char animal[50];
	char gender[50];
	int age[50] = { 0 };
	string name[50];
	int mark_of_the_beast[50] = { 0 };
	string donor[100];
	string donation[100];

	int a = 0; // a is for animal in a for loop
	int d = 0; // d is for donor in a for loop
	int choice1 = 0;
				//   Prof used switch 
			//switch (user_selection)
				
				//case 1:
				//break;
				//case 2:
				//break;
				//case 3:
				//break;
				//case 4:
				//break;
				//case 5:
				//break;
				//case 6:
				//	cout << "c ya";
				//	return 0;
	do {
		choice1 = get_selection();
			if (choice1 == 1)
			{
				input_new_animal(animal, gender, age, name, mark_of_the_beast, a);
				++a;
			}
			else if (choice1 == 2)
			{
				input_new_donation(donor, donation, d);
				++d;
			}
			else if (choice1 == 3)
			{
				print_all(name, animal, mark_of_the_beast);
			}
			else if (choice1 == 4)
			{
				print_by_type(name, age, animal, mark_of_the_beast);
			}
			else if (choice1 == 5)
			{
				print_donations(donor, donation, d);
			}
	} while (choice1 != 6);

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
	cout << "6. Leave in disgust." << endl << endl;
}
double get_selection()
{
	int choice;

	print_menu();
	do {
		cout << "Please select one. : ";
		cin >> choice;
	} while (choice > 0 && choice > 7);


	return choice;
}
void input_new_animal(char (&animal)[50], char (&gender)[50], int (&age)[50], string (&name)[50], int (&mark_of_the_beast)[50], int a)
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

	id1 = assign_id(mark_of_the_beast, a);
	
	cout << endl << "=================================" << endl;
	cout << "Your pets new name is " << setfill('0') << setw(10) << id1 << "." << endl;
	cout << "=================================" << endl;

}
int assign_id(int (&mark_of_the_beast)[50], int index)
{

	int id=0;


	srand(time(NULL));

	do {
		id = rand()%1000000000;
		for (int k = 0; k < 50; k++) 
		{
			if (id == mark_of_the_beast[k]) 
			{
				id = 0;
				break;
			}
		}
	} while (id == 0);
	mark_of_the_beast[index] = id;

	return id;

}

void input_new_donation(string (&donor)[100], string (&donation)[100], int d)
{
	string sucker;
	string contribution;

	cout << endl << endl << "You want to make a donation to us do you?" << endl; 
	cout << "You know it's not tax deductable, right?" << endl;
	cout << "Ok, what's your name sucker? ";
	cin.ignore();
	getline(cin, sucker);

	donor[d] = sucker;

	cout << "What would you like to donate? ";
	getline(cin, contribution);
	
	donation[d] = contribution;

	cout << "Both I and your carpets at home thank you!" << endl;

}

void print_all(string name[], char animal[], int mark_of_the_beast[])
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
		cout << setfill('0') << setw(10) << mark_of_the_beast[i];
		cout << setfill(' ') << setw(12) << " ";
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
		cout <<name[i] << endl;
		++i;
	} while (mark_of_the_beast[i] != 0);

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

void print_by_type(string name[], int age[], char animal[], int mark_of_the_beast[])
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
				cout << setfill('0') << setw(10) << mark_of_the_beast[i];
				cout << "			" << age[i] << "			" << name[i] << endl;
				
			}
			++i;
		} while (i != 50);

		
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
				cout << setfill('0') << setw(10) << mark_of_the_beast[i];
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
				cout << setfill('0') << setw(10) << mark_of_the_beast[i];
				cout << "			" << age[i] << "			" << name[i] << endl;

			}
			++i;
		} while (i != 50);
	}
					
				//	} while (i < 51);
		
}





//donations showing '0'
//change donations to strngs and donors to ignore done
//submit by 11 at the latest dummy

// format for future use