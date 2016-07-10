%
% NAME:        fitness
%
% DESCRIPTION: Calculates the fitness of a given solution.
%
% PARAMETERS:
%  solution (Array: [Kp Ti Td])
%    - A vector representing a solution. The vector must have 3 values.
%      The first value (sol(0)) is Kp. The second value (sol(1)), is Ti.
%      The third value (sol(2)), is Td.
%
% RETURNS:
%   fitness (number)
%     - A value representing the fitness of a solution. A higher value
%       means a better solution.
%
function [ fitness ] = fitness( solution )
    [ ISE, t_r, t_s, M_p ] = performance( solution );

    % TODO: Implement a better fitness algorithm.
    % Current one is just to get the ball rolling with the rest of the
    % GA algorithm.
    fitness = t_r + t_s + M_p - ISE;
end

