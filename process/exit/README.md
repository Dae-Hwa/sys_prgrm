기본적으로 0은 성공 1은 실패이다. `<stdlib.h>` 에는 상수 `EXIT_FAILURE` 와 `EXIT_SUCCESS` 가 정의되어 있다.
프로세스 종료에는 exit이 필요하기 때문에 우리가 만든 main 메소드 이후에도 exit이 실행되어야 한다.
main 메소드는 _start 라는 메소드 내부에서 호출되고, _start 메소드는 main 메소드가 return되면 exit을 실행한다.

exit 내부에는 종료 시 할 작업을 등록할 수 있다.
atexit 를 이용하면 되는데, stack 형식으로 작동한다.
> 가장 최근에 등록한 작업 순으로 실행된다.