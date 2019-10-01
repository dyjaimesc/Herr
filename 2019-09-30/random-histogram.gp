set term pdf
set output "random_histogram.pdf"
set xlabel "random numbers"
set ylabel "N"
plot [][0.9:1.1] "random-histogram.txt" w p