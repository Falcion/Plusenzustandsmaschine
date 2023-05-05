#include "../flow_subjects/states.h"
#include "../flow_subjects/shifts.h"

#include <memory>

// A class which represents stateflow and its basic instance
class stateflow {
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
    // Constructor of instance for stateflow
    explicit stateflow(states& state);
    // Constructor of instance for stateflow
    stateflow(states& state, unique_ptr<stateflow> inner);
    // Constructor of instance for stateflow
    explicit stateflow(shifts& shift);
    // Constructor of instance for stateflow
    stateflow(shifts& shift, unique_ptr<stateflow> inner);
    // Constructor of instance for stateflow
    explicit stateflow(unique_ptr<stateflow> inner);
    // Constructor of instance for stateflow
    stateflow(states& state, shifts& shift, unique_ptr<stateflow> inner);
    // Constructor of instance for stateflow
    stateflow(states& state, shifts& shift, unique_ptr<stateflow> inner, long long& code);
    // Constructor of instance for stateflow
    stateflow(states& state, shifts& shift);
    // Method updating params of current instance of flow with given arrangement
    void update(states& state);
    // Method updating params of current instance of flow with given arrangement
    void update(states& state, unique_ptr<stateflow> inner);
    // Method updating params of current instance of flow with given arrangement
    void update(shifts& shift);
    // Method updating params of current instance of flow with given arrangement
    void update(shifts& shift, unique_ptr<stateflow> inner);
    // Method updating params of current instance of flow with given arrangement
    void update(unique_ptr<stateflow> inner);
    // Method updating params of current instance of flow with given arrangement
    void update(states& state, shifts& shift, unique_ptr<stateflow> inner);
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
};

// Static function generating default unchecked integer hash from given instance of a stateflow
static long long gen_hash(states const& state, shifts const& shift) {
    long long hash = 17;

    hash *= 31 + int(state);
    hash *= 31 + int(shift);

    return hash;
}