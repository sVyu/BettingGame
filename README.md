# BettingGame (with C)

### Source  : sVyu/BettingGame/BettingGame/source.c
### exe &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;: sVyu/BettingGame/BettingGame.exe
[notice] exe 파일 실행 시 exe 파일이 속한 폴더에 점수 기록을 위한 BettingGameRecord.txt 1회 자동 생성 📄
<br/>
<br/>
    
<span style="color:#d62976">update : source error fixed (2023/03/29)</span>  
2015년(1학년) 2학기 프로그래밍응용 강의 중 과제로 만들었던 생애 <span style="color:#d62976">첫 프로그래밍 프로젝트</span> 😊  
자유주제였기에 계속 어떻게 만들까 고민하면서 3 ~ 4일 동안 집중적으로 만들었던 기억이 납니다  
<br/>
<p align="center">
    <img src="https://drive.google.com/uc?export=view&id=1C9aJDgrPh4elfJQbZcA5jp_sIsuMMpsh" width="90%" height="90%">
</p>
<br/>
  
최신 버전의 소프트웨어는 불안정한 요소가 있기에 2015년 기준으로 visual studio 2013 근처 버전으로 사용했습니다  
최근에 visual studio 2017/2019로 확인해보니 파일의 텍스트 배열이 다 안 맞게 보이기에 수정했습니다  
요인 : 특정 특수문자의 길이가 전보다 짧게 보입니다 (ㅂ + 한자 + 1 == '─')

<br/>
[[ 수정 전 ]]
<p align="center">

<img src="https://drive.google.com/uc?export=view&id=1OA8r442ZESqNcaunlHidxtqeomYMF4t5" width="90%">
<img src="https://drive.google.com/uc?export=view&id=1BDbiGaP0pjBoNnr3kG-8rB8bJwh4p-5B" width="90%">
<img src="https://drive.google.com/uc?export=view&id=14jNn4dDc_ofvpB7_YStFq8DobxWRQneK" width="90%">
    
</p>
<br/>
  
[[ 수정 중 ]]  
C++ 버전을 17로 맞춘 후에 <span style="color:#d62976">foepn → fopen_s, fscanf → fscanf_s 와 같은 _s 함수들 처리 및 인터페이스 알맞게 수정</span>
<p align="center">
<img src="https://drive.google.com/uc?export=view&id=1x8R9oNYRPliYCWVe9EAvVWXuf_5ljGdf" width="90%">
<img src="https://drive.google.com/uc?export=view&id=1EQsQIuRO5Gb4vNiLVqg5h7zmPwFwjVKl" width="90%">
<img src="https://drive.google.com/uc?export=view&id=1hl5EsixItoAO_43fh4m-pm4CSdnoMRdW" width="90%">
<img src="https://drive.google.com/uc?export=view&id=1y25lHUF9oZwPc97FxeXnG_cDv5MUTjRA" width="90%">
</p>
<br/>

