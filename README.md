# ton (STM32F103 工程模板)

本项目是一个基于 STM32F103 系列微控制器（STM32F103C8T6）的基础工程模板，使用 STM32 HAL 库进行开发。该模板已经包含了一些常用的外设驱动（BSP），方便在后续开发中快速搭建和调试基于 STM32 的硬件应用。

## ?? 开发环境

- **微控制器**: STM32F103C8T6
- **固件库**: STM32F1xx HAL Driver
- **配置工具**: STM32CubeMX 
- **开发IDE**: Keil MDK-ARM v5

## ? 已支持的外设驱动 (BSP)

在 `Template/BSP/` 目录下，目前已预置并包含了以下板级支持包模块：
- **LED控制**: 基础的 LED 状态控制与翻转 (`led.c`, `led.h`)
- **OLED显示**: OLED 屏幕显示驱动，支持基础字符显示 (`oled.c`, `oled.h`, `oled_font.h`)
- **舵机控制**: 利用 PWM 信号控制舵机角度 (`servo.c`, `servo.h`)

## ? 硬件连接与系统架构

- **语音控制 (ASR PRO)**: STM32 与语音模块（ASR PRO）之间通过 **两个 HC-05 蓝牙模块** 进行无线串口透传通信。用户可以通过语音模块识别指令，借由蓝牙串口发送到 STM32 进行解析和执行相应操作。

## ?? 目录结构

```text
├── Template/
│   ├── Core/              # 存放主函数及 HAL 库初始化的各项外设代码 (GPIO, TIM, USART等)
│   ├── BSP/               # 用户自定义的板级支持包 (引脚外设等驱动模块)
│   ├── Drivers/           # CMSIS 及 STM32F1xx HAL 库底层源码
│   ├── MDK-ARM/           # Keil MDK 工程相关文件所在目录 (包含 .uvprojx 工程文件)
│   └── Template.ioc       # STM32CubeMX 工程配置文件，可用于重新配置引脚与时钟
└── README.md              # 项目工程说明文档
```

## ? 使用说明

1. 推荐双击使用 Keil MDK-ARM 打开目录中的 `MDK-ARM/Template.uvprojx`。
2. 若需更改芯片的引脚分配、外设或时钟树，可以使用 STM32CubeMX 打开 `Template.ioc` 文件并重新生成代码。
3. 扩展应用可以直接在 `BSP/` 文件夹中添加新的自己编写的传感器/模块驱动，然后在主程序中进行调用。
