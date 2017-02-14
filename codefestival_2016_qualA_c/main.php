<?php
fscanf(STDIN, '%s', $str);
fscanf(STDIN, '%d', $num);

$asciiA = ord('a');
$asciiZ = ord('z');

$result = '';
$len = strlen($str);
foreach (str_split($str) as $key => $char) {
	if ($key + 1 !== $len) {
		if ($char !== 'a' && $num > $asciiZ - ord($char)) {
			$num -= $asciiZ - ord($char) + 1;
			$char = 'a';
		}
	} else {
		$char = chr($asciiA + (ord($char) - $asciiA + $num)%($asciiZ - $asciiA + 1));
	}
	$result .= $char;
}

echo $result.PHP_EOL;
