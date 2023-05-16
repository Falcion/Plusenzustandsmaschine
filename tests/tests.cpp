#include <iostream>
#include "assembler/flow_assembler.h"

#include "tests.h"

using namespace zustandsmaschine;

void UPDATING_STATEFLOW_TEST1() {
    // Create a stateflow instance
    auto sflow = stateflow();

    cout << "[-------- TEST 1 ---------]" << endl;
    cout << ">> WAS: " << to_string(sflow) << endl;  // Print the initial state of the stateflow

    // Update the stateflow with new state and shift
    sflow.update(states::STAGED, shifts::PAUSE);

    cout << ">> NOW: " << to_string(sflow) << endl;  // Print the updated state of the stateflow
    cout << "[-------- TEST 1 ---------]" << endl;

    cout << endl;
}

void UPDATING_STATEFLOW_TEST2() {
    // Create a stateflow instance
    auto sflow = stateflow();

    cout << "[-------- TEST 2 ---------]" << endl;
    cout << ">> WAS: " << to_string(sflow) << endl;  // Print the initial state of the stateflow

    // Update the stateflow with new state and shift
    sflow.update(states::PROCESSING, shifts::PHASE);

    cout << ">> NOW: " << to_string(sflow) << endl;  // Print the updated state of the stateflow
    cout << "[-------- TEST 2 ---------]" << endl;

    cout << endl;
}

void MEMORY_CHECK_DEPLOYMENT_TEST1() {
    // Create a deployment instance
    auto deploy = deployment();

    cout << "[-------- TEST 3 ---------]" << endl;
    cout << ">> Size of interactions map: " << deploy.interactions.size() << endl;  // Print the initial size of the interactions map

    // Add a debug message to the interactions map
    deploy.add("DEBUG MESSAGE!");

    cout << ">> Size of interactions map: " << deploy.interactions.size() << endl;  // Print the updated size of the interactions map
    cout << ">> Added message: " << deploy.interactions[1].first << ": " << deploy.interactions[1].second << endl;  // Print the added message and its corresponding value
    cout << "[-------- TEST 3 ---------]" << endl;

    cout << endl;
}

void MEMORY_CHECK_DEPLOYMENT_TEST2() {
    // Create a deployment instance
    auto deploy = deployment();

    cout << "[-------- TEST 4 ---------]" << endl;
    cout << ">> Size of interactions map: " << deploy.interactions.size() << endl;  // Print the initial size of the interactions map

    // Add an error message with a specific error code to the interactions map
    deploy.add("ERROR", -1);

    cout << ">> Size of interactions map: " << deploy.interactions.size() << endl;  // Print the updated size of the interactions map
    cout << ">> Added message: " << deploy.interactions[1].first << ": " << deploy.interactions[1].second << endl;  // Print the first added message and its corresponding value
    cout << ">> Added message: " << deploy.interactions[2].first << ": " << deploy.interactions[2].second << endl;  // Print the second added message and its corresponding value
    cout << "[-------- TEST 4 ---------]" << endl;

    cout << endl;
}

void ASSEMBLY_CHECK_TEST1() {
    // Create a flow_assembler instance
    auto fassembler = flow_assembler();

    cout << "[-------- TEST 5 ---------]" << endl;
    cout << ">> Assembler's instance: " << state_to_string(fassembler.get_flow().first) << ":" << shift_to_string(fassembler.get_flow().second) << endl;  // Print the initial state and shift of the assembler's instance

    // Change the state and shift of the assembler's instance using the assemble() method
    fassembler.assemble(states::PROCESSING, shifts::MOMENTUM);

    cout << ">> Instance after change: " << state_to_string(fassembler.get_flow().first) << ":" << shift_to_string(fassembler.get_flow().second) << endl;  // Print the state and shift of the assembler's instance after the change

    fassembler.assemble(states::SUCCESSFUL, shifts::EXIT);

    cout << ">> Instance after change: " << state_to_string(fassembler.get_flow().first) << ":" << shift_to_string(fassembler.get_flow().second) << endl;  // Print the state and shift of the assembler's instance after the change
    cout << "[-------- TEST 5 ---------]" << endl;

    cout << endl;
}

