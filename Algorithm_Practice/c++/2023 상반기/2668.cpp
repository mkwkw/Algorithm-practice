#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

int main(){
    vector<bool> visited;
    vector<int> second;
    set<int> s2;
    map<int, int> m;
    int answer = 0;
    int n;

    cin>>n;

    second.assign(n, 0);
    visited.assign(n, false);

    for(int i=0; i<n; i++){
        cin>>second[i];
        m[i+1] = second[i];
    }

    //map �̿�
    //ù ��° �� ���� ���� �ٸ� -> Ű
    //�� ��° �� ���� ���� ���� �� ���� -> ���

    for(int i=1; i<=n; i++){
        if(visited[i-1]){
            continue;
        }

        int start = m[i];
        set<int> temp;
        bool flag = false;
        temp.insert(i);
        temp.insert(start);
        for(int j=0; j<n; j++){
            temp.insert(m[start]);
            if(m[start]==i){ //�ٽ� ������ ���ҷ� ���ƿ��� ��쿡�� set�� ����
                flag = true;
                break;
            }
            start = m[start];
        }
        if(flag){
            for(auto t : temp){
                visited[t-1] = true;
                s2.insert(t);
            }
        }
    }

    cout<<s2.size()<<'\n';
    for(auto s : s2){
        cout<<s<<'\n';
    }

}