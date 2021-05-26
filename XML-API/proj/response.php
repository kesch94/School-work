<html>
<head>
	<style>
		.main{
			border: 3px solid black;
			border-collapse: collapse;
		}
		.row{
			border: 3px solid black;
		}
		body{
			background-color:lightgreen;

		}
		.main{
			border: 3px solid black;
			border-collapse: collapse;
		}
		.row{
			border: 1px solid black;
			background-color: lightblue;
		}
		.head{
			border: 3px solid black;
			font-size: 20px;
			font-weight: bold;
			background-color: lightblue;
		}
		table{
			background-color: lightblue;
			color:blue;
		}
		h1{
			color: purple;
		}
	</style>
</head>
<body>
<a href="form.php">Back</a>
<table class="main">

<?php

	if(isset($_POST['search'])){
        $opt=$_POST['search'];
		$val=$_POST['text'];
		if($opt=="title"){
			titlesearch($val);
		}
		elseif($opt=="auth"){
			$string=$val;
			$converted = str_replace(' ', '%20', $string);
			$val=$converted;	
			authsearch($val);
		}	
		elseif($opt=="cat"){
			
		}
		
    }
	elseif(isset($_POST['category'])){
		$opt=$_POST['category'];
		catsearch($opt);
       
    }
	elseif(isset($_GET['text'])){
		adv_titlesearch();
	}

	
	function titlesearch($val){
		$xml = file_get_contents("https://wwwlab.iit.his.se/gush/XMLAPI/bookservice/books/?titlesearch=".$val);
		$dom = new DomDocument;
		$dom->preserveWhiteSpace = FALSE;
		$dom->loadXML($xml);

		$books= $dom->getElementsByTagName('BOOK');
		foreach ($books as $book){
			echo "<tr class='row'><td>".$book->getAttribute("TITLE")."</td>";
			echo "<td>".$book->getAttribute("ID")."</td>";
			foreach ($book->childNodes as $bookchild){
				
				if($bookchild->nodeName=="PREFACE"){
					echo "<td><table>";
					foreach ($bookchild->childNodes as $preface){
						$text=trim($preface->nodeValue);
						echo "<tr><td>".$text."</td></tr>";					
					}
					echo "</table></td>";
				}
				elseif($bookchild->nodeName=="AUTHORS"){
					echo "<td><table>";
					foreach ($bookchild->childNodes as $author){
						$text=trim($author->nodeValue);
						
						echo "<tr><td><a href=adv_response.php?auth=".rawurlencode($text).">".$text."</a></td></tr>";
						
					}
					echo "</table></td>";
				}
				elseif($bookchild->nodeName=="CATEGORIES"){
					echo "<td><table>";
					foreach ($bookchild->childNodes as $category){
						$text=trim($category->nodeValue);
						echo "<tr><td><a href=adv_response.php?cat=".rawurlencode($text).">".$text."</a></td></tr>";
					}
					echo "</table></td>";
				}
			}
			echo "</tr>";
			
		}
	}
	
	function authsearch($val){
		$xml = file_get_contents("https://wwwlab.iit.his.se/gush/XMLAPI/bookservice/books/?author=".$val);
		$dom = new DomDocument;
		$dom->preserveWhiteSpace = FALSE;
		$dom->loadXML($xml);

		$books= $dom->getElementsByTagName('BOOK');
		foreach ($books as $book){
			echo "<tr class='row'><td>".$book->getAttribute("TITLE")."</td>";
			echo "<td>".$book->getAttribute("ID")."</td>";
			foreach ($book->childNodes as $bookchild){
				
				if($bookchild->nodeName=="PREFACE"){
					echo "<td><table>";
					foreach ($bookchild->childNodes as $preface){
						$text=trim($preface->nodeValue);
						echo "<tr><td>".$text."</td></tr>";					
					}
					echo "</table></td>";
				}
				elseif($bookchild->nodeName=="AUTHORS"){
					echo "<td><table>";
					foreach ($bookchild->childNodes as $author){
						$text=trim($author->nodeValue);
						echo "<tr><td><a href=adv_response.php?auth=".rawurlencode($text).">".$text."</a></td></tr>";					
					}
					echo "</table></td>";
				}
				elseif($bookchild->nodeName=="CATEGORIES"){
					echo "<td><table>";
					foreach ($bookchild->childNodes as $category){
						$text=trim($category->nodeValue);
						echo "<tr><td>".$text."</td></tr>";
					}
					echo "</table></td>";
				}
			}
			echo "</tr>";
			
		}
	}
	
?>

</table>
</body>
</html>