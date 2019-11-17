#!/bin/bash
let N=1
touch entrada.dat
touch transpuesta_blocking_o0.dat
touch transpuesta_blocking_o3.dat
sed "3d" entrada.dat > transpuesta_blocking_o0.dat
sed "3d" entrada.dat > transpuesta_blocking_o3.dat
for i in {1..7}
do
    echo $((N))
    echo $((N))>>entrada.dat # introduzco valor del bloque
    make -f Make_transpuesta_blocking_o0
    cat transpuesta_blocking.dat>>transpuesta_blocking_o0.dat
    make -f Make_transpuesta_blocking_o3
    cat transpuesta_blocking3.dat>>transpuesta_blocking_o3.dat
    N=$((N*2))
    rm -r entrada.dat
done

cat <<EOF> plot2.gp


set term pdf
set output "Transpuesta-MFLOPS_VS_NB-o0.pdf"
set xlabel "N_b"
set ylabel "MFLOPS"
set grid
#set xtics 50
#set ytics 250
#set mxtics 2
#set mytics 2
set logscale x 2
plot [][] "transpuesta_blocking_o0.dat" u 1:5 w lp ps 0.5 lt rgb "red" pointtype 7


set term pdf
set output "Trasnpuesta-tiempo_VS_NB-o0.pdf"
set xlabel "N_b"
set ylabel "tiempo(s)"
set grid
set xtics 50
#set ytics 250
#set mxtics 2
#set mytics 2
#set logscale x 2
plot [][] "transpuesta_blocking_o0.dat" u 1:2 w lp ps 0.5 lt rgb "red" pointtype 7

set term pdf
set output "Transpuesta-MFLOPS_VS_NB-o3.pdf"
set xlabel "N_b"
set ylabel "MFLOPS"
set grid
set xtics 50
#set ytics 250
#set mxtics 2
#set mytics 2
#set logscale x 2
plot [][] "transpuesta_blocking_o3.dat" u 1:5 w lp ps 0.5 lt rgb "red" pointtype 7


set term pdf
set output "Trasnpuesta-tiempo_VS_NB-o3.pdf"
set xlabel "N_b"
set ylabel "tiempo(s)"
set grid
set xtics 50
#set ytics 250
#set mxtics 2
#set mytics 2
#set logscale x 2
plot [][] "transpuesta_blocking_o3.dat" u 1:2 w lp ps 0.5 lt rgb "red" pointtype 7

EOF
gnuplot plot2.gp
