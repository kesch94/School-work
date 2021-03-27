<style>
@import url('https://fonts.googleapis.com/css2?family=Chelsea+Market&display=swap');
</style>
<?php
	if (isset($_POST['paper'])){
		$type=$_POST['paper'];

		$xslDoc = new DOMDocument();
		$xslDoc->load("xslt_response.xsl");
		$xml = file_get_contents('https://wwwlab.iit.his.se/gush/XMLAPI/articleservice/articles/?paper='.$type);
		$xmlDoc = new DomDocument;
		$xmlDoc->preserveWhiteSpace = FALSE;
		$xmlDoc->loadXML($xml);

		$proc = new XSLTProcessor();
		$proc->importStylesheet($xslDoc);
		echo $proc->transformToXML($xmlDoc);
	}
	else{
	echo "<a href='form.php'>Back</a>";
	}
?>    