#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    
    int n, m;
    vector<long long> num, partSum;

    cin>>n>>m;

    num.assign(n+1, 0);
    partSum.assign(n+1, 0);

    for(int i=1; i<=n; i++){
        int number;
        cin>>number;
        num[i] = number;
    }

    partSum[1] = num[1];
    
    for(int i=2; i<=n; i++){
        partSum[i] = partSum[i-1]+num[i];
    }

    for(int i=0; i<m; i++){
        int a, b;
        cin>>a>>b;

        cout<<partSum[b]-partSum[a-1]<<'\n';
    }
}