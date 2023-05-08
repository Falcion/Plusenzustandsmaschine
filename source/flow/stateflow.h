#include "../flow_subjects/states.h"
#include "../flow_subjects/shifts.h"

#include <memory>

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
    // A class which represents stateflow and its basic instance
    class CLASS_DECLSPEC stateflow {
    private:
        // Enum classified value representing state of current flow
        states state;
        // Enum classified value representing shift of current flow
        shifts shift;
        // Classified value representing inner stateflow of double powered instance for flow
        unique_ptr<stateflow> inner;
        // Value representing integer hash of given instance and degree of current unsync and instability of the flow
        long long code;
    public:
        // Constructor of instance for stateflow
        stateflow();
        // Destructor for instance
        ~stateflow();
        // Constructor of instance for stateflow
        stateflow(states& state);
        // Constructor of instance for stateflow
        stateflow(states& state, const stateflow& inner);
        // Constructor of instance for stateflow
        stateflow(shifts& shift);
        // Constructor of instance for stateflow
        stateflow(shifts& shift, const stateflow& inner);
        // Constructor of instance for stateflow
        stateflow(const stateflow& inner);
        // Constructor of instance for stateflow
        stateflow(states& state, shifts& shift, const stateflow& inner);
        // Constructor of instance for stateflow
        stateflow(states& state, shifts& shift, const stateflow& inner, long long& code);
        // Constructor of instance for stateflow
        stateflow(states& state, shifts& shift);
        // Method updating params of current instance of flow with given arrangement
        void update(states& state);
        // Method updating params of current instance of flow with given arrangement
        void update(states& state, const stateflow& inner);
        // Method updating params of current instance of flow with given arrangement
        void update(shifts& shift);
        // Method updating params of current instance of flow with given arrangement
        void update(shifts& shift, const stateflow& inner);
        // Method updating params of current instance of flow with given arrangement
        void update(const stateflow& inner);
        // Method updating params of current instance of flow with given arrangement
        void update(states& state, shifts& shift, const stateflow& inner);
        // Method updating params of current instance of flow with given arrangement
        void update(states& state, shifts& shift);
        // Method clearing current params of instance and randomizing current code for instability check
        void flush();
        // Getter for "STATE" field
        const states get_state();
        // Getter for "SHIFT" field
        const shifts get_shift();
        // Getter for "STATEFLOW_INNER" field
        const unique_ptr<stateflow> get_inner();
        // Getter for "CODE" field
        const long long& get_code();
        // Overriding "EQUALS" operator
        stateflow& operator=(stateflow const& flow);
        friend string to_string(stateflow const& flow) {
            return state_to_string(flow.state) + "::" + shift_to_string(flow.shift);
        }
    };

    // Static function generating default unchecked integer hash from given instance of a stateflow
    static long long gen_hash(states const& state, shifts const& shift) {
        long long hash = 17;

        hash *= 31 + int(state);
        hash *= 31 + int(shift);

        return hash;
    }
}