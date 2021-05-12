<html>                                                                                                                                                
<body>                                                                                                                                                
<pre>
<?php                                                                                                                                                 
 
    $url="https://wwwlab.iit.his.se/gush/XMLAPI/bookservice/books/?id=ALL";
    $jsontext = file_get_contents($url);
    $arr = json_decode($jsontext);
  
    print_r($arr);


    $xml = file_get_contents('https://wwwlab.iit.his.se/gush/XMLAPI/bookservice/category/?categorysearch=ALL');
    $dom = new DomDocument;
    $dom->preserveWhiteSpace = FALSE;
	$dom->loadXML($xml);

    print_r($xml)
 
?>    
</pre>
</body>                                                                                                                                               
</html>      