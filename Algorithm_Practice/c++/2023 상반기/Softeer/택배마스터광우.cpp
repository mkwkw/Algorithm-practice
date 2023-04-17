#include <iostream>
#include <vector>

using namespace std;

vector<int> num, temp, result;
vector<bool> visited;
int answer = 1000000000;

void backtracking(int n, int m, int k, int cnt){

	if(cnt == n){
		int move = 0;
		int idx = 0;
		int tempW = 0, tempTotal=0;
		while(move<k){
			if(tempW + temp[idx] <= m){
				tempW += temp[idx];
				//cout<<temp[idx]<<' ';
				idx = (idx+1)%n;
			}
			else{
				move++;
				tempTotal += tempW;
				//cout<<"tempW: "<<tempW<<" tempTotal: "<<tempTotal<<'\n';
				tempW = 0;
			}
		}

		answer = min(answer, tempTotal);

		return;
	}
	
	for(int i=0; i<n; i++){
		if(!visited[i]){
			temp[cnt] = num[i];
			visited[i] = true;
			backtracking(n,m,k,cnt+1);
			visited[i] = false;
		}
	}
}

int main(int argc, char** argv)
{
	
	
	int n, m, k;
	
	cin>>n>>m>>k;

	num.assign(n, 0);
	temp.assign(n, 0);
	result.assign(n, 0);

	for(int i=0; i<n; i++){
		cin>>num[i];
	}

	for(int i=0; i<n; i++){
		visited.assign(n, 0);

		temp[0] = num[i];
		visited[i] = true;
		backtracking(n,m,k, 1);
		visited[i] = false;


	}

	cout<<answer;

	return 0;
}