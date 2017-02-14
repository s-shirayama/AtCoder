<?php

fscanf(STDIN, '%d', $N);
$A = trim(fgets(STDIN));
$A = explode(' ', $A);

$l = 1;
$h = 2 * $N - 1;
while ($l + 1 < $h) {
	$m = floor(($l + $h) / 2);
	$b = [];
	for ($i = 0; $i < 2 * $N - 1; $i++) {
		$b[] = ($A[$i] >= $m) ? 1 : 0;
	}
	$c = $b[0];
	for ($i = 0; $i < $N - 1; $i++) {
		if ($b[$N - $i - 1] === $b[$N - $i - 2]) {
			$c = $b[$N - $i - 1];
			break;
		}
		if ($b[$N + $i - 1] === $b[$N + $i]) {
			$c = $b[$N + $i - 1];
			break;
		}
	}
	if ($c === 1) {
		$l = $m;
	} else {
		$h = $m;
	}
}
echo $l . PHP_EOL;

/*
function median ($i1, $i2, $i3) {
	if ($i1 <= $i2 && $i2 <= $i3) {
		return $i2;
	} else if ($i1 <= $i3 && $i3 <= $i2) {
		return $i3;
	} else {
		return $i1;
	}
}

function _next($arr) {
	$result = [];
	for ($i = 0; $i < count($arr) - 2; $i++) {
		$result[] = median($arr[$i], $arr[$i+1], $arr[$i+2]);
	}
	return $result;
}

while (--$N) {
	$A = _next($A);
}
echo $A[0] . PHP_EOL;
*/

