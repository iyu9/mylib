<?php
  $db_conn = pg_connect("dbname=template1 user=tomii");

  $query = 'SELECT * FROM m_enemy';
  $result = pg_query($query);

  while($line = pg_fetch_array($result, null, PGSQL_ASSOC))
  {
    foreach($line as $col_value) {
      echo $col_value;
    }
  }
  pg_free_result($result);
  pg_close($db_conn);
?>