[[ 수정 후 ]]  
<p align="center">
<img src="https://drive.google.com/uc?export=view&id=1ODt1674MpL0EuOEW1tSSIzRun1dALoyh" width="90%">
<img src="https://drive.google.com/uc?export=view&id=1hVSp2IhjOL0YAzAoZfIQWxY3Nz98_GWR" width="90%">
<img src="https://drive.google.com/uc?export=view&id=1-wf0YM23yvOupUmy35uYRGsTyiibmjsj" width="90%">
<img src="https://drive.google.com/uc?export=view&id=1ZaoHp_mqtxc3Iiq_igSbrcwg3LbL6kMX" width="90%">
<img src="https://drive.google.com/uc?export=view&id=1sWXDEKsd6-Wiw_7vhkGz8Kk2N2ipsxCR" width="90%">
<img src="https://drive.google.com/uc?export=view&id=16_mOJEw0iLCcYuAEn-g0bGLQPNL3lxfD" width="90%">
<img src="https://drive.google.com/uc?export=view&id=1EkLQfCbVjGXnrqvn-Zqe_5Qeg-QpkHs6" width="90%">
<img src="https://drive.google.com/uc?export=view&id=1QKd0tkIff4BUi-OiE8rGqVq_y9nbPASe" width="90%">
<img src="https://drive.google.com/uc?export=view&id=1vtkWX_O2As-vGNRKkIdUvj4MB-ZCFt_U" width="90%">
<img src="https://drive.google.com/uc?export=view&id=1glG1MXI7nmRHE47Un_p9Cxu76sz_mku9" width="90%">
<img src="https://drive.google.com/uc?export=view&id=1H3GZeIv69Ur5_dl_h67_R9NuDsyt3OZY" width="90%">
<img src="https://drive.google.com/uc?export=view&id=1L8htlTlsdgAzgVbR75p5R21UPlz0SKaQ" width="90%">
<img src="https://drive.google.com/uc?export=view&id=1OslpXWPIs_jTwTesgXOP36AtR8hEP7sk" width="90%">
<img src="https://drive.google.com/uc?export=view&id=1DHGGe_CPPg7NRWiFtaxOxfzV1fYeacjI" width="90%">
<img src="https://drive.google.com/uc?export=view&id=1NIK4N5bPoJckK5FeRo20UQOChumpm9dq" width="90%">
<img src="https://drive.google.com/uc?export=view&id=1Qmty2d4i8x2WOv__227HsAPd2iJNgsGr" width="90%">
<img src="https://drive.google.com/uc?export=view&id=1dHaq8SOl5PkvRCHwctuYqqc_rAYxT4ti" width="90%">
<img src="https://drive.google.com/uc?export=view&id=1JFp6lYeqPGVeHfBGw7fEBbcCiIOAeO_H" width="90%">
<img src="https://drive.google.com/uc?export=view&id=1rQi2IGI1lU7F6LAGYCUBHcJtKY25b3KM" width="90%">
<img src="https://drive.google.com/uc?export=view&id=1cPimmHednkWbvAH8WtgNgGLdsu5LWKGh" width="90%">
<img src="https://drive.google.com/uc?export=view&id=1G925CN7kYdm9fIj-VllztBRQPuOr_vPg" width="90%">
<img src="https://drive.google.com/uc?export=view&id=1ZlwitrcmTBjFuoNdIdVbApiBqEWwd3_m" width="90%">
<br/>
<br/>
</p>
  

[참고]  
visual studio 내 c++ 버전 변경
- https://hwan-shell.tistory.com/209

fopen_s
- https://ehpub.co.kr/fopen_s-%ED%95%A8%EC%88%98/
- https://learn.microsoft.com/ko-kr/cpp/c-runtime-library/reference/fopen-s-wfopen-s?view=msvc-170

fscanf_s
- https://gonyzany.tistory.com/175
- https://mooyou.tistory.com/6

strncpy_s
- https://learn.microsoft.com/ko-kr/cpp/c-runtime-library/reference/strncpy-s-strncpy-s-l-wcsncpy-s-wcsncpy-s-l-mbsncpy-s-mbsncpy-s-l?view=msvc-170
- https://ehpub.co.kr/strncpy_s-%ED%95%A8%EC%88%98/

에러 문구 (VS ERROR C4477 : *형식의 인수가 필요하지만 variadic 인수 1의 형식이 *입니다.)
- https://pang2h.tistory.com/124

exe 파일 만들기 (Debug → Release)(새로운 오류 다수 발생해서 처리)
- https://blog.naver.com/chunsh10/221362267892
- https://codingboycc.tistory.com/51

exe 파일 아이콘 바꾸기(Debug로만 적용 가능했음)  
(즉, 소스가 잘 돌아갈 수 있게 Release로 오류를 다 체크하고 debug로 아이콘 적용된 exe파일 생성을 권장)
- https://sorceryforce.net/ko/tips/visual-studio-execute-file-icon-change
- https://lopicit.tistory.com/410
- https://zzoyu.tistory.com/71

아이콘으로 쓸 파일 이미지(png)(→ ico로 변환 필요)
- https://www.flaticon.com/free-icon/rubik_2157113

png → ico 변환
- https://convertio.co/kr/download/8935321530f64871abe3eb3bc5d9110cf3a3f9/