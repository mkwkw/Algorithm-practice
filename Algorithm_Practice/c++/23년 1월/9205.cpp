#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(){
    int t;
    cin>>t;

    for(int i=0; i<t; i++){
        queue<pair<int, int>> q; //�� �� �ִ� ������ ��� ť
        vector<pair<int, int>> conv; //������ ��ǥ ��� ����
        vector<bool> visited; //�湮 üũ - �湮 üũ���� ������ �޸� �ʰ� �߻�(ť�� �ʹ� ���� ���Ұ� ��)

        int n, houseX, houseY, festivalX, festivalY;
        cin>>n>>houseX>>houseY;

        for(int j=0; j<n; j++){
            int convX, convY;
            cin>>convX>>convY;
            conv.push_back({convX, convY});    
        }

        cin>>festivalX>>festivalY;

        //����ó��: ������ ����� happy�� ���, sad�� ���
        if(abs(houseX-festivalX)+abs(houseY-festivalY)<=1000){
            cout<<"happy\n";
            continue;
        }
        else if(abs(houseX-festivalX)+abs(houseY-festivalY)>1000 && n==0){
            cout<<"sad\n";
            continue;
        }
        
        if(conv.size()==0){
            cout<<"sad\n";
            continue;
        }

        q.push({houseX, houseY});

        visited.assign(conv.size(), false);

        bool flag = false; //�佺Ƽ�� ��ҿ� �� �� ������ while�� �����ϸ鼭 true�� �ٲ� ����
        
        while(!q.empty()){

            int x = q.front().first;
            int y = q.front().second;

            //�佺Ƽ�� ��ҿ� �� �� �ִ°� - �� �� ������ flag�� true�� �ٲٰ� break
            if(abs(x-festivalX)+abs(y-festivalY)<=1000){
                flag = true;
                break;
            }

            //���� ��ġ���� 1000m �̳��� �ְ� �湮���� ���� ���������� ���� - �ݺ�
            for(int j=0; j<n; j++){    
                if(!visited[j] && abs(x-conv[j].first)+abs(y-conv[j].second)>0 && abs(x-conv[j].first)+abs(y-conv[j].second)<=1000){
                    q.push({conv[j].first, conv[j].second});
                    visited[j]=true;
                }
            }

            q.pop();

        }

        //while�� ���Ŀ� flag ���� true��� �佺Ƽ�� ��ҿ� �� �� �ְ�, false��� �佺Ƽ�� ��ҿ� �� �� ���� ���̴�.
        if(flag){
            cout<<"happy\n";
        }
        else{
            cout<<"sad\n";
        }
    }
}