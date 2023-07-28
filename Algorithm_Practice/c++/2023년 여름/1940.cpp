#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//투 포인터
//합이 m보다 작으면 right를 오른쪽으로
//합이 m보다 크거나 right를 끝까지 탐색했는데도 합이 m보다 작으면 left를 왼쪽으로 하고 right를 left+1부터 탐색
int main(){
    int n, m, left = 0, right = 1, answer = 0;
    vector<int> num;

    cin>>n>>m;

    num.assign(n, 0);

    for(int i=0; i<n; i++){
        cin>>num[i];
    }

    sort(num.begin(), num.end());

    if(n==1){
        cout<<0;
        return 0;
    }

    while(right<n && left<right){
        int tempSum = num[left]+num[right];
        //cout<<left<<' '<<right<<' '<<tempSum<<'\n';
        if(right==n-1 && tempSum<m){
            ++left;
            right = left+1;
            continue;
        }
        
        if(tempSum==m){
            answer++;
            ++left;
            right = left+1;
        }
        else if(tempSum<m){
            ++right;
        }
        else{
            ++left;
            right = left+1;
        }
    }

    cout<<answer;
}