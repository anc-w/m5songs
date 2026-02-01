#include <Arduino.h>
#include <M5Unified.h>
// wet hands - c418, script made by @NugetNet
#define BUZZER_PIN 2
#define NOTE_REST 0
#define NOTE_REST 0
#define NOTE_A2 110
#define NOTE_Cs3 139
#define NOTE_A3 220
#define NOTE_B3 247
#define NOTE_Cs4 277
#define NOTE_E3 165
#define NOTE_D3 147
#define NOTE_Fs3 185
#define NOTE_E4 330
#define NOTE_Gs4 415
#define NOTE_A4 440
#define NOTE_Fs4 370
#define NOTE_B4 494
#define NOTE_Cs5 554
#define NOTE_E5 659
#define NOTE_G5 784
#define NOTE_G2 98
#define NOTE_B2 123
#define NOTE_Fs5 740
#define NOTE_D5 587
#define NOTE_E2 82
#define NOTE_Gs2 104
#define NOTE_Gs3 208
#define NOTE_A5 880
#define NOTE_Gs5 831

const int tempoBPM = 74;

int melody[] = { NOTE_A2, NOTE_Cs3, NOTE_A3, NOTE_B3, NOTE_Cs4, NOTE_B3, NOTE_A3, NOTE_E3, NOTE_D3, NOTE_Fs3, NOTE_Cs4, NOTE_E4, NOTE_Cs4, NOTE_A3, NOTE_A2, NOTE_Cs3, NOTE_A3, NOTE_B3, NOTE_Cs4, NOTE_B3, NOTE_A3, NOTE_E3, NOTE_D3, NOTE_Fs3, NOTE_Cs4, NOTE_E4, NOTE_Cs4, NOTE_A3, NOTE_Gs4, NOTE_A2, NOTE_Cs3, NOTE_A3, NOTE_B3, NOTE_Cs4, NOTE_B3, NOTE_A4, NOTE_A3, NOTE_E3, NOTE_Fs4, NOTE_D3, NOTE_Fs3, NOTE_Cs4, NOTE_E4, NOTE_Cs4, NOTE_A3, NOTE_E4, NOTE_Fs4, NOTE_Gs4, NOTE_A2, NOTE_Cs3, NOTE_A3, NOTE_B3, NOTE_Cs4, NOTE_B3, NOTE_B4, NOTE_A3, NOTE_Cs5, NOTE_E3, NOTE_D3, NOTE_Fs4, NOTE_Fs3, NOTE_Cs4, NOTE_E4, NOTE_Cs4, NOTE_A3, NOTE_Cs5, NOTE_E5, NOTE_G5, NOTE_G2, NOTE_B2, NOTE_D3, NOTE_Fs5, NOTE_Fs3, NOTE_D5, NOTE_A3, NOTE_Fs3, NOTE_A4, NOTE_D3, NOTE_B4, NOTE_B2, NOTE_G2, NOTE_B2, NOTE_D3, NOTE_Fs3, NOTE_A3, NOTE_G5, NOTE_G2, NOTE_B2, NOTE_Fs5, NOTE_D3, NOTE_Fs3, NOTE_D5, NOTE_A3, NOTE_Fs3, NOTE_A4, NOTE_D3, NOTE_B4, NOTE_B2, NOTE_G2, NOTE_B2, NOTE_D3, NOTE_Fs3, NOTE_A3, NOTE_A4, NOTE_E4, NOTE_A2, NOTE_Cs3, NOTE_A3, NOTE_B3, NOTE_Cs4, NOTE_B3, NOTE_A3, NOTE_E3, NOTE_A2, NOTE_Cs3, NOTE_A3, NOTE_B3, NOTE_Cs4, NOTE_E4, NOTE_A4, NOTE_Cs5, NOTE_Fs4, NOTE_B2, NOTE_B4, NOTE_D5, NOTE_D3, NOTE_Fs3, NOTE_Cs5, NOTE_A3, NOTE_A4, NOTE_Cs4, NOTE_E4, NOTE_E5, NOTE_Fs4, NOTE_Fs5, NOTE_B2, NOTE_D5, NOTE_D3, NOTE_Fs3, NOTE_A3, NOTE_Cs4, NOTE_B4, NOTE_Cs5, NOTE_D5, NOTE_G2, NOTE_B2, NOTE_Cs5, NOTE_D3, NOTE_D5, NOTE_Fs3, NOTE_A3, NOTE_Fs5, NOTE_E4, NOTE_A4, NOTE_Cs5, NOTE_A2, NOTE_Cs3, NOTE_E3, NOTE_A3, NOTE_B4, NOTE_A4, NOTE_B4, NOTE_E2, NOTE_Gs2, NOTE_B2, NOTE_E3, NOTE_Gs3, NOTE_E3, NOTE_B2, NOTE_Gs2, NOTE_E2, NOTE_Gs2, NOTE_B2, NOTE_E3, NOTE_Gs3, NOTE_E3, NOTE_A2, NOTE_G5, NOTE_G2, NOTE_Fs5, NOTE_B2, NOTE_E5, NOTE_D3, NOTE_D5, NOTE_Fs3, NOTE_E5, NOTE_A3, NOTE_D5, NOTE_Fs3, NOTE_E5, NOTE_D3, NOTE_Fs5, NOTE_B2, NOTE_A2, NOTE_E5, NOTE_Cs3, NOTE_E3, NOTE_A3, NOTE_A5, NOTE_Cs4, NOTE_A3, NOTE_E3, NOTE_Cs3, NOTE_Gs5, NOTE_E2, NOTE_E5, NOTE_Gs2, NOTE_B4, NOTE_B2, NOTE_Gs4, NOTE_E3, NOTE_E4, NOTE_Gs3, NOTE_B4, NOTE_E2, NOTE_Gs4, NOTE_Gs2, NOTE_E4, NOTE_B2, NOTE_B3, NOTE_E3, NOTE_Gs3, NOTE_E2, NOTE_Gs2, NOTE_B2, NOTE_E3, NOTE_B2, NOTE_E2, NOTE_Gs2, NOTE_B2, NOTE_E3, NOTE_E3, NOTE_A4, NOTE_E4, NOTE_A2, NOTE_E3, NOTE_A3, NOTE_B3, NOTE_Cs4, NOTE_B3, NOTE_A3, NOTE_E3, NOTE_A2 };
int durationsMs[] = { 383, 383, 383, 383, 383, 383, 383, 383, 383, 383, 383, 383, 383, 1154, 383, 383, 383, 383, 383, 383, 383, 383, 383, 383, 383, 383, 383, 1154, 2309, 383, 383, 383, 383, 383, 383, 769, 383, 383, 2309, 383, 383, 383, 383, 383, 1154, 383, 383, 2309, 383, 383, 383, 383, 383, 383, 383, 383, 769, 383, 383, 1539, 383, 383, 383, 383, 1154, 383, 383, 1154, 383, 383, 383, 383, 383, 769, 383, 383, 383, 383, 3465, 383, 383, 383, 383, 383, 1539, 769, 383, 383, 769, 383, 383, 769, 383, 383, 383, 383, 2694, 383, 383, 383, 383, 383, 1539, 769, 3079, 383, 383, 383, 383, 383, 383, 383, 383, 383, 383, 383, 383, 383, 383, 383, 383, 1215, 383, 1106, 998, 383, 383, 383, 383, 769, 1539, 383, 383, 769, 769, 383, 1924, 383, 383, 383, 1539, 383, 383, 769, 383, 383, 383, 383, 769, 383, 1539, 1154, 2309, 2309, 2309, 3079, 3079, 3079, 3079, 383, 383, 3079, 383, 383, 383, 383, 383, 383, 383, 383, 383, 383, 383, 383, 383, 383, 769, 383, 383, 383, 383, 383, 383, 383, 383, 383, 383, 383, 383, 383, 383, 769, 383, 383, 1154, 383, 383, 383, 1539, 383, 383, 383, 383, 383, 383, 383, 383, 383, 383, 383, 383, 1539, 1539, 383, 383, 383, 383, 383, 383, 383, 383, 1539, 383, 383, 383, 383, 1539, 383, 383, 383, 383, 1539, 769, 769, 383, 383, 383, 383, 383, 383, 383, 383, 3079 };

