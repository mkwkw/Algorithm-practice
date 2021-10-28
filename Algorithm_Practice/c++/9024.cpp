#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findNum(vector<int> &v, int n, int k){
    int cnt=0; 
    int minSub = 2*1e8; //최대 차(절댓값)

    for(int i=0; i<=n-2; i++){
        int left = i+1; //i로 하면 틀렸습니다.가 뜨고, i+1로 하면 맞았습니다.가 뜨는데 그 이유는 모르겠다..
        int right = n-1;
        int mid, sum;
        while(left<=right){
            mid = (left+right)/2;
            sum = v[i]+v[mid]; //모든 경우의 수를 찾아야하므로 i를 0부터 n-2까지 다 돌아야하고 첫 번째 수를 v[i]로 하고 두 번째 수를 v[mid]로 하여 이진탐색한다. 
            if(sum>k){
                right = mid-1;
            }
            else if(sum<=k){
                left = mid+1;
            }
            if(abs(k-sum)<minSub){ // k에 더 가까운 수를 찾는 것이므로 두 수의 차에 절댓값을 취해서 minSub과 크기를 비교한다.
                cnt = 1;
                minSub = abs(k-sum);
            }
            else if(abs(k-sum)==minSub){ //minSub과 같은 경우가 나오면 cnt를 증가시킨다. 
                cnt++;
            }
        
        }
    }
    return cnt;
}

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);

    int t, n, k;
    int answer;

    cin>>t;

    for(int i=0; i<t; i++){
        cin>>n>>k;
        vector<int> v(n);
        for(int j=0; j<n; j++){
            cin>>v[j];
        }
        sort(v.begin(), v.end());
        answer = findNum(v,n,k);
        cout<<answer<<'\n';
    
    }

}