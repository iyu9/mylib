#!/bin/python

import psycopg2

con = psycopg2.connect(dbname="template1", user="tomii")
cur = con.cursor()
#cur.execute("CREATE TABLE test(id int, name text);")
#cur.execute("INSERT INTO test(id, name) VALUES (0, 'yuto');")
cur.execute("SELECT * FROM test;")
res = cur.fetchone()
print res
con.commit()
cur.close()
con.close()
