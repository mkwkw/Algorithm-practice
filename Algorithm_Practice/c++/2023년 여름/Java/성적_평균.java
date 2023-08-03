import java.util.*; //List 포함
import java.io.*;


public class Main
{
    //성적 평균 계산하는 함수
    static double calculateAvg(List<Integer> score, int startIdx, int endIdx){
        int tempSum = 0;

        for(int i=startIdx; i<=endIdx; i++){
            tempSum += score.get(i);
        }

        return (double)tempSum/(endIdx-startIdx+1);
    }

    //입출력 위한 IOException 붙이기
    public static void main(String args[]) throws IOException
    {
        int n, k;

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String line = br.readLine().toString();

        String[] nk = line.split(" ");
        n = Integer.parseInt(nk[0]);
        k = Integer.parseInt(nk[1]);

        List<Integer> num = new ArrayList<>();
        line = br.readLine().toString();
        nk = line.split(" ");
        for(int i=0; i<n; i++){
            num.add(Integer.parseInt(nk[i]));
        }

        for(int i=0; i<k; i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            
            int startIdx = Integer.parseInt(st.nextToken())-1;
            int endIdx = Integer.parseInt(st.nextToken())-1;

            double answer = calculateAvg(num, startIdx, endIdx);
            //소수점 아래 셋째자리에서 반올림하여 둘째자리까지 나타내기
            System.out.printf("%.2f",answer);
            System.out.println();
        }
    }
}