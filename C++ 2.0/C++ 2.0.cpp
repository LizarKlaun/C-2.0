#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>

using namespace std;


class User {
    string name;
    string surname;
    int age;
public:
    User() {
        name = "Boryslav";
        surname = "Yakibovich";
        age = 222;
    }

    User(string name, string surname, int age) {
        this->name = name;
        this->surname = surname;
        this->age = age;
    }

    void setName(string name) {
        this->name = name;
    }

    void setSurname(string surname) {
        this->surname = surname;
    }

    void setAge(int age) {
        this->age = age;
    }

    string getName() {
        return this->name;
    }

    string getSurname() {
        return this->surname;
    }

    int getAge() {
        return this->age;
    }

    void WriteUserToFile() {
        ofstream outFile("users.txt", ios::app); // ³������� ����� �� �����
        outFile << this->name << endl;
        outFile.close();

        ofstream outSecondFile("surname.txt", ios::app);
        outSecondFile << this->surname << endl;
        outSecondFile.close();

        ofstream outThirdFile("age.txt", ios::app);
        outThirdFile << this->age << endl;
        outThirdFile.close();
    }
};


class Group {
    User* user;
    int amountOfUsers;
public:
    Group() {
        ifstream inFile("users.txt");
        string line;
        int counter = 0;
        while (getline(inFile, line)) {
            counter++;
            cout << line << endl;
        }
        amountOfUsers = counter;
        user = new User[amountOfUsers];
    }

    void ReadAllUsersFromFile() {
        string* usersName = new string[amountOfUsers];
        string* usersSurname = new string[amountOfUsers];
        int* usersAge = new int[amountOfUsers];

        ifstream inFile("users.txt"); // ³������� ����� �� �������
        string line;
        int counter = 0;
        while (getline(inFile, line)) {
            usersName[counter] = line;
            counter++;
        }
        inFile.close();

        ifstream inSecondFile("surname.txt");
        counter = 0;
        while (getline(inSecondFile, line)) {
            usersSurname[counter] = line;
            counter++;
        }
        inSecondFile.close();

        counter = 0;
        ifstream inThirdFile("age.txt");
        while (getline(inThirdFile, line)) {
            usersAge[counter] = stoi(line); // stoi = string to int
            counter++;
        }
        inThirdFile.close();

        for (int i = 0; i < amountOfUsers; i++) {
            user[i].setName(usersName[i]);
            user[i].setSurname(usersSurname[i]);
            user[i].setAge(usersAge[i]);
        }

        delete[] usersName;
        usersName = nullptr;

        delete[] usersSurname;
        usersSurname = nullptr;

        delete[] usersAge;
        usersAge = nullptr;
    }

    void PrintAllUsers() {
        for (int i = 0; i < amountOfUsers; i++) {
            cout << "UserName: " << this->user[i].getName() << endl;
            cout << "Surname: " << this->user[i].getSurname() << endl;
            cout << "Age: " << this->user[i].getAge() << endl;
            cout << "-------------" << endl;
        }
    }
};

int main()
{
    User obj;
    obj.WriteUserToFile();

    Group group;
    group.ReadAllUsersFromFile();
    group.PrintAllUsers();
}