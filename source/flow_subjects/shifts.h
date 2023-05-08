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
    // An enum which defines set of shifts of current flow
    enum class CLASS_DECLSPEC shifts : int {
        // Shift of "BEGIN" displaying first instance and start of flow
        BEGIN,
        // Shift of "PAUSE" displaying safe-stop of process
        PAUSE,
        // Shift of "RESUME" displaying when process continues after "PAUSE" event
        RESUME,
        // Shift of "EXIT" displaying when process called an event of exit from method
        EXIT,
        // Shift of "STOP" displaying hard-stop of process
        STOP,
        // Shift of "PHASE" displaying rephasing of current process
        PHASE,
        // Shift of "STAGE" displaying staging or triage of current process
        STAGE,
        // Shift of "MOMENTUM" displaying event in moment
        MOMENTUM
    };

    // Generate enum value of shifts from given ID in string format (case-ignore)
    const shifts METHOD_DECLSPEC shift_from_string(string& shift_name);
    // Generate string value from given shift in lower-case format
    const string METHOD_DECLSPEC shift_to_string(const shifts& shift);
}