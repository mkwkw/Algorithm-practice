
//���� 16401
//�̺� Ž��
//���� �����ֱ�
//1. ���� ���� >= ��� �� ��
//2. ���� ���� < ��� �� ��
import java.io.*;
import java.util.*;
public class p14_1 {
	
	private static int n, m;
	private static int answer=0;
	
	
	private static int narr[];
	
	
	public static void main(String[] args) throws IOException{
		// TODO Auto-generated method stub

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String arr[] = br.readLine().split(" ");
		m = Integer.parseInt(arr[0]);
		n = Integer.parseInt(arr[1]);
		//int num []= new int [100001];
		
		String arr1[] = br.readLine().split(" ");
		narr = new int [n]; //���� ���� ����
		
		for(int i=0; i<n; i++) {
			narr[i] = Integer.parseInt(arr1[i]);
		}
		//���� ���� ����
		Arrays.sort(narr);
		
		
		
			
			//�̺�Ž��
		int left = 0;
		int right = narr[n-1];
		
		
		while(left<=right) {
			int mid = (left+right)/2;
			
			int count = 0;
			for(int i=0; i<n; i++) {
				count += narr[i]/mid; //���� ���ڸ� �� �������� �������� ���
				
			}
			
			
			if (count<m) {
				right=mid-1;
			
			}
			else  {
				
				
				left=mid+1;
				answer=mid;
			}
			
			
		}
		
		
		br.close();
		System.out.println(answer);
		
	}

}

