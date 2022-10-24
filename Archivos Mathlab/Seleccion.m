%%VALORES DE X 
x=[1000 2000 3000 4000 5000 8000 10000 50000 100000 150000 200000 300000 400000 500000 800000 1000000];
 
%%VALORES DE Y = F(x) en Milisegundos
y=[478.0293 1827.0016 4053.1158 7159.9483 11178.0167 28748.0354 44971.9429 1104804.9927 4406476.9745 9964041.9483 17884824.0376 40034404.0394 70669953.8231 110508240.9382 282642488.0028 443786532.1636];

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
title('Selección');