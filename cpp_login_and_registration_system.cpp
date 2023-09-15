#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <direct.h>
using namespace std;

namespace fs = std::filesystem;

fs::path dir = fs::current_path();

string path = dir.string() + "\\data\\";

void registration();

void login();

void forgotPASS();

int main()
{
	if (!fs::exists(dir /= "data"))
	{
		_mkdir("data");
	}
	int choice{};
	cout << "Welcome to log in page !!" << endl;
	cout << "\nPress 1 to register a new account.\nPress 2 to log in.\nPress 3 if forget your password.\nPress 4 to exit." << endl << "Enter choice : "; cin >> choice;

	cout << endl;

	switch (choice)
	{
	case 1:
		registration();
		break;
	case 2:
		login();
		break;
	case 3:
		forgotPASS();
		break;
	case 4:
		cout << "Thanks for visiting our page !!" << endl;
		break;
	default:
		system("cls");
		cout << "Please enter a valid choice." << endl << endl;
		main();
		break;
	}

	return 0;

}


void registration() {

	string username, password, un, pw;

	cout << "Enter your USERNAME : "; cin >> username;
	cout << "Enter your PASSWORD : "; cin >> password;

	ifstream database1;
	database1.open(path + username + ".txt");

	if (database1)
	{
		system("cls");
		cout << "The username has been taken. Try again." << endl << endl;
		database1.close();
	}
	else
	{


		ofstream database;
		database.open(path + username + ".txt");
		database << username << endl << password;
		database.close();

		system("cls");

		cout << "Succesfully registered." << endl << endl;


	}

	main();


}

void login()
{
	string username, password, un, pw;

	cout << "Enter your USERNAME : "; cin >> username;
	cout << "Enter your PASSWORD : "; cin >> password;


	ifstream database;
	database.open(path + username + ".txt");

	getline(database, un);
	getline(database, pw);
	database.close();

	system("cls");

	if (username == un && password == pw) {
		cout << "You are successfully logged in !!\n\n";
	}
	else {
		cout << "Incorrect username or password.\n\n";
	}

	main();

}

void forgotPASS()
{
	string username, un, pw;

	cout << "Enter your account's USERNAME : "; cin >> username;

	ifstream database;
	database.open(path + username + ".txt");

	if (!database)
	{
		database.close();
		system("cls");
		cout << "Your account is not found." << endl << endl;

	}
	else
	{

		getline(database, un);
		getline(database, pw);

		database.close();

		system("cls");

		cout << "\nYour password is " << pw << endl << endl;

	}

	main();

}


