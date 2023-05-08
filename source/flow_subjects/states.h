#include <string>

using namespace std;

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
    // An enum which defines set of states of current flow
    enum class CLASS_DECLSPEC states : int {
        // State "UNKNOWN" represents unknown or nullable state
        UNKNOWN,
        // State "FAILED" caused by event of mistake or wrong calculations
        FAILED,
        // State "STAGED" caused by event of triaging or restaging and reupdating of process
        STAGED,
        // State "SKIPPED" called when some code conception is being skipped by specified event
        SKIPPED,
        // State "PROCESSING" called whem some code conception caused by block of processing
        PROCESSING,
        // State "SUCCESSFUL" is representation of successful ending of process
        SUCCESSFUL,
    };

    // Generate enum value of state from given ID in string format (case-ignore)
    const states METHOD_DECLSPEC state_from_string(string& shift_name);
    // Generate string value from given state in lower-case format
    const string METHOD_DECLSPEC state_to_string(const states& state);
}