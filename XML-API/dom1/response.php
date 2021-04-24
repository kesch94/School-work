<html>
<head>
	<title>NEWSPAPER</title>
	<style>
		@import url('https://fonts.googleapis.com/css2?family=Special+Elite&display=swap');

		span.title{
			writing-mode: vertical-rl;
			font-size: 28px;
			font-family: 'Special Elite', cursive;
		}
		.story{
			border: 1px dotted grey;
			top: 0px;
		}
		.new{
			background-color: grey;
			width: 340px;
		}
		.rev{
			background-color: lightblue;
			width: 340px;
		}
	</style>
</head>
<body>
<a href="form.php">Back</a>
<table>
<?php
 
    // Morning edition is default
    if(isset($_POST['paper'])){
        $paper=$_POST['paper'];
    }
	else{
        $paper="Morning_Edition";
    }


	$xml = file_get_contents("https://wwwlab.iit.his.se/gush/XMLAPI/articleservice/articles?paper=".$paper);
    $dom = new DomDocument;
    $dom->preserveWhiteSpace = FALSE;
    $dom->loadXML($xml);

    $newspapers= $dom->getElementsByTagName('NEWSPAPER');
	
    foreach ($newspapers as $newspaper){
		echo "<tr><td><span class='title'>".$newspaper->getAttribute("NAME")."</span></td>";
		foreach ($newspaper->childNodes as $article){
			echo "<td><table style='border: 1px solid black'>";
			echo "<tr><td>ID: ".$article->getAttribute("ID")."</td></tr>";
			echo "<tr><td>Date: ".$article->getAttribute("TIME")."</td></tr>";
			echo "</table></td>";
			if ($article->getAttribute("DESCRIPTION")=="News"){
				echo "<td class='new'>";
			}
			elseif ($article->getAttribute("DESCRIPTION")=="Review"){
				echo "<td class='rev'>";
			}
			foreach ($article->childNodes as $content){				
				if ($content->nodeName=="HEADING"){
					$text=trim($content->nodeValue);
					echo "<h3>".$text."</h3>";
				}
				elseif($content->nodeName=="STORY"){					
					$text=trim($content->nodeValue);
					echo "<div class='story'>";
					foreach ($content->childNodes as $para){
						echo "<p>".$text."</p>";
					}
					echo "</div>";
				}				
			}
			echo "</td>";
		}		
		echo "</tr>";
    }

  
?>
</table>
</body>
</html>