#ifndef __MODULE_STREAM__H
#define __MODULE_STREAM__H

// 透过 struct 模拟实现 Stream 的 class
typedef struct {
    void (*begin)(uint16_t b);
    void (*setTimeout)(uint16_t t);
    void (*flush)(void);
    void (*end)(void);
    void (*print)(char* s);
    void (*println)(char* s);
    int (*printf)(char*, ...);
    void (*write)(char c);
    char (*read)(void);
    uint8_t (*available)(void);
} Stream;

#endif