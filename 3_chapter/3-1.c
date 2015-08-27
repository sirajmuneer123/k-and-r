/*
Exercise 3-1. Our binary search makes two tests inside the loop, when one would suffice (at
the price of more tests outside.) Write a version with only one test inside the loop and measure
the difference in run-time.
*/
#include<stdio.h>
int binarysearch(int x,int v[],int n);
main()
{
	int n,v[100],x,i;
	printf("Enter the limit of array:");
	scanf("%d",&n);
	printf("Enter the elements: ");
	for(i=0;i<n;i++)
		scanf("%d",&v[i]);
	printf("Enter the elment to be search:");
	scanf("%d",&x);
	printf("The element is %d position \n",binarysearch(x,v,n));

}
int binarysearch(int x,int v[],int n)
{
	int low,mid,high;
	low=0;
	high=n-1;
	mid=(low+high)/2;
	while(low<=high && x!=v[mid]){
		if(x<v[mid])
			high=mid-1;
		else
			low=mid+1;
		mid=(low+high)/2;
	}
	if(v[mid]==x)
		return mid;
	else
		return -1;
		
}
