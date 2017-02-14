<?php
fscanf(STDIN, '%d %d', $N, $X);
$NN = 2 * $N - 1;

if ($X <= 1 || $X >= $NN) {
	echo 'No' . PHP_EOL;
	exit;
}
echo 'Yes' . PHP_EOL;
if ($N === 2) {
	echo implode(PHP_EOL, [1, 2, 3]) . PHP_EOL;
	exit;
} 
$result = [];
if ($X > $N) {
	$result[$N - 1] = 1;
	$result[$N    ] = $X;
	$result[$N + 1] = $NN;
	$result[$N + 2] = 2;
} else {
	$result[$N - 1] = $NN;
	$result[$N    ] = $X;
	$result[$N + 1] = 1;
	$result[$N + 2] = $NN-1;
}
$num = [];
for ($i = 1; $i <= $NN; $i++) {
	$num[$i] = $i;
}
foreach ($result as $v) {
	unset($num[$v]);
}
$idx = 1;
foreach ($num as $v) {
	while (isset($result[$idx])) {
		echo $result[$idx++] . PHP_EOL;
	}
	echo $v . PHP_EOL;
	$idx++;
}
if ($idx < $NN) {
	while (isset($result[$idx])) {
		echo $result[$idx++] . PHP_EOL;
	}
}

