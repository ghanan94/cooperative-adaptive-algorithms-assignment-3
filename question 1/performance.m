%
% NAME: performance
%
% DESCRIPTION: Calculates performance of a given PID
%              (Proportional-Integral-Differential)
%              controller for closed-loop plant
%              control systems. The transfer function
%              is G(s) = Kp*(1 + (1/(Ti*s)) + (Td*s)).
%
% PARAMETERS:
%  Kp
%    - PID Parameter.
%  Ti
%    - PID Parameter.
%  Td
%    - PID Parameter.
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
function [ISE,t_r,t_s,M_p] = performance(Kp, Ti, Td)
    G = Kp * tf([Ti*Td,Ti,1], [Ti,0]);

    F = tf(1, [1, 6, 11, 6, 0]);
    sys = feedback(series(G, F), 1);
    sysinf = stepinfo(sys);
    t = 0:0.01:100;
    y = step(sys, t);

    ISE = sum((y-1) .^ 2); % Integral squared error
    t_r = sysinf.RiseTime; % Rise time
    t_s = sysinf.SettlingTime; % Settling time
    M_p = sysinf.Overshoot; % Overshoot
