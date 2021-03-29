<html>                                                                                                                                                
<body>                                                                                                                                                
<table border='1'>                                                                                                                                                 
<?php                                                                                                                                                 
 
    $arr=array(
      array("Sweden",10,array(array("Stockholm",962),
                              array("Gothenburg",572))),
      array("France",67,array(array("Paris",2200),
                              array("Lyon",513),
                              array("Toulouse",458),
                              array("Lille",235))),
      array("Spain",46,array(array("Madrid",3180),
                             array("Barcelona",1600),
                             array("Seville",690))),
      array("Norway",5,array(array("Oslo",650)))
    );
      
    echo "<tr><th>Country</th><th>Population</th><th colspan='4'>Cities</th></tr>";
    foreach ($arr as $country) {
        echo "<tr>";
        echo "<td>".$country[0]."</td>";
        echo "<td>".$country[1]."</td>";
        foreach($country[2] as $city){
            echo "<td>";
            echo "<table>";
            echo "<tr><td>".$city[0]."</td></tr>";  
            echo "<tr><td>".$city[1]."</td></tr>";
            echo "</table>";
            echo "</td>";
        }
        echo "</tr>";
    }
 
?>                                                                                                                                                    
</table>                                                                                                                                                
</body>                                                                                                                                               
</html>