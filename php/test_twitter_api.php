<?php

require_once("twitteroauth/twitteroauth.php");

//OAUTH
$consumerKey = "";
$consumerSecret = "";

$accessToken = "";
$accessTokenSecret = "";

$twObj = new
  TwitterOAuth($consumerKey, $consumerSecret, $accessToken, $accessTokenSecret);

//REQUEST
$andKey = "webnaut AND beeworks";
$options = array('q'=>$andKey, 'count'=>'30');

$json = $twObj->OAuthRequest(
  'https://api.twitter.com/1.1/search/tweets.json',
  'GET',
  $options
);

//RESPONSE
foreach ($jset['statuses'] as $result){
    $name = $result['user']['name'];
    $link = $result['user']['profile_image_url'];
    $content = $result['text'];
    $updated = $result['created_at'];
    $time = $time = date("Y-m-d H:i:s",strtotime($updated));

    echo "<img src='".$link."''>"." | ".$name." | ".$content." | ".$time;
	echo '<br>';
}

