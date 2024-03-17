#include<stdio.h>

void bfs(int adjMatrix[][n], int n, int start){
    int queue[n], visited[n];
    int front = -1, rear = -1, i, j;

    //Initializing the visited array elements to 0 initially, which will be used to check whether a node is visited
    for(i=0; i<n; i++){
        visited[i]=0;
    }

    //taking the starting vertex
    queue[++rear] = start;
    ++front;
    visited[start] = 1;

    //loop for bfs traversal
    while(rear>=front){
        start = queue[front++];
        printf("%d->", start);

        for(j=0;j<n;j++){
            if(adjMatrix[start][j] && visited[j]==0){
                queue[++rear] = j;
                visited[j] = 1;
            }
        }
    }
}

void dfs(int adjMatrix[][n], int n,int start){
    int stack[n], top = -1,i,j;
    int visited[n];

    //Initializing the visited array elements to 0 initially, which will be used to check whether a node is visited
    for(i=0;i<n;i++){
        visited[i] = 0;
    }

    //taking the starting vertex
    stack[++top] = start;
    visited[start] = 1;

    //loop for dfs traversal
    while(top!=-1){
        start = stack[top--];
        printf("%d->", start);

        for(j=0; j<n; j++){
            if(adjMatrix[start][j] && visited[j]==0){
                stack[++top] = j;
                visited[j] = 1;
                break;
            }
        }
    }
}

//main function
int main(){
    int n;
    printf("Enter the no. of vertices : ");
    scanf("%d", &n);
    int adj[n][n];
    int i, j, option, size;

    do{
        printf("\n*****MAIN MENU******\n");
        printf("1. Enter the values in graph\n");
        printf("2. BFS Traversal\n");
        printf("3. DFS Traversal\n");
        printf("4. Exit\n");
        printf("Enter your option : ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            printf("Enter the adjacency matrix - \n");
            for(i=0;i<n;i++){
                for (j = 0; j<n; j++)
                {
                    scanf("%d",&adj[i][j]);
                }
            }
            break;
        case 2:
            printf("BFS Traversal - \n");
            bfs(adj, n, 0);
            break;
        case 3:
            printf("DFS Traversal - \n");
            dfs(adj, n, 0);
            break;
        case 4:
            printf("\nExited Session.\n");
            break;
        
        default:
            printf("Invalid Input!\n");
            break;
        }

    }while(option!=4);

    return 0;
}