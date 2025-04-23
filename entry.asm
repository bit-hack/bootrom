
.8086
.model TINY

extrn _BootMain:near

.code
org     0100h
main:
    jmp short start
    nop

start:
    cli
    mov ax,cs               ; Setup segment registers
    mov ds,ax               ; Make DS correct
    mov es,ax               ; Make ES correct
    mov ss,ax               ; Make SS correct
    mov bp,0fffeh
    mov sp,0fffeh           ; Setup a stack
    sti

    call _BootMain
    ret

END main
