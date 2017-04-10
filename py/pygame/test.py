# -*- coding: utf-8 -*-

if __name__ == "__main__":
		#read
		fin = open("sample.txt", "r");
		for row in fin:
				print row
		fin.close()

		#write
		fout = open("sample.txt", "w");
		fout.write("test")
		fout.close()
