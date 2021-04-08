<html>
<meta charset="utf-8">
  <body>
  	<table border="1">
  		<pre>
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

		    echo "<h1>Truck database</h1>";
		    echo "<form method='post' action='assignment3.php'>";
			echo "<select name='country'>";

			$url="https://wwwlab.iit.his.se/gush/XMLAPI/vehiclesservice/manufacturer/".$manufacturer;
			$jsontext = file_get_contents($url);
			$arr = json_decode($jsontext);

			echo "<option>Choose manufacturer";

			foreach($arr as $manufacturer){
			echo "<option value='".$manufacturer[1]."' >".$manufacturer[0]."</option>";	
			}

			echo "</select>";
			echo "<button>Visa resultat!</button>";
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
					echo "<tr><th>Model:</th></tr>";
					echo "<tr><th>Drive shafts:</th></tr>";
					echo "<tr><th>Horsepowers:</th></tr>";
					echo "</table>";
					echo "</td>";

					foreach($manufacturer as $model){
						echo "<td>";
						echo "<table>";
						echo "<tr><td>" .$model[0]."</td></tr>";
						echo "<tr><td>" .$model[1]."</td></tr>";
						echo "<tr><td>" .$model[2]."</td></tr>";
						echo "</table>";
						echo "</td>";
					}
				}
			
    		?>
    		</pre>
   		</table>
	</body>
</html>