bool played = false;
void playTone(int freq, int duration) {
  if (freq == NOTE_REST) {
    ledcWriteTone(BUZZER_PIN, 0);
    delay(duration);
    return;
  }
  ledcWriteTone(BUZZER_PIN, freq);
  delay(duration);
  ledcWriteTone(BUZZER_PIN, 0);
  delay(20);
}

void playMelody() {
  const int MAX_DUR = 2000;
  for (size_t i = 0; i < sizeof(melody) / sizeof(melody[0]); i++) {
    int dur = durationsMs[i];
    if (dur > MAX_DUR) dur = MAX_DUR;
    playTone(melody[i], dur);
  }
}
void setup() {
  auto cfg = M5.config();
  M5.begin(cfg);

  ledcAttach(BUZZER_PIN, 2000, 8);

  M5.Display.clear();
  M5.Display.setTextDatum(middle_center);
  M5.Display.setTextSize(2);
  M5.Display.drawString("Wet Hands", M5.Display.width()/2, M5.Display.height()/2 - 10);
  M5.Display.setTextSize(1);
  M5.Display.drawString("Press M5 Button", M5.Display.width()/2, M5.Display.height()-18);
}

void loop() {
  M5.update();
  if (!played && M5.BtnA.wasPressed()) {
    played = true;
    M5.Display.clear();
    M5.Display.setTextSize(1);
    M5.Display.drawString("Playing...", M5.Display.width()/2, M5.Display.height()/2);
    playMelody();
    M5.Display.clear();
    M5.Display.setTextSize(2);
    M5.Display.drawString("Done", M5.Display.width()/2, M5.Display.height()/2);
  }
}
