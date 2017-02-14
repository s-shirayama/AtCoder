<?php
fscanf(STDIN, '%d %d', $H, $W);
$masu = array_pad([], $H, array_pad([], $W, 0));

$result = 0;
for ($i = 0; $i < $H; $i++) {
	fscanf(STDIN, '%s', $S);
	$S = str_split($S);
	for ($j = 0; $j < $W; $j++) {
		if ($S[$j] === 'X') {
			if ($i === 0 || $i === $H - 1 || $j === 0 || $j === $W - 1) {
				$result = -1;
			}
			$masu[$i][$j] = 1;
			if ($masu[$i-1][$j] === 0) $masu[$i-1][$j] = 2;
			if ($masu[$i][$j-1] === 0) $masu[$i][$j-1] = 2;
			if ($masu[$i+1][$j] === 0) $masu[$i+1][$j] = 2;
			if ($masu[$i][$j+1] === 0) $masu[$i][$j+1] = 2;
		}
	}
}
if ($result === -1) {
	echo $result.PHP_EOL;
	exit;
}
for ($i = 0; $i < $H; $i++) {
	for ($j = 0; $j < $W; $j++) {
		if ($masu[$i][$j] === 2) {
			$q = [[$i, $j]];
			$first = true;
			$chk = array_pad([], $H, array_pad([], $W, false));
			while (count($q) > 0) {
				$t = array_shift($q);
				$_i = $t[0];
				$_j = $t[1];
				if (!$first && $masu[$_i][$_j] > 0) continue;
				$first = false;
				if ($_i === 0 || $_i === $H - 1 || $_j === 0 || $_j === $W - 1) {
					$result++;
					break;
				}
				if (!$chk[$_i-1][$_j]) {
					$chk[$_i-1][$_j] = true;
					array_push($q, [$_i-1, $_j]);
				}
				if (!$chk[$_i][$_j-1]) {
					$chk[$_i][$_j-1] = true;
					array_push($q, [$_i, $_j-1]);
				}
				if (!$chk[$_i+1][$_j]) {
					$chk[$_i+1][$_j] = true;
					array_push($q, [$_i+1, $_j]);
				}
				if (!$chk[$_i][$_j+1]) {
					$chk[$_i][$_j+1] = true;
					array_push($q, [$_i, $_j+1]);
				}
			}
		}
	}
}
echo $result.PHP_EOL;
