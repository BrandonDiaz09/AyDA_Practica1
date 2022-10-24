%%VALORES DE X 
x=[1000 2000 3000 4000 5000 8000 10000 50000 100000 150000 200000 300000 400000 500000 800000 1000000];
 
%%VALORES DE Y = F(x) en Milisegundos
y=[365.9725 1492.9771 3225.0881 5692.9588 8931.1600 23195.9820 35388.9465 896040.9164 3570827.0073 8148619.8902 14505819.0823 32719455.9574 57466399.9081 91123589.9925 231721153.9745 364146142.9596];

%%OBTENER UN POLINOMIO QUE SE AJUSTE A LOS PUNTOS X Y Y
grado=2; 				%%GRADO DEL POLINOMIO DE AJUSTE
p=polyfit(x,y,grado)	%%FUNCION QUE REALIZA EL AJUSTE POLINOMIAL

%%SE CREA UN ESPACIO PARA REALIZAR UNA GRAFICA EN 
%%DONDE SE COMPARA LA CURVA AJUSTADA CONTRA LOS 
%%VALORES EXPERIMENTALES
xi=linspace(0,1000000,1000000);      %%ESPACIO DE PUNTOS PARA Xi
z=polyval(p,xi);				%%EVALUACION DEL POLINOMIO P EN EL ESPACIO Xi

%%SE REALIZA LA FIGURA CORRESPONDIENTE
figure(1);
plot(x,y,'o',xi,z,'-'),grid;
ylabel('F(x)');
xlabel('x');
title('Inserción');