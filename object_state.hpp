//
// Created by Austin Lake on 11/17/22.
//

#pragma once
#ifndef PHYSICS_SIM_STATE_HPP
#define PHYSICS_SIM_STATE_HPP

#include <array>
#include <span>
#include <cmath>

const float gravity = 9.80665; // gravitation acceleration in m/s


class object_state {
public:
    object_state();
    object_state(float mass, std::array<float, 3> position, std::array<float, 3> velocity, std::array<float, 3> acceleration);
    void update_state(float time_step);
    void apply_force(std::span<float> force);

private:
    const float mass;
    std::array<float, 3> position = {0, 0, 0}; // x-axis, y-axis and angular position respectively (m/s and rad/s)
    std::array<float, 3> velocity = {0, 0, 0}; // x-axis, y-axis and angular velocity respectively (m/s^2 and rad/s^2)
    std::array<float, 3> acceleration = {0, -gravity, 0}; // x-axis, y-axis and angular acceleration respectively (m/s^2 and rad/s^2)
};


#endif //PHYSICS_SIM_STATE_HPP
