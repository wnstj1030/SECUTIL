SSH 접속이 된 상태의 PuTTY 환경에서 진행하였다

![](https://velog.velcdn.com/images/wnstj1030/post/4a742f0e-59c2-4444-9fb7-70b20af5ab30/image.png)


PuTTY로 여기까지 하였다면 su를 사용하여 root계정으로 접근해준다
### Git Clone
그리고

```bash
git clone https://github.com/ghkdtlwns987/S-W
```

를 쳐준다(DVWA(웹 모의해킹 서버)설치를 위한 쉘스크립트가 있다)

그리고

```bash
scripts/2/dvwa_install.sh
```
### shell script 실행
위 경로로 가서  

```bash
sh dvwa_install.sh
```

를 해준다

![](https://velog.velcdn.com/images/wnstj1030/post/f9580b2b-4955-4c2b-87d7-75cd8747dfd1/image.png)


그리고 설치가 다 되었다면
### 확인하기
http:/public_DNS(자신의 퍼블릭 도메인)

으로 접속을 하면 

![](https://velog.velcdn.com/images/wnstj1030/post/94e0b857-2f7d-49fc-91ee-8a8df3eca018/image.png)


설치가 잘되었다면 이렇게 접속이 된다
### 안되면?
만약 안된다면?

- http 포트가 열어졌는지 확인하기