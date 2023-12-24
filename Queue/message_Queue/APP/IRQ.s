;/****************************************Copyright (c)**************************************************
;**                               ������������Ƭ����չ���޹�˾
;**                                     ��    ��    ��
;**                                        ��Ʒһ�� 
;**
;**                                 http://www.zlgmcu.com
;**
;**--------------�ļ���Ϣ--------------------------------------------------------------------------------
;**��   ��   ��: IRQ.s
;**��   ��   ��: ������
;**����޸�����: 2004��5��20��
;**��        ��: �����ж�Ƕ��ʱ��IRQ���
;**              ÿ������Ӧ���ж���������ļ��Ŀ�������������Ӧ���޸�   
;**--------------��ʷ�汾��Ϣ----------------------------------------------------------------------------
;** ������: ������
;** ��  ��: v1.0
;** �ա���: 2004��2��2��
;** �衡��: ԭʼ�汾
;**
;**------------------------------------------------------------------------------------------------------
;** �޸���: ������
;** ��  ��: v1.1
;** �ա���: 2004��5��26��
;** �衡��: �Ľ�HANDLER�꣬ʹ����ɿ�
;**
;**--------------��ǰ�汾�޶�------------------------------------------------------------------------------
;** �޸���:
;** �ա���:
;** �衡��:
;**
;**------------------------------------------------------------------------------------------------------
;********************************************************************************************************/

NoInt       EQU 0x80

USR32Mode   EQU 0x10
SVC32Mode   EQU 0x13
SYS32Mode   EQU 0x1f
IRQ32Mode   EQU 0x12
FIQ32Mode   EQU 0x11


;������ⲿ�����������
        IMPORT  OSIntCtxSw                      ;�����л�����
        IMPORT  OSIntExit                       ;�ж��˳�����
        IMPORT  OSTCBCur
        IMPORT  OSTCBHighRdy
        IMPORT  OSIntNesting                    ;�ж�Ƕ�׼�����
        IMPORT  StackUsr
        IMPORT  OsEnterSum

    CODE32

    PRESERVE8
    AREA    IRQ,CODE,READONLY

    MACRO
$IRQ_Label HANDLER $IRQ_Exception_Function

        EXPORT  $IRQ_Label                      ; ����ı��
        IMPORT  $IRQ_Exception_Function         ; ���õ��ⲿ���

$IRQ_Label
        SUB     LR, LR, #4                      ; ���㷵�ص�ַ
        STMFD   SP!, {R0-R3, R12, LR}           ; �������񻷾�
        MRS     R3, SPSR                        ; ����״̬
        STMFD   SP, {R3, SP, LR}^               ; �����û�״̬��R3,SP,LR,ע�ⲻ�ܻ�д
                                                ; �����д�����û���SP�����Ժ���Ҫ����SP
        LDR     R2,  =OSIntNesting              ; OSIntNesting++
        LDRB    R1, [R2]
        ADD     R1, R1, #1
        STRB    R1, [R2]

        SUB     SP, SP, #4*3
        
        MSR     CPSR_c, #(NoInt | SYS32Mode)    ; �л���ϵͳģʽ
        CMP     R1, #1
        LDREQ   SP, =StackUsr
        
        BL      $IRQ_Exception_Function         ; ����c���Ե��жϴ�������
        
;       MSR     CPSR_c, #(NoInt | SYS32Mode)    ; �л���ϵͳģʽ
        LDR     R2, =OsEnterSum                 ; OsEnterSum,ʹOSIntExit�˳�ʱ�жϹر�
        MOV     R1, #1
        STR     R1, [R2]

        BL      OSIntExit

        LDR     R2, =OsEnterSum                 ; ��Ϊ�жϷ������Ҫ�˳�������OsEnterSum=0
        MOV     R1, #0
        STR     R1, [R2]

        MSR     CPSR_c, #(NoInt | IRQ32Mode)    ; �л���irqģʽ
        LDMFD   SP, {R3, SP, LR}^               ; �ָ��û�״̬��R3,SP,LR,ע�ⲻ�ܻ�д
                                                ; �����д�����û���SP�����Ժ���Ҫ����SP
        LDR     R0, =OSTCBHighRdy
        LDR     R0, [R0]
        LDR     R1, =OSTCBCur
        LDR     R1, [R1]
        CMP     R0, R1

        ADD     SP, SP, #4*3                    ; 
        MSR     SPSR_cxsf, R3
        LDMEQFD SP!, {R0-R3, R12, PC}^          ; �����������л�
        LDR     PC, =OSIntCtxSw                 ; ���������л�
    MEND

;/* ���������жϾ�����û�����ʵ������ı� */

;/*�ж�*/
IRQ_Handler HANDLER IRQ_Exception


;/*��ʱ��0�ж�*/
Timer0_Handler  HANDLER Timer0_Exception

    END
;/*********************************************************************************************************
;**                            End Of File
;********************************************************************************************************/