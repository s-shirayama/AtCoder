<?php
fscanf(STDIN, '%d', $N);
$_t = 1;
$_a = 1;
for ($i = 0; $i < $N; $i++) {
	fscanf(STDIN, '%d %d', $T, $A);
	$_ = (int)max(floor($_t / $T), max(1, floor($_a / $A)));
	while ((int)($T * $_) < $_t || (int)($A * $_) < $_a) {
		$_++;
	}
	$_a = (int)($A * $_);
	$_t = (int)($T * $_);
}
echo ($_a + $_t) . PHP_EOL;
/*
fscanf(STDIN, '%d %d', $T, $A);
$_t = $T;
$_a = $A;
while (--$N) {
	fscanf(STDIN, '%d %d', $T, $A);
	if ($_t/$T < $_a/$A) {
		if ($_a % $A === 0) {
			$_ = ($_a/$A);
		} else {
			$_ = (floor($_a/$A) + 1);
		}
	} else {
		if ($_t % $T === 0) {
			$_ = ($_t/$T);
		} else {
			$_ = (floor($_t/$T) + 1);
		}
	}
	$_a = (int)($_ * $A);
	$_t = (int)($_ * $T);
}
echo (int)($_t + $_a) . PHP_EOL;
*/