# 贡献指南

感谢您考虑为Solar Inspection项目做出贡献！

## 开发流程

1. Fork项目仓库
2. 克隆您的Fork到本地
   ```bash
   git clone https://github.com/YOUR_USERNAME/solar-inspection.git
   ```
3. 创建新的特性分支
   ```bash
   git checkout -b feature/your-feature-name
   ```
4. 进行开发并提交更改
   ```bash
   git add .
   git commit -m "feat: add your feature"
   ```
5. 推送到您的Fork
   ```bash
   git push origin feature/your-feature-name
   ```
6. 创建Pull Request

## 提交规范

我们使用Angular提交规范：

- feat: 新功能
- fix: 修复bug
- docs: 文档更新
- style: 代码格式修改
- refactor: 重构代码
- test: 测试相关
- chore: 构建过程或辅助工具的变动

示例：
```
feat: 添加自动巡检路径规划功能

- 实现A*算法进行路径规划
- 添加避障功能
- 优化路径平滑度
```

## 代码规范

- 遵循C++17标准
- 使用clang-format进行代码格式化
- 所有代码必须通过单元测试
- 保持代码覆盖率在80%以上

## Pull Request流程

1. PR标题要简洁明了
2. 描述中需包含：
   - 功能说明
   - 实现方案
   - 测试结果
   - 相关issue编号
3. 确保CI检查通过
4. 等待代码审查
5. 根据反馈进行修改

## 问题报告

创建issue时请包含：

1. 问题描述
2. 复现步骤
3. 期望行为
4. 实际行为
5. 系统环境
6. 相关日志或截图

## 开发环境设置

1. 安装依赖
   ```bash
   sudo apt-get update
   sudo apt-get install build-essential cmake libopencv-dev libspdlog-dev catch2
   ```

2. 配置开发环境
   ```bash
   mkdir build && cd build
   cmake -DCMAKE_BUILD_TYPE=Debug ..
   make
   ```

3. 运行测试
   ```bash
   make test
   ```

## 文档贡献

- 保持文档的及时更新
- 使用清晰的语言
- 添加必要的示例
- 包含API文档

## 行为准则

- 保持专业和友善
- 尊重他人的贡献
- 积极参与讨论
- 接受建设性的批评

## 获取帮助

- 查看项目文档
- 搜索已有issues
- 通过邮件联系团队：team@solar-inspection.com

感谢您的贡献！