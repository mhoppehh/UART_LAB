#include "lcd.h"
#include "Timer.h"
#include "button.h"
#include "uart.h"

    int rl []= {3, 2, 25, 1, 1 ,1};
    char r1[] = "Yes";
    char r2[] = "No";
    char r3[] = "Blue, no green, Ahhhhh!!!";
    char r4[] = "@";
    char r5[] = "#";
    char r6[] = "$";

int main(){

    int8_t num = 0;
    char chr[21];
    lcd_init();
    button_init();
    uart_init();
    while(1){
        check_buttons();

        /*char temp = uart_receive();
        if(temp != 13){
            chr[num] = temp;
            uart_sendStr(chr[num]);
        }
        else {
            uart_sendStr(13); //13 = character return; 12 = form feed, 10 = line feed
            //uart_sendStr(12);
        }

        if(num == 19 || temp == 13){
            chr[20] = '\0';
            lcd_printf(chr);
            int i = 0;
            for(i=0; i < 20;i++){chr[i] = 0;}
            num = -1;
        }
        else{
            lcd_printf("Char: %c\nPos: %d", chr[num], num);
        }
        num++;*/
    }
}

int main(){//WIFI Main Method
    lcd_init();
    uart_init();
    WiFi_start("password");
    while(1){

    }
}


void check_buttons(){

    int button = button_getButton();
//    if(button > 0){//responses[button]
//        uart_sendStr("YES");
//        timer_waitMillis(100);
//        while(button != 0)button = button_getButton();
//    }


    if(button > 0){
        int i;
        for(i = 0; i < rl[button];i++){
            if(button == 1){uart_sendChar(r1[i]);}
            if(button == 2){uart_sendChar(r2[i]);}
            if(button == 3){uart_sendChar(r3[i]);}
            if(button == 4){uart_sendChar(r4[i]);}
            if(button == 5){uart_sendChar(r5[i]);}
            if(button == 6){uart_sendChar(r6[i]);}
        }
        while(button != 0)button = button_getButton();
    }
}
