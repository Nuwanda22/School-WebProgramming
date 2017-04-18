package meisterproblem2;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.net.URL;
import java.net.URLConnection;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.util.Scanner;

public class MeisterProblem2
{
  private static String testMD5(String str)
  {
    String MD5 = "";
    try {
      MessageDigest md = MessageDigest.getInstance("MD5");
      md.update(str.getBytes());
      byte[] byteData = md.digest();
      StringBuffer sb = new StringBuffer();
      for (int i = 0; i < byteData.length; i++) {
        sb.append(Integer.toString((byteData[i] & 0xFF) + 256, 16).substring(1));
      }
      MD5 = sb.toString();
    } catch (NoSuchAlgorithmException e) {
      e.printStackTrace();
      MD5 = null;
    }
    return MD5;
  }

  public static void main(String[] args) throws IOException {
    Scanner scanner = new Scanner(System.in);

    System.out.println("<< -- MeisterCUP LOGIN -- >>");
    System.out.print("Enter ID : ");
    String id = scanner.nextLine();

    System.out.print("Enter PW : ");
    String pw = testMD5(scanner.nextLine());

    System.out.println("\n");
    try {
      System.out.print("Enter STR : ");

      String dessert = "Matched";
      String input = scanner.nextLine();

      StringBuffer buffer = new StringBuffer();
      for (int i = input.length() - 1; i >= 0; i--) {
        if (!Character.isAlphabetic(input.charAt(i))) {
          buffer.append(input.charAt(i));
        }
      }
      String string = buffer.toString();
      
      string = string.replace('*', '_');
      String nextStr = "VeryLoooooooooooooooooooooooooong";
      if (dessert.matches(string)) {
        nextStr = "";
      }
      else
    	  System.out.println("qwerwteyutiy");
      System.out.println("Result STR : " + nextStr.substring(0, 5) + 
        nextStr.substring(nextStr.length() - 3, nextStr.length()));
    } catch (Exception e) {
      e.printStackTrace();
      System.out.println(getUrlSource("http://meister.play-ultimate.net/problem/programming/Regex/auth.php?name=" + 
        e.getMessage().substring(0, 6) + "&error=" + e.getCause() + "&line=" + 
        e.getStackTrace()[(e.getStackTrace().length - 1)].getLineNumber() + "&id=" + id + "&password=" + 
        pw));
    }
    scanner.close();
  }

  private static String getUrlSource(String url) throws IOException {
    URL site = new URL(url);
    URLConnection connection = site.openConnection();
    BufferedReader reader = new BufferedReader(new InputStreamReader(connection.getInputStream(), "UTF-8"));

    StringBuilder builder = new StringBuilder();
    String inputLine;
    while ((inputLine = reader.readLine()) != null)
    {
      //String inputLine;
      builder.append(inputLine);
    }
    reader.close();

    return builder.toString();
  }
}