%
% NAME:        velocity
%
% DESCRIPTION: Calculates next velocity for agent.
% PARAMETERS:
%   w
%     - Inertia.
%   c_1
%   c_2
%   global_best_solution
%     - Vector in format [ x y ] representing best global solution thus
%       far.
%   agent
%     - Vector(Matrix) representing agent(s).
%   
%
% RETURNS:
%   velocity
%     - Velocity represented as [ v_x v_y ].
%
function [ velocity ] = velocity( w, c_1, c_2, global_best_solution, agent )
    r_1 = 0.5;
    r_2 = 0.5;
    
    velocity = zeros( length( agent ), 2 );
    
    velocity( :, 1 ) = ( w .* agent( :, 3 ) ) + ... 
                       ( c_1 .* r_1  .* ( agent( :, 6 ) - agent( :, 1 ) ) ) + ...
                       ( c_2 .* r_2  .* ( global_best_solution( 1 ) - agent( :, 1 ) ) );

    velocity( :, 2 ) = ( w .* agent( :, 3 ) ) + ... 
                       ( c_1 .* r_1  .* ( agent( :, 7 ) - agent( :, 2 ) ) ) + ...
                       ( c_2 .* r_2  .* ( global_best_solution( 2 ) - agent( :, 2 ) ) );
end

