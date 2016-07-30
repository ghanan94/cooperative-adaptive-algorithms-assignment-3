%
% NAME:        velocity
%
% DESCRIPTION: Calculates next velocity for agent. Neext velocity is
%              calculated as: new_v = ( w * v ) + 
%              ( c_1 * r_1 * ( personal_best - current_position ) ) +
%              ( c_2 * r_2 * ( neighbourhood_best - current_position ) ). 
%              new_v is guaranteed to be within [ -max_velocity, 
%              max_velocity ]. If it is calculated to be out of these
%              bounds, it will be set to the upper or lower bound.  
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
function [ velocity ] = velocity( neighbourhood_radius, w, c_1, c_2, max_velocity, agents, population )
    r_1 = 0.5;
    r_2 = 0.5;
    
    velocity = zeros( population, 2 );
    neighbourhood_best_solution = zeros( population, 2 );
    
    for i = 1:population
        % Get all agents that are within agent i's radius (including
        % itself).
        neighbourhood_agents = agents( sqrt( ( agents( :, 1 ) - agents( i, 1 ) ) .^ 2 + ( agents( :, 2 ) - agents( i, 2 ) ) .^ 2 ) <= neighbourhood_radius, : );
        
        % Get the best known solution from the neighbourhood.
        % (Get the best, personal best solution from neighbourhood agents)
        [ ~, min_z_index ] = min( neighbourhood_agents( : , 8 ) );
        neighbourhood_best_solution( i, : ) = neighbourhood_agents( min_z_index, 1:2 );
    end
    
    velocity( :, 1 ) = min( max_velocity, max( -1 * max_velocity, ( w .* agents( :, 4 ) ) + ... 
                        ( c_1 .* r_1  .* ( agents( :, 6 ) - agents( :, 1 ) ) ) + ...
                        ( c_2 .* r_2  .* ( neighbourhood_best_solution( :, 1 ) - agents( :, 1 ) ) ) ...
                       ));          

    velocity( :, 2 ) = min( max_velocity, max( -1 * max_velocity, ( w .* agents( :, 5 ) ) + ... 
                        ( c_1 .* r_1  .* ( agents( :, 7 ) - agents( :, 2 ) ) ) + ...
                        ( c_2 .* r_2  .* ( neighbourhood_best_solution( :, 2 ) - agents( :, 2 ) ) ) ...
                       ));
end

