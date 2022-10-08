;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 4.1.0 #12072 (Linux)
;--------------------------------------------------------
	.module digi
	.optsdcc -mmcs51 --model-small
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _digitalWrite_PARM_2
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
	.globl _shiftOut_PARM_4
	.globl _shiftOut_PARM_3
	.globl _shiftOut_PARM_2
	.globl _shiftIn_PARM_3
	.globl _shiftIn_PARM_2
	.globl _pinMode
	.globl _digitalWrite
	.globl _digitalRead
	.globl _shiftIn
	.globl _shiftOut
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
Ldigi.digitalWrite$value$1_0$13==.
_digitalWrite_value_65536_13:
	.ds 1
Ldigi.digitalRead$value$1_0$25==.
_digitalRead_value_65536_25:
	.ds 1
Ldigi.shiftIn$clockPin$1_0$30==.
_shiftIn_PARM_2:
	.ds 3
Ldigi.shiftIn$bitOrder$1_0$30==.
_shiftIn_PARM_3:
	.ds 1
Ldigi.shiftOut$clockPin$1_0$36==.
_shiftOut_PARM_2:
	.ds 3
Ldigi.shiftOut$bitOrder$1_0$36==.
_shiftOut_PARM_3:
	.ds 1
Ldigi.shiftOut$val$1_0$36==.
_shiftOut_PARM_4:
	.ds 1
;--------------------------------------------------------
; overlayable items in internal ram 
;--------------------------------------------------------
	.area	OSEG    (OVR,DATA)
Ldigi.digitalWrite$level$1_0$12==.
_digitalWrite_PARM_2:
	.ds 1
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
Ldigi.shiftOut$sloc0$0_1$0==.
_shiftOut_sloc0_1_0:
	.ds 1
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
;Allocation info for local variables in function 'pinMode'
;------------------------------------------------------------
	G$pinMode$0$0 ==.
	C$digi.c$4$0_0$11 ==.
;	./src/modules/digi.c:4: void pinMode(void) {
;	-----------------------------------------
;	 function pinMode
;	-----------------------------------------
_pinMode:
	ar7 = 0x07
	ar6 = 0x06
	ar5 = 0x05
	ar4 = 0x04
	ar3 = 0x03
	ar2 = 0x02
	ar1 = 0x01
	ar0 = 0x00
	C$digi.c$7$0_0$11 ==.
;	./src/modules/digi.c:7: }
	C$digi.c$7$0_0$11 ==.
	XG$pinMode$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'digitalWrite'
;------------------------------------------------------------
;value                     Allocated with name '_digitalWrite_value_65536_13'
;level                     Allocated with name '_digitalWrite_PARM_2'
;_pin                      Allocated to registers r5 r6 r7 
;------------------------------------------------------------
	G$digitalWrite$0$0 ==.
	C$digi.c$10$0_0$13 ==.
