
## Git Practices
- Protect `main` branch (PRs only).
- Use feature branches: `feature/nfc`, `fix/ble-scan`.
- Commit docs/code separately if possible.

## .gitignore Basics
- Flutter:

.dart_tool/
build/
pubspec.lock

- ESP32:
.pio/
.vscode/

- Common:
.DS_Store
*.log


## Credentials & Keys
- Use SSH with passphrase or YubiKey.
- Never commit tokens or `local.properties`.

## Projects in GitHub
- **Roadmap project**: development steps.
- **Bug tracking project**: document issues you encounter.
