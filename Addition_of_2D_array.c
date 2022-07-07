#include<stdio.h>
int main()
{
    int i,j;
    int a[2][2],b[2][2],sum[2][2];

            printf("enter the first element:\n");
            
            for ( i = 0; i < 2; i++)
              for(j = 0; j < 2; j++)
                scanf("%d",&a[i][j]);

                printf("enter the second element:\n");

                 for(i=0;i<2;i++)
                  for(j=0; j<2; j++)
                   scanf("%d",&b[i][j]);

                   sum[i][j]=a[i][j]+b[i][j];

                   printf("sum of 2D array:\n");

                        for(i=0;i<2;i++)
                   {
                        for(j=0;j<2;j++)
                   
                     {
                        sum[i][j]= a[i][j] + b[i][j];
                        printf("%d\t",sum[i][j]);
                     }
                     printf("\n");

                   }
                   
                    return 0;
            
}