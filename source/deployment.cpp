#include "deployment.h"

deployment::deployment(const string& name) {
	this->name = name;
	this->id = 0;
	this->codes = 0;
	this->scope = 0;
}

deployment::deployment(const string& name, int id) {
	this->name = name;
	this->id = id;
	this->codes = 0;
	this->scope = 0;
}

deployment::deployment(const string& name, int id, int codes, int scope) {
	this->name = name;
	this->id = id;
	this->codes = codes;
	this->scope = scope;
}

void deployment::add(const string& message) {};
void deployment::add(const string& message, int codes) {};
void deployment::add(const string& message, int scope) {};
void deployment::clear() {};
void deployment::delete_first() {};
void deployment::delete_front() {};
void deployment::set_codes(int codes) {};
void deployment::set_scope(int scope) {};