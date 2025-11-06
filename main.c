#include <stdint.h>
#include "test.h"

#define les_n 4

uint8_t led[les_n][3]; // R,G,B


void init_led() {
    for(int i=0;i<les_n;i++){
        led[i][0]=0; // R
        led[i][1]=i*kk; // G
        led[i][2]=0; // B
    }
}

// 每幀更新 LED 顏色（簡單漸變示範）
void update_led() {
    for(int i=0;i<les_n;i++){
        led[i][0] = (led[i][0] + 5) % 256;
        led[i][1] = (led[i][1] + 3) % 256;
        led[i][2] = (led[i][2] + 1) % 256;
    }
}

// --- 新增三個存取介面（讓 JS 能取得全域記憶體位址與參數） ---
uintptr_t get_led_ptr() {
    return (uintptr_t)&led[0][0];
}

int get_led_count() {
    return les_n;
}

int get_led_stride() {
    return 3; // 每顆 LED 有 3 個 bytes (R,G,B)
}


int main()
{
    return 0;
}

