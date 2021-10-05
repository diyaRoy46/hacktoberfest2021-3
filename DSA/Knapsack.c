#include<stdio.h>
int val[] = { 3,4,5,6};
int wt[] = { 2,3,4,5 };
int W = 5;
int n = sizeof(val)/sizeof(val[0]);

int max(int a, int b)
{
	if(a>=b)
	 return a;
	else
	 return b;
}

void selection(int W, int max, int val[], int m[n+1][W+1] )
{
	int p,l, ar[n];
	for(p=0;p<n;p++)
	 ar[p]=0;
	printf("The selected items are: ");
	while(max)
		for(p=n;p>=1;p--)
		{
			for(l=W;l>=1;l--)
			{
				if(max==m[p][l])
				{
					if(m[p-1][l]!=m[p][l])
					{
						ar[p-1]= 1;
						max -= val[p-1] ;
					}
					
				}
			}
		}
		printf("The selected items are: ");
		for(p=0;p<n;p++)
		{
			 printf("%d ", ar[p]);
		}
}
int knapsack(int W, int wt[], int val[], int n)
{
	int m[n+1][W+1],i,j;
	
	
	    
	for(i=0;i<=n;i++)
	   {
	   for(j=0;j<=W;j++)
	    {
	    if (i==0||j==0)
	      m[i][j] = 0;
		else if (wt[i-1]<=j)
	     m[i][j] = max(m[i-1][j],(m[i-1][j-wt[i-1]] + val[i-1]));
	    else
	     m[i][j] = m[i-1][j];
	     
		 }
	}
	     
	
	for(i=0;i<=n;i++)
	 {
	  for(j=0;j<=W;j++)
	    printf("%d ", m[i][j]);
	  printf("\n");
	    
		}
		
printf("\n");
selection(W,m[n][W],val,m);		

return m[n][W];
	
}

void print(int a[], int n)
{
	int i;
	
	for(i=0;i<n;i++)
	{
		printf("%d ", a[i]);
	}
}


int main()
{

   printf("Weight of the items: \n");
   print(wt, n );
   printf("\n");
   printf("Profit of the items: \n");
   print(val, n );
   printf("\n");
   printf("Maximum weight it can contain: %d", W);
   printf("\n" );
   printf("\n" );
   
   printf("The table:\n");
   printf("\n");
   
   printf("\nThe solution is : %d", knapsack(W, wt, val, n));
   
	
	
	return 0;
}
