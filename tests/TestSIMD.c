#include <NativePath.h>

void testFloat4()
{
    //float32x4_t c = { 1.0f, 2.0f, 3.0f, 4.0f };
    //float32x4_t d = { 5.0f, 6.0f, 7.0f, 8.0f };
    //float32x4_t res2 = vmulq_f32(c, d);
    //printf("%f %f %f %f\n", res2[0], res2[1], res2[2], res2[3]);
	
	float4 e = { 1.0f, 2.0f, 3.0f, 4.0f };
    float4 f = { 5.0f, 6.0f, 7.0f, 8.0f };
	float4 res = e * f;
    printf("%f %f %f %f\n", res[0], res[1], res[2], res[3]);
}

void testInt4()
{
    //int32x4_t c = { 1, 2, 3, 4 };
    //int32x4_t d = { 5, 6, 7, 8 };
    //int32x4_t res2 = vmulq_s32(c, d);
    //printf("%d %d %d %d\n", res2[0], res2[1], res2[2], res2[3]);
	
	int4 e = { 1, 2, 3, 4 };
    int4 f = { 5, 6, 7, 8 };
	int4 res = e * f;
    printf("%d %d %d %d\n", res[0], res[1], res[2], res[3]);
}

int main(int argc, char** argv)
{
    testFloat4();
    testInt4();
    
    return 0;
}