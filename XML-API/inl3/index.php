<html>
<head>
	<title>PHP 3</title>
	<style>
		#cont{
			display: flex;
			flex-wrap: wrap;
		}
		
		form{
			margin-left: 10px;
		}
		
		.list{
			border-collapse: collapse;
			width: 300px;
		}
		
		.list tr{
			font-size: 14px;
		}
		
		.list tr:hover{
			background-color: #ddd;
		}
		
		.list th{
			padding-bottom: 10px;
			background-color: #4CAF50;
			color: white;
			text-align: left;
			font-size: 16px;
		}
		
		.list td{
			border: 1px solid #ddd;
		}
		
	</style>
</head>
<body>
<pre>
<?php
	$url_man="https://wwwlab.iit.his.se/gush/XMLAPI/vehiclesservice/manufacturer/";
	$jsontext=file_get_contents($url_man);
	$man= json_decode($jsontext);
	
	echo "<h1>Select manufacturer to display all vehicles from country</h1>";	
	echo "<div id='cont'>";
	echo "<div>";
	echo "<table class='list'>";
	echo "<tr><th>Producer</th><th>Country</th></tr>";
	foreach($man as $disp){
		echo "<tr>";		
		echo "<td>".$disp[0]."</td>";
		echo "<td>".$disp[1]."</td>";
		echo "</tr>";
	}
	echo "</table>";
	echo "</div>";
	
	echo "<div>";
	echo "<form action='resp.php' method='post'>";
	echo "<select name='choise'>";
	echo "<option value='none'>None</option>";
	foreach ($man as $opt){
		echo "<option value='".$opt[1]."'>".$opt[0]."</option>";
	}
	echo "</select>";
	echo "<button>Show</button>";
	echo "</form>";
	echo "</div>";
	echo "</div>";
		
?>
</pre>
</body>
</html>