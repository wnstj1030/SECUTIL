```bash
#!/bin/bash

mkdir -p ./result

for var in *.c
do
    echo `gcc -o ./result/${var%.c} $var`
    gcc -o ./result/${var.c}
done
```
result 디렉토리를 만들어 존재하는 c파일들을 컴파일하여 결과값을 넣어준다