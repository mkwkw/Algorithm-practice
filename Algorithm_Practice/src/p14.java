//���� 16401
//�̺� Ž��
//���� �����ֱ�
//1. ���� ���� >= ��� �� ��
//2. ���� ���� < ��� �� ��
import java.io.*;
import java.util.*;
public class p14 {

	public static void main(String[] args) throws IOException{
		// TODO Auto-generated method stub

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String arr[] = br.readLine().split(" ");
		int m = Integer.parseInt(arr[0]);
		int n = Integer.parseInt(arr[1]);
		int answer = 0;
		
		String arr1[] = br.readLine().split(" ");
		int narr[] = new int [n];
		
		for(int i=0; i<n; i++) {
			narr[i] = Integer.parseInt(arr1[i]);
		}
		
		Arrays.sort(narr);
		if(n>=m) //���� ���� >= ��� �� ��
			answer = narr[n-3];
		else { //���� ���� < ��� �� ��
			
		}
		System.out.println(answer);
	}

}
