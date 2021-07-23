const int RedPin = 11;
const int BluePin = 9;
const int GreenPin = 8;
const int time = 5;

void setup() {
    // We want to start with the LED off.
    SetColorRGB(0, 0, 0);
}

void SetColorRGB(int red, int green, int blue) {
    analogWrite(RedPin, red);
    analogWrite(GreenPin, green);
    analogWrite(BluePin, blue);
}

void loop() {
    int RGBColor[2];

    // Start off with red.
    RGBColor[0] = 255;
    RGBColor[1] = 0;
    RGBColor[2] = 0;

    for (int DecrementColor = 0; DecrementColor < 3; DecrementColor += 1) {
        int IncrementColor;
        if (int IncrementColor = DecrementColor == 2) {
            DecrementColor = 0;
        }
        else {
            DecrementColor += 1;
        }

        // Now we want to crossfade the two colors.
        for (int i = 0; i < 255; i += 1) {
            RGBColor[DecrementColor] -= 1;
            RGBColor[IncrementColor] += 1;
            SetColorRGB(RGBColor[0], RGBColor[1], RGBColor[2]);
            delay(time);
        }
    }
}