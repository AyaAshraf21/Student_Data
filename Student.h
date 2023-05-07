#pragma once
#include <iostream>


using namespace std;

class Student
{
private:
	int ID;
	string name;
	string department;
	float GPA;

public:
	Student();
	Student(int id ,string name , float gpa, string dep );

	int get_id();
	string get_name();
	string get_department();
	float get_gpa();

	void set_id(int id);
	void set_name(string name);
	void set_department(string dep);
	void set_gpa(float gpa);

	bool check_file(string filename);
	void read_file(string filename);

	friend ostream& operator<<(ostream& os, const Student& student);
	friend bool operator>(const Student& left, const Student& right);
	friend bool operator<(const Student& left, const Student& right);
	friend bool operator==(const Student&left, const Student& right);
	bool hasLargerGPAthan(const Student& right);
};


