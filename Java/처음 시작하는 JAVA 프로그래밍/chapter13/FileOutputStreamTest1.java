package chapter13;

import java.io.*;
import java.util.Scanner;

public class FileOutputStreamTest1 {
	public static void main(String[] args)throws IOException{
		Scanner stdin = new Scanner(System.in);
		System.out.print("출력 파일명을 입력하세요 : ");
		String s = stdin.nextLine(); stdin.close();
		FileOutputStream fos = new FileOutputStream(s);
		for(int i = 1; i <= 260; i++){
			fos.write(i);
		}
		fos.close();
		System.out.println(s+" 파일명으로 바이트 파일을 생성하였습니다.");
	}
}
