#include <stdio.h>
#include <stdlib.h>

//Desenvolvido por Gustavo Almeida
int main()
{
    double estadoSP = 67836.43, estadoRJ = 36678.66, estadoMG = 29229.88, estadoES = 27165.48, outrosEstados = 19849.53, somaTotal = estadoSP + estadoRJ + estadoMG + estadoES + outrosEstados;
    printf("Faturamento em SP: %.2lf%%", (estadoSP/somaTotal) * 100);
    printf("\nFaturamento no RJ: %.2lf%%", (estadoRJ/somaTotal) * 100);
    printf("\nFaturamento no ES: %.2lf%%", (estadoES/somaTotal) * 100);
    printf("\nFaturamento em MG: %.2lf%%", (estadoMG/somaTotal) * 100);
    printf("\nFaturamento em outros estados: %.2lf%%", (outrosEstados/somaTotal) * 100);
}
