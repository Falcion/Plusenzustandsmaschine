#include <string>
#include <list>

using namespace std;

class deployment {
private:
	list<string> messages;
public:
	string name;
	int id;
	long long codes;
	long long scope;
	deployment(const string& name);
	deployment(const string& name, int id);
	deployment(const string& name, int id, int codes, int scope);
	void add(const string& message);
	void add(const string& message, int codes);
	void add(const string& message, int codes, int scope);
	void clear();
	void delete_back();
	void delete_front();
	list<string> get_messages();
};