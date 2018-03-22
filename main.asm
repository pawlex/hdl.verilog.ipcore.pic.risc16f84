;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 3.4.0 #8981 (Oct 25 2014) (Linux)
; This file was generated Wed Mar 21 23:15:15 2018
;--------------------------------------------------------
; PIC port for the 14-bit core
;--------------------------------------------------------
;	.file	"main.c"
	list	p=16f84
	radix dec
	include "p16f84.inc"
;--------------------------------------------------------
; external declarations
;--------------------------------------------------------
	extern	_STATUSbits
	extern	_PORTAbits
	extern	_PORTBbits
	extern	_INTCONbits
	extern	_OPTION_REGbits
	extern	_TRISAbits
	extern	_TRISBbits
	extern	_EECON1bits
	extern	_INDF
	extern	_TMR0
	extern	_PCL
	extern	_STATUS
	extern	_FSR
	extern	_PORTA
	extern	_PORTB
	extern	_EEDATA
	extern	_EEADR
	extern	_PCLATH
	extern	_INTCON
	extern	_OPTION_REG
	extern	_TRISA
	extern	_TRISB
	extern	_EECON1
	extern	_EECON2
	extern	__sdcc_gsinit_startup
;--------------------------------------------------------
; global declarations
;--------------------------------------------------------
	global	_halt
	global	_main
	global	_i

	global PSAVE
	global SSAVE
	global WSAVE
	global STK12
	global STK11
	global STK10
	global STK09
	global STK08
	global STK07
	global STK06
	global STK05
	global STK04
	global STK03
	global STK02
	global STK01
	global STK00

sharebank udata_ovr 0x000C
PSAVE	res 1
SSAVE	res 1
WSAVE	res 1
STK12	res 1
STK11	res 1
STK10	res 1
STK09	res 1
STK08	res 1
STK07	res 1
STK06	res 1
STK05	res 1
STK04	res 1
STK03	res 1
STK02	res 1
STK01	res 1
STK00	res 1

;--------------------------------------------------------
; global definitions
;--------------------------------------------------------
;--------------------------------------------------------
; absolute symbol definitions
;--------------------------------------------------------
;--------------------------------------------------------
; compiler-defined variables
;--------------------------------------------------------
UDL_main_0	udata
r0x1002	res	1
r0x1003	res	1
r0x1004	res	1
r0x1005	res	1
;--------------------------------------------------------
; initialized data
;--------------------------------------------------------

ID_main_0	idata
_i
	db	0x00, 0x00

;--------------------------------------------------------
; overlayable items in internal ram 
;--------------------------------------------------------
;	udata_ovr
;--------------------------------------------------------
; reset vector 
;--------------------------------------------------------
STARTUP	code 0x0000
	nop
	pagesel __sdcc_gsinit_startup
	goto	__sdcc_gsinit_startup
;--------------------------------------------------------
; code
;--------------------------------------------------------
code_main	code
;***
;  pBlock Stats: dbName = M
;***
;entry:  _main	;Function start
; 2 exit points
;has an exit
;functions called:
;   _halt
;   _halt
;   _halt
;   _halt
;4 compiler assigned registers:
;   r0x1002
;   r0x1003
;   r0x1004
;   r0x1005
;; Starting pCode block
_main	;Function start
; 2 exit points
;	.line	30; "main.c"	for(i=0;i<MAXVAL;i=i+STRIDE)
	CLRF	_i
	CLRF	(_i + 1)
_00115_DS_
;	.line	32; "main.c"	PORTA = i & 0xff; 
	MOVF	_i,W
	MOVWF	r0x1002
	CLRF	r0x1003
	MOVF	r0x1002,W
	MOVWF	r0x1004
	BANKSEL	_PORTA
	MOVWF	_PORTA
;	.line	33; "main.c"	PORTB = ((i >> 8) & 0xff);
	MOVF	(_i + 1),W
	MOVWF	r0x1002
	CLRF	r0x1003
	CLRF	r0x1003
	MOVF	r0x1002,W
	MOVWF	_PORTB
;	.line	34; "main.c"	EEDATA = i & 0xff;
	MOVF	r0x1004,W
	MOVWF	_EEDATA
;	.line	30; "main.c"	for(i=0;i<MAXVAL;i=i+STRIDE)
	MOVLW	0x44
	ADDWF	_i,F
	BTFSC	STATUS,0
	INCF	(_i + 1),F
;;unsigned compare: left < lit(0x1FFF=8191), size=2
	MOVLW	0x1f
	SUBWF	(_i + 1),W
	BTFSS	STATUS,2
	GOTO	_00136_DS_
	MOVLW	0xff
	SUBWF	_i,W
_00136_DS_
	BTFSS	STATUS,0
	GOTO	_00115_DS_
;;genSkipc:3247: created from rifx:0x7ffd232246d0
;	.line	38; "main.c"	for(i=0;i<MAXVAL;i=i+STRIDE)
	CLRF	_i
	CLRF	(_i + 1)
_00117_DS_
;	.line	40; "main.c"	PORTA = i & 0xff; 
	MOVF	_i,W
	MOVWF	r0x1002
	CLRF	r0x1003
	MOVF	r0x1002,W
	BANKSEL	_PORTA
	MOVWF	_PORTA
;	.line	41; "main.c"	PORTB = ((i >> 8) & 0xff);
	MOVF	(_i + 1),W
	MOVWF	r0x1004
	CLRF	r0x1005
	CLRF	r0x1005
	MOVF	r0x1004,W
	MOVWF	_PORTB
;	.line	44; "main.c"	if(EEDATA != (i & 0xff))
	MOVF	_EEDATA,W
	MOVWF	r0x1004
	CLRF	r0x1005
	MOVF	r0x1002,W
	XORWF	r0x1004,W
	BTFSS	STATUS,2
	GOTO	_00137_DS_
	MOVF	r0x1003,W
;	.line	46; "main.c"	halt();
	XORWF	r0x1005,W
;	.line	38; "main.c"	for(i=0;i<MAXVAL;i=i+STRIDE)
	BTFSS	STATUS,2
_00137_DS_
	CALL	_halt
	MOVLW	0x44
	ADDWF	_i,F
	BTFSC	STATUS,0
	INCF	(_i + 1),F
;;unsigned compare: left < lit(0x1FFF=8191), size=2
	MOVLW	0x1f
	SUBWF	(_i + 1),W
	BTFSS	STATUS,2
	GOTO	_00138_DS_
	MOVLW	0xff
	SUBWF	_i,W
_00138_DS_
	BTFSS	STATUS,0
	GOTO	_00117_DS_
;;genSkipc:3247: created from rifx:0x7ffd232246d0
;	.line	50; "main.c"	halt();
	CALL	_halt
	RETURN	
; exit point of _main

;***
;  pBlock Stats: dbName = C
;***
;entry:  _halt	;Function start
; 2 exit points
;has an exit
;; Starting pCode block
_halt	;Function start
; 2 exit points
_00106_DS_
	nop 
	GOTO	_00106_DS_
	RETURN	
; exit point of _halt


;	code size estimation:
;	   68+    2 =    70 instructions (  144 byte)

	end
