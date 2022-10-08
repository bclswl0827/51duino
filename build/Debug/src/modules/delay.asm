;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 4.1.0 #12072 (Linux)
;--------------------------------------------------------
	.module delay
	.optsdcc -mmcs51 --model-small
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _CP_RL2
	.globl _C_T2
	.globl _TR2
	.globl _EXEN2
	.globl _TCLK
	.globl _RCLK
	.globl _EXF2
	.globl _TF2
	.globl _T2
	.globl _T2EX
	.globl _RI
	.globl _TI
	.globl _RB8
	.globl _TB8
	.globl _REN
	.globl _SM2
	.globl _SM1
	.globl _SM0
	.globl _RXD
	.globl _TXD
	.globl _INT0
	.globl _INT1
	.globl _T0
	.globl _T1
	.globl _WR
	.globl _RD
	.globl _PX0
	.globl _PT0
	.globl _PX1
	.globl _PT1
	.globl _PS
	.globl _PT2
	.globl _EX0
	.globl _ET0
	.globl _EX1
	.globl _ET1
	.globl _ES
	.globl _ET2
	.globl _EA
	.globl _IT0
	.globl _IE0
	.globl _IT1
	.globl _IE1
	.globl _TR0
	.globl _TF0
	.globl _TR1
	.globl _TF1
	.globl _P
	.globl _OV
	.globl _RS0
	.globl _RS1
	.globl _F0
	.globl _AC
	.globl _CY
	.globl _P37
	.globl _P36
	.globl _P35
	.globl _P34
	.globl _P33
	.globl _P32
	.globl _P31
	.globl _P30
	.globl _P27
	.globl _P26
	.globl _P25
	.globl _P24
	.globl _P23
	.globl _P22
	.globl _P21
	.globl _P20
	.globl _P17
	.globl _P16
	.globl _P15
	.globl _P14
	.globl _P13
	.globl _P12
	.globl _P11
	.globl _P10
	.globl _P07
	.globl _P06
	.globl _P05
	.globl _P04
	.globl _P03
	.globl _P02
	.globl _P01
	.globl _P00
	.globl _TH2
	.globl _TL2
	.globl _RCAP2H
	.globl _RCAP2L
	.globl _T2CON
	.globl _SBUF
	.globl _SCON
	.globl _IP
	.globl _IE
	.globl _TH1
	.globl _TH0
	.globl _TL1
	.globl _TL0
	.globl _TMOD
	.globl _TCON
	.globl _PCON
	.globl _DPH
	.globl _DPL
	.globl _SP
	.globl _B
	.globl _ACC
	.globl _PSW
	.globl _P3
	.globl _P2
	.globl _P1
	.globl _P0
	.globl _delay
	.globl _delayMicroseconds
;--------------------------------------------------------
; special function registers
;--------------------------------------------------------
	.area RSEG    (ABS,DATA)
	.org 0x0000
G$P0$0_0$0 == 0x0080
_P0	=	0x0080
G$P1$0_0$0 == 0x0090
_P1	=	0x0090
G$P2$0_0$0 == 0x00a0
_P2	=	0x00a0
G$P3$0_0$0 == 0x00b0
_P3	=	0x00b0
G$PSW$0_0$0 == 0x00d0
_PSW	=	0x00d0
G$ACC$0_0$0 == 0x00e0
_ACC	=	0x00e0
G$B$0_0$0 == 0x00f0
_B	=	0x00f0
G$SP$0_0$0 == 0x0081
_SP	=	0x0081
G$DPL$0_0$0 == 0x0082
_DPL	=	0x0082
G$DPH$0_0$0 == 0x0083
_DPH	=	0x0083
G$PCON$0_0$0 == 0x0087
_PCON	=	0x0087
G$TCON$0_0$0 == 0x0088
_TCON	=	0x0088
G$TMOD$0_0$0 == 0x0089
_TMOD	=	0x0089
G$TL0$0_0$0 == 0x008a
_TL0	=	0x008a
G$TL1$0_0$0 == 0x008b
_TL1	=	0x008b
G$TH0$0_0$0 == 0x008c
_TH0	=	0x008c
G$TH1$0_0$0 == 0x008d
_TH1	=	0x008d
G$IE$0_0$0 == 0x00a8
_IE	=	0x00a8
G$IP$0_0$0 == 0x00b8
_IP	=	0x00b8
G$SCON$0_0$0 == 0x0098
_SCON	=	0x0098
G$SBUF$0_0$0 == 0x0099
_SBUF	=	0x0099
G$T2CON$0_0$0 == 0x00c8
_T2CON	=	0x00c8
G$RCAP2L$0_0$0 == 0x00ca
_RCAP2L	=	0x00ca
G$RCAP2H$0_0$0 == 0x00cb
_RCAP2H	=	0x00cb
G$TL2$0_0$0 == 0x00cc
_TL2	=	0x00cc
G$TH2$0_0$0 == 0x00cd
_TH2	=	0x00cd
;--------------------------------------------------------
; special function bits
;--------------------------------------------------------
	.area RSEG    (ABS,DATA)
	.org 0x0000
