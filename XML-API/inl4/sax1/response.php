<html>  
<head>
	<style>
		@import url('https://fonts.googleapis.com/css2?family=Poppins&display=swap');
		
		table,tbody,td,td{
			border-collapse: collapse;
			margin: 2px;
		}
		td{
			border-bottom: 1px solid black;
		}
		.head td{
			border: none;
		}
		.story td{
			border: none;
			
		}
		.art{
			height: 250px;
			width: 250px;
		}
		.new{
			background-color: lightblue;
			width: 350px;
			top: 0px;
		}
		.rev{
			background-color: #ffe5cc;
			width: 350px;
		}
		.rad{
			
		}
		p{
			border: 1px dotted black;
			font-family: 'Poppins', sans-serif;
		}
		h3{
			font-weight: bold;
			font-size: 20px;
			font-family: 'Poppins', sans-serif;
		}

	</style>
</head>                                                                                                                                              
<body>
<a href="form.php">Back</a>
<table>                                                                                                                                                
<?php
$lastelement="";                                                                                                                                              
function startElement($parser, $entityname, $attributes) {
	global $lastelement;
	
	if($entityname=="NEWSPAPER"){
		echo "<tr class='rad'>";
		echo "<td>".$attributes['NAME']."</td>";
		echo "<td>".$attributes['SUBSCRIBERS'];
		echo "<br>".$attributes['TYPE']."</td>";
	}
	else if($entityname=="ARTICLE"){
		echo "<td>";
		if($attributes['DESCRIPTION']=="News"){
			echo "<table class='new'>";
		}
		else if($attributes['DESCRIPTION']=="Review"){
			echo "<table class='rev'>";
		}
		else{
			echo "<table>";
		}
		echo "<tr>";		
		echo "<td>".$attributes['ID']."</td>";
		if(isset($attributes['TIME'])){
			echo "<td>".$attributes['TIME']."</td>";
		}		
		echo "<td>".$attributes['DESCRIPTION']."</td>";
		echo "</tr>";	
	}	
	else if($entityname=="HEADING"){
		echo "<tr class='head'>";		
		echo "<td>";
		echo "<h3>";
		$lastelement=$entityname;
	}	
	else if($entityname=="STORY"){
		echo "<tr class='story'>";
		echo "<td>";
		echo "<div>";
		$lastelement=$entityname;
	}
}

function endElement($parser, $entityname) {
	if($entityname=="NEWSPAPER"){
		echo "</td></tr>";
	}
	else if($entityname=="ARTICLE"){
		echo "</table></td>";
	}
	else if($entityname=="HEADING"){
		echo "</h1></td></tr>";
	}
	else if($entityname=="STORY"){
		echo "</div></td></tr>";
	}
}

function charData($parser, $chardata) {
	global $lastelement;
	
	if($lastelement=="STORY"){
		echo "<p>".$chardata."</p>";
	}
	else{
		echo $chardata;
	}
}

$parser = xml_parser_create();
xml_set_element_handler($parser, "startElement", "endElement");
xml_set_character_data_handler($parser, "charData");

if(isset($_POST['choise'])&&($_POST['choise']!="none")){
	$type=$_POST['choise'];
	$url="https://wwwlab.iit.his.se/gush/XMLAPI/articleservice/articles?paper=".$type;
	$data = file_get_contents($url);
}
else{
	$url="https://wwwlab.iit.his.se/gush/XMLAPI/articleservice/articles?paper=Morning_Edition";
	$data = file_get_contents($url);
}

if(!xml_parse($parser, $data, true)){
printf("<P> Error %s at line %d</P>", xml_error_string(xml_get_error_code($parser)),xml_get_current_line_number($parser));
}else{
// print "<br>Parsing Complete!</br>";
}

xml_parser_free($parser);
 
?>
</table>                                                                                                                                                                                                                                                                                                   
</body>                                                                                                                                               
</html>