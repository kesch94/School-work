<?php
ini_set('display_errors', 1);
ini_set('display_startup_errors', 1)
error_reporting(E_ALL);

$cookiepath = "/tmp/cookies.txt";
$tmeout=3600; // (3600=1hr)

$baseurl = 'https://projectcompany.erpnext.com';

try{
    $ch = curl_init($baseurl.'api/method/login');
}
catch (Exception $e) {
    echo 'Caught exception: ', $e->getMessage(), "\n";
}

curl_setopt($ch,CURLOPT_POST, true);

curl_setopt($ch,CURLOPT_POSTFIELD, '{"usr":"c20antka@student.his.se","pwd":"S79lal80!!!")}');

?>