#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int answer = 0;
vector<int> temp;
vector<bool> visited;
void backtracking(vector<int> &num, int n, int cnt, int startIdx, int s){
    //cout<<"i: "<<n<<" cnt "<<cnt<<" start "<<startIdx<<" s "<<s<<'\n';
    if(cnt == n){
        int result = 0;
        for(int i=0; i<temp.size(); i++){
            result += temp[i];
            //cout<<temp[i]<<' ';
        }
        //cout<<result<<'\n';
        

        if(result == s){
            answer++;
            //for(int i=0; i<temp.size(); i++){
            //    cout<<temp[i]<<' ';
            //}
            //cout<<'\n';
        }

        return;
    }

    for(int i=startIdx; i<num.size(); i++){

        if(visited[i]){
            continue;
        }
        visited[i] = true;
        temp[cnt]=num[i];
        //cout<<"temp\n";
        backtracking(num, n, cnt+1, i, s);
        visited[i] = false;
    }
    

}

int main(){
    vector<int> num, positive, negative;
    int n, s;

    cin>>n>>s;

    num.assign(n, 0);
    visited.assign(n, false);

    for(int i=0; i<n; i++){
        cin>>num[i];
    }

    sort(num.begin(), num.end());

    //한 개를 선택했을 때, s가 되는 경우
    //두 개를 선택했을 때, s가 되는 경우
    //세 개를 선택했을 때, s가 되는 경우
    //...
    //N 개를 선택했을 때, s가 되는 경우

    for(int i=1; i<=n; i++){ //선택하는 개수
        for(int j=0; j<n; j++){ //시작 인덱스
            //cout<<i<<' '<<j<<'\n';
            temp.assign(n, 0);
            visited.assign(n, false);
            temp[0] = num[j];
            visited[j] = true;
            backtracking(num, i, 1, j+1, s);
        }
    }

    cout<<answer;
    
}