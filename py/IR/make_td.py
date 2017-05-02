#!/usr/bin/python
# -*- coding: utf-8 -*-

#inputs
textfiles = [
  "sample1.txt",
  "sample2.txt",
]

#outputs
g_terms = {}
g_docs = {}

def OpenFileToText(filename):
  text = ""
  try:
	fin = open(filename, 'r')
	for row in fin:
	  text += row
	fin.close()
  except IOError as e:
	print('fileopen error')
	text = 'FOPEN_ERROR'
  return text

def CreateGlobalTerms(filename, corpus):
  terms = corpus.split()

  g_docs[filename] = 1

  for term in terms:
	if term in g_terms:
	  g_terms[term] += 1
	  print('updated: ' + term + '=' + str(g_terms[term]))
	else:
	  g_terms[term] = 1
	  print('add: ' + term + '=' + str(g_terms[term]))

def CreateTerms(filename, text):
  dict = {}
  terms = text.split()

  for term in terms:
	if term in dict:
	  dict[term] += 1
	  print('updated: ' + term + '=' + str(dict[term]))
	else:
	  dict[term] = 1
	  print('add: ' + term + '=' + str(dict[term]))

def Log():
  print('--- RESULT ---')
  for g_term in g_terms:
	print(g_term + ' = ' + str(g_terms[g_term]))
  for g_doc in g_docs:
	print(g_doc + ' = ' + str(g_docs[g_doc]))

if __name__ == '__main__':
  for filename in textfiles:
	text = OpenFileToText(filename)
	CreateGlobalTerms(filename, text)
  Log()
