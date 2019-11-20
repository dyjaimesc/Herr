#!/bin/bash
let N=1
touch entrada.txt
touch salida.txt
sed "3d" entrada.txt > salida.txt
for i in {1..10}
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
set xlabel "N_b"
set ylabel "MFLOPS"
set grid
set logscale x 2
plot [][] "salida.txt" u 1:5 w lp ps 0.5 lt rgb "red" pointtype 7


set term pdf
set output "mult-tiempo_VS_NB-o0.pdf"
set xlabel "N_b"
set ylabel "tiempo(s)"
set grid
set logscale x 2
plot [][] "salida.txt" u 1:2 w lp ps 0.5 lt rgb "red" pointtype 7

EOF
gnuplot plot1.gp
