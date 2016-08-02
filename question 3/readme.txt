To get the solution, run 'run_pso' in matlab while this folder is set as the
the current folder.


3)
population size = 10;
stopping criteria is 10 iterations.

Inertia Weight version vs No Inertia Weight (Global best)
c_1 = c_2 = 2;
+--------+--------+
|   w    |    z   |
+--------+--------+
|   0    | -0.868 |
+--------+--------+
|   0.9  | -0.972 |
+--------+--------+

Vmax version vs no Vmax (Global best)
w = 0.9; c_1 = c_2 = 2;
+--------+--------+
| v_max  |    z   |
+--------+--------+
|  Inf   | -0.972 |
+--------+--------+
|   1    | -1.023 |
+--------+--------+

Constriction Factor version vs. no Constriction factor (Global Best)
v_max = 1;
+--------+--------+--------+--------+
|   w    |  c_1   |   c_2  |    z   |
+--------+--------+--------+--------+
|  0.9   |   2    |   2    | -1.023 |
+--------+--------+--------+--------+
|  0.792 | 1.4944 | 1.4944 | -1.032 |
+--------+--------+--------+--------+

Global Best vs Neighbourhood Best (Neighbourhood is all agents within 2 units of
an agent where an agent's current ( x, y ) is a plot on a 2-D cartesian plane;
neighbours are all agents within a circle of radius 2 with the origin being
where the agent is currently located).
w = 0.792; c_1 = c_2 = 1.4944; v_max = 1;
+-------------------------+-----------+
| global or neighbourhood |      z    |
+-------------------------+-----------+
|         global          | -1.031607 |
+-------------------------+-----------+
|      neighbourhood      | -1.031018 |
+-------------------------+-----------+

Guaranteed Convergence PSO (GCPSO) w/ Global best
w = 0.792; c_1 = c_2 = 1.4944; v_max = 1;
+-------+-----------+
| GCPSO |      z    |
+-------+-----------+
| false | -1.031607 |
+-------+-----------+
| true  | -1.030981 |
+-------+-----------+

Change Random number seed ten times.
+--------+---------------------+
|  trial |          z          |
+--------+---------------------+
|   1    | -1.030529492244050  |
+--------+---------------------+
|   2    | -1.031558562968682  |
+--------+---------------------+
|   3    | -1.026541478313150  |
+--------+---------------------+
|   4    | -1.030590023798790  |
+--------+---------------------+
|   5    | -1.031304477027970  |
+--------+---------------------+
|   6    | -1.031021650827862  |
+--------+---------------------+
|   7    | -1.031511419168012  |
+--------+---------------------+
|   8    | -1.031092681782181  |
+--------+---------------------+
|   9    | -1.031299651074509  |
+--------+---------------------+
|   10   | -1.030972375236296  |
+--------+---------------------+
