#include "../pch.h"

#include "stateflow.h"

#include <memory>

namespace zustandsmaschine {
    // Constructor of instance for stateflow
    stateflow::stateflow() {
        this->state = states::UNKNOWN;
        this->shift = shifts::BEGIN;

        this->code = gen_hash(this->state, this->shift);
    };
    // Destructor for instance
    stateflow::~stateflow() {

    }
    // Constructor of instance for stateflow
    stateflow::stateflow(states state) {
        this->state = state;
        this->shift = shifts::BEGIN;

        this->code = gen_hash(this->state, this->shift);
    };
    // Constructor of instance for stateflow
    stateflow::stateflow(states state, const pair<states, shifts> inner) {
        this->state = state;
        this->shift = shifts::BEGIN;

        this->inner = inner;

        this->code = gen_hash(this->state, this->shift);
    };
    // Constructor of instance for stateflow
    stateflow::stateflow(shifts shift) {
        this->state = states::UNKNOWN;
        this->shift = shift;

        this->code = gen_hash(this->state, this->shift);
    };
    // Constructor of instance for stateflow
    stateflow::stateflow(shifts shift, const pair<states, shifts> inner) {
        this->state = states::UNKNOWN;
        this->shift = shift;

        this->inner = inner;

        this->code = gen_hash(this->state, this->shift);
    };
    // Constructor of instance for stateflow
    stateflow::stateflow(const pair<states, shifts>& inner) {
        this->state = inner.first;
        this->shift = inner.second;

        this->code = gen_hash(this->state, this->shift);
    }
    // Constructor of instance for stateflow
    stateflow::stateflow(states state, shifts shift, const pair<states, shifts>& inner) {
        this->state = state;
        this->shift = shift;

        this->inner = inner;

        this->code = gen_hash(this->state, this->shift);
    }
    // Constructor of instance for stateflow
    stateflow::stateflow(states state, shifts shift, const pair<states, shifts>& inner, long long code) {
        this->state = state;
        this->shift = shift;

        this->inner = inner;

        this->code = code;
    }
    // Constructor of instance for stateflow
    stateflow::stateflow(states state, shifts shift) {
        this->state = state;
        this->shift = shift;

        this->code = gen_hash(this->state, this->shift);
    }
    // Method updating params of current instance of flow with given arrangement
    void stateflow::update(states state) {
        this->state = state;

        this->code = gen_hash(this->state, this->shift);
    }
    // Method updating params of current instance of flow with given arrangement
    void stateflow::update(states state, const pair<states, shifts>& inner) {
        this->state = state;
        this->inner = inner;

        this->code = gen_hash(this->state, this->shift);
    }
    // Method updating params of current instance of flow with given arrangement
    void stateflow::update(shifts shift) {
        this->shift = shift;

        this->code = gen_hash(this->state, this->shift);
    }
    // Method updating params of current instance of flow with given arrangement
    void stateflow::update(shifts shift, const pair<states, shifts>& inner) {
        this->shift = shift;
        this->inner = inner;

        this->code = gen_hash(this->state, this->shift);
    }
    // Method updating params of current instance of flow with given arrangement
    void stateflow::update(const pair<states, shifts>& inner) {
        this->inner = inner;

        this->code = gen_hash(this->state, this->shift);
    }
    // Method updating params of current instance of flow with given arrangement
    void stateflow::update(states state, shifts shift, const pair<states, shifts>& inner) {
        this->state = state;
        this->shift = shift;
        this->inner = inner;

        this->code = gen_hash(this->state, this->shift);
    }
    // Method updating params of current instance of flow with given arrangement
    void stateflow::update(states state, shifts shift) {
        this->state = state;
        this->shift = shift;

        this->code = gen_hash(this->state, this->shift);
    }

    void stateflow::flush()
    {
        this->state = states::UNKNOWN;
        this->shift = shifts::BEGIN;

        this->inner = pair<states, shifts>(states::UNKNOWN, shifts::BEGIN);

        this->code = -1;
    }

    // Getter for "STATE" field
    const states stateflow::get_state()
    {
        return this->state;
    }

    // Getter for "SHIFT" field
    const shifts stateflow::get_shift()
    {
        return this->shift;
    }

    // Getter for "STATEFLOW_INNER" field
    const stateflow stateflow::get_inner()
    {
        return stateflow(inner.first, inner.second);
    }

    // Getter for "CODE" field
    const long long& stateflow::get_code()
    {
        return this->code;
    }
    stateflow& stateflow::operator=(stateflow const& flow)
    {
        if (this == &flow)
            return *this;

        this->state = flow.state;
        this->shift = flow.shift;

        return *this;
    }
}