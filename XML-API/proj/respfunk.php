<html>
<head>
	<style>
		.main{
			border: 3px solid black;
			border-collapse: collapse;
		}
		.row{
			border: 1px solid black;
		}
		.head{
			border: 3px solid black;
			font-size: 20px;
			font-weight: bold;
		}
	</style>
</head>
<body>
<a href="form.php">B</a>
<?php

	function display($var){
		$xml = file_get_contents("https://wwwlab.iit.his.se/gush/XMLAPI/bookservice/books/?author=".$auth);
		$dom = new DomDocument;
		$dom->preserveWhiteSpace = FALSE;
		$dom->loadXML($xml);
	
	
	$books= $dom->getElementsByTagName('BOOK');	
		echo "<h1>Books by <em>".$_GET['auth']."</em></h1>";
		echo "<table class='main'>";
		echo "<tr class='head'><td>Title</td><td>ID</td><td>Author(s)</td><td>Categories</td><td>Preface</td></tr>";
		foreach ($books as $book){
			echo "<tr class='row'><td>".$book->getAttribute("TITLE")."</td>";
			echo "<td><a href=adv_response.php?id=".rawurlencode($book->getAttribute("ID")).">".$book->getAttribute("ID")."</a></td>";
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
		echo "</table>";
		
	}

	if(isset($_GET['auth'])){
		echo $_GET['auth'];
		$auth = rawurlencode($_GET['auth']);
		echo $auth;
	

	$xml = file_get_contents("https://wwwlab.iit.his.se/gush/XMLAPI/bookservice/books/?author=".$auth);
	$dom = new DomDocument;
	$dom->preserveWhiteSpace = FALSE;
	$dom->loadXML($xml);
	
	
	$books= $dom->getElementsByTagName('BOOK');	
		echo "<h1>Books by <em>".$_GET['auth']."</em></h1>";
		echo "<table class='main'>";
		echo "<tr class='head'><td>Title</td><td>ID</td><td>Author(s)</td><td>Categories</td><td>Preface</td></tr>";
		foreach ($books as $book){
			echo "<tr class='row'><td>".$book->getAttribute("TITLE")."</td>";
			echo "<td><a href=adv_response.php?id=".rawurlencode($book->getAttribute("ID")).">".$book->getAttribute("ID")."</a></td>";
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
		echo "</table>";
	
	}
	elseif(isset($_GET['cat'])){
		echo $_GET['cat'];
		$cat = rawurlencode($_GET['cat']);
		echo $cat;
		$xml = file_get_contents("https://wwwlab.iit.his.se/gush/XMLAPI/bookservice/books/?category=".$cat);
		$dom = new DomDocument;
		$dom->preserveWhiteSpace = FALSE;
		$dom->loadXML($xml);
		
		$books= $dom->getElementsByTagName('BOOK');	
		echo "<h1>Books by category: <em>".$_GET['cat']."</em></h1>";
		echo "<table class='main'>";
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
		echo "</table>";
	}
	elseif(isset($_GET['id'])){
		echo $_GET['id'];
		$id = rawurlencode($_GET['id']);
		echo $id;
	
		
	}
	
	
?>
</body>
</html>