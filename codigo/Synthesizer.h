// Synthesizer.h
#ifndef SYNTHESIZER_H
#define SYNTHESIZER_H

#include <Arduino.h>

class Synthesizer {
  public:
    Synthesizer(int dacPin);
    void init();
    void generateSound(float frequency, uint8_t volume);

    // Selecciona el tipo de onda
    void setSynthType(int type);

  private:
    int dacPin;
    int synthType;

    // Métodos internos para generar cada tipo de onda
    void generateSineWave(float frequency, uint8_t volume);
    void generateSquareWave(float frequency, uint8_t volume);
    void generateSawtoothWave(float frequency, uint8_t volume);
    void generateTriangleWave(float frequency, uint8_t volume);
};

#endif
