# ANTIRREBOTE
### Tipos de estrategias antirrebotes para pulsadores
1- Filtro de paso bajo: Este sistema utiliza un filtro de paso bajo para eliminar las señales de alta frecuencia que pueden causar rebotes.

2- Interrupción: Este sistema utiliza una interrupción para detectar el cambio de estado del pin.

3- Debounce interno: Algunos microcontroladores tienen un debouncing interno que puede utilizarse para eliminar los rebotes.

4- Debounce software: Este sistema utiliza software para eliminar los rebotes.

5- Debounce hardware: Este sistema utiliza hardware para eliminar los rebotes.

6- Debounce óptico: Este sistema utiliza un sensor óptico para detectar el cambio de estado del pin.


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



```C
void setup() {
  // Configura el pin como entrada
  pinMode(pin, INPUT);

  // Configura el pin para que genere una interrupción
  attachInterrupt(pin, handle_interrupt, FALLING);
}

void loop() {
  // No es necesario hacer nada aquí
}

void handle_interrupt() {
  // Se ha detectado un pulso
}

```
Esta función funciona de la siguiente manera:

La función setup() configura el pin como entrada y lo configura para que genere una interrupción.
La función loop() no hace nada.
La función handle_interrupt() se llama cuando se genera una interrupción.
Cuando se genera una interrupción, la función handle_interrupt() detecta un pulso.

Este método es más eficiente que el método del filtro de paso bajo, ya que no requiere que el microcontrolador lea continuamente el valor del pin.
