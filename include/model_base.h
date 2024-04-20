// #pragma once

#ifndef MODEL_BASE_H
#define MODEL_BASE_H

#include <casadi/casadi.hpp>
#include <iostream>
#include <vector>

using namespace std;
using namespace casadi;

class ModelBase
{
protected:

  Function ode_;

  int n_states_, n_controls_, n_outputs_;
  double dt_;

public:

    ModelBase();
    ~ModelBase();
  
    SX eval(const SX &state, const SX &control, double dt);
    DM eval(const DM &state, const DM &control, double dt);

    int get_n_states();
    int get_n_controls();
    int get_n_outputs();

    double get_sample_time();

};


#endif // MODEL_BASE_H