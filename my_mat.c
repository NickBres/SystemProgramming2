#include "my_mat.h"
#include <stdio.h>

int graph[MAT_SIZE][MAT_SIZE] = {};
int dijkstraRes[2][MAT_SIZE] = {0}; // first row shortest path weight, second for boolean value (1 - need to calculate,0 - already calculated)

void fillDijkstra(int start)
{
    int curr;
    int s[MAT_SIZE];

    for (int i = 0; i < MAT_SIZE; i++)
    { // filling dijkstraRes for the first time
        if (i == start)
        { // path weight from  point to itself is 0
            dijkstraRes[0][i] = 0;
            dijkstraRes[1][i] = FALSE;
        }
        else if (graph[start][i] > 0)
        { // neighbor,weight from matrix
            dijkstraRes[0][i] = graph[start][i];
            dijkstraRes[1][i] = TRUE;
        }
        else
        { // not neighbor, no path by default, weight is max value
            dijkstraRes[0][i] = INT_MAX;
            dijkstraRes[1][i] = TRUE;
        }
    }

    for (int i = 0; i < MAT_SIZE - 1; i++)
    {                                 // runs on graph using BFS
        curr = findMin();             // looking for a point to calculate from
        dijkstraRes[1][curr] = FALSE; // this point already closest point so dont need to check it again

        for (int v = 0; v < MAT_SIZE; v++)
        { // calculate path weight to points from current point
            if (dijkstraRes[1][v])
            {                                                                                    // check if need to calculate
                int onGraph = graph[curr][v] > 0 ? graph[curr][v] : INT_MAX;                     // if not neighbor puts max value
                dijkstraRes[0][v] = min(dijkstraRes[0][v], plus(dijkstraRes[0][curr], onGraph)); // calculates path weight
            }
        }
    }
};

int plus(int a, int b)
{
    if (a == INT_MAX || b == INT_MAX)
        return INT_MAX;
    return a + b;
}

int min(int a, int b)
{
    if (a > b)
        return b;
    else
        return a;
};

int findMin()
{
    int min;
    int i = 0;

    while (i < MAT_SIZE && !dijkstraRes[1][i])
        i++; // looking for first value

    min = i;

    for (; i < MAT_SIZE; i++)
    { // loking for smaller value
        if (dijkstraRes[1][i] && dijkstraRes[0][i] < dijkstraRes[0][min])
        {
            min = i;
        }
    }

    return min;
};

int isPathExist(int i, int j)
{
    fillDijkstra(i);
    return dijkstraRes[0][j] < INT_MAX && dijkstraRes[0][j] > 0;
};

int findShortestPath(int i, int j)
{
    if (isPathExist(i, j))
        return dijkstraRes[0][j];
    return -1;
}

void printMat()
{
    int i, j;

    for (i = 0; i < MAT_SIZE; i++)
    {
        for (j = 0; j < MAT_SIZE; j++)
        {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }

    return;
};

void printRes()
{
    for (int i = 0; i < MAT_SIZE; i++)
    {
        printf("%d ", dijkstraRes[0][i]);
    }
    printf("\n");
    for (int i = 0; i < MAT_SIZE; i++)
    {
        printf("%d ", dijkstraRes[1][i]);
    }
    printf("\n");
}

void fill()
{
    int i, j;
    for (i = 0; i < MAT_SIZE; i++)
    {
        for (j = 0; j < MAT_SIZE; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }
    return;
};
