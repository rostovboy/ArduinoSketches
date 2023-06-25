// https://dzen.ru/a/YYIaUt9Bz32SgEZy
#include <SPI.h>      // Подключаем библиотеку SPI
#include <nRF24L01.h> // Подключаем библиотеку nRF24L01
#include <RF24.h>     // Подключаем библиотеку RF24

RF24 radio(9, 10); // CE и CSN (9, 10) у Arduino Uno и (9, 53) у Arduino Mega

const uint32_t pipe = 111156789; // адрес "трубы" - адрес передатчика

void setup()
{
  radio.begin();               // Инициируем работу nRF24L01
  radio.setChannel(0x6f);      // Устанавливаем канал
  radio.openWritingPipe(pipe); // Открываем "трубу" отправки данных
  radio.stopListening();       // Прекращаем прослушивание
}

void loop()
{
  const char text[] = "Hello";  // Текст сообщения
  const char text2[] = "Hello World";     // Текст сообщения
  radio.write(&text, sizeof(text));   // Отсылаем текст
  delay(3000);                        // Задержка 1с
  radio.write(&text2, sizeof(text2)); // Отсылаем текст
  delay(3000);                        // Задержка 1с
}