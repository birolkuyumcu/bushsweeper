#ifndef CELL_H
#define CELL_H

#include <FL/Fl_Box.H>
#include <FL/Fl_Group.H>
#include <string.h>
#include <FL/Fl_Image.H>
static unsigned char idata_Bushicn[] =
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,244,238,236,255,164,158,
140,255,148,138,124,255,140,134,116,255,148,142,132,255,164,162,148,255,220,214,
212,255,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,196,190,180,255,84,74,60,255,76,58,44,255,84,70,44,
255,84,70,44,255,100,82,60,255,92,70,52,255,60,54,36,255,132,122,100,255,220,
222,220,255,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,188,186,180,255,68,54,36,255,60,46,28,255,76,62,36,255,84,70,44,255,84,74,
52,255,100,90,68,255,100,82,60,255,108,78,52,255,76,62,36,255,100,86,60,255,
180,178,172,255,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,220,222,
220,255,60,54,36,255,68,50,28,255,68,58,36,255,84,70,44,255,92,70,52,255,100,82,
60,255,108,94,76,255,100,78,60,255,124,90,68,255,132,94,68,255,92,70,44,255,76,
66,52,255,204,202,196,255,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,100,
98,92,255,60,50,36,255,76,62,36,255,124,86,60,255,156,110,76,255,164,122,92,
255,148,110,84,255,140,106,76,255,164,114,84,255,188,138,108,255,180,126,100,
255,132,98,68,255,68,58,36,255,60,58,52,255,244,238,236,255,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,228,230,228,255,60,58,44,255,60,46,28,255,108,78,52,255,180,118,
84,255,196,138,100,255,204,146,108,255,212,150,116,255,204,150,116,255,212,154,
116,255,204,142,100,255,188,122,92,255,148,98,76,255,92,70,44,255,60,54,44,255,
196,190,188,255,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,164,166,164,255,60,58,44,255,76,
66,52,255,132,98,76,255,172,118,92,255,196,134,92,255,204,146,108,255,204,146,
108,255,204,142,108,255,196,138,100,255,196,138,100,255,180,122,92,255,148,102,
76,255,116,94,68,255,52,50,36,255,188,186,180,255,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,140,146,148,255,76,66,52,255,100,90,76,255,132,94,68,255,180,122,92,255,
196,138,100,255,204,150,108,255,212,154,124,255,212,154,116,255,196,146,116,255,
180,130,100,255,172,118,92,255,148,102,76,255,108,78,60,255,60,50,36,255,172,
170,164,255,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,164,166,164,255,84,74,68,255,84,74,
60,255,124,90,68,255,180,122,92,255,156,110,84,255,140,94,68,255,156,110,84,
255,188,142,108,255,196,142,116,255,140,94,68,255,100,82,60,255,140,98,76,255,
100,82,60,255,76,58,44,255,180,166,156,255,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,180,
178,172,255,140,102,92,255,92,62,44,255,140,98,76,255,180,126,92,255,164,114,84,
255,132,86,68,255,140,94,68,255,180,126,92,255,156,110,76,255,132,90,76,255,132,
74,52,255,148,106,84,255,132,94,76,255,100,62,44,255,148,122,116,255,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,196,190,188,255,180,122,92,255,140,94,68,255,148,102,76,
255,212,146,116,255,196,146,116,255,180,130,100,255,204,146,116,255,196,134,100,
255,188,122,92,255,188,130,108,255,188,134,108,255,204,150,124,255,156,110,84,
255,116,66,44,255,180,166,156,255,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,244,246,244,
255,140,102,92,255,172,114,92,255,156,102,76,255,188,142,108,255,212,150,124,
255,204,142,108,255,212,146,116,255,196,134,100,255,188,122,92,255,188,122,92,
255,196,134,100,255,196,130,100,255,132,90,68,255,116,78,60,255,204,194,196,255,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,156,142,132,255,196,134,108,255,148,
106,76,255,172,110,92,255,196,126,92,255,212,138,108,255,204,130,100,255,188,
118,92,255,188,122,92,255,164,102,76,255,196,126,92,255,156,98,76,255,116,78,60,
255,116,90,76,255,204,198,196,255,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,148,138,124,255,172,106,84,255,164,114,84,255,180,122,92,255,196,130,100,
255,196,134,100,255,172,110,84,255,156,102,84,255,180,122,100,255,196,130,100,
255,140,94,76,255,108,78,60,255,108,98,92,255,252,250,252,255,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,252,246,244,255,124,110,100,255,172,122,92,255,
180,122,100,255,180,118,92,255,204,138,108,255,188,130,108,255,188,130,108,255,
180,122,100,255,180,122,92,255,140,102,76,255,92,70,60,255,212,206,204,255,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,212,206,204,255,
148,110,92,255,180,118,92,255,172,122,92,255,172,118,92,255,124,66,52,255,100,
62,44,255,132,70,60,255,148,106,84,255,132,90,68,255,100,82,76,255,252,250,252,
255,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,172,
154,140,255,148,106,76,255,164,114,84,255,156,102,76,255,172,106,84,255,180,102,
84,255,164,94,76,255,140,90,68,255,116,90,76,255,228,222,220,255,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,244,242,244,
255,116,90,76,255,148,98,76,255,172,122,92,255,172,98,76,255,140,70,52,255,132,
74,52,255,116,86,68,255,196,190,188,255,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,252,246,244,255,164,
146,140,255,156,98,76,255,164,102,76,255,172,98,76,255,148,98,84,255,220,210,
212,255,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,196,186,180,255,148,122,116,
255,164,138,132,255,220,214,212,255,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0};
static Fl_RGB_Image image_Bushicn(idata_Bushicn, 20, 20, 4, 0);
//
static unsigned char idata_Bomb[] =
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,252,238,28,255,244,
126,188,255,252,226,44,255,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,252,158,
116,255,252,50,244,255,236,90,196,255,236,222,44,255,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
252,222,44,255,244,62,212,255,252,30,252,255,236,18,236,255,172,118,132,255,228,
238,20,255,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,244,166,100,255,244,10,236,255,252,30,252,255,252,
14,252,255,180,38,180,255,196,190,52,255,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,244,46,236,255,244,
6,244,255,244,6,236,255,252,18,252,255,236,14,228,255,132,94,124,255,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,244,154,132,255,244,6,220,255,180,6,180,255,76,6,76,255,148,18,148,255,244,
10,236,255,180,38,180,255,172,190,60,255,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,252,238,28,255,244,58,180,255,244,6,236,255,
116,10,116,255,12,38,4,255,68,46,60,255,220,22,212,255,244,10,228,255,140,114,
92,255,236,246,12,255,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,244,158,108,255,236,14,228,255,252,6,244,255,140,10,132,255,28,50,12,
255,100,42,84,255,244,6,220,255,252,14,244,255,180,46,172,255,180,194,52,255,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,252,226,44,255,236,74,
188,255,252,6,228,255,252,6,244,255,172,6,164,255,60,78,44,255,148,42,132,255,
252,6,236,255,252,18,244,255,228,14,204,255,148,122,116,255,228,238,20,255,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,244,166,92,255,236,2,212,255,252,
6,228,255,252,2,236,255,228,2,204,255,92,94,76,255,196,14,172,255,252,2,236,
255,252,10,244,255,252,10,228,255,172,42,156,255,196,194,52,255,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,236,46,212,255,244,6,220,255,252,6,228,255,
252,2,220,255,236,2,212,255,92,58,76,255,236,2,212,255,252,2,228,255,252,6,228,
255,252,14,236,255,228,14,204,255,132,106,124,255,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,252,174,124,255,244,6,212,255,252,10,228,255,252,2,220,255,252,2,
228,255,252,2,220,255,156,26,132,255,252,2,220,255,252,2,228,255,252,2,220,255,
252,14,236,255,252,10,228,255,172,42,156,255,188,210,76,255,0,0,0,0,0,0,0,0,0,0,
0,0,252,238,28,255,236,70,164,255,252,2,212,255,252,2,228,255,252,2,220,255,
252,2,212,255,228,2,204,255,180,2,172,255,212,6,196,255,252,2,212,255,252,2,212,
255,252,6,228,255,252,14,236,255,244,6,204,255,140,122,84,255,236,242,12,255,0,
0,0,0,0,0,0,0,244,158,108,255,236,18,204,255,252,6,220,255,252,2,212,255,252,
2,212,255,252,2,212,255,140,6,124,255,20,26,12,255,100,42,84,255,236,10,204,
255,252,2,212,255,252,2,212,255,252,10,228,255,252,2,220,255,172,54,148,255,180,
194,52,255,0,0,0,0,252,226,44,255,236,74,180,255,236,2,196,255,252,2,212,255,
252,2,212,255,252,2,212,255,252,2,212,255,148,6,132,255,44,54,28,255,164,110,
148,255,236,10,204,255,252,2,212,255,252,2,212,255,252,2,212,255,244,6,204,255,
212,22,180,255,132,134,100,255,228,238,20,255,252,222,36,255,228,78,172,255,220,
10,180,255,220,2,180,255,220,2,180,255,220,2,180,255,220,2,180,255,220,2,180,
255,196,22,164,255,220,10,180,255,220,2,180,255,220,2,180,255,220,2,180,255,220,
2,180,255,220,2,180,255,196,22,164,255,92,106,92,255,212,226,20,255,0,0,0,0,
252,214,52,255,204,118,148,255,148,70,124,255,140,70,124,255,140,70,124,255,148,
70,124,255,140,70,124,255,148,70,124,255,148,70,124,255,140,70,124,255,148,70,
124,255,140,70,124,255,148,70,124,255,140,70,124,255,116,94,100,255,124,158,60,
255,236,242,12,255,0,0,0,0,0,0,0,0,236,242,28,255,220,226,28,255,212,226,20,255,
220,226,28,255,212,226,20,255,220,226,20,255,220,226,28,255,212,226,20,255,220,
226,20,255,220,226,28,255,212,226,20,255,220,226,20,255,220,226,28,255,212,226,
20,255,236,242,12,255,0,0,0,0};
static Fl_RGB_Image image_Bomb(idata_Bomb, 18, 18, 4, 0);
static unsigned char idata_Belki[] =
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,228,230,228,255,220,218,220,255,252,
250,252,255,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,212,
210,212,255,100,102,140,255,12,10,108,255,12,14,124,255,20,18,140,255,12,10,108,
255,52,54,124,255,172,174,180,255,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,212,
210,212,255,36,38,140,255,4,2,220,255,4,2,252,255,4,2,252,255,4,2,252,255,4,2,
252,255,4,2,236,255,12,14,180,255,164,162,180,255,252,250,252,255,0,0,0,0,0,0,0,
0,236,238,244,255,84,82,140,255,4,2,244,255,4,2,252,255,4,2,252,255,4,2,252,
255,4,2,244,255,4,2,252,255,4,2,252,255,4,2,252,255,28,26,156,255,204,206,212,
255,0,0,0,0,0,0,0,0,196,198,196,255,12,10,164,255,4,2,252,255,4,2,252,255,4,6,
204,255,60,62,116,255,84,86,116,255,12,14,180,255,4,2,252,255,4,2,252,255,4,6,
196,255,148,146,164,255,0,0,0,0,0,0,0,0,164,166,172,255,12,14,132,255,4,6,196,
255,4,2,220,255,36,34,140,255,220,218,220,255,220,222,220,255,36,38,124,255,4,2,
252,255,4,2,252,255,4,2,212,255,124,122,156,255,0,0,0,0,0,0,0,0,236,238,236,255,
180,182,180,255,148,146,164,255,132,134,132,255,148,146,148,255,252,250,252,255,
92,94,140,255,4,6,220,255,4,2,252,255,4,2,252,255,4,6,172,255,180,182,188,255,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,228,230,228,255,84,86,140,255,
4,2,228,255,4,2,252,255,4,2,252,255,4,2,220,255,108,106,148,255,244,242,244,
255,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,252,250,252,255,108,110,148,255,4,2,
220,255,4,2,252,255,4,2,252,255,4,2,228,255,84,86,148,255,236,234,236,255,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,204,202,204,255,28,26,156,255,4,2,
252,255,4,2,252,255,4,2,212,255,92,94,140,255,244,246,244,255,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,172,174,180,255,4,6,156,255,4,2,220,255,
4,2,220,255,36,34,140,255,212,210,212,255,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,204,202,204,255,84,86,116,255,84,82,124,255,84,82,
124,255,124,126,140,255,244,242,244,255,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,156,154,164,255,28,30,108,255,28,26,124,255,28,26,124,
255,68,70,108,255,228,230,228,255,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,140,138,156,255,4,6,196,255,4,2,244,255,4,2,244,255,44,46,
132,255,228,226,228,255,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,140,138,156,255,4,6,204,255,4,2,252,255,4,2,252,255,44,46,140,255,220,
222,220,255,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,140,
142,156,255,4,2,124,255,4,2,148,255,4,2,148,255,44,46,100,255,228,226,228,255,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,236,238,236,255,
212,210,212,255,212,210,212,255,212,210,212,255,220,218,220,255,252,250,252,255,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
static Fl_RGB_Image image_Belki(idata_Belki, 14, 20, 4, 0);
//
class GMap : public Fl_Group {
protected:
    int handle(int e) {
    int x;
	int ret = Fl_Group::handle(e);
        switch ( e ) {
            case FL_PUSH:
            x=Fl::event_button();
            do_callback(this,(void*)x);
         }
        return(ret);
    }
public:
    GMap(int X, int Y, int W, int H, const char *L=0) : Fl_Group(X,Y,W,H,L) {

    }

};


