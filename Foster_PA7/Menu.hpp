/*File: Menu.hpp
* Author: Isaiah Foster
* Professor: Andy O'fallon
* Class: Cpts_122
* Assignment: PA6
* Created: 03/24/2025
* Last updated: 04/07/2025
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
	void importMasterRecords(const std::string& filename);
	
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
	std::cout << "3. Store to Master List" << std::endl;
	std::cout << "4. Mark Absences" << std::endl;
	std::cout << "5. Generate Report" << std::endl;
	std::cout << "6. Exit" << std::endl;
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

void Menu::importMasterRecords(const std::string& filename)
{
	recordList.importMaster(filename);
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
				std::cout << "please store to master list first" << endl;
				system("pause");
			}
			else
			{
				importMasterRecords("master.csv");
				loaded = 1;
			}
			break;
		case 3:
			if (!loaded)
			{
				std::cout << "please import records first first" << endl;
				system("pause");
			}
			else
			{
				recordList.store("master.csv");
				stored = 1;
				std::cout << "Master list stored successfully." << std::endl;
				system("pause");
			}
		
			break;
		case 4:
			if (!loaded)
			{
				std::cout << "please import records first first " << endl;
				system("pause");
			}
			else
			{
				recordList.markAbsences();
			}
			break;
		case 5:
			if (!loaded)
			{
				std::cout << "please import records first first " << endl;
				system("pause");
			}
			else
			{
				recordList.generateReports();
			}
			break;
		case 6:
			std::cout << "Exiting program." << std::endl;
			exit(0);
			break;
		default:
			std::cout << "Invalid choice, please try again." << std::endl;
		}
	}
}