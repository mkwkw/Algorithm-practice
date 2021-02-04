//���� 1935
//���� ǥ���
//����
//���� ������ push, ��ȣ ������ pop, ��� ����� push
import java.io.*;
import java.util.*;
public class p27 {

	public static void main(String[] args) throws IOException{
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int n = Integer.parseInt(br.readLine());
		char brr[] = br.readLine().toCharArray();
		
		
		double num[] = new double [n];
		for(int i=0; i<n; i++) {
			num[i] = Double.parseDouble(br.readLine());
		}
		
		Stack<Double> stack = new Stack<Double>();
		
		int count = 0;
		for(int i=0; i<brr.length; i++) {
			if(brr[i]=='*' || brr[i]=='/' || brr[i]=='+' || brr[i]=='-') {
				double b = stack.pop();
				double a = stack.pop();
				
				if(brr[i]=='*')
					stack.push(a*b);
				else if(brr[i]=='/')
					stack.push(a/b);
				else if(brr[i]=='+')
					stack.push(a+b);
				else 
					stack.push(a-b);
			}
			else
				stack.push(num[brr[i]-'A']); //A�̸� num���� ù��° �� �Ҵ��ϴ� ����
		}
		
		System.out.printf("%.2f", stack.pop());
	}

}
