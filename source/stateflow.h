#include "shifts.h";
#include "states.h";

class stateflow {
private:
	states state;
	shifts shift;
public:
	stateflow();
	stateflow(states state, shifts shift);
	explicit stateflow(states state);
	explicit stateflow(shifts shift);
	stateflow(const stateflow& stateflow);
	void edit(states state, shifts shift);
	void edit(states state);
	void edit(shifts shift);
	void flush();
};