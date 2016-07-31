%
% NAME:        parent_selection
%
% DESCRIPTION: Generates list of parents that will be selected to have
%              children.
%
% PARAMETERS:
%  population (Matrix: (Array of (Array: [Kp Ti Td])))
%    - A matrix that represents the current population. Each row in the
%      matrix represents a solution. Col1 represents Kp, Col2 represents
%      Ti, Col3 represents Td, and Col4 is the fitness of the solution
%      (row).
%
% RETURNS:
%   selected_parents (Matrix: (Array of (Array: [Kp Ti Td])))
%     - A subset of the population that will have children.
%
function [ selected_parents ] = parent_selection( population )
    % Sum of all fitnesses
    sum_fitness = sum( population( :, 4 ) );
       
    % population will already be sorted by the ime parent_selection is
    % called. initial_population and survivor_selection will return a 
    % sorted population.

    % Initialize a matrix representing solutions to have offspring
    selected_parents = zeros( length(population), 4 );

    % Using Fitness-porportionate selection's roulette wheel algorithm,
    % Select n solutions (some may repeat) that will create offspring.
    for i = 1:length( population )
        rand_sum = rand() * sum_fitness;
        idx = length(population);

        for j = 1:length( population )
            rand_sum = rand_sum - population( j, 4 );

            if rand_sum <= 0
                idx = j;
            end
        end

        selected_parents( i, : ) = population( idx, : );
    end
end

