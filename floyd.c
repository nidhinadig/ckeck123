#include<stdio.h>
#include<omp.h>
int floyd(int a[50][50],int n)
{
int b[50][50],k,i,j,thread_id,start,end;
for(i=1;i<=n;i++)
{
for(j=1;j<=n;j++)
{
b[i][j]=a[i][j];
}}
omp_set_num_threads(2);
#pragma omp parallel for shared(b) private(i,j,k)
for(k=1;k<=n;k++)
{
for(i=1;i<=n;i++)
{
for(j=1;j<=n;j++)
{
thread_id=omp_get_thread_num();
 b[i][j]=min((b[i][j]),(b[i][k]+b[k][j] ));
printf("thread %d : b[%d][%d]=%d\n" ,thread_id,i,j,b[i][j]);
}
}
}
printf("the short path");
{
for(i=1;i<=n;i++)
{
for(j=1;j<=n;j++)
{ printf("%d\t",b[i][j]);
}
printf("\n");
}
}
}
int min(int a,int b)
{
return (a<b?a:b);
}

int main()
{
int a[50][50],i,j,n;
printf("enter n");
scanf("%d",&n);
printf("enter matrix");
for(i=1;i<=n;i++)
{
for(j=1;j<=n;j++)
{
scanf("%d",&a[i][j]);
}
}
floyd(a,n);
} 
