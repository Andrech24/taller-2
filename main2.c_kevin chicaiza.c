#include <stdio.h>
#include <math.h>

float calcularDistancia(float x1, float y1, float z1, float x2, float y2, float z2);
float calcularArea(float lado1, float lado2, float lado3);
float calcularPerimetro(float lado1, float lado2, float lado3);
float calcularVolumen(float areaBase, float altura);

int main() {
    float puntos[4][3];
    printf("Ingrese las coordenadas de los 4 puntos (x, y, z):\n");

    
    for (int i = 0; i < 4; i++) {
        printf("Punto %d: ", i + 1);
        scanf("%f %f %f", &puntos[i][0], &puntos[i][1], &puntos[i][2]);
    }

    
    float distancias[6];
    distancias[0] = calcularDistancia(puntos[0][0], puntos[0][1], puntos[0][2], puntos[1][0], puntos[1][1], puntos[1][2]);
    distancias[1] = calcularDistancia(puntos[0][0], puntos[0][1], puntos[0][2], puntos[2][0], puntos[2][1], puntos[2][2]);
    distancias[2] = calcularDistancia(puntos[0][0], puntos[0][1], puntos[0][2], puntos[3][0], puntos[3][1], puntos[3][2]);
    distancias[3] = calcularDistancia(puntos[1][0], puntos[1][1], puntos[1][2], puntos[2][0], puntos[2][1], puntos[2][2]);
    distancias[4] = calcularDistancia(puntos[1][0], puntos[1][1], puntos[1][2], puntos[3][0], puntos[3][1], puntos[3][2]);
    distancias[5] = calcularDistancia(puntos[2][0], puntos[2][1], puntos[2][2], puntos[3][0], puntos[3][1], puntos[3][2]);

    
    float perimetroBase = calcularPerimetro(distancias[0], distancias[1], distancias[3]);

    
    float areaBase = calcularArea(distancias[0], distancias[1], distancias[3]);

   
    float altura = calcularDistancia(puntos[3][0], puntos[3][1], puntos[3][2], puntos[0][0], puntos[0][1], puntos[0][2]);

    
    float volumen = calcularVolumen(areaBase, altura);


    printf("Distancias:\n");
    printf("P1-P2: %.2f\n", distancias[0]);
    printf("P1-P3: %.2f\n", distancias[1]);
    printf("P1-P4: %.2f\n", distancias[2]);
    printf("P2-P3: %.2f\n", distancias[3]);
    printf("P2-P4: %.2f\n", distancias[4]);
    printf("P3-P4: %.2f\n", distancias[5]);

    printf("Perímetro de la base: %.2f\n", perimetroBase);
    printf("Área de la base: %.2f\n", areaBase);
    printf("Altura de la pirámide: %.2f\n", altura);
    printf("Volumen de la pirámide: %.2f\n", volumen);

    return 0;
}

float calcularDistancia(float x1, float y1, float z1, float x2, float y2, float z2) {
    float dist = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2) + pow(z2 - z1, 2));
    return dist;
}

float calcularArea(float lado1, float lado2, float lado3) {
    float s = (lado1 + lado2 + lado3) / 2;
    float area = sqrt(s * (s - lado1) * (s - lado2) * (s - lado3));
    return area;
}

float calcularPerimetro(float lado1, float lado2, float lado3) {
    float perimetro = lado1 + lado2 + lado3;
    return perimetro;
}

float calcularVolumen(float areaBase, float altura) {
    float volumen = (areaBase * altura) / 3;
    return volumen;
}