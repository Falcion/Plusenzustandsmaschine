#include "../pch.h"

#include "../deployment/deployment.h"
#include "../flow/stateflow.h"

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
	// Stateflow assembler
	class flow_assembler {
	private:
		// State of current assembler's flow instance
		states state;
		// Shift of current assembler's flow instance
		shifts shift;
		// Stabilizer inner of current assembler's flow instance
		stateflow flow;
		// Message system of current instance
		deployment deploy = deployment("ASSEMBLER");
		// Hash of current stable check of assembler
		long long code = 0;
	public:
		// Constructor of assembler
		flow_assembler();
		// Deconstructor of assembler
		~flow_assembler();
		// Constructor of assembler
		flow_assembler(states state, shifts shift);
		// Constructor of assembler
		flow_assembler(stateflow& _stateflow);
		// Constructor of assembler
		flow_assembler(stateflow& _stateflow, states state, shifts shift);
		// Constructor of assembler
		flow_assembler(states state);
		// Constructor of assembler
		flow_assembler(shifts shift);
		// Change instance of flow's assembler
		void assemble(stateflow& _stateflow);
		// Change instance of flow's assembler
		void assemble(stateflow& _stateflow, states state, shifts shift);
		// Change instance of flow's assembler
		void assemble(states state);
		// Change instance of flow's assembler
		void assemble(shifts shift);
		// Nullify instance of flow's assembler
		void disassemble();
		// Analyze current instance of assembler
		void analyze();
		// Analyze current instance through flow inner stability check
		void analyze(stateflow& _stateflow);
		// Method of "APPROACH" type to deployment, adding message into instance of interactions
		void redeploy(string& message);
		// Method of "DIRECT-APPROACH" type to deployment, adding message into instance of interactions within custom hash
		void redeploy(string& message, int codes);
		// Method of "DIRECT-DIRECT APPROACH" type to deployment, adding message into instance of interactions within custom hash
		void redeploy(string& message, int codes, int scope);
		// Get message system of current instance
		deployment& get_deployment();
		// Get state and shift of instance flow's
		pair<states, shifts> get_flow();
		// Get stabilizer inner of current assembler's flow instance
		stateflow& get_inner();
	};
}