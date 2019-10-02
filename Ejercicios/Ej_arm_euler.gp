set term pdf
set output "Ej_arm_euler.pdf"
set xlabel "x"
set ylabel "y"
plot [][0.56:0.6]"Ej_arm_euler.txt" u 1:2 w l , "" u 1:3 w l