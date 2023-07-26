;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 4.1.0 #12072 (Linux)
;--------------------------------------------------------
	.module main
	.optsdcc -mmcs51 --model-small
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _main
	.globl _sendSensorData
	.globl _getChecksum
	.globl _ADS1115ToVoltage
	.globl _ADS1115Read
	.globl _ADS1115Init
	.globl _SerialWrite
	.globl _SerialBegin
	.globl ___memcpy
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
Lmain.sendSensorData$dataBytes$1_0$53==.
_sendSensorData_dataBytes_65536_53:
	.ds 17
Lmain.main$dat$1_0$56==.
_main_dat_65536_56:
	.ds 17
Lmain.main$f$1_1$57==.
_main_f_65537_57:
	.ds 4
;--------------------------------------------------------
; overlayable items in internal ram 
;--------------------------------------------------------
	.area	OSEG    (OVR,DATA)
Lmain.getChecksum$dat$1_0$46==.
_getChecksum_dat_65536_46:
	.ds 3
Lmain.getChecksum$bytes$3_0$49==.
_getChecksum_bytes_196608_49:
	.ds 3
;--------------------------------------------------------
; Stack segment in internal ram 
;--------------------------------------------------------
	.area	SSEG
__start__stack:
	.ds	1

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
; interrupt vector 
;--------------------------------------------------------
	.area HOME    (CODE)
__interrupt_vect:
	ljmp	__sdcc_gsinit_startup
;--------------------------------------------------------
; global & static initialisations
;--------------------------------------------------------
	.area HOME    (CODE)
	.area GSINIT  (CODE)
	.area GSFINAL (CODE)
	.area GSINIT  (CODE)
	.globl __sdcc_gsinit_startup
	.globl __sdcc_program_startup
	.globl __start__stack
	.globl __mcs51_genXINIT
	.globl __mcs51_genXRAMCLEAR
	.globl __mcs51_genRAMCLEAR
	.area GSFINAL (CODE)
	ljmp	__sdcc_program_startup
;--------------------------------------------------------
; Home
;--------------------------------------------------------
	.area HOME    (CODE)
	.area HOME    (CODE)
__sdcc_program_startup:
	ljmp	_main
;	return from main will return to caller
;--------------------------------------------------------
; code
;--------------------------------------------------------
	.area CSEG    (CODE)
;------------------------------------------------------------
;Allocation info for local variables in function 'getChecksum'
;------------------------------------------------------------
;dat                       Allocated with name '_getChecksum_dat_65536_46'
;checksum                  Allocated to registers r4 
;i                         Allocated to registers r3 
;bytes                     Allocated with name '_getChecksum_bytes_196608_49'
;j                         Allocated to registers r7 
;------------------------------------------------------------
	G$getChecksum$0$0 ==.
	C$main.c$28$0_0$47 ==.
