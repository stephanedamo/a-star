#include "astar.h"
#include <string.h>
#include <math.h>

node path[MAX_NODES], closedset[MAX_NODES], openset[MAX_NODES];
int pathsize, closedset_size, openset_size;

node* find_openset_lowest_f_score(){
	float min = openset[0].f;
	int lowest = 0;
	for (int i = 1; i < openset_size; i++){
		if (openset[i].f < min){
			min = openset[i].f;
			lowest = i;
		}
	}
	return &openset[lowest];
}

int is_in_closedset(node* n){
	for (int i = 0; i < closedset_size; i++)
	if (closedset[i].x == n->x && closedset[i].y == n->y)
		return 1;
	return 0;
}

int is_in_openset(node* n){
	for (int i = 0; i < openset_size; i++)
	if (openset[i].x == n->x && openset[i].y == n->y)
		return 1;
	return 0;
}

node* switch_to_closedset(node* n){
	closedset[closedset_size++] = *n;
	for (int i = 0; i < openset_size; i++){
		if (openset[i].x == n->x && openset[i].y == n->y){
			memmove(&openset[i], &openset[i + 1], sizeof(node)* (openset_size - i - 1));
			openset_size--;
			break;
		}
	}
	return &closedset[closedset_size - 1];
}

int astar(int* map, int map_width, int map_height, int start_x, int start_y, int goal_x, int goal_y){
	pathsize = closedset_size = openset_size = 0;
	openset[openset_size++] = (node){ start_x, start_y, abs(start_x - goal_x) + abs(start_y - goal_y), 0, 0 };
	while (openset_size > 0){
		node* current = find_openset_lowest_f_score();
		if (current->x == goal_x && current->y == goal_y){
			path[pathsize++] = *current;
			while (current->x != start_x || current->y != start_y){
				path[pathsize++] = *current = *current->previous;
			}
			return pathsize;
		}
		current = switch_to_closedset(current);
		for (int i = 0; i < 4; i++){
			struct node neighbor = { current->x, current->y, 0, 0, 0 };
			switch (i){
			case 0: neighbor.y--; break;
			case 1: neighbor.x++; break;
			case 2: neighbor.y++; break;
			case 3: neighbor.x--; break;
			}
			if (is_in_closedset(&neighbor) || neighbor.x < 0 || neighbor.y < 0 || neighbor.x >= map_width || neighbor.y >= map_height || map[neighbor.x * map_height + neighbor.y] == 1)
				continue;
			if (!is_in_openset(&neighbor) || current->g + 1 < neighbor.g){
				neighbor.previous = current;
				neighbor.g = current->g + 1;
				neighbor.f = neighbor.g + abs(neighbor.x - goal_x) + abs(neighbor.y - goal_y);
				if (!is_in_openset(&neighbor))
					openset[openset_size++] = neighbor;
			}
		}
	}
	return 0;
}

node* astar_getnode(int index){
	return &path[pathsize - 1 - index];
}