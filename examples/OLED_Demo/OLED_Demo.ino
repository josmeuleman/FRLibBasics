#include <U8x8lib.h>
U8X8_SSD1306_128X64_NONAME_SW_I2C u8x8(22, 21, U8X8_PIN_NONE);

void setup(void)
{
  u8x8.begin();
  u8x8.setPowerSave(0);

  u8x8.setFont(u8x8_font_pxplusibmcgathin_f);
  u8x8.drawString(0,0,"Hello World 209!");
  u8x8.drawString(0,3,"1234567890123456");
  u8x8.drawString(0,7,"Hello World 209!");
}

void loop(void)
{
}