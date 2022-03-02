#include <iostream>
#include <vector>

using namespace std;

vector<int> find_prime(int n){ //�Ҽ� ���� �迭 ã��
    vector<bool> num(n+1, true);
    vector<int> prime;
    num[0]=false;
    num[1]=false;
    for(int i=2; i*i<=n; i++){
        for(int j=i*i; j<=n; j+=i){
            num[j]=false;
        }
    }

    for(int i=2; i<=n; i++){
        if(num[i]){
            prime.push_back(i);
        }
    }

    return prime; //�Ҽ� �迭 ����
}

vector<int> add_prime(vector<int> &find_prime, int n){
    vector<int> prime_sum(find_prime.size()+1,0); //�Ҽ� ������ ������ �迭;
    prime_sum[0]=0; //�ε��� 0�� �� ���ڸ� 0���� �ؾ� �����հ��� ���� ������ �� ����.

    //������ ���
    int num = prime_sum[0];
    for(int i=1; i<prime_sum.size(); i++){
        prime_sum[i]=find_prime[i-1]+ num;
        num = prime_sum[i];
    }

    return prime_sum;
}

//������ ���� ���̰� n�� ��� ã��
int find_case(vector<int> &prime_sum, int n){
    int answer=0;
    int result=0;
    int left=0;
    int right=0;

    while(left<=right && right<prime_sum.size()){
        result = prime_sum[right]-prime_sum[left];
        //cout<<"left: "<<left<<" right: "<<right<<" result: "<<result<<" answer: "<<answer<<'\n';
        if(result >= n){
            if(result==n){
                answer++;
            }
            left++;
        }
        else{
            right++;
            if(right==prime_sum.size()){
                break;
            }
        }
    }

    return answer;    
}

int main(){
    vector<int> prime;
    int n, answer;
    cin>>n;

    prime = find_prime(n);
    prime = add_prime(prime, n);

    answer = find_case(prime, n);
    cout<<answer;
}

//n���� �Ҽ� ã��
//�Ҽ��� ������ ����ϱ�
//���� ���� �� �� ������ �̿��Ͽ� ������ ���� ���̰� n�� ��� ã��