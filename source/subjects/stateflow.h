#include "items.h"

class stateflow {
protected: 
    states state;
    shifts shift;
public:
    stateflow();
    stateflow(states _state, shifts _shift);
    stateflow(states _state);
    stateflow(shifts _shift);
    //stateflow(stateflow _stateflow); // find a possible way to use "stateflow" in constructor of a stateflow
    void edit(states _state, shifts _shift);
    void selfdestroy();
    states get_state();
    shifts get_shift();
};