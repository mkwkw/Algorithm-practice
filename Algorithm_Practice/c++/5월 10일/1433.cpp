#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int tapeCount(vector<int> &pos,int tapeLength){
    int cnt=0, n=pos.size(), lastPos=pos[n-1], reach, idx;
    vector<bool> check; //테이프가 붙여졌는지 여부 저장
    check.assign(n, false);

    for(int i=0; i<n; i++){
        if(!check[i]){
            cnt++;
            check[i]=true;
        
            reach = pos[i]+tapeLength-1; //테이프가 닿는 위치

            for(int j=i+1; j<n; j++){ //테이프가 닿는 마지막 위치의 인덱스 알아내기
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
    int n, l, answer; //위치 개수, 테이프 길이, 테이프 개수
    vector<int> pos; //위치

    cin>>n>>l;

    pos.assign(n,0);

    for(int i=0; i<n; i++){
        cin>>pos[i];
    }

    sort(pos.begin(), pos.end());

    answer = tapeCount(pos, l);

    cout<<answer;
}