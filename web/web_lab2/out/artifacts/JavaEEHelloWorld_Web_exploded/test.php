<?php
//запомнили время до выполнения
$start_time = microtime();
$r = $_GET['r'];
$x = $_GET['x'];
$y = $_GET['y'];
$out = "";
$maximum = 17;
$flag = true;
$response = "";

//провека на присутсвие данных
if ($_SERVER['REQUEST_METHOD'] === 'GET') {
    if (!preg_match('/^-?\d+(\.|,)?\d*$/', $r) ||
        !preg_match('/^-?\d+(\.|,)?\d*$/', $x) ||
        !preg_match('/^-?\d+(\.|,)?\d*$/', $y))
        $flag = false;

    //валидация принятых данных
    if ($x < -2 || $x > 2)
        $flag = false;
    if ($r < 1 || $r > 3)
        $flag = false;
    if ($y < -5 || $y > 5)
        $flag = false;
    if (strlen($y) > $maximum || strlen($x) > $maximum || strlen($r) > $maximum)
        $flag = false;

    //провекра на вхождение в область
    if ((($x * $x + $y * $y) <= $r * $r / 4 && $x >= 0 && $y <= 0) ||
        ($y + 2 * $x <= $r && $x >= 0 && $y >= 0) ||
        ($x <= 0 && $y <= 0 && $x >= (-1) * $r / 2 && $y >= (-1) * $r)) {
        $out = "Входит";
    } else {
        $out = "Не входит";
    }

    $response .= $flag;
    $response .= ";";
    $response .= $x;
    $response .= ";";
    $response .= $y;
    $response .= ";";
    $response .= $r;
    $response .= ";";
    $response .= $out;
    $response .= ";";
    $response .= date("Y-m-d H:i:s");
    $response .= ";";
    $response .= microtime() - $start_time;
    $response .= "/";
    echo $response;

}
