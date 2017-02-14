<?php

fscanf(STDIN, '%d', $N);
fscanf(STDIN, '%s', $S);
fscanf(STDIN, '%s', $T);
$result = 2 * $N;
for ($i = 0; $i < $N; $i++) {
	$str = substr($S, $i);
	$str2 = substr($T, 0, $N - $i);
	if ($str === $str2) {
		$result = (2 * $N) - ($N - $i);
		break;
	}
}
echo $result . PHP_EOL;
