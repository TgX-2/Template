// Bật bit
mask |= (1 << i)

// Tắt bit
mask &= ~(1 << i)

// Đổi bit
mask ^= (1 << i)

// Kiểm tra bit
if (mask & (1 << i))
if ((mask >> i) & 1)

// Đếm số bit 1
__builtin_popcount(mask)
__builtin_popcountll(mask)

// Lấy vị trí bit 1 thấp nhất
__builtin_clz(mask)

// Lấy vị trí bit 1 cao nhất
31 - __builtin_clz(mask)

// Xóa bit 1 thấp nhất - 1001100 -> 1001000
mask &= (mask - 1)

// Chỉ lấy riêng bit 1 thấp nhất
mask & -mask

// Duyệt từng bit 1 trong mask
while(mask) {
    int bit = mask & -mask;
    int i = __builtin_ctz(bit);

    mask ^= bit;
}

// Duyệt submask
for(int sub = mask; sub; sub = (sub - 1) & mask)

// Duyệt supermask
for(int sup = mask; sup <= (1 << n) - 1; sup = (sup + 1) | mask)

// Graycode
for(int i = 0; i <= (1 << n) - 1; i++)
    int gray = i ^ (i >> 1);

// SOS
for(int i = 0; i <= n - 1; i++)
    for(int mask = 0; mask <= (1 << n) - 1; mask++)
        if ((mask >> i) & 1)
            f[mask] += f[mask ^ (1 << i)];

// Đảo toàn bộ bit trong n bit
mask ^= (1 << n) - 1;

// Đếm số bit khác nhau giữa 2 mask
__builtin_popcount(a ^ b)