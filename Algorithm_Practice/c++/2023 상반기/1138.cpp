#include <iostream>
#include <vector>

using namespace std;

vector<int> leftCnt, result;
vector<bool> visited;

void backtracking(int n, int cnt){

    if(cnt==n){
        return;
    }
    

    for(int i=1; i<=n; i++){
        int biggerCnt = 0;

        if(result[n-1]>0){
            return;
        }

        if(visited[i]){
            continue;
        }

        for(int j=0; j<cnt; j++){
            if(result[j]>i){
                biggerCnt++;
            }
        }
        //cout<<"bigger: "<<biggerCnt<<" i: "<<i<<'\n';
        if(biggerCnt != leftCnt[i]){
            continue;
        }

        //cout<<"result["<<cnt<<"]: "<<i<<'\n';
        result[cnt] = i;
        visited[i] = true;
        backtracking(n, cnt+1);
        visited[i] = false;

    }

}

int main(){
    
    int n;

    cin>>n;

    leftCnt.assign(n+1,0);
    result.assign(n,0);
    visited.assign(n+1, false);

    for(int i=1; i<=n; i++){
        cin>>leftCnt[i];
    }

    for(int i=1; i<=n; i++){ //result ù ��° ���� ����
    
        //�� ���ڸ� ���̹Ƿ� ���ʿ� ���� ��ü�� ����
        if(leftCnt[i]!=0){
            continue;
        }

        result[0] = i;
        visited[i] = true;
        backtracking(n, 1);
        visited[i] = false;
       
        if(result[n-1]>0){
            break;
        }
    }

    for(int i=0; i<n; i++){
        cout<<result[i]<<' ';
    }
    //cout<<'\n'; 
}