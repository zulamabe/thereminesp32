// Synthesizer.cpp
#include "Synthesizer.h"

Synthesizer::Synthesizer(int dacPin) {
  this->dacPin = dacPin;
  this->synthType = 0;  // Por defecto, seleccionamos la onda seno
}

void Synthesizer::init() {
  // No se requiere inicialización adicional para el DAC en la ESP32
}

void Synthesizer::setSynthType(int type) {
  this->synthType = type;
}

void Synthesizer::generateSound(float frequency, uint8_t volume) {
  // Según el tipo de onda seleccionada, generamos el sonido adecuado
  switch (synthType) {
    case 0:
      generateSineWave(frequency, volume);
      break;
    case 1:
      generateSquareWave(frequency, volume);
      break;
    case 2:
      generateSawtoothWave(frequency, volume);
      break;
    case 3:
      generateTriangleWave(frequency, volume);
      break;
  }
}

void Synthesizer::generateSineWave(float frequency, uint8_t volume) {
  // Generación de onda seno usando una tabla de valores de seno
  const int sineWaveSamples = 100;  // Cantidad de muestras para una onda seno completa
  float angleStep = (2.0 * PI) / sineWaveSamples;  // Paso de ángulo para cada muestra
  for (int i = 0; i < sineWaveSamples; i++) {
    float sample = sin(i * angleStep);  // Generamos la muestra seno
    int output = (int)((sample + 1.0) * (volume / 2.0));  // Normalizamos y ajustamos al volumen
    dacWrite(dacPin, output);
    delayMicroseconds(1000000 / (sineWaveSamples * frequency));  // Ajuste de tiempo entre muestras
  }
}

void Synthesizer::generateSquareWave(float frequency, uint8_t volume) {
  // Generación de onda cuadrada alternando entre dos niveles
  int highOutput = volume;
  int lowOutput = 0;
  int period = 1000000 / frequency;  // Periodo de la onda en microsegundos
  dacWrite(dacPin, highOutput);
  delayMicroseconds(period / 2);  // Duración de la fase alta
  dacWrite(dacPin, lowOutput);
  delayMicroseconds(period / 2);  // Duración de la fase baja
}

void Synthesizer::generateSawtoothWave(float frequency, uint8_t volume) {
  // Generación de onda diente de sierra incrementando el valor linealmente
  int samples = 100;  // Cantidad de muestras por ciclo
  int period = 1000000 / frequency;
  int step = volume / samples;
  for (int i = 0; i < samples; i++) {
    dacWrite(dacPin, i * step);  // Generamos la rampa ascendente
    delayMicroseconds(period / samples);
  }
}

void Synthesizer::generateTriangleWave(float frequency, uint8_t volume) {
  // Generación de onda triangular alternando subida y bajada linealmente
  int samples = 50;  // Muestras para cada medio ciclo
  int period = 1000000 / frequency;
  int step = volume / samples;

  // Subida
  for (int i = 0; i < samples; i++) {
    dacWrite(dacPin, i * step);
    delayMicroseconds(period / (2 * samples));
  }
  // Bajada
  for (int i = samples; i > 0; i--) {
    dacWrite(dacPin, i * step);
    delayMicroseconds(period / (2 * samples));
  }
}
