#define SPEAKER_PIN D3

void initializeSpeaker(){
  pinMode(SPEAKER_PIN, OUTPUT);
}

void playTone(int frequency, int duration) { // frequency in hz, duration in ms
  tone(SPEAKER_PIN, frequency, duration);
  delay(duration);
  noTone(SPEAKER_PIN);
}

void playAlert(int frequency){ // frequency in hz
  playTone(frequency, 50);
  delay(100);
  playTone(frequency, 50);
  delay(100);
  playTone(frequency, 50);
}