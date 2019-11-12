#!/bin/bash
touch entrada.txt
touch salida.txt
sed "3d" entrada.txt > salida.txt
for i in {1..1000}
do
    make
    #echo $((i))>>salida.txt; cat out.txt>>salida.txt
   cat out.txt>>salida.txt
done
