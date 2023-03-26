                                      1 ;--------------------------------------------------------
                                      2 ; File Created by SDCC : free open source ANSI-C Compiler
                                      3 ; Version 4.1.0 #12072 (Linux)
                                      4 ;--------------------------------------------------------
                                      5 	.module main
                                      6 	.optsdcc -mmcs51 --model-small
                                      7 	
                                      8 ;--------------------------------------------------------
                                      9 ; Public variables in this module
                                     10 ;--------------------------------------------------------
                                     11 	.globl _main
                                     12 	.globl _SerialPrintln
                                     13 	.globl _SerialBegin
                                     14 	.globl _setTime
                                     15 	.globl _getTime
                                     16 	.globl _LcdChar
                                     17 	.globl _LcdInit
                                     18 	.globl _LcdClear
                                     19 	.globl _CP_RL2
                                     20 	.globl _C_T2
                                     21 	.globl _TR2
                                     22 	.globl _EXEN2
                                     23 	.globl _TCLK
                                     24 	.globl _RCLK
                                     25 	.globl _EXF2
                                     26 	.globl _TF2
                                     27 	.globl _T2
                                     28 	.globl _T2EX
                                     29 	.globl _RI
                                     30 	.globl _TI
                                     31 	.globl _RB8
                                     32 	.globl _TB8
                                     33 	.globl _REN
                                     34 	.globl _SM2
                                     35 	.globl _SM1
                                     36 	.globl _SM0
                                     37 	.globl _RXD
                                     38 	.globl _TXD
                                     39 	.globl _INT0
                                     40 	.globl _INT1
                                     41 	.globl _T0
                                     42 	.globl _T1
                                     43 	.globl _WR
                                     44 	.globl _RD
                                     45 	.globl _PX0
                                     46 	.globl _PT0
                                     47 	.globl _PX1
                                     48 	.globl _PT1
                                     49 	.globl _PS
                                     50 	.globl _PT2
                                     51 	.globl _EX0
                                     52 	.globl _ET0
                                     53 	.globl _EX1
                                     54 	.globl _ET1
                                     55 	.globl _ES
                                     56 	.globl _ET2
                                     57 	.globl _EA
                                     58 	.globl _IT0
                                     59 	.globl _IE0
                                     60 	.globl _IT1
                                     61 	.globl _IE1
                                     62 	.globl _TR0
                                     63 	.globl _TF0
                                     64 	.globl _TR1
                                     65 	.globl _TF1
                                     66 	.globl _P
                                     67 	.globl _OV
                                     68 	.globl _RS0
                                     69 	.globl _RS1
                                     70 	.globl _F0
                                     71 	.globl _AC
                                     72 	.globl _CY
                                     73 	.globl _P37
                                     74 	.globl _P36
                                     75 	.globl _P35
                                     76 	.globl _P34
                                     77 	.globl _P33
                                     78 	.globl _P32
                                     79 	.globl _P31
                                     80 	.globl _P30
                                     81 	.globl _P27
                                     82 	.globl _P26
                                     83 	.globl _P25
                                     84 	.globl _P24
                                     85 	.globl _P23
                                     86 	.globl _P22
                                     87 	.globl _P21
                                     88 	.globl _P20
                                     89 	.globl _P17
                                     90 	.globl _P16
                                     91 	.globl _P15
                                     92 	.globl _P14
                                     93 	.globl _P13
                                     94 	.globl _P12
                                     95 	.globl _P11
                                     96 	.globl _P10
                                     97 	.globl _P07
                                     98 	.globl _P06
                                     99 	.globl _P05
                                    100 	.globl _P04
                                    101 	.globl _P03
                                    102 	.globl _P02
                                    103 	.globl _P01
                                    104 	.globl _P00
                                    105 	.globl _TH2
                                    106 	.globl _TL2
                                    107 	.globl _RCAP2H
                                    108 	.globl _RCAP2L
                                    109 	.globl _T2CON
                                    110 	.globl _SBUF
                                    111 	.globl _SCON
                                    112 	.globl _IP
                                    113 	.globl _IE
                                    114 	.globl _TH1
                                    115 	.globl _TH0
                                    116 	.globl _TL1
                                    117 	.globl _TL0
                                    118 	.globl _TMOD
                                    119 	.globl _TCON
                                    120 	.globl _PCON
                                    121 	.globl _DPH
                                    122 	.globl _DPL
                                    123 	.globl _SP
                                    124 	.globl _B
                                    125 	.globl _ACC
                                    126 	.globl _PSW
                                    127 	.globl _P3
                                    128 	.globl _P2
                                    129 	.globl _P1
                                    130 	.globl _P0
                                    131 ;--------------------------------------------------------
                                    132 ; special function registers
                                    133 ;--------------------------------------------------------
                                    134 	.area RSEG    (ABS,DATA)
      000000                        135 	.org 0x0000
                           000080   136 G$P0$0_0$0 == 0x0080
                           000080   137 _P0	=	0x0080
                           000090   138 G$P1$0_0$0 == 0x0090
                           000090   139 _P1	=	0x0090
                           0000A0   140 G$P2$0_0$0 == 0x00a0
                           0000A0   141 _P2	=	0x00a0
                           0000B0   142 G$P3$0_0$0 == 0x00b0
                           0000B0   143 _P3	=	0x00b0
                           0000D0   144 G$PSW$0_0$0 == 0x00d0
                           0000D0   145 _PSW	=	0x00d0
                           0000E0   146 G$ACC$0_0$0 == 0x00e0
                           0000E0   147 _ACC	=	0x00e0
                           0000F0   148 G$B$0_0$0 == 0x00f0
                           0000F0   149 _B	=	0x00f0
                           000081   150 G$SP$0_0$0 == 0x0081
                           000081   151 _SP	=	0x0081
                           000082   152 G$DPL$0_0$0 == 0x0082
                           000082   153 _DPL	=	0x0082
                           000083   154 G$DPH$0_0$0 == 0x0083
                           000083   155 _DPH	=	0x0083
                           000087   156 G$PCON$0_0$0 == 0x0087
                           000087   157 _PCON	=	0x0087
                           000088   158 G$TCON$0_0$0 == 0x0088
                           000088   159 _TCON	=	0x0088
                           000089   160 G$TMOD$0_0$0 == 0x0089
                           000089   161 _TMOD	=	0x0089
                           00008A   162 G$TL0$0_0$0 == 0x008a
                           00008A   163 _TL0	=	0x008a
                           00008B   164 G$TL1$0_0$0 == 0x008b
                           00008B   165 _TL1	=	0x008b
                           00008C   166 G$TH0$0_0$0 == 0x008c
                           00008C   167 _TH0	=	0x008c
                           00008D   168 G$TH1$0_0$0 == 0x008d
                           00008D   169 _TH1	=	0x008d
                           0000A8   170 G$IE$0_0$0 == 0x00a8
                           0000A8   171 _IE	=	0x00a8
                           0000B8   172 G$IP$0_0$0 == 0x00b8
                           0000B8   173 _IP	=	0x00b8
                           000098   174 G$SCON$0_0$0 == 0x0098
                           000098   175 _SCON	=	0x0098
                           000099   176 G$SBUF$0_0$0 == 0x0099
                           000099   177 _SBUF	=	0x0099
                           0000C8   178 G$T2CON$0_0$0 == 0x00c8
                           0000C8   179 _T2CON	=	0x00c8
                           0000CA   180 G$RCAP2L$0_0$0 == 0x00ca
                           0000CA   181 _RCAP2L	=	0x00ca
                           0000CB   182 G$RCAP2H$0_0$0 == 0x00cb
                           0000CB   183 _RCAP2H	=	0x00cb
                           0000CC   184 G$TL2$0_0$0 == 0x00cc
                           0000CC   185 _TL2	=	0x00cc
                           0000CD   186 G$TH2$0_0$0 == 0x00cd
                           0000CD   187 _TH2	=	0x00cd
                                    188 ;--------------------------------------------------------
                                    189 ; special function bits
                                    190 ;--------------------------------------------------------
                                    191 	.area RSEG    (ABS,DATA)
      000000                        192 	.org 0x0000
                           000080   193 G$P00$0_0$0 == 0x0080
                           000080   194 _P00	=	0x0080
                           000081   195 G$P01$0_0$0 == 0x0081
                           000081   196 _P01	=	0x0081
                           000082   197 G$P02$0_0$0 == 0x0082
                           000082   198 _P02	=	0x0082
                           000083   199 G$P03$0_0$0 == 0x0083
                           000083   200 _P03	=	0x0083
                           000084   201 G$P04$0_0$0 == 0x0084
                           000084   202 _P04	=	0x0084
                           000085   203 G$P05$0_0$0 == 0x0085
                           000085   204 _P05	=	0x0085
                           000086   205 G$P06$0_0$0 == 0x0086
                           000086   206 _P06	=	0x0086
                           000087   207 G$P07$0_0$0 == 0x0087
                           000087   208 _P07	=	0x0087
                           000090   209 G$P10$0_0$0 == 0x0090
                           000090   210 _P10	=	0x0090
                           000091   211 G$P11$0_0$0 == 0x0091
                           000091   212 _P11	=	0x0091
                           000092   213 G$P12$0_0$0 == 0x0092
                           000092   214 _P12	=	0x0092
                           000093   215 G$P13$0_0$0 == 0x0093
                           000093   216 _P13	=	0x0093
                           000094   217 G$P14$0_0$0 == 0x0094
                           000094   218 _P14	=	0x0094
                           000095   219 G$P15$0_0$0 == 0x0095
                           000095   220 _P15	=	0x0095
                           000096   221 G$P16$0_0$0 == 0x0096
                           000096   222 _P16	=	0x0096
                           000097   223 G$P17$0_0$0 == 0x0097
                           000097   224 _P17	=	0x0097
                           0000A0   225 G$P20$0_0$0 == 0x00a0
                           0000A0   226 _P20	=	0x00a0
                           0000A1   227 G$P21$0_0$0 == 0x00a1
                           0000A1   228 _P21	=	0x00a1
                           0000A2   229 G$P22$0_0$0 == 0x00a2
                           0000A2   230 _P22	=	0x00a2
                           0000A3   231 G$P23$0_0$0 == 0x00a3
                           0000A3   232 _P23	=	0x00a3
                           0000A4   233 G$P24$0_0$0 == 0x00a4
                           0000A4   234 _P24	=	0x00a4
                           0000A5   235 G$P25$0_0$0 == 0x00a5
                           0000A5   236 _P25	=	0x00a5
                           0000A6   237 G$P26$0_0$0 == 0x00a6
                           0000A6   238 _P26	=	0x00a6
                           0000A7   239 G$P27$0_0$0 == 0x00a7
                           0000A7   240 _P27	=	0x00a7
                           0000B0   241 G$P30$0_0$0 == 0x00b0
                           0000B0   242 _P30	=	0x00b0
                           0000B1   243 G$P31$0_0$0 == 0x00b1
                           0000B1   244 _P31	=	0x00b1
                           0000B2   245 G$P32$0_0$0 == 0x00b2
                           0000B2   246 _P32	=	0x00b2
                           0000B3   247 G$P33$0_0$0 == 0x00b3
                           0000B3   248 _P33	=	0x00b3
                           0000B4   249 G$P34$0_0$0 == 0x00b4
                           0000B4   250 _P34	=	0x00b4
                           0000B5   251 G$P35$0_0$0 == 0x00b5
                           0000B5   252 _P35	=	0x00b5
                           0000B6   253 G$P36$0_0$0 == 0x00b6
                           0000B6   254 _P36	=	0x00b6
                           0000B7   255 G$P37$0_0$0 == 0x00b7
                           0000B7   256 _P37	=	0x00b7
                           0000D7   257 G$CY$0_0$0 == 0x00d7
                           0000D7   258 _CY	=	0x00d7
                           0000D6   259 G$AC$0_0$0 == 0x00d6
                           0000D6   260 _AC	=	0x00d6
                           0000D5   261 G$F0$0_0$0 == 0x00d5
                           0000D5   262 _F0	=	0x00d5
                           0000D4   263 G$RS1$0_0$0 == 0x00d4
                           0000D4   264 _RS1	=	0x00d4
                           0000D3   265 G$RS0$0_0$0 == 0x00d3
                           0000D3   266 _RS0	=	0x00d3
                           0000D2   267 G$OV$0_0$0 == 0x00d2
                           0000D2   268 _OV	=	0x00d2
                           0000D0   269 G$P$0_0$0 == 0x00d0
                           0000D0   270 _P	=	0x00d0
                           00008F   271 G$TF1$0_0$0 == 0x008f
                           00008F   272 _TF1	=	0x008f
                           00008E   273 G$TR1$0_0$0 == 0x008e
                           00008E   274 _TR1	=	0x008e
                           00008D   275 G$TF0$0_0$0 == 0x008d
                           00008D   276 _TF0	=	0x008d
                           00008C   277 G$TR0$0_0$0 == 0x008c
                           00008C   278 _TR0	=	0x008c
                           00008B   279 G$IE1$0_0$0 == 0x008b
                           00008B   280 _IE1	=	0x008b
                           00008A   281 G$IT1$0_0$0 == 0x008a
                           00008A   282 _IT1	=	0x008a
                           000089   283 G$IE0$0_0$0 == 0x0089
                           000089   284 _IE0	=	0x0089
                           000088   285 G$IT0$0_0$0 == 0x0088
                           000088   286 _IT0	=	0x0088
                           0000AF   287 G$EA$0_0$0 == 0x00af
                           0000AF   288 _EA	=	0x00af
                           0000AD   289 G$ET2$0_0$0 == 0x00ad
                           0000AD   290 _ET2	=	0x00ad
                           0000AC   291 G$ES$0_0$0 == 0x00ac
                           0000AC   292 _ES	=	0x00ac
                           0000AB   293 G$ET1$0_0$0 == 0x00ab
                           0000AB   294 _ET1	=	0x00ab
                           0000AA   295 G$EX1$0_0$0 == 0x00aa
                           0000AA   296 _EX1	=	0x00aa
                           0000A9   297 G$ET0$0_0$0 == 0x00a9
                           0000A9   298 _ET0	=	0x00a9
                           0000A8   299 G$EX0$0_0$0 == 0x00a8
                           0000A8   300 _EX0	=	0x00a8
                           0000BD   301 G$PT2$0_0$0 == 0x00bd
                           0000BD   302 _PT2	=	0x00bd
                           0000BC   303 G$PS$0_0$0 == 0x00bc
                           0000BC   304 _PS	=	0x00bc
                           0000BB   305 G$PT1$0_0$0 == 0x00bb
                           0000BB   306 _PT1	=	0x00bb
                           0000BA   307 G$PX1$0_0$0 == 0x00ba
                           0000BA   308 _PX1	=	0x00ba
                           0000B9   309 G$PT0$0_0$0 == 0x00b9
                           0000B9   310 _PT0	=	0x00b9
                           0000B8   311 G$PX0$0_0$0 == 0x00b8
                           0000B8   312 _PX0	=	0x00b8
                           0000B7   313 G$RD$0_0$0 == 0x00b7
                           0000B7   314 _RD	=	0x00b7
                           0000B6   315 G$WR$0_0$0 == 0x00b6
                           0000B6   316 _WR	=	0x00b6
                           0000B5   317 G$T1$0_0$0 == 0x00b5
                           0000B5   318 _T1	=	0x00b5
                           0000B4   319 G$T0$0_0$0 == 0x00b4
                           0000B4   320 _T0	=	0x00b4
                           0000B3   321 G$INT1$0_0$0 == 0x00b3
                           0000B3   322 _INT1	=	0x00b3
                           0000B2   323 G$INT0$0_0$0 == 0x00b2
                           0000B2   324 _INT0	=	0x00b2
                           0000B1   325 G$TXD$0_0$0 == 0x00b1
                           0000B1   326 _TXD	=	0x00b1
                           0000B0   327 G$RXD$0_0$0 == 0x00b0
                           0000B0   328 _RXD	=	0x00b0
                           00009F   329 G$SM0$0_0$0 == 0x009f
                           00009F   330 _SM0	=	0x009f
                           00009E   331 G$SM1$0_0$0 == 0x009e
                           00009E   332 _SM1	=	0x009e
                           00009D   333 G$SM2$0_0$0 == 0x009d
                           00009D   334 _SM2	=	0x009d
                           00009C   335 G$REN$0_0$0 == 0x009c
                           00009C   336 _REN	=	0x009c
                           00009B   337 G$TB8$0_0$0 == 0x009b
                           00009B   338 _TB8	=	0x009b
                           00009A   339 G$RB8$0_0$0 == 0x009a
                           00009A   340 _RB8	=	0x009a
                           000099   341 G$TI$0_0$0 == 0x0099
                           000099   342 _TI	=	0x0099
                           000098   343 G$RI$0_0$0 == 0x0098
                           000098   344 _RI	=	0x0098
                           000091   345 G$T2EX$0_0$0 == 0x0091
                           000091   346 _T2EX	=	0x0091
                           000090   347 G$T2$0_0$0 == 0x0090
                           000090   348 _T2	=	0x0090
                           0000CF   349 G$TF2$0_0$0 == 0x00cf
                           0000CF   350 _TF2	=	0x00cf
                           0000CE   351 G$EXF2$0_0$0 == 0x00ce
                           0000CE   352 _EXF2	=	0x00ce
                           0000CD   353 G$RCLK$0_0$0 == 0x00cd
                           0000CD   354 _RCLK	=	0x00cd
                           0000CC   355 G$TCLK$0_0$0 == 0x00cc
                           0000CC   356 _TCLK	=	0x00cc
                           0000CB   357 G$EXEN2$0_0$0 == 0x00cb
                           0000CB   358 _EXEN2	=	0x00cb
                           0000CA   359 G$TR2$0_0$0 == 0x00ca
                           0000CA   360 _TR2	=	0x00ca
                           0000C9   361 G$C_T2$0_0$0 == 0x00c9
                           0000C9   362 _C_T2	=	0x00c9
                           0000C8   363 G$CP_RL2$0_0$0 == 0x00c8
                           0000C8   364 _CP_RL2	=	0x00c8
                                    365 ;--------------------------------------------------------
                                    366 ; overlayable register banks
                                    367 ;--------------------------------------------------------
                                    368 	.area REG_BANK_0	(REL,OVR,DATA)
      000000                        369 	.ds 8
                                    370 ;--------------------------------------------------------
                                    371 ; internal ram data
                                    372 ;--------------------------------------------------------
                                    373 	.area DSEG    (DATA)
                           000000   374 Lmain.main$time$1_0$21==.
      000008                        375 _main_time_65536_21:
      000008                        376 	.ds 7
                                    377 ;--------------------------------------------------------
                                    378 ; overlayable items in internal ram 
                                    379 ;--------------------------------------------------------
                                    380 ;--------------------------------------------------------
                                    381 ; Stack segment in internal ram 
                                    382 ;--------------------------------------------------------
                                    383 	.area	SSEG
      000023                        384 __start__stack:
      000023                        385 	.ds	1
                                    386 
                                    387 ;--------------------------------------------------------
                                    388 ; indirectly addressable internal ram data
                                    389 ;--------------------------------------------------------
                                    390 	.area ISEG    (DATA)
                                    391 ;--------------------------------------------------------
                                    392 ; absolute internal ram data
                                    393 ;--------------------------------------------------------
                                    394 	.area IABS    (ABS,DATA)
                                    395 	.area IABS    (ABS,DATA)
                                    396 ;--------------------------------------------------------
                                    397 ; bit data
                                    398 ;--------------------------------------------------------
                                    399 	.area BSEG    (BIT)
                                    400 ;--------------------------------------------------------
                                    401 ; paged external ram data
                                    402 ;--------------------------------------------------------
                                    403 	.area PSEG    (PAG,XDATA)
                                    404 ;--------------------------------------------------------
                                    405 ; external ram data
                                    406 ;--------------------------------------------------------
                                    407 	.area XSEG    (XDATA)
                                    408 ;--------------------------------------------------------
                                    409 ; absolute external ram data
                                    410 ;--------------------------------------------------------
                                    411 	.area XABS    (ABS,XDATA)
                                    412 ;--------------------------------------------------------
                                    413 ; external initialized ram data
                                    414 ;--------------------------------------------------------
                                    415 	.area XISEG   (XDATA)
                                    416 	.area HOME    (CODE)
                                    417 	.area GSINIT0 (CODE)
                                    418 	.area GSINIT1 (CODE)
                                    419 	.area GSINIT2 (CODE)
                                    420 	.area GSINIT3 (CODE)
                                    421 	.area GSINIT4 (CODE)
                                    422 	.area GSINIT5 (CODE)
                                    423 	.area GSINIT  (CODE)
                                    424 	.area GSFINAL (CODE)
                                    425 	.area CSEG    (CODE)
                                    426 ;--------------------------------------------------------
                                    427 ; interrupt vector 
                                    428 ;--------------------------------------------------------
                                    429 	.area HOME    (CODE)
      000000                        430 __interrupt_vect:
      000000 02 00 06         [24]  431 	ljmp	__sdcc_gsinit_startup
                                    432 ;--------------------------------------------------------
                                    433 ; global & static initialisations
                                    434 ;--------------------------------------------------------
                                    435 	.area HOME    (CODE)
                                    436 	.area GSINIT  (CODE)
                                    437 	.area GSFINAL (CODE)
                                    438 	.area GSINIT  (CODE)
                                    439 	.globl __sdcc_gsinit_startup
                                    440 	.globl __sdcc_program_startup
                                    441 	.globl __start__stack
                                    442 	.globl __mcs51_genXINIT
                                    443 	.globl __mcs51_genXRAMCLEAR
                                    444 	.globl __mcs51_genRAMCLEAR
                                    445 	.area GSFINAL (CODE)
      000065 02 00 03         [24]  446 	ljmp	__sdcc_program_startup
                                    447 ;--------------------------------------------------------
                                    448 ; Home
                                    449 ;--------------------------------------------------------
                                    450 	.area HOME    (CODE)
                                    451 	.area HOME    (CODE)
      000003                        452 __sdcc_program_startup:
      000003 02 00 68         [24]  453 	ljmp	_main
                                    454 ;	return from main will return to caller
                                    455 ;--------------------------------------------------------
                                    456 ; code
                                    457 ;--------------------------------------------------------
                                    458 	.area CSEG    (CODE)
                                    459 ;------------------------------------------------------------
                                    460 ;Allocation info for local variables in function 'main'
                                    461 ;------------------------------------------------------------
                                    462 ;time                      Allocated with name '_main_time_65536_21'
                                    463 ;------------------------------------------------------------
                           000000   464 	G$main$0$0 ==.
                           000000   465 	C$main.c$5$0_0$21 ==.
                                    466 ;	./src/main.c:5: void main() {
                                    467 ;	-----------------------------------------
                                    468 ;	 function main
                                    469 ;	-----------------------------------------
      000068                        470 _main:
                           000007   471 	ar7 = 0x07
                           000006   472 	ar6 = 0x06
                           000005   473 	ar5 = 0x05
                           000004   474 	ar4 = 0x04
                           000003   475 	ar3 = 0x03
                           000002   476 	ar2 = 0x02
                           000001   477 	ar1 = 0x01
                           000000   478 	ar0 = 0x00
                           000000   479 	C$main.c$8$1_0$21 ==.
                                    480 ;	./src/main.c:8: SerialBegin(9600);
      000068 90 25 80         [24]  481 	mov	dptr,#0x2580
      00006B 12 07 A9         [24]  482 	lcall	_SerialBegin
                           000006   483 	C$main.c$10$1_0$21 ==.
                                    484 ;	./src/main.c:10: LcdInit();
      00006E 12 03 28         [24]  485 	lcall	_LcdInit
                           000009   486 	C$main.c$11$1_0$21 ==.
                                    487 ;	./src/main.c:11: LcdClear();
      000071 12 03 1E         [24]  488 	lcall	_LcdClear
                           00000C   489 	C$main.c$13$1_0$21 ==.
                                    490 ;	./src/main.c:13: setTime(23, 3, 26, 18, 45, 10, 6);
      000074 75 18 03         [24]  491 	mov	_setTime_PARM_2,#0x03
      000077 75 19 1A         [24]  492 	mov	_setTime_PARM_3,#0x1a
      00007A 75 1A 12         [24]  493 	mov	_setTime_PARM_4,#0x12
      00007D 75 1B 2D         [24]  494 	mov	_setTime_PARM_5,#0x2d
      000080 75 1C 0A         [24]  495 	mov	_setTime_PARM_6,#0x0a
      000083 75 1D 06         [24]  496 	mov	_setTime_PARM_7,#0x06
      000086 75 82 17         [24]  497 	mov	dpl,#0x17
      000089 12 06 DF         [24]  498 	lcall	_setTime
                           000024   499 	C$main.c$15$1_0$21 ==.
                                    500 ;	./src/main.c:15: while (1) {
      00008C                        501 00102$:
                           000024   502 	C$main.c$16$2_0$22 ==.
                                    503 ;	./src/main.c:16: SerialPrintln("Test123...");
      00008C 90 0A 42         [24]  504 	mov	dptr,#___str_0
      00008F 75 F0 80         [24]  505 	mov	b,#0x80
      000092 12 08 44         [24]  506 	lcall	_SerialPrintln
                           00002D   507 	C$main.c$18$2_0$22 ==.
                                    508 ;	./src/main.c:18: getTime(&time);
      000095 90 00 08         [24]  509 	mov	dptr,#_main_time_65536_21
      000098 75 F0 40         [24]  510 	mov	b,#0x40
      00009B 12 05 79         [24]  511 	lcall	_getTime
                           000036   512 	C$main.c$20$2_0$22 ==.
                                    513 ;	./src/main.c:20: LcdChar(0, 0, '2');
      00009E 75 10 00         [24]  514 	mov	_LcdChar_PARM_2,#0x00
      0000A1 75 11 32         [24]  515 	mov	_LcdChar_PARM_3,#0x32
      0000A4 75 82 00         [24]  516 	mov	dpl,#0x00
      0000A7 12 03 59         [24]  517 	lcall	_LcdChar
                           000042   518 	C$main.c$21$2_0$22 ==.
                                    519 ;	./src/main.c:21: LcdChar(1, 0, '0');
      0000AA 75 10 00         [24]  520 	mov	_LcdChar_PARM_2,#0x00
      0000AD 75 11 30         [24]  521 	mov	_LcdChar_PARM_3,#0x30
      0000B0 75 82 01         [24]  522 	mov	dpl,#0x01
      0000B3 12 03 59         [24]  523 	lcall	_LcdChar
                           00004E   524 	C$main.c$22$2_0$22 ==.
                                    525 ;	./src/main.c:22: LcdChar(2, 0, time.year / 10 + '0');
      0000B6 AE 08            [24]  526 	mov	r6,_main_time_65536_21
      0000B8 7F 00            [12]  527 	mov	r7,#0x00
      0000BA 75 1F 0A         [24]  528 	mov	__divsint_PARM_2,#0x0a
                                    529 ;	1-genFromRTrack replaced	mov	(__divsint_PARM_2 + 1),#0x00
      0000BD 8F 20            [24]  530 	mov	(__divsint_PARM_2 + 1),r7
      0000BF 8E 82            [24]  531 	mov	dpl,r6
      0000C1 8F 83            [24]  532 	mov	dph,r7
      0000C3 12 09 34         [24]  533 	lcall	__divsint
      0000C6 AE 82            [24]  534 	mov	r6,dpl
      0000C8 74 30            [12]  535 	mov	a,#0x30
      0000CA 2E               [12]  536 	add	a,r6
      0000CB F5 11            [12]  537 	mov	_LcdChar_PARM_3,a
      0000CD 75 10 00         [24]  538 	mov	_LcdChar_PARM_2,#0x00
      0000D0 75 82 02         [24]  539 	mov	dpl,#0x02
      0000D3 12 03 59         [24]  540 	lcall	_LcdChar
                           00006E   541 	C$main.c$23$2_0$22 ==.
                                    542 ;	./src/main.c:23: LcdChar(3, 0, time.year % 10 + '0');
      0000D6 AE 08            [24]  543 	mov	r6,_main_time_65536_21
      0000D8 7F 00            [12]  544 	mov	r7,#0x00
      0000DA 75 1F 0A         [24]  545 	mov	__modsint_PARM_2,#0x0a
                                    546 ;	1-genFromRTrack replaced	mov	(__modsint_PARM_2 + 1),#0x00
      0000DD 8F 20            [24]  547 	mov	(__modsint_PARM_2 + 1),r7
      0000DF 8E 82            [24]  548 	mov	dpl,r6
      0000E1 8F 83            [24]  549 	mov	dph,r7
      0000E3 12 08 FE         [24]  550 	lcall	__modsint
      0000E6 AE 82            [24]  551 	mov	r6,dpl
      0000E8 74 30            [12]  552 	mov	a,#0x30
      0000EA 2E               [12]  553 	add	a,r6
      0000EB F5 11            [12]  554 	mov	_LcdChar_PARM_3,a
      0000ED 75 10 00         [24]  555 	mov	_LcdChar_PARM_2,#0x00
      0000F0 75 82 03         [24]  556 	mov	dpl,#0x03
      0000F3 12 03 59         [24]  557 	lcall	_LcdChar
                           00008E   558 	C$main.c$24$2_0$22 ==.
                                    559 ;	./src/main.c:24: LcdChar(4, 0, '-');
      0000F6 75 10 00         [24]  560 	mov	_LcdChar_PARM_2,#0x00
      0000F9 75 11 2D         [24]  561 	mov	_LcdChar_PARM_3,#0x2d
      0000FC 75 82 04         [24]  562 	mov	dpl,#0x04
      0000FF 12 03 59         [24]  563 	lcall	_LcdChar
                           00009A   564 	C$main.c$25$2_0$22 ==.
                                    565 ;	./src/main.c:25: LcdChar(5, 0, time.month / 10 + '0');
      000102 AE 09            [24]  566 	mov	r6,(_main_time_65536_21 + 0x0001)
      000104 7F 00            [12]  567 	mov	r7,#0x00
      000106 75 1F 0A         [24]  568 	mov	__divsint_PARM_2,#0x0a
                                    569 ;	1-genFromRTrack replaced	mov	(__divsint_PARM_2 + 1),#0x00
      000109 8F 20            [24]  570 	mov	(__divsint_PARM_2 + 1),r7
      00010B 8E 82            [24]  571 	mov	dpl,r6
      00010D 8F 83            [24]  572 	mov	dph,r7
      00010F 12 09 34         [24]  573 	lcall	__divsint
      000112 AE 82            [24]  574 	mov	r6,dpl
      000114 74 30            [12]  575 	mov	a,#0x30
      000116 2E               [12]  576 	add	a,r6
      000117 F5 11            [12]  577 	mov	_LcdChar_PARM_3,a
      000119 75 10 00         [24]  578 	mov	_LcdChar_PARM_2,#0x00
      00011C 75 82 05         [24]  579 	mov	dpl,#0x05
      00011F 12 03 59         [24]  580 	lcall	_LcdChar
                           0000BA   581 	C$main.c$26$2_0$22 ==.
                                    582 ;	./src/main.c:26: LcdChar(6, 0, time.month % 10 + '0');
      000122 AE 09            [24]  583 	mov	r6,(_main_time_65536_21 + 0x0001)
      000124 7F 00            [12]  584 	mov	r7,#0x00
      000126 75 1F 0A         [24]  585 	mov	__modsint_PARM_2,#0x0a
                                    586 ;	1-genFromRTrack replaced	mov	(__modsint_PARM_2 + 1),#0x00
      000129 8F 20            [24]  587 	mov	(__modsint_PARM_2 + 1),r7
      00012B 8E 82            [24]  588 	mov	dpl,r6
      00012D 8F 83            [24]  589 	mov	dph,r7
      00012F 12 08 FE         [24]  590 	lcall	__modsint
      000132 AE 82            [24]  591 	mov	r6,dpl
      000134 74 30            [12]  592 	mov	a,#0x30
      000136 2E               [12]  593 	add	a,r6
      000137 F5 11            [12]  594 	mov	_LcdChar_PARM_3,a
      000139 75 10 00         [24]  595 	mov	_LcdChar_PARM_2,#0x00
      00013C 75 82 06         [24]  596 	mov	dpl,#0x06
      00013F 12 03 59         [24]  597 	lcall	_LcdChar
                           0000DA   598 	C$main.c$27$2_0$22 ==.
                                    599 ;	./src/main.c:27: LcdChar(7, 0, '-');
      000142 75 10 00         [24]  600 	mov	_LcdChar_PARM_2,#0x00
      000145 75 11 2D         [24]  601 	mov	_LcdChar_PARM_3,#0x2d
      000148 75 82 07         [24]  602 	mov	dpl,#0x07
      00014B 12 03 59         [24]  603 	lcall	_LcdChar
                           0000E6   604 	C$main.c$28$2_0$22 ==.
                                    605 ;	./src/main.c:28: LcdChar(8, 0, time.day / 10 + '0');
      00014E AE 0A            [24]  606 	mov	r6,(_main_time_65536_21 + 0x0002)
      000150 7F 00            [12]  607 	mov	r7,#0x00
      000152 75 1F 0A         [24]  608 	mov	__divsint_PARM_2,#0x0a
                                    609 ;	1-genFromRTrack replaced	mov	(__divsint_PARM_2 + 1),#0x00
      000155 8F 20            [24]  610 	mov	(__divsint_PARM_2 + 1),r7
      000157 8E 82            [24]  611 	mov	dpl,r6
      000159 8F 83            [24]  612 	mov	dph,r7
      00015B 12 09 34         [24]  613 	lcall	__divsint
      00015E AE 82            [24]  614 	mov	r6,dpl
      000160 74 30            [12]  615 	mov	a,#0x30
      000162 2E               [12]  616 	add	a,r6
      000163 F5 11            [12]  617 	mov	_LcdChar_PARM_3,a
      000165 75 10 00         [24]  618 	mov	_LcdChar_PARM_2,#0x00
      000168 75 82 08         [24]  619 	mov	dpl,#0x08
      00016B 12 03 59         [24]  620 	lcall	_LcdChar
                           000106   621 	C$main.c$29$2_0$22 ==.
                                    622 ;	./src/main.c:29: LcdChar(9, 0, time.day % 10 + '0');
      00016E AE 0A            [24]  623 	mov	r6,(_main_time_65536_21 + 0x0002)
      000170 7F 00            [12]  624 	mov	r7,#0x00
      000172 75 1F 0A         [24]  625 	mov	__modsint_PARM_2,#0x0a
                                    626 ;	1-genFromRTrack replaced	mov	(__modsint_PARM_2 + 1),#0x00
      000175 8F 20            [24]  627 	mov	(__modsint_PARM_2 + 1),r7
      000177 8E 82            [24]  628 	mov	dpl,r6
      000179 8F 83            [24]  629 	mov	dph,r7
      00017B 12 08 FE         [24]  630 	lcall	__modsint
      00017E AE 82            [24]  631 	mov	r6,dpl
      000180 74 30            [12]  632 	mov	a,#0x30
      000182 2E               [12]  633 	add	a,r6
      000183 F5 11            [12]  634 	mov	_LcdChar_PARM_3,a
      000185 75 10 00         [24]  635 	mov	_LcdChar_PARM_2,#0x00
      000188 75 82 09         [24]  636 	mov	dpl,#0x09
      00018B 12 03 59         [24]  637 	lcall	_LcdChar
                           000126   638 	C$main.c$31$2_0$22 ==.
                                    639 ;	./src/main.c:31: LcdChar(0, 1, time.hour / 10 + '0');
      00018E AE 0C            [24]  640 	mov	r6,(_main_time_65536_21 + 0x0004)
      000190 7F 00            [12]  641 	mov	r7,#0x00
      000192 75 1F 0A         [24]  642 	mov	__divsint_PARM_2,#0x0a
                                    643 ;	1-genFromRTrack replaced	mov	(__divsint_PARM_2 + 1),#0x00
      000195 8F 20            [24]  644 	mov	(__divsint_PARM_2 + 1),r7
      000197 8E 82            [24]  645 	mov	dpl,r6
      000199 8F 83            [24]  646 	mov	dph,r7
      00019B 12 09 34         [24]  647 	lcall	__divsint
      00019E AE 82            [24]  648 	mov	r6,dpl
      0001A0 74 30            [12]  649 	mov	a,#0x30
      0001A2 2E               [12]  650 	add	a,r6
      0001A3 F5 11            [12]  651 	mov	_LcdChar_PARM_3,a
      0001A5 75 10 01         [24]  652 	mov	_LcdChar_PARM_2,#0x01
      0001A8 75 82 00         [24]  653 	mov	dpl,#0x00
      0001AB 12 03 59         [24]  654 	lcall	_LcdChar
                           000146   655 	C$main.c$32$2_0$22 ==.
                                    656 ;	./src/main.c:32: LcdChar(1, 1, time.hour % 10 + '0');
      0001AE AE 0C            [24]  657 	mov	r6,(_main_time_65536_21 + 0x0004)
      0001B0 7F 00            [12]  658 	mov	r7,#0x00
      0001B2 75 1F 0A         [24]  659 	mov	__modsint_PARM_2,#0x0a
                                    660 ;	1-genFromRTrack replaced	mov	(__modsint_PARM_2 + 1),#0x00
      0001B5 8F 20            [24]  661 	mov	(__modsint_PARM_2 + 1),r7
      0001B7 8E 82            [24]  662 	mov	dpl,r6
      0001B9 8F 83            [24]  663 	mov	dph,r7
      0001BB 12 08 FE         [24]  664 	lcall	__modsint
      0001BE AE 82            [24]  665 	mov	r6,dpl
      0001C0 74 30            [12]  666 	mov	a,#0x30
      0001C2 2E               [12]  667 	add	a,r6
      0001C3 F5 11            [12]  668 	mov	_LcdChar_PARM_3,a
      0001C5 75 10 01         [24]  669 	mov	_LcdChar_PARM_2,#0x01
      0001C8 75 82 01         [24]  670 	mov	dpl,#0x01
      0001CB 12 03 59         [24]  671 	lcall	_LcdChar
                           000166   672 	C$main.c$33$2_0$22 ==.
                                    673 ;	./src/main.c:33: LcdChar(2, 1, ':');
      0001CE 75 10 01         [24]  674 	mov	_LcdChar_PARM_2,#0x01
      0001D1 75 11 3A         [24]  675 	mov	_LcdChar_PARM_3,#0x3a
      0001D4 75 82 02         [24]  676 	mov	dpl,#0x02
      0001D7 12 03 59         [24]  677 	lcall	_LcdChar
                           000172   678 	C$main.c$34$2_0$22 ==.
                                    679 ;	./src/main.c:34: LcdChar(3, 1, time.minute / 10 + '0');
      0001DA AE 0D            [24]  680 	mov	r6,(_main_time_65536_21 + 0x0005)
      0001DC 7F 00            [12]  681 	mov	r7,#0x00
      0001DE 75 1F 0A         [24]  682 	mov	__divsint_PARM_2,#0x0a
                                    683 ;	1-genFromRTrack replaced	mov	(__divsint_PARM_2 + 1),#0x00
      0001E1 8F 20            [24]  684 	mov	(__divsint_PARM_2 + 1),r7
      0001E3 8E 82            [24]  685 	mov	dpl,r6
      0001E5 8F 83            [24]  686 	mov	dph,r7
      0001E7 12 09 34         [24]  687 	lcall	__divsint
      0001EA AE 82            [24]  688 	mov	r6,dpl
      0001EC 74 30            [12]  689 	mov	a,#0x30
      0001EE 2E               [12]  690 	add	a,r6
      0001EF F5 11            [12]  691 	mov	_LcdChar_PARM_3,a
      0001F1 75 10 01         [24]  692 	mov	_LcdChar_PARM_2,#0x01
      0001F4 75 82 03         [24]  693 	mov	dpl,#0x03
      0001F7 12 03 59         [24]  694 	lcall	_LcdChar
                           000192   695 	C$main.c$35$2_0$22 ==.
                                    696 ;	./src/main.c:35: LcdChar(4, 1, time.minute % 10 + '0');
      0001FA AE 0D            [24]  697 	mov	r6,(_main_time_65536_21 + 0x0005)
      0001FC 7F 00            [12]  698 	mov	r7,#0x00
      0001FE 75 1F 0A         [24]  699 	mov	__modsint_PARM_2,#0x0a
                                    700 ;	1-genFromRTrack replaced	mov	(__modsint_PARM_2 + 1),#0x00
      000201 8F 20            [24]  701 	mov	(__modsint_PARM_2 + 1),r7
      000203 8E 82            [24]  702 	mov	dpl,r6
      000205 8F 83            [24]  703 	mov	dph,r7
      000207 12 08 FE         [24]  704 	lcall	__modsint
      00020A AE 82            [24]  705 	mov	r6,dpl
      00020C 74 30            [12]  706 	mov	a,#0x30
      00020E 2E               [12]  707 	add	a,r6
      00020F F5 11            [12]  708 	mov	_LcdChar_PARM_3,a
      000211 75 10 01         [24]  709 	mov	_LcdChar_PARM_2,#0x01
      000214 75 82 04         [24]  710 	mov	dpl,#0x04
      000217 12 03 59         [24]  711 	lcall	_LcdChar
                           0001B2   712 	C$main.c$36$2_0$22 ==.
                                    713 ;	./src/main.c:36: LcdChar(5, 1, ':');
      00021A 75 10 01         [24]  714 	mov	_LcdChar_PARM_2,#0x01
      00021D 75 11 3A         [24]  715 	mov	_LcdChar_PARM_3,#0x3a
      000220 75 82 05         [24]  716 	mov	dpl,#0x05
      000223 12 03 59         [24]  717 	lcall	_LcdChar
                           0001BE   718 	C$main.c$37$2_0$22 ==.
                                    719 ;	./src/main.c:37: LcdChar(6, 1, time.second / 10 + '0');
      000226 AE 0E            [24]  720 	mov	r6,(_main_time_65536_21 + 0x0006)
      000228 7F 00            [12]  721 	mov	r7,#0x00
      00022A 75 1F 0A         [24]  722 	mov	__divsint_PARM_2,#0x0a
                                    723 ;	1-genFromRTrack replaced	mov	(__divsint_PARM_2 + 1),#0x00
      00022D 8F 20            [24]  724 	mov	(__divsint_PARM_2 + 1),r7
      00022F 8E 82            [24]  725 	mov	dpl,r6
      000231 8F 83            [24]  726 	mov	dph,r7
      000233 12 09 34         [24]  727 	lcall	__divsint
      000236 AE 82            [24]  728 	mov	r6,dpl
      000238 74 30            [12]  729 	mov	a,#0x30
      00023A 2E               [12]  730 	add	a,r6
      00023B F5 11            [12]  731 	mov	_LcdChar_PARM_3,a
      00023D 75 10 01         [24]  732 	mov	_LcdChar_PARM_2,#0x01
      000240 75 82 06         [24]  733 	mov	dpl,#0x06
      000243 12 03 59         [24]  734 	lcall	_LcdChar
                           0001DE   735 	C$main.c$38$2_0$22 ==.
                                    736 ;	./src/main.c:38: LcdChar(7, 1, time.second % 10 + '0');
      000246 AE 0E            [24]  737 	mov	r6,(_main_time_65536_21 + 0x0006)
      000248 7F 00            [12]  738 	mov	r7,#0x00
      00024A 75 1F 0A         [24]  739 	mov	__modsint_PARM_2,#0x0a
                                    740 ;	1-genFromRTrack replaced	mov	(__modsint_PARM_2 + 1),#0x00
      00024D 8F 20            [24]  741 	mov	(__modsint_PARM_2 + 1),r7
      00024F 8E 82            [24]  742 	mov	dpl,r6
      000251 8F 83            [24]  743 	mov	dph,r7
      000253 12 08 FE         [24]  744 	lcall	__modsint
      000256 AE 82            [24]  745 	mov	r6,dpl
      000258 74 30            [12]  746 	mov	a,#0x30
      00025A 2E               [12]  747 	add	a,r6
      00025B F5 11            [12]  748 	mov	_LcdChar_PARM_3,a
      00025D 75 10 01         [24]  749 	mov	_LcdChar_PARM_2,#0x01
      000260 75 82 07         [24]  750 	mov	dpl,#0x07
      000263 12 03 59         [24]  751 	lcall	_LcdChar
      000266 02 00 8C         [24]  752 	ljmp	00102$
                           000201   753 	C$main.c$40$1_0$21 ==.
                                    754 ;	./src/main.c:40: }
                           000201   755 	C$main.c$40$1_0$21 ==.
                           000201   756 	XG$main$0$0 ==.
      000269 22               [24]  757 	ret
                                    758 	.area CSEG    (CODE)
                                    759 	.area CONST   (CODE)
                           000000   760 Fmain$__str_0$0_0$0 == .
                                    761 	.area CONST   (CODE)
      000A42                        762 ___str_0:
      000A42 54 65 73 74 31 32 33   763 	.ascii "Test123..."
             2E 2E 2E
      000A4C 00                     764 	.db 0x00
                                    765 	.area CSEG    (CODE)
                                    766 	.area XINIT   (CODE)
                                    767 	.area CABS    (ABS,CODE)
