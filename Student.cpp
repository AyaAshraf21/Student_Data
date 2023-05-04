#include "Student.h"


// constructor

Student::Student(){}

Student::Student(int id, string name, float gpa, string dep) {
	this->ID = id;
	this->name = name;
	this->department = dep;
	this->GPA = gpa;
}


// getters
int Student::get_id() {
	return ID;
}
string Student::get_name() {
	return name;
}
string Student::get_department() {
	return department;
}
float Student::get_gpa() {
	return GPA;
}


//setters
void Student::set_id(int id) {
	this->ID = id;
}
void Student::set_name(string name) {
	this->name = name;
}
void Student::set_department(string dep) {
	this->department = dep;
}
void Student::set_gpa(float gpa) {
	this->GPA = gpa;
}



