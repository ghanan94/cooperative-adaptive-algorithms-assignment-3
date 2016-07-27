% Run the PSO algorithm to find best set of x and y given the below
% parameters.

format long;

% Number of agents.
population = 50;

% Agents within this radius of an agent is considered to be part of its 
% neighborhood.
neighbourhood_radius = 2;

% Inertia weight.
w = 0.792;

% Acceleration coefficient representing how much to trust own best solution 
% so far.
c_1 = 1.4944;

% Acceleration coefficient representing how much to trust other agents' 
% global best solution so far.
c_2 = 1.4944;

% Max velocity (absolute value).
max_velocity = 1;

% Max number of iterations before terminating. (Terminating condition).
max_iterations = 100;

% Min value for x.
min_x = -5;

% Max value for x.
max_x = 5;

% Min value for y.
min_y = -5;

% Max value for y.
max_y = 5;

% Run PSO giving above params
best_solution = solution( population, neighbourhood_radius, w, c_1, c_2, max_velocity, max_iterations, min_x, max_x, min_y, max_y )

% Calculate z value.
best_z = evaluate_equation( best_solution( 1 ), best_solution( 2 ) )

format;
