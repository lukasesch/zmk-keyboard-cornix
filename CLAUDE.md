# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Project Overview

ZMK firmware configuration for the **Cornix split keyboard** (nRF52840-based, Choc V2 low-profile). This repo is both a standalone ZMK module (via `zephyr/module.yml`) and a self-contained build project. The stock firmware is RMK; this project provides the ZMK alternative.

## Build Commands

**Prerequisites:** Nix flake provides the dev environment (`nix develop`), or manually install: Zephyr SDK, west, cmake, ninja, dtc, just, yq.

```bash
# First-time setup
just init              # west init -l config && west update && west zephyr-export

# Update dependencies
just update            # west update with blob filter

# Build firmware (expr matches artifact-name in build.yaml)
just build all         # build all targets
just build cornix_left # build single target by artifact-name pattern
just build dongle      # partial match works

# List available build targets
just list

# Run a keymap test
just test path/to/test/dir

# Clean
just clean             # remove .build/ and firmware/
just clean-all         # also remove .west/ and zmk/
```

Build outputs go to `firmware/` as `.uf2` files. The Justfile expects `ZMK_LIB_PREFIX` env var pointing to the parent of your zmk checkout (defaults to `zmk_exts`).

## Architecture

### Board & Shield Structure

- **`boards/jzf/cornix/`** — Board definitions (devicetree, pinctrl, Kconfig) for three variants:
  - `cornix_left` — Left half, standalone (no dongle)
  - `cornix_right` — Right half (peripheral)
  - `cornix_ph_left` — Left half for dongle setups
- **`boards/shields/`** — Overlay shields:
  - `cornix_dongle_adapter` — Matrix + BLE for dongle configs
  - `cornix_dongle_eyelash` — Display overlay for dongles without `zephyr,display`
  - `cornix_indicator` — RGB LED indicators (high power draw)

### Config

- **`config/cornix.keymap`** — Main keymap (uses `zmk-helpers` macros and `includes/cornix54.h` for key position defines)
- **`config/west.yml`** — West manifest pulling ZMK, zmk-helpers, zmk-dongle-display
- **`build.yaml`** — GitHub Actions build matrix; also parsed by `just build` to resolve targets

### Key Details

- All boards use **nosd (no SoftDevice)** flash layout by default — the `nrf52840-nosd` snippet is applied
- The `zephyr/module.yml` registers this repo as a Zephyr module with `board_root` and `snippet_root` at repo root
- GitHub Actions triggers on pushes to `boards/` or `config/` directories (ignores tags)
- Dongle screen support is disabled pending Zephyr 4 / LVGL 9 compatibility

### External Dependencies (via west.yml)

- `zmkfirmware/zmk` (main branch)
- `urob/zmk-helpers` — helper macros for keymap definitions
- `hitsmaxft/zmk-dongle-display` (zephyr4 branch) — dongle display widgets
