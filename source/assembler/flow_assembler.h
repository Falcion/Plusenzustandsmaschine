#include "stateflow.h"
#include "deployment.h"

class assembler {
private:
	states state;
	shifts shift;
	stateflow flow;
	deployment deploy;
public:
	assembler();
	assembler(states state, shifts shift);
	assembler(stateflow stateflow);
	assembler(stateflow stateflow, states state, shifts shift);
	assembler(states state);
	assembler(shifts shift);
	void assemble(stateflow stateflow);
	void assemble(stateflow stateflow, states state, shifts shift);
	void assemble(states state);
	void assemble(shifts shift);
	void disassemble();
	void analysis();
	void redeploy(string& message);
	void redeploy(string& message, int codes);
	void redeploy(string& message, int codes, int scope);
};