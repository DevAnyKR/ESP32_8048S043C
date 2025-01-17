# ESP32-8048S043C

ESP32 + TFT-LCD + Touch Panel + SD Slot 등이 모두 내장된 개발 보드입니다.

Arduino IDE는 컴파일 속도가 매우 느리고, 라이브러리 설정이 복잡하며 다른 프로젝트와 호환되지 않습니다.
그외 여러가지 이유로 Arduino IDE는 개발하기 불편한 환경입니다.

PlatformIO IDE에서 사용할 수 있도록 재구성하였습니다.

### 보드 구입하기

- [AliExpress Store 1](https://s.click.aliexpress.com/e/_okKUXX7)


- USB: C Type
- Display: 800x480 ST7262
- Touch: GT911

# LVGL, LovyanGFX 라이브러리 사용 방법
## 새 프로젝트일 때
platformio.ini 파일을 열고
`src_dir =` 줄을 모두 주석으로 변경하거나 삭제합니다.

`.\src\` 위치에서 프로젝트 코드 작성을 시작하세요.

LVGL 설정을 변경하려면 `.\include\lv_conf.h` 파일을 편집하세요.

## Main Libraries
- [LVGL](https://github.com/lvgl/lvgl)
- [LovyanGFX](https://github.com/lovyan03/LovyanGFX)
  

## References
- https://github.com/clumsyCoder00/Sunton-ESP32-8048S043

## License
MIT
