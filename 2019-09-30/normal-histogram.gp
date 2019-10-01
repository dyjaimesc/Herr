set term pdf
set output "normal-histogram.pdf"
set xlabel "random numbers"
set ylabel "N"
plot [][0:] "normal-histogram.txt" w lp ps 0.5