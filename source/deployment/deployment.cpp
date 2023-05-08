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

namespace zustandsmaschine {
    // Delete front element from dictionary alike list
    void deployment::delete_front() {
        this->interactions.erase(interactions.begin());
    }
    // Delete back element from dictionary alike list
    void deployment::delete_back() {
        this->interactions.erase(interactions.end());
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
        int size = interactions.size();

        // Compute the timestamp in microseconds
        auto now = std::chrono::high_resolution_clock::now();
        std::size_t timestamp = std::chrono::time_point_cast<std::chrono::microseconds>(now).time_since_epoch().count();

        auto current_codes = hash<string>()(message);

        // Combine the hash and timestamp to generate the scope value
        this->scope = current_codes ^ timestamp ^ this->codes;

        if (this->scope == -1) { // "-1" can't be got by automatic system, it must be given through "DIRECT-DIRECT APPROACH"
            this->scope += size;
        }

        this->codes = current_codes;

        // if given pair does exists in given interactions map
        if (interactions.find(size) != interactions.end()) {
            pair<long long, string> temp = interactions[size];

            interactions[size] == pair<long long, string>(codes, message);

            int i = size;

            // scavenging existing pairs of given range (to non-existent)
            while (interactions.find(size) != interactions.end()) {
                i++;
            }

            // after scavenging to non-existent, we can finally add
            interactions.insert(make_pair(i, pair<long long, string>(codes, message)));
        }
        else {
            interactions[size++] = pair<long long, string>(codes, message);
        }

        analyze();
    }
    // Method of "DIRECT-APPROACH" type to deployment, adding message into instance of interactions within custom hash
    void deployment::add(string message, int _codes) {
        int size = interactions.size();

        // Compute the timestamp in microseconds
        auto now = std::chrono::high_resolution_clock::now();
        std::size_t timestamp = std::chrono::time_point_cast<std::chrono::microseconds>(now).time_since_epoch().count();

        // Combine the hash and timestamp to generate the scope value
        this->scope = _codes ^ timestamp ^ this->codes;

        if (this->scope == -1) { // "-1" can't be got by automatic system, it must be given through "DIRECT-DIRECT APPROACH"
            this->scope += size;
        }

        this->codes = _codes;

        // if given pair does exists in given interactions map
        if (interactions.find(size) != interactions.end()) {
            pair<long long, string> temp = interactions[size];

            interactions[size] == pair<long long, string>(_codes, message);

            int i = size;

            // scavenging existing pairs of given range (to non-existent)
            while (interactions.find(size) != interactions.end()) {
                i++;
            }

            // after scavenging to non-existent, we can finally add
            interactions.insert(make_pair(i, pair<long long, string>(_codes, message)));
            interactions.insert(make_pair(i+1, pair<long long, string>(_codes, "Event had been called with custom \"DIRECT APPROACH\" variable, its delegate is attached")));
        }
        else {
            interactions[size++] = pair<long long, string>(_codes, message);
            interactions[size+2] = pair<long long, string>(_codes, "Event had been called with custom \"DIRECT APPROACH\" variable, its delegate is attached");
        }

        analyze();
    }
    // Method of "DIRECT-DIRECT APPROACH" type to deployment, adding message into instance of interactions within custom hash
    void deployment::add(string message, int _codes, int scope) {
        int size = interactions.size();

        this->codes = _codes;

        this->scope = scope; // here you can get "-1" through direct approach

        // if given pair does exists in given interactions map
        if (interactions.find(size) != interactions.end()) {
            pair<long long, string> temp = interactions[size];

            interactions[size] == pair<long long, string>(_codes, message);

            int i = size;

            // scavenging existing pairs of given range (to non-existent)
            while (interactions.find(size) != interactions.end()) {
                i++;
            }

            // after scavenging to non-existent, we can finally add
            interactions.insert(make_pair(i, pair<long long, string>(_codes, message)));
            interactions.insert(make_pair(i + 1, pair<long long, string>(_codes, "Event had been called with custom \"DIRECT-DIRECT APPROACH\" variable, its delegate is attached: " + to_string(scope))));
        }
        else {
            interactions[size++] = pair<long long, string>(_codes, message);
            interactions[size + 2] = pair<long long, string>(_codes, "Event had been called with custom \"DIRECT-DIRECT APPROACH\" variable, its delegate is attached: " + to_string(scope));
        }

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
        else {
            int size = interactions.size();

            if (interactions[size].first != this->codes)
                interactions[size] = pair<long long, string>(this->codes, interactions[size].second);
        }
        
        if (this->scope == -1) {
            add("Total checksum SCOPE of deployment caught in total instability and exception situtation! Misbehave concluded in " + to_string(codes) + "/" + to_string(interactions.size()));
        }
        else
            add("[APPROXIMATE STEP] Scope of step: " + to_string(this->scope));
    }
}