# rlottie (Nanogram fork) changelog

Branch: `telegram-ios-dev`, pinned by both Nanogram for iOS and Nanogram for macOS since 2026-11-05 (`nanogram-mac` is retired). Base: Telegram's iOS line.

Newest first. Fork-only commits, grouped by day; entries for new work go on top under `## Unreleased`, then are
moved under their date when the app repositories pin them.

## Unreleased

(none)

## 2026-11-05

- One commit for both apps: `LOTTIE_THREAD_SAFE` defined in `src/vector/config.h` (guarded; iOS already passes it in its BUILD), the only difference left from the Mac line. The Mac pins `telegram-ios-dev` from now on.

## 2026-10-31

- Port upstream rlottie security fixes (2025-2026) (0742a48)

