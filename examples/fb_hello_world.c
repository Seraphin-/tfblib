/* SPDX-License-Identifier: BSD-2-Clause */

#include <stdio.h>
#include <tfblib/tfblib.h>
#include <tfblib/tfb_colors.h>
#include <unistd.h>

int main(int argc, char **argv)
{
   printf("Loaded.");
   int rc;

   if ((rc = tfb_acquire_fb(TFB_FL_USE_DOUBLE_BUFFER, NULL, NULL)) != TFB_SUCCESS) {
      fprintf(stderr, "tfb_acquire_fb() failed: %s\n", tfb_strerror(rc));
      return 1;
   }

   uint32_t w = tfb_screen_width();
   uint32_t h = tfb_screen_height();
   uint32_t rect_w = w / 2;
   uint32_t rect_h = h / 2;

   alarm(5);

   /* Paint the whole screen in black */
   tfb_clear_screen(tfb_black);
   while(usleep(10) == 0) {
       /* Draw some text on-screen */
       tfb_draw_string(10, 10, tfb_white, tfb_black, "Press ENTER to quit");

       /* Draw a red rectangle at the center of the screen */
       tfb_draw_rect(w / 2 - rect_w / 2,  /* x coordinate */
                     h / 2 - rect_h / 2,  /* y coordinate */
                     rect_w,              /* width */
                     rect_h,              /* height */
                     tfb_red              /* color */);

       tfb_flush_window();
   }

   tfb_release_fb();
   return 0;
}
