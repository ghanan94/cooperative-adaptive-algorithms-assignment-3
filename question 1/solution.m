%
% NAME:        solution
%
% DESCRIPTION: Calculates the best set of parameters (Kp, Ti, Td) for a  
%              closed-loop PID (Proportional-Integral-Differential) control 
%              system. The control system's transfer function G(s) is
%              G(s) = Kp*(1 + (1/(Ti*s)) + (Td*s)). The parmaeters will be
%              obtained through a genetic algorithm.
%
% PARAMETERS:
%  initial_population (integer)
%    - Initial number of solutions (size of population).
%  generations (integer)
%    - Number of generations to observe.
%  crossover_probability (decimal)
%    - Probability of solution parameters crossing over.
%  mutation_probability (decimal)
%    - Probability of solution parameters mutating.
%
% RETURNS:
%   sol
%     - Best solution so far.
%
function [ sol ] = solution( initial_population, generations, crossover_probability, mutation_probability )

end

