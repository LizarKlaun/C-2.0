#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class User {
	string name;
	int age;
public:
	User() {
		name = "Boryslav";
		age = 222;
	}
	User(string name, int age) {
		this->name = name;
		this->age = age;
	}
	void WriteUserToFile() {
		ofstream outFile("text.txt", ios::app);
		outFile << "Username: " << this->name << " - Age: " << this->age << endl;
		outFile.close();
	}
	void ReadAllUsersToFile() {
		ifstream inFile("text.txt");
		string line;
		while (getline(inFile, line)) {
			cout << line << endl;
		}
		inFile.close();
	}
};

class Group {
	int amountOfUser;
	User* arrayOfUsers;
public:
	Group() {
		amountOfUser = 3;
		arrayOfUsers = new User[amountOfUser];
	}

	void ReadAllUsersToFile() {
		ifstream inFile("text.txt");
		string line;
		while (getline(inFile, line)) {
			cout << line << endl;
		}
		inFile.close();
	}
};

int main()
{
	User obj;
	obj.WriteUserToFile();
	obj.ReadAllUsersToFile();

}