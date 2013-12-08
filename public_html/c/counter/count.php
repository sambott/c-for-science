<?php

		$cfile = htmlspecialchars($_GET["page"]) . '.txt';

	if (file_exists($cfile)) 
	{
		$fil = fopen($cfile, r);
		$dat = fread($fil, filesize($cfile)); 
		echo 'document.write(\'' . ($dat+1) . '\')';
		fclose($fil);
		$fil = fopen($cfile, w);
		fwrite($fil, $dat+1);
	}

	else
	{
		$fil = fopen($cfile, w);
		fwrite($fil, 1);
		echo 'document.write(\'1\')';
		fclose($fil);
	}
?>