; emacs --script test.el
(defun message-sample ()
(let (list)
(dotimes (i 10)
(push i list)
(message "%s" list))))
