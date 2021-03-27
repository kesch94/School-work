<html>
<head>
	<style>
		.main{
			border: 3px solid black;
			border-collapse: collapse;
		}
		.row{
			border: 1px solid black;
			background-color: #ffc;
		}
		.head{
			border: 3px solid black;
			font-size: 20px;
			font-weight: bold;
			background-color: #f2f2f2;
		}
	</style>
</head>
<body>
<a href="form.php">B</a>
<?php
	if (isset($_GET['text'])&&($_GET['category'])){
		$searchtext = rawurlencode($_GET['text']);
		$cat = rawurlencode($_GET['category']);

		$xml = file_get_contents("https://wwwlab.iit.his.se/gush/XMLAPI/bookservice/books/?titlesearch=".$searchtext."&category=".$cat);
		$dom = new DomDocument;
		$dom->preserveWhiteSpace = FALSE;
		$dom->loadXML($xml);
		
		$books= $dom->getElementsByTagName('BOOK');	
		echo "<h1>Books by category: <em>".$_GET['category']."</em></h1>";
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
	elseif(isset($_GET['auth'])){
		/* $fullname = $_GET['auth'];
		$split = explode(" ", $fullname); */		
		$auth = rawurlencode($_GET['auth']);
	
		$xml = file_get_contents("https://wwwlab.iit.his.se/gush/XMLAPI/bookservice/books/?author=".$auth);
		$dom = new DomDocument;
		$dom->preserveWhiteSpace = FALSE;
		$dom->loadXML($xml);	
		$books= $dom->getElementsByTagName('BOOK');	
		
		echo "<h1>Books by <em>".$_GET['auth']."</em></h1>";
		echo "<h2>Click <a href=adv_response.php?authdetail=".$auth.">here</a> for more details on ".$_GET['auth'];
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
		$cat = rawurlencode($_GET['cat']);
		$xml = file_get_contents("https://wwwlab.iit.his.se/gush/XMLAPI/bookservice/books/?category=".$cat);
		$dom = new DomDocument;
		$dom->preserveWhiteSpace = FALSE;
		$dom->loadXML($xml);
		
		$books= $dom->getElementsByTagName('BOOK');	
		echo "<h1>Books by category: <em>".$_GET['cat']."</em></h1>";
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
	elseif(isset($_GET['id'])){
		$id = rawurlencode($_GET['id']);	
		$xml = file_get_contents("https://wwwlab.iit.his.se/gush/XMLAPI/bookservice/books/?id=".$id);
		$dom = new DomDocument;
		$dom->preserveWhiteSpace = FALSE;
		$dom->loadXML($xml);
		$books= $dom->getElementsByTagName('BOOK');	
		
		echo "<h1>Book ID: <em>".$_GET['id']."</em></h1>";
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
	elseif(isset($_GET['authdetail'])){
		$fullname = $_GET['authdetail'];
		$split = explode(" ", $fullname);
		/* echo $split[0];
		echo $split[1]; */
		
		$url = "https://wwwlab.iit.his.se/gush/XMLAPI/bookservice/authors?firstname=".$split[0]."&lastname=".$split[1];

		$xml = file_get_contents("https://wwwlab.iit.his.se/gush/XMLAPI/bookservice/authors?firstname=".$split[0]."&lastname=".$split[1]);
		$dom = new DomDocument;
		$dom->preserveWhiteSpace = FALSE;
		$dom->loadXML($xml);	
		$authors= $dom->getElementsByTagName("AUTHOR");	
		$details = $dom->getElementsByTagName("AUTHOR");
		echo "<table><tr><td><table>";
		
		foreach ($authors as $author){
			echo "<tr><td>".$author->getAttribute("ROLE")."</td></tr>";
			
		}
		echo "</table></td>";
		echo "<td><table>";
		/* foreach ($details as $detail){ */
			
			foreach ($details[0]->childNodes as $child){
				$text=trim($child->nodeValue);
				if ($child->nodeName=="FIRSTNAME"){
					echo "<tr><td>";
					echo $text;
				}
				elseif ($child->nodeName=="LASTNAME"){
					echo $text;
					echo "</td></tr>";
				}
				elseif ($child->nodeName=="BIRTHYEAR"){
					echo "<tr><td>";
					echo $text." - ";
				}
				elseif ($child->nodeName=="DEATHYEAR"){
					echo $text;
					echo "</td></tr>";
				}
				elseif ($child->nodeName=="IMGURL"){
					echo "<tr><td><img src='".$text."' style='width:48px;height:71px;'></td></tr>";
				}
				elseif ($child->nodeName=="ABOUT"){
					echo "<tr><td>";
					echo $text;
					echo "</td>";
				}
				elseif ($child->nodeName=="SIGNATURE"){
					echo "<td>";
					echo "<tr><td><img src='".$text."' style='width:80px;height:48px;'></td></tr>";
					echo "</td></tr>";
				}
			}
		/* } */
		echo "</table></td>";
		echo "</tr></table>";
	}
?>
</body>
</html>