#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int check(int adjMatrix[][MAX], int n, int v)
{
    int result = 1;
    for (int i = 0; i < n; i++)
    {
        if (adjMatrix[i][v] == 1)
        {
            result = 0;
        }
    }
    return result;
}

void deleteEdge(int adjMatrix[][MAX], int n, int v)
{
    for (int i = 0; i < n; i++)
    {
        adjMatrix[v][i] = 0;
    }
}

void topologicalsort(int adjMatrix[][MAX], int n)
{
    int removed[MAX] = {0};
    int popped[MAX];
    int popIndex = 0;

    for (int i = 0; i < n; i++)
    {
        if (removed[i] == 0 && check(adjMatrix, n, i))
        {
            removed[i] = 1;
            popped[popIndex++] = i;
            deleteEdge(adjMatrix, n, i);
            i = -1;
        }
    }

    for (int i = 0; i < popIndex; i++)
    {
        printf("%c ", (97 + popped[i]));
    }
    printf("\n");
}

int main()
{
    int n;
    printf("Enter the number of Vertices: \n");
    scanf("%d", &n);

    int checkEdge;
    int i, j;
    int adjMatrix[MAX][MAX];

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (i == j)
                continue;

            printf("Edge from %c to %c? Enter 0 if No and 1 if Yes\t", (97 + i), (97 + j));
            scanf("%d", &checkEdge);

            if (checkEdge == 1)
                adjMatrix[i][j] = 1;
            else
                adjMatrix[i][j] = 0;
        }
    }
    topologicalsort(adjMatrix, n);
    return 0;
}

/*Enter the number of Vertices:
3
Is there a edge from a to b? Enter 0 if No and 1 if Yes 1
Is there a edge from a to c? Enter 0 if No and 1 if Yes 1
Is there a edge from b to a? Enter 0 if No and 1 if Yes 0
Is there a edge from b to c? Enter 0 if No and 1 if Yes 0
Is there a edge from c to a? Enter 0 if No and 1 if Yes 0
Is there a edge from c to b? Enter 0 if No and 1 if Yes 1
a c b */