%
% NAME:        evaluate_equation
%
% DESCRIPTION: Calculates z for the equation z = ( 4 - ( 2.1 * x ^ 2 ) +
%              ( ( x ^ 4 ) / 3 ) ) ) * ( x ^ 2 ) + ( x * y ) + 
%              ( ( 4 * y ^ 2 ) - 4 ) * ( y ^ 2 ).
% PARAMETERS:
%   x
%     - x value(s).
%   y
%     - y value(s).
%
% RETURNS:
%   z
%     - z value(s).
%
function [ z ] = evaluate_equation( x, y )
    z = ( 4 - ( 2.1 .* ( x .^ 2 ) ) + ( ( x .^ 4 ) ./ 3 ) ) .* ( x .^ 2 ) + ...
        ( x .* y ) + ...
        ( ( 4 .* ( y .^ 2 ) ) - 4 ) .* ( y .^ 2 );
end

