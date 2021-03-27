<html>
<head>
	<title>PHP 2</title>
	<style>
		#cont{
			width: 40%;
		}
		
		.outer{
			width: 100%;
		}
		
		.outer:hover{
			border: 1px solid green;
			font-weight: bold;
		}
		
		.inner{
			width: 100%;
		}
		
		.inner tr:hover{
			font-weight: bold;
			background-color: antiquewhite;
		}
		
		th{
			color: black;
			background-color: lightblue;
		}
		
		table, td, th{
			border: 1px solid white;
		}
				
		#display{
			width:40%;
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
	
function form($truck){
	// Sållar ut dubbletter av landsnamn
	for ($i=0; $i<8; $i++){
		$arr[$i]=$truck[$i][2];
	}	
	$unik_arr=array_unique($arr);		
	echo "<form action='index.php' method='post'>";
	echo "<select name='choise'>";
	echo "<option value='none'>None</option>";
	// Tar fram länder som options
	foreach ($unik_arr as $opt){
		echo "<option value='".$opt."'";
		if(isset($_POST['choise'])){
			// Om land är valt - selected
			if($_POST['choise']==$opt){
			echo "selected";
			}
		}
		echo ">".$opt."</option>";
	}
	echo "</select>";
	echo "<button>Show</button>";
	echo "</form>";
}
	
function show($truck){
	// Visar table, om val gjorts
	if(isset($_POST['choise'])){		
		$selection=$_POST['choise'];
		if($selection!='none'){	
			echo "<div id='display'>";
			echo "<h1>Producers and vehicles from ".$selection."</h1>";		
			echo "</div>";
			foreach ($truck as $prod){
				if($prod[2]==$selection){
					echo "<div id='cont'>";
					echo "<table class='outer'>";
					echo "<tr><th>Producer</th><th>Variations</th></tr>";
					echo "<tr>";
					echo "<td>".$prod[0]."</td>";
					echo "<td>";
					echo "<table class='inner'>";
					echo "<tr><th>Name</th><th>Drive</th><th>HP</th></tr>";
					foreach($prod[3] as $variant){
						echo "<tr>";
						echo "<td>".$variant[0]."</td>";
						echo "<td>".$variant[1]."</td>";
						echo "<td>".$variant[2]."</td>";
						echo "</tr>";
					}
					echo "</table>";
					echo "</td>";
					echo "</table>";
					echo "</div>";
				}
			}
		}
		else{
		echo "<div id='display'>";
		echo "<h1>No country selected</h1>";
		echo "</div>";		
		}
	}
	else{
		echo "<div id='display'>";
		echo "<h1>Select a country to display vehicles</h1>";
		echo "</div>";		
	}
}

	echo form($truck);
	echo show($truck);
?>
</pre>
</body>
</html>