#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <set>

using namespace std;

int main(){
    vector<int> order;
    map<int, int> cnt; //�����ǰ �̸�, ���� Ƚ��
    vector<queue<int>> pos(101); //[i]�� ť: ��ǰi�� ��ġ��
    //queue<int> multiTap; //��Ƽ�� ����
    set<int> multiTap;
    int n, k, answer=0;

    cin>>n>>k;

    order.assign(k, 0);
    
    for(int i=0; i<k; i++){
        cin>>order[i];
        
        // if(cnt.find(order[i])!=cnt.end()){
        //     cnt[order[i]]++;
        // }
        // else{
        //     cnt[order[i]]=1;
        // }

        pos[order[i]].push(i);
        
    }

    for(int i=0; i<6; i++){
        while(!pos[i].empty()){
            cout<<pos[i].front()<<' ';
            pos[i].pop();
        }
        cout<<'\n';
    }

    //ó���� ��Ƽ�� ���� �� ä���
    int idx=0;
    while(idx<k && (((multiTap.find(order[idx])!=multiTap.end()) && multiTap.size()<=n) || ((multiTap.find(order[idx])==multiTap.end()) && multiTap.size()<n))){
        multiTap.insert(order[idx]);
        //cnt[order[idx]]--;
        pos[order[idx]].pop();
        //cout<<"order["<<idx<<"]: "<<order[idx]<<'\n';
        idx++;
        //cout<<"i: "<<idx<<" multiTap size: "<<multiTap.size()<<" order["<<idx<<"]: "<<order[idx]<<'\n';
    }

    //ó���� �� ������
    if(idx==k-1){
        cout<<0;
        return 0;
    }

    //n==1 && �ڿ� ������
    if(n==1 && idx<k-1){
        answer = k-1;
        cout<<answer;
        return 0;
    }

    //n>1 && �ڿ� ������
    for(int i=idx; i<k; i++){

        //�ڿ� �ִ� �� �߿� �¿� �ش��ϴ� ���� ���ٸ�
        if(multiTap.find(order[i])==multiTap.end()){ //�ڿ� ���� �� �߿� �¿� �ش��ϴ� ���� ���� ���
            int minCnt = 100;
            int minName = 0;

            int farDist = 0;
            int farName = 0;
            //��Ƽ�ǿ� �ִ� ��ǰ �߿� ���� ���� Ƚ���� ���� ���� �� ã��
            // for(auto s:multiTap){
            //     if(minCnt>cnt[s]){
            //         minCnt = cnt[s];
            //         minName = s; 
            //     }
            // }

            //��Ƽ�ǿ� �ִ� ��ǰ �߿� ���� �������� �Ÿ��� ���� �� �� ã��
            //���� ���� Ƚ���� ������ ���� �����
            for(auto s:multiTap){
                if(pos[s].empty()){
                    farName = s;
                    break;
                }
                
                //cout<<"s: "<<s<<' '<<pos[s].front()<<' '<<i<<' '<<pos[s].front() - i<<'\n';
                if(pos[s].front() - i >= farDist){
                    farDist = pos[s].front() - i;
                    farName = s;
                }

            }


            //cout<<"out: "<<farName<<'\n';
            //multiTap.erase(minName);
            multiTap.erase(farName);
            //cout<<multiTap.size()<<'\n';
            answer++;
            multiTap.insert(order[i]);

            // for(auto s: multiTap){
            //     cout<<s<<' ';
            // }
            // cout<<'\n';

            //cnt[order[i]]--;
            pos[order[i]].pop();
            //cout<<multiTap.size()<<'\n';
        }
        else{ //�ڿ� ���� �� �߿� �¿� �ش��ϴ� ���� �ִ� ���
            //cnt[order[i]]--;
            pos[order[i]].pop();
        }
        
    }

    cout<<answer;

}