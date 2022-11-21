//
// Created by Austin Lake on 11/17/22.
//

#include "object_state.hpp"

object_state::object_state() : mass(1.0) {}

object_state::object_state(float mass, std::array<float, 3> position, std::array<float, 3> velocity, std::array<float, 3> acceleration)
             : mass(mass), position(position), velocity(velocity), acceleration(acceleration) {}

void object_state::update_state(float time_step) {
    for (int i = 0; i < 3; ++i) {
        position[i] += velocity[i] * time_step + acceleration[i] * std::pow(time_step, 2) / 2;
        velocity[i] += acceleration[i] * time_step;
    }
}

void object_state::apply_force(std::span<float> force) {
    for (int i = 0; i < force.size(); ++i) {
        acceleration[i] = force[i]/mass;
    }
}
