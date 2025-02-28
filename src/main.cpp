#include <Arduino.h>

// Pin untuk tombol pada ESP32
const int button1 = 33;  
const int button2 = 34;  
const int button3 = 35;  

// Pin untuk LED pada ESP32
const int ledRed = 25;    
const int ledYellow = 26; 
const int ledGreen = 27;  

void setup() {
    // Konfigurasi pin tombol sebagai input dengan pull-up internal
    pinMode(button1, INPUT_PULLUP);
    pinMode(button2, INPUT_PULLUP);
    pinMode(button3, INPUT_PULLUP);
    
    // Konfigurasi pin LED sebagai output
    pinMode(ledRed, OUTPUT);
    pinMode(ledYellow, OUTPUT);
    pinMode(ledGreen, OUTPUT);
}

void loop() {
    // Jika tombol 1 ditekan, LED merah berkedip 5 kali
    if (digitalRead(button1) == LOW) {
        for (int i = 0; i < 5; i++) {
            digitalWrite(ledRed, HIGH);
            delay(300);
            digitalWrite(ledRed, LOW);
            delay(300);
        }
    }
    
    // Jika tombol 2 ditekan, LED merah dan hijau berkedip bergantian sebanyak 5 kali
    if (digitalRead(button2) == LOW) {
        for (int i = 0; i < 5; i++) {
            digitalWrite(ledRed, HIGH);
            digitalWrite(ledGreen, LOW);
            delay(300);
            digitalWrite(ledRed, LOW);
            digitalWrite(ledGreen, HIGH);
            delay(300);
        }
        // Pastikan LED hijau mati setelah kedipan selesai
        digitalWrite(ledGreen, LOW);
    }
    
    // Jika tombol 3 ditekan, LED merah, kuning, dan hijau berkedip bergantian sebanyak 5 kali
    if (digitalRead(button3) == LOW) {
        for (int i = 0; i < 5; i++) {
            digitalWrite(ledRed, HIGH);
            delay(300);
            digitalWrite(ledRed, LOW);
            digitalWrite(ledYellow, HIGH);
            delay(300);
            digitalWrite(ledYellow, LOW);
            digitalWrite(ledGreen, HIGH);
            delay(300);
            digitalWrite(ledGreen, LOW);
        }
    }
}
