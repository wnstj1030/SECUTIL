# **Assembly**

어셈블리 언어는 문장으로 치자면 동사인 명령어와 목적어에 해당하는 피연산자로 구성된다

| 데이터 이동(Data Transfer) | mov, lea |
| --- | --- |
| 산술 연산(Arithmetic) | inc, dec, add, sub |
| 논리 연산(Logical) | and, or, xor, not |
| 비교(Comparison) | cmp, test |
| 분기(Branch) | jmp, je, jg |
| 스택(Stack) | push, pop |
| 프로시져(Procedure) | call, ret, leave |
| 시스템 콜(System call) | syscall |

### 피연산자

- 상수(Immediate Value)
- 레지스터(Register)
- 메모리(Memory)

메모리 피연산자는 []에 둘러싸인 것으로 표현되며, 앞에 크기 지정자 `TYPE PTR` 이 추가될 수 있다 

여기서 타입으로는 BYTE, WORD, DWORD, QWORD가 올 수 있고 각각 1바이트, 2바이트, 4바이트, 8바이트의 크기를 지정한다

EX)

| 메모리 피연산자 |  |
| --- | --- |
| QWORD PTR [0x8048000] | 0x8048000의 데이터를 8바이트만큼 참조 |
| DWORD PTR [0x8048000] | 0x8048000의 데이터를 4바이트만큼 참조 |
| WORD PTR [rax] | rax가 가르키는 주소에서 데이터를 2바이트 만큼 참조 |

---

## ****x86-64 어셈블리 명령어****

### 데이터 이동🚚

데이터 이동 명령어는 어떤 값을 레지스터나 메오리에 옮기도록 지시한다

| mov dst, src : src에 들어있는 값을 dst에 대입 |  |
| --- | --- |
| mov rdi, rsi | rsi의 값을 rdi에 대입 |
| mov QWORD PTR[rdi], rsi | rsi의 값을 rdi가 가리키는 주소에 대입 |
| mov QWORD PTR[rdi+8*rcx], rsi | rsi의 값을 rdi+8*rcx가 가리키는 주소에 대입 |

**lea dst, src : src의 유효 주소(Effective Address, EA)를 dst에 저장한다**

| lea rsi, [rbx+8*rcx] | rbx+8*rcx 를 rsi에 대입 |
| --- | --- |

```c
[Register]
rbx = 0x401A40
=================================
[Memory]
0x401a40 | 0x0000000012345678
0x401a48 | 0x0000000000C0FFEE
0x401a50 | 0x00000000DEADBEEF
0x401a58 | 0x00000000CAFEBABE
0x401a60 | 0x0000000087654321
=================================
[Code]
1: mov rax, [rbx+8]
2: lea rax, [rbx+8]
```

Code를 1까지 실행했을 때, `rax`에 저장된 값은?

⇒ 0xC0FFEE

Code를 2까지 실행했을 때, `rax`에 들어있는 값은?

⇒ 0x401a48

### 산술 연산🎲

**add dst, src : dst에 src의 값을 더한다**

| add eax, 3 | eax += 3 |
| --- | --- |
| add ax, WORD PTR[rdi] | ax += *(WORD *)rdi |

**sub dst, src: dst에서 src의 값을 뺀다**

| sub eax, 3 | eax -= 3 |
| --- | --- |
| sub ax, WORD PTR[rdi] | ax -= *(WORD *)rdi |

**inc op: op의 값을 1 증가시킨다**

| inc eax | eax += 1 |
| --- | --- |

**dec op: op의 값을 1 감소 시킨다**

| dec eax | eax -= 1 |
| --- | --- |

```c
[Register]
rax = 0x31337
rbx = 0x555555554000
rcx = 0x2
=================================
[Memory]
0x555555554000| 0x0000000000000000
0x555555554008| 0x0000000000000001
0x555555554010| 0x0000000000000003
0x555555554018| 0x0000000000000005
0x555555554020| 0x000000000003133A
==================================
[Code]
1: add rax, [rbx+rcx*8]
2: add rcx, 2
3: sub rax, [rbx+rcx*8]
4: inc rax
```

