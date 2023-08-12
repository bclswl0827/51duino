#include "framework/analog.h"

uint8_t _pwm_enable = 0;  // PWM 功能使能开关
uint8_t _pwm_pin = 0;     // PWM 引脚序号
uint8_t _pwm_timer = 0;   // PWM 中断次数记录
uint8_t _pwm_pulse = 0;   // analogWrite 的 value

// 初始化定时器 T0
void pwmInit() {
    // 设置定时器 T0 为工作模式 1
    TMOD = 0x01;
    // 除以 256 得到二进制高八位
    TH0 = _TH0;
    // 模除 256 得到二进制低八位
    TL0 = _TL0;
    EA = ET0 = TR0 = 1;
}

// analogWrite 启用后，单片机速度会严重下降
void analogWrite(uint8_t pin, uint8_t value) {
    // value 为 0 时关闭 PWM
    if (value) {
        _pwm_enable = 1;
        _pwm_pin = pin;
        _pwm_pulse = value;
        pwmInit();
    } else {
        _pwm_enable = 0;
    }
}

// 定时器 T0 中断
void pwmInterrupt() interrupt 1 {
    // 若启用 PWM 功能
    if (_pwm_enable) {
        // 清除中断标志位
        TR0 = 0;
        // 除以 256 得到二进制高八位
        TH0 = _TH0;
        // 模除 256 得到二进制低八位
        TL0 = _TL0;
        // 重新启动 T0
        TR0 = 1;
        // pwm 计数做自增
        _pwm_timer++;
        // 频率 1 kHz
        if (_pwm_timer >= 100) {
            _pwm_timer = 0;
        }
        // 占空比判断
        switch (_pwm_pin) {
            case PIN_PWM07:
                P07 = _pwm_timer <= _pwm_pulse ? HIGH : LOW;
                break;
            case PIN_PWM17:
                P17 = _pwm_timer <= _pwm_pulse ? HIGH : LOW;
                break;
            case PIN_PWM27:
                P27 = _pwm_timer <= _pwm_pulse ? HIGH : LOW;
                break;
            case PIN_PWM37:
                P37 = _pwm_timer <= _pwm_pulse ? HIGH : LOW;
                break;
            default:
                P07 = _pwm_timer <= _pwm_pulse ? HIGH : LOW;
                break;
        }
    } else {
        // 关闭所有 PWM 引脚
        P07 = P17 = P27 = P37 = LOW;
    }
}
