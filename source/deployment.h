#include <string>
#include <vector>

using namespace std;

class deployment {
public:
	string name;
	int id;
	int codes;
	int scope;
	vector<string> message;
	deployment(const string& name);
	deployment(const string& name, int id);
	deployment(const string& name, int id, int codes, int scope);
	void add(const string& message);
	void add(const string& message, int codes);
	void add(const string& message, int codes, int scope);
	void clear();
	void delete_first();
	void delete_front();
	void set_codes(int codes);
	void set_scope(int scope);
};