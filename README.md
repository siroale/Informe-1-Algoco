# Informe-1-Algoco

| Nombre                    | ROL         |
| ------------------------- | ----------- |
| Alexis Mellis Orozco      | 202273557-0 |

## IMPORTANTE
Para realizar los test de tiempos de ejecución se utilizaron los archivos "SortingTest.cpp" y "MatricesTest.cpp", ambos necesitan que exista una carpeta llamada
"Datasets" que contenga los juegos de datos creados con "DatasetMatricesScript.cpp" y "DatasetSortScript.cpp", además de otra carpeta llamada "Output" para que
puedan escribir el resultado de los algoritmos.

## EJECUCIÓN
Para compilar se usan los siguientes comandos en una consola de Linux.

Crear los datasets: (Es necesario que exista la carpeta "Datasets" para que se creen los archivos)
g++ DatasetSortScript.cpp -o datasetsort
g++ DatasetMatrices.cpp -o datasetmatriz
./datasetsort
./datasetmatriz

Probar los algoritmos:
g++ SortingTest.cpp -o sort
g++ MatricesTest.cpp -o matrices

## VERSIONES UTILIZADAS

- C++17 o superior
- g++ version 13.2.0
