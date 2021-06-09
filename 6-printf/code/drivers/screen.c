#include"../include/screen.h"
#include"../include/asm.h"

int getCursorOffset();
void setCursorOffset(int offset);

int getOffset(int row,int col);
int getCurrentRow(int offset);
int getCurrentCol(int offset);


void clearScreen()
{
    int screenSize = MAX_COLS * MAX_ROWS;
    unsigned char* mem = (unsigned char*)VIDEO_ADDRESS;
    for(int i = 0;i < screenSize;i++){
        mem[i * 2] = ' ';
        mem[i * 2 + 1] = WHITE_ON_BLACK;
    }
    setCursorOffset(getOffset(0,0));
}

void putChar(char character, int row,int col, char attr)
{
    unsigned char* screen = (unsigned char*)VIDEO_ADDRESS;
    if(!attr)attr = WHITE_ON_BLACK;
    if(col >= MAX_COLS || row >= MAX_ROWS){
        int pos = MAX_COLS * MAX_ROWS * 2;
        screen[pos - 2] = 'E';
        screen[pos - 1] = RED_ON_WHITE;
        return;
    }

    int offset;
    if(col < 0 && row < 0){//直接在当前光标处输出
        offset = getCursorOffset();
    }
    else{//否则输出到指定位置
        offset = getOffset(row,col);
    }

    if(character == '\n'){//换行符处理
        row = getCurrentRow(offset);
        offset = getOffset(row + 1,0);
    }
    else{
        screen[offset] = character;
        screen[offset + 1] = attr;
        offset += 2;
    }

    setCursorOffset(offset);
}

void printChar(char c)
{
    putChar(c,-1,-1,0);
}

int getOffset(int row, int col)
{
    return (row * MAX_COLS + col) * 2;
}

int getCurrentRow(int offset)
{
    return offset / (2 * MAX_COLS);
}

int getCurrentCol(int offset)
{
    return (offset - getCurrentRow(offset) * 2 * MAX_COLS) / 2;
}

int getCursorOffset()
{
    outb(REG_SCREEN_CTRL, 14);
    int offset = inb(REG_SCREEN_DATA) << 8;
    outb(REG_SCREEN_CTRL, 15);
    offset += inb(REG_SCREEN_DATA);
    return offset * 2; 
}

void setCursorOffset(int offset)
{
    offset /= 2;
    outb(REG_SCREEN_CTRL, 14);
    outb(REG_SCREEN_DATA, (unsigned char)(offset >> 8));
    outb(REG_SCREEN_CTRL, 15);
    outb(REG_SCREEN_DATA, (unsigned char)(offset & 0xff));
}