Code를 1까지 실행했을 때, `rax`에 저장된 값은?

⇒ 0x3133A

Code를 3까지 실행했을 때, `rax`에 저장된 값은?

⇒ 0

Code를 4까지 실행했을 때, `rax`에 저장된 값은?

⇒ 1

### ****논리 연산🤔 - and & or****

**and dst, src: dst와 src의 비트가 모두 1이면 1, 아니면 0**

```c
[Register]
eax = 0xffff0000
ebx = 0xcafebabe
[Code]
and eax, ebx
[Result]
eax = 0xcafe0000
```

**or dst, src: dst와 src의 비트 중 하나라도 1이면 1, 아니면 0**

```c
[Register]
eax = 0xffff0000
ebx = 0xcafebabe
[Code]
or eax, ebx
[Result]
eax = 0xffffbabe
```

****예제📝논리 연산 - and, or****

```c
[Register]
rax = 0xffffffff00000000
rbx = 0x00000000ffffffff
rcx = 0x123456789abcdef0
==================================
[Code]
1: and rax, rcx
2: and rbx, rcx
3: or rax, rbx
```

Code를 1까지 실행했을 때, `rax`에 저장된 값은?

⇒ 0x1234567800000000

Code를 2까지 실행했을 때, `rbx`에 저장된 값은?

⇒ 0x000000009abcdef0

Code를 3까지 실행했을 때, `rax`에 저장된 값은?

⇒ 0x123456789abcdef0

### ****논리연산🤔 - xor & not****

**xor dst, src: dst와 src의 비트가 서로 다르면 1, 같으면 0**

```c
[Register]
eax = 0xffffffff
ebx = 0xcafebabe
[Code]
xor eax, ebx
[Result]
eax = 0x35014541
```

**not op: op의 비트 전부 반전**

```c
[Register]
eax = 0xffffffff
[Code]
not eax
[Result]
eax = 0x00000000
```

****예제📝논리 연산 - xor, not****

```c
[Register]
rax = 0x35014541
rbx = 0xdeadbeef
==================================
[Code]
1: xor rax, rbx
2: xor rax, rbx
3: not eax
```

Code를 1까지 실행했을 때, `rax`에 저장되는 값은?

⇒ 0xebacfbae

Code를 2까지 실행했을 때, `rax`에 저장되는 값은?

⇒ 0x35014541

⇒ xor연산을 동일한 값으로 두 번 실행할 경우, 원래 값으로 돌아간다

Code를 3까지 실행했을 때, `rax`에 저장되는 값은?

⇒ 0xcafebabe

⇒ 참고로 [Code]의 3번에서 rax가 아닌 eax를 not 하여도 괜찮은 이유는 eax가 rax의 하위 32비트를 가리키는 부분이기 때문이다

### ****비교⚖️****

**cmp op1, op2: op1과 op2를 비교**

cmp는 두 피연산자를 빼서 대소를 비교합니다. 연산의 결과는 op1에 대입하지 않는다

```c
[Code]
1: mov rax, 0xA
2: mov rbx, 0xA
3: cmp rax, rbx ; ZF=1
```

**test op1, op2: op1과 op2를 비교**

```c
[Code]
1: xor rax, rax
2: test rax, rax ; ZF=1
```

### 분기****🔀****

**jmp addr: addr로 rip를 이동**

```c
[Code]
1: xor rax, rax
2: jmp 1 ; jump to 1
```

**je addr: 직전에 비교한 두 피연산자가 같으면 점프 (jump if equal)**

```c
[Code]
1: mov rax, 0xcafebabe
2: mov rbx, 0xcafebabe
3: cmp rax, rbx ; rax == rbx
4: je 1 ; jump to 1
```

**jg addr: 직전에 비교한 두 연산자 중 전자가 더 크면 점프 (jump if greater)**
```c
[Code]
1: mov rax, 0x31337
2: mov rbx, 0x13337
3: cmp rax, rbx ; rax > rbx
4: jg 1  ; jump to 1
```