#include <Adafruit_NeoPixel.h>

#define LED_PIN     D4
#define LED_COUNT   8
#define BUTTON_PIN D2

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

unsigned long pomodoroDuration = 25 * 1000 * 60; // 25 segundos para probar
unsigned long shortBreakDuration = 5 * 1000 * 60; // 5 segundos para probar
unsigned long longBreakDuration = 15 * 1000 * 60; // 15 segundos para probar

unsigned long startTime;

void setup() {
 strip.begin();
 strip.clear(); // Limpiar todos los LEDs antes de mostrar
 strip.show(); // Mostrar el estado inicial de los LEDs
 pinMode(BUTTON_PIN, INPUT_PULLUP);
}

void loop() {
 if (digitalRead(BUTTON_PIN) == LOW) { // Botón presionado
    startPomodoro();
    startShortBreak();
    startPomodoro();
    startShortBreak();
    startPomodoro();
    startShortBreak();
    startPomodoro();
    startLongBreak();
 }
}

void startPomodoro() {
 strip.clear(); // Limpiar todos los LEDs antes de mostrar
 startTime = millis(); // Inicializa el temporizador
 while (millis() - startTime < pomodoroDuration) {
    unsigned long elapsedTime = millis() - startTime;
    float progress = (float)elapsedTime / pomodoroDuration;
    int ledsOn = (int)(progress * (LED_COUNT - 1)) + 1; // Comenzar desde el segundo LED
    for (int i = 0; i < ledsOn; i++) {
       strip.setPixelColor(i, 80, 0, 0); // Encender los LEDs en rojo
    }
    strip.show(); // Mostrar el estado actual de los LEDs
    delay(100); // Pequeño retraso para la animación
 }
}

void startShortBreak() {
 strip.clear(); // Limpiar todos los LEDs antes de mostrar
 startTime = millis(); // Inicializa el temporizador
 while (millis() - startTime < shortBreakDuration) {
    unsigned long elapsedTime = millis() - startTime;
    float progress = (float)elapsedTime / shortBreakDuration;
    int ledsOn = (int)(progress * (LED_COUNT - 1)) + 1; // Comenzar desde el segundo LED
    for (int i = 0; i < ledsOn; i++) {
       strip.setPixelColor(i, 0, 80, 0); // Encender los LEDs en verde
    }
    strip.show(); // Mostrar el estado actual de los LEDs
    delay(100); // Pequeño retraso para la animación
 }
}

void startLongBreak() {
 strip.clear(); // Limpiar todos los LEDs antes de mostrar
 startTime = millis(); // Inicializa el temporizador
 while (millis() - startTime < longBreakDuration) {
    unsigned long elapsedTime = millis() - startTime;
    float progress = (float)elapsedTime / longBreakDuration;
    int ledsOn = (int)(progress * (LED_COUNT - 1)) + 1; // Comenzar desde el segundo LED
    for (int i = 0; i < ledsOn; i++) {
       strip.setPixelColor(i, 0, 0, 80); // Encender los LEDs en azul
    }
    strip.show(); // Mostrar el estado actual de los LEDs
    delay(100); // Pequeño retraso para la animación
 }
}
