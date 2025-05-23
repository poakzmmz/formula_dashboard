CubeIDE 기준
- 📁 CM4
  - 📁 Core

- 📁 CM7
  - 📁 Core
    - 📝 main.c                        #  메인 진입점, 태스크 생성 위치
  - 📁 gui
    - 📝 Model.cpp                     #  TouchGFX 모델 로직 (tick 함수 포함)
    - 📝 Screen1Presenter.cpp          #  Presenter 계층
    - 📝 Screen1View.cpp               #  View(UI) 계층
    - 📝 FrontendApplication.cpp       #  화면 전환 및 TouchGFX 엔트리포인트

TouchGFX_Task(void *argument)
TouchGFX UI 렌더링, 이벤트 처리, 애니메이션

Start_Gear_detect(void *argument)
기어 업/다운 또는 클러치 관련 외부 입력을 감지
 - osMessageQueuePut(gearStateQueueHandle, &gearState, 0, 0);  <- 계산 후 gearStateQueue 에 Put

