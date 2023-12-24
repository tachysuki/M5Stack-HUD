#include <M5Core2.h>
#define LGFX_M5STACK_CORE2
#define LGFX_AUTODETECT
#include <LovyanGFX.hpp>


float pitch = 0.0F;
float roll = 0.0F;
float yaw = 0.0F;
static LGFX lcd;
static LGFX_Sprite sprite(&lcd);
int correction_y = 75;


void setup() {
  // put your setup code here, to run once:
  M5.begin();
    lcd.init();
    sprite.printf("Startup ...");
    sprite.printf("Initialized LCD");
    lcd.setBrightness(255);
    M5.IMU.Init();
    sprite.setTextColor(GREEN);
    sprite.printf("Initialized IMU");
    lcd.setTextColor(
        GREEN,
        BLACK);
    lcd.setTextSize(2);
    sprite.setColorDepth(8);
    sprite.createSprite(lcd.width()+30, lcd.height()+30);
    sprite.printf("Completed Startup");
}

void loop() {
  // put your main code here, to run repeatedly:

  M5.IMU.getAhrsData(
        &pitch, &roll,
        &yaw);

    M5.Lcd.setTextColor(GREEN);
    sprite.fillScreen(BLACK);
    sprite.setCursor(-50,-50);
    sprite.drawFastHLine(-50, 120 - (int)(roll * 7.5F) - correction_y, 400, GREEN);
    sprite.drawCircle(160 + (int)(pitch * 3.75F), 120 + (int)(roll * 0.1F), 5, RED);
    sprite.setPivot(sprite.width()/2.0 - 15, sprite.height()/2.0);

    //5~180
    for (int i = 1; i <= 36; i++){
      sprite.setCursor(85, (120+78*i) - int(roll * 7.5F) - correction_y - 2.5F);
      sprite.printf("+%d", 10*i);
      sprite.drawFastHLine(105, (120+78*i) - int(roll * 7.5F) - correction_y, 50, GREEN);
      sprite.drawFastHLine(225, (120+78*i) - int(roll * 7.5F) - correction_y, 50, GREEN);
      sprite.setCursor(280, (120+78*i) - int(roll * 7.5F) - correction_y - 2.5F);
      sprite.printf("+%d", 10*i);
    }

    //-5~-175
    for (int j = 1; j <= 36; j++){
      sprite.setCursor(85, (120-78*j) - int(roll * 7.5F) - correction_y - 2.5F);
      sprite.printf("-%d", 10*j);
      sprite.drawFastHLine(105, (120-78*j) - int(roll * 7.5F) - correction_y, 7.5F, GREEN);
      sprite.drawFastHLine(117.5F, (120-78*j) - int(roll * 7.5F) - correction_y, 7.5F, GREEN);
      sprite.drawFastHLine(130, (120-78*j) - int(roll * 7.5F) - correction_y, 7.5F, GREEN);
      sprite.drawFastHLine(142.5F, (120-78*j) - int(roll * 7.5F) - correction_y, 7.5F, GREEN);

      sprite.drawFastHLine(225, (120-78*j) - int(roll * 7.5F) - correction_y, 7.5F, GREEN);
      sprite.drawFastHLine(237.5F, (120-78*j) - int(roll * 7.5F) - correction_y, 7.5F, GREEN);
      sprite.drawFastHLine(250, (120-78*j) - int(roll * 7.5F) - correction_y, 7.5F, GREEN);
      sprite.drawFastHLine(262.5F, (120-78*j) - int(roll * 7.5F) - correction_y, 7.5F, GREEN);

      sprite.setCursor(280, (120-78*j) - int(roll * 7.5F) - correction_y - 2.5F);
      sprite.printf("-%d", 10*j);
    }

    sprite.setCursor(80,80);
    sprite.printf("angle: %f", roll+11);

    sprite.setRotation(6);
    sprite.pushRotateZoom(160, 120, int(pitch), 1.5F, 1.5F);



}
