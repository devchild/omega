Int32 write(Char[] str, Int32 str_len):
    Int32 stdout = 1
    Int32 syscall_nr = 33554432 + 4
    asm<UInt64>("syscall", "={rax}, {rax}, {rdi}, {rsi}, {rdx},~{rcx},~{r11}", syscall_nr, stdout, str, str_len)
    return 0

Int32 exit(Int32 exit_code):
    Int32 syscall_nr = 33554432 + 1
    asm<UInt64>("syscall", "={rax}, {rax}, {rdi},~{rcx},~{r11}", syscall_nr, exit_code)
    return 0