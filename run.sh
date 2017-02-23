#!/bin/bash
for i in data/*.in; do echo $i; ./binary < $i > ${i/\.in/\.out}; done
