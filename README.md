# Particle Swarm Optimization (PSO) Algorithm

## Introduction

This repository contains a C++ implementation of the Particle Swarm Optimization (PSO) algorithm. PSO is a heuristic optimization algorithm inspired by the social behavior of birds and fish. In this implementation, the algorithm is applied to find the minimum value of a fitness function with two variables.

## Features

- **Particle Initialization:** The algorithm starts with the initialization of particles with random positions and velocities within a specified range.

- **Fitness Function:** A fitness function is defined to evaluate the fitness of each particle based on its position.

- **Velocity and Position Update:** The velocity and position of each particle are updated using the PSO equations, considering inertia, personal best, and global best.

- **Convergence Criteria:** The algorithm continues iterating until both variables of the global best solution approach zero.

## Parameters

- `particalcount`: Number of particles in the swarm.
- `w`: Inertia weight.
- `c1`: Personal best weight.
- `c2`: Global best weight.
- `max_v`: Maximum velocity.
- `min_pos`: Minimum position.
- `max_pos`: Maximum position.

Adjust these parameters in the code according to your optimization problem.

## Results

The algorithm prints the global best solution and the number of iterations it took to converge. The convergence criteria are both variables of the global best approaching zero.
