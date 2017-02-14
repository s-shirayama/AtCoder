<?php
fscanf(STDIN, '%d %d %d', $num, $min, $max);
$res = 0;
for ($i = 0; $i < $num; $i++) {
	fscanf(STDIN, '%d', $t);
	if ($t < $min || $t >= $max) {
		$res++;
	}
}
echo $res.PHP_EOL;
