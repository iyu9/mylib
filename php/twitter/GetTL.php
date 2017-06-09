<?php

require 'TwistOAuth.phar';

//REF: http://qiita.com/yokoh9/items/760e432ebd39040d5a0f 

$consumer_key = 'CgiAQLkQPEtIAO3aS37iwTGvp';
$consumer_secret = '3Dh7DgHUKbdVAeWLXVj43UOWgjpdt4Vvbgfqug3YLx1KLSL4j';
$access_token = '179592985-wUsv2hCH6q6w17LHQztettPwwGexKKE9eF4d6yEA';
$access_token_secret = 'TrgVvmmYNBJm1PETSqwQG5N5u4v8HjfYQJwASzadj3b5T';

$connection = new TwistOAuth(
$consumer_key, $consumer_secret, $access_token, $access_token_secret);

// キーワードによるツイート検索
$tweets_params = ['q' => '夜景,きれい OR キレイ OR 綺麗' ,'count' => '10'];
$tweets = $connection->get('search/tweets', $tweets_params)->statuses;

// ハッシュタグによるツイート検索
$hash_params = ['q' => '#html5,#css3' ,'count' => '10', 'lang'=>'ja'];
$hash = $connection->get('search/tweets', $hash_params)->statuses;

// 指定位置geo情報から投稿されたツイート検索
$geo_params = ['geocode' => '35.710063,139.8107,0.2km' ,'count' => '10'];
$geo = $connection->get('search/tweets', $geo_params)->statuses;

// 自分のタイムラインを取得
$home_params = ['count' => '10'];
$home = $connection->get('statuses/home_timeline', $home_params);

// 自分のツイートを取得
$user_params = ['count' => '10'];
$user = $connection->get('statuses/user_timeline', $user_params);

// ニックネームからユーザ情報を取得
$users_params = ['screen_name' => 'yokoh9'];
$users = $connection->get('users/show', $users_params);
?>