;	./src/modules/digi.c:10: void digitalWrite(uint8_t* _pin, uint8_t level) {
;	-----------------------------------------
;	 function digitalWrite
;	-----------------------------------------
_digitalWrite:
	C$digi.c$17$1_0$13 ==.
;	./src/modules/digi.c:17: MACRO_LOOP(PORTS)
	mov	r5,dpl
	mov	r6,dph
	mov	r7,b
	lcall	__gptrget
	jnz	00102$
	mov	_digitalWrite_value_65536_13,_P0
00102$:
	mov	dpl,r5
	mov	dph,r6
	mov	b,r7
	lcall	__gptrget
	mov	r4,a
	cjne	r4,#0x01,00104$
	mov	_digitalWrite_value_65536_13,_P1
00104$:
	mov	dpl,r5
	mov	dph,r6
	mov	b,r7
	lcall	__gptrget
	mov	r4,a
	cjne	r4,#0x02,00106$
	mov	_digitalWrite_value_65536_13,_P2
00106$:
	mov	dpl,r5
	mov	dph,r6
	mov	b,r7
	lcall	__gptrget
	mov	r4,a
	cjne	r4,#0x03,00108$
	mov	_digitalWrite_value_65536_13,_P3
00108$:
	C$digi.c$19$1_0$13 ==.
;	./src/modules/digi.c:19: if (level) {
	mov	a,_digitalWrite_PARM_2
	jz	00110$
	C$digi.c$20$2_0$18 ==.
;	./src/modules/digi.c:20: value |= 1 << _pin[1];
	mov	a,#0x01
	add	a,r5
	mov	r2,a
	clr	a
	addc	a,r6
	mov	r3,a
	mov	ar4,r7
	mov	dpl,r2
	mov	dph,r3
	mov	b,r4
	lcall	__gptrget
	mov	r2,a
	mov	b,r2
	inc	b
	mov	a,#0x01
	sjmp	00168$
00166$:
	add	a,acc
00168$:
	djnz	b,00166$
	mov	r2,a
	orl	_digitalWrite_value_65536_13,a
	sjmp	00111$
00110$:
	C$digi.c$22$2_0$19 ==.
;	./src/modules/digi.c:22: value &= ~(1 << _pin[1]);
	mov	a,#0x01
	add	a,r5
	mov	r2,a
	clr	a
	addc	a,r6
	mov	r3,a
	mov	ar4,r7
	mov	dpl,r2
	mov	dph,r3
	mov	b,r4
	lcall	__gptrget
	mov	r2,a
	mov	b,r2
	inc	b
	mov	a,#0x01
	sjmp	00171$
00169$:
	add	a,acc
00171$:
	djnz	b,00169$
	cpl	a
	mov	r2,a
	anl	_digitalWrite_value_65536_13,a
00111$:
	C$digi.c$29$1_0$13 ==.
;	./src/modules/digi.c:29: MACRO_LOOP(PORTS)
	mov	dpl,r5
	mov	dph,r6
	mov	b,r7
	lcall	__gptrget
	jnz	00113$
	mov	_P0,_digitalWrite_value_65536_13
00113$:
	mov	dpl,r5
	mov	dph,r6
	mov	b,r7
	lcall	__gptrget
	mov	r4,a
	cjne	r4,#0x01,00115$
	mov	_P1,_digitalWrite_value_65536_13
00115$:
	mov	dpl,r5
	mov	dph,r6
	mov	b,r7
	lcall	__gptrget
	mov	r4,a
	cjne	r4,#0x02,00117$
	mov	_P2,_digitalWrite_value_65536_13
00117$:
	mov	dpl,r5
	mov	dph,r6
	mov	b,r7
	lcall	__gptrget
	mov	r5,a
	cjne	r5,#0x03,00120$
	mov	_P3,_digitalWrite_value_65536_13
00120$:
	C$digi.c$31$1_0$13 ==.
;	./src/modules/digi.c:31: }
	C$digi.c$31$1_0$13 ==.
	XG$digitalWrite$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'digitalRead'
;------------------------------------------------------------
;value                     Allocated with name '_digitalRead_value_65536_25'
;_pin                      Allocated to registers r5 r6 r7 
;------------------------------------------------------------
	G$digitalRead$0$0 ==.
	C$digi.c$34$1_0$25 ==.
;	./src/modules/digi.c:34: uint8_t digitalRead(uint8_t* _pin) {
;	-----------------------------------------
;	 function digitalRead
;	-----------------------------------------
_digitalRead:
	C$digi.c$41$1_0$25 ==.
;	./src/modules/digi.c:41: MACRO_LOOP(PORTS)
	mov	r5,dpl
	mov	r6,dph
	mov	r7,b
	lcall	__gptrget
	jnz	00102$
	mov	_digitalRead_value_65536_25,_P0
00102$:
	mov	dpl,r5
	mov	dph,r6
	mov	b,r7
	lcall	__gptrget
	mov	r4,a
	cjne	r4,#0x01,00104$
	mov	_digitalRead_value_65536_25,_P1
00104$:
	mov	dpl,r5
	mov	dph,r6
	mov	b,r7
	lcall	__gptrget
	mov	r4,a
	cjne	r4,#0x02,00106$
	mov	_digitalRead_value_65536_25,_P2
00106$:
	mov	dpl,r5
	mov	dph,r6
	mov	b,r7
	lcall	__gptrget
	mov	r4,a
	cjne	r4,#0x03,00108$
	mov	_digitalRead_value_65536_25,_P3
00108$:
	C$digi.c$43$1_0$25 ==.
;	./src/modules/digi.c:43: return (value >> _pin[1]) & 1;
	inc	r5
	cjne	r5,#0x00,00134$
	inc	r6
00134$:
	mov	dpl,r5
	mov	dph,r6
	mov	b,r7
	lcall	__gptrget
	mov	r5,a
	mov	b,r5
	inc	b
	mov	a,_digitalRead_value_65536_25
	sjmp	00136$
00135$:
	clr	c
	rrc	a
00136$:
	djnz	b,00135$
	anl	a,#0x01
	mov	dpl,a
	C$digi.c$44$1_0$25 ==.
;	./src/modules/digi.c:44: }
	C$digi.c$44$1_0$25 ==.
	XG$digitalRead$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'shiftIn'
;------------------------------------------------------------
;clockPin                  Allocated with name '_shiftIn_PARM_2'
;bitOrder                  Allocated with name '_shiftIn_PARM_3'
;dataPin                   Allocated to registers r5 r6 r7 
;value                     Allocated to registers r4 
;i                         Allocated to registers r3 
;------------------------------------------------------------
	G$shiftIn$0$0 ==.
	C$digi.c$47$1_0$31 ==.
;	./src/modules/digi.c:47: uint8_t shiftIn(uint8_t* dataPin, uint8_t* clockPin, uint8_t bitOrder) {
;	-----------------------------------------
;	 function shiftIn
;	-----------------------------------------
_shiftIn:
	mov	r5,dpl
	mov	r6,dph
	mov	r7,b
	C$digi.c$48$2_0$31 ==.
;	./src/modules/digi.c:48: uint8_t value = 0;
	mov	r4,#0x00
	C$digi.c$49$1_0$31 ==.
;	./src/modules/digi.c:49: for (uint8_t i = 0; i < 8; ++i) {
	mov	r3,#0x00
00106$:
	cjne	r3,#0x08,00123$
00123$:
	jc	00124$
	ljmp	00104$
00124$:
	C$digi.c$50$3_0$33 ==.
;	./src/modules/digi.c:50: digitalWrite(clockPin, HIGH);
	mov	_digitalWrite_PARM_2,#0x01
	mov	dpl,_shiftIn_PARM_2
	mov	dph,(_shiftIn_PARM_2 + 1)
	mov	b,(_shiftIn_PARM_2 + 2)
	push	ar7
	push	ar6
	push	ar5
	push	ar4
	push	ar3
	lcall	_digitalWrite
	pop	ar3
	pop	ar4
	pop	ar5
	pop	ar6
	pop	ar7
	C$digi.c$51$3_0$33 ==.
;	./src/modules/digi.c:51: if (bitOrder == LSBFIRST) {
	mov	a,_shiftIn_PARM_3
	jnz	00102$
	C$digi.c$52$4_0$34 ==.
;	./src/modules/digi.c:52: value |= digitalRead(dataPin) << i;
	mov	dpl,r5
	mov	dph,r6
	mov	b,r7
	push	ar7
	push	ar6
	push	ar5
	push	ar4
	push	ar3
	lcall	_digitalRead
	mov	a,dpl
	pop	ar3
	pop	ar4
	pop	ar5
	pop	ar6
	pop	ar7
	mov	b,r3
	inc	b
	sjmp	00128$
00126$:
	add	a,acc
00128$:
	djnz	b,00126$
	mov	r2,a
	orl	ar4,a
	sjmp	00103$
00102$:
	C$digi.c$54$4_0$35 ==.
;	./src/modules/digi.c:54: value |= digitalRead(dataPin) << (7 - i);
	mov	dpl,r5
	mov	dph,r6
	mov	b,r7
	push	ar7
	push	ar6
	push	ar5
	push	ar4
	push	ar3
	lcall	_digitalRead
	mov	r2,dpl
	pop	ar3
	pop	ar4
	pop	ar5
	pop	ar6
	pop	ar7
	mov	ar1,r3
	mov	a,#0x07
	clr	c
	subb	a,r1
	mov	r1,a
	mov	b,r1
	inc	b
	mov	a,r2
	sjmp	00131$
00129$:
	add	a,acc
00131$:
	djnz	b,00129$
	mov	r1,a
	orl	ar4,a
00103$:
	C$digi.c$56$3_0$33 ==.
;	./src/modules/digi.c:56: digitalWrite(clockPin, LOW);
	mov	_digitalWrite_PARM_2,#0x00
	mov	dpl,_shiftIn_PARM_2
	mov	dph,(_shiftIn_PARM_2 + 1)
	mov	b,(_shiftIn_PARM_2 + 2)
	push	ar7
	push	ar6
	push	ar5
	push	ar4
	push	ar3
	lcall	_digitalWrite
	pop	ar3
	pop	ar4
	pop	ar5
	pop	ar6
	pop	ar7
	C$digi.c$49$2_0$32 ==.
;	./src/modules/digi.c:49: for (uint8_t i = 0; i < 8; ++i) {
	inc	r3
	ljmp	00106$
00104$:
	C$digi.c$58$1_0$31 ==.
;	./src/modules/digi.c:58: return value;
	mov	dpl,r4
	C$digi.c$59$1_0$31 ==.
;	./src/modules/digi.c:59: }
	C$digi.c$59$1_0$31 ==.
	XG$shiftIn$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'shiftOut'
;------------------------------------------------------------
;clockPin                  Allocated with name '_shiftOut_PARM_2'
;bitOrder                  Allocated with name '_shiftOut_PARM_3'
;val                       Allocated with name '_shiftOut_PARM_4'
;dataPin                   Allocated to registers r5 r6 r7 
;i                         Allocated to registers r4 
;------------------------------------------------------------
	G$shiftOut$0$0 ==.
	C$digi.c$62$1_0$38 ==.
;	./src/modules/digi.c:62: void shiftOut(uint8_t* dataPin,
;	-----------------------------------------
;	 function shiftOut
;	-----------------------------------------
_shiftOut:
	mov	r5,dpl
	mov	r6,dph
	mov	r7,b
	C$digi.c$66$2_0$38 ==.
;	./src/modules/digi.c:66: for (uint8_t i = 0; i < 8; i++) {
	mov	r4,#0x00
00106$:
	cjne	r4,#0x08,00123$
00123$:
	jc	00124$
	ljmp	00108$
00124$:
	C$digi.c$67$3_0$39 ==.
;	./src/modules/digi.c:67: if (bitOrder == LSBFIRST) {
	mov	a,_shiftOut_PARM_3
	jnz	00102$
	C$digi.c$68$4_0$40 ==.
;	./src/modules/digi.c:68: digitalWrite(dataPin, !!(val & (1 << i)));
	mov	b,r4
	inc	b
	mov	r2,#0x01
	mov	r3,#0x00
	sjmp	00127$
00126$:
	mov	a,r2
	add	a,r2
	mov	r2,a
	mov	a,r3
	rlc	a
	mov	r3,a
00127$:
	djnz	b,00126$
	mov	r0,_shiftOut_PARM_4
	mov	r1,#0x00
	mov	a,r0
	anl	ar2,a
	mov	a,r1
	anl	ar3,a
	mov	a,r2
	orl	a,r3
	cjne	a,#0x01,00128$
00128$:
	cpl	c
	mov	_shiftOut_sloc0_1_0,c
	clr	a
	rlc	a
	mov	_digitalWrite_PARM_2,a
	mov	dpl,r5
	mov	dph,r6
	mov	b,r7
	push	ar7
	push	ar6
	push	ar5
	push	ar4
	lcall	_digitalWrite
	pop	ar4
	pop	ar5
	pop	ar6
	pop	ar7
	sjmp	00103$
00102$:
	C$digi.c$70$4_0$41 ==.
;	./src/modules/digi.c:70: digitalWrite(dataPin, !!(val & (1 << (7 - i))));
	mov	a,#0x07
	clr	c
	subb	a,r4
	mov	r3,a
	mov	b,r3
	inc	b
	mov	r3,#0x01
	mov	r2,#0x00
	sjmp	00130$
00129$:
	mov	a,r3
	add	a,r3
	mov	r3,a
	mov	a,r2
	rlc	a
	mov	r2,a
00130$:
	djnz	b,00129$
	mov	r0,_shiftOut_PARM_4
	mov	r1,#0x00
	mov	a,r0
	anl	ar3,a
	mov	a,r1
	anl	ar2,a
	mov	a,r3
	orl	a,r2
	cjne	a,#0x01,00131$
00131$:
	cpl	c
	mov	_shiftOut_sloc0_1_0,c
	clr	a
	rlc	a
	mov	_digitalWrite_PARM_2,a
	mov	dpl,r5
	mov	dph,r6
	mov	b,r7
	push	ar7
	push	ar6
	push	ar5
	push	ar4
	lcall	_digitalWrite
	pop	ar4
	pop	ar5
	pop	ar6
	pop	ar7
00103$:
	C$digi.c$72$3_0$39 ==.
;	./src/modules/digi.c:72: digitalWrite(clockPin, HIGH);
	mov	_digitalWrite_PARM_2,#0x01
	mov	dpl,_shiftOut_PARM_2
	mov	dph,(_shiftOut_PARM_2 + 1)
	mov	b,(_shiftOut_PARM_2 + 2)
	push	ar7
	push	ar6
	push	ar5
	push	ar4
	lcall	_digitalWrite
	C$digi.c$73$3_0$39 ==.
;	./src/modules/digi.c:73: digitalWrite(clockPin, LOW);
	mov	_digitalWrite_PARM_2,#0x00
	mov	dpl,_shiftOut_PARM_2
	mov	dph,(_shiftOut_PARM_2 + 1)
	mov	b,(_shiftOut_PARM_2 + 2)
	lcall	_digitalWrite
	pop	ar4
	pop	ar5
	pop	ar6
	pop	ar7
	C$digi.c$66$2_0$38 ==.
;	./src/modules/digi.c:66: for (uint8_t i = 0; i < 8; i++) {
	inc	r4
	ljmp	00106$
00108$:
	C$digi.c$75$2_0$38 ==.
;	./src/modules/digi.c:75: }
	C$digi.c$75$2_0$38 ==.
	XG$shiftOut$0$0 ==.
	ret
	.area CSEG    (CODE)
	.area CONST   (CODE)
	.area XINIT   (CODE)
	.area CABS    (ABS,CODE)
