#include <iostream>
#include <vector>

using namespace std;

bool finish = false;
string answer = "";

void solve(string tmp, int cnt, int n){
    if(finish){
        return;
    }

    int size = tmp.size();
    for(int i=1; i<=size/2; i++){
        //size-i 인덱스부터 i개의 부분 문자열과 size-2*i 인덱스부터 i개의 부분 문자열이 같은지 비교
        //"1212"
        //size = 4, i=1,2 -> i=1일 때 [4-1 = 3]=> "2", [4-2*1 = 2]=> "1" / i=2일 때 [4-2 = 2]=> "12", [4-2*2 = 0]=> "12" return - 끝에 "3" 붙이는 solve(tmp, "3", n)으로 넘어감
        if(tmp.substr(size-i, i)==tmp.substr(size-2*i, i)){
            return;
        }
    }

    if(cnt==n){
        answer = tmp;
        finish = true;
    }

    for(int i=0; i<n; i++){ //n자리까지 진행하는동안 맨끝에 1, 2, 3을 직접 붙여본다.
        solve(tmp+"1", cnt+1, n); 
        solve(tmp+"2", cnt+1, n);
        solve(tmp+"3", cnt+1, n);
    }
}

int main(){
    int n;

    cin>>n;

    solve("", 0, n);

    cout<<answer;

}