#include <iostream>
#include <vector>

using namespace std;

//누적합, dp
//만약 (2,2), (3,4) 범위의 직사각형이라면 아래와 같이 잘라야한다.
// xxxx
// xooo
// xooo
// xxxx
//행 누적합, 열 누적합 따로
int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<vector<long long>> num, partSumRow, partSumCol;
    int n, m;

    cin>>n>>m;

    num.assign(n+1, vector<long long>(n+1, 0));
    partSumRow.assign(n+1, vector<long long>(n+1, 0));
    partSumCol.assign(n+1, vector<long long>(n+1, 0));

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin>>num[i][j];
        }
    }

    partSumRow[1][1] = num[1][1];
    partSumCol[1][1] = num[1][1];

    for(int i=1; i<=n; i++){ //행
        for(int j=1; j<=n; j++){ //열
            if(i==1&&j==1){
                continue;
            }

            if(j==1){
                partSumRow[i][j] = num[i][j]; 
            }
            else{
                partSumRow[i][j] = partSumRow[i][j-1]+num[i][j];
            }
        }
    }

    for(int i=1; i<=n; i++){ //열
        for(int j=1; j<=n; j++){ //행
            if(i==1&&j==1){
                continue;
            }

            if(j==1){
                partSumCol[i][j] = num[j][i]; 
            }
            else{
                partSumCol[i][j] = partSumCol[i][j-1]+num[j][i];
            }
        }
    }
/*
    cout<<'\n';
    for(int i=0; i<=n; i++){
        for(int j=0; j<=n; j++){
            cout<<partSumRow[i][j]<<' ';
        }
        cout<<'\n';
    }

    cout<<'\n';
    for(int i=0; i<=n; i++){
        for(int j=0; j<=n; j++){
            cout<<partSumCol[i][j]<<' ';
        }
        cout<<'\n';
    }
*/
    for(int i=0; i<m; i++){
        int x1, y1, x2, y2;
        long long answer = 0;
        cin>>x1>>y1>>x2>>y2;

        if(x1!=x2){
            if(y1!=y2){
                //행, 열 둘 다 잘라내기
                for(int j=x1; j<=x2; j++){
                    answer += partSumRow[j][y2]-partSumRow[j][y1-1];
                }
            }
            else{
                //열만 잘라내기
                answer = partSumCol[y1][x2]-partSumCol[y1][x1-1];
            }
        }
        else{ 
            //행만 잘라내기
            answer = partSumRow[x2][y2]-partSumRow[x2][y1-1];
        } 
        cout<<answer<<'\n';       
    }

}