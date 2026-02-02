#include <Arduino.h>
#include <M5Unified.h>

#define BUZZER_PIN 2
#define NOTE_REST 0

// ===== start of arduino buzzer song so kewl!11!111 =====
#define NOTE_REST 0
#define NOTE_C2 65
#define NOTE_B1 62
#define NOTE_A4 440
#define NOTE_Cs5 554
#define NOTE_E5 659
#define NOTE_Gs5 831
#define NOTE_Fs5 740
#define NOTE_B4 494
#define NOTE_D5 587
#define NOTE_A5 880
#define NOTE_F5 698
#define NOTE_G5 784
#define NOTE_Gs4 415
#define NOTE_As4 466
#define NOTE_C5 523
#define NOTE_Fs4 370

int melody[] = { NOTE_C2, NOTE_B1, NOTE_C2, NOTE_B1, NOTE_C2, NOTE_C2, NOTE_C2, NOTE_B1, NOTE_C2, NOTE_B1, NOTE_C2, NOTE_A4, NOTE_Cs5, NOTE_E5, NOTE_Gs5, NOTE_Fs5, NOTE_E5, NOTE_Cs5, NOTE_A4, NOTE_B4, NOTE_D5, NOTE_Fs5, NOTE_A5, NOTE_Gs5, NOTE_A4, NOTE_Cs5, NOTE_E5, NOTE_Gs5, NOTE_Fs5, NOTE_E5, NOTE_Cs5, NOTE_A4, NOTE_B4, NOTE_D5, NOTE_Fs5, NOTE_A5, NOTE_Gs5, NOTE_F5, NOTE_Fs5, NOTE_Gs5, NOTE_Fs5, NOTE_E5, NOTE_Gs5, NOTE_Fs5, NOTE_E5, NOTE_Cs5, NOTE_A4, NOTE_Gs5, NOTE_Gs5, NOTE_G5, NOTE_Gs5, NOTE_Gs4, NOTE_As4, NOTE_C5, NOTE_Cs5, NOTE_A5, NOTE_A5, NOTE_Gs5, NOTE_A5, NOTE_A5, NOTE_Gs5, NOTE_D5, NOTE_D5, NOTE_Cs5, NOTE_D5, NOTE_Fs4, NOTE_Gs4, NOTE_As4, NOTE_B4, NOTE_Gs5, NOTE_Gs5, NOTE_Fs5, NOTE_Gs5, NOTE_Fs5 };
int durationsMs[] = { 136, 136, 136, 136, 136, 136, 136, 136, 136, 136, 136, 273, 273, 273, 273, 273, 273, 273, 273, 273, 273, 273, 273, 545, 273, 273, 273, 273, 273, 273, 273, 273, 273, 273, 273, 273, 545, 273, 273, 273, 1636, 273, 273, 273, 273, 273, 273, 273, 273, 273, 273, 273, 273, 273, 273, 273, 273, 273, 273, 545, 273, 273, 273, 273, 545, 273, 273, 273, 273, 273, 273, 273, 818, 273 };
// ===== end of buzzer song bwabwabwabwab =====

bool playing = false;
bool paused = false;
bool stopped = false;
size_t currentNote = 0;
unsigned long noteStartTime = 0;
int buzzerVolume = 255; // if your wondering this doesnt do shit yet, im working on it
int noteDuration = 0;

void startNote(size_t i) {
  int freq = melody[i];
  noteDuration = durationsMs[i];
  if (noteDuration > 2000) noteDuration = 2000;
  if (freq == NOTE_REST) {
    ledcWriteTone(BUZZER_PIN, 0);
  } else {
    ledcWriteTone(BUZZER_PIN, freq);
    ledcWrite(BUZZER_PIN, buzzerVolume);
  }
  noteStartTime = millis();
}

void stopNote() {
  ledcWriteTone(BUZZER_PIN, 0);
}

void setup() {
  auto cfg = M5.config();
  M5.begin(cfg);

  ledcAttach(BUZZER_PIN, 2000, 8);

  M5.Display.clear();
  M5.Display.setTextDatum(middle_center);
  M5.Display.setTextSize(5);
  M5.Display.drawString("Midi", M5.Display.width()/2, M5.Display.height()/2 - 10);
  M5.Display.setTextSize(1);
  M5.Display.drawString("Press BtnA", M5.Display.width()/2, M5.Display.height()-18);
}

void loop() {
  M5.update();

  if (!playing && M5.BtnA.wasPressed()) {
    playing = true;
    paused = false;
    stopped = false;
    currentNote = 0;
    M5.Display.clear();
    M5.Display.setTextSize(3);
    M5.Display.drawString("Playing...", M5.Display.width()/2, M5.Display.height()/2);
    startNote(currentNote);
  }

  if (playing && M5.BtnB.wasPressed()) {
    paused = !paused;
    if (paused) {
      stopNote();
      M5.Display.clear();
      M5.Display.setTextSize(2);
      M5.Display.drawString("Paused", M5.Display.width()/2, M5.Display.height()/2);
    } else {
      noteStartTime = millis();
      M5.Display.clear();
      M5.Display.setTextSize(2);
      M5.Display.drawString("Resumed", M5.Display.width()/2, M5.Display.height()/2);
    }
    delay(300);
  }

  if (playing && M5.BtnC.wasPressed()) {
    stopped = true;
    playing = false;
    paused = false;
    stopNote();
    M5.Display.clear();
    M5.Display.setTextSize(2);
    M5.Display.drawString("Stopped", M5.Display.width()/2, M5.Display.height()/2);
    delay(500);
  }

  if (playing && !paused && !stopped) {
    if (millis() - noteStartTime >= noteDuration + 20) { 
      stopNote();
      currentNote++;
      if (currentNote >= sizeof(melody)/sizeof(melody[0])) {
        playing = false;
        M5.Display.clear();
        M5.Display.setTextSize(2);
        M5.Display.drawString("Done", M5.Display.width()/2, M5.Display.height()/2);
      } else {
        startNote(currentNote);
      }
    }
  }
}
