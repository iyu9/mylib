import System;
string line;

public class ReadTextData {

  public void Read() {

	System.IO.StreamReader file = 
	new System.IO.StreamReader("TextData.dat");

	while(line = file.ReadLine() != null) {
	  System.Console.WriteLine(line);
	}

	file.close();
	System.Console.ReadLine();
  }
}
