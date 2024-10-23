// Theremin_ESP32.ino
#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_SSD1306.h>  // Biblioteca para la pantalla OLED
#include "UltrasonicSensor.h"
#include "Synthesizer.h"

// Definimos los pines del hardware adicional
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
#define BUTTON_PIN 32
#define POT_1_PIN 34   // Potenciómetro para seleccionar sintetizador
#define POT_2_PIN 35   // Potenciómetro para ajustar parámetro (volumen)

// Definimos los pines de los sensores de ultrasonido
#define TRIG_PIN_1 12  // Sensor de tono
#define ECHO_PIN_1 13
#define TRIG_PIN_2 14  // Sensor de volumen
#define ECHO_PIN_2 27

// DAC output pin (para generar sonido)
#define DAC_PIN 25

// Inicializamos la pantalla OLED
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// Inicializamos los sensores de ultrasonido y el sintetizador
UltrasonicSensor sensorTone(TRIG_PIN_1, ECHO_PIN_1);
UltrasonicSensor sensorVolume(TRIG_PIN_2, ECHO_PIN_2);
Synthesizer synth(DAC_PIN);

// Variables del menú
int synthType = 0;  // Índice del sintetizador seleccionado
int volume = 128;   // Volumen inicial

void setup() {
  // Configuramos el botón y los potenciómetros
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(POT_1_PIN, INPUT);
  pinMode(POT_2_PIN, INPUT);

  // Iniciamos la comunicación I2C para la pantalla
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("Error en la inicialización de la pantalla OLED"));
    for (;;);
  }
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.println(F("Theremin ESP32"));
  display.display();

  // Iniciamos los sensores y el sintetizador
  sensorTone.init();
  sensorVolume.init();
  synth.init();
  delay(1000);
}

void loop() {
  // Leemos los valores de los potenciómetros
  int pot1Value = analogRead(POT_1_PIN);
  int pot2Value = analogRead(POT_2_PIN);

  // Mapeamos el potenciómetro 1 para seleccionar el sintetizador
  synthType = map(pot1Value, 0, 4095, 0, 3);  // Mapeo para seleccionar entre 4 tipos de sintetizadores

  // Mapeamos el potenciómetro 2 para ajustar el volumen
  volume = map(pot2Value, 0, 4095, 0, 255);  // Mapeo simple para volumen

  // Actualizamos la pantalla con el tipo de sintetizador y volumen
  display.clearDisplay();
  display.setCursor(0, 0);
  display.println(F("Synth:"));
  switch (synthType) {
    case 0:
      display.println(F("Sine Wave"));
      break;
    case 1:
      display.println(F("Square Wave"));
      break;
    case 2:
      display.println(F("Sawtooth Wave"));
      break;
    case 3:
      display.println(F("Triangle Wave"));
      break;
  }
  display.print(F("Volume: "));
  display.println(volume);
  display.display();

  // Leemos la distancia de los sensores de ultrasonido
  float distanceTone = sensorTone.readDistance();
  float distanceVolume = sensorVolume.readDistance();

  // Convertimos la distancia a tono y aplicamos volumen
  float frequency = map(distanceTone, 10, 200, 100, 1500);  // Mapeo para la frecuencia del tono
  synth.generateSound(frequency, volume);

  delay(50);  // Breve pausa para evitar sobrecarga
}
