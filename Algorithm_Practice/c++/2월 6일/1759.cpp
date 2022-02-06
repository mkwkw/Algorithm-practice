#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int SIZE=15;

int l,c;
vector<pair<char, bool>> alpha;
vector<char> result(SIZE);

bool decide(char ch){
    if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u'){
        return true;
    }
    return false;
}

void backtracking(int vcnt, int ccnt, int start){ 
    
    int cnt = vcnt+ccnt;

    //��ü ����, ���� ����, ���� ���� ���� �����ϸ� ��� �� �������� �Ѿ
    if(cnt==l && vcnt>=1 && ccnt>=2){
        for(int i=0; i<l; i++){
            cout<<result[i];
        }
        cout<<'\n';
        return;
    }

    //������������ �����Ƿ� ���� �ε����� �޾Ƽ� ������ ���� ������ ���� �ε���+1�ؾ���
    for(int i=start; i<c; i++){
        
        result[cnt] = alpha[i].first;
            
        if(alpha[i].second){ // �����̸�
             backtracking(vcnt+1, ccnt, i+1);
        }
        else{ //�����̸�
            backtracking(vcnt, ccnt+1, i+1);
        }
           
    }
}

int main(){

    char ch;
    cin>>l>>c;

    for(int i=0; i<c; i++){
        cin>>ch;
        if(decide(ch)){ //�����̸� true, �����̸� false
            alpha.push_back(make_pair(ch, true));
        }
        else{
            alpha.push_back(make_pair(ch, false));
        }
    }

    sort(alpha.begin(), alpha.end());

    backtracking(0,0,0);
}

//������ ��� ����� ���� �������Ѵ�.
//���� ��Ʈ��ŷ�� ����ؾ��Ѵ�.
//���� �ɸ����� �Ǵ��ϰ�, �׷��� ������ Ž������ �ʰ� �ٽ� ������ �Ѿ�� Ž���� ����Ѵ�.
//������������ ����ؾ��ϹǷ� ���� �ε����� �ް� ���� �ε���+1 �ؼ� ��Ʈ��ŷ �Լ��� �۵��Ѵ�.