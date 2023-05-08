#include "../pch.h"

#include "stateflow.h"

#include <memory>

namespace zustandsmaschine {
    // Constructor of instance for stateflow
    stateflow::stateflow() : inner(nullptr) {
        this->state = states::UNKNOWN;
        this->shift = shifts::BEGIN;

        this->code = gen_hash(this->state, this->shift);
    };
    // Destructor for instance
    stateflow::~stateflow() {

    }
    // Constructor of instance for stateflow
    stateflow::stateflow(states& state) : inner(nullptr) {
        this->state = state;
        this->shift = shifts::BEGIN;

        this->code = gen_hash(this->state, this->shift);
    };
    // Constructor of instance for stateflow
    stateflow::stateflow(states& state, const stateflow& inner) {
        this->state = state;
        this->shift = shifts::BEGIN;
        this->inner = make_unique<stateflow>(inner);

        this->code = gen_hash(this->state, this->shift);
    };
    // Constructor of instance for stateflow
    stateflow::stateflow(shifts& shift) : inner(nullptr) {
        this->state = states::UNKNOWN;
        this->shift = shift;

        this->code = gen_hash(this->state, this->shift);
    };
    // Constructor of instance for stateflow
    stateflow::stateflow(shifts& shift, const stateflow& inner) {
        this->state = states::UNKNOWN;
        this->shift = shift;
        this->inner = make_unique<stateflow>(inner);

        this->code = gen_hash(this->state, this->shift);
    };
    // Constructor of instance for stateflow
    stateflow::stateflow(const stateflow& inner) {
        this->state = states::UNKNOWN;
        this->shift = shifts::BEGIN;
        this->inner = make_unique<stateflow>(inner);

        this->code = gen_hash(this->state, this->shift);
    }
    // Constructor of instance for stateflow
    stateflow::stateflow(states& state, shifts& shift, const stateflow& inner) {
        this->state = state;
        this->shift = shift;
        this->inner = make_unique<stateflow>(inner);

        this->code = gen_hash(this->state, this->shift);
    }
    // Constructor of instance for stateflow
    stateflow::stateflow(states& state, shifts& shift, const stateflow& inner, long long& code) {
        this->state = state;
        this->shift = shift;
        this->inner = make_unique<stateflow>(inner);
        this->code = code;
    }
    // Constructor of instance for stateflow
    stateflow::stateflow(states& state, shifts& shift) {
        this->state = state;
        this->shift = shift;

        this->code = gen_hash(this->state, this->shift);
    }
    // Method updating params of current instance of flow with given arrangement
    void stateflow::update(states& state) {
        this->state = state;

        this->code = gen_hash(this->state, this->shift);
    }
    // Method updating params of current instance of flow with given arrangement
    void stateflow::update(states& state, const stateflow& inner) {
        this->state = state;
        this->inner = make_unique<stateflow>(inner);

        this->code = gen_hash(this->state, this->shift);
    }
    // Method updating params of current instance of flow with given arrangement
    void stateflow::update(shifts& shift) {
        this->shift = shift;

        this->code = gen_hash(this->state, this->shift);
    }
    // Method updating params of current instance of flow with given arrangement
    void stateflow::update(shifts& shift, const stateflow& inner) {
        this->shift = shift;
        this->inner = make_unique<stateflow>(inner);

        this->code = gen_hash(this->state, this->shift);
    }
    // Method updating params of current instance of flow with given arrangement
    void stateflow::update(const stateflow& inner) {
        this->inner = make_unique<stateflow>(inner);

        this->code = gen_hash(this->state, this->shift);
    }
    // Method updating params of current instance of flow with given arrangement
    void stateflow::update(states& state, shifts& shift, const stateflow& inner) {
        this->state = state;
        this->shift = shift;
        this->inner = make_unique<stateflow>(inner);

        this->code = gen_hash(this->state, this->shift);
    }
    // Method updating params of current instance of flow with given arrangement
    void stateflow::update(states& state, shifts& shift) {
        this->state = state;
        this->shift = shift;

        this->code = gen_hash(this->state, this->shift);
    }

    void stateflow::flush()
    {
        this->state = states::UNKNOWN;
        this->shift = shifts::BEGIN;

        this->inner = nullptr;

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
    const unique_ptr<stateflow> stateflow::get_inner()
    {
        return move(this->inner);
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