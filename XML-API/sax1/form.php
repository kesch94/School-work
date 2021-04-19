<html>                                                                                                                                                
<body>                                                                                                                                                
<form method="POST" action="response.php" >
<select name="choise">
<option value="none">Morning_Edition article</option>                                                                                                                                                 
<?php                                                                                                                                                 
     
function startElement($parser, $entityname, $attributes) {
	if($entityname=="NEWSPAPER"){
		echo "<option value='".$attributes['TYPE']."'>".$attributes['NAME'];
	}

}

function endElement($parser, $entityname) {
	if($entityname=="NEWSPAPER"){
		echo "</option>";
	}
}

function charData($parser, $chardata) {
}

$parser = xml_parser_create();
xml_set_element_handler($parser, "startElement", "endElement");
xml_set_character_data_handler($parser, "charData");

$url="https://wwwlab.iit.his.se/gush/XMLAPI/articleservice/papers";
$data = file_get_contents($url);

if(!xml_parse($parser, $data, true)){
printf("<P> Error %s at line %d</P>", xml_error_string(xml_get_error_code($parser)),xml_get_current_line_number($parser));
}else{
//print "<br>Parsing Complete!</br>";
}

xml_parser_free($parser);
 
?> 
</select>
<button>Search</button>                                                                                                                                                   
</form>                                                                                                                                                
</body>                                                                                                                                               
</html>    