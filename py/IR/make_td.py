#!/usr/bin/python

# Prepare Basic Info
termList = {"hello", "term", "doc", "matrix"}
docList = {"doc1.csv", "doc2.csv", "doc3.csv", "doc4.csv"}

termDoc = {"hello":1, "term":2, "doc":3, "matrix":4}
termDocList = []
termDocList.append(termDoc)
termDocList.append(termDoc)

# Create Term-Doc Matrix
for termDoc in termDocList:
  for x in termDoc:
	print x
	print termDoc[x]

def GetTermSum(termDocList, key):
  termSum = 0
  for termDoc in termDocList:
	termSum += termDoc[key]
  return termSum

def GetTermSumList(termDocList):
  termList = []
  sumList = []
  dictionary = {}

  # GET TERMS
  for termDoc in termDocList:
	for key in termDoc:
	  termList.append(key)

  # GET SUMS
  for term in termList:
	print GetTermSum(termDocList, term)
	dictionary[term] = GetTermSum(termDocList, term);

  print dictionary

GetTermSumList(termDocList);
