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

    //�� ���� �������� ��, s�� �Ǵ� ���
    //�� ���� �������� ��, s�� �Ǵ� ���
    //�� ���� �������� ��, s�� �Ǵ� ���
    //...
    //N ���� �������� ��, s�� �Ǵ� ���

    for(int i=1; i<=n; i++){ //�����ϴ� ����
        for(int j=0; j<n; j++){ //���� �ε���
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