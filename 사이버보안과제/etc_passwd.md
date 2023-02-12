각 필드들이 의미하는 바가 있는데, 필드 하나하나 무엇을 의미하는지 확인해봅시다. 각 필드는 콜론(:)으로 구분 되어진다

`root:x:0:0:root:/root:/bin/bashroot:x:0:0:root:/root:/bin/bash`

| 필드 | 설명 |
| --- | --- |
| 사용자 계정명 | 맨 앞에 필드는 사용자의 계정명을 나타낸다 |
| 패스워드 | 그 다음의 필드는 패스워드 필드인데, x가 의미하는 바는 사용자의 패스워드가 /etc/shadow에 암호화되어 저장되어있다는 뜻이다 |
| UID | 사용자의 user id를 나타낸디 관리자 계정(Root)은 UID가 0이다 |
| GID | 사용자의 그룹 ID를 나타냅니다. 관리자 그룹(Root)의 GID는 0이다 |
| comment | 사용자와 관련한 기타 정보로 일반적으로 사용자의 이름을 나타낸다 |
| 홈 디렉토리 | 사용자의 홈디렉토리를 의미한다. 관리자 계정의 홈 디렉토리는 /root이며, 다른 사용자의 홈 디렉토리는 기본으로 /home/ 하위에 계정명으로 위치한다 |
| 로그인 쉘 | 사용자가 로그인시에 사용할 쉘을 의미한다<br>보통 사용자의 쉘은 성능이 우수한 bash쉘을 사용힌다<br>또 로그인이 불필요한 계정도 있는데<br>이때는 이 필드가 /usr/sbin/nologin, /bin/false, /sbin/nologin 등으로 표기된다 <br>이것은 사용자가 아니라 어플리케이션이기 때문이다 
아래처럼 말이다 |

sshd:x:126:65534::/run/sshd:**/usr/sbin/nologin**<br>
gnome-initial-setup:x:124:65534::/run/gnome-initial-setup/:**/bin/false**
gdm:x:125:130:Gnome Display Manager:/var/lib/gdm3:**/bin/false**