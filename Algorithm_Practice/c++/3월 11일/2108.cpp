#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

deque<int> make_init(vector<int> &cmd, int n, deque<int> &dq2){
    deque<int> dq;
    for(int i=0; i<n; i++){
        if(cmd[i]==1){
            dq.push_front(dq2.front());
            dq2.pop_front();
        }
        else if(cmd[i]==2){
            int tmp = dq.front();
            dq.pop_front();
            dq.push_front(dq2.front());
            dq2.pop_front();
            dq.push_front(tmp);
        }
        else{
            dq.push_back(dq2.front());
            dq2.pop_front();
        }
    }

    return dq;
}

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

    dq1 = make_init(cmd, n, dq2);

    while(!dq1.empty()){
        int num = dq1.front();
        cout<<num<<' ';
        dq1.pop_front();
    }
    
}

//앞 뒤로 넣었다가 뺐다가 해야하므로 덱을 사용하기로 했다.
//결과가 1,2,3,...,n 이렇게 나오는 것이 정해져있으므로 여기서 역순으로 돌아가기로 한다.
//역순으로 하려면 1번에서는 dq2의 front()를 dq1에 push_front()해야하고 
//2번에서는 dq1에서 pop_front() 한 후에 dq2의 front()를 push_front()하여 맨 위에서 두 번째에 들어가도록 한다.
//3번에서는 dq2에서 pop_front() 한 후에 dq1에 push_back()하여 맨 뒤에서 카드가 들어가도록 한다.