#include <iostream>
#include <vector>

using namespace std;




int routeChecking(vector<vector<int>> &v, int n, int m){
    //맨 왼쪽 위 -1 또는 맨 오른쪽 아래 -1 -> 불가능
    if(v[0][0]==-1 || v[n-1][m-1]==-1)
        return -1;

    //하나의 열 또는 하나의 행 전체가 -1 -> 불가능
    //하나의 행 체크
    bool check1;
    for(int i=0; i<n; i++){
        check1=false;
        for(int j=0; j<m; j++){
            if(v[i][j]!=-1){
                check1=true;
                break;
            }
        }
        if(!check1)
            break;
    }
    //cout<<check1<<'\n';
    if(!check1){
        return -1;
    }
    //하나의 열 체크
    bool check2;
    for(int i=0; i<m; i++){
        check2=false;
        for(int j=0; j<n; j++){
            if(v[j][i]!=-1){
                check2=true;
                break;
            }
        }
        if(!check2)
            break;
    }
    //cout<<check2<<'\n';
    if(!check2){
        return -1;
    }
    return 1; //가능

}
//다익스트라 - 시작지점~현재지점+현재지점~끝지점 최솟값 구하기
//사방이 -1로 둘러싸여있으면 불가능

int routeFinding(vector<vector<int>> &v, int n, int m){

}
int main(){
    vector<vector<int>> v;
    int n,m;
    cin>>n>>m;
    v.assign(n,vector<int>(m,0));

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>v[i][j];
        }
    }

    int answer = routeChecking(v,n,m);
    if(answer==-1) {
        cout << answer;
        return 0;
    }
    else{
        cout<<routeFinding(v,n,m);
    }

}