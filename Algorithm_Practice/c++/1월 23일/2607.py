import sys
#�� ���迡���� solution �ڵ�� ������ �ʿ��� �Լ��� �ۼ��մϴ�.

#word���� �� ���ĺ� ���� ���� (�ϳ��� char�� ���ڷ� �ް� �ƽ�Ű�ڵ�� ��ȯ�ϴ� ord�Լ��� �̿�)
def counting(ar, word) :
    for w in word : 
        i=ord(w) - ord('A')
        ar[i] += 1
 
def solution(n, words): #�ܾ��� �� ������ �ܾ��� �迭�� ���ڷ� �־����ϴ�.  
#�鿩���⿡ �����ϸ鼭 �ʿ��� �ڵ带 �ۼ��ϼ���
    answer =0
    diff =0 #�� �ܾ�� ���ĺ� ����     
    freq_firstword=[0] *26 
    length = len(words[0]) #ù ��° �ܾ� ����
 
    counting(freq_firstword, words[0]) #ù ��° �ܾ� ���ĺ� ���� ����
   
    for i in range(1,n) :
        diff =0
        freq_other=[0] * 26        
        counting(freq_other, words[i]) #�ٸ� �ܾ� ���ĺ� ���� ����
    
        #�� �ܾ�� ���ĺ� ���� ���
        for freq1, freq2 in zip(freq_other, freq_firstword) :
           diff += abs(freq1-freq2)            
        
        #����� �ܾ��� ������ �ڵ�� ǥ��
        if (diff==0 or diff ==1 or (diff==2  and (len(words[i]) == length))) :  answer +=1
 
    return answer
 
if __name__ == "__main__":
    input = sys.stdin.readline
    n = int(input())
    words = [input().rstrip() for _ in range(n)]
    answer = solution(n, words)
    print(answer)