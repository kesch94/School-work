<?php
	$xslDoc = new DOMDocument();
	$xslDoc->load("xslt_select.xsl");

	$xml = file_get_contents('https://wwwlab.iit.his.se/gush/XMLAPI/articleservice/papers/');
	$xmlDoc = new DomDocument;
	$xmlDoc->preserveWhiteSpace = FALSE;
	$xmlDoc->loadXML($xml);

	$proc = new XSLTProcessor();
	$proc->importStylesheet($xslDoc);
	echo $proc->transformToXML($xmlDoc);
?>     