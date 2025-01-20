# ESP32-8048S043C

ESP32 + TFT-LCD + Touch Panel + SD Slot 등이 모두 내장된 개발 보드입니다.

Arduino IDE는 컴파일 속도가 매우 느리고, 라이브러리 설정이 복잡하며 다른 프로젝트와 호환되지 않습니다.
그외 여러가지 이유로 Arduino IDE는 개발하기 불편한 환경입니다.

PlatformIO IDE에서 사용할 수 있도록 재구성하였습니다.

![image](https://github.com/user-attachments/assets/46ddff28-963c-4199-ac4e-7ef891369c44)

### 보드 구입하기

- [AliExpress Store 1](https://s.click.aliexpress.com/e/_okKUXX7)

### 사양

- USB: C Type
- Display: 800x480 ST7262
- Touch: GT911

## PlatformIO 설정
### 빌드할 소스 폴더 변경하기
platformio.ini 파일을 열고
`src_dir =` 줄을 모두 주석으로 변경하거나 삭제합니다.

`.\src\` 위치에서 프로젝트 코드 작성을 시작하세요.

LVGL 설정을 변경하려면 `.\include\lv_conf.h` 파일을 편집하세요.

## References
- [LVGL](https://github.com/lvgl/lvgl)@^9.2
- [platform-espressif32](https://github.com/pioarduino/platform-espressif32)@^3
- [Arduino GFX](https://github.com/moononournation/Arduino_GFX/)@^1.5
- [GT911 Arduino](https://github.com/TAMCTec/gt911-arduino)@^1
- [eez-framework](https://github.com/eez-open/eez-framework)

## License
MIT
