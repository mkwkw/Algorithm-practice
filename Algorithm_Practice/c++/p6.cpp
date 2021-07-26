#include<iostream>
#include<cmath>
using namespace std;
int arr[21][21];
bool visited[21];
int ans=100;
int N;

void permu(int cnt, int cur){
	if(cnt==N/2){
		int a=0;
		int b=0;
		for(int i=1; i<=N; i++){
			for(int j=i+1; j<=N; j++){
				if(visited[i]&& visited[j]){
				a+=arr[i][j];
				a+=arr[j][i];
				}
				else if(!visited[i]&&!visited[j]){
					b+=arr[i][j];
					b+=arr[j][i];
				}
			}
		}
		ans = min(ans, abs(a-b)); 
	}
	for(int i=0; i<N; i++){
		if(visited[i]==false&&i>cur){
			visited[i]=true;
			permu(cnt+1, i);
			visited[i]=false;
		}
	}
}

int main(){
	
	
	cin>>N;
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			cin>>arr[i][j];
		}
	}

	permu(0,-1);
	cout<<ans<<endl;
}
