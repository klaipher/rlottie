# How this rlottie differs from TelegramMessenger/rlottie

Upstream: https://github.com/TelegramMessenger/rlottie (`master`, 53c9679 2026-09-06). Telegram-iOS builds a line of
its own (`telegram-ios-dev`: raster scheduler and model cache keepalive, polystar fix); we add on top of it.
History: [CHANGELOG.md](CHANGELOG.md). Format: docs/fork-records.md in klaipher/nanogram.

### Security fixes ported from the 2025-2026 upstream (iOS line, 0742a48)
- What: parser limits and validation (`lottieparser.cpp` +142 lines), bounds in `vbitmap`, `vrle`, FreeType raster and
  stroker, `lottiemodel`/`lottieitem` guards; fixes for malformed animation files that arrive in chats as stickers.
- Why: stickers are parsed on receipt (remote crash risk).
- Where: `src/lottie/`, `src/vector/`. 12 files, +277/-33 against upstream `master`.
- Upstream: yes.
- Sync: when TelegramMessenger/rlottie moves, compare these files first; the iOS and Mac builds must stay on the same commit (`tools/dev/parity` equal-SHA check).

### nanogram-mac
- What: the iOS line plus Mac build integration; merged from `telegram-ios-dev` (ade473c). No behavioural difference
  from the iOS line at 2026-11-05 except what the merge brings.
- Where: Mac app submodule `submodules/rlottie`.