;	./src/main.c:28: uint8_t getChecksum(float* dat) {
;	-----------------------------------------
;	 function getChecksum
;	-----------------------------------------
_getChecksum:
	ar7 = 0x07
	ar6 = 0x06
	ar5 = 0x05
	ar4 = 0x04
	ar3 = 0x03
	ar2 = 0x02
	ar1 = 0x01
	ar0 = 0x00
	mov	_getChecksum_dat_65536_46,dpl
	mov	(_getChecksum_dat_65536_46 + 1),dph
	mov	(_getChecksum_dat_65536_46 + 2),b
	C$main.c$29$2_0$47 ==.
;	./src/main.c:29: uint8_t checksum = 0;
	mov	r4,#0x00
	C$main.c$31$1_0$47 ==.
;	./src/main.c:31: for (uint8_t i = 0; i < 4; i++) {
	mov	r3,#0x00
00107$:
	cjne	r3,#0x04,00129$
00129$:
	jnc	00102$
	C$main.c$32$3_0$49 ==.
;	./src/main.c:32: uint8_t* bytes = (uint8_t*)&dat[i];
	mov	a,r3
	mov	b,#0x04
	mul	ab
	add	a,_getChecksum_dat_65536_46
	mov	r0,a
	mov	a,(_getChecksum_dat_65536_46 + 1)
	addc	a,b
	mov	r1,a
	mov	r2,(_getChecksum_dat_65536_46 + 2)
	mov	_getChecksum_bytes_196608_49,r0
	mov	(_getChecksum_bytes_196608_49 + 1),#0x00
	mov	(_getChecksum_bytes_196608_49 + 2),#0x40
	C$main.c$34$1_0$47 ==.
;	./src/main.c:34: for (uint8_t j = 0; j < sizeof(float); j++) {
	mov	r7,#0x00
00104$:
	cjne	r7,#0x04,00131$
00131$:
	jnc	00108$
	C$main.c$35$5_0$51 ==.
;	./src/main.c:35: checksum ^= bytes[j];
	mov	a,r7
	add	a,_getChecksum_bytes_196608_49
	mov	r2,a
	clr	a
	addc	a,(_getChecksum_bytes_196608_49 + 1)
	mov	r5,a
	mov	r6,(_getChecksum_bytes_196608_49 + 2)
	mov	dpl,r2
	mov	dph,r5
	mov	b,r6
	lcall	__gptrget
	mov	r2,a
	xrl	ar4,a
	C$main.c$34$4_0$50 ==.
;	./src/main.c:34: for (uint8_t j = 0; j < sizeof(float); j++) {
	inc	r7
	sjmp	00104$
00108$:
	C$main.c$31$2_0$48 ==.
;	./src/main.c:31: for (uint8_t i = 0; i < 4; i++) {
	inc	r3
	sjmp	00107$
00102$:
	C$main.c$39$1_0$47 ==.
;	./src/main.c:39: return checksum;
	mov	dpl,r4
	C$main.c$40$1_0$47 ==.
;	./src/main.c:40: }
	C$main.c$40$1_0$47 ==.
	XG$getChecksum$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'sendSensorData'
;------------------------------------------------------------
;dat                       Allocated to registers r5 r6 r7 
;dataBytes                 Allocated with name '_sendSensorData_dataBytes_65536_53'
;i                         Allocated to registers r7 
;------------------------------------------------------------
	G$sendSensorData$0$0 ==.
	C$main.c$43$1_0$53 ==.
;	./src/main.c:43: void sendSensorData(sensor_t* dat) {
;	-----------------------------------------
;	 function sendSensorData
;	-----------------------------------------
_sendSensorData:
	mov	r5,dpl
	mov	r6,dph
	mov	r7,b
	C$main.c$45$1_0$53 ==.
;	./src/main.c:45: memcpy(dataBytes, dat, sizeof(sensor_t));
	mov	___memcpy_PARM_2,r5
	mov	(___memcpy_PARM_2 + 1),r6
	mov	(___memcpy_PARM_2 + 2),r7
	mov	___memcpy_PARM_3,#0x11
	mov	(___memcpy_PARM_3 + 1),#0x00
	mov	dptr,#_sendSensorData_dataBytes_65536_53
	mov	b,#0x40
	lcall	___memcpy
	C$main.c$47$2_0$53 ==.
;	./src/main.c:47: for (uint8_t i = 0; i < sizeof(sensor_t); i++) {
	mov	r7,#0x00
00103$:
	cjne	r7,#0x11,00116$
00116$:
	jnc	00105$
	C$main.c$48$3_0$55 ==.
;	./src/main.c:48: SerialWrite(dataBytes[i]);
	mov	a,r7
	add	a,#_sendSensorData_dataBytes_65536_53
	mov	r1,a
	mov	dpl,@r1
	push	ar7
	lcall	_SerialWrite
	pop	ar7
	C$main.c$47$2_0$54 ==.
;	./src/main.c:47: for (uint8_t i = 0; i < sizeof(sensor_t); i++) {
	inc	r7
	sjmp	00103$
00105$:
	C$main.c$50$2_0$53 ==.
;	./src/main.c:50: }
	C$main.c$50$2_0$53 ==.
	XG$sendSensorData$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'main'
;------------------------------------------------------------
;dat                       Allocated with name '_main_dat_65536_56'
;f                         Allocated with name '_main_f_65537_57'
;------------------------------------------------------------
	G$main$0$0 ==.
	C$main.c$52$2_0$56 ==.
;	./src/main.c:52: void main() {
;	-----------------------------------------
;	 function main
;	-----------------------------------------
_main:
	C$main.c$54$1_0$56 ==.
;	./src/main.c:54: SerialBegin(19200);
	mov	dptr,#0x4b00
	lcall	_SerialBegin
	C$main.c$56$1_0$56 ==.
;	./src/main.c:56: ADS1115Init();
	lcall	_ADS1115Init
	C$main.c$57$1_1$57 ==.
;	./src/main.c:57: float f = ADS1115ToVoltage(ADS1115_PGA_4_096V);
	mov	dptr,#0x0200
	lcall	_ADS1115ToVoltage
	mov	_main_f_65537_57,dpl
	mov	(_main_f_65537_57 + 1),dph
	mov	(_main_f_65537_57 + 2),b
	mov	(_main_f_65537_57 + 3),a
	C$main.c$59$1_1$57 ==.
;	./src/main.c:59: while (1) {
00102$:
	C$main.c$60$2_1$58 ==.
;	./src/main.c:60: dat.AIN[0] =
	C$main.c$64$2_1$58 ==.
;	./src/main.c:64: ADS1115_COMP_QUEUE_DISABLE);
	mov	_ADS1115Read_PARM_2,#0x00
	mov	(_ADS1115Read_PARM_2 + 1),#0x02
	mov	_ADS1115Read_PARM_3,#0xe0
	mov	_ADS1115Read_PARM_4,#0x10
	mov	_ADS1115Read_PARM_5,#0x00
	mov	_ADS1115Read_PARM_6,#0x00
	mov	_ADS1115Read_PARM_7,#0x03
	mov	dptr,#0x4000
	lcall	_ADS1115Read
	lcall	___sint2fs
	mov	r2,dpl
	mov	r3,dph
	mov	r6,b
	mov	r7,a
	push	ar2
	push	ar3
	push	ar6
	push	ar7
	mov	dpl,_main_f_65537_57
	mov	dph,(_main_f_65537_57 + 1)
	mov	b,(_main_f_65537_57 + 2)
	mov	a,(_main_f_65537_57 + 3)
	lcall	___fsmul
	mov	r4,dpl
	mov	r5,dph
	mov	r6,b
	mov	r7,a
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
	mov	(_main_dat_65536_56 + 0),r4
	mov	(_main_dat_65536_56 + 1),r5
	mov	(_main_dat_65536_56 + 2),r6
	mov	(_main_dat_65536_56 + 3),r7
	C$main.c$65$2_1$58 ==.
;	./src/main.c:65: dat.AIN[1] =
	C$main.c$69$2_1$58 ==.
;	./src/main.c:69: ADS1115_COMP_QUEUE_DISABLE);
	mov	_ADS1115Read_PARM_2,#0x00
	mov	(_ADS1115Read_PARM_2 + 1),#0x02
	mov	_ADS1115Read_PARM_3,#0xe0
	mov	_ADS1115Read_PARM_4,#0x10
	mov	_ADS1115Read_PARM_5,#0x00
	mov	_ADS1115Read_PARM_6,#0x00
	mov	_ADS1115Read_PARM_7,#0x03
	mov	dptr,#0x5000
	lcall	_ADS1115Read
	lcall	___sint2fs
	mov	r4,dpl
	mov	r5,dph
	mov	r6,b
	mov	r7,a
	push	ar4
	push	ar5
	push	ar6
	push	ar7
	mov	dpl,_main_f_65537_57
	mov	dph,(_main_f_65537_57 + 1)
	mov	b,(_main_f_65537_57 + 2)
	mov	a,(_main_f_65537_57 + 3)
	lcall	___fsmul
	mov	r4,dpl
	mov	r5,dph
	mov	r6,b
	mov	r7,a
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
	mov	((_main_dat_65536_56 + 0x0004) + 0),r4
	mov	((_main_dat_65536_56 + 0x0004) + 1),r5
	mov	((_main_dat_65536_56 + 0x0004) + 2),r6
	mov	((_main_dat_65536_56 + 0x0004) + 3),r7
	C$main.c$70$2_1$58 ==.
;	./src/main.c:70: dat.AIN[2] =
	C$main.c$74$2_1$58 ==.
;	./src/main.c:74: ADS1115_COMP_QUEUE_DISABLE);
	mov	_ADS1115Read_PARM_2,#0x00
	mov	(_ADS1115Read_PARM_2 + 1),#0x02
	mov	_ADS1115Read_PARM_3,#0xe0
	mov	_ADS1115Read_PARM_4,#0x10
	mov	_ADS1115Read_PARM_5,#0x00
	mov	_ADS1115Read_PARM_6,#0x00
	mov	_ADS1115Read_PARM_7,#0x03
	mov	dptr,#0x6000
	lcall	_ADS1115Read
	lcall	___sint2fs
	mov	r4,dpl
	mov	r5,dph
	mov	r6,b
	mov	r7,a
	push	ar4
	push	ar5
	push	ar6
	push	ar7
	mov	dpl,_main_f_65537_57
	mov	dph,(_main_f_65537_57 + 1)
	mov	b,(_main_f_65537_57 + 2)
	mov	a,(_main_f_65537_57 + 3)
	lcall	___fsmul
	mov	r4,dpl
	mov	r5,dph
	mov	r6,b
	mov	r7,a
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
	mov	((_main_dat_65536_56 + 0x0008) + 0),r4
	mov	((_main_dat_65536_56 + 0x0008) + 1),r5
	mov	((_main_dat_65536_56 + 0x0008) + 2),r6
	mov	((_main_dat_65536_56 + 0x0008) + 3),r7
	C$main.c$75$2_1$58 ==.
;	./src/main.c:75: dat.AIN[3] =
	C$main.c$79$2_1$58 ==.
;	./src/main.c:79: ADS1115_COMP_QUEUE_DISABLE);
	mov	_ADS1115Read_PARM_2,#0x00
	mov	(_ADS1115Read_PARM_2 + 1),#0x02
	mov	_ADS1115Read_PARM_3,#0xe0
	mov	_ADS1115Read_PARM_4,#0x10
	mov	_ADS1115Read_PARM_5,#0x00
	mov	_ADS1115Read_PARM_6,#0x00
	mov	_ADS1115Read_PARM_7,#0x03
	mov	dptr,#0x7000
	lcall	_ADS1115Read
	lcall	___sint2fs
	mov	r4,dpl
	mov	r5,dph
	mov	r6,b
	mov	r7,a
	push	ar4
	push	ar5
	push	ar6
	push	ar7
	mov	dpl,_main_f_65537_57
	mov	dph,(_main_f_65537_57 + 1)
	mov	b,(_main_f_65537_57 + 2)
	mov	a,(_main_f_65537_57 + 3)
	lcall	___fsmul
	mov	r4,dpl
	mov	r5,dph
	mov	r6,b
	mov	r7,a
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
	mov	((_main_dat_65536_56 + 0x000c) + 0),r4
	mov	((_main_dat_65536_56 + 0x000c) + 1),r5
	mov	((_main_dat_65536_56 + 0x000c) + 2),r6
	mov	((_main_dat_65536_56 + 0x000c) + 3),r7
	C$main.c$80$2_1$58 ==.
;	./src/main.c:80: dat.Checksum = getChecksum(dat.AIN);
	mov	dptr,#_main_dat_65536_56
	mov	b,#0x40
	lcall	_getChecksum
	mov	a,dpl
	mov	(_main_dat_65536_56 + 0x0010),a
	C$main.c$82$2_1$58 ==.
;	./src/main.c:82: SerialWrite(SYNC_WORD);
	mov	dpl,#0x8a
	lcall	_SerialWrite
	C$main.c$83$2_1$58 ==.
;	./src/main.c:83: sendSensorData(&dat);
	mov	dptr,#_main_dat_65536_56
	mov	b,#0x40
	lcall	_sendSensorData
	ljmp	00102$
	C$main.c$85$1_1$56 ==.
;	./src/main.c:85: }
	C$main.c$85$1_1$56 ==.
	XG$main$0$0 ==.
	ret
	.area CSEG    (CODE)
	.area CONST   (CODE)
	.area XINIT   (CODE)
	.area CABS    (ABS,CODE)
