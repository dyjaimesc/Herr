set term pdf
set output "Ej_armonica.pdf"
set xlabel "x"
set ylabel "y"
plot "Ej_armonica.txt" u 1:2 w lp ps 0.5