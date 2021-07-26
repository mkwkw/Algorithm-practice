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
	queue<int> que[21]; //�迭�� ���Ұ� ť�� ����, que[a]: ���̰� a�� ���ҵ��� ť ���·� ������. 
	long long cnt=0;
	cin>>N>>K;
	
	//find(N,K); -�迭�� Ǯ�� �ð��ʰ�
	for(int i=0; i<N; i++){
		string name;
		cin>>name;
		
		int len = name.length();
		
		while(!que[len].empty() && i-que[len].front()>K){ //���̰� ���� �ʰ� ������̰� k�̻��� �� �Ÿ��� 
			que[len].pop();
		}
		cnt+=que[len].size(); //������ �ɷ����� ���� �͵��� ������ cnt�� ���Ѵ�. 
		que[len].push(i);
		
	}
	cout<<cnt;
	
	
	 
}
