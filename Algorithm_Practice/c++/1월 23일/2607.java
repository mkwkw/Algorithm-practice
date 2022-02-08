import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
//�� ���迡���� solution �ڵ�� ������ �ʿ��� �Լ��� �ۼ��մϴ�.
public class Main {
    
    public static void counting(int [] ar, String word){
 
        //word���� �� ���ĺ� ���� ����
        for(int i=0; i<word.length(); i++)
            ar[word.charAt(i)-'A']++;
        
    }
    public static int solution(int n, String [] words) {//�ܾ��� �� ������ �ܾ��� �迭�� ���ڷ� �־����ϴ�.  
        int answer=0;
        int [] freq_firstword = new int[26]; //���� �ܾ��� ���ĺ�
        int [] freq_other = new int[26]; //���� �ܾ��� ���ĺ�
        int diff; //�� �ܾ�� ���ĺ� ����        
        int length = words[0].length(); //ù ��° �ܾ��� ����
 
        counting(freq_firstword, words[0]);
        
        for(int i=1; i<n; i++){
            diff=0;
            Arrays.fill(freq_other, 0);
            counting(freq_other, words[i]); //�ٸ� �ܾ� ���ĺ� ���� ����

            //�� �ܾ�� ���ĺ� ���� ���
            for(int k=0; k<26; k++)
                diff += Math.abs(freq_other[k]-freq_firstword[k]);
            
            //����� �ܾ��� ������ �ڵ�� ǥ��
            if(diff == 0 || diff ==1 || diff ==2 &&(words[i].length() == length)) answer++;
        
        }        
        return answer;
    }
            
    // ������� ���� ���� �Լ�
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        String [] words = new String[n];
        int answer;
        
        for (int i=0; i<n; i++) words[i] = br.readLine();
        
        answer = solution(n, words);
        System.out.println(answer);
    }
}