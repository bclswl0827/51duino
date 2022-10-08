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
                                     11 	.globl _loop_lights_65537_66
                                     12 	.globl _PIN_P37
                                     13 	.globl _PIN_P36
                                     14 	.globl _PIN_P35
                                     15 	.globl _PIN_P34
                                     16 	.globl _PIN_P33
                                     17 	.globl _PIN_P32
                                     18 	.globl _PIN_P31
                                     19 	.globl _PIN_P30
                                     20 	.globl _PIN_P27
                                     21 	.globl _PIN_P26
                                     22 	.globl _PIN_P25
                                     23 	.globl _PIN_P24
                                     24 	.globl _PIN_P23
                                     25 	.globl _PIN_P22
                                     26 	.globl _PIN_P21
                                     27 	.globl _PIN_P20
                                     28 	.globl _PIN_P17
                                     29 	.globl _PIN_P16
                                     30 	.globl _PIN_P15
                                     31 	.globl _PIN_P14
                                     32 	.globl _PIN_P13
                                     33 	.globl _PIN_P12
                                     34 	.globl _PIN_P11
                                     35 	.globl _PIN_P10
                                     36 	.globl _PIN_P07
                                     37 	.globl _PIN_P06
                                     38 	.globl _PIN_P05
                                     39 	.globl _PIN_P04
                                     40 	.globl _PIN_P03
                                     41 	.globl _PIN_P02
                                     42 	.globl _PIN_P01
                                     43 	.globl _PIN_P00
                                     44 	.globl _main
                                     45 	.globl _SerialAvailable
                                     46 	.globl _SerialRead
                                     47 	.globl _SerialPrintln
                                     48 	.globl _SerialPrint
                                     49 	.globl _SerialWrite
                                     50 	.globl _SerialSetTimeout
                                     51 	.globl _SerialEnd
                                     52 	.globl _SerialBegin
                                     53 	.globl _SerialFlush
                                     54 	.globl _printf
                                     55 	.globl _millisInit
                                     56 	.globl _millisInterrupt
                                     57 	.globl _shiftOut
                                     58 	.globl _digitalWrite
                                     59 	.globl _delay
                                     60 	.globl _CP_RL2
                                     61 	.globl _C_T2
                                     62 	.globl _TR2
                                     63 	.globl _EXEN2
                                     64 	.globl _TCLK
                                     65 	.globl _RCLK
                                     66 	.globl _EXF2
                                     67 	.globl _TF2
                                     68 	.globl _T2
                                     69 	.globl _T2EX
                                     70 	.globl _RI
                                     71 	.globl _TI
                                     72 	.globl _RB8
                                     73 	.globl _TB8
                                     74 	.globl _REN
                                     75 	.globl _SM2
                                     76 	.globl _SM1
                                     77 	.globl _SM0
                                     78 	.globl _RXD
                                     79 	.globl _TXD
                                     80 	.globl _INT0
                                     81 	.globl _INT1
                                     82 	.globl _T0
                                     83 	.globl _T1
                                     84 	.globl _WR
                                     85 	.globl _RD
                                     86 	.globl _PX0
                                     87 	.globl _PT0
                                     88 	.globl _PX1
                                     89 	.globl _PT1
                                     90 	.globl _PS
                                     91 	.globl _PT2
                                     92 	.globl _EX0
                                     93 	.globl _ET0
                                     94 	.globl _EX1
                                     95 	.globl _ET1
                                     96 	.globl _ES
                                     97 	.globl _ET2
                                     98 	.globl _EA
                                     99 	.globl _IT0
                                    100 	.globl _IE0
                                    101 	.globl _IT1
                                    102 	.globl _IE1
                                    103 	.globl _TR0
                                    104 	.globl _TF0
                                    105 	.globl _TR1
                                    106 	.globl _TF1
                                    107 	.globl _P
                                    108 	.globl _OV
                                    109 	.globl _RS0
                                    110 	.globl _RS1
                                    111 	.globl _F0
                                    112 	.globl _AC
                                    113 	.globl _CY
                                    114 	.globl _P37
                                    115 	.globl _P36
                                    116 	.globl _P35
                                    117 	.globl _P34
                                    118 	.globl _P33
                                    119 	.globl _P32
                                    120 	.globl _P31
                                    121 	.globl _P30
                                    122 	.globl _P27
                                    123 	.globl _P26
                                    124 	.globl _P25
                                    125 	.globl _P24
                                    126 	.globl _P23
                                    127 	.globl _P22
                                    128 	.globl _P21
                                    129 	.globl _P20
                                    130 	.globl _P17
                                    131 	.globl _P16
                                    132 	.globl _P15
                                    133 	.globl _P14
                                    134 	.globl _P13
                                    135 	.globl _P12
                                    136 	.globl _P11
                                    137 	.globl _P10
                                    138 	.globl _P07
                                    139 	.globl _P06
                                    140 	.globl _P05
                                    141 	.globl _P04
                                    142 	.globl _P03
                                    143 	.globl _P02
                                    144 	.globl _P01
                                    145 	.globl _P00
                                    146 	.globl _TH2
                                    147 	.globl _TL2
                                    148 	.globl _RCAP2H
                                    149 	.globl _RCAP2L
                                    150 	.globl _T2CON
                                    151 	.globl _SBUF
                                    152 	.globl _SCON
                                    153 	.globl _IP
                                    154 	.globl _IE
                                    155 	.globl _TH1
                                    156 	.globl _TH0
                                    157 	.globl _TL1
                                    158 	.globl _TL0
                                    159 	.globl _TMOD
                                    160 	.globl _TCON
                                    161 	.globl _PCON
                                    162 	.globl _DPH
                                    163 	.globl _DPL
                                    164 	.globl _SP
                                    165 	.globl _B
                                    166 	.globl _ACC
                                    167 	.globl _PSW
                                    168 	.globl _P3
                                    169 	.globl _P2
                                    170 	.globl _P1
                                    171 	.globl _P0
                                    172 	.globl _Serial
                                    173 	.globl _uptime
                                    174 	.globl _putchar
                                    175 	.globl _setup
                                    176 	.globl _loop
                                    177 ;--------------------------------------------------------
                                    178 ; special function registers
                                    179 ;--------------------------------------------------------
                                    180 	.area RSEG    (ABS,DATA)
      000000                        181 	.org 0x0000
                           000080   182 G$P0$0_0$0 == 0x0080
                           000080   183 _P0	=	0x0080
                           000090   184 G$P1$0_0$0 == 0x0090
                           000090   185 _P1	=	0x0090
                           0000A0   186 G$P2$0_0$0 == 0x00a0
                           0000A0   187 _P2	=	0x00a0
                           0000B0   188 G$P3$0_0$0 == 0x00b0
                           0000B0   189 _P3	=	0x00b0
                           0000D0   190 G$PSW$0_0$0 == 0x00d0
                           0000D0   191 _PSW	=	0x00d0
                           0000E0   192 G$ACC$0_0$0 == 0x00e0
                           0000E0   193 _ACC	=	0x00e0
                           0000F0   194 G$B$0_0$0 == 0x00f0
                           0000F0   195 _B	=	0x00f0
                           000081   196 G$SP$0_0$0 == 0x0081
                           000081   197 _SP	=	0x0081
                           000082   198 G$DPL$0_0$0 == 0x0082
                           000082   199 _DPL	=	0x0082
                           000083   200 G$DPH$0_0$0 == 0x0083
                           000083   201 _DPH	=	0x0083
                           000087   202 G$PCON$0_0$0 == 0x0087
                           000087   203 _PCON	=	0x0087
                           000088   204 G$TCON$0_0$0 == 0x0088
                           000088   205 _TCON	=	0x0088
                           000089   206 G$TMOD$0_0$0 == 0x0089
                           000089   207 _TMOD	=	0x0089
                           00008A   208 G$TL0$0_0$0 == 0x008a
                           00008A   209 _TL0	=	0x008a
                           00008B   210 G$TL1$0_0$0 == 0x008b
                           00008B   211 _TL1	=	0x008b
                           00008C   212 G$TH0$0_0$0 == 0x008c
                           00008C   213 _TH0	=	0x008c
                           00008D   214 G$TH1$0_0$0 == 0x008d
                           00008D   215 _TH1	=	0x008d
                           0000A8   216 G$IE$0_0$0 == 0x00a8
                           0000A8   217 _IE	=	0x00a8
                           0000B8   218 G$IP$0_0$0 == 0x00b8
                           0000B8   219 _IP	=	0x00b8
                           000098   220 G$SCON$0_0$0 == 0x0098
                           000098   221 _SCON	=	0x0098
                           000099   222 G$SBUF$0_0$0 == 0x0099
                           000099   223 _SBUF	=	0x0099
                           0000C8   224 G$T2CON$0_0$0 == 0x00c8
                           0000C8   225 _T2CON	=	0x00c8
                           0000CA   226 G$RCAP2L$0_0$0 == 0x00ca
                           0000CA   227 _RCAP2L	=	0x00ca
                           0000CB   228 G$RCAP2H$0_0$0 == 0x00cb
                           0000CB   229 _RCAP2H	=	0x00cb
                           0000CC   230 G$TL2$0_0$0 == 0x00cc
                           0000CC   231 _TL2	=	0x00cc
                           0000CD   232 G$TH2$0_0$0 == 0x00cd
                           0000CD   233 _TH2	=	0x00cd
                                    234 ;--------------------------------------------------------
                                    235 ; special function bits
                                    236 ;--------------------------------------------------------
                                    237 	.area RSEG    (ABS,DATA)
      000000                        238 	.org 0x0000
                           000080   239 G$P00$0_0$0 == 0x0080
                           000080   240 _P00	=	0x0080
                           000081   241 G$P01$0_0$0 == 0x0081
                           000081   242 _P01	=	0x0081
                           000082   243 G$P02$0_0$0 == 0x0082
                           000082   244 _P02	=	0x0082
                           000083   245 G$P03$0_0$0 == 0x0083
                           000083   246 _P03	=	0x0083
                           000084   247 G$P04$0_0$0 == 0x0084
                           000084   248 _P04	=	0x0084
                           000085   249 G$P05$0_0$0 == 0x0085
                           000085   250 _P05	=	0x0085
                           000086   251 G$P06$0_0$0 == 0x0086
                           000086   252 _P06	=	0x0086
                           000087   253 G$P07$0_0$0 == 0x0087
                           000087   254 _P07	=	0x0087
                           000090   255 G$P10$0_0$0 == 0x0090
                           000090   256 _P10	=	0x0090
                           000091   257 G$P11$0_0$0 == 0x0091
                           000091   258 _P11	=	0x0091
                           000092   259 G$P12$0_0$0 == 0x0092
                           000092   260 _P12	=	0x0092
                           000093   261 G$P13$0_0$0 == 0x0093
                           000093   262 _P13	=	0x0093
                           000094   263 G$P14$0_0$0 == 0x0094
                           000094   264 _P14	=	0x0094
                           000095   265 G$P15$0_0$0 == 0x0095
                           000095   266 _P15	=	0x0095
                           000096   267 G$P16$0_0$0 == 0x0096
                           000096   268 _P16	=	0x0096
                           000097   269 G$P17$0_0$0 == 0x0097
                           000097   270 _P17	=	0x0097
                           0000A0   271 G$P20$0_0$0 == 0x00a0
                           0000A0   272 _P20	=	0x00a0
                           0000A1   273 G$P21$0_0$0 == 0x00a1
                           0000A1   274 _P21	=	0x00a1
                           0000A2   275 G$P22$0_0$0 == 0x00a2
                           0000A2   276 _P22	=	0x00a2
                           0000A3   277 G$P23$0_0$0 == 0x00a3
                           0000A3   278 _P23	=	0x00a3
                           0000A4   279 G$P24$0_0$0 == 0x00a4
                           0000A4   280 _P24	=	0x00a4
                           0000A5   281 G$P25$0_0$0 == 0x00a5
                           0000A5   282 _P25	=	0x00a5
                           0000A6   283 G$P26$0_0$0 == 0x00a6
                           0000A6   284 _P26	=	0x00a6
                           0000A7   285 G$P27$0_0$0 == 0x00a7
                           0000A7   286 _P27	=	0x00a7
                           0000B0   287 G$P30$0_0$0 == 0x00b0
                           0000B0   288 _P30	=	0x00b0
                           0000B1   289 G$P31$0_0$0 == 0x00b1
                           0000B1   290 _P31	=	0x00b1
                           0000B2   291 G$P32$0_0$0 == 0x00b2
                           0000B2   292 _P32	=	0x00b2
                           0000B3   293 G$P33$0_0$0 == 0x00b3
                           0000B3   294 _P33	=	0x00b3
                           0000B4   295 G$P34$0_0$0 == 0x00b4
                           0000B4   296 _P34	=	0x00b4
                           0000B5   297 G$P35$0_0$0 == 0x00b5
                           0000B5   298 _P35	=	0x00b5
                           0000B6   299 G$P36$0_0$0 == 0x00b6
                           0000B6   300 _P36	=	0x00b6
                           0000B7   301 G$P37$0_0$0 == 0x00b7
                           0000B7   302 _P37	=	0x00b7
                           0000D7   303 G$CY$0_0$0 == 0x00d7
                           0000D7   304 _CY	=	0x00d7
                           0000D6   305 G$AC$0_0$0 == 0x00d6
                           0000D6   306 _AC	=	0x00d6
                           0000D5   307 G$F0$0_0$0 == 0x00d5
                           0000D5   308 _F0	=	0x00d5
                           0000D4   309 G$RS1$0_0$0 == 0x00d4
                           0000D4   310 _RS1	=	0x00d4
                           0000D3   311 G$RS0$0_0$0 == 0x00d3
                           0000D3   312 _RS0	=	0x00d3
                           0000D2   313 G$OV$0_0$0 == 0x00d2
                           0000D2   314 _OV	=	0x00d2
                           0000D0   315 G$P$0_0$0 == 0x00d0
                           0000D0   316 _P	=	0x00d0
                           00008F   317 G$TF1$0_0$0 == 0x008f
                           00008F   318 _TF1	=	0x008f
                           00008E   319 G$TR1$0_0$0 == 0x008e
                           00008E   320 _TR1	=	0x008e
                           00008D   321 G$TF0$0_0$0 == 0x008d
                           00008D   322 _TF0	=	0x008d
                           00008C   323 G$TR0$0_0$0 == 0x008c
                           00008C   324 _TR0	=	0x008c
                           00008B   325 G$IE1$0_0$0 == 0x008b
                           00008B   326 _IE1	=	0x008b
                           00008A   327 G$IT1$0_0$0 == 0x008a
                           00008A   328 _IT1	=	0x008a
                           000089   329 G$IE0$0_0$0 == 0x0089
                           000089   330 _IE0	=	0x0089
                           000088   331 G$IT0$0_0$0 == 0x0088
                           000088   332 _IT0	=	0x0088
                           0000AF   333 G$EA$0_0$0 == 0x00af
                           0000AF   334 _EA	=	0x00af
                           0000AD   335 G$ET2$0_0$0 == 0x00ad
                           0000AD   336 _ET2	=	0x00ad
                           0000AC   337 G$ES$0_0$0 == 0x00ac
                           0000AC   338 _ES	=	0x00ac
                           0000AB   339 G$ET1$0_0$0 == 0x00ab
                           0000AB   340 _ET1	=	0x00ab
                           0000AA   341 G$EX1$0_0$0 == 0x00aa
                           0000AA   342 _EX1	=	0x00aa
                           0000A9   343 G$ET0$0_0$0 == 0x00a9
                           0000A9   344 _ET0	=	0x00a9
                           0000A8   345 G$EX0$0_0$0 == 0x00a8
                           0000A8   346 _EX0	=	0x00a8
                           0000BD   347 G$PT2$0_0$0 == 0x00bd
                           0000BD   348 _PT2	=	0x00bd
                           0000BC   349 G$PS$0_0$0 == 0x00bc
                           0000BC   350 _PS	=	0x00bc
                           0000BB   351 G$PT1$0_0$0 == 0x00bb
                           0000BB   352 _PT1	=	0x00bb
                           0000BA   353 G$PX1$0_0$0 == 0x00ba
                           0000BA   354 _PX1	=	0x00ba
                           0000B9   355 G$PT0$0_0$0 == 0x00b9
                           0000B9   356 _PT0	=	0x00b9
                           0000B8   357 G$PX0$0_0$0 == 0x00b8
                           0000B8   358 _PX0	=	0x00b8
                           0000B7   359 G$RD$0_0$0 == 0x00b7
                           0000B7   360 _RD	=	0x00b7
                           0000B6   361 G$WR$0_0$0 == 0x00b6
                           0000B6   362 _WR	=	0x00b6
                           0000B5   363 G$T1$0_0$0 == 0x00b5
                           0000B5   364 _T1	=	0x00b5
                           0000B4   365 G$T0$0_0$0 == 0x00b4
                           0000B4   366 _T0	=	0x00b4
                           0000B3   367 G$INT1$0_0$0 == 0x00b3
                           0000B3   368 _INT1	=	0x00b3
                           0000B2   369 G$INT0$0_0$0 == 0x00b2
                           0000B2   370 _INT0	=	0x00b2
                           0000B1   371 G$TXD$0_0$0 == 0x00b1
                           0000B1   372 _TXD	=	0x00b1
                           0000B0   373 G$RXD$0_0$0 == 0x00b0
                           0000B0   374 _RXD	=	0x00b0
                           00009F   375 G$SM0$0_0$0 == 0x009f
                           00009F   376 _SM0	=	0x009f
                           00009E   377 G$SM1$0_0$0 == 0x009e
                           00009E   378 _SM1	=	0x009e
                           00009D   379 G$SM2$0_0$0 == 0x009d
                           00009D   380 _SM2	=	0x009d
                           00009C   381 G$REN$0_0$0 == 0x009c
                           00009C   382 _REN	=	0x009c
                           00009B   383 G$TB8$0_0$0 == 0x009b
                           00009B   384 _TB8	=	0x009b
                           00009A   385 G$RB8$0_0$0 == 0x009a
                           00009A   386 _RB8	=	0x009a
                           000099   387 G$TI$0_0$0 == 0x0099
                           000099   388 _TI	=	0x0099
                           000098   389 G$RI$0_0$0 == 0x0098
                           000098   390 _RI	=	0x0098
                           000091   391 G$T2EX$0_0$0 == 0x0091
                           000091   392 _T2EX	=	0x0091
                           000090   393 G$T2$0_0$0 == 0x0090
                           000090   394 _T2	=	0x0090
                           0000CF   395 G$TF2$0_0$0 == 0x00cf
                           0000CF   396 _TF2	=	0x00cf
                           0000CE   397 G$EXF2$0_0$0 == 0x00ce
                           0000CE   398 _EXF2	=	0x00ce
                           0000CD   399 G$RCLK$0_0$0 == 0x00cd
                           0000CD   400 _RCLK	=	0x00cd
                           0000CC   401 G$TCLK$0_0$0 == 0x00cc
                           0000CC   402 _TCLK	=	0x00cc
                           0000CB   403 G$EXEN2$0_0$0 == 0x00cb
                           0000CB   404 _EXEN2	=	0x00cb
                           0000CA   405 G$TR2$0_0$0 == 0x00ca
                           0000CA   406 _TR2	=	0x00ca
                           0000C9   407 G$C_T2$0_0$0 == 0x00c9
                           0000C9   408 _C_T2	=	0x00c9
                           0000C8   409 G$CP_RL2$0_0$0 == 0x00c8
                           0000C8   410 _CP_RL2	=	0x00c8
                                    411 ;--------------------------------------------------------
                                    412 ; overlayable register banks
                                    413 ;--------------------------------------------------------
                                    414 	.area REG_BANK_0	(REL,OVR,DATA)
      000000                        415 	.ds 8
                                    416 ;--------------------------------------------------------
                                    417 ; internal ram data
                                    418 ;--------------------------------------------------------
                                    419 	.area DSEG    (DATA)
                           000000   420 G$uptime$0_0$0==.
      000008                        421 _uptime::
      000008                        422 	.ds 4
                           000004   423 G$Serial$0_0$0==.
      00000C                        424 _Serial::
      00000C                        425 	.ds 20
                                    426 ;--------------------------------------------------------
                                    427 ; overlayable items in internal ram 
                                    428 ;--------------------------------------------------------
                                    429 	.area	OSEG    (OVR,DATA)
                                    430 	.area	OSEG    (OVR,DATA)
                                    431 ;--------------------------------------------------------
                                    432 ; Stack segment in internal ram 
                                    433 ;--------------------------------------------------------
                                    434 	.area	SSEG
      000066                        435 __start__stack:
      000066                        436 	.ds	1
                                    437 
                                    438 ;--------------------------------------------------------
                                    439 ; indirectly addressable internal ram data
                                    440 ;--------------------------------------------------------
                                    441 	.area ISEG    (DATA)
                                    442 ;--------------------------------------------------------
                                    443 ; absolute internal ram data
                                    444 ;--------------------------------------------------------
                                    445 	.area IABS    (ABS,DATA)
                                    446 	.area IABS    (ABS,DATA)
                                    447 ;--------------------------------------------------------
                                    448 ; bit data
                                    449 ;--------------------------------------------------------
                                    450 	.area BSEG    (BIT)
                                    451 ;--------------------------------------------------------
                                    452 ; paged external ram data
                                    453 ;--------------------------------------------------------
                                    454 	.area PSEG    (PAG,XDATA)
                                    455 ;--------------------------------------------------------
                                    456 ; external ram data
                                    457 ;--------------------------------------------------------
                                    458 	.area XSEG    (XDATA)
                                    459 ;--------------------------------------------------------
                                    460 ; absolute external ram data
                                    461 ;--------------------------------------------------------
                                    462 	.area XABS    (ABS,XDATA)
                                    463 ;--------------------------------------------------------
                                    464 ; external initialized ram data
                                    465 ;--------------------------------------------------------
                                    466 	.area XISEG   (XDATA)
                                    467 	.area HOME    (CODE)
                                    468 	.area GSINIT0 (CODE)
                                    469 	.area GSINIT1 (CODE)
                                    470 	.area GSINIT2 (CODE)
                                    471 	.area GSINIT3 (CODE)
                                    472 	.area GSINIT4 (CODE)
                                    473 	.area GSINIT5 (CODE)
                                    474 	.area GSINIT  (CODE)
                                    475 	.area GSFINAL (CODE)
                                    476 	.area CSEG    (CODE)
                                    477 ;--------------------------------------------------------
                                    478 ; interrupt vector 
                                    479 ;--------------------------------------------------------
                                    480 	.area HOME    (CODE)
      000000                        481 __interrupt_vect:
      000000 02 00 11         [24]  482 	ljmp	__sdcc_gsinit_startup
      000003 32               [24]  483 	reti
      000004                        484 	.ds	7
      00000B 02 00 C6         [24]  485 	ljmp	_millisInterrupt
                                    486 ;--------------------------------------------------------
                                    487 ; global & static initialisations
                                    488 ;--------------------------------------------------------
                                    489 	.area HOME    (CODE)
                                    490 	.area GSINIT  (CODE)
                                    491 	.area GSFINAL (CODE)
                                    492 	.area GSINIT  (CODE)
                                    493 	.globl __sdcc_gsinit_startup
                                    494 	.globl __sdcc_program_startup
                                    495 	.globl __start__stack
                                    496 	.globl __mcs51_genXINIT
                                    497 	.globl __mcs51_genXRAMCLEAR
                                    498 	.globl __mcs51_genRAMCLEAR
                           000000   499 	C$millis.c$9$2_1$65 ==.
                                    500 ;	src/modules/millis.c:9: uint32_t uptime = 0;
      00006A E4               [12]  501 	clr	a
      00006B F5 08            [12]  502 	mov	_uptime,a
      00006D F5 09            [12]  503 	mov	(_uptime + 1),a
      00006F F5 0A            [12]  504 	mov	(_uptime + 2),a
      000071 F5 0B            [12]  505 	mov	(_uptime + 3),a
                           000009   506 	C$ttl.h$31$2_1$65 ==.
                                    507 ;	inc/modules/ttl.h:31: Stream Serial = {
      000073 75 0C F3         [24]  508 	mov	(_Serial + 0),#_SerialBegin
      000076 75 0D 00         [24]  509 	mov	(_Serial + 1),#(_SerialBegin >> 8)
      000079 75 0E 36         [24]  510 	mov	((_Serial + 0x0002) + 0),#_SerialSetTimeout
      00007C 75 0F 01         [24]  511 	mov	((_Serial + 0x0002) + 1),#(_SerialSetTimeout >> 8)
      00007F 75 10 4C         [24]  512 	mov	((_Serial + 0x0004) + 0),#_SerialFlush
      000082 75 11 01         [24]  513 	mov	((_Serial + 0x0004) + 1),#(_SerialFlush >> 8)
      000085 75 12 2F         [24]  514 	mov	((_Serial + 0x0006) + 0),#_SerialEnd
      000088 75 13 01         [24]  515 	mov	((_Serial + 0x0006) + 1),#(_SerialEnd >> 8)
      00008B 75 14 63         [24]  516 	mov	((_Serial + 0x0008) + 0),#_SerialPrint
      00008E 75 15 01         [24]  517 	mov	((_Serial + 0x0008) + 1),#(_SerialPrint >> 8)
      000091 75 16 8E         [24]  518 	mov	((_Serial + 0x000a) + 0),#_SerialPrintln
      000094 75 17 01         [24]  519 	mov	((_Serial + 0x000a) + 1),#(_SerialPrintln >> 8)
      000097 75 18 49         [24]  520 	mov	((_Serial + 0x000c) + 0),#_printf
      00009A 75 19 06         [24]  521 	mov	((_Serial + 0x000c) + 1),#(_printf >> 8)
      00009D 75 1A 52         [24]  522 	mov	((_Serial + 0x000e) + 0),#_SerialWrite
      0000A0 75 1B 01         [24]  523 	mov	((_Serial + 0x000e) + 1),#(_SerialWrite >> 8)
      0000A3 75 1C 9B         [24]  524 	mov	((_Serial + 0x0010) + 0),#_SerialRead
      0000A6 75 1D 01         [24]  525 	mov	((_Serial + 0x0010) + 1),#(_SerialRead >> 8)
      0000A9 75 1E A4         [24]  526 	mov	((_Serial + 0x0012) + 0),#_SerialAvailable
      0000AC 75 1F 01         [24]  527 	mov	((_Serial + 0x0012) + 1),#(_SerialAvailable >> 8)
                                    528 	.area GSFINAL (CODE)
      0000AF 02 00 0E         [24]  529 	ljmp	__sdcc_program_startup
                                    530 ;--------------------------------------------------------
                                    531 ; Home
                                    532 ;--------------------------------------------------------
                                    533 	.area HOME    (CODE)
                                    534 	.area HOME    (CODE)
      00000E                        535 __sdcc_program_startup:
      00000E 02 01 B7         [24]  536 	ljmp	_main
                                    537 ;	return from main will return to caller
                                    538 ;--------------------------------------------------------
                                    539 ; code
                                    540 ;--------------------------------------------------------
                                    541 	.area CSEG    (CODE)
                                    542 ;------------------------------------------------------------
                                    543 ;Allocation info for local variables in function 'millisInit'
                                    544 ;------------------------------------------------------------
                           000000   545 	G$millisInit$0$0 ==.
                           000000   546 	C$millis.c$12$0_0$8 ==.
                                    547 ;	src/modules/millis.c:12: void millisInit() {
                                    548 ;	-----------------------------------------
                                    549 ;	 function millisInit
                                    550 ;	-----------------------------------------
      0000B2                        551 _millisInit:
                           000007   552 	ar7 = 0x07
                           000006   553 	ar6 = 0x06
                           000005   554 	ar5 = 0x05
                           000004   555 	ar4 = 0x04
                           000003   556 	ar3 = 0x03
                           000002   557 	ar2 = 0x02
                           000001   558 	ar1 = 0x01
                           000000   559 	ar0 = 0x00
                           000000   560 	C$millis.c$14$1_0$8 ==.
                                    561 ;	src/modules/millis.c:14: TMOD = 0x01;
      0000B2 75 89 01         [24]  562 	mov	_TMOD,#0x01
                           000003   563 	C$millis.c$16$1_0$8 ==.
                                    564 ;	src/modules/millis.c:16: TH0 = (65536 - PERIOD) / 256;
      0000B5 75 8C FC         [24]  565 	mov	_TH0,#0xfc
                           000006   566 	C$millis.c$18$1_0$8 ==.
                                    567 ;	src/modules/millis.c:18: TL0 = (65536 - PERIOD) % 256;
      0000B8 75 8A 67         [24]  568 	mov	_TL0,#0x67
                           000009   569 	C$millis.c$19$1_0$8 ==.
                                    570 ;	src/modules/millis.c:19: EA = ET0 = TR0 = 1;
                                    571 ;	assignBit
      0000BB D2 8C            [12]  572 	setb	_TR0
                                    573 ;	assignBit
      0000BD A2 8C            [12]  574 	mov	c,_TR0
      0000BF 92 A9            [24]  575 	mov	_ET0,c
                                    576 ;	assignBit
      0000C1 A2 A9            [12]  577 	mov	c,_ET0
      0000C3 92 AF            [24]  578 	mov	_EA,c
                           000013   579 	C$millis.c$20$1_0$8 ==.
                                    580 ;	src/modules/millis.c:20: }
                           000013   581 	C$millis.c$20$1_0$8 ==.
                           000013   582 	XG$millisInit$0$0 ==.
      0000C5 22               [24]  583 	ret
                                    584 ;------------------------------------------------------------
                                    585 ;Allocation info for local variables in function 'millisInterrupt'
                                    586 ;------------------------------------------------------------
                           000014   587 	G$millisInterrupt$0$0 ==.
                           000014   588 	C$millis.c$23$1_0$9 ==.
                                    589 ;	src/modules/millis.c:23: void millisInterrupt() interrupt 1 {
                                    590 ;	-----------------------------------------
                                    591 ;	 function millisInterrupt
                                    592 ;	-----------------------------------------
      0000C6                        593 _millisInterrupt:
      0000C6 C0 E0            [24]  594 	push	acc
      0000C8 C0 D0            [24]  595 	push	psw
                           000018   596 	C$millis.c$25$1_0$9 ==.
                                    597 ;	src/modules/millis.c:25: TH0 = (65536 - PERIOD) / 256;
      0000CA 75 8C FC         [24]  598 	mov	_TH0,#0xfc
                           00001B   599 	C$millis.c$27$1_0$9 ==.
                                    600 ;	src/modules/millis.c:27: TL0 = (65536 - PERIOD) % 256;
      0000CD 75 8A 67         [24]  601 	mov	_TL0,#0x67
                           00001E   602 	C$millis.c$29$1_0$9 ==.
                                    603 ;	src/modules/millis.c:29: uptime++;
      0000D0 05 08            [12]  604 	inc	_uptime
      0000D2 E4               [12]  605 	clr	a
      0000D3 B5 08 0C         [24]  606 	cjne	a,_uptime,00103$
      0000D6 05 09            [12]  607 	inc	(_uptime + 1)
      0000D8 B5 09 07         [24]  608 	cjne	a,(_uptime + 1),00103$
      0000DB 05 0A            [12]  609 	inc	(_uptime + 2)
      0000DD B5 0A 02         [24]  610 	cjne	a,(_uptime + 2),00103$
      0000E0 05 0B            [12]  611 	inc	(_uptime + 3)
      0000E2                        612 00103$:
                           000030   613 	C$millis.c$30$1_0$9 ==.
                                    614 ;	src/modules/millis.c:30: }
      0000E2 D0 D0            [24]  615 	pop	psw
      0000E4 D0 E0            [24]  616 	pop	acc
                           000034   617 	C$millis.c$30$1_0$9 ==.
                           000034   618 	XG$millisInterrupt$0$0 ==.
      0000E6 32               [24]  619 	reti
                                    620 ;	eliminated unneeded mov psw,# (no regs used in bank)
                                    621 ;	eliminated unneeded push/pop dpl
                                    622 ;	eliminated unneeded push/pop dph
                                    623 ;	eliminated unneeded push/pop b
                                    624 ;------------------------------------------------------------
                                    625 ;Allocation info for local variables in function 'millis'
                                    626 ;------------------------------------------------------------
                           000035   627 	G$millis$0$0 ==.
                           000035   628 	C$millis.c$33$1_0$10 ==.
                                    629 ;	src/modules/millis.c:33: uint32_t millis() {
                                    630 ;	-----------------------------------------
                                    631 ;	 function millis
                                    632 ;	-----------------------------------------
      0000E7                        633 _millis:
                           000035   634 	C$millis.c$34$1_0$10 ==.
                                    635 ;	src/modules/millis.c:34: return uptime;
      0000E7 85 08 82         [24]  636 	mov	dpl,_uptime
      0000EA 85 09 83         [24]  637 	mov	dph,(_uptime + 1)
      0000ED 85 0A F0         [24]  638 	mov	b,(_uptime + 2)
      0000F0 E5 0B            [12]  639 	mov	a,(_uptime + 3)
                           000040   640 	C$millis.c$35$1_0$10 ==.
                                    641 ;	src/modules/millis.c:35: }
                           000040   642 	C$millis.c$35$1_0$10 ==.
                           000040   643 	XG$millis$0$0 ==.
      0000F2 22               [24]  644 	ret
                                    645 ;------------------------------------------------------------
                                    646 ;Allocation info for local variables in function 'SerialBegin'
                                    647 ;------------------------------------------------------------
                                    648 ;b                         Allocated to registers r6 r7 
                                    649 ;------------------------------------------------------------
                           000041   650 	G$SerialBegin$0$0 ==.
                           000041   651 	C$ttl.c$6$1_0$35 ==.
                                    652 ;	src/modules/ttl.c:6: void SerialBegin(uint16_t b) {
                                    653 ;	-----------------------------------------
                                    654 ;	 function SerialBegin
                                    655 ;	-----------------------------------------
      0000F3                        656 _SerialBegin:
      0000F3 AE 82            [24]  657 	mov	r6,dpl
      0000F5 AF 83            [24]  658 	mov	r7,dph
                           000045   659 	C$ttl.c$8$1_0$35 ==.
                                    660 ;	src/modules/ttl.c:8: PCON = 0x80;
      0000F7 75 87 80         [24]  661 	mov	_PCON,#0x80
                           000048   662 	C$ttl.c$10$1_0$35 ==.
                                    663 ;	src/modules/ttl.c:10: SCON = 0x50;
      0000FA 75 98 50         [24]  664 	mov	_SCON,#0x50
                           00004B   665 	C$ttl.c$12$1_0$35 ==.
                                    666 ;	src/modules/ttl.c:12: TMOD = 0x20;
      0000FD 75 89 20         [24]  667 	mov	_TMOD,#0x20
                           00004E   668 	C$ttl.c$14$1_0$35 ==.
                                    669 ;	src/modules/ttl.c:14: TH1 = TL1 = -(CRYSTAL / 12 / 32 / (b / 2));
      000100 EF               [12]  670 	mov	a,r7
      000101 C3               [12]  671 	clr	c
      000102 13               [12]  672 	rrc	a
      000103 CE               [12]  673 	xch	a,r6
      000104 13               [12]  674 	rrc	a
      000105 CE               [12]  675 	xch	a,r6
      000106 FF               [12]  676 	mov	r7,a
      000107 8E 5C            [24]  677 	mov	__divslong_PARM_2,r6
      000109 8F 5D            [24]  678 	mov	(__divslong_PARM_2 + 1),r7
      00010B 75 5E 00         [24]  679 	mov	(__divslong_PARM_2 + 2),#0x00
      00010E 75 5F 00         [24]  680 	mov	(__divslong_PARM_2 + 3),#0x00
      000111 90 70 80         [24]  681 	mov	dptr,#0x7080
      000114 E4               [12]  682 	clr	a
      000115 F5 F0            [12]  683 	mov	b,a
      000117 12 05 9E         [24]  684 	lcall	__divslong
      00011A AC 82            [24]  685 	mov	r4,dpl
      00011C C3               [12]  686 	clr	c
      00011D E4               [12]  687 	clr	a
      00011E 9C               [12]  688 	subb	a,r4
      00011F FC               [12]  689 	mov	r4,a
      000120 8C 8B            [24]  690 	mov	_TL1,r4
      000122 8C 8D            [24]  691 	mov	_TH1,r4
                           000072   692 	C$ttl.c$16$1_0$35 ==.
                                    693 ;	src/modules/ttl.c:16: TR1 = EA = ES = 1;
                                    694 ;	assignBit
      000124 D2 AC            [12]  695 	setb	_ES
                                    696 ;	assignBit
      000126 A2 AC            [12]  697 	mov	c,_ES
      000128 92 AF            [24]  698 	mov	_EA,c
                                    699 ;	assignBit
      00012A A2 AF            [12]  700 	mov	c,_EA
      00012C 92 8E            [24]  701 	mov	_TR1,c
                           00007C   702 	C$ttl.c$17$1_0$35 ==.
                                    703 ;	src/modules/ttl.c:17: }
                           00007C   704 	C$ttl.c$17$1_0$35 ==.
                           00007C   705 	XG$SerialBegin$0$0 ==.
      00012E 22               [24]  706 	ret
                                    707 ;------------------------------------------------------------
                                    708 ;Allocation info for local variables in function 'SerialEnd'
                                    709 ;------------------------------------------------------------
                           00007D   710 	G$SerialEnd$0$0 ==.
                           00007D   711 	C$ttl.c$20$1_0$36 ==.
                                    712 ;	src/modules/ttl.c:20: void SerialEnd() {
                                    713 ;	-----------------------------------------
                                    714 ;	 function SerialEnd
                                    715 ;	-----------------------------------------
      00012F                        716 _SerialEnd:
                           00007D   717 	C$ttl.c$22$1_0$36 ==.
                                    718 ;	src/modules/ttl.c:22: EA = ES = 0;
                                    719 ;	assignBit
      00012F C2 AC            [12]  720 	clr	_ES
                                    721 ;	assignBit
      000131 A2 AC            [12]  722 	mov	c,_ES
      000133 92 AF            [24]  723 	mov	_EA,c
                           000083   724 	C$ttl.c$23$1_0$36 ==.
                                    725 ;	src/modules/ttl.c:23: }
                           000083   726 	C$ttl.c$23$1_0$36 ==.
                           000083   727 	XG$SerialEnd$0$0 ==.
      000135 22               [24]  728 	ret
                                    729 ;------------------------------------------------------------
                                    730 ;Allocation info for local variables in function 'SerialSetTimeout'
                                    731 ;------------------------------------------------------------
                                    732 ;t                         Allocated to registers r6 r7 
                                    733 ;------------------------------------------------------------
                           000084   734 	G$SerialSetTimeout$0$0 ==.
                           000084   735 	C$ttl.c$26$1_0$38 ==.
                                    736 ;	src/modules/ttl.c:26: void SerialSetTimeout(uint16_t t) {
                                    737 ;	-----------------------------------------
                                    738 ;	 function SerialSetTimeout
                                    739 ;	-----------------------------------------
      000136                        740 _SerialSetTimeout:
      000136 AE 82            [24]  741 	mov	r6,dpl
      000138 AF 83            [24]  742 	mov	r7,dph
                           000088   743 	C$ttl.c$28$1_0$38 ==.
                                    744 ;	src/modules/ttl.c:28: TMOD = 0x01;
      00013A 75 89 01         [24]  745 	mov	_TMOD,#0x01
                           00008B   746 	C$ttl.c$30$1_0$38 ==.
                                    747 ;	src/modules/ttl.c:30: TH0 = (t >> 8) & 0xff;
      00013D 8F 8C            [24]  748 	mov	_TH0,r7
                           00008D   749 	C$ttl.c$31$1_0$38 ==.
                                    750 ;	src/modules/ttl.c:31: TL0 = t & 0xff;
      00013F 8E 8A            [24]  751 	mov	_TL0,r6
                           00008F   752 	C$ttl.c$33$1_0$38 ==.
                                    753 ;	src/modules/ttl.c:33: TR0 = EA = ET0 = 1;
                                    754 ;	assignBit
      000141 D2 A9            [12]  755 	setb	_ET0
                                    756 ;	assignBit
      000143 A2 A9            [12]  757 	mov	c,_ET0
      000145 92 AF            [24]  758 	mov	_EA,c
                                    759 ;	assignBit
      000147 A2 AF            [12]  760 	mov	c,_EA
      000149 92 8C            [24]  761 	mov	_TR0,c
                           000099   762 	C$ttl.c$34$1_0$38 ==.
                                    763 ;	src/modules/ttl.c:34: }
                           000099   764 	C$ttl.c$34$1_0$38 ==.
                           000099   765 	XG$SerialSetTimeout$0$0 ==.
      00014B 22               [24]  766 	ret
                                    767 ;------------------------------------------------------------
                                    768 ;Allocation info for local variables in function 'SerialFlush'
                                    769 ;------------------------------------------------------------
                           00009A   770 	G$SerialFlush$0$0 ==.
                           00009A   771 	C$ttl.c$37$1_0$39 ==.
                                    772 ;	src/modules/ttl.c:37: void SerialFlush() {
                                    773 ;	-----------------------------------------
                                    774 ;	 function SerialFlush
                                    775 ;	-----------------------------------------
      00014C                        776 _SerialFlush:
                           00009A   777 	C$ttl.c$39$1_0$39 ==.
                                    778 ;	src/modules/ttl.c:39: while (!TI) {
      00014C                        779 00101$:
                           00009A   780 	C$ttl.c$43$1_0$39 ==.
                                    781 ;	src/modules/ttl.c:43: TI = 0;
                                    782 ;	assignBit
      00014C 10 99 02         [24]  783 	jbc	_TI,00114$
      00014F 80 FB            [24]  784 	sjmp	00101$
      000151                        785 00114$:
                           00009F   786 	C$ttl.c$44$1_0$39 ==.
                                    787 ;	src/modules/ttl.c:44: }
                           00009F   788 	C$ttl.c$44$1_0$39 ==.
                           00009F   789 	XG$SerialFlush$0$0 ==.
      000151 22               [24]  790 	ret
                                    791 ;------------------------------------------------------------
                                    792 ;Allocation info for local variables in function 'SerialWrite'
                                    793 ;------------------------------------------------------------
                                    794 ;c                         Allocated to registers r7 
                                    795 ;------------------------------------------------------------
                           0000A0   796 	G$SerialWrite$0$0 ==.
                           0000A0   797 	C$ttl.c$47$1_0$42 ==.
                                    798 ;	src/modules/ttl.c:47: void SerialWrite(uint8_t c) {
                                    799 ;	-----------------------------------------
                                    800 ;	 function SerialWrite
                                    801 ;	-----------------------------------------
      000152                        802 _SerialWrite:
      000152 AF 82            [24]  803 	mov	r7,dpl
                           0000A2   804 	C$ttl.c$49$1_0$42 ==.
                                    805 ;	src/modules/ttl.c:49: ES = 0;
                                    806 ;	assignBit
      000154 C2 AC            [12]  807 	clr	_ES
                           0000A4   808 	C$ttl.c$51$1_0$42 ==.
                                    809 ;	src/modules/ttl.c:51: SBUF = c;
      000156 8F 99            [24]  810 	mov	_SBUF,r7
                           0000A6   811 	C$ttl.c$53$1_0$42 ==.
                                    812 ;	src/modules/ttl.c:53: while (!TI) {
      000158                        813 00101$:
                           0000A6   814 	C$ttl.c$57$1_0$42 ==.
                                    815 ;	src/modules/ttl.c:57: TI = 0;
                                    816 ;	assignBit
      000158 10 99 02         [24]  817 	jbc	_TI,00114$
      00015B 80 FB            [24]  818 	sjmp	00101$
      00015D                        819 00114$:
                           0000AB   820 	C$ttl.c$59$1_0$42 ==.
                                    821 ;	src/modules/ttl.c:59: ES = !TI;
      00015D A2 99            [12]  822 	mov	c,_TI
      00015F B3               [12]  823 	cpl	c
      000160 92 AC            [24]  824 	mov	_ES,c
                           0000B0   825 	C$ttl.c$60$1_0$42 ==.
                                    826 ;	src/modules/ttl.c:60: }
                           0000B0   827 	C$ttl.c$60$1_0$42 ==.
                           0000B0   828 	XG$SerialWrite$0$0 ==.
      000162 22               [24]  829 	ret
                                    830 ;------------------------------------------------------------
                                    831 ;Allocation info for local variables in function 'SerialPrint'
                                    832 ;------------------------------------------------------------
                                    833 ;s                         Allocated to registers 
                                    834 ;------------------------------------------------------------
                           0000B1   835 	G$SerialPrint$0$0 ==.
                           0000B1   836 	C$ttl.c$63$1_0$45 ==.
                                    837 ;	src/modules/ttl.c:63: void SerialPrint(char* s) {
                                    838 ;	-----------------------------------------
                                    839 ;	 function SerialPrint
                                    840 ;	-----------------------------------------
      000163                        841 _SerialPrint:
      000163 AD 82            [24]  842 	mov	r5,dpl
      000165 AE 83            [24]  843 	mov	r6,dph
      000167 AF F0            [24]  844 	mov	r7,b
                           0000B7   845 	C$ttl.c$65$1_0$45 ==.
                                    846 ;	src/modules/ttl.c:65: while (*s) {
      000169                        847 00101$:
      000169 8D 82            [24]  848 	mov	dpl,r5
      00016B 8E 83            [24]  849 	mov	dph,r6
      00016D 8F F0            [24]  850 	mov	b,r7
      00016F 12 0D 84         [24]  851 	lcall	__gptrget
      000172 FC               [12]  852 	mov	r4,a
      000173 60 18            [24]  853 	jz	00104$
                           0000C3   854 	C$ttl.c$66$2_0$46 ==.
                                    855 ;	src/modules/ttl.c:66: SerialWrite(*s++);
      000175 8C 82            [24]  856 	mov	dpl,r4
      000177 0D               [12]  857 	inc	r5
      000178 BD 00 01         [24]  858 	cjne	r5,#0x00,00116$
      00017B 0E               [12]  859 	inc	r6
      00017C                        860 00116$:
      00017C C0 07            [24]  861 	push	ar7
      00017E C0 06            [24]  862 	push	ar6
      000180 C0 05            [24]  863 	push	ar5
      000182 12 01 52         [24]  864 	lcall	_SerialWrite
      000185 D0 05            [24]  865 	pop	ar5
      000187 D0 06            [24]  866 	pop	ar6
      000189 D0 07            [24]  867 	pop	ar7
      00018B 80 DC            [24]  868 	sjmp	00101$
      00018D                        869 00104$:
                           0000DB   870 	C$ttl.c$68$1_0$45 ==.
                                    871 ;	src/modules/ttl.c:68: }
                           0000DB   872 	C$ttl.c$68$1_0$45 ==.
                           0000DB   873 	XG$SerialPrint$0$0 ==.
      00018D 22               [24]  874 	ret
                                    875 ;------------------------------------------------------------
                                    876 ;Allocation info for local variables in function 'SerialPrintln'
                                    877 ;------------------------------------------------------------
                                    878 ;s                         Allocated to registers r5 r6 r7 
                                    879 ;------------------------------------------------------------
                           0000DC   880 	G$SerialPrintln$0$0 ==.
                           0000DC   881 	C$ttl.c$71$1_0$48 ==.
                                    882 ;	src/modules/ttl.c:71: void SerialPrintln(char* s) {
                                    883 ;	-----------------------------------------
                                    884 ;	 function SerialPrintln
                                    885 ;	-----------------------------------------
      00018E                        886 _SerialPrintln:
                           0000DC   887 	C$ttl.c$73$1_0$48 ==.
                                    888 ;	src/modules/ttl.c:73: SerialPrint(s);
      00018E 12 01 63         [24]  889 	lcall	_SerialPrint
                           0000DF   890 	C$ttl.c$74$1_0$48 ==.
                                    891 ;	src/modules/ttl.c:74: SerialPrint("\r\n");
      000191 90 0D E4         [24]  892 	mov	dptr,#___str_0
      000194 75 F0 80         [24]  893 	mov	b,#0x80
      000197 12 01 63         [24]  894 	lcall	_SerialPrint
                           0000E8   895 	C$ttl.c$75$1_0$48 ==.
                                    896 ;	src/modules/ttl.c:75: }
                           0000E8   897 	C$ttl.c$75$1_0$48 ==.
                           0000E8   898 	XG$SerialPrintln$0$0 ==.
      00019A 22               [24]  899 	ret
                                    900 ;------------------------------------------------------------
                                    901 ;Allocation info for local variables in function 'SerialRead'
                                    902 ;------------------------------------------------------------
                           0000E9   903 	G$SerialRead$0$0 ==.
                           0000E9   904 	C$ttl.c$78$1_0$49 ==.
                                    905 ;	src/modules/ttl.c:78: char SerialRead() {
                                    906 ;	-----------------------------------------
                                    907 ;	 function SerialRead
                                    908 ;	-----------------------------------------
      00019B                        909 _SerialRead:
                           0000E9   910 	C$ttl.c$80$1_0$49 ==.
                                    911 ;	src/modules/ttl.c:80: while (!RI) {
      00019B                        912 00101$:
                           0000E9   913 	C$ttl.c$84$1_0$49 ==.
                                    914 ;	src/modules/ttl.c:84: RI = 0;
                                    915 ;	assignBit
      00019B 10 98 02         [24]  916 	jbc	_RI,00114$
      00019E 80 FB            [24]  917 	sjmp	00101$
      0001A0                        918 00114$:
                           0000EE   919 	C$ttl.c$86$1_0$49 ==.
                                    920 ;	src/modules/ttl.c:86: return SBUF;
      0001A0 85 99 82         [24]  921 	mov	dpl,_SBUF
                           0000F1   922 	C$ttl.c$87$1_0$49 ==.
                                    923 ;	src/modules/ttl.c:87: }
                           0000F1   924 	C$ttl.c$87$1_0$49 ==.
                           0000F1   925 	XG$SerialRead$0$0 ==.
      0001A3 22               [24]  926 	ret
                                    927 ;------------------------------------------------------------
                                    928 ;Allocation info for local variables in function 'SerialAvailable'
                                    929 ;------------------------------------------------------------
                           0000F2   930 	G$SerialAvailable$0$0 ==.
                           0000F2   931 	C$ttl.c$90$1_0$51 ==.
                                    932 ;	src/modules/ttl.c:90: uint8_t SerialAvailable() {
                                    933 ;	-----------------------------------------
                                    934 ;	 function SerialAvailable
                                    935 ;	-----------------------------------------
      0001A4                        936 _SerialAvailable:
                           0000F2   937 	C$ttl.c$92$1_0$51 ==.
                                    938 ;	src/modules/ttl.c:92: return RI;
      0001A4 A2 98            [12]  939 	mov	c,_RI
      0001A6 E4               [12]  940 	clr	a
      0001A7 33               [12]  941 	rlc	a
      0001A8 F5 82            [12]  942 	mov	dpl,a
                           0000F8   943 	C$ttl.c$93$1_0$51 ==.
                                    944 ;	src/modules/ttl.c:93: }
                           0000F8   945 	C$ttl.c$93$1_0$51 ==.
                           0000F8   946 	XG$SerialAvailable$0$0 ==.
      0001AA 22               [24]  947 	ret
                                    948 ;------------------------------------------------------------
                                    949 ;Allocation info for local variables in function 'putchar'
                                    950 ;------------------------------------------------------------
                                    951 ;c                         Allocated to registers r7 
                                    952 ;------------------------------------------------------------
                           0000F9   953 	G$putchar$0$0 ==.
                           0000F9   954 	C$ttl.c$96$1_0$53 ==.
                                    955 ;	src/modules/ttl.c:96: uint8_t putchar(uint8_t c) {
                                    956 ;	-----------------------------------------
                                    957 ;	 function putchar
                                    958 ;	-----------------------------------------
      0001AB                        959 _putchar:
                           0000F9   960 	C$ttl.c$98$1_0$53 ==.
                                    961 ;	src/modules/ttl.c:98: SerialWrite(c);
      0001AB AF 82            [24]  962 	mov  r7,dpl
      0001AD C0 07            [24]  963 	push	ar7
      0001AF 12 01 52         [24]  964 	lcall	_SerialWrite
      0001B2 D0 07            [24]  965 	pop	ar7
                           000102   966 	C$ttl.c$99$1_0$53 ==.
                                    967 ;	src/modules/ttl.c:99: return c;
      0001B4 8F 82            [24]  968 	mov	dpl,r7
                           000104   969 	C$ttl.c$100$1_0$53 ==.
                                    970 ;	src/modules/ttl.c:100: }
                           000104   971 	C$ttl.c$100$1_0$53 ==.
                           000104   972 	XG$putchar$0$0 ==.
      0001B6 22               [24]  973 	ret
                                    974 ;------------------------------------------------------------
                                    975 ;Allocation info for local variables in function 'main'
                                    976 ;------------------------------------------------------------
                           000105   977 	G$main$0$0 ==.
                           000105   978 	C$51duino.h$19$1_0$62 ==.
                                    979 ;	inc/51duino.h:19: void main() {
                                    980 ;	-----------------------------------------
                                    981 ;	 function main
                                    982 ;	-----------------------------------------
      0001B7                        983 _main:
                           000105   984 	C$51duino.h$21$1_0$62 ==.
                                    985 ;	inc/51duino.h:21: millisInit();
      0001B7 12 00 B2         [24]  986 	lcall	_millisInit
                           000108   987 	C$51duino.h$23$1_0$62 ==.
                                    988 ;	inc/51duino.h:23: P0 = P1 = P2 = P3 = LOW;
      0001BA 75 B0 00         [24]  989 	mov	_P3,#0x00
      0001BD 75 A0 00         [24]  990 	mov	_P2,#0x00
      0001C0 75 90 00         [24]  991 	mov	_P1,#0x00
      0001C3 75 80 00         [24]  992 	mov	_P0,#0x00
                           000114   993 	C$51duino.h$25$1_0$62 ==.
                                    994 ;	inc/51duino.h:25: P30 = P31 = HIGH;
                                    995 ;	assignBit
      0001C6 D2 B1            [12]  996 	setb	_P31
                                    997 ;	assignBit
      0001C8 A2 B1            [12]  998 	mov	c,_P31
      0001CA 92 B0            [24]  999 	mov	_P30,c
                           00011A  1000 	C$51duino.h$27$1_0$62 ==.
                                   1001 ;	inc/51duino.h:27: setup();
      0001CC 12 01 D5         [24] 1002 	lcall	_setup
                           00011D  1003 	C$51duino.h$29$1_0$62 ==.
                                   1004 ;	inc/51duino.h:29: while (1) {
      0001CF                       1005 00102$:
                           00011D  1006 	C$51duino.h$30$2_0$63 ==.
                                   1007 ;	inc/51duino.h:30: loop();
      0001CF 12 01 EF         [24] 1008 	lcall	_loop
      0001D2 80 FB            [24] 1009 	sjmp	00102$
                           000122  1010 	C$51duino.h$32$1_0$62 ==.
                                   1011 ;	inc/51duino.h:32: }
                           000122  1012 	C$51duino.h$32$1_0$62 ==.
                           000122  1013 	XG$main$0$0 ==.
      0001D4 22               [24] 1014 	ret
                                   1015 ;------------------------------------------------------------
                                   1016 ;Allocation info for local variables in function 'setup'
                                   1017 ;------------------------------------------------------------
                           000123  1018 	G$setup$0$0 ==.
                           000123  1019 	C$main.c$8$1_0$64 ==.
                                   1020 ;	./src/main.c:8: void setup() {
                                   1021 ;	-----------------------------------------
                                   1022 ;	 function setup
                                   1023 ;	-----------------------------------------
      0001D5                       1024 _setup:
                           000123  1025 	C$main.c$9$1_0$64 ==.
                                   1026 ;	./src/main.c:9: Serial.begin(9600);
      0001D5 AE 0C            [24] 1027 	mov	r6,(_Serial + 0)
      0001D7 AF 0D            [24] 1028 	mov	r7,(_Serial + 1)
      0001D9 C0 07            [24] 1029 	push	ar7
      0001DB C0 06            [24] 1030 	push	ar6
      0001DD 12 01 E2         [24] 1031 	lcall	00103$
      0001E0 80 08            [24] 1032 	sjmp	00104$
      0001E2                       1033 00103$:
      0001E2 C0 06            [24] 1034 	push	ar6
      0001E4 C0 07            [24] 1035 	push	ar7
      0001E6 90 25 80         [24] 1036 	mov	dptr,#0x2580
      0001E9 22               [24] 1037 	ret
      0001EA                       1038 00104$:
      0001EA D0 06            [24] 1039 	pop	ar6
      0001EC D0 07            [24] 1040 	pop	ar7
                           00013C  1041 	C$main.c$10$1_0$64 ==.
                                   1042 ;	./src/main.c:10: }
                           00013C  1043 	C$main.c$10$1_0$64 ==.
                           00013C  1044 	XG$setup$0$0 ==.
      0001EE 22               [24] 1045 	ret
                                   1046 ;------------------------------------------------------------
                                   1047 ;Allocation info for local variables in function 'loop'
                                   1048 ;------------------------------------------------------------
                                   1049 ;i                         Allocated to registers r7 
                                   1050 ;------------------------------------------------------------
                           00013D  1051 	G$loop$0$0 ==.
                           00013D  1052 	C$main.c$12$1_0$65 ==.
                                   1053 ;	./src/main.c:12: void loop() {
                                   1054 ;	-----------------------------------------
                                   1055 ;	 function loop
                                   1056 ;	-----------------------------------------
      0001EF                       1057 _loop:
                           00013D  1058 	C$main.c$13$1_0$65 ==.
                                   1059 ;	./src/main.c:13: Serial.println("Hello World!");
      0001EF AE 16            [24] 1060 	mov	r6,((_Serial + 0x000a) + 0)
      0001F1 AF 17            [24] 1061 	mov	r7,((_Serial + 0x000a) + 1)
      0001F3 C0 07            [24] 1062 	push	ar7
      0001F5 C0 06            [24] 1063 	push	ar6
      0001F7 12 01 FC         [24] 1064 	lcall	00116$
      0001FA 80 0B            [24] 1065 	sjmp	00117$
      0001FC                       1066 00116$:
      0001FC C0 06            [24] 1067 	push	ar6
      0001FE C0 07            [24] 1068 	push	ar7
      000200 90 0D E7         [24] 1069 	mov	dptr,#___str_1
      000203 75 F0 80         [24] 1070 	mov	b,#0x80
      000206 22               [24] 1071 	ret
      000207                       1072 00117$:
      000207 D0 06            [24] 1073 	pop	ar6
      000209 D0 07            [24] 1074 	pop	ar7
                           000159  1075 	C$main.c$20$3_1$68 ==.
                                   1076 ;	./src/main.c:20: for (uint8_t i = 0; i < sizeof(lights) / sizeof(lights[0]); i++) {
      00020B 7F 00            [12] 1077 	mov	r7,#0x00
      00020D                       1078 00103$:
      00020D BF 1E 00         [24] 1079 	cjne	r7,#0x1e,00118$
      000210                       1080 00118$:
      000210 50 45            [24] 1081 	jnc	00105$
                           000160  1082 	C$main.c$21$3_1$68 ==.
                                   1083 ;	./src/main.c:21: delay(50);
      000212 90 00 32         [24] 1084 	mov	dptr,#0x0032
      000215 C0 07            [24] 1085 	push	ar7
      000217 12 05 F0         [24] 1086 	lcall	_delay
                           000168  1087 	C$main.c$22$3_1$68 ==.
                                   1088 ;	./src/main.c:22: digitalWrite(latch, LOW);
      00021A 75 5C 00         [24] 1089 	mov	_digitalWrite_PARM_2,#0x00
      00021D 90 0D C0         [24] 1090 	mov	dptr,#_PIN_P16
      000220 75 F0 80         [24] 1091 	mov	b,#0x80
      000223 12 02 DC         [24] 1092 	lcall	_digitalWrite
      000226 D0 07            [24] 1093 	pop	ar7
                           000176  1094 	C$main.c$23$3_1$68 ==.
                                   1095 ;	./src/main.c:23: shiftOut(dat, clock, MSBFIRST, lights[i]);
      000228 75 27 C2         [24] 1096 	mov	_shiftOut_PARM_2,#_PIN_P17
      00022B 75 28 0D         [24] 1097 	mov	(_shiftOut_PARM_2 + 1),#(_PIN_P17 >> 8)
      00022E 75 29 80         [24] 1098 	mov	(_shiftOut_PARM_2 + 2),#0x80
      000231 EF               [12] 1099 	mov	a,r7
      000232 90 02 58         [24] 1100 	mov	dptr,#_loop_lights_65537_66
      000235 93               [24] 1101 	movc	a,@a+dptr
      000236 F5 2B            [12] 1102 	mov	_shiftOut_PARM_4,a
      000238 75 2A 01         [24] 1103 	mov	_shiftOut_PARM_3,#0x01
      00023B 90 0D BE         [24] 1104 	mov	dptr,#_PIN_P15
      00023E 75 F0 80         [24] 1105 	mov	b,#0x80
      000241 C0 07            [24] 1106 	push	ar7
      000243 12 04 CC         [24] 1107 	lcall	_shiftOut
                           000194  1108 	C$main.c$24$3_1$68 ==.
                                   1109 ;	./src/main.c:24: digitalWrite(latch, HIGH);
      000246 75 5C 01         [24] 1110 	mov	_digitalWrite_PARM_2,#0x01
      000249 90 0D C0         [24] 1111 	mov	dptr,#_PIN_P16
      00024C 75 F0 80         [24] 1112 	mov	b,#0x80
      00024F 12 02 DC         [24] 1113 	lcall	_digitalWrite
      000252 D0 07            [24] 1114 	pop	ar7
                           0001A2  1115 	C$main.c$20$2_1$67 ==.
                                   1116 ;	./src/main.c:20: for (uint8_t i = 0; i < sizeof(lights) / sizeof(lights[0]); i++) {
      000254 0F               [12] 1117 	inc	r7
      000255 80 B6            [24] 1118 	sjmp	00103$
      000257                       1119 00105$:
                           0001A5  1120 	C$main.c$26$2_1$65 ==.
                                   1121 ;	./src/main.c:26: }
                           0001A5  1122 	C$main.c$26$2_1$65 ==.
                           0001A5  1123 	XG$loop$0$0 ==.
      000257 22               [24] 1124 	ret
                                   1125 	.area CSEG    (CODE)
                                   1126 	.area CONST   (CODE)
                           000000  1127 G$PIN_P00$0_0$0 == .
      000DA4                       1128 _PIN_P00:
      000DA4 00                    1129 	.db #0x00	; 0
      000DA5 00                    1130 	.db #0x00	; 0
                           000002  1131 G$PIN_P01$0_0$0 == .
      000DA6                       1132 _PIN_P01:
      000DA6 00                    1133 	.db #0x00	; 0
      000DA7 01                    1134 	.db #0x01	; 1
                           000004  1135 G$PIN_P02$0_0$0 == .
      000DA8                       1136 _PIN_P02:
      000DA8 00                    1137 	.db #0x00	; 0
      000DA9 02                    1138 	.db #0x02	; 2
                           000006  1139 G$PIN_P03$0_0$0 == .
      000DAA                       1140 _PIN_P03:
      000DAA 00                    1141 	.db #0x00	; 0
      000DAB 03                    1142 	.db #0x03	; 3
                           000008  1143 G$PIN_P04$0_0$0 == .
      000DAC                       1144 _PIN_P04:
      000DAC 00                    1145 	.db #0x00	; 0
      000DAD 04                    1146 	.db #0x04	; 4
                           00000A  1147 G$PIN_P05$0_0$0 == .
      000DAE                       1148 _PIN_P05:
      000DAE 00                    1149 	.db #0x00	; 0
      000DAF 05                    1150 	.db #0x05	; 5
                           00000C  1151 G$PIN_P06$0_0$0 == .
      000DB0                       1152 _PIN_P06:
      000DB0 00                    1153 	.db #0x00	; 0
      000DB1 06                    1154 	.db #0x06	; 6
                           00000E  1155 G$PIN_P07$0_0$0 == .
      000DB2                       1156 _PIN_P07:
      000DB2 00                    1157 	.db #0x00	; 0
      000DB3 07                    1158 	.db #0x07	; 7
                           000010  1159 G$PIN_P10$0_0$0 == .
      000DB4                       1160 _PIN_P10:
      000DB4 01                    1161 	.db #0x01	; 1
      000DB5 00                    1162 	.db #0x00	; 0
                           000012  1163 G$PIN_P11$0_0$0 == .
      000DB6                       1164 _PIN_P11:
      000DB6 01                    1165 	.db #0x01	; 1
      000DB7 01                    1166 	.db #0x01	; 1
                           000014  1167 G$PIN_P12$0_0$0 == .
      000DB8                       1168 _PIN_P12:
      000DB8 01                    1169 	.db #0x01	; 1
      000DB9 02                    1170 	.db #0x02	; 2
                           000016  1171 G$PIN_P13$0_0$0 == .
      000DBA                       1172 _PIN_P13:
      000DBA 01                    1173 	.db #0x01	; 1
      000DBB 03                    1174 	.db #0x03	; 3
                           000018  1175 G$PIN_P14$0_0$0 == .
      000DBC                       1176 _PIN_P14:
      000DBC 01                    1177 	.db #0x01	; 1
      000DBD 04                    1178 	.db #0x04	; 4
                           00001A  1179 G$PIN_P15$0_0$0 == .
      000DBE                       1180 _PIN_P15:
      000DBE 01                    1181 	.db #0x01	; 1
      000DBF 05                    1182 	.db #0x05	; 5
                           00001C  1183 G$PIN_P16$0_0$0 == .
      000DC0                       1184 _PIN_P16:
      000DC0 01                    1185 	.db #0x01	; 1
      000DC1 06                    1186 	.db #0x06	; 6
                           00001E  1187 G$PIN_P17$0_0$0 == .
      000DC2                       1188 _PIN_P17:
      000DC2 01                    1189 	.db #0x01	; 1
      000DC3 07                    1190 	.db #0x07	; 7
                           000020  1191 G$PIN_P20$0_0$0 == .
      000DC4                       1192 _PIN_P20:
      000DC4 02                    1193 	.db #0x02	; 2
      000DC5 00                    1194 	.db #0x00	; 0
                           000022  1195 G$PIN_P21$0_0$0 == .
      000DC6                       1196 _PIN_P21:
      000DC6 02                    1197 	.db #0x02	; 2
      000DC7 01                    1198 	.db #0x01	; 1
                           000024  1199 G$PIN_P22$0_0$0 == .
      000DC8                       1200 _PIN_P22:
      000DC8 02                    1201 	.db #0x02	; 2
      000DC9 02                    1202 	.db #0x02	; 2
                           000026  1203 G$PIN_P23$0_0$0 == .
      000DCA                       1204 _PIN_P23:
      000DCA 02                    1205 	.db #0x02	; 2
      000DCB 03                    1206 	.db #0x03	; 3
                           000028  1207 G$PIN_P24$0_0$0 == .
      000DCC                       1208 _PIN_P24:
      000DCC 02                    1209 	.db #0x02	; 2
      000DCD 04                    1210 	.db #0x04	; 4
                           00002A  1211 G$PIN_P25$0_0$0 == .
      000DCE                       1212 _PIN_P25:
      000DCE 02                    1213 	.db #0x02	; 2
      000DCF 05                    1214 	.db #0x05	; 5
                           00002C  1215 G$PIN_P26$0_0$0 == .
      000DD0                       1216 _PIN_P26:
      000DD0 02                    1217 	.db #0x02	; 2
      000DD1 06                    1218 	.db #0x06	; 6
                           00002E  1219 G$PIN_P27$0_0$0 == .
      000DD2                       1220 _PIN_P27:
      000DD2 02                    1221 	.db #0x02	; 2
      000DD3 07                    1222 	.db #0x07	; 7
                           000030  1223 G$PIN_P30$0_0$0 == .
      000DD4                       1224 _PIN_P30:
      000DD4 03                    1225 	.db #0x03	; 3
      000DD5 00                    1226 	.db #0x00	; 0
                           000032  1227 G$PIN_P31$0_0$0 == .
      000DD6                       1228 _PIN_P31:
      000DD6 03                    1229 	.db #0x03	; 3
      000DD7 01                    1230 	.db #0x01	; 1
                           000034  1231 G$PIN_P32$0_0$0 == .
      000DD8                       1232 _PIN_P32:
      000DD8 03                    1233 	.db #0x03	; 3
      000DD9 02                    1234 	.db #0x02	; 2
                           000036  1235 G$PIN_P33$0_0$0 == .
      000DDA                       1236 _PIN_P33:
      000DDA 03                    1237 	.db #0x03	; 3
      000DDB 03                    1238 	.db #0x03	; 3
                           000038  1239 G$PIN_P34$0_0$0 == .
      000DDC                       1240 _PIN_P34:
      000DDC 03                    1241 	.db #0x03	; 3
      000DDD 04                    1242 	.db #0x04	; 4
                           00003A  1243 G$PIN_P35$0_0$0 == .
      000DDE                       1244 _PIN_P35:
      000DDE 03                    1245 	.db #0x03	; 3
      000DDF 05                    1246 	.db #0x05	; 5
                           00003C  1247 G$PIN_P36$0_0$0 == .
      000DE0                       1248 _PIN_P36:
      000DE0 03                    1249 	.db #0x03	; 3
      000DE1 06                    1250 	.db #0x06	; 6
                           00003E  1251 G$PIN_P37$0_0$0 == .
      000DE2                       1252 _PIN_P37:
      000DE2 03                    1253 	.db #0x03	; 3
      000DE3 07                    1254 	.db #0x07	; 7
                           000040  1255 Fmain$__str_0$0_0$0 == .
                                   1256 	.area CONST   (CODE)
      000DE4                       1257 ___str_0:
      000DE4 0D                    1258 	.db 0x0d
      000DE5 0A                    1259 	.db 0x0a
      000DE6 00                    1260 	.db 0x00
                                   1261 	.area CSEG    (CODE)
                           0001A6  1262 Lmain.loop$lights$1_1$66 == .
      000258                       1263 _loop_lights_65537_66:
      000258 00                    1264 	.db #0x00	; 0
      000259 01                    1265 	.db #0x01	; 1
      00025A 03                    1266 	.db #0x03	; 3
      00025B 07                    1267 	.db #0x07	; 7
      00025C 0F                    1268 	.db #0x0f	; 15
      00025D 1F                    1269 	.db #0x1f	; 31
      00025E 3F                    1270 	.db #0x3f	; 63
      00025F 7F                    1271 	.db #0x7f	; 127
      000260 FF                    1272 	.db #0xff	; 255
      000261 7F                    1273 	.db #0x7f	; 127
      000262 3F                    1274 	.db #0x3f	; 63
      000263 1F                    1275 	.db #0x1f	; 31
      000264 0F                    1276 	.db #0x0f	; 15
      000265 07                    1277 	.db #0x07	; 7
      000266 03                    1278 	.db #0x03	; 3
      000267 01                    1279 	.db #0x01	; 1
      000268 80                    1280 	.db #0x80	; 128
      000269 C0                    1281 	.db #0xc0	; 192
      00026A E0                    1282 	.db #0xe0	; 224
      00026B F0                    1283 	.db #0xf0	; 240
      00026C F8                    1284 	.db #0xf8	; 248
      00026D FC                    1285 	.db #0xfc	; 252
      00026E FE                    1286 	.db #0xfe	; 254
      00026F FF                    1287 	.db #0xff	; 255
      000270 FE                    1288 	.db #0xfe	; 254
      000271 FC                    1289 	.db #0xfc	; 252
      000272 F8                    1290 	.db #0xf8	; 248
      000273 F0                    1291 	.db #0xf0	; 240
      000274 E0                    1292 	.db #0xe0	; 224
      000275 C0                    1293 	.db #0xc0	; 192
                           0001C4  1294 Fmain$__str_1$0_0$0 == .
                                   1295 	.area CONST   (CODE)
      000DE7                       1296 ___str_1:
      000DE7 48 65 6C 6C 6F 20 57  1297 	.ascii "Hello World!"
             6F 72 6C 64 21
      000DF3 00                    1298 	.db 0x00
                                   1299 	.area CSEG    (CODE)
                                   1300 	.area XINIT   (CODE)
                                   1301 	.area CABS    (ABS,CODE)
