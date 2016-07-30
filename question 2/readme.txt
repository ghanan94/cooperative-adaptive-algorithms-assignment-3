problems files have X rows where each row is a City
col1 is city numb, col2 is x-coordinate, col3 is y-coordinate

a)
As population is increased, the time to find food forages (and transporting)
decreases significantly.
As evaporation rate is increased, more ants seem to be traveling in more random
directions instead of towards any food forage. In other words, as evaporation
rate is increased, performance of the agents decrease significantly.
As diffusion rate is increased, the performance of the ants as a whole increases.

b) alpha = beta = 1.0; population size = 29; online pheromone update = offline pheromone update = true
+-----------------------+--------------+
| pheromone persistence |     cost     |
+-----------------------+--------------+
|         0.25          |   9477.22    |
+-----------------------+--------------+
|          0.5          |   9346.27   |
+-----------------------+--------------+
|         0.75          |   9588.49    |
+-----------------------+--------------+

c) pheromone persistence = 0.5; population size = 29; online pheromone update = offline pheromone update = true
+-------+------+--------------+
| alpha | beta |     cost     |
+-------+------+--------------+
| alpha | beta |   9519.97    |
+-------+------+--------------+
| 1.25  | 0.75 |   9420.19    |
+-------+------+--------------+
|  1.0  | 1.0  |   9346.27    |
+-------+------+--------------+

d) alpha = beta = 1.0; pheromone persistence = 0.5; offline pheromone update = true
+-------------------------+--------------+
| online pheromone update |     cost     |
+-------------------------+--------------+
|           true          |   9346.27    |
+-------------------------+--------------+
|          false          |   9151.15    |
+-------------------------+--------------+
