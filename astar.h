/*  Simple and fast A* pathfinding, v1.0
*
*	This algorithm is 4 directions only (no diagonals) and all map cells are considered of equal cost.
*
*	Feel free to use it for your projects !
*
*	Author : Stéphane Damo
*	stephane.damo@gmail.com / https://github.com/stephanedamo / http://stephanedamo.fr
*/

#ifndef ASTAR_H
#define ASTAR_H

// Max analyzed nodes during pathfinding. Increase it for big maps. Will crash if MAX_NODES is reached during calculation.
#define MAX_NODES 1000

typedef struct node node;
struct node{
	int x, y; // Node coordinates
	float f, g, h; // Internal variables used for A* algorithm
	node* previous; // Previous node
};


// Calculate the path between start and goal.
// map : pointer to a 2D int array (you can change int for char or other if your need to). 0 = walkable, 1 = unwalkable. See astar.c line 67 (last condition) to change which values are considered walkable or not.
// Returns the path length (node count from start to goal including themselves), or zero if the goal is unreachable.
int astar(int* map, int map_width, int map_height, int start_x, int start_y, int goal_x, int goal_y);


// Retrieve your path step by step, by reading node->x and node->y, from index = 0 to pathlength-1.
node* astar_getnode(int index);


#endif