G$P00$0_0$0 == 0x0080
_P00	=	0x0080
G$P01$0_0$0 == 0x0081
_P01	=	0x0081
G$P02$0_0$0 == 0x0082
_P02	=	0x0082
G$P03$0_0$0 == 0x0083
_P03	=	0x0083
G$P04$0_0$0 == 0x0084
_P04	=	0x0084
G$P05$0_0$0 == 0x0085
_P05	=	0x0085
G$P06$0_0$0 == 0x0086
_P06	=	0x0086
G$P07$0_0$0 == 0x0087
_P07	=	0x0087
G$P10$0_0$0 == 0x0090
_P10	=	0x0090
G$P11$0_0$0 == 0x0091
_P11	=	0x0091
G$P12$0_0$0 == 0x0092
_P12	=	0x0092
G$P13$0_0$0 == 0x0093
_P13	=	0x0093
G$P14$0_0$0 == 0x0094
_P14	=	0x0094
G$P15$0_0$0 == 0x0095
_P15	=	0x0095
G$P16$0_0$0 == 0x0096
_P16	=	0x0096
G$P17$0_0$0 == 0x0097
_P17	=	0x0097
G$P20$0_0$0 == 0x00a0
_P20	=	0x00a0
G$P21$0_0$0 == 0x00a1
_P21	=	0x00a1
G$P22$0_0$0 == 0x00a2
_P22	=	0x00a2
G$P23$0_0$0 == 0x00a3
_P23	=	0x00a3
G$P24$0_0$0 == 0x00a4
_P24	=	0x00a4
G$P25$0_0$0 == 0x00a5
_P25	=	0x00a5
G$P26$0_0$0 == 0x00a6
_P26	=	0x00a6
G$P27$0_0$0 == 0x00a7
_P27	=	0x00a7
G$P30$0_0$0 == 0x00b0
_P30	=	0x00b0
G$P31$0_0$0 == 0x00b1
_P31	=	0x00b1
G$P32$0_0$0 == 0x00b2
_P32	=	0x00b2
G$P33$0_0$0 == 0x00b3
_P33	=	0x00b3
G$P34$0_0$0 == 0x00b4
_P34	=	0x00b4
G$P35$0_0$0 == 0x00b5
_P35	=	0x00b5
G$P36$0_0$0 == 0x00b6
_P36	=	0x00b6
G$P37$0_0$0 == 0x00b7
_P37	=	0x00b7
G$CY$0_0$0 == 0x00d7
_CY	=	0x00d7
G$AC$0_0$0 == 0x00d6
_AC	=	0x00d6
G$F0$0_0$0 == 0x00d5
_F0	=	0x00d5
G$RS1$0_0$0 == 0x00d4
_RS1	=	0x00d4
G$RS0$0_0$0 == 0x00d3
_RS0	=	0x00d3
G$OV$0_0$0 == 0x00d2
_OV	=	0x00d2
G$P$0_0$0 == 0x00d0
_P	=	0x00d0
G$TF1$0_0$0 == 0x008f
_TF1	=	0x008f
G$TR1$0_0$0 == 0x008e
_TR1	=	0x008e
G$TF0$0_0$0 == 0x008d
_TF0	=	0x008d
G$TR0$0_0$0 == 0x008c
_TR0	=	0x008c
G$IE1$0_0$0 == 0x008b
_IE1	=	0x008b
G$IT1$0_0$0 == 0x008a
_IT1	=	0x008a
G$IE0$0_0$0 == 0x0089
_IE0	=	0x0089
G$IT0$0_0$0 == 0x0088
_IT0	=	0x0088
G$EA$0_0$0 == 0x00af
_EA	=	0x00af
G$ET2$0_0$0 == 0x00ad
_ET2	=	0x00ad
G$ES$0_0$0 == 0x00ac
_ES	=	0x00ac
G$ET1$0_0$0 == 0x00ab
_ET1	=	0x00ab
G$EX1$0_0$0 == 0x00aa
_EX1	=	0x00aa
G$ET0$0_0$0 == 0x00a9
_ET0	=	0x00a9
G$EX0$0_0$0 == 0x00a8
_EX0	=	0x00a8
G$PT2$0_0$0 == 0x00bd
_PT2	=	0x00bd
G$PS$0_0$0 == 0x00bc
_PS	=	0x00bc
G$PT1$0_0$0 == 0x00bb
_PT1	=	0x00bb
G$PX1$0_0$0 == 0x00ba
_PX1	=	0x00ba
G$PT0$0_0$0 == 0x00b9
_PT0	=	0x00b9
G$PX0$0_0$0 == 0x00b8
_PX0	=	0x00b8
G$RD$0_0$0 == 0x00b7
_RD	=	0x00b7
G$WR$0_0$0 == 0x00b6
_WR	=	0x00b6
G$T1$0_0$0 == 0x00b5
_T1	=	0x00b5
G$T0$0_0$0 == 0x00b4
_T0	=	0x00b4
G$INT1$0_0$0 == 0x00b3
_INT1	=	0x00b3
G$INT0$0_0$0 == 0x00b2
_INT0	=	0x00b2
G$TXD$0_0$0 == 0x00b1
_TXD	=	0x00b1
G$RXD$0_0$0 == 0x00b0
_RXD	=	0x00b0
G$SM0$0_0$0 == 0x009f
_SM0	=	0x009f
G$SM1$0_0$0 == 0x009e
_SM1	=	0x009e
G$SM2$0_0$0 == 0x009d
_SM2	=	0x009d
G$REN$0_0$0 == 0x009c
_REN	=	0x009c
G$TB8$0_0$0 == 0x009b
_TB8	=	0x009b
G$RB8$0_0$0 == 0x009a
_RB8	=	0x009a
G$TI$0_0$0 == 0x0099
_TI	=	0x0099
G$RI$0_0$0 == 0x0098
_RI	=	0x0098
G$T2EX$0_0$0 == 0x0091
_T2EX	=	0x0091
G$T2$0_0$0 == 0x0090
_T2	=	0x0090
G$TF2$0_0$0 == 0x00cf
_TF2	=	0x00cf
G$EXF2$0_0$0 == 0x00ce
_EXF2	=	0x00ce
G$RCLK$0_0$0 == 0x00cd
_RCLK	=	0x00cd
G$TCLK$0_0$0 == 0x00cc
_TCLK	=	0x00cc
G$EXEN2$0_0$0 == 0x00cb
_EXEN2	=	0x00cb
G$TR2$0_0$0 == 0x00ca
_TR2	=	0x00ca
G$C_T2$0_0$0 == 0x00c9
_C_T2	=	0x00c9
G$CP_RL2$0_0$0 == 0x00c8
_CP_RL2	=	0x00c8
;--------------------------------------------------------
; overlayable register banks
;--------------------------------------------------------
	.area REG_BANK_0	(REL,OVR,DATA)
	.ds 8
