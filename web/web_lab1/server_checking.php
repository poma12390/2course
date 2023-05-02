<?php
    $start_time = microtime();
    $r = $_GET['r'];
    $y = $_GET['x'];
    $x = $_GET['y'];
    $out = "";
    $flag = true;
    $response = "";

    if ($_SERVER['REQUEST_METHOD'] === 'GET') {
        if (!preg_match('/^-?\d+(\.|,)?\d*$/', $r) ||
            !preg_match('/^-?\d+(\.|,)?\d*$/', $x) ||
            !preg_match('/^-?\d+(\.|,)?\d*$/', $y))
            $flag = false;

        if ($x < -3 || $x > 5)
            $flag = false;
        if ($r < 1 || $r > 5)
            $flag = false;
        if ($y < -5 || $y > 5)
            $flag = false;
        if (($y<=$r and $y>=0 and $x>=0 and $x<=$r/2) or ($x<=0 and $x>=$y-$r/2 and $y<=$r/2 and $y>=0)or ($x>=0 and $y<=0 and $x*$x+$y*$y<=$r*$r/4)) {
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
        $response .= number_format(microtime() - $start_time, 6,'.', '');
        $response .= ";";
        $response .= date("Y-m-d H:i:s");
        $response .= "/";
        echo $response;

    }
