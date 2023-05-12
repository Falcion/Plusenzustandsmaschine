#include "../pch.h"

#include "deployment.h"

#include <chrono>

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
    // Delete front element from dictionary alike list
    void deployment::delete_front() {
        this->interactions.erase(interactions.begin());
    }
    // Delete back element from dictionary alike list
    void deployment::delete_back() {
        this->interactions.erase(interactions.end());
    }
    deployment::deployment()
    {
        this->name = "Default";
        this->id = 0;
    }
    // Deconstructor of deployment
    deployment::~deployment() {
        interactions.clear();
    }
    // Constructor of deployment
    deployment::deployment(string name) {
        this->name = name;
        this->id = hash<string>()(name);
    }
    // Constructor of deployment
    deployment::deployment(string name, int& id) {
        this->name = name;
        this->id = id;
    }
    // Constructor of deployment
    deployment::deployment(string name, int& id, int& codes, int& scope) {
        this->name = name;
        this->id = id;
        this->codes = codes;
        this->scope = scope;

        add("Deployment was initialized with custom codes and scope!");
    }
    // Method of "APPROACH" type to deployment, adding message into instance of interactions
    void deployment::add(string message) {
        // Compute the timestamp in microseconds
        auto now = std::chrono::high_resolution_clock::now();
        std::size_t timestamp = std::chrono::time_point_cast<std::chrono::microseconds>(now).time_since_epoch().count();

        auto current_codes = hash<string>()(message);

        // Combine the hash and timestamp to generate the scope value
        this->scope = current_codes ^ timestamp ^ this->codes;

        if (this->scope == -1) { // "-1" can't be got by automatic system, it must be given through "DIRECT-DIRECT APPROACH"
            this->scope += interactions.size();
        }

        this->codes = current_codes;

        auto sizet = interactions.size();
        interactions.insert({ sizet+1, pair<long long, string>(codes, message) });

        analyze();
    }
    // Method of "DIRECT-APPROACH" type to deployment, adding message into instance of interactions within custom hash
    void deployment::add(string message, int _codes) {
        // Compute the timestamp in microseconds
        auto now = std::chrono::high_resolution_clock::now();
        std::size_t timestamp = std::chrono::time_point_cast<std::chrono::microseconds>(now).time_since_epoch().count();

        // Combine the hash and timestamp to generate the scope value
        this->scope = _codes ^ timestamp ^ this->codes;

        if (this->scope == -1) { // "-1" can't be got by automatic system, it must be given through "DIRECT-DIRECT APPROACH"
            this->scope += interactions.size();
        }

        this->codes = _codes;

        auto sizet = interactions.size();
        interactions.insert({ sizet + 1, pair<long long, string>(_codes, message) });
        interactions.insert({ sizet + 2, pair<long long, string>(_codes, "Event had been called with custom \"DIRECT APPROACH\" variable, its delegates are attached: " + to_string(scope)) });

        analyze();
    }
    // Method of "DIRECT-DIRECT APPROACH" type to deployment, adding message into instance of interactions within custom hash
    void deployment::add(string message, int _codes, int _scope) {
        this->codes = _codes;

        this->scope = _scope; // here you can get "-1" through direct approach

        auto sizet = interactions.size();
        interactions.insert({ sizet + 1, pair<long long, string>(_codes, message) });
        interactions.insert({ sizet + 2, pair<long long, string>(_codes, "Event had been called with custom \"DIRECT-DIRECT APPROACH\" variable, its delegates are attached: " + to_string(scope)) });

        analyze();
    }
    // Method clearing interactions without editing "CODES" and "SCOPE"
    void deployment::clear() {
        this->interactions.clear();
        add("Deployment was cleared!", -1, 0);
    }
    // Private analyzer which gets "CODES" and "SCOPE" to concat them into interactions
    void deployment::analyze() {
        if (this->codes == -1) {
            add("Deployment has caught instability value!");
        }
        
        if (this->scope == -1) {
            add("Total checksum SCOPE of deployment caught in total instability and exception situtation! Misbehave concluded in " + to_string(codes) + "/" + to_string(interactions.size()));
        }
    }
    //LNK2019
    deployment& deployment::operator=(const deployment& other)
    {
        if (this != &other)
        {
            // copy all fields from the other object
            this->name = other.name;
            this->id = other.id;
            this->codes = other.codes;
            this->scope = other.scope;
            this->interactions = other.interactions;
        }
        return *this;
    }
}