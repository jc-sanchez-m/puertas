// Control Puertas
// -*- modo: C++ -*-
// 
// lee el valor en los pines digitales 6 y 7
// para abrir o cerrar las puertas
// lee el valor en los pines digitales 8 y 9
// para saber la posicion de las puertas
// 8 = puertaCerrada, 9 = puertaAbierta
// considera las puertas cerradas como posicion 0
//
// 11-02-2014 
// Julio César Sanchez Mendoza
//
// Placa: Arduino Ethernet
// Microstep Driver FMD2740A 
// SW1  SW2
//  0    1  Fast Decay
// SW3  SW4  SW5  
//  1    0    0  1/8  Microstep
// SW6  SW7  SW8
//  1    0    1  3.0  A 

#include <AccelStepper.h> // Biblioteca de funciones mejorada para motores a pasos

// Definimos el stepper y los pines que usaremos
AccelStepper driver(AccelStepper::DRIVER, 2, 3); // Indicamos que utilizaremos un driver
                                                 // pin 2 = step, pin 3 = dir
int puertaCerrada = 8;  // El sensor que indica que la puerta esta cerrada
int puertaAbierta = 9;  // Sensor que indica que la puerta esta abierta

int abrir = 6;          // Push boton temporal abre las puertas
int cerrar = 7;         // Push boton temporal cierra las puertas

                                                 
void setup()
{
  driver.setEnablePin(4);                   // pin de habilitacion del driver (en = 4)
  driver.setPinsInverted(true, true, true); // utilizaremos el arduino como sink
  driver.setMaxSpeed(3000);                 
  driver.setAcceleration(1500);
  driver.setCurrentPosition(0); 
  
  pinMode(puertaCerrada, INPUT);
  pinMode(puertaAbierta, INPUT);
  pinMode(abrir, INPUT);
  pinMode(cerrar, INPUT);  
}

void loop()
{
  if (digitalRead(puertaAbierta) == HIGH)  {
    driver.setCurrentPosition(0);
  }
  if (digitalRead(puertaCerrada) == HIGH)  {
    driver.setCurrentPosition(1600);
  }
  if(digitalRead(abrir) == HIGH)  
    driver.moveTo(1600);
  }
  if(digitalRead(cerrar) == HIGH)
    driver.moveTo(0);
  }
  driver.run();
}
