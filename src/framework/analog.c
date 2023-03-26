#include <analog.h>

uint_least8_t _pwm = 0,  // PWM 功能使能开关
    _pin = 0,            // PWM 引脚序号
    _timer = 0,          // PWM 中断次数记录
    _pulse = 0;          // analogWrite 的 value

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
void analogWrite(uint_least8_t pin, uint_least8_t value) {
    // value 为 0 时关闭 PWM
    if (value) {
        _pwm = 1;
        _pin = pin;
        _pulse = value;
        pwmInit();
    } else {
        _pwm = 0;
    }
}

// 定时器 T0 中断
void pwmInterrupt() interrupt 1 {
    // 若启用 PWM 功能
    if (_pwm) {
        // 清除中断标志位
        TR0 = 0;
        // 除以 256 得到二进制高八位
        TH0 = _TH0;
        // 模除 256 得到二进制低八位
        TL0 = _TL0;
        // 重新启动 T0
        TR0 = 1;
        // pwm 计数做自增
        _timer++;
        // 频率 1 kHz
        if (_timer >= 100) {
            _timer = 0;
        }
        // 占空比判断
        if (_timer <= _pulse) {
            switch (_pin) {
                case 0:
                    P07 = HIGH;
                    break;
                case 1:
                    P17 = HIGH;
                    break;
                case 2:
                    P27 = HIGH;
                    break;
                case 3:
                    P37 = HIGH;
                    break;
                default:
                    P07 = HIGH;
                    break;
            }
        } else {
            switch (_pin) {
                case 0:
                    P07 = LOW;
                    break;
                case 1:
                    P17 = LOW;
                    break;
                case 2:
                    P27 = LOW;
                    break;
                case 3:
                    P37 = LOW;
                    break;
                default:
                    P07 = LOW;
                    break;
            }
        }
    } else {
        // 关闭 PWM 引脚
        P07 = P17 = P27 = P37 = LOW;
    }
}