;--------------------------------------------------------
; internal ram data
;--------------------------------------------------------
	.area DSEG    (DATA)
;--------------------------------------------------------
; overlayable items in internal ram 
;--------------------------------------------------------
	.area	OSEG    (OVR,DATA)
	.area	OSEG    (OVR,DATA)
;--------------------------------------------------------
; indirectly addressable internal ram data
;--------------------------------------------------------
	.area ISEG    (DATA)
;--------------------------------------------------------
; absolute internal ram data
;--------------------------------------------------------
	.area IABS    (ABS,DATA)
	.area IABS    (ABS,DATA)
;--------------------------------------------------------
; bit data
;--------------------------------------------------------
	.area BSEG    (BIT)
;--------------------------------------------------------
; paged external ram data
;--------------------------------------------------------
	.area PSEG    (PAG,XDATA)
;--------------------------------------------------------
; external ram data
;--------------------------------------------------------
	.area XSEG    (XDATA)
;--------------------------------------------------------
; absolute external ram data
;--------------------------------------------------------
	.area XABS    (ABS,XDATA)
;--------------------------------------------------------
; external initialized ram data
;--------------------------------------------------------
	.area XISEG   (XDATA)
	.area HOME    (CODE)
	.area GSINIT0 (CODE)
	.area GSINIT1 (CODE)
	.area GSINIT2 (CODE)
	.area GSINIT3 (CODE)
	.area GSINIT4 (CODE)
	.area GSINIT5 (CODE)
	.area GSINIT  (CODE)
	.area GSFINAL (CODE)
	.area CSEG    (CODE)
