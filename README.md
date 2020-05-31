# preshoes-shoes
Preshoes - ESP-32S 센서 모듈

[Preshoes](https://github.com/WBPBP/preshoes-docs)의 일부인 센서 노드 측 ESP-32S 소스코드입니다.

`Reader`와 `Transmitter`로 이루어집니다.

## Reader

센서로부터 값을 읽고 가공하여 `transmitter`에게 보냅니다.

## Transmitter

블루투스 시리얼 모듈처럼 기능합니다. 전달받은 값을 휴대전화로 전송합니다.