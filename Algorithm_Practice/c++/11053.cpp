#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector <int> v; //입력받은 수열 저장할 배열
    vector <int> dp;//길이 저장할 배열;
    int maxLen=0; //최대 길이 저장할 변수
    int n;

    cin>>n;

    v.assign(n,0);
    dp.assign(n,0);
    for(int i=0; i<n; i++){ //수열 입력 받기
        cin>>v[i];
    }

    for(int i=0; i<n; i++){
        int minLen=0;
        for(int j=0; j<i; j++){
            if(v[j]<v[i]){
                if(minLen<dp[j])
                    minLen=dp[j]; //i전 원소 중 최대 길이 찾고
            }
        }
        dp[i]=minLen+1; //그 최대 길이에 1더해서 저장
        if(maxLen<dp[i]){
            maxLen = dp[i]; //최대 길이 찾기
        }
    }

    cout<<maxLen;


    
    
}