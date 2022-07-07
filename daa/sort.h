//Mege sort
void merge(int a[],int l,int m,int h)
{
	int i,j,k,b[20];
	for(i=l,j=m+1,k=0;(i<=m)&&(j<=h);)
	{
		if(a[i]<=a[j])
			b[k++]=a[i++];
		else
			b[k++]=a[j++];
	}
	for(;i<=m;i++)
		b[k++]=a[i];
	for(;j<=h;j++)
		b[k++]=a[j];
	for(i=l,k=0;i<=h;i++,k++)
		a[i]=b[k];
}
void mergesort(int a[],int l,int h)
{
	int m;
	if(l<h)
	{
		m=(l+h)/2;
		mergesort(a,l,m);
		mergesort(a,m+1,h);
		merge(a,l,m,h);
	}
}


//Selection sort
void sel(int a[],int n)
{
	int i,j,t;
	for(i=0;i<n-1;i++)
		for(j=i+1;j<n;j++)
			if(a[i]>a[j])
			{
				t=a[j];
				a[j]=a[i];
				a[i]=t;
			}
}


//Bubble sort
void bub(int a[],int n)
{
	int i,j,t;
	for(i=0;i<n;i++)
		for(j=0;j<n-i-1;j++)
			if(a[j]>a[j+1])
			{
				t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
}


//Insertion sort
void ins(int a[],int n)
{
	int i,j,key;
	for(i=0;i<n;i++)
	{
		j=i-1;
		key=a[i];
		while((a[j]>key)&&(j>=0))
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=key;
	}
}


//Quick sort
int partition(int a[],int low,int high)
{
	int pivot=a[low],i=low,j=high,temp;
	while(i<j)
	{
		while((a[i]<=pivot)&&(i<high))
			i++;
		while((a[j]>=pivot)&&(j>low)&&(j>=i))
			j--;
		if(i<j)
		{
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
	}
	a[low]=a[j];
	a[j]=pivot;
	return j;
}
void quick_sort(int a[],int low,int high)
{
	int j;
	if(low<high)
	{
		j=partition(a,low,high);
		quick_sort(a,low,j-1);
		quick_sort(a,j+1,high);
	}
}
