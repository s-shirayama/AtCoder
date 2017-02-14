<?php
fscanf(STDIN, '%d', $N);
$s = ['.', '#'];
$r1 = '';
$r2 = '';
$right = true;
while ($N) {
	$idx = 0;
	while ($idx < 4) {
		$_r1 = ($right) ? $r1.$s[floor($idx/2)] : $s[floor($idx/2)].$r1;
		$_r2 = ($right) ? $r2.$s[$idx%2] : $s[$idx%2].$r2;
		echo $_r1."\n".$_r2."\n";
		fscanf(STDIN, '%s', $R);
		if ($R === 'T') {
			$r1 = $_r1;
			$r2 = $_r2;
			break;
		}
		$idx++;
	}
	if ($idx === 4) {
		$right = !$right;
	} else {
		$N--;
	}
}
