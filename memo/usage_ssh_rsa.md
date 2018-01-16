## RSA public key  
  
1. ssh-keygen -t rsa -f hoge_rsa  
> hoge_rsa(secret key)  
> hoge_rsa.pub(public key)  
  
2. secret key put client ~/.ssh/hoge_rsa  
  
3. public key put server ~/.ssh/authorized_keys  
(see /etc/ssh/sshd_config)
