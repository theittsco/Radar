# 4-Week Radar Engineering Roadmap (Essential Foundations)

---

## Week 1: Radar Fundamentals & Electromagnetics
**Goal:** Understand basic radar concepts, wave propagation, and the radar range equation.

### Topics:
- History and Applications of Radar  
- Electromagnetic (EM) wave basics  
- Radar equation derivation and implications  
- Radar types: CW vs. pulsed, monostatic vs. bistatic  
- Basic radar system block diagram  

### Resources:
- *Introduction to Radar Systems* by Merrill Skolnik – Ch. 1–2  
- MIT OpenCourseWare: [Radar Basics Lecture](https://ocw.mit.edu/courses/aeronautics-and-astronautics/16-684-airs-traffic-control-systems-fall-2005/lecture-notes/)

### Tasks:
- Derive the radar range equation by hand  
- Sketch and explain a basic radar system  
- Compute maximum detection range given transmitter power, RCS, and losses  
- Begin using MATLAB Radar Toolbox or Python (NumPy/Matplotlib)  

---

## Week 2: Radar Subsystems – Transmitters, Antennas, and Receivers
**Goal:** Dive into the physical hardware and signal chain of a radar system.

### Topics:
- Transmitters: Magnetron, Klystron, TWT, solid-state options  
- Antennas: Directivity, gain, phased arrays, beam steering  
- Receivers: Superheterodyne receiver architecture  
- SNR and radar system losses  

### Resources:
- *Radar Principles* by Peebles – Ch. 3–5  
- "Phased Array Antennas" – IEEE Tutorial Series  
- Skolnik – Ch. 4, 5  

### Tasks:
- Calculate antenna gain and beamwidth  
- Simulate antenna radiation patterns  
- Analyze receiver noise figure and compute output SNR  
- Watch: [Phased Array Radar Basics (YouTube)](https://www.youtube.com/watch?v=JtK-EHxLs7M)  

---

## Week 3: Radar Signal Processing & Detection Theory
**Goal:** Learn how radar signals are processed and targets are detected.

### Topics:
- Pulsed radar signal structure  
- Doppler effect and MTI (Moving Target Indication)  
- Pulse compression and matched filtering  
- Clutter, noise, CFAR (Constant False Alarm Rate)  
- Pd vs. Pfa (detection vs. false alarm probabilities)  

### Resources:
- *Radar Signal Analysis and Processing Using MATLAB* by Mahafza – Ch. 3–6  
- Skolnik – Ch. 6, 10  
- MIT Radar Signal Processing [Lecture Series](https://radar.labsystems.co/)

### Tasks:
- Simulate pulse-Doppler radar  
- Implement matched filter  
- Plot ROC curve  
- Compute detection thresholds under different SNR  

---

## Week 4: Tracking, Imaging, and Modern Radar Trends
**Goal:** Explore target tracking, radar imaging, and emerging radar tech.

### Topics:
- Tracking filters: Kalman, alpha-beta  
- Multi-target tracking and data association  
- SAR (Synthetic Aperture Radar) basics  
- Passive radar and MIMO radar  
- Intro to ML in radar (target classification)  

### Resources:
- *Tracking and Kalman Filtering Made Easy* by Eli Brookner  
- Skolnik – Ch. 7, 12  
- IEEE RadarConf Proceedings (recent 2 years)  

### Tasks:
- Simulate basic Kalman filter  
- Visualize SAR image reconstruction  
- Research and summarize one emerging radar tech  
- Implement basic CFAR detector (sliding window)  

---

## Final Project (Optional)
Design and simulate a simplified radar system that:
- Sends a pulsed signal  
- Applies matched filtering  
- Estimates range and velocity of a target  
- Displays detection output with a ROC curve  
# Radar
