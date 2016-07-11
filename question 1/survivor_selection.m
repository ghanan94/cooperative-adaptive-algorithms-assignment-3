%
% NAME:        survivor_selection
%
% DESCRIPTION: Returns subset of the current population that will survive
%              (The best X solutions).
%
% PARAMETERS:
%  population (Matrix: (Array of (Array: [Kp Ti Td])))
%    - A matrix that represents the current population. Each row in the
%      matrix represents a solution. Col1 represents Kp, Col2 represents
%      Ti, Col3 represents Td, and Col4 is the fitness of the solution
%      (row).
%
% RETURNS:
%   new_population (Matrix: (Array of (Array: [Kp Ti Td])))
%     - A matrix that represents the new population. Each row in the
%      matrix represents a solution. Col1 represents Kp, Col2 represents
%      Ti, Col3 represents Td, and Col4 is the fitness of the solution
%      (row).
%
function [ new_population ] = survivor_selection( population )
    % Sort population by fitness in descending order
    [ ~, sorted_indexes ] = sort( population( :, 4 ), 'descend' );
    fitness_sorted_population = population( sorted_indexes, : );

    % Accept the best 50
    new_population = fitness_sorted_population( 1:50, : );
end