class Cell : public Fl_Box {
protected:



    int handle(int e) {
    int x;
	int ret = Fl_Box::handle(e);
        switch ( e ) {
            case FL_PUSH:
            x=Fl::event_button();
            if(x==1)
              LClick();
            else if(x==3)
              RClick();
               return(1);

        }
        return(ret);
    }
public:
    int value;
    bool opened;
    int rclick;
    Cell(int X, int Y, int W, int H, const char *L=0) : Fl_Box(X,Y,W,H,L) {
        box(FL_UP_BOX);
        opened=false;
        color(FL_GRAY);
        rclick=0;
    }
    Cell(int X, int Y,int ivalue) : Fl_Box(X,Y,20,20,0) {
        box(FL_PLASTIC_UP_BOX);
      //  box(FL_UP_BOX);
        color(FL_GRAY);
        opened=false;
        color(15);
        rclick=0;
        value=ivalue;

    }

    void LClick(){
      if(opened) return;
      if(rclick==1) return;
      if(rclick==2) image(0);
      opened=true;
      color(FL_WHITE);
      box(FL_DOWN_BOX);
      int L=200;
      switch(value){
        case -1 : labelcolor(FL_RED); // Booom :)
                  image(image_Bushicn);
                  break;
        case 0 : label("");
                 break;
        case 1 : labelcolor(FL_BLACK);
                 label("1");
                 break;
        case 2 : labelcolor(FL_BLACK);
                 label("2");
                 break;

        case 3 : labelcolor(FL_BLUE);
                 label("3");
                 break;
        case 4 : labelcolor(FL_BLUE);
                 label("4");
                 break;
        case 5 : labelcolor(FL_RED);
                 label("5");
                 break;
        case 6 : labelcolor(FL_RED);
                 label("6");
                 break;

        case 7 : labelcolor(FL_RED);
                 label("7");
                 break;

        case 8 : labelcolor(FL_RED);
                 label("8");
                 break;
      }


      redraw();
    }
    void RClick(){
      if(opened) return;
      rclick++;
      rclick=rclick%3;
      switch(rclick){
        case 0 : image(0);
                 break;
        case 1 : image(image_Bomb); // !
                 break;
        case 2 : image(image_Belki);  // ?
                 break;
      }
      redraw();
    }

};
#endif
