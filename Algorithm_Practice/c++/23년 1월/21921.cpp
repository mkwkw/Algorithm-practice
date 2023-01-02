#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main(){
    int n, x;
    long long answer=0, temp=0;
    vector<long long> visitors;
    map<long long, int> subsum;

    cin>>n>>x;

    for(int i=0; i<n; i++){
        long long num;
        cin>>num;
        visitors.push_back(num);
    }

    //�Ǿ� ���� ��
    for(int i=0; i<x; i++){
        answer += visitors[i];
    }

    subsum.insert({answer, 1});

    temp = answer;

    for(int i=1; i<=n-x; i++){
        temp -= visitors[i-1];
        temp += visitors[i+x-1];
        if(temp>=answer){
            answer = temp;
            if(subsum.find(answer)==subsum.end()){
                subsum.insert({answer, 1});
            }
            else{
                subsum[answer]++;
            }
        }
    }

    if(answer!=0){
        cout<<answer<<'\n';
        cout<<subsum[answer];
    }
    else{
        cout<<"SAD";
    }
}

//�����̵� ������
//����
//1. �湮�� �� ������ ���� �ʿ�
//2. �����̵� ������ �̿� - ó�� ��(�ε��� 0~x-1) ����
//3. �ϳ��� �̵��ϸ鼭 �Ǿտ� �� ���� �ǵڿ� �� ���ϸ鼭 ���� - �ִ� ���
//4. �ִ��� ��Ÿ���� Ƚ���� ���ؾ��ϹǷ� map {�湮�ڼ� ������, �ش� �������� �Ⱓ ����} ���� ���
 