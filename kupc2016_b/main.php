<?php
fscanf(STDIN, '%d %d', $N, $K);
$pp = [];
for ($i = 0; $i < $N; $i++) {
	fscanf(STDIN, '%s', $P);
	$pp[substr($P, 0, 1)]++;
}

$result = 0;
while (true) {
	arsort($pp);
	$pp = array_values($pp);
	$idx = 0;
	for ($i = 0; $i < $K; $i++) {
		if ($pp[$idx] > 0) {
			$pp[$idx++]--;
		} else {
			break 2;
		}
	}
	$result++;
}

echo $result . PHP_EOL;
