#include<iostream>
using namespace std;
void insertion(int [],int [],int);

int main()
{
	int i,n,p[20],b[20];
	float avg,sum=0;
	cout<<"Enter the no of process ";
	cin>>n;
	for(i=0;i<n;i++)
	{
		cout<<"Enter the process no ";
		cin>>p[i];
		cout<<"Enter its burst time ";
		cin>>b[i];
	}
	insertion(p,b,n);
	for(i=0;i<n;i++)
	{
		sum=sum+b[i];	
	}
	sum=sum-b[n-1];
	avg=sum/n;
	cout<<"Total waiting time "<<sum<<endl;
	cout<<"average time "<<avg;
	return 0;
}

void insertion(int a[],int b[],int n)
{
	int i,j,m,temp;
	for(int k=0;k<n;k++)
	{
		i=k;
		j=i+1;
		temp=b[j];
		while(b[i]>temp&&i!=-1)
		{
			b[j]=b[i];
			--j;
			--i;
		}
		b[j]=temp;
		a[j]=a[++i];
	}
}
