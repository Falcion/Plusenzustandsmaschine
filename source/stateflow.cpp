#include "stateflow.h"

stateflow::stateflow() {
	this->state = states();
	this->shift = shifts();
}

stateflow::stateflow(states state, shifts shift) {
	this->state = state;
	this->shift = shift;
}

stateflow::stateflow(states state) {
	this->state = state;
	this->shift = shifts();
}

stateflow::stateflow(shifts shift) {
	this->state = states();
	this->shift = shift;
}

stateflow::stateflow(const stateflow& stateflow) {
	this->state = stateflow.state;
	this->shift = stateflow.shift;
}

void stateflow::edit(states state, shifts shift) {
	this->state = state;
	this->shift = shift;
}

void stateflow::edit(states state) {
	this->state = state;
}

void stateflow::edit(shifts shift) {
	this->shift = shift;
}

void stateflow::flush() {
	this->state = states();
	this->shift = shifts();
}