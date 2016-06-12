/* -*- mode: asm; coding: utf-8; -*-
as -o hello64.o hello64.s
ld -o hello64 hello64.o
./hello64
*/
.code64
.text

.global _start

_start:
        mov     $4,     %rax    # 出力システムコール
        mov     $1,     %rbx    # 標準出力
        mov     $msg,   %rcx    # 文字列のアドレス
        mov     $len,   %rdx    # 文字列の長さ
        int     $0x80           # システムコール実行

        mov     $1,     %rax    # exit システムコール
        mov     $0,     %rbx    # exit コード
        int     $0x80           # システムコール実行

.data

msg:    .ascii "Hello World!\n"
msgend: len = msgend - msg
