<?php

fscanf(STDIN, '%s', $number);
$numbers = str_split($number);
for ($i = 0; $i < count($numbers); $i++) {
	$numbers[$i] = (int)$numbers[$i];
}

function sum($_numbers, $_cur = 0) {
    if (count($_numbers) === 0) {
    	return $_cur;
    } else if (count($_numbers) === 1) {
    	return $_cur + $_numbers[0];
    }
    $sum = 0;
    $cur = 0;
    for ($i = 0; $i < count($_numbers); $i++) {
        $cur = $cur * 10 + $_numbers[$i];
        $sum += sum(array_slice($_numbers, $i + 1), $_cur + $cur);
    }
    return $sum;
}

echo sum($numbers).PHP_EOL;
