#!/bin/bash
mkdir -p outputs
for i in data/*.in; do echo $i; tmpp=`echo $i | sed "s/\.in/\.out/g" | sed "s/data/outputs/g"`; ./binary < $i > $tmpp; done
