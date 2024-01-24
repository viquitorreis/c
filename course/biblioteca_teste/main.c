#include <stdio.h>
#include <stdlib.h>
#include "circulo.h"

int main() {
    double raio = 5.00;
    double area_circulo = area(raio);
    double perimetro_circulo = perimetro(raio);
    printf("Area: %f\n", area_circulo);
    printf("Perímetro: %f\n", perimetro_circulo);

    return 0;
}