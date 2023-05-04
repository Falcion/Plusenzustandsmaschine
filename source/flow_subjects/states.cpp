#include <string>

#include "states.h"

using namespace std;

// Generate enum value of state from given ID in string format (case-ignore)
const states state_from_string(string& shift_name) {
    for(unsigned int i = 0; i < shift_name.length(); i++){
        if(isupper(shift_name[i]))
            shift_name[i] = tolower(shift_name[i]);
    }

	if (shift_name == "unknown")
		return states::UNKNOWN;
    else if (shift_name == "failed")
        return states::FAILED;
	else if (shift_name == "staged")
		return states::STAGED;
	else if (shift_name == "skipped")
		return states::SKIPPED;
	else if (shift_name == "processing")
		return states::PROCESSING;
	else if (shift_name == "successful")
		return states::SUCCESSFUL;
	else
    // because user can give unknown string and reassembling mistake is not correct for state-machine, we need to throw an exception
		throw exception("unknown given states's name: can't return any state");
}

// Generate string value from given state in lower-case format
const string state_to_string(const states& shift) {
    switch(shift) {
        case states::UNKNOWN:
            return "unknown";
        case states::FAILED:
            return "failed";
        case states::STAGED:
            return "staged";
        case states::SKIPPED:
            return "skipped";
        case states::PROCESSING:
            return "processing";
        case states::SUCCESSFUL:
            return "successful";
    }
}