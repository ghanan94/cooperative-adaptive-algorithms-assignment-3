%
% NAME:        performance
%
% DESCRIPTION: Calculates performance of a given PID
%              (Proportional-Integral-Differential)
%              controller for closed-loop plant
%              control systems. The transfer function
%              is G(s) = Kp*(1 + (1/(Ti*s)) + (Td*s)).
%
% PARAMETERS:
%  sol (Array: [Kp Ti Td])
%    - A vector representing a solution. The vector must have 3 values.
%      The first value (sol(0)) is Kp. The second value (sol(1)), is Ti.
%      The third value (sol(2)), is Td.
%
% RETURNS:
%   ISE
%     - Integral from 0 to T of error squared.
%   t_r
%     - Rise time.
%   t_s
%     - Settling time.
%   M_p
%     - Overshoot.
%
function [ ISE, t_r, t_s, M_p ] = performance( sol )
    Kp = sol(0);
    Ti = sol(1);
    Td = sol(2);
    
    G = Kp * tf( [ Ti * Td, Ti, 1 ], [ Ti, 0 ] );

    F = tf( 1, [ 1, 6, 11, 6, 0 ] );
    sys = feedback( series( G, F ), 1 );
    sysinf = stepinfo( sys );
    t = 0:0.01:100;
    y = step( sys, t );

    ISE = sum( ( y - 1 ) .^ 2 ); % Integral squared error
    t_r = sysinf.RiseTime; % Rise time
    t_s = sysinf.SettlingTime; % Settling time
    M_p = sysinf.Overshoot; % Overshoot
