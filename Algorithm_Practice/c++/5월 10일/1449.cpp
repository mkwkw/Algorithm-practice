#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int tapeCount(vector<int> &pos,int tapeLength){
    int cnt=0, n=pos.size(), lastPos=pos[n-1], reach, idx;
    vector<bool> check; //�������� �ٿ������� ���� ����
    check.assign(n, false);

    for(int i=0; i<n; i++){
        if(!check[i]){
            cnt++;
            check[i]=true;
        
            reach = pos[i]+tapeLength-1; //�������� ��� ��ġ

            for(int j=i+1; j<n; j++){ //�������� ��� ������ ��ġ�� �ε��� �˾Ƴ���
                if(pos[j]<=reach){
                    check[j]=true;
                    idx=j;
                }
                else{
                    break;
                }
            }
        }
    }

    return cnt;
}

int main(){
    int n, l, answer; //��ġ ����, ������ ����, ������ ����
    vector<int> pos; //��ġ

    cin>>n>>l;

    pos.assign(n,0);

    for(int i=0; i<n; i++){
        cin>>pos[i];
    }

    sort(pos.begin(), pos.end());

    answer = tapeCount(pos, l);

    cout<<answer;
}