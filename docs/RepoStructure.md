
---

# 📄 `docs/RepoStructure.md`
```markdown
# Repository Structure

## Recommended Layout
- Separate repos for clarity:
  - `garden-esp32` → Firmware (PlatformIO / ESP-IDF).
  - `garden-flutter` → Mobile app (Flutter).
- If you need a mono-repo:
monitor-repo/
├─ garden-esp32/
│ ├─ src/
│ ├─ include/
│ └─ platformio.ini
├─ garden-flutter/
│ ├─ lib/
│ ├─ android/
│ └─ ios/
└─ docs/