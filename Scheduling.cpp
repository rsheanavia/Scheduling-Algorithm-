// Implementation file for Cpu scheduling

#include "Scheduling.h"
//Getting no of processes and Burst time
void cpuschedule::Getdata()
{
	int i;
	cout<<endl<<"Enter the no of processes:";
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cout<<endl<<"Enter The BurstTime for Process p"<<i<<"=	";
		cin>>Bu[i];
	}
}

//First come First served Algorithm
void cpuschedule::Fcfs()
{
	int B[10];
	Twt=0.0;
	for(i=1;i<=n;i++)
	{
		B[i]=Bu[i];
		cout<<endl<<"Burst time for process p"<<i<<"=	";
		cout<<B[i];
	}
	Wt[1]=0;
	for(i=2;i<=n;i++)
	{
		Wt[i]=B[i-1]+Wt[i-1];
	}

	//Calculating Average waiting time
	for(i=1;i<=n;i++)
		Twt=Twt+Wt[i];
	Awt=Twt/n;
	cout<<endl<<"Total waiting time="<<Twt;
	cout<<endl<<"Average waiting time="<<Awt<<"";
}

//Shortest job First Algorithm
void cpuschedule::Sjf()
{
	int i,B[10],Tt=0,temp,j;
	char S[10];
	float A[10],temp1,t;
	Twt=0.0;
	w=0.0;
	for(i=1;i<=n;i++)
	{
		B[i]=Bu[i];
		cout<<endl<<"Burst time for process p"<<i<<"=	"<<endl;
		cout<<B[i];
		S[i]='T';
		Tt=Tt+B[i];
	}
	for(i =1; i<=n;i++){
		cout<<"Enter the Arrival Time for process "<<i<<" "<<endl;
		cin>>A[i];
	}

	for(i=n;i>=1;i--)
	{
		for(j=3;j<=n;j++)
		{
			if(B[j-1]>B[j])
			{
				temp=B[j-1];
				temp1=A[j-1];
				B[j-1]=B[j];
				A[j-1]=A[j];
				B[j]=temp;
				A[j]=temp1;
			}
		}
	}

		Wt[1]=0;
		w=w+B[1];
		t=w;
		S[1]='F';

		while(w<Tt)
		{
			i=2;
			while(i<=n)
			{
				if(S[i]=='T'&&A[i]<=t)
				{
					Wt[i]=w;
					cout<<"WT "<<i<<"= "<<Wt[i]<< endl;
					S[i]='F';
					w=w+B[i];
					t=w;
					i=2;
				}
				else
					i++;
			}
		}

		for(i=1;i<=n;i++)
			Twt=Twt+(Wt[i]-A[i]);
		Awt=Twt/n;
	cout<<"Total Waiting Time="<<Twt<<""<<endl;
	cout<<"Average Waiting Time="<<Awt<<""<<endl;
}

//Priority Algorithm

void cpuschedule::Priority()
{
	int i,B[10],P[10],j;
	w=0.0;
	int max;
	Twt=0.0;
	max=1;
	for(i=1;i<=n;i++)
	{
		B[i]=Bu[i];
		cout<<"Burst time for process p "<<i<<"="<<B[i]<<endl;
		cout<<"Enter the priority for process P"<<i<<":"<<"";
		cin>>P[i];
		if(max<P[i])
			max=P[i];
	}
	j=1;
	while(j<=max)
	{
		i=1;
		while(i<=n)
		{
			if(P[i]==j)
			{
				Wt[i]=w;
				w=w+B[i];
			}
			i++;
		}
		j++;
	}

	for(i=1;i<=n;i++)
		Twt=Twt+Wt[i];
	Awt=Twt/n;
	cout<<"Total Waiting Time="<<Twt<<""<<endl;
	cout<<"Average Waiting Time="<<Awt<<""<<endl;
}




//Round Robin Algorithm
void cpuschedule::RoundRobin()
{
	int i,j,tq,k,B[10],Rrobin[10][10],count[10];
	int max=0;
	int m;
	Twt=0.0;
	for(i=1;i<=n;i++)
	{
		B[i]=Bu[i];
		cout<<"Burst time for process p"<<i<<"=	"<<B[i];
		if(max<B[i])
			max=B[i];
		Wt[i]=0;
	}
	cout<<"Enter the Time Quantum=";
	cin>>tq;
	//TO find the dimension of the Rrobin array
	m=max/tq+1;

	//initializing Rrobin array
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			Rrobin[i][j]=0;
		}
	}
	//placing value in the Rrobin array
	i=1;
	while(i<=n)
	{
		j=1;
		while(B[i]>0)
		{
			if(B[i]>=tq)
			{
				B[i]=B[i]-tq;
				Rrobin[i][j]=tq;
				j++;
			}
			else
			{
				Rrobin[i][j]=B[i];
				B[i]=0;
				j++;
			}
		}
		count[i]=j-1;
		i++;
	}

	cout<<"Display";
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			cout<<"Rr["<<i<<","<<j<<"]="<<Rrobin[i][j]<<"	"<<endl;
		}
		cout<<"";
	}
	//calculating weighting time
	int x=1;
	i=1;
	while(x<=n)
	{
		for(int a=1;a<x;a++)
		{
			Wt[x]=Wt[x]+Rrobin[a][i];
		}
		i=1;
		int z=x;
		j=count[z];
		k=1;
		while(k<=j-1)
		{
			if(i==n+1)
			{
				i=1;
				k++;
			}
			else
			{
				if(i!=z)
				{
					Wt[z]=Wt[z]+Rrobin[i][k];
				}
				i++;
			}
		}
		x++;
	}
	for(i=1;i<=n;i++)
		cout<<"Waiting Time for process P"<<i<<"="<<Wt[i]<<endl;

	//calculating Average Weighting Time
	for(i=1;i<=n;i++)
		Twt=Twt+Wt[i];
	Awt=Twt/n;
	cout<<"Total Waiting Time="<<Twt<<endl;
	cout<<"Average Waiting Time="<<Awt<<"";
	
}

//Test Driver: Application file for cpu Scheduling


void main()
{
	int ch;
	cpuschedule c;
	do
	{
		cout<<endl<<"=========MENU========="<<endl;
		cout<<endl<<"1.Getting BurstTime"<<endl;
		cout<<endl<<"2.FirstComeFirstServed"<<endl;
		cout<<endl<<"3.ShortestJobFirst"<<endl;
		cout<<endl<<"4.Priority"<<endl;
		cout<<endl<<"5.RoundRobin"<<endl;
		cout<<endl<<"6.EXIT"<<endl;
		cout<<endl<<"Enter your choice"<<endl;
		cin>>ch;
		switch(ch)
		{
		case 1:
			c.Getdata();
			break;
		case 2:
			cout<<endl<<"FIRST COME FIRST SERVED SCHEDULING"<<endl;
			c.Fcfs();
			break;
		case 3:
			cout<<endl<<"SHORTEST JOB FIRST SCHEDULING"<<endl;
			c.Sjf();		
			break;
		case 4:
			cout<<endl<<"PRIORITY SCHEDULING"<<endl;
			c.Priority();
			break;
		case 5:
			cout<<endl<<"ROUND ROBIN SCHEDULING"<<endl;
			c.RoundRobin();
			break;
		case 6:
			break;
		}
	}while(ch<=5);
}
