#include <stdio.h>


void vector_Digitos(int numero, int vector[], int longitud) {
    for (int i = longitud - 1; i >= 0; i--) {
        vector[i] = numero % 10; //Aqui calcularemos el el ultimo digito del vector
        numero /= 10;// este paso lo utilizaremos para que en cada interaccion del bucle se elimine el ultimo numero original, para que asi el bulce tenga todos los digitos en el vector. 
    }
}// En est afuncion s esepararan los digitos, donde recibira los parametros que queremos convertir en digitos, el arreglo de almacenamiento y la longitud del vector.


void sumale(int vector[], int posicion, int valor, int longitud) {
    
    if (posicion >= 0 && posicion < longitud) {
        vector[posicion] += valor; // EN este paso validamos la posicion y sumaremos el valor a la posicion del vector.

        
        int acarreo = 0; // almacenamos acarreo
        for (int i = longitud - 1; i >= 0; i--) {
            vector[i] += acarreo; // Sumamos el acarreo al dígito actual
            acarreo = vector[i] / 10; // calculamos el nuevo acarreo para la siguiente iteración
            vector[i] %= 10; // Nos quedamos solo con el dígito de la posición actual
        }
    }
}

int main() {
    int numero;
    int longitud = 0;

    printf("Ingrese un número: ");
    scanf("%d", &numero);

   
    int temp = numero;
    while (temp != 0) {
        temp /= 10;
        longitud++;
    }

    int vector[longitud];

    vector_Digitos(numero, vector, longitud);

    
    printf("Vector original: ");
    for (int i = 0; i < longitud; i++) {
        printf("%d ", vector[i]);
    }
    printf("\n");

    
    int posicion, valor;
    printf("Ingrese la posición y el valor de suma (separados por espacio): ");
    scanf("%d %d", &posicion, &valor);
    sumale(vector, posicion, valor, longitud);

    
    printf("Resultado: ");
    for (int i = 0; i < longitud; i++) {
        printf("%d ", vector[i]);
    }
    printf("\n");

    return 0;
}

