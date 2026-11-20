struct gd_1_u8 { u8 pad[0x1]; u8 v; };
struct gd_2_s16 { u8 pad[0x2]; s16 v; };
struct gd_2_s8 { u8 pad[0x2]; s8 v; };
struct gd_2_u8 { u8 pad[0x2]; u8 v; };
struct gd_3_s8 { u8 pad[0x3]; s8 v; };
struct gd_3_u8 { u8 pad[0x3]; u8 v; };
extern s8 D_800A8F98;
extern s8 D_800A8F99;
extern s8 D_800A8F9A;
extern s8 D_800A8F9B;

void f(s32 arg0) {
    ((struct gd_2_s8 *)arg0)->v = ((struct gd_2_u8 *)arg0)->v + ((struct gd_3_u8 *)arg0)->v;
    if (((struct gd_2_s8 *)arg0)->v >= 2) {
        ((struct gd_3_s8 *)arg0)->v = ((struct gd_3_u8 *)arg0)->v - 2;
    } else {
        if (((struct gd_2_s8 *)arg0)->v < -1) {
            ((struct gd_3_s8 *)arg0)->v = ((struct gd_3_u8 *)arg0)->v + 2;
        } else {
            if (((struct gd_3_s8 *)arg0)->v >= 2) {
                ((struct gd_3_s8 *)arg0)->v = ((struct gd_3_u8 *)arg0)->v - 2;
            } else {
                if (((struct gd_3_s8 *)arg0)->v < -1) {
                    ((struct gd_3_s8 *)arg0)->v = ((struct gd_3_u8 *)arg0)->v + 2;
                } else {
                    ((struct gd_2_s16 *)arg0)->v = 0;
                }
            }
        }
    }
    D_800A8F98 = *(u8 *)arg0;
    D_800A8F99 = ((struct gd_1_u8 *)arg0)->v;
    D_800A8F9A = ((struct gd_2_u8 *)arg0)->v;
    D_800A8F9B = ((struct gd_3_u8 *)arg0)->v;
}
