

set term pdf
set output "Transpuesta-tiempo_VS_N-o0.pdf"
set xlabel "N"
set ylabel "Tiempo(s)"
set grid
#set logscale x 2
set key at 4000,18
plot [][] "transpuesta_blocking_o0.dat" u 1:2 title "Transpuesta blocking o0" w lp ps 0.5 lt rgb "red" pointtype 7,\
         "transpuesta_eigen_o0.dat" u 1:2 title "Transpuesta eigen o0"  w lp ps 0.5 lt rgb "blue" pointtype 7


set term pdf
set output "Trasnpuesta-tiempo_VS_N-o3.pdf"
set xlabel "N"
set ylabel "Tiempo(s)"
set grid
#set logscale x 2
set key at 4000,18
plot [][]"transpuesta_blocking_o3.dat" u 1:2 title "Transpuesta blocking o3" w lp ps 0.5 lt rgb "red" pointtype 7,\
         "transpuesta_eigen_o3.dat" u 1:2 title "Transpuesta eigen o3"  w lp ps 0.5 lt rgb "blue" pointtype 7

set term pdf
set output "Transpuesta-MFLOPS_VS_N-o0.pdf"
set xlabel "N"
set ylabel "MFLOPS"
set grid
#set logscale x 2
set key at 8000,60
plot [][] "transpuesta_blocking_o0.dat" u 1:5 title "NFlops: Transpuesta blocking o0" w lp ps 0.5 lt rgb "red" pointtype 7,\
         "transpuesta_eigen_o0.dat" u 1:5 title "NFlops: Transpuesta eigen o0"  w lp ps 0.5 lt rgb "blue" pointtype 7


set term pdf
set output "Trasnpuesta-MFLOPS_VS_NB-o3.pdf"
set xlabel "N"
set ylabel "MFLOPS"
set grid
#set logscale x 2
set key at 8000,60
plot [][]  "transpuesta_blocking_o3.dat" u 1:5 title "NFlops: Transpuesta blocking o3" w lp ps 0.5 lt rgb "red" pointtype 7,\
         "transpuesta_eigen_o3.dat" u 1:5 title "NFlops: Transpuesta eigen o3"  w lp ps 0.5 lt rgb "blue" pointtype 7

