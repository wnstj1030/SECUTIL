# **레지스터**

- **범용레지스터**

| 이름 | 주용도 |
| --- | --- |
| rax (accumulator register) | 함수의 반환 값 |
| rbx (base register) | x64에서는 주된 용도 없음 |
| rcx (counter register) | 반복문의 반복 횟수, 각종 연산의 시행 횟수 |
| rdx (data register) | x64에서는 주된 용도 없음 |
| rsi (source index) | 데이터를 옮길 때 원본을 가리키는 포인터 |
| rdi (destination index) | 데이터를 옮길 때 목적지를 가리키는 포인터 |
| rsp (stack pointer) | 사용중인 스택의 위치를 가리키는 포인터 |
| rbp (stack base pointer) | 스택의 바닥을 가리키는 포인터 |
- **세그먼트 레지스터(Segment Register)**: 과거에는 메모리 세그멘테이션이나, 가용 메모리 공간의 확장을 위해 사용됐으나, 현재는 주로 메모리 보호를 위해 사용되는 레지스터 x64에는 *cs, ss, ds, es, fs, gs*가 있다.
- **플래그 레지스터(Flag Register)**: CPU의 상태를 저장하는 레지스터
- **명령어 포인터 레지스터(Instruction Pointer Register, IP):** CPU가 실행해야할 코드를 가리키는 레지스터. x64에서는 *rip*가 있다.