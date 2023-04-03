#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, k, answer;
    long long newNum;
    vector<long long> num;
    
    cin>>n>>newNum>>k;
    
    num.assign(k,-1); //점수가 0부터 2*10^9까지 들어올 수 있으므로 -1로 초기화
    
    for(int i=0; i<n; i++){
        cin>>num[i];
    }
    
    sort(num.begin(), num.end(), greater<>());
    
    if(n==0){
        answer = 1;
    }
    else if(num[k-1]>=newNum){
        answer = -1;
    }
    else{
        for(int i=0; i<k; i++){
            if(newNum>=num[i]){
                answer = i+1;
                break;
            }
        }
    }
    
    cout<<answer;
    
}