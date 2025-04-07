#!/bin/fish

for f in (ls build.d)
    echo "$f"
    chmod +x "build.d/$f"
    "build.d/$f" 2> /dev/null
end

qemu-system-x86_64 -cdrom build/lindows.iso -m 1024 -net nic -net user
