#!/usr/bin/python

# CREATE TD
termList = {"hello", "term", "doc", "matrix"}
docList = {"doc1.csv", "doc2.csv", "doc3.csv", "doc4.csv"}

termDoc = {"hello":1, "term":2, "doc":3, "matrix":4}
termDocList = []
termDocList.append(termDoc)
termDocList.append(termDoc)

# CALC
for termDoc in termDocList:
  for x in termDoc:
	print x
	print termDoc[x]

def GetTermSum(termDocList, key):
  termSum = 0
  for termDoc in termDocList:
	termSum += termDoc[key]
  return termSum

def GetSumTermList(termDocList):
  termList = []
  sumList = []
  for termDoc in termDocList:
	for key in termDoc:
	  termList.append(key)

GetSumTermList(termDocList);

print GetTermSum(termDocList, "hello")
print GetTermSum(termDocList, "term")
print GetTermSum(termDocList, "doc")
print GetTermSum(termDocList, "matrix")
