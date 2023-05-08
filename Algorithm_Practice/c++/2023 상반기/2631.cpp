#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    vector<int> dp, children;
    int n, lisLength = 0;

    cin>>n;

    dp.assign(n, 1); //���� �ε������� ���� �� ������ ���� ����
    children.assign(n, 0);

    for(int i=0; i<n; i++){
        cin>>children[i];
    }

    for(int i=1; i<n; i++){
        int maxCnt = 0;
        for(int j=0; j<i; j++){
            if(children[j]<children[i] && dp[j]+1>dp[i]){
                dp[i] = dp[j]+1;
            }
        }
    }

    for(int i=0; i<n; i++){
        lisLength = max(lisLength, dp[i]);
    }

    cout<<n-lisLength;
}

//���� �� ���� ���� ���ϰ� ���� �ű�� �� ���� -> �ð� �ʰ� - �׳� n-���� �� ������ �����ϴ� ���� ���� �ص� ��.
/*
//���̵��� ������������ ���ִ°�
bool verify(vector<int> &children){
    bool flag = true;

    for(int i=0; i<children.size()-1; i++){
        if(children[i]+1!=children[i+1]){
            flag = false;
            break;
        }
    }

    return flag;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    //vector<int> dp; //���� �ε������� ���� �� ������ �����ϴ� ���� ����
    int n, answer = 0;
    vector<int> children;

    cin>>n;

    children.assign(n, 0);
    
    for(int i=0; i<n; i++){
        cin>>children[i];
    }

    while(!verify(children)){
        vector<vector<pair<char, int>>> dpLis(n); //���� �� ������ �����ϴ� ������ ���̵� ��ȣ, �ε���
        int maxCnt = 0, maxIdx = 0, insertPos = 0;
        dpLis[0].push_back({children[0], 0});

        for(int i=1; i<n; i++){
            int maxLisCnt = 0; //children[i]���� �տ� �ִ� ���� �͵��� ��
            for(int j=0; j<i; j++){
                if(children[j]<children[i]){
                    if(maxLisCnt<dpLis[j].size()){
                        maxLisCnt = dpLis[j].size();
                        dpLis[i] = dpLis[j];
                    }
                }
            }
            //dp[i] += maxLisCnt;
            dpLis[i].push_back({children[i], i});
        }

        for(int i=0; i<n; i++){
            if(maxCnt < dpLis[i].size()){
                maxCnt = dpLis[i].size();
                maxIdx = i;
            }
        }

        //cout<<"children length: "<<children.size()<<" dpLis size: "<<dpLis.size()<<'\n';
        
        for(int i=0; i<children.size(); i++){
            bool flag = false; //���� lis�� chlidren[i]�� �ִ°�
            for(int j=0; j<dpLis[maxIdx].size(); j++){
                
                if(children[i]==dpLis[maxIdx][j].first){
                    flag = true;
                    break;
                }
                else{
                    if(children[i]<dpLis[maxIdx][0].first){
                        insertPos = 0;
                        break;
                    }
                    if(dpLis[maxIdx][j].first<children[i]){
                        insertPos = dpLis[maxIdx][j].second+1;
                    }
                }
            }

            if(!flag){
                children.insert(children.begin()+insertPos, children[i]);
                if(insertPos<i){
                    children.erase(children.begin()+i+1);
                }
                else{
                    children.erase(children.begin()+i);
                }
                
                //cout<<"insertPos: "<<insertPos<<' '<<children[i]<<'\n';
                //cout<<"erasePos: "<<i<<' '<<children[i]<<'\n';
                //for(int i=0; i<n; i++){
                //    cout<<children[i]<<' ';
                //}
                //cout<<'\n';
                answer++;
                break;
            }
            
        }
    }

    cout<<answer;

}
*/