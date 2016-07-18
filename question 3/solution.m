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
%   max_iterations
%     - Max iterations.
%
function [ solution ] = solution( population, min_x, max_x, min_y, max_y, max_iterations )
    % For the agents matrix: Each agent is represented by a row. Column1
    % will be the agent's current x value. Column2 will be the agent's
    % current y value. Column3 will be the agent's current velocity in the
    % x direction. Column4 will be the agent's current velocity in the y.
    % Column5 will be the agent's valuation for z. Column6 and Column7 will
    % be the agent's best position so far where Column6 is best position's
    % x and Column7 is best position's y.
    
    w = 0;
    c_1 = 1.4479;
    c_2 = 1.4479;
    
    hold off;
    
    agents = initial_solution( population, min_x, max_x, min_y, max_y );

    scatter( agents( :, 1 ), agents( :, 2 ) );
    hold on;
    
    [ ~, min_z_index ] = min( agents( :, 5 ) );
    
    solution = agents( min_z_index, 1:2 );
    
    for iteration = 1:max_iterations
        % Get global best position.
        [ ~, min_z_index ] = min( agents( :, 5 ) );
        global_best = agents( min_z_index, 1:2 );
        
        % Calculate agent's next velocity.
        agents( :, 3:4 ) = velocity( w, c_1, c_2, global_best, agents );
        
        % Update scatter plot.
        scatter( agents( :, 1 ), agents( :, 2 ) );
    end
end

