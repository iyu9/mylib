

corpus = "hoge piyo hoge fuga"

def CreateTermDoc(corpus):
  dict = {}
  terms = corpus.split()

  for term in terms:
	if term in dict:
	  dict[term] += 1
	  print('updated: ' + term + '=' + str(dict[term]))
	else:
	  dict[term] = 1
	  print('add: ' + term + '=' + str(dict[term]))

CreateTermDoc(corpus)


