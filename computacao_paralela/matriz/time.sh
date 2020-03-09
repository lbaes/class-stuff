#!/bin/bash
echo -e "\nMatriz IJK\n"
time -p ./matriz-ijk

echo -e "\nMatriz IJK O3\n"
time -p ./matriz-ijk-O3

echo -e "\nMatriz IKJ\n"
time -p ./matriz-ikj

echo -e "\nMatriz IKJ O3\n"
time -p ./matriz-ikj-O3