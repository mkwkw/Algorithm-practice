#include <iostream>

using namespace std;

void calculate(int q, int total){
    for(int i=0; i<q; i++){
        int t,c,result;
        cin>>t;
        if(t==1){
            cin>>c;
            total = (total+c)%86400;
        }

        else if(t==2){
            cin>>c;
            total = (total-c)%86400;
            while(total<0){
                total += 86400;
            }
        }

        else{
            cout<<(total/3600)%24<<' '<<(total/60)%60<<' '<<total%60<<'\n';
        }

    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int h,m,s,q, total;
    cin>>h>>m>>s;

    total = h*3600 + m*60 + s;

    cin>>q;

    calculate(q, total);
}

//24�ð� = 86400��
//�ϴ� �ʷ� �� ȯ���� ��, 86400�ʷ� ��ⷯ ���� �ؾ���.