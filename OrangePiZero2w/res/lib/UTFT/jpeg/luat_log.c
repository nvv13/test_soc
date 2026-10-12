#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>     // va_list, va_start, va_end — нужны для luat_log_printf
#include "UTFT.h"

#define LUAT_LOG_TAG "log"
#include "luat_log.h"

#ifndef LUAT_WEAK
#define LUAT_WEAK __attribute__((weak))
#endif

#define LOGLOG_SIZE 100
static char log_printf_buff[LOGLOG_SIZE];

luat_lcd_conf_t* default_conf = NULL;

LUAT_WEAK void luat_log_printf(int level, const char* _fmt, ...) {
    size_t len;
    va_list args;
    //if (luat_log_level_cur > level) return;
    va_start(args, _fmt);
    len = vsnprintf(log_printf_buff, LOGLOG_SIZE, _fmt, args);
    va_end(args);
    if (len > 0) {
        //luat_log_write(log_printf_buff, len);
        printf("%s\n", log_printf_buff);
    }
}

// ---------------- файловые обёртки поверх stdio ----------------

FILE* luat_fs_fopen(const char *filename, const char *mode)
{
    // POSIX: fopen сам разбирается с mode ("rb", "r", "wb", ...)
    return fopen(filename, mode);
}

size_t luat_fs_fread(void *ptr, size_t size, size_t nmemb, FILE *stream)
{
    if (!stream || !ptr || size == 0 || nmemb == 0)
        return 0;
    return fread(ptr, size, nmemb, stream);
}

int luat_fs_fseek(FILE* stream, long int offset, int origin)
{
    if (!stream)
        return -1;
    // stdio:fseek уже принимает SEEK_SET/SEEK_CUR/SEEK_END
    return (fseek(stream, offset, origin) == 0) ? 0 : -1;
}

long luat_fs_ftell(FILE* stream)
{
    if (!stream)
        return -1;
    return ftell(stream);
}

int luat_fs_fclose(FILE* stream)
{
    if (!stream)
        return -1;
    return (fclose(stream) == 0) ? 0 : -1;
}

// ---------------- LCD ----------------

int luat_lcd_draw(luat_lcd_conf_t* conf,
                  uint16_t x1, uint16_t y1,
                  uint16_t x2, uint16_t y2,
                  luat_color_t* color)
{
    UTFT_drawBitmap24bpp(x1, y1, x2 - x1 + 1, y2 - y1 + 1, color);
    return 0;
}
