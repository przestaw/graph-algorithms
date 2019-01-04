#!/bin/sh

for i in 1 2 3 4 5 6 
do
   echo "graf$i.txt : "
   cat examples/graf$i.txt
   echo "graph <graf$i.txt : "
   bin/graph <examples/graf$i.txt
done
