#include<iostream>
#include<conio.h>
#include<stdio.h>

using namespace std;
class cpuschedule
{
	int i,j,n,Bu[20];
	float Twt,Awt,A[10],Wt[10],w;
public:
	//Getting the No of processes & burst time
	void Getdata();
	//First come First served Algorithm
	void Fcfs();
	//Shortest job First Algorithm
	void Sjf();
	//Shortest job First Algorithm with Preemption
	void SjfP();
	//Shortest job First Algorithm with NonPreemption
	void SjfNp();
	//Round Robin Algorithm
	void RoundRobin();
	//Priority Algorithm
	void Priority();
};