#include <NativePath.h>

void testFloat2()
{
    float32x2_t a = { 1.0f, 2.0f };
    float32x2_t b = { 5.0f, 6.0f };
    float32x2_t res1 = vmul_f32(a, b);
    printf("%f %f\n", res1[0], res1[1]);
}

void testFloat4()
{
    float32x4_t c = { 1.0f, 2.0f, 3.0f, 4.0f };
    float32x4_t d = { 5.0f, 6.0f, 7.0f, 8.0f };
    float32x4_t res2 = vmulq_f32(c, d);
    printf("%f %f %f %f\n", res2[0], res2[1], res2[2], res2[3]);
}

void testInt2()
{
    int32x2_t a = { 1, 2 };
    int32x2_t b = { 5, 6 };
    int32x2_t res1 = vmul_s32(a, b);
    printf("%d %d\n", res1[0], res1[1]);
}

void testInt4()
{
    int32x4_t c = { 1, 2, 3, 4 };
    int32x4_t d = { 5, 6, 7, 8 };
    int32x4_t res2 = vmulq_s32(c, d);
    printf("%d %d %d %d\n", res2[0], res2[1], res2[2], res2[3]);
}

int main(int argc, char** argv)
{
    testFloat2();
    testFloat4();
    testInt2();
    testInt4();
    
    return 0;
}