<html>
<head>
	<title>PHP 3</title>
	<style>
		.list{
			border-collapse: collapse;
			width: 30%;
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
<a href="index.php">Back</a>
<pre>
<?php
	$selection=$_POST['choise'];
	$url_data="https://wwwlab.iit.his.se/gush/XMLAPI/vehiclesservice/vehicles/?country=".$selection;
	$jsontext=file_get_contents($url_data);
	$country= json_decode($jsontext);
	
	echo "<h1>Vehicles from ".$selection."</h1>";
	echo "<table class='list'>";
	echo "<tr><th>Name</th><th>Drive</th><th>HP</th></tr>";
	foreach($country as $man){
		foreach($man as $veh){
			echo "<tr>";
			echo "<td>".$veh[0]."</td>";
			echo "<td>".$veh[1]."</td>";
			echo "<td>".$veh[2]."</td>";
			echo "</tr>";
		}
	}
	echo "</table>";
?>
</pre>

</body>
</html>