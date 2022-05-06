#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*int main(){
    int n;
    string word;
    
    cin>>word;

    n = word.length();

    vector<vector<string>> flip(n);

    flip[0].push_back(word); //1��ŭ ������ �ƴϵ�
    for(int i=1; i<n; i++){ //flip[i]�� i+1��ŭ ������ �ƴϵ� �� �� ����.
        for(int j=0; j<flip[i-1].size(); j++){
            flip[i].push_back(flip[i-1][j]); // �� ������

            for(int k=0; k<(i+1)/2; k++){
                swap(flip[i-1][j][k], flip[i-1][j][i-k]);
                flip[i].push_back(flip[i-1][j]);
            }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<flip[i].size(); j++){
            if(word>flip[i][j]){
                word = flip[i][j];
            }
        }
    }

    cout<<word;
}

//�޸� �ʰ�
*/
int main()
{
	string word, temp;
	int len, i;

	cin >> word;
	len = word.length();

	temp.push_back(word[0]);
	for (i = 1; i < len; i++){

        //temp�� �� �ձ��ڰ� word[i]���� ũ�� ������
		if (temp[0] >= word[i]){
			reverse(temp.begin(), temp.end()); //�������ִ� ���̺귯��
			temp.push_back(word[i]); //word[i] �ְ�
			reverse(temp.begin(), temp.end()); //�ٽ� ������
		}
         //temp�� �� �ձ��ڰ� word[i]���� ũ�� ������ ������ ���ϰ� word[i] �ֱ�
		else{
			temp.push_back(word[i]);
		}
	}

	cout << temp;

}