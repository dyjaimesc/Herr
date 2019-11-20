#!/bin/bash
let N=2
touch entrada.dat
touch multiplicacion_blocking_o0.dat
touch multiplicacion_blocking_o3.dat
touch multiplicacion_eigen_o0.dat
touch multiplicacion_eigen_o3.dat
sed "1d" entrada.dat > multiplicacion_blocking_o0.dat
sed "1d" entrada.dat > multiplicacion_blocking_o3.dat
sed "1d" entrada.dat > multiplicacion_eigen_o0.dat
sed "1d" entrada.dat > multiplicacion_eigen_o3.dat
for i in {1..12}
do
    echo $i $((N));
    echo $((N))>>entrada.dat # introduzco valor del bloque
    make -f Make_multiplicacion_blocking_o0
    cat out.dat>>multiplicacion_blocking_o0.dat
    rm -r out.dat
    make -f Make_multiplicacion_blocking_o3
    cat out.dat>>multiplicacion_blocking_o3.dat
    rm -r out.dat
    make -f Make_multiplicacion_eigen_o0
    cat out.dat>>multiplicacion_eigen_o0.dat
    rm -r out.dat
    make -f Make_multiplicacion_eigen_o3
    cat out.dat>>multiplicacion_eigen_o3.dat
    rm -r out.dat
    
    N=$((N*2))
    rm -r entrada.dat
done

cat <<EOF> plot1.gp


set term pdf
set output "Multiplicacion-tiempo_VS_N-o0.pdf"
set xlabel "N"
set ylabel "Tiempo(s)"
set grid
#set logscale x 2
#set key at 4000,18
plot [][] "multiplicacion_blocking_o0.dat" u 1:2 title "Tiempo de multiplicacion con blocking o0" w lp ps 0.5 lt rgb "red" pointtype 7,         "multiplicacion_eigen_o0.dat" u 1:2 title "Tiempo de multiplicacion con eigen o0"  w lp ps 0.5 lt rgb "blue" pointtype 7


set term pdf
set output "Multiplicacion-tiempo_VS_N-o3.pdf"
set xlabel "N"
set ylabel "Tiempo(s)"
set grid
#set logscale x 2
#set key at 4000,18
plot [][]"multiplicacion_blocking_o3.dat" u 1:2 title "Tiempo de multiplicacion con blocking o3" w lp ps 0.5 lt rgb "red" pointtype 7,         "multiplicacion_eigen_o3.dat" u 1:2 title "Tiempo de multiplicacion con eigen o3"  w lp ps 0.5 lt rgb "blue" pointtype 7

set term pdf
set output "Multiplicacion-MFLOPS_VS_N-o0.pdf"
set xlabel "N"
set ylabel "MFLOPS"
set grid
set ytics nomirror
set y2tics
set tics out
set y2label "KFLOPS"
#set autoscale y
set autoscale y2
#set logscale x 2
#set key at 8000,60
plot [][] "multiplicacion_blocking_o0.dat" u 1:5 title "MFlops de multiplicacion con  blocking o0" w lp ps 0.5 lt rgb "red" pointtype 7,         "multiplicacion_eigen_o0.dat" u 1:(1000*\$5) title "MFlops de multiplicacion con  eigen o0"  w lp ps 0.5 lt rgb "blue" pointtype 7


set term pdf
set output "Multiplicacion-MFLOPS_VS_N-o3.pdf"
set xlabel "N"
set ylabel "MFLOPS"
set grid
set ytics nomirror
set y2tics
set tics out
set y2label "KFLOPS"
#set autoscale y
set autoscale y2
#set logscale x 2
#set key at 8000,60
plot [][]  "multiplicacion_blocking_o3.dat" u 1:5 title "MFlops de multiplicacion con blocking o3" w lp ps 0.5 lt rgb "red" pointtype 7,         "multiplicacion_eigen_o3.dat" u 1:(1000*\$5) title "MFlops de multiplicacion con  eigen o3"  w lp ps 0.5 lt rgb "blue" pointtype 7

EOF
gnuplot plot1.gp
