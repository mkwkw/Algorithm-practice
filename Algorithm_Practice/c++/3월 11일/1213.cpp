#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int SIZE = 26;    // ���ĺ��� ��

vector<int> countAlphabet(string text) {
    // text�� �ִ� �� ���ĺ��� ������ ���� �����ϴ� �Լ�
    vector<int> count(SIZE, 0); // A-Z���� ������ ������ ������ ����Ʈ
    for (auto i: text) {
        // �� ���ڸ� �ε����� �ٲ��ֱ� ���� 'A'�� �ε����� ����
        count[i - 'A']++;
    }
    return count;
}

string makePalindrome(vector<int> &count) {
    // �Ӹ������ ����� �����ϴ� �Լ�.
    // ���� �Ұ����ϴٸ� "I'm Sorry Hansoo"�� ����.
    // part1(part3�� ��Ī) + part2(�ִ� 1����) + part3(part1�� ��Ī)
    string part1 = "", part2 = "", part3 = "";

    for (int i = 0; i < SIZE; i++) {
        // ���� ���ĺ��� ���� Ȧ�����
        if (count[i] % 2 == 1) {
            // �̹� ��� ���ڰ� á�ٸ� �� �̻� �Ұ���
            if (part2.size() > 0) {
                return "I'm Sorry Hansoo";
            }
            // ��� ���ڰ� ����ִٸ� �Ҵ�
            part2 = (char) (i + 'A');
        }
        // ���� ���� ������ ������ part1�� part3�� �̾� ���δ�
        for (int j = 0; j < count[i] / 2; j++) {
            part1 += (char) (i + 'A');
            part3 = (char) (i + 'A') + part3;
        }
    }

    return part1 + part2 + part3;
}

int main() {
    // �Է�
    string input;
    cin >> input;

    // ���� + ���
    auto count = countAlphabet(input);
    cout << makePalindrome(count);

    return 0;
}