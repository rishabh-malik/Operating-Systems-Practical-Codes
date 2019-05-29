#include <bits/stdc++.h>
using namespace std;

struct Process{
	int at,bt,pid,rt,wt,last;
};

bool compare(Process& l,Process& r){
	return l.at<r.at;
}

int main() {
	
	int n;
	cout<<"Enter no of processes: ";
	cin>>n;
	
	queue<Process>q;
	Process* p=new Process[n];
	
	for(int i=0;i<n;i++){
		
		p[i].pid=i+1;
		cin>>p[i].at>>p[i].bt;
		p[i].wt=0;
		p[i].last=p[i].at;
		p[i].rt=p[i].bt;
	}
	
	//sort according to arrival time
	sort(p,p+n,compare);
	
	for(int i=0;i<n;i++){
		q.push(p[i]);
	}
	
	//time quantum = 1
	int t=0;
	while(!q.empty()){
		
		Process curr=q.front();
		//curr.wt=curr.wt+t-curr.last-1;
		q.pop();
		if(curr.rt==1){
			curr.rt=0;
			//int id=curr.pid;
			//p[id].wt=curr.wt;
		}else{
			curr.rt--;
			//curr.last=t;
			q.push(curr);
		}
		
		cout<<curr.pid<<"->";
		
	t++;
	}
	
	//cout<<"\n";
	// for(int i=0;i<n;i++){
	// 	cout<<p[i].pid<<" "<<p[i].wt<<"\n";
	// }
	
	return 0;
}