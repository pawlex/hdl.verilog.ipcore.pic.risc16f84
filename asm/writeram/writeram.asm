;START=0x00C             END=0x07F
;START=0x08C             END=0x0FF           PROTECTED
;START=0x10C             END=0x17F
;START=0x18C             END=0x1FF           PROTECTED

; STATUS REGISER:
; bit 7: IRP: Register Bank Select bit (used for indirect addressing)
; 0 = Bank 0, 1 (00h - FFh)
; 1 = Bank 2, 3 (100h - 1FFh)
; The IRP bit is not used by the PIC16F8X. IRP should be maintained clear.
; bit 6-5: RP1:RP0: Register Bank Select bits (used for direct addressing)
; 00 = Bank 0 (00h - 7Fh)
; 01 = Bank 1 (80h - FFh)
; 10 = Bank 2 (100h - 17Fh)
; 11 = Bank 3 (180h - 1FFh)
; Each bank is 128 bytes. Only bit RP0 is used by the PIC16F8X. RP1 should be maintained clear.
;
list	p=16f84
        radix  hex
include "p16f84.inc"
;START movlw 0x55      ; pattern
;L0  BCF   STATUS, IRP ; BANK 0x0 - 0xFF 


; JUMP OVER NEXT INSTRUCTION IF TRUE
;BTFSC Bit Test, Skip if Clear - TRUE IF BIT IS 0
;BTFSS Bit Test f, Skip if Set - TRUE IF BIT IS 1

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
S   BCF     STATUS, IRP     ; SET BANK 0 (0x0C - 0x7F)
    MOVLW   0x55            ; MOVE THE INITIAL PATTERN INTO THE 1ST ADDRESS (0xC)
    MOVWF   0xC
L0  MOVLW   0xC             ; SET THE WRITE POINTER
    MOVWF   FSR
    MOVFW   0xC             ; LOAD THE PATTERN INTO THE WORKING REGISTER
L2  MOVWF   INDF            ; MOVE THE PATTERN INTO THE ADDRESS POINTED TO BY FSR
    INCF    FSR,    1       ; INC THE POINTER TO NEXT ADDRESS
    BTFSS   FSR,    7       ; BIT TEST FSR BIT 7
    GOTO    L2              ; if(!FSR & 0b1000_0000) JMP label: L2
;   ELSE
    BTFSC   STATUS, IRP     ; if(BANK1)
    GOTO    L3              ; if(!BANK1) goto L3
    BSF     STATUS, IRP     ; SET BANK 1 (0x8C - 0xFF)
    GOTO    L0              ; RESTART WRITING AT 1ST ADDRESS OF BANK 1 (initial pattern)
L3  BCF     STATUS, IRP     ; GO BACK TO BANK 0
    MOVLW   0xFF            ;
    XORWF   0xC,    1       ; CHANGE THE PATTERN TO 0xAA
    GOTO    L0              ; START OVER
                 
    END                     ;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;S   BCF   STATUS, IRP
;    MOVLW 0xC   ;initialize pointer..
;    MOVWF FSR   ;..to RAM
;    MOVLW 0x55  ;pattern
;L1  MOVWF INDF  ;Write contents of W to RAM indirectly.
;    INCF  FSR,1 ;inc pointer
;    BTFSS FSR,7 ;all done?
;    GOTO  L1    ;NO, clear next
;;;
;    MOVLW 0xC
;    MOVWF FSR
;    MOVLW 0x55
;    BSF STATUS, IRP
;L2  MOVWF INDF  ;Write contents of W to RAM indirectly.
;    INCF  FSR,1 ;inc pointer
;    BTFSS FSR,7 ;all done?
;    GOTO  L2    ;NO, clear next
;;;  
;    BCF   STATUS, IRP
;    MOVLW 0xC
;    MOVWF FSR
;    MOVLW 0xAA
;    GOTO L1
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;
    ;MOVLW 0xC   ;re-init pointer
    ;MOVWF FSR   ;..
    ;;XORLW 0xFF  ; pattern 0x55 to 0xAA to 0x55;
    ;BTFSC STATUS,IRP ; if(bank1) ? GOTO L0 : set(bank1) and goto L1.
    ;GOTO  L0
    ;BSF   STATUS,IRP    ;set bank 1;
    ;GOTO  L1    ; UCJMP
    
    END ;;
