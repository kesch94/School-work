<html>
<body>
<form method='POST' action='response.php'>
<select name='paper'>
<?php
	$xml = file_get_contents('https://wwwlab.iit.his.se/gush/XMLAPI/articleservice/papers');
    $dom = new DomDocument;
    $dom->preserveWhiteSpace = FALSE;
	$dom->loadXML($xml);    
    $newspapers= $dom->getElementsByTagName('NEWSPAPER');
	
    foreach ($newspapers as $newspaper){
		echo "<option value='".$newspaper->getAttribute("TYPE")."'>".$newspaper->getAttribute("NAME")."</option>";
    }

	

  
?>
</select>
<button>Submit!</button>
</form>
</body>
</html>