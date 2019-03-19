Esta práctica se compila con la herramiena Generic-Makefile (una herramienta mia)


Para configurar el makefile en tu equipo ejecutar

    make config

(parecido al build del cmake)



para compilar usa

    make

(tambien ejecuta el binario por defecto)




Para compilar las pruebas, clona googletest en make-files

    git clone git@github.com:google/googletest.git ./make-files

y ejecuta

    make googletest



Para generar la documentación usa

    make doc