#!/usr/bin/php

<?php 
    $fic = fopen('texte/Bretagne.txt', 'r');
    $ligne = '';

    $ligne = fgets($fic);

    while(!feof($fic)){ 
        if (strpos($ligne, 'DEBUT_TEXTE') !== false) {
            echo "\n";
            while (strpos($ligne, 'FIN_TEXTE') === false) {
                $ligne = fgets($fic);
                if (strpos($ligne, 'FIN_TEXTE') === false) {
                    echo $ligne . '';
                }
            }
        }
        $ligne = fgets($fic);
    }
    fclose($fic);

// strtrouper mettre tout en maj

?>


