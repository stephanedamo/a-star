# Overview
* Simple and fast A* pathfinding algorithm written in C
* For use with 2D, grid-based maps
* Very easy to use
* 4 directions only (no diagonals), all map cells are considered of equal cost

# Installation
* Add astar.h / astar.c to your project
* Include astar.h
* Change MAX_NODES value in astar.h according to the size of your map. It's the max number of nodes analyzed during pathfinding, the program may crash if it needs to analyze more nodes than MAX_NODES. Setting this value to (map_width * map_height)/2 should be 100% safe for labyrinth-style maps, although in most cases (maps with a lot of free walking space) you can use smaller values and save memory.
* You're ready !

# Usage example
```C
// Create a map
int map[4][4] =	{
	{ 0, 0, 0, 0 },
	{ 0, 0, 1, 0 },
	{ 1, 1, 1, 0 },
	{ 0, 0, 0, 0 } };

// Create an astar_result struct to hold the calculated path
astar_result result;

// Find a path from start (x=0, y=0) to goal(x=1, y=3). Display it if the path exists
if (astar(&map, 10, 10, 0, 0, 1, 3, &result)){
	for (int i = 0; i<result.pathsize; i++){
		printf("%d, %d\n", result.path[i].x, result.path[i].y);
	}
}
```

# API

```C
// Calculate the path between start and goal.
// map : Pointer to a 2D int map array. Change int to other type in astar.h / astar.c if your map does not use integers.
// map_width, map_height : Map dimensions
// start_x, start_y : Start coordinates
// goal_x, goal_y : Goal coordinates
// result : Pointer to the result structure.
// Function returns 1 if a path was found, 0 otherwise.
int astar(int* map, int map_width, int map_height, int start_x, int start_y, int goal_x, int goal_y, astar_result* result);

// The result structure where the calculated path is stored. Read result->path[i] (i from 0 to result->pathsize-1) to get your path.
typedef struct astar_result{
	node path[MAX_NODES];
	int pathsize;
}astar_result;
```

# Final words

Feel free to use this code for your projects, suggest improvements, or contact me for more info.
