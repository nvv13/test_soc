#ifndef LAUT_LOG
#define LAUT_LOG

#ifdef __cplusplus
extern "C" {
#endif

#include "tjpgdcnf.h"

#include <stdlib.h>
#include <stdio.h>   // FILE, size_t, fopen, fread, fseek, fclose

#ifndef tls_mem_alloc
#define tls_mem_alloc(n)  malloc(n)
#endif
#ifndef tls_mem_free
#define tls_mem_free(p)   free(p)
#endif

#define luat_heap_malloc tls_mem_alloc
#define luat_heap_free   tls_mem_free
//#define realloc luat_heap_realloc
//#define zalloc luat_heap_zalloc
//#define calloc luat_heap_calloc

#define LUAT_LOG_DEBUG 1
#define LUAT_LOG_INFO  2
#define LUAT_LOG_WARN  3
#define LUAT_LOG_ERROR 4
#define LUAT_LOG_CLOSE 7

#define LLOGE(format, ...) luat_log_printf(LUAT_LOG_ERROR, "E/" LUAT_LOG_TAG " " format "\n", ##__VA_ARGS__)
#define LLOGW(format, ...) luat_log_printf(LUAT_LOG_WARN,  "W/" LUAT_LOG_TAG " " format "\n", ##__VA_ARGS__)
#define LLOGI(format, ...) luat_log_printf(LUAT_LOG_INFO,  "I/" LUAT_LOG_TAG " " format "\n", ##__VA_ARGS__)
#define LLOGD(format, ...) luat_log_printf(LUAT_LOG_DEBUG, "D/" LUAT_LOG_TAG " " format "\n", ##__VA_ARGS__)
void luat_log_printf(int level, const char* _fmt, ...);

// --- Файловые обёртки теперь поверх stdio ---
// FILE уже определён в <stdio.h>, отдельный typedef не нужен.

FILE*  luat_fs_fopen(const char *filename, const char *mode);
size_t luat_fs_fread(void *ptr, size_t size, size_t nmemb, FILE *stream);
int    luat_fs_fseek(FILE* stream, long int offset, int origin);
int    luat_fs_fclose(FILE* stream);
long   luat_fs_ftell(FILE* stream);   // может пригодиться

typedef struct luat_lcd_conf {
    void* userdata;
} luat_lcd_conf_t;

extern luat_lcd_conf_t* default_conf;

int luat_lcd_draw(luat_lcd_conf_t* conf,
                  uint16_t x1, uint16_t y1,
                  uint16_t x2, uint16_t y2,
                  luat_color_t* color);

#ifdef __cplusplus
}
#endif

#endif /* LAUT_LOG */
