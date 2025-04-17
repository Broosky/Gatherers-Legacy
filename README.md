# 🛠️ **Gatherers-Historic**

This project, started and largely completed during my reading week near the end of 2010, was born out of my passion for video games — especially the resource gathering mechanic of *StarCraft*. So, I built my own version of it.

Initially created using **Dev-C++** (https://www.bloodshed.net/) with the MinGW compiler, I've since ported it to run with VS Code and the C/C++ extensions. It still runs smoothly, even on modern versions of Windows and Ubuntu (tested).

---

## 🎥 **In Action**

![Demo](Gatherers.gif)

---

## 🧠 **Key Features**

- **Time-based Update Loop**  
  Smooth and consistent unit behavior across systems, using a time-delta (tick-based) update approach.

- **Custom Engine with Animation Support**  
  Built from scratch to manage entity states, movement, rendering, and basic AI — with sprite animations and fluid state transitions.

- **Classic Blending with Bitmap Masks**  
  Implements retro-style transparency using manually crafted bitmap masks for a nostalgic, software-rendered look.

- **State-based AI System**  
  Workers transition between states like *seeking*, *gathering*, and *returning*, emulating early RTS gatherer logic.

- **Old-school Raycast Pathfinding**  
  Uses line-of-sight raycasting to determine clear paths, skipping obstacles when possible.

- **Map Scrolling**  
  Supports camera panning to follow the action across larger maps — just like classic RTS titles.

- **Minimap Display**  
  A compact overview of the world space, showing unit positions and resource locations at a glance.

- **Text Blittering System**  
  Custom-built text renderer using bitmap fonts, used for in-game UI and overlays.

---

## 🧩 **A Bit of History**

The original builds relied on a barebones IDE with minimal debugging tools, relying heavily on caffeine and persistence. After a few proof-of-concept trials in C++, I decided to rewrite it in pure C. Though this version isn't fully optimized, it holds a special place in my development journey.

This repository has been renamed **Gatherers-Historic** to preserve its sentimental value. A new repo, **Gatherers** (https://github.com/Broosky/Gatherers), will supersede it — and I'll continue to improve it when time allows.

---

## ⚙️ **Ubuntu Instructions**

To build the project on Ubuntu, you'll need to install the MinGW cross-compiler, Visual Studio Code, and Wine to run Windows executables on Linux. Then, compile with either the **i686-w64-mingw32** or **x86_64-w64-mingw32 toolchains**, and run the executable via **Wine**.

---

## 💻 **Windows Instructions**

Install **MSYS2** on your C drive (following the [official guide](https://www.msys2.org/)), and then follow the steps for compiling with MinGW from the MSYS2 terminal, or use the Visual Studio Code toolchains.