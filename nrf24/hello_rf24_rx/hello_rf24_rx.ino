
// https://dzen.ru/a/YYIaUt9Bz32SgEZy
#include <SPI.h>               // Подключаем библиотеку SPI
#include <nRF24L01.h>          // Подключаем библиотеку nRF24L01
#include <RF24.h>              // Подключаем библиотеку RF24
#include <LiquidCrystal_I2C.h> // https://kit.alexgyver.ru/tutorials/lcd1602/
LiquidCrystal_I2C lcd(0x27, 16, 2);

RF24 radio(9, 10); // Указываем номера выводов nRF24L01: CE и CSN

const uint32_t pipe = 111156789; // адрес "трубы" - адрес приёмника

void setup()
{
  while (!Serial)
    ;                             // для Leonardo и т. п. плат ждёт пока откроем монитор порта
  Serial.begin(9600);             // устанавливаем скор. обмена данными 9600 бод
  radio.begin();                  // Инициируем работу nRF24L01
  radio.setChannel(0x6f);         // Устанавливаем канал
  radio.openReadingPipe(0, pipe); // Открываем "трубу" чтения
  radio.startListening();         // начинаем прослушивать

  lcd.init();      // инициализация LCD
  lcd.backlight(); // подсветка
}

void loop()
{
  if (radio.available())
  {                                  // если модуль получил информацию
    char text[32] = {0};             // переменная, хранящая текст сообщения
    radio.read(&text, sizeof(text)); // читаем текст сообщения
    Serial.println(text);            // выводим текст в монитор порта

    lcd.home();
    lcd.clear();
    lcd.print(text);
  }
}