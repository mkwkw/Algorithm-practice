#include <iostream>
#include <queue>
#include <vector>

using namespace std;

long long integrateFiles(priority_queue<long long, vector<long long>, greater<long long>> &pq){
    long long result = 0;

    while(pq.size()>=2){
        long long add = 0;
        add += pq.top();
        pq.pop();
        add += pq.top();
        pq.pop();
        result += add;
        //cout<<result<<'\n';
        pq.push(add);
    }

    return result;
}

int main(){
    //�ִ�: k*����ũ��: 10^10
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    int t, k, file_size;
    long long answer;

    cin>>t;

    for(int i=0; i<t; i++){
        cin>>k;
        for(int j=0; j<k; j++){
            cin>>file_size;
            pq.push(file_size);
        }
        answer = integrateFiles(pq);
        cout<<answer<<'\n';
        
        pq.pop(); //integrateFiles���� ������ push ������ pq�� ���� �ϳ� ���µ� �̰� �������.
    }

}