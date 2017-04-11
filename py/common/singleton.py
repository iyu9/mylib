import threading


class ThreadingSingleton:
  _instance = None
  _lock = threading.Lock()

  def __init__(self):
	print("__init__")

  def __new__(cls):
	with cls._lock:
	  if cls._instance is None:
		cls._instance = super().__new__(cls)
		return cls._instance

if __name__ == '__main__':
  ts = ThreadingSingleton()
