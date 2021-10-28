/*
   Пример простого многостраничного меню (F macro)
*/

#define OLED_SOFT_BUFFER_64     // Буфер на стороне МК
#include <GyverOLED.h>          // Библиотека дисплея
GyverOLED<SSD1306_128x64, OLED_BUFFER> oled;

#include <GyverButton.h>      // Либа кнопок
GButton up(0, HIGH_PULL); // Кнопки
GButton down(16, HIGH_PULL);
GButton ok(2, HIGH_PULL);
int slide = 0;
#define ITEMS 24               // Общее кол во пунктов (больше 8 - нужно несколько страниц)

// Битмап с картинкой стрелочки (Если нужен)
const uint8_t ptr_bmp[] PROGMEM = {
  0x3C, 0x3C, 0x3C, 0x3C, 0x3C, 0xFF, 0xFF, 0x7E, 0x3C, 0x18,
};

const unsigned char icons_32x32[][72] PROGMEM = {
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF8,
     0xFC, 0xFC, 0xFC, 0xFC, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x00,
     0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
     0x00, 0xC0, 0xF0, 0xBF, 0x3F, 0x3F, 0x3F, 0x3F, 0xFF, 0xF0,
     0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
     0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x07, 0x0F, 0x0E, 0x0C,
     0x0C, 0x0E, 0x0E, 0x07, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
     0x00, 0x00},
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF8,
     0xFC, 0xFC, 0xFC, 0xFC, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x00,
     0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
     0x00, 0xC0, 0xF0, 0xBF, 0x3F, 0x3F, 0x3F, 0x3F, 0xFF, 0xF0,
     0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
     0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x07, 0x0F, 0x0E, 0x0C,
     0x0C, 0x0E, 0x0E, 0x07, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
     0x00, 0x00},
};

const char *text[] ={ 
  "текст1",
  "ТЭкст2",
};
void setup() {
  oled.init();           // Инциализация дисплея
  oled.setContrast(255); // Макс. яркость
}

void loop() {
    up.tick();                 // Опрос кнопок
  down.tick();
  ok.tick();
  oled.clear();
  oled.println(text[slide]);
oled.drawBitmap(30, 30, icons_32x32[slide], 24, 24);
  oled.update();

  /* Кнопки */


  if (up.isClick() or up.isHold()) {                // Если кнопку нажали или удерживают
    slide++; // Двигаем указатель в пределах дисплея
  }

  if (down.isClick() or down.isHold()) {
    slide--;
  }

//  if (ok.isClick()) {   // Нажатие на ОК - переход в пункт меню
//    switch (pointer) {  // По номеру указателей располагаем вложенные функции (можно вложенные меню)
//      case 0: func(); break;  // По нажатию на ОК при наведении на 0й пункт вызвать функцию
//      case 1: break;
//      case 2: break;
//      case 3: break;
//      case 4: break;
//      case 5: break;
//      case 6: break;
//      case 7: break;
//        // И все остальные
//    }
  }

  /* меню */
//  oled.clear();           // Очищаем буфер
//  oled.home();            // Курсор в левый верхний угол

//  if (pointer < 8) {      // Первая страница
//    oled.println("Parameter 1");
//    oled.println("Parameter 2");
//    oled.println("Parameter 2");
//    oled.println("Parameter 3");
//    oled.println("Parameter 4");
//    oled.println("Parameter 5");
//    oled.println("Parameter 6");
//    oled.println("Parameter 7");
//  } else if (pointer < 16) {// Вторая страница
//    oled.print
//    (F(
//       "  Parameter 8:\n"
//       "  Parameter 9:\n"
//       "  Parameter 10:\n"
//       "  Parameter 11:\n"
//       "  Parameter 12:\n"
//       "  Parameter 13:\n"
//       "  Parameter 14:\n"
//       "  Parameter 15:\n"
//     ));
//  } else {                  // Последняя страница
//    oled.print
//    (F(
//       "  Parameter 16:\n"
//       "  Parameter 17:\n"
//       "  Parameter 18:\n"
//       "  Parameter 19:\n"
//       "  Parameter 20:\n"
//       "  Parameter 21:\n"
//       "  Parameter 22:\n"
//       "  Parameter 23:\n"
//     ));
//  }
//
//  printPointer(pointer);  // Вывод указателя
//  oled.update();          // Выводим кадр на дисплей
//}
//void printPointer(uint8_t pointer) {
//  // Символьный указатель - лучший выбор в многостраничном меню
//  // Указатель в начале строки
//  oled.setCursor(0, pointer);
//  oled.print(">");
//  // Можно еще в конце
//  /*oled.setCursor(20, pointer);
//    oled.print("<");*/
//  // Указатель в виде прямоугольной рамки со скругленными углами
//  /*oled.roundRect(0, pointer * 8, 127, (pointer * 8) + 6);*/
//  // Указатель в виде битмапа (картинки)
//  /*oled.drawBitmap(0, pointer * 8, ptr_bmp, 10, 8);*/
//}
//
///* пример вложеной функции, которую можно вызвать из под меню */
//void func(void) {
//  oled.clear();
//  oled.home();
//  oled.print(F("Press OK to return"));
//  oled.update();
//  while (1) {
//    ok.tick();
//    if (ok.isClick()) return; // return возвращает нас в предыдущее меню
//  }
//}
