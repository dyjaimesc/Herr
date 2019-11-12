

set term pdf
set output "mult-MFLOPS_VS_NB-o0.pdf"
set xlabel "NB-o0"
set ylabel "MFLOPS"
plot [][] "salida.txt" u 1:4 w lp ps 0.5


set term pdf
set output "mult-tiempo_VS_NB-o0.pdf"
set xlabel "NB-o0"
set ylabel "tiempo(s)"
plot [][] "salida.txt" u 1:2 w lp ps 0.5

