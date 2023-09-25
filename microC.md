```c
//Sistema 1 para la detección de pulso de botón.
while(true) {
    if(input(pin_A1)){
      delay_ms(30);
      output_toggle(LED1);
      while(input(pin_A1));
   }
 
   if(input(pin_A2)){
      delay_ms(30);
      output_toggle(LED2);
      while(input(pin_A2));
   }
 
}

//Sistema 2 para la deteccion de pulso de boton
if(input(pin_A1)==1){
delay_ms(30);
if(input(pin_A1)==1){
output_toggle(LED);
while(input(pin_A1)==1);
}
}
```

```c

//Filtro Pasa bajo
void filter(int pin, int ancho_filtro) {
  int valor_anterior = input(pin);
  int valor_actual = input(pin);
  unsigned long tiempo_inicio = micros();

  while (valor_actual == valor_anterior && (micros() - tiempo_inicio) < ancho_filtro) {
    valor_actual = input(pin);
  }

  if (valor_actual != valor_anterior) {
    // Se ha detectado un pulso
  }
}
```
Este código funciona de la siguiente manera:

La función comienza leyendo el valor actual del pin pin.
A continuación, la función almacena el valor actual en la variable valor_anterior.
La función almacena el tiempo actual en la variable tiempo_inicio.
La función vuelve a leer el valor del pin pin.
Si el valor actual es igual al valor anterior y el tiempo transcurrido desde que se inició el filtro es menor que el ancho de filtro, la función espera hasta que el valor actual sea diferente al valor anterior o hasta que el tiempo transcurrido sea mayor que el ancho de filtro.
Si el valor actual es diferente al valor anterior, la función detecta un pulso.
