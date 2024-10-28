<html>

<head>
    <link rel="icon" type="png" href="pictures/worm.png">
</head>

<body>
<link href="style.css" rel="stylesheet" type="text/css" />

<?php
$size = (int) $_POST["size"];
$table = [" "];
echo "<table border='1'\n>";
echo "<tr>\n";
echo "<th>X</th>\n";
for ($i = 1; $i <= $size; $i++) {
    echo "<th>$i</th>\n";
}
$row = 1;
for ($i = 1; $i <= $size; $i++) {
    echo "<tr>\n";
    echo "<th>$row</th>\n";
    for ($j = 1; $j <= $size; $j++) {
        echo "<td>" . $i * $j . "</td>\n";
    }
    $row += 1;
    echo "</tr>\n";
}

echo "</tr\n>";

?><br>
</body>
</html>