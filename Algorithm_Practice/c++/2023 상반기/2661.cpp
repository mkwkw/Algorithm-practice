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
        //size-i �ε������� i���� �κ� ���ڿ��� size-2*i �ε������� i���� �κ� ���ڿ��� ������ ��
        //"1212"
        //size = 4, i=1,2 -> i=1�� �� [4-1 = 3]=> "2", [4-2*1 = 2]=> "1" / i=2�� �� [4-2 = 2]=> "12", [4-2*2 = 0]=> "12" return - ���� "3" ���̴� solve(tmp, "3", n)���� �Ѿ
        if(tmp.substr(size-i, i)==tmp.substr(size-2*i, i)){
            return;
        }
    }

    if(cnt==n){
        answer = tmp;
        finish = true;
    }

    for(int i=0; i<n; i++){ //n�ڸ����� �����ϴµ��� �ǳ��� 1, 2, 3�� ���� �ٿ�����.
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