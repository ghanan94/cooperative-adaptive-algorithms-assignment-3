%
% NAME:        velocity
%
% DESCRIPTION: Calculates next velocity for agent. Neext velocity is
%              calculated as: new_v = ( w * v ) + 
%              ( c_1 * r_1 * ( personal_best - current_position ) ) +
%              ( c_2 * r_2 * ( global_best - current_position ) ). new_v is
%              guaranteed to be within [ -max_velocity, max_velocity ]. If
%              it is calculated to be out of these bounds, it will be set
%              to the upper or lower bound.
%
% PARAMETERS:
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
%   global_best_solution [ x y ]
%     - Vector in format [ x y ] representing best global solution so
%       far.
%   agent
%     - Vector(Matrix) representing agent(s).
%
% RETURNS:
%   velocity [ v_x v_y ]
%     - Velocity represented as [ v_x v_y ].
%
function [ velocity ] = velocity( w, c_1, c_2, max_velocity, global_best_solution, agent )
    r_1 = 0.5;
    r_2 = 0.5;
    
    velocity = zeros( length( agent ), 2 );
    
    velocity( :, 1 ) = min( max_velocity, max( -1 * max_velocity, ( w .* agent( :, 4 ) ) + ... 
                        ( c_1 .* r_1  .* ( agent( :, 6 ) - agent( :, 1 ) ) ) + ...
                        ( c_2 .* r_2  .* ( global_best_solution( 1 ) - agent( :, 1 ) ) ) ...
                       ));          

    velocity( :, 2 ) = min( max_velocity, max( -1 * max_velocity, ( w .* agent( :, 5 ) ) + ... 
                        ( c_1 .* r_1  .* ( agent( :, 7 ) - agent( :, 2 ) ) ) + ...
                        ( c_2 .* r_2  .* ( global_best_solution( 2 ) - agent( :, 2 ) ) ) ...
                       ));
end

