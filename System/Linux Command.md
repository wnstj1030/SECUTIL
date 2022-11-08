# **명령어(command)**

모든 명령어는 명령어 뒤에 --help 옵션을 주면 자세한 사용 방법이 나온다.

예를들어 ls 명령어의 자세한 사용 방법과 모든 옵션을 알고싶으면 ls –help를 입력하면 된다.

## **cd**

**cd (change directory)**

해당 디렉토리로 이동하는 명령어이다. 만약 해당 디렉토리가 있다면 해당 디렉토리로 이동을 하지만 없다면 다음과 같이 에러 메시지를 출력한다.

—>

`-bash: cd: directory: No such file or directory`

cd ..

—>

현재 디렉토리에서 상위 디렉토리로 이동하게 된다.

전에 있었던 디렉터리로 이동하고 싶은 경우 이동하려는 해당 디렉토리의 경로를 입력할 필요 없이 아래와 같은 방법을 이용하면 된다.

`cd -`

## **pwd**

**pwd (print working directory)**

현재 작업중인 디렉토리 정보 출력

—>

`$ pwd
/home/wnstj`

## **ls**

**ls(list)**

디렉토리 목록 확인

—>

```
$ ls
testfile1  testfile2  testfile3
```

## **cp**

**cp(copy)**

파일 혹은 디렉토리를 복사

```
$ ls
testdir/  testfile

$ cp testfile1 testfile_cp
$ ls
testdir/  testfile  testfile_cp$ cp -r testdir testdir_cp
$ ls
testdir/  testdir_cp/  testfile  testfile_cp

```

디렉토리를 복사할때는 -r 옵션을 주어야함

```
$ cp -r testdir testdir_cp
$ ls
testdir/  testdir_cp/  testfile  testfile_cp
```

## **mv**

**mv(move)**

파일 혹은 디렉토리 이동

*실제로 원하는 위치로 이동할때도 사용하지만, 이름을 변경하는 용도로도 사용한다.

cp와는 달리 디렉토리를 이동할때도 별다른 옵션이 필요 없다.

`$ ls
testdir/  testfile

$ mv testfile testfile_mv
$ ls
testdir/  testfile_mv

$ mv testfile_mv testdir/
$ ls
testdir/

$ ls testdir/
testfile`

## mkdir

**mkdir(make directory)** 

디렉토리 생성

```
$ ls
testfile

$ mkdir testdir
$ ls
testdir/  testfile
```

## rm

**rm(remove)**

파일이나 디렉토리를 삭제한다.

-f를 쓰면 삭제 여부를 묻지않고 삭제한다.

```
	$ ls
testdir/  testfile1  testfile2

$ rm -f testfile1
$ ls
testdir/  testfile2

$ rm -rf testdir/
$ ls
testfile2
```

## **cat**

**cat (concatenate)**

단순히 파일의 내용을 출력하기도 하고, 파일 여러개를 합쳐서 하나의 파일로도 만들 수 있다.