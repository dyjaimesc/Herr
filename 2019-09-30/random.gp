set term pdf
set output "random.pdf"
set xlabel "N"
set ylabel "Valores entre 0 y 1"
plot "random.txt"
