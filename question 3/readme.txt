To get the solution, run 'run_pso' in matlab while this folder is set as the
the current folder.


3)
avg_z is the average z after 5 runs.

Inertia Weight version vs No Inertia Weight (Global best)
c_1 = c_2 = 2;
+--------+--------+
|   w    |    z   |
+--------+--------+
|   0    | 892.1  |
+--------+--------+
|   0.9  | 148.1  |
+--------+--------+

Vmax version vs no Vmax (Global best)
w = 0.9; c_1 = c_2 = 2;
+--------+--------+
| v_max  |    z   |
+--------+--------+
|  Inf   | 148.1  |
+--------+--------+
|   1    | 1.775  |
+--------+--------+

Constriction Factor version vs. no Constriction factor (Global Best)
v_max = 1;
+--------+--------+--------+--------+
|   w    |  c_1   |   c_2  |    z   |
+--------+--------+--------+--------+
|  0.9   |   2    |   2    | 1.775  |
+--------+--------+--------+--------+
|  0.792 | 1.4944 | 1.4944 | -0.706 |
+--------+--------+--------+--------+

Global Best vs Neighbourhood Best (Neighbourhood is all agents within 2 units of
an agent where an agent's current ( x, y ) is a plot on a 2-D cartesian plane;
neighbours are all agents within a circle of radius 2 with the origin being
where the agent is currently located).
w = 0.792; c_1 = c_2 = 1.4944; v_max = 1;
+-------------------------+--------+
| global or neighbourhood |    z   |
+-------------------------+--------+
|         global          | -0.706 |
+-------------------------+--------+
|      neighbourhood      | -0.869 |
+-------------------------+--------+


// Change to Guaranteed Convergence PSO (GCPSO)

Change Random number seed ten times.
+--------+---------------------+
|  trial |          z          |
+--------+---------------------+
|   1    | -1.031628441907443  |
+--------+---------------------+
|   2    | -1.031628444400555  |
+--------+---------------------+
|   3    | -1.031628063027431  |
+--------+---------------------+
|   4    | -1.031628453487918  |
+--------+---------------------+
|   5    | -1.031628452512049  |
+--------+---------------------+
|   6    | -1.031628452856680  |
+--------+---------------------+
|   7    | -1.031628443547237  |
+--------+---------------------+
|   8    | -1.031628453319429  |
+--------+---------------------+
|   9    | -1.031628453042610  |
+--------+---------------------+
|   10   | -1.031628450116396  |
+--------+---------------------+
