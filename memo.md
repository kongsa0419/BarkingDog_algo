# [오답노트]

## BFS
+ fill(); 
    + 배열 초기화 시 map[][]를 전역변수로 두는 경우가 많은데, 이때 TC>=2 인 경우엔 init()과정이 필요함. 
    + init() 과정에서 배열의 크기 (n x m)이라면 fill(map[i],map[i]+n, 0) --> fill(map[i],map[i]+1005,0)
    + TC마다 n을 초기화해줘서 무효값이 될 수 있음 <-- fill(map[i], map[i]+0, 0); 식으로...

+ {'#', '*', '0', '.'} 등의 문자열을 처리해야하는 경우
    + map[i][j] - '0' + 1 (0)
    + map[i][j] + 1       (X)
    + 처럼 되도록해야 == 연산에서 오류를 피할 수 있을듯(0-1-2-3...255-256 중에 저 특수문자 있음)

+ BFS시, queue에 I/O 연산 횟수를 줄이는 것이 문제의 pass/fail을 결정함

+ 빡빡한 문제일 경우, 처음 dist[][][]를 초기화하는 연산때문에도 pass/fail이 갈리기도 함.
+ 원래 일반(4) + 뚫는경우(4) 총 8번의 방향처리를 해줬더니 틀렸음. 일반 방향 처리(4)번의 연산만으로도 뚫을 경우를 처리할 수 있음.
    + 막혀있으면 뚫는다. 안막혀있으면  안뚫는다.


## 문자열 입력(coding test 전용)
+ C++ string vs C string
    + NULL '\n' 문자의 포함 여부 (C는 포함, C++은 미포함)
    + 그 외에도 C++의 string이 훨씬 유연하나, C는 속도가 더 빠름

### <istream> cin(), <istream> cin.getline(), <string> getline();
+ cin() : '\n' 개행문자 이전까지만 읽어들임. 개행문자는 버퍼에 쌓임. (cin.ignore()로 제거)
+ cin.getline(변수주소 char* s, 입력개수 n, delim '\n'):
    + C형식 문자열 입력 ('\n'까지도 포함해서 입력받음)
    + 사실상 n-1개 입력(개행문자 포함 n개 이므로)
    + 구분자 생략시 '\n'
+ getline(입력 스트림 isteam& stream, string str, char delim);
    + delim 전까지의 문자열을 str에 할당해줌.
+ ETC.
    + cin.clear()는 버퍼를 지워주는게 아니라 fail bit등 내부 상태플래그를 초기화시켜주는 함수임.
        + cin.fail()과 묶어서 쓰인다고 함.
    + cin.ignore(int n, char delim); 으로 버퍼를 지워줄 수 있음. 
        + cin.ignore()로 버퍼를 완전 다 날릴 수 있음.

