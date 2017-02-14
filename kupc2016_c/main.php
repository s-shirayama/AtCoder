<?php
fscanf(STDIN,'%d',$T);
while($T--){
	fscanf(STDIN,'%d %d',$N,$D);
	if($N%2==0)$D^=127;
	echo($D+--$N*127)."\n";
}