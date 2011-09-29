--TEST--
Test the num_processors_configured function
--FILE--
<?php

echo "Configured processors: ",num_processors_configured(),PHP_EOL;
--EXPECTF--
Configured processors: %d