/*                                      50 KEY MATRIX / LAYOUT MAPPING

  ╭────────────────────────╮               ╭────────────────���───────╮
  │  0   1   2   3   4   5 │               │  6   7   8   9  10  11 │
  │ 12  13  14  15  16  17 ╰──╮         ╭──╯ 18  19  20  21  22  23 │
  │ 24  25  26  27  28  29  30╰────┬────╯31  32  33  34  35  36  37 │
  │ 38  39  40  41  42  43     │     44  45  46  47  48  49 │
  ╰────────────────────────────────┴────────────────────────────────╯

 ╭─────────────────────────────╮         ╭────────────────���────────────╮
 │ LT5 LT4 LT3 LT2 LT1 LT0  │         │ RT0 RT1 RT2 RT3 RT4 RT5    │
 │ LM5 LM4 LM3 LM2 LM1 LM0  ╰──╮   ╭���─╯ RM0 RM1 RM2 RM3 RM4 RM5  │
 │ LB5 LB4 LB3 LB2 LB1 LB0 LH3 ╰┬─╯ RH3 RB0 RB1 RB2 RB3 RB4 RB5 │
 │ LP2 LP1 LP0 LH2 LH1 LH0      │    RH0 RH1 RH2 RP0 RP1 RP2      │
 ╰────────────────────────────────┴─────────────��─────────────────────╯

 T : Top    M : Middle    B : Bottom    H : Hand/Thumb    P : Palm
*/

#pragma once

/* Left top row */
#define LT0  5  // inner (near split)
#define LT1  4
#define LT2  3
#define LT3  2
#define LT4  1  // outer of inner 5
#define LT5  0  // outermost (6th column)

/* Right top row */
#define RT0  6  // inner (near split)
#define RT1  7
#define RT2  8
#define RT3  9
#define RT4 10  // outer of inner 5
#define RT5 11  // outermost (6th column)

/* Left middle row */
#define LM0 17  // inner
#define LM1 16
#define LM2 15
#define LM3 14
#define LM4 13  // outer of inner 5
#define LM5 12  // outermost

/* Right middle row */
#define RM0 18  // inner
#define RM1 19
#define RM2 20
#define RM3 21
#define RM4 22  // outer of inner 5
#define RM5 23  // outermost

/* Left bottom row */
#define LB0 29  // inner
#define LB1 28
#define LB2 27
#define LB3 26
#define LB4 25  // outer of inner 5
#define LB5 24  // outermost

/* Right bottom row */
#define RB0 32  // inner
#define RB1 33
#define RB2 34
#define RB3 35
#define RB4 36  // outer of inner 5
#define RB5 37  // outermost

/* Left thumb/hand keys */
#define LH0 43  // inner (near split)
#define LH1 42
#define LH2 41  // outer thumb
#define LH3 30  // encoder / extra

/* Right thumb/hand keys */
#define RH0 44  // inner (near split)
#define RH1 45
#define RH2 46  // outer thumb
#define RH3 31  // encoder / extra

/* Left palm keys */
#define LP0 40
#define LP1 39
#define LP2 38

/* Right palm keys */
#define RP0 47
#define RP1 48
#define RP2 49

/* Key groups for positional hold-tap (HRM) triggers */
#define KEYS_L                                                                 \
    LT0 LT1 LT2 LT3 LT4 LT5                                                 \
    LM0 LM1 LM2 LM3 LM4 LM5                                                  \
    LB0 LB1 LB2 LB3 LB4 LB5

#define KEYS_R                                                                 \
    RT0 RT1 RT2 RT3 RT4 RT5                                                    \
    RM0 RM1 RM2 RM3 RM4 RM5                                                    \
    RB0 RB1 RB2 RB3 RB4 RB5

#define THUMBS                                                                 \
    LH0 LH1 LH2 LH3                                                           \
    RH0 RH1 RH2 RH3                                                            \
    LP0 LP1 LP2                                                                \
    RP0 RP1 RP2
