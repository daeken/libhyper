Introduction
============

`libhyper` is a cross-platform hypervisor library for Windows, Linux, and OS X on x86/x64 CPUs.

- Windows support via Intel HAXM - Intel only
- OS X support via Hypervisor.framework - Intel only
- Linux support via KVM - Intel and AMD

Structure
=========

Libhyper will be based off on the KVM API.  This will be largely passed directly to KVM on Linux, and implemented on top of Hypervisor.framework/HAXM for OS X and Windows.  In `KVM Cloning.md` we have a list of KVM ioctls that would be useful to clone.

This structure is being implemented using various relevant C++ classes.
