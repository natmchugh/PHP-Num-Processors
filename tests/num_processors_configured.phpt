--TEST--
Test the num_processors_avaliable function
--FILE--
<?php

echo "Available processors: ",num_processors_available(),PHP_EOL;
--EXPECTF--
Available processors: %d