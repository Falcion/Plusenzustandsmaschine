#include "stateflow.h"

class assembler {
protected:
    stateflow _stateflow;
    states state;
    shifts shift;
public:
    assembler();
    assembler(stateflow n_stateflow);
    assembler(stateflow n_stateflow, states _state, shifts _shift);
    assembler(states _state, shifts _shift);
    assembler(states _state);
    assembler(shifts _shift);
    void assemble(stateflow n_stateflow);
    void assemble(stateflow n_stateflow, states _state, shifts _shift);
    void assemble(states _state, shifts _shift);
    void assemble(states _state);
    void assemble(shifts _shift);
    void disassemble();
};