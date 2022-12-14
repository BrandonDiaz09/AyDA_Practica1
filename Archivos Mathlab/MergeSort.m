%%VALORES DE X
x=[1000 2000 3000 4000 5000 8000 10000 50000 100000 150000 200000 300000 400000 500000 800000 900000 1000000 1500000 2000000];

%%VALORES DE y = F(x) en Milisegundos
y=[0.0001220703 0.0002119541 0.0003190041 0.0004320145 0.0006029606 0.0009381771 0.0012040138 0.0067069530 0.0142071247 0.0216510296 0.0294518471 0.0457279682 0.0613901615 0.0771660805 0.1272029877 0.1433978081 0.1612131596 0.2468550205 0.3319120407];

%%OBTENER UN POLINOMIO QUE SE AJUSTE A LOS PUNTOS X Y Y
p = polyfit(log(x),y,1)
a=p(1);
c=p(2);
fprintf('f(x)=%f*ln(x)+%f\n',a,c);

%%SE CREA UN ESPACIO PARA REALIZAR UNA GRAFICA EN 
%%DONDE SE COMPARA LA CURVA AJUSTADA CONTRA LOS 
%%VALORES EXPERIMENTALES
xi=linspace(0,3000000,10000000);      %%ESPACIO DE PUNTOS PARA Xi
z = polyval(p,log(xi));        %%EVALUACION DE LA CURVA LOGARITMICA P EN EL ESPACIO Xi

%%SE REALIZA LA FIGURA CORRESPONDIENTE
figure(1);
plot(x,y,'o',xi,z,'-'),grid;
ylabel('F(x)');
xlabel('x');
title('MergeSort');

