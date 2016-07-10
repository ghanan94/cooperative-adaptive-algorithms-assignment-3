%
% NAME:        solution
%
% DESCRIPTION: Calculates the best set of parameters (Kp, Ti, Td) for a  
%              closed-loop PID (Proportional-Integral-Differential) control 
%              system. The control system's transfer function G(s) is
%              G(s) = Kp*(1 + (1/(Ti*s)) + (Td*s)). The parmaeters will be
%              obtained through a genetic algorithm with fitness
%              proportionate selection of parents and an elitism survival
%              strategy.
%
% PARAMETERS:
%  num_initial_population (integer)
%    - Initial number of solutions (size of population).
%  generations (integer)
%    - Number of generations to observe.
%  crossover_probability (decimal)
%    - Probability of solution parameters crossing over.
%  mutation_probability (decimal)
%    - Probability of solution parameters mutating.
%  min_Kp (decimal)
%    - Min value for Kp, not-inclusive.
%  max Kp (decimal)
%    - Max value for Kp, not-inclusive.
%  min_Ti (decimal)
%    - Min value for Ti, not-inclusive.
%  max Ti (decimal)
%    - Max value for Ti, not-inclusive.
%  min_Td (decimal)
%    - Min value for Td, not-inclusive.
%  max Td (decimal)
%    - Max value for Td, not-inclusive.
%
% RETURNS:
%   sol
%     - Best solution so far.
%
function [ solution ] = solution(...
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
    population = initial_population( num_initial_population, min_Kp, max_Kp, min_Ti, max_Ti, min_Td, max_Td );

    % TODO: Implement GA

    solution = population{1};
end

