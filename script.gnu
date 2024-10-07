set terminal pngcairo enhanced size 800,600
set output 'grafico.png'
set title "Pontos e Função Identificada"
set xlabel "Eixo X"
set ylabel "Eixo Y"
set grid

f(x) = x*x

plot "dados.txt" using 1:2 title "Pontos" with points pointtype 7 pointsize 1 lc rgb "blue", \
     f(x) title "Função Identificada" with lines lw 2 lc rgb "red"
