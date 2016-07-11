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
    rand_value = rand();

    selected_parents_counter = 0;
    selected_parents = zeros( length(population), 4 );

    for i = 1:length( population )
        if rand_value <= population( i, 4 ) / sum_fitness
            selected_parents( selected_parents_counter + 1, : ) = population( i, : );
        end
    end

    selected_parents = selected_parents( 1:selected_parents_counter, : );
end

