#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void input(int arr[],int n){
    int i;
    for (i = 0; i < n; i++)
    {
	scanf("%d",&arr[i]);
    }
}

void print(int arr[],int n){
    int i;
    for (i = 0; i < n; i++)
    {
	printf("%d ",arr[i]);
    }
}

void insertionsort(int arr[],int n){
    int i;
    for (i = 1; i < n; i++)
    {
	int temp=arr[i];
	int j=i-1;
	while (j>=0 && arr[j]>temp)
	{
	    arr[j+1]=arr[j];
	    j--;
	}
	arr[j+1]=temp;
    }

}

int partition(int a[],int lb,int ub){
    int pivot=a[lb];
    int start=lb,end=ub,temp;
    while (start<end)
    {
	while (a[start] <= pivot)
	{
	    start++;
	}
	while (a[end] > pivot)
	{
	    end--;
	}
	if(start<end){
	    int temp;
	    temp=a[start];
	    a[start]=a[end];
	    a[end]=temp;
	}
    }

    temp= a[lb];
    a[lb] = a[end];
    a[end] = temp;
    return end;
}

void quicksort(int a[],int lb, int ub){
    if(lb < ub){
	int loc ;
	loc= partition(a,lb,ub);
	quicksort(a,lb,loc-1);
	quicksort(a,loc+1,ub);
    }
}


void bubblesort(int a[],int n){
    int i;
    for (i = 0; i < n-1; i++)
    {
       int flag=0,j;
       for(j=0;j<n-1-i;j++)
       {
	 if(a[j]>a[j+1]){
	     int temp ;
	     temp= a[j];
	     a[j] = a[j+1];
	     a[j+1] = temp;
	     flag=1;
	 }
       }
       if(flag==0)
	break;
    }

}

int main(){

    int n1,n2,n3;
    int *arr1, *arr2, *arr3;
    printf("Enter the size of 1st array:");
    scanf("%d",&n1);
    arr1=(int*)malloc(n1 * sizeof(int));
    printf("Enter the elements of 1st array:");
    input(arr1,n1);
    print(arr1,n1);
    printf("\n");
    insertionsort(arr1,n1);
    print(arr1, n1);
    printf("\n");

    printf("Enter the size of second array:");
    scanf("%d", &n2);
    arr2=(int*)malloc(n2 * sizeof(int));
    printf("Enter the elements of second array:");
    input(arr2, n2);
    print(arr2, n2);
    printf("\n");
    quicksort(arr2,0,n2-1);
    print(arr2, n2);
    printf("\n");

    printf("Enter the size of 3rd array:");
    scanf("%d", &n3);
    arr3=(int*)malloc(n3 * sizeof(int));
    printf("Enter the elements 3rd second array:");
    input(arr3, n3);
    print(arr3, n3);
    printf("\n");
    bubblesort(arr3,n3);
    print(arr3, n3);

    getch();
    return 0;
}