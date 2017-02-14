<?php
fscanf(STDIN, '%d %d', $N, $K);
$result = min(2147483647, $K * pow($K - 1, $N - 1));
echo $result . PHP_EOL;