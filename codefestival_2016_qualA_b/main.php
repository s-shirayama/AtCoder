<?php
fscanf(STDIN, '%d', $num);
$numbers = explode(' ', trim(fgets(STDIN)));

$likes = array();
$cnt = 0;
foreach ($numbers as $key => $val) {
    $key++;
    if (isset($likes[$val]) && $likes[$val] == $key) $cnt++;
    $likes[$key] = $val;
}

echo $cnt.PHP_EOL;