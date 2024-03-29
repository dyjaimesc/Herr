#!/bin/bash
pwd
name="random_walk_3d"
VAR=0.05
Name_walk="Walk"

g++ -std=c++17 -Wall -g -fsanitize=address -fsanitize=leak -fsanitize=undefined  $name.cpp -o $name.x
./$name.x > $name.txt



cat <<EOF> $name.gp


set term pdf
set output "Rand_walk_vs_steps.pdf"
set xlabel "x"
set ylabel "y"
set grid
#set xtics 50
#set ytics 250
#set mxtics 2
#set mytics 2
#set logscale x 2
#set key left top box
#unset key
splot [][] "$name.txt" u 3:4:5 title "$Name_walk 1" w lp ps $VAR lt rgb "red" pointtype 7, \
     	  "$name.txt" u 6:7:8  title "$Name_walk 2" w lp ps $VAR lt rgb "blue" pointtype 7, \
	  "$name.txt" u 9:10:11  title "$Name_walk 3" w lp ps $VAR lt rgb "green" pointtype 7

set term pdf
set output "Mean_Rand_walk_vs_steps.pdf"
set xlabel "Steps"
set ylabel "<x^2>"
set grid
#set xtics 50
#set ytics 250
#set mxtics 2
#set mytics 2
#set logscale x 2
set key right bottom box
plot [][] "$name.txt" u 1:2 w lp ps $VAR lt rgb "red" pointtype 7
replot x w lp ps $VAR lt rgb "blue" pointtype 7


EOF
gnuplot $name.gp

okular Rand_walk_vs_steps.pdf &
okular Mean_Rand_walk_vs_steps.pdf &

