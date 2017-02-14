<?php
fscanf(STDIN, '%d %d %d', $A, $B, $C);
$result = 0;
$num = [];
foreach ([$A, $B, $C] as $v) {
	if (!isset($num[$v])) {
		$num[$v] = true;
		$result++;
	}
}
echo $result . PHP_EOL;