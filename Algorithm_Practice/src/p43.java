//��������
//4��
//���Ʈ����
//1.���� ����->�ִ� ���� ���̻� �������� ���� ���� �ݾ� 
//�� ������� �Ⱦ��� �� ����
//2.������ ���� �� 0���
import java.io.*;
public class p43 {

	public static void main(String[] args) throws IOException{
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		
		int price[] = new int [n]; //�ִ� �ݾ�
 		int deliver[] = new int [n]; //��ۺ�
 		int profit[] = new int [n]; //�� ����� ����
 		
 		int result = 1; //�ִ� ������ ������ִ� ����
 		int max = 0; //�ִ� ����
 		int answer = 0; //����
 		int maxprofit = 0; 
 		for(int i=0; i<n; i++) {
 			String brr[] = br.readLine().split(" ");
 			price[i] = Integer.parseInt(brr[0]);
 			deliver[i] = Integer.parseInt(brr[1]);
 			profit[i] = price[i]-deliver[i];
 			if(profit[i]>maxprofit)
 				maxprofit=profit[i];
 		}
 		
 		
 		
 		while(result<=maxprofit) {
 			int sum=0;
 			for(int i=0; i<n; i++) {
 				if(result<=profit[i])
 					sum += result;
 				else
 					continue;
 			}
 			System.out.println("��: "+sum);
 			System.out.println("���� ����: "+result);
// 			if(max>=sum)
// 				break;
 			
 			if(max<sum) {
 				max=sum;
 				answer = result;
 			}
 			System.out.println("�ִ� ����: "+max);
 			
 			result++;
 			System.out.println();
 			
 			if(answer == 1)
 				answer = 0;
 		}
 		
 		System.out.println(answer);
		

	}

}
