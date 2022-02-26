#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

//�ּ� ����� ã��
//ù ��° ���
int gcd1(int a, int b){
    //�� �� �� �� ���� �� �������� �ϳ��� �����ϸ� ������� �ִ��� �Ǵ�
    for(int i=min(a,b); i>1; i--){
        //����� �����ϸ� �ٷ� ����
        if(a%i==0&&b%i==0){
            return i;
        }
    }

    return 1; //������ ���ٸ� �ִ����� 1
}

//�� ��° ���
int gcd2(int a, int b){
    if(b==0){
        return a;
    }

    //a%b���� �� b�� �ڸ� �ٲپ ȣ��
    return gcd2(b, a%b);
}

int main(){
    int a,b;
    cin>>a>>b;

    int gcd = gcd2(max(a,b), min(a,b));
    int lcm = a*b/gcd;

    cout<<gcd<<'\n'<<lcm;
}

//�ִ� �����, �ּ� ����� ���ϱ�
//a,b�� �ִ�����*�ּ� ����� = a*b