#include "../pch.h"

#include "flow_assembler.h"

namespace zustandsmaschine {
	// Constructor of assembler
	flow_assembler::flow_assembler() {
		this->state = states::UNKNOWN;
		this->shift = shifts::BEGIN;
		this->deploy = deployment();

		this->flow = stateflow();

		this->code = static_cast<long long>(state) + static_cast<long long>(shift);
	}
	// Deconstructor of assembler
	flow_assembler::~flow_assembler() {
		// Call the destructor of the deployment member explicitly
		// NOT IMPLEMENTED: https://rules.sonarsource.com/cpp/RSPEC-3432
		deploy.~deployment();
	}
	// Constructor of assembler
	flow_assembler::flow_assembler(states state, shifts shift) {
		this->state = state;
		this->shift = shift;
		this->deploy = deployment();

		this->flow = stateflow();

		this->code = static_cast<long long>(state) + static_cast<long long>(shift);

		this->deploy = deployment("ASSEMBLER");
	}
	// Constructor of assembler
	flow_assembler::flow_assembler(stateflow& _stateflow) {
		this->state = _stateflow.get_state();
		this->shift = _stateflow.get_shift();
		this->deploy = deployment();

		this->flow = _stateflow;

		this->code = static_cast<long long>(state) + static_cast<long long>(shift);
	}
	// Constructor of assembler
	flow_assembler::flow_assembler(stateflow& _stateflow, states state, shifts shift) {
		this->state = state;
		this->shift = shift;
		this->deploy = deployment();

		this->flow = _stateflow;

		this->code = static_cast<long long>(state) + static_cast<long long>(shift);
	}
	// Constructor of assembler
	flow_assembler::flow_assembler(states state) {
		this->state = state;
		this->shift = shifts::BEGIN;
		this->deploy = deployment();

		this->flow = stateflow();

		this->code = static_cast<long long>(state) + static_cast<long long>(shift);
	}
	// Constructor of assembler
	flow_assembler::flow_assembler(shifts shift) {
		this->state = states::UNKNOWN;
		this->shift = shift;
		this->deploy = deployment();

		this->flow = stateflow();

		this->code = static_cast<long long>(state) + static_cast<long long>(shift);
	}
	// Change instance of flow's assembler
	void flow_assembler::assemble(stateflow& _stateflow) {
		string subflow_message = "MOVED FROM: { " + state_to_string(this->state) + ", " + shift_to_string(this->shift) + "; } => { " + state_to_string(_stateflow.get_state()) + ", " + shift_to_string(_stateflow.get_shift()) + "; }";
		string substate_message = "MOVED WITHIN STATEFLOWS: { " + to_string(this->flow) + "; } => { " + to_string(_stateflow) + " };";

		redeploy(subflow_message);
		redeploy(substate_message);

		this->state = _stateflow.get_state();
		this->shift = _stateflow.get_shift();

		this->flow = _stateflow;

		this->code = static_cast<long long>(state) + static_cast<long long>(shift);
	}
	// Change instance of flow's assembler
	void flow_assembler::assemble(stateflow& _stateflow, states state, shifts shift) {
		string subflow_message = "MOVED FROM: { " + state_to_string(this->state) + ", " + shift_to_string(this->shift) + "; } => { " + state_to_string(state) + ", " + shift_to_string(shift) + "; }";
		string substate_message = "MOVED WITHIN STATEFLOWS: { " + to_string(this->flow) + "; } => { " + to_string(_stateflow) + " };";

		redeploy(subflow_message);
		redeploy(substate_message);

		this->state = state;
		this->shift = shift;

		this->flow = _stateflow;

		this->code = static_cast<long long>(state) + static_cast<long long>(shift);
	}
	// Change instance of flow's assembler
	void flow_assembler::assemble(states state) {
		string subflow_message = "MOVED FROM: { " + state_to_string(this->state) + ", " + shift_to_string(this->shift) + "; } => { " + state_to_string(state) + ", " + shift_to_string(shift) + "; }";
		
		redeploy(subflow_message);

		this->state = state;
		this->shift = shifts::BEGIN;

		this->flow = stateflow();

		this->code = static_cast<long long>(state) + static_cast<long long>(shift);
	}
	// Change instance of flow's assembler
	void flow_assembler::assemble(shifts shift) {
		string subflow_message = "MOVED FROM: { " + state_to_string(this->state) + ", " + shift_to_string(this->shift) + "; } => { " + state_to_string(state) + ", " + shift_to_string(shift) + "; }";
		
		redeploy(subflow_message);

		this->state = states::UNKNOWN;
		this->shift = shift;

		this->flow = stateflow();

		this->code = static_cast<long long>(state) + static_cast<long long>(shift);
	}
	// Nullify instance of flow's assembler
	void flow_assembler::disassemble() {
		this->state = states::UNKNOWN;
		this->shift = shifts::BEGIN;

		this->flow = stateflow();

		this->code = 0;
	}
	// Analyze current instance of assembler
	void flow_assembler::analyze() {
		switch (state) {
		case states::UNKNOWN:
			if (shift == shifts::EXIT || shift == shifts::MOMENTUM) {
				string message = state_to_string(state) + "::" + shift_to_string(shift) + " is caught in current instance of assembly!";
				redeploy(message, hash<string>()(message), -1);
			}
			else
				code += 10000;
			break;
		case states::FAILED:
			if (shift == shifts::EXIT || shift == shifts::MOMENTUM) {
				string message = state_to_string(state) + "::" + shift_to_string(shift) + " is caught in current instance of assembly!";
				redeploy(message, hash<string>()(message), -1);
			}
			break;
		case states::STAGED:
			if (shift == shifts::EXIT || shift == shifts::STAGE || shift == shifts::PAUSE) {
				string message = state_to_string(state) + "::" + shift_to_string(shift) + " is caught in current instance of assembly!";
				redeploy(message, hash<string>()(message), -1);
			}
			break;
		case states::SKIPPED:
			if (shift == shifts::EXIT || shift == shifts::STAGE || shift == shifts::PAUSE) {
				string message = state_to_string(state) + "::" + shift_to_string(shift) + " is caught in current instance of assembly!";
				redeploy(message, hash<string>()(message), -1);
			}
			break;
		case states::PROCESSING:
			if (shift == shifts::EXIT) {
				string message = state_to_string(state) + "::" + shift_to_string(shift) + " is caught in current instance of assembly!";
				redeploy(message, hash<string>()(message), -1);
			}
			break;
		case states::SUCCESSFUL:
			if (shift == shifts::STOP) {
				string message = state_to_string(state) + "::" + shift_to_string(shift) + " is caught in current instance of assembly!";
				redeploy(message, hash<string>()(message), -1);
			}
			break;
		}
		
	}
	// Analyze current instance through flow inner stability check
	void flow_assembler::analyze(stateflow& flow) {
		if ((int(this->flow.get_state()) > int(flow.get_state())) && (int(this->flow.get_shift()) > int(flow.get_shift()))) {
			string refcode = "[REF: " + to_string(int(this->flow.get_state())) + ">" + to_string(int(flow.get_state())) + " && " + to_string(int(this->flow.get_shift())) + ">" + to_string(int(flow.get_shift())) + "]";

			string message = "Analyzer of inner stabilizers called within, result - SUCCESS! " + refcode;

			redeploy(message);
		}
		else if ((int(this->flow.get_state()) > int(flow.get_state())) && (int(this->flow.get_shift()) < int(flow.get_shift()))) {
			string refcode = "[REF: " + to_string(int(this->flow.get_state())) + ">" + to_string(int(flow.get_state())) + " && " + to_string(int(this->flow.get_shift())) + "<" + to_string(int(flow.get_shift())) + "]";

			string message = "Analyzer of inner stabilizers called within, result - UNKNOWN! " + refcode;

			redeploy(message, hash<string>()(message), -1);
		}
		else if ((int(this->flow.get_state()) < int(flow.get_state())) && (int(this->flow.get_shift()) > int(flow.get_shift()))) {
			string refcode = "[REF: " + to_string(int(this->flow.get_state())) + "<" + to_string(int(flow.get_state())) + " && " + to_string(int(this->flow.get_shift())) + ">" + to_string(int(flow.get_shift())) + "]";

			string message = "Analyzer of inner stabilizers called within, result - UNKNOWN! " + refcode;

			redeploy(message, hash<string>()(message), -1);
		}
		else {
			string refcode = "[REF: " + to_string(int(this->flow.get_state())) + "<" + to_string(int(flow.get_state())) + " && " + to_string(int(this->flow.get_shift())) + "<" + to_string(int(flow.get_shift())) + "]";

			string message = "Analyzer of inner stabilizers called within, result - FAILED! " + refcode;

			redeploy(message, hash<string>()(message), -1);
		}
	}
	// Method of "APPROACH" type to deployment, adding message into instance of interactions
	void flow_assembler::redeploy(string& message) {
		this->deploy.add(message);
	}
	// Method of "DIRECT-APPROACH" type to deployment, adding message into instance of interactions within custom hash
	void flow_assembler::redeploy(string& message, int codes) {
		this->deploy.add(message, codes);
	}
	// Method of "DIRECT-DIRECT APPROACH" type to deployment, adding message into instance of interactions within custom hash
	void flow_assembler::redeploy(string& message, int codes, int scope) {
		this->deploy.add(message, codes, scope);
	}
	// Get message system of current instance
	deployment& flow_assembler::get_deployment() {
		return this->deploy;
	}
	// Get state and shift of instance flow's
	pair<states, shifts> flow_assembler::get_flow() {
		return pair<states, shifts>(this->state, this->shift);
	}
	// Get stabilizer inner of current assembler's flow instance
	stateflow& flow_assembler::get_inner() {
		return this->flow;
	}
}