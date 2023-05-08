#include "../pch.h"

#include <string>

#include "shifts.h"

using namespace std;

namespace zustandsmaschine {
    // Generate enum value of shifts from given ID in string format (case-ignore)
    const shifts shift_from_string(string& shift_name) {
        for (unsigned int i = 0; i < shift_name.length(); i++) {
            if (isupper(shift_name[i]))
                shift_name[i] = tolower(shift_name[i]);
        }

        if (shift_name == "begin")
            return shifts::BEGIN;
        else if (shift_name == "pause")
            return shifts::PAUSE;
        else if (shift_name == "stage")
            return shifts::STAGE;
        else if (shift_name == "resume")
            return shifts::RESUME;
        else if (shift_name == "exit")
            return shifts::EXIT;
        else if (shift_name == "stop")
            return shifts::STOP;
        else if (shift_name == "phase")
            return shifts::PHASE;
        else if (shift_name == "stage")
            return shifts::STAGE;
        else if (shift_name == "momentum")
            return shifts::MOMENTUM;
        else
            // because user can give unknown string and there is no universum shift, we need to throw an exception
            throw exception("unknown given shifts's name: can't return any shift");
    }

    // Generate string value from given shift in lower-case format
    const string shift_to_string(const shifts& shift) {
        switch (shift) {
        case shifts::BEGIN:
            return "begin";
        case shifts::PAUSE:
            return "pause";
        case shifts::RESUME:
            return "resume";
        case shifts::EXIT:
            return "exit";
        case shifts::STOP:
            return "stop";
        case shifts::PHASE:
            return "phase";
        case shifts::STAGE:
            return "stage";
        case shifts::MOMENTUM:
            return "momentum";
        }
    }
}