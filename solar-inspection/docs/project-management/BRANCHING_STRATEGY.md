# 分支管理策略

## 分支类型

### 1. 主分支 (main)
- 用途：存放稳定的生产版本代码
- 保护策略：需要代码审查和CI通过
- 合并来源：仅接受来自develop分支的合并
- 版本标签：每次发布都要打标签

### 2. 开发分支 (develop)
- 用途：集成各个功能的开发代码
- 保护策略：需要代码审查
- 合并来源：feature分支、hotfix分支
- 测试要求：所有测试必须通过

### 3. 功能分支 (feature/*)
- 命名规范：feature/[功能名称]
- 创建自：develop分支
- 合并到：develop分支
- 生命周期：功能开发完成后删除

### 4. 修复分支 (hotfix/*)
- 命名规范：hotfix/[问题简述]
- 创建自：main分支
- 合并到：main和develop分支
- 使用场景：生产环境紧急问题修复

### 5. 发布分支 (release/*)
- 命名规范：release/v[版本号]
- 创建自：develop分支
- 合并到：main和develop分支
- 用途：版本发布准备

## 工作流程

1. 功能开发
   ```bash
   # 创建功能分支
   git checkout develop
   git pull origin develop
   git checkout -b feature/new-feature
   
   # 开发完成后
   git push origin feature/new-feature
   # 创建Pull Request到develop分支
   ```

2. 版本发布
   ```bash
   # 创建发布分支
   git checkout develop
   git checkout -b release/v1.0.0
   
   # 版本准备完成后
   # 合并到main和develop
   ```

3. 紧急修复
   ```bash
   # 创建hotfix分支
   git checkout main
   git checkout -b hotfix/critical-bug
   
   # 修复完成后合并到main和develop
   ```

## 提交规范

### 提交信息格式
```
<type>(<scope>): <subject>

<body>

<footer>
```

### 类型(type)
- feat: 新功能
- fix: 修复bug
- docs: 文档更新
- style: 代码格式调整
- refactor: 重构
- test: 测试相关
- chore: 构建/工具链/辅助工具的变动

### 示例
```
feat(video): 添加视频流处理模块

- 实现实时视频流获取
- 添加视频帧缓存机制
- 实现基本的图像预处理

Resolves: #123
```

## 保护规则

1. main分支
   - 禁止直接推送
   - 必须通过Pull Request合并
   - 需要至少1个审查者批准
   - 必须通过CI检查

2. develop分支
   - 禁止直接推送
   - 必须通过Pull Request合并
   - 需要至少1个审查者批准

## 版本号规范

采用语义化版本 (Semantic Versioning):
- 主版本号：不兼容的API修改
- 次版本号：向下兼容的功能性新增
- 修订号：向下兼容的问题修正

示例：v1.0.0