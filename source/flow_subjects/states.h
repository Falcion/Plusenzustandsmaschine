#include <string>

using namespace std;

// An enum which defines set of states of current flow
enum class states : int {
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
const states state_from_string(string& shift_name);
// Generate string value from given state in lower-case format
const string state_to_string(const states& shift);