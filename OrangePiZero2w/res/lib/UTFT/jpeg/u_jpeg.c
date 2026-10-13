/*

исходники для jpeg библиотеки, взяты отсюда:
https://gitee.com/openLuat/LuatOS.git

*/

#include <string.h>


#define LUAT_LOG_TAG "ujpg"
#include "luat_log.h"

#include "tjpgd.h"
#include "tjpgdcnf.h"

#include "u_jpeg.h"

#define N_BPP (3 - JD_FORMAT)

/* Session identifier for input/output functions (name, members and usage are as user defined) */
typedef struct {
    FILE *fp;               /* Input stream */
    int x;
    int y;
    // int width;
    // int height;
//    uint16_t buff[16*16];
} IODEV;


static size_t file_in_func (JDEC* jd, uint8_t* buff, size_t nbyte){
    IODEV *dev = (IODEV*)jd->device;   /* Device identifier for the session (5th argument of jd_prepare function) */
    if (buff) {
        /* Read bytes from input stream */
        return luat_fs_fread(buff, 1, nbyte, dev->fp);
    } else {
        /* Remove bytes from input stream */
        return luat_fs_fseek(dev->fp, nbyte, SEEK_CUR) ? 0 : nbyte;
    }
}

//int (*outfunc)(JDEC*,void*,JRECT*)
static int lcd_out_func (JDEC* jd, void* bitmap, JRECT* rect){
    IODEV *dev = (IODEV*)jd->device;
//    uint16_t* tmp = (uint16_t*)bitmap;

    // rgb高低位swap
//    uint16_t count = (rect->right - rect->left + 1) * (rect->bottom - rect->top + 1);
//    for (size_t i = 0; i < count; i++)
//    {
      //dev->buff[i] = ((tmp[i] >> 8) & 0xFF)+ ((tmp[i] << 8) & 0xFF00);
//      dev->buff[i] = tmp[i]; //((tmp[i] >> 8) & 0xFF)+ ((tmp[i] << 8) & 0xFF00);
//    }

    // LLOGD("jpeg seg %dx%d %dx%d", rect->left, rect->top, rect->right, rect->bottom);
    // LLOGD("jpeg seg size %d %d %d", rect->right - rect->left + 1, rect->bottom - rect->top + 1, (rect->right - rect->left + 1) * (rect->bottom - rect->top + 1));
    luat_lcd_draw(default_conf, dev->x + rect->left, dev->y + rect->top,
                                dev->x + rect->right, dev->y + rect->bottom,
                                //dev->buff
                                bitmap);
    return 1;    /* Continue to decompress */
}


static int lcd_draw_jpeg(const char* path, int xpos, int ypos) {
  JRESULT res;      /* Result code of TJpgDec API */
  JDEC jdec;        /* Decompression object */
  void *work;       /* Pointer to the decompressor work area */
#if JD_FASTDECODE == 2
  size_t sz_work = 3500 * 3; /* Size of work area */
#else
  size_t sz_work = 3500; /* Size of work area */
#endif
  IODEV devid;      /* User defined device identifier */

  if (!(strstr (path, ".jpg") != NULL ||
        strstr (path, ".JPG") != NULL ||
        strstr (path, ".jpeg") != NULL ||
        strstr (path, ".JPEG") != NULL
      )) {
    LLOGW("no such file jpg %s", path);
    return -1;
  }

  FILE* fd = luat_fs_fopen(path, "r");
  if (fd == NULL) {
    LLOGW("no such file %s", path);
    return -1;
  }

  devid.fp = fd;
  work = luat_heap_malloc(sz_work);
  if (work == NULL) {
    LLOGE("out of memory when malloc jpeg decode workbuff");
    return -3;
  }
  res = jd_prepare(&jdec, file_in_func, work, sz_work, &devid);
  if (res != JDR_OK) {
    luat_heap_free(work);
    luat_fs_fclose(fd);
    LLOGW("jd_prepare file %s error %d", path, res);
    return -2;
  }
  devid.x = xpos;
  devid.y = ypos;
  // devid.width = jdec.width;
  // devid.height = jdec.height;
  res = jd_decomp(&jdec, lcd_out_func, 0);
  luat_heap_free(work);
  luat_fs_fclose(fd);
  if (res != JDR_OK) {
    LLOGW("jd_decomp file %s error %d", path, res);
    return -2;
  }
  else {
    //lcd_auto_flush(default_conf);
    return 0;
  }
}


int UTFT_ADD_lcd_draw_jpeg (const char* path, int xpos, int ypos)
{
return lcd_draw_jpeg(path,  xpos,  ypos);
}


#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>


int UTFT_scan_files_jpg(char *path)
{
    DIR *dir;
    struct dirent *entry;
    struct stat st;

    dir = opendir(path);
    if (dir == NULL) {
        perror(path);
        return -1;
    }

    while ((entry = readdir(dir)) != NULL) {
        // пропускаем "." и ".."
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;

        // полный путь: path + "/" + d_name
        char full[512];
        int n = snprintf(full, sizeof(full), "%s/%s", path, entry->d_name);
        if (n < 0 || (size_t)n >= sizeof(full)) {
            fprintf(stderr, "path too long: %s/%s\n", path, entry->d_name);
            continue;
        }

        if (stat(full, &st) != 0) {
            perror(full);
            continue;
        }

        if (S_ISDIR(st.st_mode)) {
            // рекурсивный обход подкаталога
            scan_files(full);
        } else if (S_ISREG(st.st_mode)) {
            printf("%s\n", full);

            // формируем "0:%s" для совместимости с FatFS-стилем путей,
            // если UTFT_ADD_lcd_draw_jpeg ожидает именно такой префикс
            char FileName[512];
            snprintf(FileName, sizeof(FileName), "%s", full);

            if (strstr (FileName, ".jpg") != NULL ||
                strstr (FileName, ".JPG") != NULL ||
                strstr (FileName, ".jpeg") != NULL ||
                strstr (FileName, ".JPEG") != NULL) {

                UTFT_ADD_lcd_draw_jpeg(FileName, 0, 0);
                // UTFT_loadBitmap(0, 0, 280, 240, FileName);

                UTFT_setFont(SmallFont);
                UTFT_setColor2(VGA_BLUE);
                UTFT_setBackColor2(VGA_TRANSPARENT);
                UTFT_print(entry->d_name, CENTER, 150, 0);

	      sleep (3);
            }
        }
    }

    closedir(dir);
    return 0;
}
