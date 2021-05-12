<html>
<body>
<h1>Bookservice</h1>
<table style="border: 1px solid black">
<tr>
<td>
<h2>Search by category</h2>
<form method='GET' action='adv_response.php'>
<select name='cat'>
<?php
	$xml = file_get_contents('https://wwwlab.iit.his.se/gush/XMLAPI/bookservice/category/?categorysearch=ALL');
    $dom = new DomDocument;
    $dom->preserveWhiteSpace = FALSE;
	$dom->loadXML($xml);    
    $categories= $dom->getElementsByTagName('CATEGORY');
	
    foreach ($categories as $category){
		$text=trim($category->nodeValue);
		echo "<option value='".$text."'>".$text."</option>";
    }  
?>
</select>
<button>Submit!</button>
</form>
</td>
</tr>
<tr>
<td>
<h2>Search by text</h2>
<form method='POST' action='response.php'>
<select name='search'>
<option value='title'>Title</option>
<option value='auth'>Author</option>
</select>
<input type='text' id='text' name='text'>
<button>Submit!</button>
</form>
</td>
</tr>
<tr>
<td>
<form method='GET' action='adv_response.php'>
<h2>Advanced search</h2>
<?php
	$xml = file_get_contents('https://wwwlab.iit.his.se/gush/XMLAPI/bookservice/category/?categorysearch=ALL');
    $dom = new DomDocument;
    $dom->preserveWhiteSpace = FALSE;
	$dom->loadXML($xml);
	$categories = $dom->getElementsByTagName('CATEGORY');
	echo "<label for='text'>Title:</label>";
	echo "<input type='text' id='text' name='text'>";
	echo "<label for='category'>Category:</label>";
	echo "<select name='category'>";
	foreach ($categories as $category){
		$text=trim($category->nodeValue);
		echo "<option value='".$text."'>".$text."</option>";
    }
	echo "</select>";
	
	
?>

<button>Submit!</button>
</form>
</td>
</tr>
<tr><td><a href="adv_response.php?id=ALL">Click here to browse all books</a></td></tr>
</table>
</body>
</html>