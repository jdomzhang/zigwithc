# `Zig` with `C`
This is a very simple example to demonstrate how `Zig` works with `C`.

# Run
Use below script to run.
```bash
zig build run
```

# Test
Use below script to test.
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
    };

    exe.linkLibC();
    exe.addIncludePath("src/vendor/include");
    exe.addCSourceFile("src/vendor/myadd.c", &c_args);
    exe.addCSourceFile("src/vendor/mytime.c", &c_args);
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
