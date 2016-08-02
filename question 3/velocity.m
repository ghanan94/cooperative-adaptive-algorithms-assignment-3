%
% NAME:        velocity
%
% DESCRIPTION: Calculates next velocity for agent. Neext velocity is
%              calculated as: new_v = ( w * v ) + 
%              ( c_1 * U( 0,1 ) * ( personal_best - current_position ) ) +
%              ( c_2 * U( 0,1 ) * ( neighbourhood_best - current_position ) ). 
%              new_v is guaranteed to be within [ -max_velocity, 
%              max_velocity ]. If it is calculated to be out of these
%              bounds, it will be set to the upper or lower bound. If GCPSO
%              is enabled and an agent is the global best, it's velocity
%              update equation will be calculated as: 
%              new_v = ( w * v ) - current_position + personal_best +
%              ( scaling_factor * U( -1, 1) ).
%
% PARAMETERS:
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
%   scaling_factor (double)
%     - Factor to scale a random number by for velocity equation when using
%       GCPSO.
%   global_best_agent_idx (int)
%     - Index of the agent that has was at the best solution so far.
%   max_velocity (double)
%     - Maximum velocity bound (absolute value).
%   agents
%     - Vector(Matrix) representing agents.
%   population (int)
%     - Number of agents.
%
% RETURNS:
%   velocity [ v_x v_y ]
%     - Velocity represented as [ v_x v_y ].
%
function [ velocity ] = velocity( neighbourhood_radius, w, c_1, c_2, gcpso, scaling_factor, global_best_agent_idx, max_velocity, agents, population )
    r_1_1 = rand( population, 1 );
    r_1_2 = rand( population, 1 );
    r_2_1 = rand( population, 1 );
    r_2_2 = rand( population, 1 );
    
    velocity = zeros( population, 2 );
    
    for i = 1:population
        % Get all agents that are within agent i's radius (including
        % itself).
        neighbourhood_agents = agents( sqrt( ( agents( :, 1 ) - agents( i, 1 ) ) .^ 2 + ( agents( :, 2 ) - agents( i, 2 ) ) .^ 2 ) <= neighbourhood_radius, : );
        
        % Get the best known solution from the neighbourhood.
        % (Get the best, personal best solution from neighbourhood agents)
        [ ~, min_z_index ] = min( neighbourhood_agents( : , 8 ) );
        neighbourhood_best_solution = neighbourhood_agents( min_z_index, 6:7 );
        
        % If gcpso is not enabled, or the current agent is not the global
        % best, apply the normal velocity update equation.
        if gcpso == 0 || i ~= global_best_agent_idx
            velocity( i, 1 ) = min( max_velocity, max( -1 * max_velocity, ( w .* agents( i, 4 ) ) + ... 
                    ( c_1 .* r_1_1( i )  .* ( agents( i, 6 ) - agents( i, 1 ) ) ) + ...
                    ( c_2 .* r_1_2( i )  .* ( neighbourhood_best_solution( 1 ) - agents( i, 1 ) ) ) ...
                   ));          

            velocity( i, 2 ) = min( max_velocity, max( -1 * max_velocity, ( w .* agents( i, 5 ) ) + ... 
                    ( c_1 .* r_2_1( i )  .* ( agents( i, 7 ) - agents( i, 2 ) ) ) + ...
                    ( c_2 .* r_2_2( i )  .* ( neighbourhood_best_solution( 2 ) - agents( i, 2 ) ) ) ...
                   ));
        else
            r_1 = rand * 2 - 1;
            r_2 = rand * 2 - 1;
            
            velocity( i, 1 ) = min( max_velocity, max( -1 * max_velocity, ( w .* agents( i, 4 ) ) - ... 
                    agents( i, 1 ) + agents( i, 6 ) + ( r_1 .* scaling_factor ) ...
                   ));          
        
            velocity( i, 2 ) = min( max_velocity, max( -1 * max_velocity, ( w .* agents( i, 5 ) ) - ... 
                    agents( i, 2 ) + agents( i, 7 ) + ( r_2 .* scaling_factor ) ...
                   ));
        end
    end
end

