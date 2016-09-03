<?php

  //sample input param
  $_POST['cmd'] = "test";
  $_POST['txt'] = "test";
  $_POST['log'] = "test";
  $_POST['pass'] = "password";

  //post param
  $cmd = $_POST['cmd'];
  $txt = $_POST['txt'];
  $log = $_POST['log'];
  $pass = $_POST['pass'];

  //check pass
  if ($pass != "password")
  {
	exit("invalid password");	
  }

  //output log
  $fout = fopen("log.txt", 'a');
  fwrite($fout, "exec" . date(DATE_RSS) . '\n');
  fclose($fout);
?>
