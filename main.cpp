typedef unsigned char   uint8_t;
typedef unsigned short  uint16_t;
typedef unsigned long   uint32_t;
typedef char            bool;

#define BLACK           0x0
#define BLUE            0x1
#define GREEN           0x2
#define CYAN            0x3
#define RED             0x4
#define MAGENTA         0x5
#define BROWN           0x6
#define GREY            0x7
#define DARK_GREY       0x8
#define LIGHT_BLUE      0x9
#define LIGHT_GREEN     0xA
#define LIGHT_CYAN      0xB
#define LIGHT_RED       0xC
#define LIGHT_MAGENTA   0xD
#define LIGHT_BROWN     0xE
#define WHITE           0xF

#define true            0x1
#define false           0x0

#define HELLO_STR "Hello world!"

static uint16_t StringLen(
    const char far* string) {

    uint16_t l = 0;
    for (;*string; ++l, ++string);

    return l;
}

void TextOut(
    const char far* string,
    uint8_t         x,
    uint8_t         y,
    uint8_t         bg,
    uint8_t         fg,
    bool            inUpdateCursor
    )
{
    uint8_t att = ((fg) | (bg << 4));
    uint8_t len = StringLen(string);

    __asm
    {
        push bp
        mov  al, inUpdateCursor
        xor  bh, bh
        mov  bl, att
        xor  cx, cx
        mov  cl, len
        mov  dh, y
        mov  dl, x
        mov  es, word ptr[string + 2]
        mov  bp, word ptr[string]
        mov  ah, 13h
        int  10h
        pop  bp
    }
}

void ClearScreen() {
    __asm
    {
        mov     al, 02h
        mov     ah, 00h
        int     10h
    } 
}

void ShowCursor(bool inMode) {
    uint8_t flag = inMode ? 0 : 0x32;
    __asm
    {
        mov     ch, flag
        mov     cl, 0Ah
        mov     ah, 01h
        int     10h
    }
}

extern "C" void BootMain()
{
    ClearScreen();
    ShowCursor(false);

    TextOut(
        HELLO_STR,
        1,
        1,
        BLACK,
        WHITE,
        false
        );

    for(;;);
}
