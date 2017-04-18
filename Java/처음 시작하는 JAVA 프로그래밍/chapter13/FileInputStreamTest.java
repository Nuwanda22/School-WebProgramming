package chapter13;

import java.io.*;
import java.util.Scanner;

public class FileInputStreamTest {
	public static void main(String[] args)throws IOException{
		Scanner stdin = new Scanner(System.in);
		System.out.print("입력 파일명을 입력하세요 : ");
		String s = stdin.nextLine(); stdin.close();
		FileInputStream fis = new FileInputStream(s);
		int i;
		while((i = fis.read()) != -1){
			System.out.println(i);
		}
		fis.close();
		System.out.println(s+" 파일로부터 바이트를 읽어 화면에 출력하였습니다.");
	}
}
