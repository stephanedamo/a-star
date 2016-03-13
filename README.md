# a-star
* Simple and fast A* pathfinding algorithm in C for use with 2D grid-maps
* Very easy to use
* 4 directions only (no diagonals), all map cells are considered of equal cost

# Installation
* Add astar.h / astar.c to your project files
* Include astar.h

# Example
```C
// Create a map
int map[10][10]; 

/* Fill it with 0 (walkable cells) and >0 values (unwalkable cells) */

// Create an astar_result struct to hold the calculated paths
astar_result result;

// Find a path from start (x=3, y=2) to goal(x=8, y=9)
if (astar(&map, 10, 10, 3, 2, 8, 9, &result)){ 
  for (int i = 0; i<result.pathsize; i++){
    // Display the path
    printf("%d, %d\n", result.path[i].x, result.path[i].y);
  }
}
```

# API

```C
// map : Pointer to a 2D int map array. Change int to other type in astar.h / astar.c if your map don't use integers...
// map_width, map_height : Map dimensions
// start_x, start_y : Coordinates of the starting point
// goal_x, goal_y : Coordinates of the ending point
// result : Pointer to the result structure. Read result->path[i] (i from 0 to result->pathsize-1) to get your path.
// Function returns 1 if a path was found, 0 otherwise.

int astar(int* map, int map_width, int map_height, int start_x, int start_y, int goal_x, int goal_y, astar_result* result);
```

# Final words

Feel free to use this code for your projects, suggest improvements, or contact me for more info.
