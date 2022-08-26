# `zig` with `c`
This is a very simple example project to demonstrate working zig with c lang.

# Run
```bash
zig build run
```

# Test
```bash
zig build test
```

# The magic
It's in `build.zig`, the magic code is here.
*(You may change or add more flags in `c_args`.)*

```zig
fn withC(exe: *std.build.LibExeObjStep) void {
    const c_args = [_][]const u8{
        "-std=c99",
        "-Isrc/vendor",
    };
    // exe.linkLibC();
    exe.addIncludeDir("src/vendor");
    exe.addCSourceFile("src/vendor/myadd.c", &c_args);
}
```

Invoking the function `withC` for `zig build run`,
```zig
    ...
    const exe = b.addExecutable("zigwithc", "src/main.zig");
    exe.setTarget(target);
    exe.setBuildMode(mode);
    withC(exe);
    ...
```
 and ` zig build test`.
```zig
    ...
    const exe_tests = b.addTest("src/main.zig");
    exe_tests.setTarget(target);
    exe_tests.setBuildMode(mode);
    withC(exe_tests);
    ...
```
That's it.
