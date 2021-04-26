<html>
<html lang="en">
    <head>
        <meta chartset="UTF-8">
        <title>XML SAX</title>
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
<table border='1' style="border-collapse: collapse; border: solid 2px black">
<?php

$globalE="";

if(isset($_POST['NEWSPAPER'])){
    $newspaper=$_POST['NEWSPAPER'];
}else{
    $newspaper="Morning_Edition";
}

foreach($_POST as $newspaper);

$url="https://wwwlab.iit.his.se/gush/XMLAPI/articleservice/articles?paper=".$newspaper;
$data = file_get_contents($url);

echo "<tr><th>Newspaper</th><th>Subscribers</th><th>Type</th><th>Article</th></tr>";
function startElement($parser, $entity, $attributes) {
    global $globalE;

        if($entity=="NEWSPAPER"){
            echo "<tr>";
            foreach ($attributes as $attname => $attvalue) {
                echo "<td style='background:grey;' >";
                echo "<div>";
                echo $attvalue;
                echo "</div>";
                echo "</td>";
            }
            echo "<td><table>";   
        }
        else if($entity=="ARTICLE"){
            foreach ($attributes as $attname => $attvalue) {    
                if($attvalue=='News'){
                    echo "<td style='background:beige;' >";
                    echo $attvalue;
                    echo "</td>"; 
                }else{
                    echo "<td style='background:lightblue;' >"; 
                    echo $attvalue;
                    echo "</td>"; 
                }
            }
            echo "</tr>";
        }
        else if($entity=="HEADING"){
            echo "<td colspan='3'>";
            echo "<h3>";
        }
        else if($entity=="STORY"){
            echo "<div>";
        }

        if($entity!="TEXT") $globalE=$entity;
}

    function endElement($parser, $entity) {
        if($entity=="NEWSPAPER"){
            echo "</table></td>";
            echo "</tr>";
        }else if($entity=="ARTICLE"){
            echo "</td></tr>";     
        }else if($entity=="STORY"){
            echo "</div>";
        }else if($entity=="HEADING"){
            echo "</h3>";
        }           
    }
    
    function charData($parser, $chardata) {
        global $globalE;

        $chardata=trim($chardata);
        if($chardata=="") return;
        if($globalE=="STORY"){
            echo"<p style='color:darkgrey; font-family:sans-serif;'>".$chardata."</div>";
        }else{
            echo $chardata;
        }  
    }
    
    $parser = xml_parser_create();
    xml_set_element_handler($parser, "startElement", "endElement");
    xml_set_character_data_handler($parser, "charData");
    

    
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