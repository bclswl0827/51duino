#include <lcd.h>
#include <rtc.h>
#include <stream.h>

void main() {
    TimeData time;

    SerialBegin(9600);

    LcdInit();
    LcdClear();

    setTime(23, 3, 26, 18, 45, 10, 6);

    while (1) {
        SerialPrintln("Test123...");

        getTime(&time);

        LcdChar(0, 0, '2');
        LcdChar(1, 0, '0');
        LcdChar(2, 0, time.year / 10 + '0');
        LcdChar(3, 0, time.year % 10 + '0');
        LcdChar(4, 0, '-');
        LcdChar(5, 0, time.month / 10 + '0');
        LcdChar(6, 0, time.month % 10 + '0');
        LcdChar(7, 0, '-');
        LcdChar(8, 0, time.day / 10 + '0');
        LcdChar(9, 0, time.day % 10 + '0');

        LcdChar(0, 1, time.hour / 10 + '0');
        LcdChar(1, 1, time.hour % 10 + '0');
        LcdChar(2, 1, ':');
        LcdChar(3, 1, time.minute / 10 + '0');
        LcdChar(4, 1, time.minute % 10 + '0');
        LcdChar(5, 1, ':');
        LcdChar(6, 1, time.second / 10 + '0');
        LcdChar(7, 1, time.second % 10 + '0');
    }
}
