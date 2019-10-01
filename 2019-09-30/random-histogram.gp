set term pdf
set output "random-histogram.pdf"
set xlabel "random numbers"
set ylabel "N"
plot [][0.8:1.2] "random-histogram.txt" w p