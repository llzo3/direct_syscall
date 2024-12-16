.code
DirectNtAllocateVirtualMemory PROC
    mov r10, rcx
    mov eax, 18h
    syscall
    ret
DirectNtAllocateVirtualMemory ENDP
End