#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(int argc, char** argv)
{
	vector<vector<bool>> numbers;
	int t;
	string a, b;

    //���� ��ġ���� �����ߵǸ� true, �����ߵǸ� false
	numbers.assign(10, vector<bool>(7, false));
	numbers[0]={1,1,1,0,1,1,1};
	numbers[1]={0,0,1,0,0,1,0};
	numbers[2]={1,0,1,1,1,0,1};
	numbers[3]={1,0,1,1,0,1,1};
	numbers[4]={0,1,1,1,0,1,0};
	numbers[5]={1,1,0,1,0,1,1};
	numbers[6]={1,1,0,1,1,1,1};
	numbers[7]={1,1,1,0,0,1,0};
	numbers[8]={1,1,1,1,1,1,1};
	numbers[9]={1,1,1,1,0,1,1};
	
	cin>>t;

	for(int i=0; i<t; i++){
		int answer = 0;

		cin>>a>>b;

        //ū ���� b, ���� ���� a�� �ǵ��� ����
		int aInt = stoi(a);
		int bInt = stoi(b);

		if(bInt<aInt){
			swap(aInt, bInt);
		}

		a = to_string(aInt);
		b = to_string(bInt);
		
        //a�� b ���̰� �ٸ� ��, ���� b ���̸� �ڸ���.
		if(b.length()>a.length()){
			for(int i=0; i<b.length()-a.length(); i++){
				for(int j=0; j<7; j++){
					if(numbers[b[i]-'0'][j]){
						answer++;
					}
				}
			}
			b = b.substr(b.length()-a.length());
		}

        //���� �ε����� ��
		for(int i=0; i<a.length(); i++){
			if(a[i]!=b[i]){
				//cout<<"a: "<<a[i]<<" b: "<<b[i]<<'\n';
				for(int j=0; j<7; j++){
					if(numbers[a[i]-'0'][j]!=numbers[b[i]-'0'][j]){
						answer++;
					}
				}
				//cout<<"answer: "<<answer<<'\n';
			}
		}

		cout<<answer<<'\n';

	}
	return 0;
}