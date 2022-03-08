#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    vector<int> tips;
    int n;
    long long answer = 0; //n=10^5 이고 다 팁이 10^5 일 때, int 범위 초과
    cin>>n;

    tips.assign(n,0);

    for(int i=0; i<n; i++){
        cin>>tips[i];
    }

    sort(tips.begin(), tips.end(), greater<int>());

    for(int i=0; i<n; i++){
        int tip = tips[i]-i;
        if(tip<0){ //음수인 경우 0으로 처리
            tip=0;
        }
        answer += tip;
    }

    cout<<answer;

}