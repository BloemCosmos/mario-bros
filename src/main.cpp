#include<SerieNavidad.hpp>

int main(int argc, char const *argv[])
{
    SerieNavidad s1(10);
    SerieNavidad s2(5);
    SerieNavidad s3(15);

    s1.Encender();
    s1.Imprimir();

    s2.Encender();
    s2.Imprimir();

    s3.Encender();
    s3.Imprimir();

    return 0;
}

