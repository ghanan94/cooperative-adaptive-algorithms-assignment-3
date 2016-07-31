%
% NAME:        solution
%
% DESCRIPTION: Calculates the best set of parameters x, y for the equation 
%              z = ( 4 - ( 2.1 * x ^ 2 ) + ( ( x ^ 4 ) / 3 ) ) ) * 
%              ( x ^ 2 ) + ( x * y ) + ( ( 4 * y ^ 2 ) - 4 ) * ( y ^ 2 ).
%              The best set of parameters is calculated using the Particle
%              Swarm Optimization algorithm (PSO).
%
% PARAMETERS:
%   population (int)
%     - Number of agents.
%   neighbourhood_radius (double)
%     - Agents within the radius of an agent is considered to be part of
%       its neighborhood. A value of Inf means neighbourhood is all agents
%       (global).
%   w (double)
%     - Inertia weight.
%   c_1 (double)
%     - Acceleration coefficient representing how much to trust own best
%       solution so far.
%   c_2 (double)
%     - Acceleration coefficient representing how much to trust other
%       agents' global best solution so far.
%   gcpso (boolean)
%     - Disable guaranteed convergence pso when 0; enable otherwise.
%   s_c (int)
%     - Number of successes before scaling factor update.
%   f_c (int)
%     - Number of failures before scaling factor update.
%   max_velocity (double)
%     - Maximum velocity bound (absolute value).
%   max_iterations (int)
%     - Max iterations.
%   min_x (double)
%     - Min value for x.
%   max_y (double)
%     - Max value for x.
%   min_y (double)
%     - Min value for y.
%   max_y (double)
%     - Max value for y.
%
% RETURNS:
%   solution [ x y ]
%     - Best x and y values in the format [ x y ].
%
function [ solution ] = solution( population, neighbourhood_radius, w, c_1, c_2, gcpso, s_c, f_c, max_velocity, max_iterations, min_x, max_x, min_y, max_y )
    % For the agents matrix: Each agent is represented by a row. Column1
    % will be the agent's current x value. Column2 will be the agent's
    % current y value. Column3 will be the agent's current valuation for z.
    % Column4 will be the agent's current velocity in the x direction.
    % Column5 will be the agent's current velocity in the y direction.
    % Column6 and Column7 will be the agent's best position so far where 
    % Column6 is best position's x and Column7 is best position's y. 
    % Column8 is the best position's z value.
    
    hold off;
    
    agents = initial_solution( population, min_x, max_x, min_y, max_y );
    scaling_factor = 1;
    success_count = 0;
    failure_count = 0;
    
    % Get global best position.
    [ prev_global_best_agent_current_z, global_best_agent_idx ] = min( agents( :, 8 ) );
    
    scatter( agents( :, 1 ), agents( :, 2 ) );
    hold on;
    
    for iteration = 1:max_iterations
        % Pause so we can see the scatter plot updating and the changes.
        pause(0.1);
        
        % Calculate agent's next velocity.
        agents( :, 4:5 ) = velocity( neighbourhood_radius, w, c_1, c_2, gcpso, scaling_factor, global_best_agent_idx, max_velocity, agents, population );
        
        % Calculate agent's next position and z values.
        agents( :, 1:3 ) = next_position( agents, population, min_x, max_x, min_y, max_y );
        
        % Update personal bests if neccessary.
        agents( agents( :, 3 ) < agents( :, 8 ), 6:8 ) = agents( agents( :, 3 ) < agents( :, 8 ), 1:3 );
        
        % Get global best position.
        [ ~, temp_best_agent_idx ] = min( agents( :, 8 ) );
        
        if global_best_agent_idx ~= temp_best_agent_idx
            success_count = 0;
            failure_count = 0;
            scaling_factor = 1;
        else            
            global_best_new_current_z = agents( temp_best_agent_idx, 3 );
            
            if prev_global_best_agent_current_z < global_best_new_current_z
                % New step gets worse for current global best solution
                failure_count = failure_count + 1;
                success_count = 0;

                if failure_count > f_c
                    scaling_factor = 0.5 * scaling_factor;
                end
            else
                if prev_global_best_agent_current_z > global_best_new_current_z
                    % New step gets better for current global best solution
                    success_count = success_count + 1;
                    failure_count = 0;

                    if success_count > s_c
                        scaling_factor = 2 * scaling_factor;
                    end
                end
            end
        end
         
        global_best_agent_idx = temp_best_agent_idx;
        prev_global_best_agent_current_z = agents( global_best_agent_idx, 3 );
        
        % Update scatter plot.
        scatter( agents( :, 1 ), agents( :, 2 ) );
    end
    
    solution = agents( global_best_agent_idx, 6:7 );
    
    % Mark solution with an x.
    scatter( solution( 1 ), solution( 2 ), 'x' );
end
