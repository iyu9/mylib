#!/bin/python

import psycopg2

con = psycopg2.connect("dbname=template1 user=tomii")
cur = con.cursor()
#cur.execute("CREATE TABLE test(id int, name text);")
#cur.execute("INSERT INTO test(id, name) VALUES (0, 'yuto');")
cur.execute("SELECT * FROM m_lv_exp;")
#res = cur.fetchone()
#print res

for record in cur:
        print record
con.commit()
cur.close()
con.close()
