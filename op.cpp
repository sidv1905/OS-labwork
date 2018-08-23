#include<iostream>
using namespace std;
int main()
{
int n;
cout<<"enter no. of process:";
cin>>n;
int a[n],b[n];
cout<<"enter arrival time of processes:";
for(int i=0;i<n;i++)
{
	cout<<"arrival time of process"<<i+1<<":";
	cin>>a[i];
}
for(int i=0;i<n;i++)
{
	for(int j=0;j<n-i;j++)
	{
		if(a[j]>a[j+1])
		{
			int temp=a[j];
			a[j]=a[j+1];
			a[j+1]=temp;
		}
	}
}
for(int i=0;i<n;i++)
{
	cout<<"burst time of process"<<i+1<<":";
	cin>>b[i];
}
int c=a[0];
for(int i=0;i<n;i++)
{
	int t=c+b[i];
	cout<<"completion time of process"<<i+1<<" is "<<t<<"\n";
	cout<<"turn around time time of process"<<i+1<<" is "<<t-a[i]<<"\n";
	c=c+b[i];
}
}
