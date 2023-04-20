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

void deployment::add(const string& message) {
	this->messages.push_front(message);

	this->codes = hash<string>()(message);

	this->scope = size(this->messages);

	for (string const& en_in : this->messages) {
		if (en_in != this->messages.front()) {
			this->scope += hash<string>()(en_in);
		}
	}

	this->scope -= this->codes;
};

void deployment::add(const string& message, int codes) {
	this->messages.push_front(message);

	this->codes = codes;

	this->scope = size(this->messages);

	for (string const& en_in : this->messages) {
		if (en_in != this->messages.front()) {
			this->scope += hash<string>()(en_in);
		}
	}

	this->scope -= codes;
};

void deployment::add(const string& message, int scope) {
	this->messages.push_front(message);

	this->scope = scope;

	this->codes = hash<string>()(message);
};

void deployment::add(const string& message, int scope, int codes) {
	this->messages.push_front(message);

	this->codes = codes;
	this->scope = scope;
}

void deployment::clear() {
	this->messages.clear();
};

void deployment::delete_back() {
	this->messages.pop_back();
};

void deployment::delete_front() {
	this->messages.pop_front();
};

list<string> deployment::get_messages() {
	return this->messages;
}