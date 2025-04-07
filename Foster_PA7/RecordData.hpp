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
using std::string;
using std::istream;
using std::ostream;
using std::getline;

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
	int getAbsences();
	friend void operator>>(istream& lhs, RecordData& rhs);
	friend ostream& operator<<(ostream& lhs, const RecordData& rhs);
	void readMasterRecord(istream& master);
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

ostream& operator<<(ostream& lhs, const RecordData& rhs)
{
	lhs << rhs.recordNumber << "," << rhs.IDNumber << "," << rhs.name << "," << rhs.email << "," << rhs.units << "," << rhs.program << "," << rhs.level << "," << rhs.absences;
	for (int i = 0; i < rhs.absences; i++)
	{
		if (i != 0) lhs << ",";
		lhs << rhs.absenceDates.top() << ",";
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
	getline(master, temp);
	absences = stoi(temp);
	for (int i = 0; i < stoi(temp); i++)
	{
		getline(master, temp, ',');
		absenceDates.push(temp);
	}
}