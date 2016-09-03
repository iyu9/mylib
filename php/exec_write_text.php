<?php

  //sample input param
  $_POST['cmd'] = "regist";
  $_POST['txt'] = "submit_something_text";
  $_POST['usr'] = "test_user";
  $_POST['pass'] = "password";;

  //post param
  $cmd = $_POST['cmd'];
  $txt = $_POST['txt'];
  $usr = $_POST['usr'];
  $pass = $_POST['pass'];

  $log = date(DATE_RSS) .' '. $usr .' '. $cmd .' '. $txt .' '. "\n";

  //check pass
  if ($pass != "password")
  {
	exit("invalid password");	
  }

  //output log
  $fout = fopen("log.txt", 'a');
  fwrite($fout, $log);
  fclose($fout);
?>
