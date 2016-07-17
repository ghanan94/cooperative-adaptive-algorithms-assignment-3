%
% NAME:        solution
%
% DESCRIPTION: Calculates the best set of parameters x, y for the equation 
%              z = ( 4 - ( 2.1 * x ^ 2 ) + ( ( x ^ 4 ) / 3 ) ) ) * 
%              ( x ^ 2 ) + ( x * y ) + ( ( 4 * y ^ 2 ) - 4 ) * ( y ^ 2 ).
% PARAMETERS:
%   population (int)
%     - Number of agents.
%
% RETURNS:
%   solution
%     - Best x and y values in the format [ x y ].
%   min_x
%     - Min value for x.
%   max_y
%     - Max value for x.
%   min_y
%     - Min value for y.
%   max_y
%     - Max value for y.
%
function [ solution ] = solution( population, min_x, max_x, min_y, max_y )
    % For the agents matrix: Each agent is represented by a row. Column1
    % will be the agent's current x value. Column2 will be the agent's
    % current y value. Column3 will be the agent's current velocity.
    % Column4 will be the agent's valuation for z.
    
    agents = initial_solution( population, min_x, max_x, min_y, max_y );

    [ ~, min_z_index ] = min( agents( :, 4 ) );
    
    solution = agents( min_z_index, 1:2 );
end

