%%VALORES DE X 
x=[1000 2000 3000 4000 5000 8000 10000 50000 100000 150000 200000 300000 400000 500000 800000 1000000];
 
%%VALORES DE Y = F(x) en Milisegundos
y=[939.1308 3662.8246 8052.1107 14364.0041 22526.0258 57111.0249 94282.1503 3478163.9576 15520655.8704 35229723.9304 65406296.9685 145267391.9201 261847346.0674 410616521.1201 1041251347.0650 1609748196.1250];

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
title('Burbuja Optimizada 2');