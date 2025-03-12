# DJI Edge SDK 开发指南

## 项目概述

DJI Edge SDK 是一个用于边缘计算的软件开发工具包，专门设计用于 DJI 无人机系统。该 SDK 提供了丰富的功能接口，包括实时视频流处理、媒体文件管理、云服务通信等。

## 架构设计

- 使用 C++ 编写，采用现代 C++ 特性
- 模块化设计，各个功能模块独立
- 使用单例模式管理关键组件
- 提供清晰的错误处理机制

## 核心功能模块

### 1. 初始化模块 (Init)

初始化模块负责 SDK 的基本配置和环境准备：

- 设备信息管理（产品名称、版本等）
- 应用授权验证
- 日志系统配置
- 密钥管理

示例代码：
```cpp
Options option;
option.product_name = "Edge-1.0";
option.vendor_name = "Vendor";
option.serial_number = "SN0000100010101";
option.firmware_version = {0, 1, 0, 0};

// 初始化 SDK
auto rc = ESDKInit::Instance()->Init(option);
```

### 2. 实时视图模块 (Liveview)

支持多种视频源和格式的实时视频流处理：

#### 摄像头类型
- FPV 摄像头
- 负载摄像头 (Payload)

#### 镜头类型
- 广角镜头 (Wide)
- 变焦镜头 (Zoom)
- 红外镜头 (IR)

#### 视频质量选项
- 540p (30fps, 960×540, 512Kbps)
- 720p (30fps, 1280×720, 1Mbps)
- 720p High (30fps, 1280×720, 1.5Mbps)
- 1080p (30fps, 1920×1080, 3Mbps)
- 1080p High (30fps, 1920×1080, 8Mbps)

示例代码：
```cpp
// 创建实时视图实例
auto liveview = CreateLiveview();

// 配置选项
Liveview::Options options;
options.camera = Liveview::kCameraTypePayload;
options.quality = Liveview::kStreamQuality1080p;
options.callback = H264StreamCallback;

// 初始化
liveview->Init(options);
```

### 3. 媒体管理模块 (MediaManager)

提供媒体文件的管理功能：

- 媒体文件读取和观察
- 云端上传控制
- 本地文件管理
- 自动删除策略

示例代码：
```cpp
auto mediaManager = MediaManager::Instance();

// 创建媒体文件读取器
auto reader = mediaManager->CreateMediaFilesReader();

// 配置云端上传
mediaManager->SetDroneNestUploadCloud(true);
mediaManager->SetDroneNestAutoDelete(false);
```

### 4. 云 API 模块 (CloudAPI)

提供与云服务的双向通信功能：

- 自定义消息发送和接收
- 实时事件通知
- 服务调用

消息格式：
```json
{
    "method": "custom_data_transmission_to_esdk",
    "timestamp": xxxxxxxxxx,
    "bid": "xxxxxxxx-xxxx-xxxx-xxxx-xxxxxxxxxxxx",
    "tid": "xxxxxxxx-xxxx-xxxx-xxxx-xxxxxxxxxxxx",
    "data": {
        "value": "xxxx"
    }
}
```

示例代码：
```cpp
// 注册消息处理器
CloudAPI_RegisterCustomServicesMessageHandler(MessageHandler);

// 发送消息到云端
uint8_t message[] = "message from edge sdk";
CloudAPI_SendCustomEventsMessage(message, sizeof(message));
```

## 高级特性

### 1. 视频处理架构

- FFmpeg 视频解码
- 多种图像处理器支持
- YOLOv-fastest 目标检测集成
- 线程安全的处理队列

### 2. 线程管理

- 独立的视频流处理线程
- 线程安全的消息队列
- 优雅的启动和停止机制

### 3. 错误处理

统一的错误码系统，包括：
- 参数验证错误
- 系统错误
- 网络通信错误
- 认证和加密错误
- 视频流相关错误

### 4. 安全特性

- 应用授权验证
- 密钥管理
- 加密通信
- 安全的云端通信

## 最佳实践

1. 初始化顺序
   - 先初始化 SDK
   - 配置日志系统
   - 设置授权信息
   - 初始化其他模块

2. 视频流处理
   - 使用适当的视频质量配置
   - 实现高效的回调处理
   - 注意内存管理

3. 云端通信
   - 处理消息超时
   - 实现重试机制
   - 控制消息大小（<256字节）

4. 错误处理
   - 始终检查返回值
   - 实现适当的错误恢复机制
   - 记录详细日志

## 适用场景

1. 无人机实时视频流处理
2. 边缘计算应用
3. 云端集成应用
4. 计算机视觉应用
5. 实时监控系统

## 注意事项

1. 内存管理
   - 使用智能指针
   - 注意资源释放
   - 避免内存泄漏

2. 性能优化
   - 合理配置视频质量
   - 优化回调处理
   - 注意线程资源

3. 安全性
   - 保护密钥信息
   - 验证云端通信
   - 控制访问权限

## 许可证

版权所有 (c) 2023 DJI。保留所有权利。