void ASSEMBLY_CHECK_TEST2() {
    // Create a flow_assembler instance
    auto fassembler = flow_assembler();

    // Change the state and shift of the assembler's instance using the assemble() method
    fassembler.assemble(states::PROCESSING, shifts::MOMENTUM);
    fassembler.assemble(states::SUCCESSFUL, shifts::EXIT);

    cout << "[-------- TEST 6 ---------]" << endl;

    // Iterate over the interactions in the assembler's deployment and print the messages
    for (auto const& i : fassembler.get_deployment().interactions) {
        cout << "Message of assembler's deployment (" << i.first << "): " << i.second.first << "[:] " << i.second.second << endl;
    }

    cout << "[-------- TEST 6 ---------]" << endl;

    cout << endl;
}

void PARSING_EXCEPTION_CHECK_STATE_TEST() {
    // Define an input message for future parsing
    string msg = "8asdjbkas";

    cout << "[-------- EXCEPTION TEST 1 (TEST 7) ---------]" << endl;

    cout << ">> Input for future parsing method (catching exception): " << msg << endl;

    try {
        // Try to parse the input message and obtain the state
        states state = state_from_string(msg);

        cout << ">> Parsed state: " << state_to_string(state) << endl;
    }
    catch (exception& e) {
        // Catch any exception that occurs during parsing and print the reason
        cout << ">> Parsing exception occurred. Reason: " << e.what() << endl;
    }

    // Update the input message
    msg = "processing";

    // Parse the input message with default values
    auto state = state_from_string(msg);

    cout << ">> Now working with default values, entry state value: " << msg << endl;

    cout << ">> Result: " << state_to_string(state) << endl;

    cout << "[-------- EXCEPTION TEST 1 (TEST 7) ---------]" << endl;

    cout << endl;
}

void PARSING_EXCEPTION_CHECK_SHIFT_TEST() {
    // Define an input message for future parsing
    string msg = "8asdjbkas";

    cout << "[-------- EXCEPTION TEST 2 (TEST 8) ---------]" << endl;

    cout << ">> Input for future parsing method (catching exception): " << msg << endl;

    try {
        // Try to parse the input message and obtain the shift
        shifts shift = shift_from_string(msg);

        cout << ">> Parsed shift: " << shift_to_string(shift) << endl;
    }
    catch (exception& e) {
        // Catch any exception that occurs during parsing and print the reason
        cout << ">> Parsing exception occurred. Reason: " << e.what() << endl;
    }

    // Update the input message
    msg = "pause";

    // Parse the input message with default values
    auto shift = shift_from_string(msg);

    cout << ">> Now working with default values, entry shift value: " << msg << endl;

    cout << ">> Result: " << shift_to_string(shift) << endl;

    cout << "[-------- EXCEPTION TEST 2 (TEST 8) ---------]" << endl;

    cout << endl;
}

void LOGIC_LIMIT_ASSEMBLER_TEST1() {
    cout << "[-------- LOGIC LIMIT TEST 1 (TEST 9) ---------]" << endl;
    flow_assembler assembler;

    // Set the state and shift of the assembler
    assembler.assemble(states::UNKNOWN);
    assembler.assemble(shifts::EXIT);

    // Analyze the assembler
    assembler.analyze();

    // Retrieve the interactions from the deployment
    auto interactions = assembler.get_deployment().interactions;

    // Print the interactions
    for (const auto& interaction : interactions) {
        std::cout << ">> " << interaction.second.first << "[:] " << interaction.second.second << std::endl;
    }
    cout << "[-------- LOGIC LIMIT TEST 1 (TEST 9) ---------]" << endl;
    cout << endl;
}

void LOGIC_LIMIT_ASSEMBLER_TEST2() {
    cout << "[-------- LOGIC LIMIT TEST 2 (TEST 10) ---------]" << endl;

    // Create a flow_assembler instance
    flow_assembler assembler;

    // Create a stateflow instance for comparison
    stateflow flow(states::PROCESSING, shifts::PHASE);

    // Analyze the flow_assembler instance
    assembler.analyze(flow);

    // Retrieve the interactions from the deployment
    auto interactions = assembler.get_deployment().interactions;

    // Print the interactions
    for (const auto& interaction : interactions) {
        std::cout << ">> " << interaction.second.first << "[:] " << interaction.second.second << std::endl;
    }

    cout << "[-------- LOGIC LIMIT TEST 2 (TEST 10) ---------]" << endl;
    cout << endl;
}