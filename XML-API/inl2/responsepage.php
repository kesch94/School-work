<!DOCTYPE html>
    <html>
        <head>
            <title>PHP FORM</title>
            <style>
		table{
			border-collapse: collapse;
            width: 100%;
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
            <table style='border: 2px solid black'>
            <?php
            $trucks=Array(
                Array("KrAZ","Kremenchuk","Ukraine",
                      Array(
                          Array("KrAZ-65055","6x6","330Hp"),
                          Array("KrAZ-6130C4","6x6","330Hp"),
                          Array("KrAZ-5133H2","4x2","330Hp"),
                          Array("KrAZ-7140H6","8x6","400Hp")
                      )),
                Array("EBIAM","Thessaloniki","Greece",
                      Array(
                          Array("EBIAM MVM","4x4","86Hp")
                      )),
                Array("KaMAZ","Naberezhnye Chelny","Tatarstan",
                      Array(
                          Array("KAMAZ 54115","6x4","240Hp"),
                          Array("KAMAZ 6560","8x8","400Hp"),
                          Array("KAMAZ 5460","8x8","340Hp")
                      )),
                Array("LIAZ","Rynovice","Czechoslovakia",Array(
                    Array("LIAZ 706 RT","2x4","160Hp")
                )),
                Array("IRUM","Brasov","Romania",
                      Array(
                          Array("TAF 690","2x4","90Hp")
                      )),
                Array("MAZ","Minsk","Belarus",
                      Array(
                          Array("MAZ 535","8x8","375Hp"),
                          Array("MAZ 7310","8x8","525Hp"),
                          Array("MAZ 7907","4x12","1250Hp"),
                          Array("MAZ 6317","6x6","425Hp"),
                          Array("MAZ 6430","6x6","360Hp"),
                          Array("MAZ 5551","4x2","160Hp")
                      )),
                Array("BelAz","Zohodino","Belarus",
                      Array(
                          Array("Belaz 75600","4x4","3400Hp")
                      )),
                Array("Oshkosh","Oshkosh","USA",
                      Array(
                          Array("Oshkosh P-15","8x8","840Hp"),
                          Array("Oshkosh MK-36","6x6","425Hp")
                      )),
                Array("Tatra","Koprivnice","Czechoslovakia",
                      Array(
                          Array("Tatra T 813","4x4","266Hp"),
                          Array("Tatra T 815","10x10","436Hp"),
                      ))
            );

    if(isset($_POST['country']))
    {
        $incountry=$_POST['country']; 
    }
    else
    {
        $incountry="Empty selection";
    } 

    echo "<div style='font-size: 20px;'>" .$incountry."</div>";
    echo "<tr style='background: grey;'><th style='border: 1px solid black';>Producer</th><th style='border: 1px solid black';>City</th><th style='border: 1px solid black';>Country</th><th colspan='6' style='border: 1px solid black'>Variations</th>";
    foreach($trucks as $country)
    {
        if($country[2]==$incountry)
        {
            echo "<tr style='background: silver;'>";
            echo "<td style='border: 1px solid black';>".$country[0]."</td>";
            echo "<td style='border: 1px solid black';>".$country[1]."</td>";
            echo "<td style='border: 1px solid black';>".$country[2]."</td>";
                echo "<td style='border: 1px solid black';>";
                echo "<table>";
                echo "<tr><th>Name</th><td></tr>";
                echo "<tr><th>Wheel</th><td></tr>";
                echo "<tr><th>Hp</th></tr>";
                echo "</table>";
                echo "</td>";
            foreach($country [3] as $model)
            {
                echo "<td style='border: 1px solid black;'>";
                echo "<table>";
                echo "<tr><td>".$model[0]."</td></tr>";
                echo "<tr><td>".$model[1]."</td></tr>";
                echo "<tr><td>".$model[2]."</td></tr>";
                echo "</table>";
                echo "</td>";
            } 
        echo "</tr>";  
        }
    }; 
    ?>
            </table>
            </pre>
        </body>
    </html>