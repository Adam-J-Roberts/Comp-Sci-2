#include <iostream>
#include <cstdlib>

using namespace std;

class cat
{
	//Keep your hands off my privates!
    private:			
	string name;
    size_t age;
    bool gender;
    string id;

	//My functions that will change my class objects
    public:		
	cat(){}
	cat(string name)
	{
		this->name = name;
	}
    string get_name()
    {
        return name;
    }
    size_t get_age()
    {
        return age;
    }
    bool get_gender()
    {
        return gender;
    }
    string get_id()
    {
        return id;
    }
    void set_name(string name)
    {
		this->name = name;
    }
    void set_age(size_t age)
    {
		this->age = age;
    }
    void set_gender(bool gender)
    {
		this->gender = gender;
    }
    void set_id(string id)
    {
		this->id = id;
    }
};

class dog
{
	//Insert privates joke here. Still just my strings 
	//I don't want changed accidentally.
    private:
        string name;
        size_t age;
        string breed;
        bool gender;
        string id;
	//Member functions
    public:
	dog(){}
	dog(string id)
	{
		this->id = id;
	}
    string get_name()
    {
        return name;
    }
    size_t get_age()
    {
        return age;
    }
    string get_breed()
    {
        return breed;
    }
    bool get_gender()
    {
        return gender;
    }
    string get_id()
    {
        return id;
    }
    void set_name(string name)
    {
		this->name = name;
    }
    void set_age(size_t age)
	{
		this->age = age;
    }
    void set_breed(string breed)
    {
		this->breed = breed;
    }
    void set_gender(bool gender)
    {
		this->gender = gender;
    }
    void set_id(string id)
    {
		this->id = id;
    }
};

class bird
{
    private:
        string name;
        size_t age;
        bool gender;
        string id;

    public:
	bird(){}
	bird(string id)
	{
		this->id = id;
	}
	bird(string name, size_t age, string id)
	{
		this->name = name;
		this->age = age;
		this->id = id;

	}
    string get_name()
    {
        return name;
    }
    size_t get_age()
    {
        return age;
    }
    bool get_gender()
    {
        return gender;
    }
    string get_id()
    {
        return id;
    }
    void set_name(string name)
    {
		this->name = name;
    }
	void set_age(size_t age)
	{
		this->age = age;
	}
    void set_gender(bool gender)
    {
		this->gender = gender;
    }
    void set_id(string id)
    {
		this->id = id;
    }
};

class donation
{
    private:
    string donor_name;
    string item;
    string data;

    public:
	donation(){}
    // Member Functions()
    string get_donor_name()
    {
       return donor_name;
    }
    string get_item()
    {
        return item;
    }   
    string get_data()
    {
        return data;
    }
    void set_donor_name(string donor_name)
    {
        this->donor_name = donor_name;
    }
    void set_item(string item)
    {
        this->item = item;
    }
	void set_data(string data)
	{
		this->data = data;
	}
};

int main()
{
	int choice;
	dog * dog_array = new dog[10];						//create dynamic array of Dog
	cat * cat_array = new cat[10];						//Same for cats	
	bird * bird_array = new bird[10];					//Turtles all the way down
	donation * donation_array = new donation[10];		//I still hate commenting
	
	//Everything in here is just me testing the classes...  To lazy to set up functions for something I'll never see agian
	cout << "What would you like to test?" << endl
		<< "1)dog" << endl
		<< "2)cat" << endl
		<< "3)bird" << endl
		<< "4)donations?" << endl
		<< "5) Nothings, let me out" << endl;
	cin >> choice;
	
	
	//set info

		if (choice == 1)
		{
			for (size_t i = 0; i < 10; i++)
			{
				dog_array[i].set_name("Rex");
				dog_array[i].set_age(i);
				dog_array[i].set_breed("CatDog");
				dog_array[i].set_gender(true);
				dog_array[i].set_id("0123456789");
			}
			for (size_t i = 0; i < 10; i++)
			{
				cout << dog_array[i].get_name() << " "
					<< dog_array[i].get_age() << " "
					<< dog_array[i].get_breed() << " "
					<< dog_array[i].get_gender() << " "
					<< dog_array[i].get_id() << endl;
			}
		}
		if (choice == 2)
		{
			for (size_t i = 0; i < 10; i++)
			{
				cat_array[i].set_name("Rex");
				cat_array[i].set_age(i);
				cat_array[i].set_gender(true);
				cat_array[i].set_id("0123456789");
			}
			for (size_t i = 0; i < 10; i++)
			{
				cout << cat_array[i].get_name() << " "
					<< cat_array[i].get_age() << " "
					<< cat_array[i].get_gender() << " "
					<< cat_array[i].get_id() << endl;
			}

		}
		if (choice == 3)
		{
			for (size_t i = 0; i < 10; i++)
			{
				bird_array[i].set_name("Rex");
				bird_array[i].set_age(i);
				bird_array[i].set_gender(true);
				bird_array[i].set_id("0123456789");
			}
			//print info
			for (size_t i = 0; i < 10; i++)
			{
				cout << bird_array[i].get_name() << " "
					<< bird_array[i].get_age() << " "
					<< bird_array[i].get_gender() << " "
					<< bird_array[i].get_id() << endl;
			}
		}
		if (choice == 4)
		{
			for (size_t i = 0; i < 10; i++)
			{
				donation_array[i].set_donor_name("Roxy");
				donation_array[i].set_item("food");
				donation_array[i].set_data("wtf is this");
			}
			for (size_t i = 0; i < 10; i++)
			{
				cout << donation_array[i].get_donor_name() << " "
					<< donation_array[i].get_item() << " "
					<< donation_array[i].get_data() << " ";
			}
		}
		if (choice = 5);
		{
			return 0;
		}
	
	return 0;
}