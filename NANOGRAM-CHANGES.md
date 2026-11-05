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

### One line for both apps (since 2026-11-05)
- What: `LOTTIE_THREAD_SAFE` in `src/vector/config.h`, guarded with `#ifndef` (the Mac build reads this file; iOS passes `-DLOTTIE_THREAD_SAFE=1` in its BUILD). The former `nanogram-mac` branch (ade473c) is retired; both apps pin `telegram-ios-dev`.
- Why: the Mac renders from several threads; one commit for both apps keeps the parity check's equal-SHA rule.
- Where: `src/vector/config.h`.
- Upstream: no (Telegram's Mac line defines it the same way).
