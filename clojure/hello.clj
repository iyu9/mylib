(println "Hello world.")

;; def is like global variable
(def text "aiueo")
(println text)
(def hello_func 
  (fn [name]
	(println 
	  (str "hello, " name)
	)
  )
)

(hello_func "test_user")

(if true
  (println "IF_EXP == TRUE")
  (println "IF_EXP == FALSE")
)

(let [x 1]
  (println x)
)

;; comment out
;(let a)
