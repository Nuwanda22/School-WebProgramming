package chapter13;

import java.io.*;
import java.util.Scanner;

public class FileInputStreamTest {
	public static void main(String[] args)throws IOException{
		Scanner stdin = new Scanner(System.in);
		System.out.print("�Է� ���ϸ��� �Է��ϼ��� : ");
		String s = stdin.nextLine(); stdin.close();
		FileInputStream fis = new FileInputStream(s);
		int i;
		while((i = fis.read()) != -1){
			System.out.println(i);
		}
		fis.close();
		System.out.println(s+" ���Ϸκ��� ����Ʈ�� �о� ȭ�鿡 ����Ͽ����ϴ�.");
	}
}
