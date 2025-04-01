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
	int units;
	string program;
	string level;
	int absences;
	std::stack<string> absenceDates;


public:
	RecordData();
	friend void operator>>(istream& lhs, RecordData& rhs);
	friend ostream& operator<<(ostream& lhs, const RecordData& rhs);
};

RecordData::RecordData()
{
	recordNumber = 0;
	IDNumber = 0;
	name = "";
	email = "";
	units = 0;
	program = "";
	level = "";
	absences = 0;
	absenceDates = std::stack<string>();
}

void operator>>(istream& lhs, RecordData& rhs)
{
	string temp;
	getline(lhs, temp); //get rid of first line
	getline(lhs, temp, ',');
	rhs.recordNumber = std::stoi(temp);
	getline(lhs, temp, ',');
	rhs.IDNumber = std::stoi(temp);
	getline(lhs, rhs.name, ',');
	getline(lhs, rhs.email, ',');
	getline(lhs, temp, ',');
	rhs.units = std::stoi(temp);
	getline(lhs, rhs.program, ',');
	getline(lhs, rhs.level);
}

ostream& operator<<(ostream& lhs, const RecordData& rhs)
{
	lhs << rhs.recordNumber << "," << rhs.IDNumber << "," << rhs.name << "," << rhs.email << "," << rhs.units << "," << rhs.program << "," << rhs.level;
	return lhs;
}