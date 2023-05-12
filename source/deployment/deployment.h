#include <string>
#include <unordered_map>

#pragma once
#ifdef _EXPORTING
#define CLASS_DECLSPEC    __declspec(dllexport)
#else
#define CLASS_DECLSPEC    __declspec(dllimport)
#endif
#ifdef _EXPORTING
#define METHOD_DECLSPEC   __declspec(dllexport)
#else
#define METHOD_DECLSPEC   __declspec(dllimport)
#endif

using namespace std;

namespace zustandsmaschine {
    // Custom message system within interactions
    class CLASS_DECLSPEC deployment {
    private:
        // Private analyzer which gets "CODES" and "SCOPE" to concat them into interactions
        void analyze();
    public:
        // Name for deployment for better object-relations
        string name;
        // Unique ID for deployment for better object-relations
        size_t id = hash<string>()(name);
        // Hash value of last "interaction" (added message) which symbolizes stability of current deployment
        long long codes = 0;
        // Hash combination value of checksum of deployment, current time which symbolizes chaos of current deployment and exception position through code with analyzer
        long long scope = 0;
        // Dictionary of messages paired with their stability hashes inserted by position's of current deployment (ID of position)
        vector<pair<long long, string>> interactions;
        // Delete front element from dictionary alike list
        void delete_front();
        // Delete back element from dictionary alike list
        void delete_back();
        //Constructor of deployment
        deployment();
        // Deconstructor of deployment
        ~deployment();
        // Constructor of deployment
        explicit deployment(string name);
        // Constructor of deployment
        deployment(string name, int& id);
        // Constructor of deployment
        deployment(string name, int& id, int& codes, int& scope);
        // Method of "APPROACH" type to deployment, adding message into instance of interactions
        void add(string message);
        // Method of "DIRECT-APPROACH" type to deployment, adding message into instance of interactions within custom hash
        void add(string message, int _codes);
        // Method of "DIRECT-DIRECT APPROACH" type to deployment, adding message into instance of interactions within custom hash
        void add(string message, int _codes, int _scope);
        // Method clearing interactions without editing "CODES" and "SCOPE"
        void clear();
        //LNK2019
        deployment& operator=(const deployment& other);
    };
}