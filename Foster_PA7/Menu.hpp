/*File: Menu.hpp
* Author: Isaiah Foster
* Professor: Andy O'fallon
* Class: Cpts_122
* Assignment: PA6
* Created: 03/24/2025
* Last updated: 03/24/2025
* Description: Defines the menu class that gives the user a cmd display of options
*/
#pragma once
#include "RecordList.hpp"

class Menu
{
private:
	RecordList<RecordData> recordList;
public:
	Menu();
	void displayMenu() const;
	int getUserChoice() const;
	void importRecords(const std::string& filename);
	
	void runProgram();
};

Menu::Menu()
{
}

void Menu::displayMenu() const
{
	system("cls");
	std::cout << "1. Import Records" << std::endl;
	std::cout << "2. Load Master List" << std::endl;
	std::cout << "3. Store Master List" << std::endl;
	std::cout << "4. Mark Absences" << std::endl;
	std::cout << "5. Edit Absences" << std::endl;
	std::cout << "6. Generate Report" << std::endl;
	std::cout << "7. Exit" << std::endl;
}

int Menu::getUserChoice() const
{
	int choice = 0;
	std::cout << "Enter your choice: ";
	while (choice < 1 || choice > 7) // Ensure valid input
	{
		std::cin >> choice;
	}
	system("cls");
	return choice;
}

void Menu::importRecords(const std::string& filename)
{
	recordList.import(filename);
	std::cout << "Records imported successfully." << std::endl;
	system("pause");
}

void Menu::runProgram()
{
	int choice = 0, loaded = 0, stored = 0;
	while (true)
	{
		displayMenu();
		choice = getUserChoice();
		switch (choice)
		{
		case 1:
			importRecords("records.csv");
			loaded = 1;
			break;
		case 2:
			if (!stored)
			{
				std::cout << "please store course list first";
			}
			else
			{
				importRecords("master.csv");
				loaded = 1;
			}
			break;
		case 3:
			recordList.store("master.csv");
			stored = 1;
			std::cout << "Master list stored successfully." << std::endl;
			system("pause");
			break;
		case 4:
			std::cout << "Mark Absences functionality not implemented." << std::endl;
			break;
		case 5:
			std::cout << "Edit Absences functionality not implemented." << std::endl;
			break;
		case 6:
			std::cout << "Generate Report functionality not implemented." << std::endl;
			break;
		case 7:
			std::cout << "Exiting program." << std::endl;
			exit(0);
			break;
		default:
			std::cout << "Invalid choice, please try again." << std::endl;
		}
	}
}
