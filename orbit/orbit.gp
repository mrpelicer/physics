set terminal tikz size 10.6cm,6.40cm fontscale 0.8 fulldoc
set output "orbit.tex"

set xlabel offset 0.0,0.0 ""
set ylabel offset 0.0,0.0 ""

set xrange[-75:100]
set yrange[-80:100]

set xtics offset 0.0, 0.0 25 nomirror
set ytics offset 0.0, 0.0 25 nomirror

set label "$L= 8$" at -65,75
set object 1 circle at 0,0 size 7 fill solid 1.0 lw 3 fc rgb 'blue'


plot "nwt.dat" u 1:2 w l ls 1 lw 4 lc rgb 'green' t"Clássica",\
		 "rel.dat" u 1:2 w l ls 1 lw 2 lc rgb 'red' t"Relativística"

