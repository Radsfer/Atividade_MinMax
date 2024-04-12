# Script Gnuplot para plotar dados de tempo de algoritmos (casos ordenado e desordenado)

# Configurações do gráfico
set terminal pngcairo enhanced font 'Verdana,12' size 1200, 800  # Tamanho da imagem
set output 'imgs/algorithms10000_comparison.png'
set title 'Comparação de Tempo de Algoritmos de Busca'
set xlabel 'x'
set ylabel 'Tempo (ns)'
set logscale x 10  # Usar escala logarítmica no eixo x (tamanho do vetor)

# Definir cores para os dados
set style line 1 lc rgb 'blue'   # Algoritmo 1
set style line 2 lc rgb 'red'    # Algoritmo 2
set style line 3 lc rgb 'green'  # Algoritmo 3
set style line 4 lc rgb 'cyan'   # Algoritmo 1
set style line 5 lc rgb 'brown'    # Algoritmo 2
set style line 6 lc rgb 'gold'  # Algoritmo 3
# Plotar dados para casos ordenados
plot \
    'datasets/Matrix_Dados/Ordenado_10000.txt' using 1 with linespoints ls 1 title 'Algoritmo 1 (Ordenado 10000)', \
    '' using 2 with linespoints ls 2 title 'Algoritmo 2 (Ordenado 10000)', \
    '' using 3 with linespoints ls 3 title 'Algoritmo 3 (Ordenado 10000)', \
    'datasets/Matrix_Dados/Desordenado_10000.txt' using 1 with linespoints ls 4 title 'Algoritmo 1 (Desordenado 10000)', \
    '' using 2 with linespoints ls 5 title 'Algoritmo 2 (Desordenado 10000)', \
    '' using 3 with linespoints ls 6 title 'Algoritmo 3 (Desordenado 10000)'
# Legenda
set key outside right top

# Salvar o gráfico
replot

