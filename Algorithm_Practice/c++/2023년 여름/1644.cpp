#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

//투 포인터 && 소수 구하기(에라토스테네스의 체)
//소수 구하는 방법을 아래의 방법으로 해야지 시간초과 발생하지 않음
//누적합의 뺄셈으로 연속합 구하기
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<bool> num; //인덱스의 숫자가 소수인가 아닌가
    vector<int> primeNumSum; //n이하 소수의 누적합 집합
    int n, left=0, right=0, partSum, answer=0;

    cin>>n;

    if(n==1){
        cout<<0;
        return 0;
    }

    num.assign(n+1, true);

    //n이하 소수 구하기 - 이 방법으로 해야 시간초과 발생하지 않음.
    num[0] = false;
    num[1] = false;
    for(int i=2; i*i<=n; i++){
        for(int j=i*i; j<=n; j+=i){
            num[j]=false;
        }
    }
    
/*
    for(int i=0; i<primeNum.size(); i++){
        cout<<primeNum[i]<<' ';
    }
    cout<<'\n';
*/

    //누적합 저장
    primeNumSum.push_back(0); //맨 첫번째 원소 2도 포함되게 해야함.
    for(int i=2; i<=n; i++){
        if(num[i]){
            //cout<<i<<'\n';
            int prevSum = primeNumSum[primeNumSum.size()-1];
            primeNumSum.push_back(prevSum+i);
        }
    }
/*
    for(int i=0; i<n; i++){
        cout<<primeNumSum[i]<<'\n';
    }
*/
    //뺄셈으로 연속합 구하기
    while(right<primeNumSum.size() && left<=right){
        //cout<<primeNumSum[left]<<' '<<primeNumSum[right]<<' '<<partSum<<'\n';
        partSum = primeNumSum[right]-primeNumSum[left];
        if(partSum<n){
            ++right;
        }
        else{
            if(partSum==n){
                answer++;
            }
            ++left;
        }
    }

    cout<<answer;
}