#include <string>
#include <map>

using namespace std;

class deployment {
    private:
    string name;
    int id;
    long long codes;
    long long scope;
    public:
    map<int, pair<int, string>> interactions;
    void delete_front();
    void delete_back();
    deployment(string& name);
    deployment(string& name, int& id);
    deployment(string& name, int& id, int& codes, int& scope);
    void add(string& message);
	void add(string& message, int codes);
	void add(string& message, int codes, int scope);
	void clear();
    string& get_name();
    int& get_id();
    long long get_codes();
    long long get_scope();
};