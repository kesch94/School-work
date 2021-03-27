<html>
<head>
	<style>
		table{
			border-collapse: collapse;
		}
		
		th{
			color: white;
			background-color: black;
		}
		
		table, td, th{
			border: 1px solid black;
		}
	</style>
</head>
<body>
<pre>
<?php
	$truck=Array(
		Array("KrAZ","Kremenchuk","Ukraine",Array(
			Array("KrAZ-65055","6x6","330Hp"),
			Array("KrAZ-6130C4","6x6","330Hp"),
			Array("KrAZ-5133H2","4x2","330Hp"),
			Array("KrAZ-7140H6","8x6","400Hp")
		)),
		Array("EBIAM","Thessaloniki","Greece",Array(
			Array("EBIAM MVM","4x4","86Hp")
		)),
		Array("KaMAZ","Naberezhnye Chelny","Tatarstan",Array(
			Array("KAMAZ 54115","6x4","240Hp"),
			Array("KAMAZ 6560","8x8","400Hp"),
			Array("KAMAZ 5460","8x8","340Hp")
		)),
		Array("LIAZ","Rynovice","Czechoslovakia",Array(
			Array("LIAZ 706 RT","2x4","160Hp")
		)),
		Array("IRUM","Brasov","Romania",Array(
			Array("TAF 690","2x4","90Hp")
		)),
		Array("MAZ","Minsk","Belarus",Array(
			Array("MAZ 535","8x8","375Hp"),
			Array("MAZ 7310","8x8","525Hp"),
			Array("MAZ 7907","4x12","1250Hp"),
			Array("MAZ 6317","6x6","425Hp"),
			Array("MAZ 6430","6x6","360Hp"),
			Array("MAZ 5551","4x2","160Hp")
		)),
		Array("BelAz","Zohodino","Belarus",Array(
			Array("Belaz 75600","4x4","3400Hp")
		)),
		Array("Oshkosh","Oshkosh","USA",Array(
			Array("Oshkosh P-15","8x8","840Hp"),
			Array("Oshkosh MK-36","6x6","425Hp")
		)),
		Array("Tatra","Koprivnice","Czechoslovakia",Array(
			Array("Tatra T 813","4x4","266Hp"),
			Array("Tatra T 815","10x10","436Hp"),
		))
	);
	echo "<table>";
	echo "<tr><th>Producer</th><th>City</th><th>Country</th><th>Variations</th></tr>";
	foreach($truck as $type){
		if($type[2]=="Belarus"){
			echo "<tr style='background:yellow'>";
		}
		else{
			echo "<tr style='background:lightblue'>";
		}
		echo "<td>".$type[0]."</td>";
		echo "<td>".$type[1]."</td>";
		echo "<td>".$type[2]."</td>";
		echo "<td>";
		echo "<table width='100%'>";
		echo "<tr><th>Name</th><th>Drive</th><th>HP</th></tr>";
		foreach($type[3] as $variant){
			echo "<tr>";
			echo "<td>".$variant[0]."</td>";
			echo "<td>".$variant[1]."</td>";
			echo "<td>".$variant[2]."</td>";
			echo "</tr>";
		}
		echo "</table>";
		echo "</tr>";
	}
	echo "</table>";
?>
</pre>
</body>
</html>