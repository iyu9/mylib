
textfiles = ["sample1.txt", "sample2.txt"]
g_terms = {}
corpus = "hoge piyo hoge fuga"

def OpenFileToText(filename):
  text = ''
  try:
	fin = open(filename, 'r')
	for row in fin:
	  text += row
	fin.close()
  except IOError as e:
	print('fileopen error')
  return text

def CreateGlobalTerms(corpus):
  terms = corpus.split()

  for term in terms:
	if term in g_terms:
	  g_terms[term] += 1
	  print('updated: ' + term + '=' + str(g_terms[term]))
	else:
	  g_terms[term] = 1
	  print('add: ' + term + '=' + str(g_terms[term]))

def CreateTermText(corpus):
  dict = {}
  terms = corpus.split()

  for term in terms:
	if term in dict:
	  dict[term] += 1
	  print('updated: ' + term + '=' + str(dict[term]))
	else:
	  dict[term] = 1
	  print('add: ' + term + '=' + str(dict[term]))

if __name__ == '__main__':
  for filename in textfiles:
	text = OpenFileToText(filename)
	CreateGlobalTerms(text)
