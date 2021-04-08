<html>
<meta charset="utf-8">
  <body>
  	<table border="1">
  		<pre>
		  	<title>PHP WEB SERVICE</title>
	  		<style type="text/css">
		  		button, select {
		  			height: 30px;
		  			width: 100px;
		  			margin-left: 17px;
		  		}
		  		button:hover {
		  			background-color: grey;
		  			color: white;
		  		}
		  		tr, td, th  {
		  			padding-right: 5px;
		  			padding-left: 5px;
		  		}
		  		thead {
		  			background-color: lightgrey;
		  		}
		  		h1 {
		  			margin-left: 17px; 
		  		}
	  		</style>
		    <?php

		    echo "<h1>Database Trucks</h1>";
		    echo "<form method='post' action='Assignment3.php'>";
			echo "<select name='country'>";

			$url="https://wwwlab.iit.his.se/gush/XMLAPI/vehiclesservice/manufacturer/".$manufacturer;
			$jsontext = file_get_contents($url);
			$arr = json_decode($jsontext);

			echo "<option>Select";

			foreach($arr as $manufacturer){
			echo "<option value='".$manufacturer[1]."'>".$manufacturer[0]."</option>";	
			}

			echo "</select>";
			echo "<button>Search!</button>";
			echo "</form>";

			if(isset($_POST['country'])){
				$country = $_POST['country'];
			}

			else{
				$country = "";
			}

		    $url="https://wwwlab.iit.his.se/gush/XMLAPI/vehiclesservice/vehicles/?country=".$country;  
			$jsontext = file_get_contents($url);
		    $arr = json_decode($jsontext); 

		    	echo  "<tr><th colspan='10'>".$country. "</th> </tr>";

				foreach($arr as $manufacturer){
					echo "<td>";
					echo "<table>";
					echo "<tr><th>Name:</th></tr>";
					echo "<tr><th>Wheel:</th></tr>";
					echo "<tr><th>HP:</th></tr>";
					echo "</table>";
					echo "</td>";

					foreach($manufacturer as $variant){
						echo "<td>";
						echo "<table>";
						echo "<tr><td>" .$variant[0]."</td></tr>";
						echo "<tr><td>" .$variant[1]."</td></tr>";
						echo "<tr><td>" .$variant[2]."</td></tr>";
						echo "</table>";
						echo "</td>";
					}
				}
			$url="https://wwwlab.iit.his.se/gush/XMLAPI/vehiclesservice/vehicles/";
			$jsontext = file_get_contents($url);
			$arr = json_decode($jsontext);

    		?>
    		</pre>
   		</table>
	</body>
</html>