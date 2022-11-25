#ifndef MAIN_H
#define MAIN_H

#define MAT_SIZE 4//nXn matrix size
#define TRUE 1
#define FALSE 0
#define INT_MIN -2147483648 //integer min value
#define INT_MAX 2147483647 //integer max value
/*
Dijkstra algorith that finds shortest path from current point to every point on graph
get: point
*/
void fillDijkstra(int);

int min(int,int);//return min between two integers
int findMin();//find min num that need to calculate in dijkstraRes array. return its place
int plus(int,int);//regular plus function but if one of integers is max value returns max value

/*
using Dijkstra algorithm to create array of shortest paths to every point 
return: if path exist in dijkstraRes array
*/
int isPathExist(int,int);
/*
if isPathExist is true
returns: value from dijkstraRes array
*/
int findShortestPath(int,int);

void fill();//build matrix
void printMat();
void printRes();//print dijkstraRes array

#endif