;--------------------------------------------------------
; global & static initialisations
;--------------------------------------------------------
	.area HOME    (CODE)
	.area GSINIT  (CODE)
	.area GSFINAL (CODE)
	.area GSINIT  (CODE)
;--------------------------------------------------------
; Home
;--------------------------------------------------------
	.area HOME    (CODE)
	.area HOME    (CODE)
;--------------------------------------------------------
; code
;--------------------------------------------------------
	.area CSEG    (CODE)
;------------------------------------------------------------
;Allocation info for local variables in function 'delay'
;------------------------------------------------------------
;t                         Allocated to registers 
;i                         Allocated to registers r6 r7 
;j                         Allocated to registers r4 r5 
;------------------------------------------------------------
	G$delay$0$0 ==.
	C$delay.c$4$0_0$5 ==.
;	./src/modules/delay.c:4: void delay(uint16_t t) {
;	-----------------------------------------
;	 function delay
;	-----------------------------------------
_delay:
	ar7 = 0x07
	ar6 = 0x06
	ar5 = 0x05
	ar4 = 0x04
	ar3 = 0x03
	ar2 = 0x02
	ar1 = 0x01
	ar0 = 0x00
	mov	r6,dpl
	mov	r7,dph
	C$delay.c$5$2_0$5 ==.
;	./src/modules/delay.c:5: for (uint16_t i = t; i > 0; i--) {
00107$:
	mov	a,r6
	orl	a,r7
	jz	00109$
	C$delay.c$6$2_0$5 ==.
;	./src/modules/delay.c:6: for (uint16_t j = 118; j > 0; j--) {
	mov	r4,#0x76
	mov	r5,#0x00
00104$:
	mov	a,r4
	orl	a,r5
	jz	00108$
	dec	r4
	cjne	r4,#0xff,00135$
	dec	r5
00135$:
	sjmp	00104$
00108$:
	C$delay.c$5$2_0$5 ==.
;	./src/modules/delay.c:5: for (uint16_t i = t; i > 0; i--) {
	dec	r6
	cjne	r6,#0xff,00136$
	dec	r7
00136$:
	sjmp	00107$
00109$:
	C$delay.c$10$2_0$5 ==.
;	./src/modules/delay.c:10: }
	C$delay.c$10$2_0$5 ==.
	XG$delay$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'delayMicroseconds'
;------------------------------------------------------------
;t                         Allocated to registers 
;------------------------------------------------------------
	G$delayMicroseconds$0$0 ==.
	C$delay.c$13$2_0$10 ==.
;	./src/modules/delay.c:13: void delayMicroseconds(uint16_t t) {
;	-----------------------------------------
;	 function delayMicroseconds
;	-----------------------------------------
_delayMicroseconds:
	mov	r6,dpl
	mov	r7,dph
	C$delay.c$15$1_0$10 ==.
;	./src/modules/delay.c:15: while (t--) {
00101$:
	mov	ar4,r6
	mov	ar5,r7
	dec	r6
	cjne	r6,#0xff,00111$
	dec	r7
00111$:
	mov	a,r4
	orl	a,r5
	jnz	00101$
	C$delay.c$18$1_0$10 ==.
;	./src/modules/delay.c:18: }
	C$delay.c$18$1_0$10 ==.
	XG$delayMicroseconds$0$0 ==.
	ret
	.area CSEG    (CODE)
	.area CONST   (CODE)
	.area XINIT   (CODE)
	.area CABS    (ABS,CODE)
