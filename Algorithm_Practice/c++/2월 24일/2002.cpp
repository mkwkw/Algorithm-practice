#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main(){
    map<string, int> m;
    vector<string> v;
    int n, answer=0;
    string str;
    
    cin>>n;

    v.assign(n,"");
    for(int i=0; i<n; i++){
        cin>>str;
        m[str]=i;
    }
    for(int i=0; i<n; i++){
        cin>>str;
        v[i]=str;
    }

    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(m[v[i]]>m[v[j]]){
                answer++;
                break;
            }
        }
    }

    cout<<answer;   
}

//map�� key�� ������ȣ, value�� ���� ������ �����Ѵ�.
//� ���� � ���� �߿��ߴ����� �߿��� ���� �ƴ϶�
//�� �밡 �߿��ߴ��� �ƴ� ���� �߿��ϹǷ�
/*
for(int i=0; i<n; i++){
    for(int j=i+1; j<n; j++){
        if(m[v[i]]>m[v[j]]){
            answer++;
            break;
        }
    }
}
�̷��� �ڵ带 �ۼ��Ѵ�.
*/