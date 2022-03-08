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

//24시간 = 86400초
//일단 초로 다 환산한 후, 86400초로 모듈러 연산 해야함.