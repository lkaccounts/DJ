# Solar Inspection System

基于DJI Edge SDK的太阳能电站巡检系统。

## 功能特点

- 基于DJI Edge SDK的无人机控制
- 实时视频流处理
- AI缺陷检测
- 数据记录与分析
- 自动化巡检路径规划

## 系统要求

- Ubuntu 20.04或更高版本
- CMake 3.10或更高版本
- OpenCV 4.x
- spdlog
- Catch2 (用于测试)
- DJI Edge SDK

## 快速开始

### 1. 安装依赖

```bash
sudo apt-get update
sudo apt-get install build-essential cmake libopencv-dev libspdlog-dev catch2
```

### 2. 编译项目

```bash
mkdir build && cd build
cmake ..
make
```

### 3. 运行测试

```bash
make test
```

### 4. 运行程序

```bash
./src/solar_inspection
```

## 项目结构

```
solar-inspection/
├── src/
│   ├── ai/          # AI检测模块
│   ├── control/     # 无人机控制模块
│   ├── utils/       # 工具类
│   └── video/       # 视频处理模块
├── include/         # 头文件
├── tests/          # 测试文件
└── docs/           # 文档
```

## 开发流程

请参考以下文档：
- [分支管理策略](docs/project-management/BRANCHING_STRATEGY.md)
- [代码审查流程](docs/project-management/CODE_REVIEW.md)
- [发布流程](docs/project-management/RELEASE_PROCESS.md)

## 贡献指南

1. Fork 项目
2. 创建特性分支 (`git checkout -b feature/AmazingFeature`)
3. 提交更改 (`git commit -m 'Add some AmazingFeature'`)
4. 推送到分支 (`git push origin feature/AmazingFeature`)
5. 开启 Pull Request

## 许可证

[MIT License](LICENSE)

## 联系方式

- 项目团队：Solar Inspection Team
- 邮箱：team@solar-inspection.com