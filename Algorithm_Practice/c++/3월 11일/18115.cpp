#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    vector<int> cmd;
    deque<int> dq1; //초기 카드 상태 담을 덱
    deque<int> dq2; //1,2,3,...,n 순서대로 담고 있는 덱
    int n;

    cin>>n;

    cmd.assign(n,0);

    for(int i=0; i<n; i++){
        cin>>cmd[i];
    }

    for(int i=1; i<=n; i++){
        dq2.push_back(i);
    }
    
    reverse(cmd.begin(), cmd.end()); //algorithm 헤더의 reverse함수 이용

    for(int i=0; i<n; i++){
        if(cmd[i]==1){
            dq1.push_front(dq2.front());
            dq2.pop_front();
        }
        else if(cmd[i]==2){
            int tmp = dq1.front();
            dq1.pop_front();
            dq1.push_front(dq2.front());
            dq2.pop_front();
            dq1.push_front(tmp);
        }
        else{
            dq1.push_back(dq2.front());
            dq2.pop_front();
        }
    }

    while(!dq1.empty()){
        int num = dq1.front();
        cout<<num<<' ';
        dq1.pop_front();
    }
    
}