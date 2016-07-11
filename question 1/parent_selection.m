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
    sum_fitness = sum( population( :, 4 ) );
    [ ~, sorted_indexes ] = sort( population( :, 4 ), 'descend' );
    fitness_sorted_population = population( sorted_indexes, : );

    selected_parents = zeros( length(population), 4 );

    for i = 1:length( population )
        rand_sum = rand() * sum_fitness;
        idx = length(population);

        for j = 1:length( population )
            rand_sum = rand_sum - fitness_sorted_population( j, 4 );

            if rand_sum <= 0
                idx = j;
            end
        end

        selected_parents( i, : ) = fitness_sorted_population( idx, : );
    end
end

