
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
