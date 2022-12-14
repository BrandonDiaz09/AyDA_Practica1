%%VALORES DE X
x=[1000 2000 3000 4000 5000 8000 10000 50000 100000 150000 200000 300000 400000 500000 800000 900000 1000000 1500000 2000000];

%%VALORES DE y = F(x) en Milisegundos
y=[149.0116 305.1758 471.1151 787.9734 1008.9874 1965.9996 2450.2277 18795.0134 47995.0905 63650.1312 108111.8584 158962.9650 260272.0261 305647.1348 622205.9727 593862.0567 713804.9603 1110351.8009 1826978.9219];

%%OBTENER UN POLINOMIO QUE SE AJUSTE A LOS PUNTOS X Y Y
grado=2; 				%%GRADO DEL POLINOMIO DE AJUSTE
p=polyfit(x,y,grado)	%%FUNCION QUE REALIZA EL AJUSTE POLINOMIAL

%%SE CREA UN ESPACIO PARA REALIZAR UNA GRAFICA EN 
%%DONDE SE COMPARA LA CURVA AJUSTADA CONTRA LOS 
%%VALORES EXPERIMENTALES
xi=linspace(0,3000000,10000000);      %%ESPACIO DE PUNTOS PARA Xi
z = polyval(p,xi);        %%EVALUACION DE LA CURVA LOGARITMICA P EN EL ESPACIO Xi

%%SE REALIZA LA FIGURA CORRESPONDIENTE
figure(1);
plot(x,y,'o',xi,z,'-'),grid;
ylabel('F(x)');
xlabel('x');
title('Shell');

