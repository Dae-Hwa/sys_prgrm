# exec
`exec()`는 현재 프로세스 공간에 새로운 프로세스를 덮어씌우는 것이다.

종류가 총 6개 있다.
```c
#include <unistd.h>

extern char **environ;

// 전체경로 사용
int execl(const char *pathname, const char *arg, ... /* (char  *) NULL */);
// 환경변수 사용
int execlp(const char *file, const char *arg, ... /* (char  *) NULL */);
// 환경변수 정의해서 사용
int execle(const char *pathname, const char *arg, ... /*, (char *) NULL, char *const envp[] */);
// 전체 경로 사용
int execv(const char *pathname, char *const argv[]);
// 환경변수 사용
int execvp(const char *file, char *const argv[]);
// 환경변수 정의해서 사용
int execvpe(const char *file, char *const argv[], char *const envp[]);
```

`pathname` 혹은 `file` 에는 실행시킬 프로세스가 들어간다. 환경변수를 사용할 경우 경로가 아닌 해당 파일명만 지정해주면 된다.
> execvp.c 참조

`arg` 에는 해당 실행파일의 인자를 넣어주면 된다. 예를 들어 `ls` 를 실행 시킬 경우 `-l` 과 같은 명령어를 넣어주면 된다. 가변변수를 사용하기 때문에 필요한 경우 명령어를 계속해서 넣어주면 된다. 
> 이름에 v가 들어간 경우 가변변수 대신 배열을 매개변수로 사용한다. 두 가지 모두 마지막에는 `NULL` 이 들어가야 한다.

`exec()` 만 사용되기 보다는 `fork()` 를 한 자식 프로세스에서 `exec()` 를 실행시키는 방식으로 사용된다. 그렇게 되면 자식 프로세스에서 원하는 프로그램을 실행시킨 것과 같은 동작이 된다.