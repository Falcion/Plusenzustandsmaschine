#include "stateflow.h"

#include <memory>

// Constructor of instance for stateflow
stateflow::stateflow() : inner(nullptr) {
    this->state = states::UNKNOWN;
    this->shift = shifts::BEGIN;

    this->code = gen_hash(this->state, this->shift);
};
// Constructor of instance for stateflow
stateflow::stateflow(states& state) : inner(nullptr) {
    this->state = state;
    this->shift = shifts::BEGIN;

    this->code = gen_hash(this->state, this->shift);
};
// Constructor of instance for stateflow
stateflow::stateflow(states& state, unique_ptr<stateflow> inner) {
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
stateflow::stateflow(shifts& shift, unique_ptr<stateflow> inner) {
    this->state = states::UNKNOWN;
    this->shift = shift;
    this->inner = make_unique<stateflow>(inner);

    this->code = gen_hash(this->state, this->shift);
};
// Constructor of instance for stateflow
stateflow::stateflow(unique_ptr<stateflow> inner) {
    this->state = states::UNKNOWN;
    this->shift = shifts::BEGIN;
    this->inner = make_unique<stateflow>(inner);

    this->code = gen_hash(this->state, this->shift);
}
// Constructor of instance for stateflow
stateflow::stateflow(states& state, shifts& shift, unique_ptr<stateflow> inner) {
    this->state = state;
    this->shift = shift;
    this->inner = make_unique<stateflow>(inner);

    this->code = gen_hash(this->state, this->shift);
}
// Constructor of instance for stateflow
stateflow::stateflow(states& state, shifts& shift, unique_ptr<stateflow> inner, long long& code) {
    this->state = state;
    this->shift = shift;
    this->inner = make_unique<stateflow>(inner);;
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
void stateflow::update(states& state, unique_ptr<stateflow> inner) {
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
void stateflow::update(shifts& shift, unique_ptr<stateflow> inner) {
    this->shift = shift;
    this->inner = make_unique<stateflow>(inner);

    this->code = gen_hash(this->state, this->shift);
}
// Method updating params of current instance of flow with given arrangement
void stateflow::update(unique_ptr<stateflow> inner) {
    this->inner = make_unique<stateflow>(inner);

    this->code = gen_hash(this->state, this->shift);
}
// Method updating params of current instance of flow with given arrangement
void stateflow::update(states& state, shifts& shift, unique_ptr<stateflow> inner) {
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