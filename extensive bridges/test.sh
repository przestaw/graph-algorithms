#!/bin/sh

for i in 0 1 2 3 4 5 6 7 8 9
do
   echo "graf$i.txt : "
   cat examples/graf$i.txt
   echo "graph <graf$i.txt : "
   bin/graph <examples/graf$i.txt
done
