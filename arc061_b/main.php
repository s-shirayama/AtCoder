<?php

fscanf(STDIN, '%d %d %d', $h, $w, $n);
$a = array();
$b = array();
for ($i = 0; $i < $n; $i++){
	fscanf(STDIN, '%d %d', $a[$i], $b[$i]);
}
$table = array();

$results = array_fill(0, 10, 0);
$results[0] = ($h - 2) * ($w - 2);

for ($i = 0; $i < $n; $i++) {
	for ($j = max($a[$i] - 1, 2); $j <= min($a[$i] + 1, $h - 1); $j++) {
		for ($k = max($b[$i] - 1, 2); $k <= min($b[$i] + 1, $w - 1); $k++) {
            if (isset($table[$j])) {
            	if (!isset($table[$j][$k])) {
                    $table[$j][$k] = 0;
                }

            } else {
            	$tmp = array();
            	$tmp[$k] = 0;
            	$table[$j] = $tmp;
            }
			$results[$table[$j][$k]]--;
			$results[++$table[$j][$k]]++;
		}
	}
}
echo implode(PHP_EOL, $results).PHP_EOL;
