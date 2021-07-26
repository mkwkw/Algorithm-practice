#include <iostream>
#include <queue>
#include <string.h>

using namespace std;

string name[300001];
int visited[300001];
int N,K;

void find(int N, int K){
	int i=0;
	int cnt=0;
	
	for(int i=0; i<N; i++){
		cin>>name[i];
	}
	while(i+K<=N){
		visited[i]=1;
		for(int j=i+1; j<=i+K; j++){
			visited[j]=1;
			if(name[i].length()==name[j].length() ){
			
			cnt++;
			}
		}
		if(i+K==N) break;
		else i++;
	}
	
	cout<<cnt;
	
}

int main(){
	queue<int> que[21]; //배열의 원소가 큐인 형태, que[a]: 길이가 a인 원소들이 큐 형태로 들어가있음. 
	long long cnt=0;
	cin>>N>>K;
	
	//find(N,K); -배열로 풀면 시간초과
	for(int i=0; i<N; i++){
		string name;
		cin>>name;
		
		int len = name.length();
		
		while(!que[len].empty() && i-que[len].front()>K){ //길이가 같지 않고 등수차이가 k이상인 것 거르기 
			que[len].pop();
		}
		cnt+=que[len].size(); //위에서 걸러지고 남은 것들의 개수를 cnt에 더한다. 
		que[len].push(i);
		
	}
	cout<<cnt;
	
	
	 
}
