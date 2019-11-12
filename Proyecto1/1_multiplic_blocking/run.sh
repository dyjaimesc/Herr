#!/bin/bash
let N=1
touch entrada.txt
touch salida.txt
sed "3d" entrada.txt > salida.txt
for i in {4..7}
do
    echo $((N))>>entrada.txt
    make
    cat out.txt>>salida.txt
    N=$((N*2))
    rm -r entrada.txt
done

cat <<EOF> plot1.gp


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

EOF
gnuplot plot1.gp
