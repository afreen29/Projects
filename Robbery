#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdio.h>
#define IN 99

int n;
int dijkstra(int cost[10][10], int source, int target);

int max(int a, int b) { return (a > b) ? a : b; }

int i,j,m,n,c[20][20];
char g[20],h[20],b[20][20];

void print(int i,int j)
{
    if(i==0 || j==0)
        return;
    if(b[i][j]=='c')
    {
        print(i-1,j-1);
        printf("%c",g[i-1]);
    }
    else if(b[i][j]=='u')
        print(i-1,j);
    else
        print(i,j-1);
}

void lcs()
{

    m=strlen(g);
    n=strlen(h);
    
    for(i=0;i<=m;i++)
        c[i][0]=0;
    for(i=0;i<=n;i++)
        c[0][i]=0;
    //c, u and l denotes cross, upward and downward directions respectively
    for(i=1;i<=m;i++)
        for(j=1;j<=n;j++)
        {
            if(g[i-1]==h[j-1])
            {
                c[i][j]=c[i-1][j-1]+1;
                b[i][j]='c';
            }
            else if(c[i-1][j]>=c[i][j-1])
            {
                c[i][j]=c[i-1][j];
                b[i][j]='u';
            }
            else
            {
                c[i][j]=c[i][j-1];
                b[i][j]='l';
            }
        }
}

// Prints the items which are put in a knapsack of capacity W
void printknapSack(int W, int wt[10], int val[10], int n)
{
    int i, w,count=0;
    int K[n + 1][W + 1];

    for (i = 0; i <= n; i++) 
    {
        for (w = 0; w <= W; w++) 
        {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w)
                K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }
    
    int res = K[n][W];

    w = W;
    for (i = n; i > 0 && res > 0; i--) 
    {
        if (res == K[i - 1][w])
            continue;
        else 
        {
             // This item is included.
             printf("House number %d is having profit %d and weight %d\n",i,val[i-1], wt[i - 1]);
             count ++;

             // Since this weight is included its
             // value is deducted
             res = res - val[i - 1];
             w = w - wt[i - 1];
        }
    }
     printf("\nTotal number of houses selected:%d\n",count);
}

// Driver code
int main()
{
    int val[10],wt[10],i;
    int W;
    
    printf("\n\n\n\n\n\n");
    printf("\t\t\t\t ______________");
    printf("\n\t\t\t\t|              |");
    printf("\n\t\t\t\t|   ROBBERY    |");
    printf("\n\t\t\t\t|______________|");
    printf("\n\n\n\n\n\n");
    printf("\n\nA Theif decides to rob in his locality.\nTherefore He finds out the details of his locality.\n");
    printf("\nEnter the number of houses in the locality:\n");
    scanf("%d",&n);
    printf("\nEnter the profit and weight of Jewllery of each house:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d%d",&val[i],&wt[i]);
    }
    printf("\nEnter the weight that Theif can carry:\n");
    scanf("%d",&W);
    printknapSack(W, wt, val, n);

    int cost[10][10],j,p,co;
    int source, target,x,y;
    printf("\n\n\nEnter the different possible routes to each house in the locality\nconsidering the roads are Bidirectional\n\n\nEnter the distances between\n");
    for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
    cost[i][j] = IN;
    for(x=1;x<=n;x++)
    {
        for(y=x+1;y<=n;y++)
        {
            printf("Houses %d and %d: ",x,y);
            scanf("%d",&p);
            cost [x][y] = cost[y][x] = p;
        }
        printf("\n");
    }
    printf("\nEnter the House no. of Theif:");
    scanf("%d", &source);
    printf("\nEnter the House no. the Theif decides to rob:");
    scanf("%d", &target);
    co = dijsktra(cost,source,target);
    printf("\nThe Shortest distance between the Theif's house and the victim's house is %dkm\n",co);

    printf("\n\nThe Thief enters the house and finds the locker.\nWhile searching for the locker he finds a note reading two sequences,\n");
    printf("in which some of the letters where coloured.\n\nSo he guesses that actual password will have some common letters\nbetween the two written passwords.\n\n");
    printf("Enter the first password sequence:");
    scanf("%s",g);
    printf("Enter the second password sequence:");
    scanf("%s",h);
    printf("\nThe common Password is ");
    lcs();
    print(m,n);
    printf("\n\n");

    printf("The theif was successful in opening the locker and taking off the\nJewellery with him.");
    printf("\n\n\n");

    return 0;
}


int dijsktra(int cost[10][10],int source,int target)
{
    int dist[10],selected[10]={0},i,m,min,start,d,j;
    char path[10],prev[10];

    for(i=1;i<=n;i++)
    {
        dist[i] = IN;
        prev[i]= -1;
    }
    start = source;
    selected[start]=1;
    dist[start] = 0;
    while(selected[target] ==0)
    {
        min = IN;
        m = 0;
        for(i=1;i<=n;i++)
        {
            d = dist[start] +cost[start][i];
            if(d< dist[i]&&selected[i]==0)
            {
                dist[i] = d;
                prev[i]=start;
            }
            if(min>dist[i] && selected[i]==0)
            {
                min = dist[i];
                m = i;
            }
        }
        start = m;
        selected[start] = 1;
    }
    start = target;
    j = 0;
    while(start != -1)
    {
        path[j++] = start+64;
        start = prev[start];
    }
    path[j++]='\0';
    strrev(path);
    printf("\t\t\t\t");
    for(i=0;i<strlen(path);i++)
        {
            printf("%c-->",path[i]);
        }
    return dist[target];
}
