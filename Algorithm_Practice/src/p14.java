//���� 16401
//�̺� Ž��
//���� �����ֱ�
//1. ���� ���� >= ��� �� ��
//2. ���� ���� < ��� �� ��
import java.io.*;
import java.util.*;
public class p14 {
	
	private static int n, m;
	private static int answer=0;
	
	private static long num[][];
	private static int narr[];
	
	private static void binary_search(long num[][], int value) {
		int left = 0;
		int right = num.length-1;
		
		int mid;
		while(left<=right) {
			mid = (left+right)/2;
			
			
			if (num[mid][0]<value) {
				right=mid-1;
			
			}
			else  {
				
				
				left=mid+1;
				answer=mid+1;
			}
			
			
		}
		
	}

	public static void main(String[] args) throws IOException{
		// TODO Auto-generated method stub

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String arr[] = br.readLine().split(" ");
		m = Integer.parseInt(arr[0]);
		n = Integer.parseInt(arr[1]);
		
		
		String arr1[] = br.readLine().split(" ");
		narr = new int [n]; //���� ���� ����
		
		for(int i=0; i<n; i++) {
			narr[i] = Integer.parseInt(arr1[i]);
		}
		//���� ���� ����
		Arrays.sort(narr);
		num = new long [narr[n-1]][1];
		
		if(n>=m) //���� ���� >= ��� �� ��
			answer = narr[n-m];
		else { //���� ���� < ��� �� ��
			for(int i = 0; i<narr[n-1]; i++) {
				for(int j = 0; j<n; j++) {
					num[i][0] += narr[j]/(i+1);
					
					
				}
				
			}
			
			//�̺�Ž��
			binary_search(num, m);
		}
		
		
		System.out.println(answer);
		br.close();
	}

}
