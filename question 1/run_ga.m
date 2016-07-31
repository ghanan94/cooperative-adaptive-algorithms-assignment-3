%  Initial number of solutions (size of population).
num_initial_population = 50;

%  Number of generations to observe.
generations = 150;

%  Probability of solution parameters crossing over.
crossover_probability = 0.6;

%  Probability of solution parameters mutating.
mutation_probability = 0.25;

%  Min value for Kp, not-inclusive.
min_Kp = 2;

%  Max value for Kp, not-inclusive.
max_Kp = 18;

%  Min value for Ti, not-inclusive.
min_Ti = 1.05;

%  Max value for Ti, not-inclusive.
max_Ti = 9.42;

%  Min value for Td, not-inclusive.
min_Td = 0.26;

%  Max value for Td, not-inclusive.
max_Td = 2.37;

% Run the GA to get best set of params
% sol will be a vector of 3 elements where the first will be Kp, second is
% Ti, and last is Td.
sol = solution( ...
    num_initial_population, ...
    generations, ...
    crossover_probability, ...
    mutation_probability, ...
    min_Kp, ...
    max_Kp, ...
    min_Ti, ...
    max_Ti, ...
    min_Td, ...
    max_Td ...
)

fitness( sol )