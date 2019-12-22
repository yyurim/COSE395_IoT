# COSE395_IoT

고려대학교 컴퓨터학과 사물인터넷설계(COSE395)의 프로젝트입니다.

## Christmas Project

<img width="512" alt="image" src="https://user-images.githubusercontent.com/47660338/71325052-96f95c00-252a-11ea-96ea-f12775196f77.png">

### 어떤 프로젝트인가
크리스마스를 보내는 장소에 적절한 분위기 조성

### 프로젝트 선정 이유
곧 다가올 크리스마스

### 가정사항
조용한 집 또는 시끌시끌한 파티룸 
다양한 LED 색
많은 노래

## 통신 방식
리모컨과 IR센서를 이용한 적외선 통신

## 센서 및 제어 정보
고감도 사운드 감지 센서 / BUZZER & LED

## References

1. 크리스마스 캐럴 노트 및 박자
https://create.arduino.cc/projecthub/joshi/piezo-christmas-songs-fd1ae9

2. 1열 7세그먼트 LED 제어 방법
http://blog.daum.net/_blog/BlogTypeView.do?blogid=02XGV&articleno=13720483

3. COSE395 강의 자료

차이점
    1. 주어진 NOTES와 DURATION을 이용하여 리모콘을 통해 제어
	2. 노래가 끝나고 별다른 조작이 없다면 이전 노래를 반복 재생
	3. 박자에 맞춰 LED 점등