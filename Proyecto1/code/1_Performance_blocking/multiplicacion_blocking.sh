#!/bin/bash
let N=1
touch entrada.dat
touch  Block_multi_o0.dat
touch  Block_multi_o3.dat
sed "3d" entrada.dat > Block_multi_o0.dat
sed "3d" entrada.dat > Block_multi_o3.dat
for i in {1..7}
do
    echo $((N))>>entrada.dat # introduzco valor del bloque
    make -f Make_Block_multi_o0
    cat out.dat>>Block_multi_o0.dat
    make -f Make_Block_multi_o3
    cat out3.dat>>Block_multi_o3.dat
    N=$((N*2))
    rm -r entrada.dat
done

cat <<EOF> plot1.gp


set term pdf
set output "mult-MFLOPS_VS_NB-o0.pdf"
set xlabel "N_b"
set ylabel "MFLOPS"
set grid
#set xtics 50
#set ytics 250
#set mxtics 2
#set mytics 2
set logscale x 2
plot [][] "Block_multi_o0.dat" u 1:5 w lp ps 0.5 lt rgb "red" pointtype 7


set term pdf
set output "mult-tiempo_VS_NB-o0.pdf"
set xlabel "N_b"
set ylabel "tiempo(s)"
set grid
#set xtics 50
#set ytics 250
#set mxtics 2
#set mytics 2
#set logscale x 2
plot [][] "Block_multi_o0.dat" u 1:2 w lp ps 0.5 lt rgb "red" pointtype 7



set term pdf
set output "mult-MFLOPS_VS_NB-o3.pdf"
set xlabel "N_b"
set ylabel "MFLOPS"
set grid
#set xtics 50
#set ytics 250
#set mxtics 2
#set mytics 2
set logscale x 2
plot [][] "Block_multi_o3.dat" u 1:5 w lp ps 0.5 lt rgb "red" pointtype 7


set term pdf
set output "mult-tiempo_VS_NB-o3.pdf"
set xlabel "N_b"
set ylabel "tiempo(s)"
set grid
#set xtics 50
#set ytics 250
#set mxtics 2
#set mytics 2
#set logscale x 2
plot [][] "Block_multi_o3.dat" u 1:2 w lp ps 0.5 lt rgb "red" pointtype 7




EOF
gnuplot plot1.gp
