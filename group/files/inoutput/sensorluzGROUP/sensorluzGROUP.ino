/*
Activar los leds dependiendo de la 
cantidad de luz que tengamso en la habitación
******************************************************************************/
// Declaramos el pin del sensor y creamos una array para lso leds
// Las arrays almacenan datos por lo que al tener 5 leds se declaran
int sensorPin = A6;
int barraLED[5] = {5,6,A2,A4,A3};

// las arrays se indexan desde 0 por lo que tendriamos 4

void setup()
{
  int x;
  pinMode(sensorPin, INPUT);

  // bucle para indexar los leds

  for (x = 0; x <= 4; x++){
    
    pinMode(barraLED[x], OUTPUT);
  }

  // iniciamos el monitor serie

  Serial.begin(9600);
}

void loop(){
  
  int valorSensor;

  // Lee el valor del sensor 

  valorSensor = analogRead(sensorPin);

  // Imprime el valor del sensor

  Serial.print("Valor Sensor: ");
  Serial.println(valorSensor);
  barra(valorSensor);
}

// Ahora creamos nuestra propia función el primer void significa que nada retornará 
// desde aquí, " int valor" es el que pasaremos a la función y que se llamará valor

void barra(int valor){
 
 int x;

  // Valor estará en un rango 0 a 1023.
  // Tenemos 5 LEDs en la barra
  // 1023/5 = 204, 204 será nuestra media o threshold
  // entre cada led

  for (x=0; x <= 4; x++){
    
    if (valor > (x*204) ){
      
      digitalWrite(barraLED[x], HIGH);
    }
    
    else{
      
      digitalWrite(barraLED[x], LOW);
    }    
  }
}

