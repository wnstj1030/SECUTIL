### 오늘은?😃
오늘은 AWS에서 EC2 인스턴스를 생성해보고, 다음에 EC2에 DVWA(모의해킹 웹 서버) 설치까지 해보려고 한다

일단 오늘은 인스턴스 생성까지만 할거다

### EC2?
<aside>
💡 EC2는 Amazon Elastic Compute Cloud의 약자로
클라우드에서 확장 가능한 컴퓨팅 용량을 제공한다.


</aside>

우리는 돈이 들지 않는 **Free Tier**를 사용할 예정이다

### 인스턴스 생성
먼저 AWS사이트에 들어가서

![](https://velog.velcdn.com/images/wnstj1030/post/9cf29939-6fad-4c97-80ad-3287b50ac9c5/image.png)

로그인을 하면 뜨는 이 창에서 EC2에 들어가준다

그 다음

![](https://velog.velcdn.com/images/wnstj1030/post/8d4a86fe-6524-4e3d-9d8f-46e6dbd2b918/image.png)


인스턴스를 눌러준 뒤

![](https://velog.velcdn.com/images/wnstj1030/post/086e43bb-3647-45f6-a378-2c19bb2138c6/image.png)


오른쪽 상단에 인스턴스 시작을 눌러준다 

![](https://velog.velcdn.com/images/wnstj1030/post/20cb230a-4070-4bdd-a056-69674c0a141c/image.png)


인스턴스의 이름을 정해주고 난 뒤에

DVWA를 설치하기 위해 Ubuntu 18.04를 선택해준다

![](https://velog.velcdn.com/images/wnstj1030/post/68a5ad94-1876-435e-afd8-9b37c67b717a/image.png)


### 인스턴스 유형 설정
![](https://velog.velcdn.com/images/wnstj1030/post/03be08a2-a28f-4c79-8396-a49cdd084876/image.png)


인스턴스 유형은 t2.micro로 설정해준뒤 (Free Tier 사용 가능)

![](https://velog.velcdn.com/images/wnstj1030/post/0814e39a-8e31-435d-8cc5-4b6c80b811c1/image.png)


### Key Pair
키페어는 무조건 생성해줘야 한다

![](https://velog.velcdn.com/images/wnstj1030/post/30d96656-a8f4-43e8-b40f-2b1656b696ae/image.png)


PuTTY에서 사용할 예정이기 때문에 .ppk 형태로 key를 저장해준다

### 보안그룹
보안그룹에서 22번 포트가 0.0.0.0/0으로 설정되어있는 보안그룹을 선택해준다
(22번포트 = SSH접속을 하기 위한 포트 번호)

![](https://velog.velcdn.com/images/wnstj1030/post/f765c36b-e63e-4060-b03c-7fe5f4499c07/image.png)


여기까지 설정이 끝났다면 인스턴스 시작을 눌러주자!

![](https://velog.velcdn.com/images/wnstj1030/post/334a5887-b218-4dd0-b514-dd0c3f63c752/image.png)


다시 인스턴스로 가서 이렇게 아래 사진처럼 됐다면 잘 만들어 진 것이다

![](https://velog.velcdn.com/images/wnstj1030/post/b516a36a-e889-499f-be6b-7b4fcdfd3bbf/image.png)

