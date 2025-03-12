# 版本发布流程

## 版本号规范

采用语义化版本 (Semantic Versioning):
- 主版本号：不兼容的API修改
- 次版本号：向下兼容的功能性新增
- 修订号：向下兼容的问题修正

示例：v1.0.0

## 发布流程

### 1. 发布准备

1. 创建发布分支
   ```bash
   git checkout develop
   git pull origin develop
   git checkout -b release/vX.Y.Z
   ```

2. 版本更新
   - 更新版本号
   - 更新CHANGELOG.md
   - 更新文档版本信息

3. 测试验证
   - 运行完整测试套件
   - 执行性能测试
   - 进行集成测试

### 2. 代码审查

1. 创建发布PR
   - 目标分支：main
   - 包含所有版本更新
   - 附带完整的发布说明

2. 审查内容
   - 版本号更新
   - 文档完整性
   - 变更记录完整性
   - 测试结果审查

### 3. 发布步骤

1. 合并发布分支
   ```bash
   # 合并到main分支
   git checkout main
   git merge release/vX.Y.Z
   
   # 创建版本标签
   git tag -a vX.Y.Z -m "Release version X.Y.Z"
   
   # 合并回develop分支
   git checkout develop
   git merge release/vX.Y.Z
   ```

2. 推送更改
   ```bash
   git push origin main
   git push origin develop
   git push origin --tags
   ```

3. 创建GitHub Release
   - 标题：vX.Y.Z
   - 包含详细的发布说明
   - 附加编译好的二进制文件

### 4. 发布后续

1. 清理工作
   - 删除发布分支
   - 更新项目看板
   - 关闭相关issue

2. 监控与跟踪
   - 监控系统性能
   - 跟踪用户反馈
   - 记录潜在问题

## 发布说明模板

```markdown
# Release v[X.Y.Z]

## 新功能
- 功能1：详细说明
- 功能2：详细说明

## 改进
- 改进1：详细说明
- 改进2：详细说明

## Bug修复
- 修复1：详细说明
- 修复2：详细说明

## 性能优化
- 优化1：详细说明
- 优化2：详细说明

## 依赖更新
- 依赖1：v1.2.3 -> v1.2.4
- 依赖2：v2.0.0 -> v2.1.0

## 升级说明
[如何升级到新版本的说明]

## 已知问题
[列出已知的问题和限制]

## 贡献者
[列出本次发布的贡献者]
```

## 紧急修复流程

### 1. 创建修复分支
```bash
git checkout main
git checkout -b hotfix/vX.Y.Z+1
```

### 2. 修复步骤
1. 实现修复
2. 更新版本号
3. 更新CHANGELOG
4. 创建PR并审查

### 3. 合并修复
```bash
# 合并到main
git checkout main
git merge hotfix/vX.Y.Z+1
git tag -a vX.Y.Z+1 -m "Hotfix version X.Y.Z+1"

# 合并到develop
git checkout develop
git merge hotfix/vX.Y.Z+1

# 推送更改
git push origin main develop --tags
```

## 版本维护

### 1. 长期支持版本(LTS)
- 定义LTS版本策略
- 维护周期
- 更新策略

### 2. 版本生命周期
1. 开发版本
2. 稳定版本
3. 维护版本
4. 停止支持

### 3. 文档维护
- 版本说明文档
- API文档
- 升级指南
- 兼容性说明