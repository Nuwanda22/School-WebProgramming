#include <iostream>
#include <string>

using namespace std;

class Person
{
	char *name;
	int age;

public:
	Person(int age, char *name)
	{
		Person::name = new char[strlen(name)];
		strcpy(Person::name, name);

		Person::age = age;
	}
	void wakeUp() 
	{
		cout << "I'm Wake up!" << endl;
	}
	void printInfo()
	{
		cout << "His name is " << name << endl;
		cout << "His age is " << age << endl;
	}
};

char *toCharPointer(string a)
{
	char *temp = new char[a.size() + 1];
	strcpy(temp, a.c_str());

	return temp;
}

int main(int argc, char *argv[])
{
	int sum = 0;
	
	for (int i = 1; i < argc; i++) {
		sum += atoi(argv[i]);
	}

	std::cout << sum << std::endl;

	string s = string("Àü¼º¿ì");
	char *str = toCharPointer(s);

	Person a = Person(18, str); 
	a.printInfo();

	/*Person *b = new Person(18, str);
	b->printInfo();*/

	return 0;
}