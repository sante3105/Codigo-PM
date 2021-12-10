#pragma once
#include <iostream>
#include "particle.h"
#include "integrator.h"

// This could on itws own class: Config
const double G = -9.81;
const int NSTEPS = 20;
const double DT = 1; // TIEMPO TOTAL : TF = NSTEPS*DT -> NSTEPS = int(TF/DT)
const double K = 253.57; // we will model the floor as a spring

// function declarations
void initial_conditions(Particle & body);
void compute_force(Particle & body);
void compute_energy(Particle & body);
void print(Particle & body, double time);
