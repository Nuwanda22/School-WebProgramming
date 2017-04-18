package text15;

import java.util.*;

enum Part {
	Top, LeftTop, RightTop, Middle, LeftBottom, RightBottom, Bottom;
	
	public static ArrayList<Part> IntToParts(int number) {
		ArrayList<Part> parts = new ArrayList<Part>();
		
		switch(number){
		case 1:
			parts.add(RightTop);
			parts.add(RightBottom);
			break;
		case 2:
			parts.add(Top);
			parts.add(RightTop);
			parts.add(Middle);
			parts.add(LeftBottom);
			parts.add(Bottom);
			break;
		case 3:
			parts.add(Top);
			parts.add(RightTop);
			parts.add(Middle);
			parts.add(RightBottom);
			parts.add(Bottom);
			break;
		case 4:
			parts.add(LeftTop);
			parts.add(RightTop);
			parts.add(Middle);
			parts.add(RightBottom);
			break;
		case 5:
			parts.add(Top);
			parts.add(LeftTop);
			parts.add(Middle);
			parts.add(RightBottom);
			parts.add(Bottom);
			break;
		case 6:
			parts.add(Top);
			parts.add(LeftTop);
			parts.add(Middle);
			parts.add(LeftBottom);
			parts.add(RightBottom);
			parts.add(Bottom);
			break;
		case 7:
			parts.add(Top);
			parts.add(RightTop);
			parts.add(RightBottom);
			break;
		case 8:
			parts.add(Top);
			parts.add(LeftTop);
			parts.add(LeftBottom);
			parts.add(Middle);
			parts.add(RightTop);
			parts.add(RightBottom);
			parts.add(Bottom);
			break;
		case 9:
			parts.add(Top);
			parts.add(LeftTop);
			parts.add(Middle);
			parts.add(RightTop);
			parts.add(RightBottom);
			parts.add(Bottom);
			break;
		case 0:
			parts.add(Top);
			parts.add(LeftTop);
			parts.add(LeftBottom);
			parts.add(RightTop);
			parts.add(RightBottom);
			parts.add(Bottom);
			break;
		default:
			break;
		}
		
		return parts;
	}
}

class Main {
	
  public static void main(String[] args) {
	  /* Input */
	  Scanner scanner = new Scanner(System.in);
	  
	  int size = scanner.nextInt();
	  String numberString = scanner.next();
	  ArrayList<Integer> numbers = new ArrayList<Integer>();
	  
	  for(char ch : numberString.toCharArray()) {
		  numbers.add(Integer.parseInt(ch+""));
	  }
	  
	  scanner.close();
	  
	  /* Processing */
	  ArrayList<ArrayList<String>> letters = new ArrayList<ArrayList<String>>();
	  for(int i : numbers){
		  letters.add(PartToLetter(Part.IntToParts(i), size));
	  }  	  
	  
	  ArrayList<String> sentence = MergeLetter(letters);
	  for(String i : sentence){
		  System.out.println(i);
	  }
  }
  
  public static ArrayList<String> PartToLetter(ArrayList<Part> parts, int size){
	  ArrayList<String> strings = new ArrayList<String>();
	  
	  final String dash = "-";
	  final String wall = "|";
	  final String space = " ";
	  
	  String top = "";
	  for (int i = 0; i < size; i++){
			top += parts.contains(Part.Top) ? dash : space;
		}
	  strings.add(space + top + space);
	  
	  for (int i = 0; i < size; i++){
		String temp = "";
		temp += parts.contains(Part.LeftTop) ? wall : space;
		for (int j = 0; j < size; j++){
			temp += space;
		}
		temp += parts.contains(Part.RightTop) ? wall : space;
		strings.add(temp);
	  }
	  
	  String middle = "";
	  for (int i = 0; i < size; i++){
			middle += parts.contains(Part.Middle) ? dash : space;
		}
	  strings.add(space + middle + space);
	  
	  for (int i = 0; i < size; i++){
		String temp = "";
		temp += parts.contains(Part.LeftBottom) ? wall : space;
		for (int j = 0; j < size; j++){
			temp += space;
		}
		temp += parts.contains(Part.RightBottom) ? wall : space;
		strings.add(temp);
	  }
	  
	  String bottom = "";
	  for (int i = 0; i < size; i++){
			bottom += parts.contains(Part.Bottom) ? dash : space;
		}
	  strings.add(space + bottom + space);
  
	  return strings;
  }
  
  public static ArrayList<String> MergeLetter(ArrayList<ArrayList<String>> letters){
	  ArrayList<String> sentence = new ArrayList<String>();
	  
	  for(String s : letters.get(0)){
		  sentence.add(s);
	  }
	  
	  boolean first = true;
	  for(ArrayList<String> letter : letters){
		  if (first) {
			  first = false;
			  continue;
		  }
		  
		  int i = 0;
		  for(String s : letter){
			  sentence.set(i, sentence.get(i) + " " + s);
			  i++;
		  } 
	  }
	  
	  return sentence;
  }
}