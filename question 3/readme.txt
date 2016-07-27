To get the solution, run 'run_pso' in matlab while this folder is set as the
the current folder.


3)
avg_z is the average z after 5 runs.

Inertia Weight version vs No Inertia Weight (Global best)
c_1 = c_2 = 2;
+--------+--------+
|   w    | avg_z  |
+--------+--------+
|   0    | 892.1  |
+--------+--------+
|   1    | 148.1  |
+--------+--------+

Vmax version vs no Vmax (Global best)
w = 1; c_1 = c_2 = 2;
+--------+--------+
| v_max  | avg_z  |
+--------+--------+
|  Inf   | 148.1  |
+--------+--------+
|   1    | 1.775  |
+--------+--------+

Constriction Factor version vs. no Constriction factor (Global Best)
v_max = 1;
+--------+--------+--------+--------+
|   w    |  c_1   |   c_2  | avg_z  |
+--------+--------+--------+--------+
|   1    |   2    |   2    | 1.775  |
+--------+--------+--------+--------+
|  0.792 | 1.4944 | 1.4944 | -0.706 |
+--------+--------+--------+--------+
