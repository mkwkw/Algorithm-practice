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
    deque<int> dq1; //�ʱ� ī�� ���� ���� ��
    deque<int> dq2; //1,2,3,...,n ������� ��� �ִ� ��
    int n;

    cin>>n;

    cmd.assign(n,0);

    for(int i=0; i<n; i++){
        cin>>cmd[i];
    }

    for(int i=1; i<=n; i++){
        dq2.push_back(i);
    }
    
    reverse(cmd.begin(), cmd.end()); //algorithm ����� reverse�Լ� �̿�

    dq1 = make_init(cmd, n, dq2);

    while(!dq1.empty()){
        int num = dq1.front();
        cout<<num<<' ';
        dq1.pop_front();
    }
    
}

//�� �ڷ� �־��ٰ� ���ٰ� �ؾ��ϹǷ� ���� ����ϱ�� �ߴ�.
//����� 1,2,3,...,n �̷��� ������ ���� �����������Ƿ� ���⼭ �������� ���ư���� �Ѵ�.
//�������� �Ϸ��� 1�������� dq2�� front()�� dq1�� push_front()�ؾ��ϰ� 
//2�������� dq1���� pop_front() �� �Ŀ� dq2�� front()�� push_front()�Ͽ� �� ������ �� ��°�� ������ �Ѵ�.
//3�������� dq2���� pop_front() �� �Ŀ� dq1�� push_back()�Ͽ� �� �ڿ��� ī�尡 ������ �Ѵ�.