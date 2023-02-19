### **오늘은?**
오늘은 저번에 한 [AWS EC2 생성해보기(for DVWA)](https://velog.io/@wnstj1030/AWS-EC2-%EC%83%9D%EC%84%B1%ED%95%B4%EB%B3%B4%EA%B8%B0for-DVWA)에 이어서 생성한 다음 SSH로 접속하기를 해보겠다
### **인스턴스 확인**
![](https://velog.velcdn.com/images/wnstj1030/post/557314d9-28e7-4da6-9163-f0ee055b2214/image.png)

### **보안그룹 설정**
인스턴스가 실행중인 상태에서 
처음으로 생성한 인스턴스라면 보안그룹에서 네트워크를 허용해주어야한다
![](https://velog.velcdn.com/images/wnstj1030/post/6da942e4-c381-4268-b974-e63691c5193f/image.png)

### **인바운드 규칙 편집**
보안그룹을 클릭한 뒤 인바운드 규칙 편집을 클릭해준다
그리고 인바운드 규칙을 다음과 같이 설정해준다
(기존의 SSH연결을 열려있었으므로 웹으로 접속하기 위해 HTTP(80번)포트도 열어준다)
![](https://velog.velcdn.com/images/wnstj1030/post/584f584e-12d9-4c10-8701-9ed24ede0d1a/image.png)


규칙 추가를 눌러 규칙을 생성해주면 된다

다 됐다면 인스턴스로 돌아가보자

인스턴스로 돌아가면 퍼블릭 DNS,IP가 생성되어있는 것을 확인해 볼 수 있다
### **PuTTY로 SSH 접속**
그러면 이제 SSH접속을 해보자

나는 PuTTY를 사용하였다

PuTTY를 켜준다음 

![](https://velog.velcdn.com/images/wnstj1030/post/c403b124-dfbf-46bc-a1f1-46b28b01073a/image.png)


이 화면에서 Host Name에 퍼블릭 DNS를 쳐주고 

Data에 가서 username을 입력해준다

![](https://velog.velcdn.com/images/wnstj1030/post/3a8b8d45-6710-40cc-8353-8f3d25dbdac5/image.png)


그리고 SSH의 Auth의 Credentials에서 .ppk형태의 key를 가져와준다

![](https://velog.velcdn.com/images/wnstj1030/post/d3502e5b-86a5-4548-b3c9-aff3e5cbf619/image.png)


그리고 다시 session으로 돌아가서 save를 눌러준 뒤 Open을 해준다

![](https://velog.velcdn.com/images/wnstj1030/post/37401979-9352-41c2-a519-8884e44b6025/image.png)


이 창이 뜨면 ubuntu로 login해주고

sudo passwd로 passwd를 지정해준다 

그러면 끝!