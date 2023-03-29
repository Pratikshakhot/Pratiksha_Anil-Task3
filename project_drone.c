#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
    int sky[20][20];
    /// Taking input from the user for the number of Drones that are flying in the sky
    int n;

    printf("\n");
    printf(" ***  Welcome to the Project on Drone's Path Tracking using x, y co-ordinates  ***\n");

    printf("\n");
    printf("Enter the number of drones flying in the sky : ");

    scanf("%d", &n);
    printf("\n");

    /// in is an 2 dimentional array that is used to store the initial point, destination point and the time period of travel of all the drones that are flying
    int in[n][5];

    printf("Enter the Details of Drones path of Travel in the form [x1 y1 x2 y2 t1]\n");
    printf("\n");
    printf("Where\n");
    printf("\n");
    printf("1)    x1 and y1 indicates starting position of the drone\n");
    printf("2)    x2 and y2 indicates destination co-ordinates of the drone\n");
    printf("3)    t1 indicates the time period of drone\n");
    printf("\n");

    for(int i=0; i<n; i++)
    {
        printf("Enter the details of drone number %d : \n", i+1);
        printf("\n");
        for(int j=0; j<5; j++)
        {
            scanf("%d", &in[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<5; j++)
        {
            printf("%d\t", in[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    /// dis is an 2 dimentional array that is used to store the distance between the initial and destination co-ordinates
    /// Manhattan Distance formula will be used to find the simple path length between any two points on the vector graph

    int dis[n];
    int max =0;
    for(int i=0; i<n; i++)
    {
        dis[i]=abs(in[i][3]-in[i][1])+abs(in[i][2]-in[i][0]);
        if ( dis[i]>max)
        {
            max=dis[i];
        }
    }


    for(int i=0; i<n; i++)
    {
        printf("The Distance of travel of drone number %d : %d\n", i+1, dis[i]);
    }
    printf("\n");
    /// pat is an 3 dimentional array that is used to store the path of co-ordinates through which the drones used to travel to reach their destination

    int pat[n][max][2];

    // in this array the i'th term indicates the i'th drone that is flying
    // max is the maximum length of all the distances of all the drones

    int outlen[n];
    for(int i=0; i<n; i++)
    {
        int j=0;
        pat[i][j][0]=in[i][0];
        pat[i][j][1]=in[i][1];
        while(abs(in[i][0]-in[i][2])!=0)
        {
            if(in[i][0]<in[i][2])
            {
                in[i][0]+=1;
            }
            else if(in[i][2]<in[i][0])
            {
                in[i][0]-=1;
            }
            j++;
            pat[i][j][0]=in[i][0];
            pat[i][j][1]=in[i][1];
        }
        while(abs(in[i][1]-in[i][3])!=0)
        {
            if(in[i][1]<in[i][3])
            {
                in[i][1]+=1;
            }
            else if(in[i][3]<in[i][1])
            {
                in[i][1]-=1;
            }
            j++;
            pat[i][j][0]=in[i][0];
            pat[i][j][1]=in[i][1];
        }
        outlen[i]=j;
    }

    for(int i=0; i<n; i++)
    {
        printf("The Travel co-ordinates for the Drone no. %d are :\n", i+1);
        printf("\n");
        for(int j=0; j<max+1; j++)
        {
            printf("%d th Co-ordinates are : %d %d\n", j+1, pat[i][j][0], pat[i][j][1]);
        }
        printf("\n");
    }
    return 0;
}