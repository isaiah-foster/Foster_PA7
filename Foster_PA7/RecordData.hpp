/*File: RecordData.hpp
* Author: Isaiah Foster
* Professor: Andy O'fallon
* Class: Cpts_122
* Assignment: PA6
* Created: 03/28/2025
* Last updated: 03/28/2025
* Description: Defines RecordData class to store data for a record
*/
#pragma once
#include <iostream>
#include <fstream>
#include <stack>
#include <string>
#include <sstream>
using std::string;
using std::istream;
using std::ostream;
using std::getline;
using std::cout;
using std::endl;

class RecordData
{
private:
	int recordNumber;
	int IDNumber;
	string name;
	string email;
	string units;
	string program;
	string level;
	int absences;
	std::stack<string> absenceDates;


public:
	RecordData();
	void markAbsent();
	friend void operator>>(istream& lhs, RecordData& rhs);
	friend ostream& operator<<(ostream& lhs, RecordData rhs);
	void readMasterRecord(istream& master);
	void pop();
	int getAbsences() const { return absences; }
	string getName() const { return name; }
	std::stack<string> getAbsenceDates() const { return absenceDates; }
};

RecordData::RecordData()
{
	recordNumber = 0;
	IDNumber = 0;
	name = "";
	email = "";
	units = "";
	program = "";
	level = "";
	absences = 0;
	absenceDates = std::stack<string>();
}

//outputs a record not including its absences
void operator>>(istream& lhs, RecordData& rhs)
{	
	string temp;
	getline(lhs, temp, ',');
	rhs.recordNumber = std::stoi(temp);
	getline(lhs, temp, ',');
	rhs.IDNumber = std::stoi(temp);
	getline(lhs, temp, '"');
	getline(lhs, temp, '"');
	rhs.name = "\"" + temp + "\"";
	getline(lhs, rhs.email, ',');
	getline(lhs, rhs.email, ',');
	getline(lhs, rhs.units, ',');
	getline(lhs, rhs.program, ',');
	getline(lhs, rhs.level);
}

ostream& operator<<(ostream& lhs, RecordData rhs)
{
	lhs << rhs.recordNumber << "," << rhs.IDNumber << "," << rhs.name << "," << rhs.email << "," << rhs.units << "," << rhs.program << "," << rhs.level << "," << rhs.absences << ',';
	for (int i = 0; i < rhs.absences; i++)
	{
		
		std::stack<string> temp;
		temp.push(rhs.absenceDates.top());
		lhs << temp.top();
		rhs.pop();
		lhs << ","; //add a comma after each date
	}
	return lhs;
}

void RecordData::readMasterRecord(istream& master) 
{
	string temp;
	getline(master, temp, ',');
	recordNumber = stoi(temp);
	getline(master, temp, ',');
	IDNumber = stoi(temp);
	getline(master, temp, '"');
	getline(master, temp, '"');
	name = "\"" + temp + "\"";
	getline(master, email, ',');
	getline(master, email, ',');
	getline(master, units, ',');
	getline(master, program, ',');
	getline(master, level, ',');
	getline(master, temp, ',');
	absences = stoi(temp);
	for (int i = 0; i < absences; i++)
	{
		if (i + 1 < absences)
		{
			getline(master, temp, ',');
			absenceDates.push(temp);
		}
		else
		{
			getline(master, temp);
			temp[temp.length() - 1] = '\0';
			absenceDates.push(temp);
		}

	}
}

void RecordData::markAbsent()
{
	char absent = '\0';
	cout << "Is " << name << " absent? (y/n): ";
	std::cin >> absent;

	if (absent == 'y')
	{
		time_t t = time(0); // get time now
		struct tm* now = localtime(&t);
		std::ostringstream dateStream;
		dateStream << (now->tm_year + 1900) << '-'
			<< (now->tm_mon + 1) << '-'
			<< now->tm_mday;
		string dateString = dateStream.str();
		absenceDates.push(dateString);
		absences++;
		cout << "Absence recorded for " << name << " on " << dateString << endl << endl;
	}
	else
	{
		cout << "No absence recorded for " << name << endl << endl;
	}
}

void RecordData::pop()
{
	absenceDates.pop();
}