# a-star
* Simple and fast A* pathfinding algorithm in C for use with 2D grid-maps
* Very easy to use
* 4 directions only (no diagonals), all map cells are considered of equal cost

# Example
`int map[10][10]; // Create a map`

`/* Fill it with 0 (walkable cells) and >0 values (unwalkable cells) */`

`astar_result result; // Create an astar_result struct to hold the calculated paths`


`astar(&map, 10, 10, 3, 2, 8, 9, &result); // Find a path from start(3,2) to goal(8,9)`

`for (int i = 0; i<result.pathsize; i++){`

` printf("%d, %d\n", result.path[i].x, result.path[i].y); // Display the path`

`}`


# Usage
* Add astar.h / astar.c to your project files
* Include astar.h
* Create an astar_result struct which will hold the results of the calculated path
* Call astar()
* Read astar_result

# API

`int astar(int* map, int map_width, int map_height, int start_x, int start_y, int goal_x, int goal_y, astar_result* result);`

map : pointer to your map array
map_width, map_height : map size
start_x, int start_y : coordinates of the starting point
goal_x, int goal_y : coordinates of the ending point
result : pointer to the result structure

