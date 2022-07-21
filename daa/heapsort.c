#include <stdio.h>
void swap(int *a,int *b)//utility to swap two values
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
void heapify(int a[],int n,int i)
{
    int max=i,left=2*i,right=2*i+1;//children of i is at 2*i and 2*i+1 indices within bounds
    if(left<=n&&a[left]>a[max])//check for parental dominance property
        max=left;
    if(right<=n&&a[right]>a[max])
        max=right;
    if(max!=i)
    {
        swap(&a[i],&a[max]);//max out of parent and both children will be the root
        heapify(a,n,max);//recursively check for subtree whose root was altered
    }
}
void heapsort(int a[],int n)
{
    int i;
    for(i=n/2;i>0;i--)//check for parental dominance property(parents ccupy 1 to n/2 indices)
        heapify(a,n,i);//max heap construction
    printf("initial heap : ");
    for(i=1;i<=n;i++)
        printf("%d ",a[i]);
    printf("\nintermediate heaps:-\n");
    for(i=n;i>0;i--)
    {
        swap(&a[i],&a[1]);//max key deletion(place at the end of array)
        heapify(a,i-1,1);
        for(int t=1;t<i;t++)
            printf("%d ",a[t]);
        printf("\n");
    }    
}
int main()
{
    int a[10],n,i;
    printf("size : ");
    scanf("%d",&n);
    printf("array : ");
    a[0]=n;//heap starts from index=1
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    heapsort(a,n);
    printf("sorted array : ");
    for(i=1;i<=n;i++)
        printf("%d ",a[i]);
    printf("\n");
    return 0;
}