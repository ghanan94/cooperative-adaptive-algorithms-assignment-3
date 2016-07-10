%
% NAME:        initial_solutions
%
% DESCRIPTION: Generates initial solutions (initial population) randomly.
%
% PARAMETERS:
%  num_initial_population (integer)
%    - Initial number of solutions (size of population).
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
%   initial_solutions
%     - A vector of vectors representing the <num_initial_population>
%       initial solutions.
%
function [ initial_population ] = initial_population(...
    num_initial_population, ...
    min_Kp, ...
    max_Kp, ...
    min_Ti, ...
    max_Ti, ...
    min_Td, ...
    max_Td ...
)
    % Initial empty matrix of solutions
    % rows in population are each solution
    % The last column wil be the fitness score
    initial_population = zeros( num_initial_population, 4 );

    for i = 1:num_initial_population
        Kp = ( max_Kp - min_Kp ) * rand() + min_Kp;
        Ti = ( max_Ti - min_Ti ) * rand() + min_Ti;
        Td = ( max_Td - min_Td ) * rand() + min_Td;
 
        solution = [ Kp Ti Td 0 ];
        solution( 4 ) = fitness( solution );

        initial_population( i, : ) = solution;
    end
end

