#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v(8); //주어진 수
vector<bool> visited(8, false); //v의 인덱스에 대응하는 수가 방문되었는가
vector<int> res(8); //만들어진 수열

//사전순 배열이므로 맨 끝 숫자와 들어올 숫자가 같으면 중복
void backtracking(int n, int m, int len){
    
    if(len == m){
        for(int i=0; i<m; i++){
           cout<<res[i]<<' '; 
        }
        cout<<'\n';
        return; //len == m-1상태로 돌아감
    }

    int end = 0; //맨 끝 숫자의 인덱스
    for(int i=0; i<n; i++){
        if(!visited[i] && v[i]!=end){
            res[len]=v[i];
            visited[i]=true; //방문 했다고 체크
            end = res[len];
            backtracking(n,m,len+1);
            visited[i]=false; //방문 안했다고 체크
        }
    }
    
}

/* n=4, m=2
v = {1,7,9,9}
backtracking(4,2,0);
i=0, v[0]=1!=0
res[0]=v[0]=1
visited[0]=true
end=res[0]=1

<i=0(v[0]이 res[0]인 backtracking(4,2,1) 상태>
{
    backtracking(4,2,1);
    i=0, visited[0]이 true이므로 pass
    i=1 , visited[1]=false, v[1]=7!=1
    res[1]=v[1]=7
    visited[1]=true
    end = res[1] = 7
    backtracking(4,2,2); 
    res={1,7} 출력
    visited[1]=false

    (backtracking(4,2,1)상태)
    i=2, visited[2]=false, v[2]=9!=7
    res[1]=v[2]=9
    visited[2]=false
    end = res[1] = 9
    backtracking(4,2,2);
    res={1,9} 출력
    visited[2]=false

    (backtracking(4,2,1)상태)
    i=3, visited[3]=false 하지만 v[3]=9==9pass
}
<i=1(v[1]=7이 res[0]인 backtracking(4,2,1) 상태)>

*/

int main(){
    
    int n,m;
    cin>>n>>m;

    for(int i=0; i<n; i++){
        cin>>v[i];        
    }

    sort(v.begin(), v.begin()+n); //v.begin(), v.end()라고 하면 8칸의 v가 정렬될려고 함. - 오류

    backtracking(n,m,0);
    
}