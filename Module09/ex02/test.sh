#!/bin/bash

./PmergeMe `shuf -i 1-100000 -n 3000 | tr "\n" " "`
