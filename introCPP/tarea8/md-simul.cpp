#include "md-simul.h"

void initial_conditions(Particle &body) {
  body.Ry = 1.6598;
  body.Vx = 0.23698;

  body.rad = 0.235;
  body.mass = 0.29698;
}

void compute_force(Particle &body) {
  // reset force
  body.Fx = body.Fy = body.Fz = 0.0;

  // gravitational force
  body.Fy += body.mass * G;

  // floor
  double delta = body.rad - body.Ry;
  if (delta > 0) {
    body.Fy += K * delta;
  }
}
void compute_energy(Particle &body) { // reset energy
  body.Ec = body.Ep = body.E = 0.0;

  // energia cinetica
  body.Ec = 0.5 * (body.mass) * ((body.Vx * body.Vx) + (body.Vy * body.Vy));

  // energia potencial eje y
  double delta = body.rad - body.Ry;
  if (delta > 0) {
    body.Ep = K * delta * delta * 0.5;
  } else {
    body.Ep = -body.mass * G * body.Ry;
  }

  // energia mecanica
  double E = body.Ep + body.Ec;

  // diferencial
  body.E = (E / 4.811445) - 1;
}

void print(Particle &body, double time) {
  std::cout << time << "  " << body.Rx << "  " << body.Ry << "  " << body.Vx
            << "  " << body.Vy << "  " << body.E << "  " << body.Ec << "  "
            << body.Ep << "  "
            << "\n";
}
