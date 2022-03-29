#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

//����: ��ȣ��->������ �ص��ϴ� ��
int main(){
    vector<pair<char, int>> front; //key�� ���ڿ� �� ������ �ε��� ����
    vector<vector<char>> v;
    map<int, int> idx_pair; //���� �ε���, ���ĵ� ������ �ε���
    string key, code;
    int n, idx, h;

    cin>>key>>code;

    n = key.length();
    h = code.length()/n;
    v.assign(n, vector<char>(1,' '));

    for(int i=0; i<n; i++){
        front.push_back({key[i], i});
    }

    sort(front.begin(), front.end()); //Ű ����

    for(int i=0; i<n; i++){
        v[i][0]=front[i].first;
        idx_pair[front[i].second]= i; // D�� 3:0
    }

    //code�� n���� ��� v[idx]�� ����
    for(int i=0; i<code.length(); i++){
        if(i>0 && i%h==0){
            idx++;
        }
        v[idx].push_back(code[i]);
    }

    for(int i=1; i<h+1; i++){
        for(auto iter: idx_pair){
            cout<<v[iter.second][i];
        }
    }
    

}