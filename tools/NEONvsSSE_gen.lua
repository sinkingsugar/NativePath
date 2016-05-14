local functions = [[
//*************************************************************************
//*************************************************************************
//*********  Functions declarations as declared in original arm_neon.h *****
//*************************************************************************
//Vector add: vadd -> Vr[i]:=Va[i]+Vb[i], Vr, Va, Vb have equal lane sizes.
int8x16_t vaddq_s8(int8x16_t a, int8x16_t b); // VADD.I8 q0,q0,q0
int16x8_t vaddq_s16(int16x8_t a, int16x8_t b); // VADD.I16 q0,q0,q0
int32x4_t vaddq_s32(int32x4_t a, int32x4_t b); // VADD.I32 q0,q0,q0
int64x2_t vaddq_s64(int64x2_t a, int64x2_t b); // VADD.I64 q0,q0,q0
float32x4_t vaddq_f32(float32x4_t a, float32x4_t b); // VADD.F32 q0,q0,q0
uint8x16_t vaddq_u8(uint8x16_t a, uint8x16_t b); // VADD.I8 q0,q0,q0
uint16x8_t vaddq_u16(uint16x8_t a, uint16x8_t b); // VADD.I16 q0,q0,q0
uint32x4_t vaddq_u32(uint32x4_t a, uint32x4_t b); // VADD.I32 q0,q0,q0
uint64x2_t vaddq_u64(uint64x2_t a, uint64x2_t b); // VADD.I64 q0,q0,q0
//Vector long add: vaddl -> Vr[i]:=Va[i]+Vb[i], Va, Vb have equal lane sizes, result is a 128 bit vector of lanes that are twice the width.
//Vector wide addw: vadd -> Vr[i]:=Va[i]+Vb[i]
//Vector halving add: vhadd -> Vr[i]:=(Va[i]+Vb[i])>>1
int8x16_t vhaddq_s8(int8x16_t a, int8x16_t b); // VHADD.S8 q0,q0,q0
int16x8_t vhaddq_s16(int16x8_t a, int16x8_t b); // VHADD.S16 q0,q0,q0
int32x4_t vhaddq_s32(int32x4_t a, int32x4_t b); // VHADD.S32 q0,q0,q0
uint8x16_t vhaddq_u8(uint8x16_t a, uint8x16_t b); // VHADD.U8 q0,q0,q0
uint16x8_t vhaddq_u16(uint16x8_t a, uint16x8_t b); // VHADD.U16 q0,q0,q0
uint32x4_t vhaddq_u32(uint32x4_t a, uint32x4_t b); // VHADD.U32 q0,q0,q0
//Vector rounding halving add: vrhadd -> Vr[i]:=(Va[i]+Vb[i]+1)>>1
int8x16_t vrhaddq_s8(int8x16_t a, int8x16_t b); // VRHADD.S8 q0,q0,q0
int16x8_t vrhaddq_s16(int16x8_t a, int16x8_t b); // VRHADD.S16 q0,q0,q0
int32x4_t vrhaddq_s32(int32x4_t a, int32x4_t b); // VRHADD.S32 q0,q0,q0
uint8x16_t vrhaddq_u8(uint8x16_t a, uint8x16_t b); // VRHADD.U8 q0,q0,q0
uint16x8_t vrhaddq_u16(uint16x8_t a, uint16x8_t b); // VRHADD.U16 q0,q0,q0
uint32x4_t vrhaddq_u32(uint32x4_t a, uint32x4_t b); // VRHADD.U32 q0,q0,q0
//Vector saturating add: vqadd -> Vr[i]:=sat<size>(Va[i]+Vb[i])
int8x16_t vqaddq_s8(int8x16_t a, int8x16_t b); // VQADD.S8 q0,q0,q0
int16x8_t vqaddq_s16(int16x8_t a, int16x8_t b); // VQADD.S16 q0,q0,q0
int32x4_t vqaddq_s32(int32x4_t a, int32x4_t b); // VQADD.S32 q0,q0,q0
int64x2_t vqaddq_s64(int64x2_t a, int64x2_t b); // VQADD.S64 q0,q0,q0
uint8x16_t vqaddq_u8(uint8x16_t a, uint8x16_t b); // VQADD.U8 q0,q0,q0
uint16x8_t vqaddq_u16(uint16x8_t a, uint16x8_t b); // VQADD.U16 q0,q0,q0
uint32x4_t vqaddq_u32(uint32x4_t a, uint32x4_t b); // VQADD.U32 q0,q0,q0
uint64x2_t vqaddq_u64(uint64x2_t a, uint64x2_t b); // VQADD.U64 q0,q0,q0
//Vector add high half: vaddhn-> Vr[i]:=Va[i]+Vb[i]
//Vector rounding add high half: vraddhn
//Multiplication
//Vector multiply: vmul -> Vr[i] := Va[i] * Vb[i]
int8x16_t vmulq_s8(int8x16_t a, int8x16_t b); // VMUL.I8 q0,q0,q0
int16x8_t vmulq_s16(int16x8_t a, int16x8_t b); // VMUL.I16 q0,q0,q0
int32x4_t vmulq_s32(int32x4_t a, int32x4_t b); // VMUL.I32 q0,q0,q0
float32x4_t vmulq_f32(float32x4_t a, float32x4_t b); // VMUL.F32 q0,q0,q0
uint8x16_t vmulq_u8(uint8x16_t a, uint8x16_t b); // VMUL.I8 q0,q0,q0
uint16x8_t vmulq_u16(uint16x8_t a, uint16x8_t b); // VMUL.I16 q0,q0,q0
uint32x4_t vmulq_u32(uint32x4_t a, uint32x4_t b); // VMUL.I32 q0,q0,q0
poly8x16_t vmulq_p8(poly8x16_t a, poly8x16_t b); // VMUL.P8 q0,q0,q0
//multiply lane
//Vector multiply accumulate: vmla -> Vr[i] := Va[i] + Vb[i] * Vc[i]
int8x16_t vmlaq_s8(int8x16_t a, int8x16_t b, int8x16_t c); // VMLA.I8 q0,q0,q0
int16x8_t vmlaq_s16(int16x8_t a, int16x8_t b, int16x8_t c); // VMLA.I16 q0,q0,q0
int32x4_t vmlaq_s32(int32x4_t a, int32x4_t b, int32x4_t c); // VMLA.I32 q0,q0,q0
float32x4_t vmlaq_f32(float32x4_t a, float32x4_t b, float32x4_t c); // VMLA.F32 q0,q0,q0
uint8x16_t vmlaq_u8(uint8x16_t a, uint8x16_t b, uint8x16_t c); // VMLA.I8 q0,q0,q0
uint16x8_t vmlaq_u16(uint16x8_t a, uint16x8_t b, uint16x8_t c); // VMLA.I16 q0,q0,q0
uint32x4_t vmlaq_u32(uint32x4_t a, uint32x4_t b, uint32x4_t c); // VMLA.I32 q0,q0,q0
//Vector multiply accumulate long: vmlal -> Vr[i] := Va[i] + Vb[i] * Vc[i]
//Vector multiply subtract: vmls -> Vr[i] := Va[i] - Vb[i] * Vc[i]
int8x16_t vmlsq_s8(int8x16_t a, int8x16_t b, int8x16_t c); // VMLS.I8 q0,q0,q0
int16x8_t vmlsq_s16(int16x8_t a, int16x8_t b, int16x8_t c); // VMLS.I16 q0,q0,q0
int32x4_t vmlsq_s32(int32x4_t a, int32x4_t b, int32x4_t c); // VMLS.I32 q0,q0,q0
float32x4_t vmlsq_f32(float32x4_t a, float32x4_t b, float32x4_t c); // VMLS.F32 q0,q0,q0
uint8x16_t vmlsq_u8(uint8x16_t a, uint8x16_t b, uint8x16_t c); // VMLS.I8 q0,q0,q0
uint16x8_t vmlsq_u16(uint16x8_t a, uint16x8_t b, uint16x8_t c); // VMLS.I16 q0,q0,q0
uint32x4_t vmlsq_u32(uint32x4_t a, uint32x4_t b, uint32x4_t c); // VMLS.I32 q0,q0,q0
//Vector multiply subtract long
//Vector saturating doubling multiply high
int16x8_t vqdmulhq_s16(int16x8_t a, int16x8_t b); // VQDMULH.S16 q0,q0,q0
int32x4_t vqdmulhq_s32(int32x4_t a, int32x4_t b); // VQDMULH.S32 q0,q0,q0
//Vector saturating rounding doubling multiply high
int16x8_t vqrdmulhq_s16(int16x8_t a, int16x8_t b); // VQRDMULH.S16 q0,q0,q0
int32x4_t vqrdmulhq_s32(int32x4_t a, int32x4_t b); // VQRDMULH.S32 q0,q0,q0
//Vector saturating doubling multiply accumulate long
//Vector saturating doubling multiply subtract long
//Vector long multiply
//Vector saturating doubling long multiply
//Subtraction
//Vector subtract
int8x16_t vsubq_s8(int8x16_t a, int8x16_t b); // VSUB.I8 q0,q0,q0
int16x8_t vsubq_s16(int16x8_t a, int16x8_t b); // VSUB.I16 q0,q0,q0
int32x4_t vsubq_s32(int32x4_t a, int32x4_t b); // VSUB.I32 q0,q0,q0
int64x2_t vsubq_s64(int64x2_t a, int64x2_t b); // VSUB.I64 q0,q0,q0
float32x4_t vsubq_f32(float32x4_t a, float32x4_t b); // VSUB.F32 q0,q0,q0
uint8x16_t vsubq_u8(uint8x16_t a, uint8x16_t b); // VSUB.I8 q0,q0,q0
uint16x8_t vsubq_u16(uint16x8_t a, uint16x8_t b); // VSUB.I16 q0,q0,q0
uint32x4_t vsubq_u32(uint32x4_t a, uint32x4_t b); // VSUB.I32 q0,q0,q0
uint64x2_t vsubq_u64(uint64x2_t a, uint64x2_t b); // VSUB.I64 q0,q0,q0
//Vector long subtract: vsub -> Vr[i]:=Va[i]+Vb[i]
//Vector wide subtract: vsub -> Vr[i]:=Va[i]+Vb[i]
//Vector saturating subtract
int8x16_t vqsubq_s8(int8x16_t a, int8x16_t b); // VQSUB.S8 q0,q0,q0
int16x8_t vqsubq_s16(int16x8_t a, int16x8_t b); // VQSUB.S16 q0,q0,q0
int32x4_t vqsubq_s32(int32x4_t a, int32x4_t b); // VQSUB.S32 q0,q0,q0
int64x2_t vqsubq_s64(int64x2_t a, int64x2_t b); // VQSUB.S64 q0,q0,q0
uint8x16_t vqsubq_u8(uint8x16_t a, uint8x16_t b); // VQSUB.U8 q0,q0,q0
uint16x8_t vqsubq_u16(uint16x8_t a, uint16x8_t b); // VQSUB.U16 q0,q0,q0
uint32x4_t vqsubq_u32(uint32x4_t a, uint32x4_t b); // VQSUB.U32 q0,q0,q0
uint64x2_t vqsubq_u64(uint64x2_t a, uint64x2_t b); // VQSUB.U64 q0,q0,q0
//Vector halving subtract
int8x16_t vhsubq_s8(int8x16_t a, int8x16_t b); // VHSUB.S8 q0,q0,q0
int16x8_t vhsubq_s16(int16x8_t a, int16x8_t b); // VHSUB.S16 q0,q0,q0
int32x4_t vhsubq_s32(int32x4_t a, int32x4_t b); // VHSUB.S32 q0,q0,q0
uint8x16_t vhsubq_u8(uint8x16_t a, uint8x16_t b); // VHSUB.U8 q0,q0,q0
uint16x8_t vhsubq_u16(uint16x8_t a, uint16x8_t b); // VHSUB.U16 q0,q0,q0
uint32x4_t vhsubq_u32(uint32x4_t a, uint32x4_t b); // VHSUB.U32 q0,q0,q0
//Vector subtract high half
//Vector rounding subtract high half
//Comparison
//Vector compare equal
uint8x16_t vceqq_s8(int8x16_t a, int8x16_t b); // VCEQ.I8 q0, q0, q0
uint16x8_t vceqq_s16(int16x8_t a, int16x8_t b); // VCEQ.I16 q0, q0, q0
uint32x4_t vceqq_s32(int32x4_t a, int32x4_t b); // VCEQ.I32 q0, q0, q0
uint32x4_t vceqq_f32(float32x4_t a, float32x4_t b); // VCEQ.F32 q0, q0, q0
uint8x16_t vceqq_u8(uint8x16_t a, uint8x16_t b); // VCEQ.I8 q0, q0, q0
uint16x8_t vceqq_u16(uint16x8_t a, uint16x8_t b); // VCEQ.I16 q0, q0, q0
uint32x4_t vceqq_u32(uint32x4_t a, uint32x4_t b); // VCEQ.I32 q0, q0, q0
uint8x16_t vceqq_p8(poly8x16_t a, poly8x16_t b); // VCEQ.I8 q0, q0, q0
//Vector compare greater-than or equal
uint8x16_t vcgeq_s8(int8x16_t a, int8x16_t b); // VCGE.S8 q0, q0, q0
uint16x8_t vcgeq_s16(int16x8_t a, int16x8_t b); // VCGE.S16 q0, q0, q0
uint32x4_t vcgeq_s32(int32x4_t a, int32x4_t b); // VCGE.S32 q0, q0, q0
uint32x4_t vcgeq_f32(float32x4_t a, float32x4_t b); // VCGE.F32 q0, q0, q0
uint8x16_t vcgeq_u8(uint8x16_t a, uint8x16_t b); // VCGE.U8 q0, q0, q0
uint16x8_t vcgeq_u16(uint16x8_t a, uint16x8_t b); // VCGE.U16 q0, q0, q0
uint32x4_t vcgeq_u32(uint32x4_t a, uint32x4_t b); // VCGE.U32 q0, q0, q0
//Vector compare less-than or equal
uint8x16_t vcleq_s8(int8x16_t a, int8x16_t b); // VCGE.S8 q0, q0, q0
uint16x8_t vcleq_s16(int16x8_t a, int16x8_t b); // VCGE.S16 q0, q0, q0
uint32x4_t vcleq_s32(int32x4_t a, int32x4_t b); // VCGE.S32 q0, q0, q0
uint32x4_t vcleq_f32(float32x4_t a, float32x4_t b); // VCGE.F32 q0, q0, q0
uint8x16_t vcleq_u8(uint8x16_t a, uint8x16_t b); // VCGE.U8 q0, q0, q0
uint16x8_t vcleq_u16(uint16x8_t a, uint16x8_t b); // VCGE.U16 q0, q0, q0
uint32x4_t vcleq_u32(uint32x4_t a, uint32x4_t b); // VCGE.U32 q0, q0, q0
//Vector compare greater-than
uint8x16_t vcgtq_s8(int8x16_t a, int8x16_t b); // VCGT.S8 q0, q0, q0
uint16x8_t vcgtq_s16(int16x8_t a, int16x8_t b); // VCGT.S16 q0, q0, q0
uint32x4_t vcgtq_s32(int32x4_t a, int32x4_t b); // VCGT.S32 q0, q0, q0
uint32x4_t vcgtq_f32(float32x4_t a, float32x4_t b); // VCGT.F32 q0, q0, q0
uint8x16_t vcgtq_u8(uint8x16_t a, uint8x16_t b); // VCGT.U8 q0, q0, q0
uint16x8_t vcgtq_u16(uint16x8_t a, uint16x8_t b); // VCGT.U16 q0, q0, q0
uint32x4_t vcgtq_u32(uint32x4_t a, uint32x4_t b); // VCGT.U32 q0, q0, q0
//Vector compare less-than
uint8x16_t vcltq_s8(int8x16_t a, int8x16_t b); // VCGT.S8 q0, q0, q0
uint16x8_t vcltq_s16(int16x8_t a, int16x8_t b); // VCGT.S16 q0, q0, q0
uint32x4_t vcltq_s32(int32x4_t a, int32x4_t b); // VCGT.S32 q0, q0, q0
uint32x4_t vcltq_f32(float32x4_t a, float32x4_t b); // VCGT.F32 q0, q0, q0
uint8x16_t vcltq_u8(uint8x16_t a, uint8x16_t b); // VCGT.U8 q0, q0, q0
uint16x8_t vcltq_u16(uint16x8_t a, uint16x8_t b); // VCGT.U16 q0, q0, q0
uint32x4_t vcltq_u32(uint32x4_t a, uint32x4_t b); // VCGT.U32 q0, q0, q0
//Vector compare absolute greater-than or equal
//Vector test bits
uint8x16_t vtstq_s8(int8x16_t a, int8x16_t b); // VTST.8 q0, q0, q0
uint16x8_t vtstq_s16(int16x8_t a, int16x8_t b); // VTST.16 q0, q0, q0
uint32x4_t vtstq_s32(int32x4_t a, int32x4_t b); // VTST.32 q0, q0, q0
uint8x16_t vtstq_u8(uint8x16_t a, uint8x16_t b); // VTST.8 q0, q0, q0
uint16x8_t vtstq_u16(uint16x8_t a, uint16x8_t b); // VTST.16 q0, q0, q0
uint32x4_t vtstq_u32(uint32x4_t a, uint32x4_t b); // VTST.32 q0, q0, q0
uint8x16_t vtstq_p8(poly8x16_t a, poly8x16_t b); // VTST.8 q0, q0, q0
//Absolute difference
//Absolute difference between the arguments: Vr[i] = | Va[i] - Vb[i] |
int8x16_t vabdq_s8(int8x16_t a, int8x16_t b); // VABD.S8 q0,q0,q0
int16x8_t vabdq_s16(int16x8_t a, int16x8_t b); // VABD.S16 q0,q0,q0
int32x4_t vabdq_s32(int32x4_t a, int32x4_t b); // VABD.S32 q0,q0,q0
uint8x16_t vabdq_u8(uint8x16_t a, uint8x16_t b); // VABD.U8 q0,q0,q0
uint16x8_t vabdq_u16(uint16x8_t a, uint16x8_t b); // VABD.U16 q0,q0,q0
uint32x4_t vabdq_u32(uint32x4_t a, uint32x4_t b); // VABD.U32 q0,q0,q0
float32x4_t vabdq_f32(float32x4_t a, float32x4_t b); // VABD.F32 q0,q0,q0
//Absolute difference - long
//Absolute difference and accumulate: Vr[i] = Va[i] + | Vb[i] - Vc[i] |
int8x16_t vabaq_s8(int8x16_t a, int8x16_t b, int8x16_t c); // VABA.S8 q0,q0,q0
int16x8_t vabaq_s16(int16x8_t a, int16x8_t b, int16x8_t c); // VABA.S16 q0,q0,q0
int32x4_t vabaq_s32(int32x4_t a, int32x4_t b, int32x4_t c); // VABA.S32 q0,q0,q0
uint8x16_t vabaq_u8(uint8x16_t a, uint8x16_t b, uint8x16_t c); // VABA.U8 q0,q0,q0
uint16x8_t vabaq_u16(uint16x8_t a, uint16x8_t b, uint16x8_t c); // VABA.U16 q0,q0,q0
uint32x4_t vabaq_u32(uint32x4_t a, uint32x4_t b, uint32x4_t c); // VABA.U32 q0,q0,q0
//Absolute difference and accumulate - long
//Max/Min
//vmax -> Vr[i] := (Va[i] >= Vb[i]) ? Va[i] : Vb[i]
int8x16_t vmaxq_s8(int8x16_t a, int8x16_t b); // VMAX.S8 q0,q0,q0
int16x8_t vmaxq_s16(int16x8_t a, int16x8_t b); // VMAX.S16 q0,q0,q0
int32x4_t vmaxq_s32(int32x4_t a, int32x4_t b); // VMAX.S32 q0,q0,q0
uint8x16_t vmaxq_u8(uint8x16_t a, uint8x16_t b); // VMAX.U8 q0,q0,q0
uint16x8_t vmaxq_u16(uint16x8_t a, uint16x8_t b); // VMAX.U16 q0,q0,q0
uint32x4_t vmaxq_u32(uint32x4_t a, uint32x4_t b); // VMAX.U32 q0,q0,q0
float32x4_t vmaxq_f32(float32x4_t a, float32x4_t b); // VMAX.F32 q0,q0,q0
//vmin -> Vr[i] := (Va[i] >= Vb[i]) ? Vb[i] : Va[i]
int8x16_t vminq_s8(int8x16_t a, int8x16_t b); // VMIN.S8 q0,q0,q0
int16x8_t vminq_s16(int16x8_t a, int16x8_t b); // VMIN.S16 q0,q0,q0
int32x4_t vminq_s32(int32x4_t a, int32x4_t b); // VMIN.S32 q0,q0,q0
uint8x16_t vminq_u8(uint8x16_t a, uint8x16_t b); // VMIN.U8 q0,q0,q0
uint16x8_t vminq_u16(uint16x8_t a, uint16x8_t b); // VMIN.U16 q0,q0,q0
uint32x4_t vminq_u32(uint32x4_t a, uint32x4_t b); // VMIN.U32 q0,q0,q0
float32x4_t vminq_f32(float32x4_t a, float32x4_t b); // VMIN.F32 q0,q0,q0
//Pairwise addition
//Pairwise add
//Long pairwise add
int16x8_t vpaddlq_s8(int8x16_t a); // VPADDL.S8 q0,q0
int32x4_t vpaddlq_s16(int16x8_t a); // VPADDL.S16 q0,q0
int64x2_t vpaddlq_s32(int32x4_t a); // VPADDL.S32 q0,q0
uint16x8_t vpaddlq_u8(uint8x16_t a); // VPADDL.U8 q0,q0
uint32x4_t vpaddlq_u16(uint16x8_t a); // VPADDL.U16 q0,q0
uint64x2_t vpaddlq_u32(uint32x4_t a); // VPADDL.U32 q0,q0
//Long pairwise add and accumulate
int16x8_t vpadalq_s8(int16x8_t a, int8x16_t b); // VPADAL.S8 q0,q0
int32x4_t vpadalq_s16(int32x4_t a, int16x8_t b); // VPADAL.S16 q0,q0
int64x2_t vpadalq_s32(int64x2_t a, int32x4_t b); // VPADAL.S32 q0,q0
uint16x8_t vpadalq_u8(uint16x8_t a, uint8x16_t b); // VPADAL.U8 q0,q0
uint32x4_t vpadalq_u16(uint32x4_t a, uint16x8_t b); // VPADAL.U16 q0,q0
uint64x2_t vpadalq_u32(uint64x2_t a, uint32x4_t b); // VPADAL.U32 q0,q0
//Folding maximum vpmax -> takes maximum of adjacent pairs
//Folding minimum vpmin -> takes minimum of adjacent pairs
//Reciprocal/Sqrt
float32x4_t vrecpsq_f32(float32x4_t a, float32x4_t b); // VRECPS.F32 q0, q0, q0
float32x4_t vrsqrtsq_f32(float32x4_t a, float32x4_t b); // VRSQRTS.F32 q0, q0, q0
//Shifts by signed variable
//Vector shift left: Vr[i] := Va[i] << Vb[i] (negative values shift right)
int8x16_t vshlq_s8(int8x16_t a, int8x16_t b); // VSHL.S8 q0,q0,q0
int16x8_t vshlq_s16(int16x8_t a, int16x8_t b); // VSHL.S16 q0,q0,q0
int32x4_t vshlq_s32(int32x4_t a, int32x4_t b); // VSHL.S32 q0,q0,q0
int64x2_t vshlq_s64(int64x2_t a, int64x2_t b); // VSHL.S64 q0,q0,q0
uint8x16_t vshlq_u8(uint8x16_t a, int8x16_t b); // VSHL.U8 q0,q0,q0
uint16x8_t vshlq_u16(uint16x8_t a, int16x8_t b); // VSHL.U16 q0,q0,q0
uint32x4_t vshlq_u32(uint32x4_t a, int32x4_t b); // VSHL.U32 q0,q0,q0
uint64x2_t vshlq_u64(uint64x2_t a, int64x2_t b); // VSHL.U64 q0,q0,q0
//Vector saturating shift left: (negative values shift right)
int8x16_t vqshlq_s8(int8x16_t a, int8x16_t b); // VQSHL.S8 q0,q0,q0
int16x8_t vqshlq_s16(int16x8_t a, int16x8_t b); // VQSHL.S16 q0,q0,q0
int32x4_t vqshlq_s32(int32x4_t a, int32x4_t b); // VQSHL.S32 q0,q0,q0
int64x2_t vqshlq_s64(int64x2_t a, int64x2_t b); // VQSHL.S64 q0,q0,q0
uint8x16_t vqshlq_u8(uint8x16_t a, int8x16_t b); // VQSHL.U8 q0,q0,q0
uint16x8_t vqshlq_u16(uint16x8_t a, int16x8_t b); // VQSHL.U16 q0,q0,q0
uint32x4_t vqshlq_u32(uint32x4_t a, int32x4_t b); // VQSHL.U32 q0,q0,q0
uint64x2_t vqshlq_u64(uint64x2_t a, int64x2_t b); // VQSHL.U64 q0,q0,q0
//Vector rounding shift left: (negative values shift right)
int8x16_t vrshlq_s8(int8x16_t a, int8x16_t b); // VRSHL.S8 q0,q0,q0
int16x8_t vrshlq_s16(int16x8_t a, int16x8_t b); // VRSHL.S16 q0,q0,q0
int32x4_t vrshlq_s32(int32x4_t a, int32x4_t b); // VRSHL.S32 q0,q0,q0
int64x2_t vrshlq_s64(int64x2_t a, int64x2_t b); // VRSHL.S64 q0,q0,q0
uint8x16_t vrshlq_u8(uint8x16_t a, int8x16_t b); // VRSHL.U8 q0,q0,q0
uint16x8_t vrshlq_u16(uint16x8_t a, int16x8_t b); // VRSHL.U16 q0,q0,q0
uint32x4_t vrshlq_u32(uint32x4_t a, int32x4_t b); // VRSHL.U32 q0,q0,q0
uint64x2_t vrshlq_u64(uint64x2_t a, int64x2_t b); // VRSHL.U64 q0,q0,q0
//Vector saturating rounding shift left: (negative values shift right)
int8x16_t vqrshlq_s8(int8x16_t a, int8x16_t b); // VQRSHL.S8 q0,q0,q0
int16x8_t vqrshlq_s16(int16x8_t a, int16x8_t b); // VQRSHL.S16 q0,q0,q0
int32x4_t vqrshlq_s32(int32x4_t a, int32x4_t b); // VQRSHL.S32 q0,q0,q0
int64x2_t vqrshlq_s64(int64x2_t a, int64x2_t b); // VQRSHL.S64 q0,q0,q0
uint8x16_t vqrshlq_u8(uint8x16_t a, int8x16_t b); // VQRSHL.U8 q0,q0,q0
uint16x8_t vqrshlq_u16(uint16x8_t a, int16x8_t b); // VQRSHL.U16 q0,q0,q0
uint32x4_t vqrshlq_u32(uint32x4_t a, int32x4_t b); // VQRSHL.U32 q0,q0,q0
uint64x2_t vqrshlq_u64(uint64x2_t a, int64x2_t b); // VQRSHL.U64 q0,q0,q0
//Shifts by a constant
//Vector shift right by constant
int8x16_t vshrq_n_s8(int8x16_t a, __constrange(1,8) int b); // VSHR.S8 q0,q0,#8
int16x8_t vshrq_n_s16(int16x8_t a, __constrange(1,16) int b); // VSHR.S16 q0,q0,#16
int32x4_t vshrq_n_s32(int32x4_t a, __constrange(1,32) int b); // VSHR.S32 q0,q0,#32
int64x2_t vshrq_n_s64(int64x2_t a, __constrange(1,64) int b); // VSHR.S64 q0,q0,#64
uint8x16_t vshrq_n_u8(uint8x16_t a, __constrange(1,8) int b); // VSHR.U8 q0,q0,#8
uint16x8_t vshrq_n_u16(uint16x8_t a, __constrange(1,16) int b); // VSHR.U16 q0,q0,#16
uint32x4_t vshrq_n_u32(uint32x4_t a, __constrange(1,32) int b); // VSHR.U32 q0,q0,#32
uint64x2_t vshrq_n_u64(uint64x2_t a, __constrange(1,64) int b); // VSHR.U64 q0,q0,#64
//Vector shift left by constant
int8x16_t vshlq_n_s8(int8x16_t a, __constrange(0,7) int b); // VSHL.I8 q0,q0,#0
int16x8_t vshlq_n_s16(int16x8_t a, __constrange(0,15) int b); // VSHL.I16 q0,q0,#0
int32x4_t vshlq_n_s32(int32x4_t a, __constrange(0,31) int b); // VSHL.I32 q0,q0,#0
int64x2_t vshlq_n_s64(int64x2_t a, __constrange(0,63) int b); // VSHL.I64 q0,q0,#0
uint8x16_t vshlq_n_u8(uint8x16_t a, __constrange(0,7) int b); // VSHL.I8 q0,q0,#0
uint16x8_t vshlq_n_u16(uint16x8_t a, __constrange(0,15) int b); // VSHL.I16 q0,q0,#0
uint32x4_t vshlq_n_u32(uint32x4_t a, __constrange(0,31) int b); // VSHL.I32 q0,q0,#0
uint64x2_t vshlq_n_u64(uint64x2_t a, __constrange(0,63) int b); // VSHL.I64 q0,q0,#0
//Vector rounding shift right by constant
int8x16_t vrshrq_n_s8(int8x16_t a, __constrange(1,8) int b); // VRSHR.S8 q0,q0,#8
int16x8_t vrshrq_n_s16(int16x8_t a, __constrange(1,16) int b); // VRSHR.S16 q0,q0,#16
int32x4_t vrshrq_n_s32(int32x4_t a, __constrange(1,32) int b); // VRSHR.S32 q0,q0,#32
int64x2_t vrshrq_n_s64(int64x2_t a, __constrange(1,64) int b); // VRSHR.S64 q0,q0,#64
uint8x16_t vrshrq_n_u8(uint8x16_t a, __constrange(1,8) int b); // VRSHR.U8 q0,q0,#8
uint16x8_t vrshrq_n_u16(uint16x8_t a, __constrange(1,16) int b); // VRSHR.U16 q0,q0,#16
uint32x4_t vrshrq_n_u32(uint32x4_t a, __constrange(1,32) int b); // VRSHR.U32 q0,q0,#32
uint64x2_t vrshrq_n_u64(uint64x2_t a, __constrange(1,64) int b); // VRSHR.U64 q0,q0,#64
//Vector shift right by constant and accumulate
int8x16_t vsraq_n_s8(int8x16_t a, int8x16_t b, __constrange(1,8) int c); // VSRA.S8 q0,q0,#8
int16x8_t vsraq_n_s16(int16x8_t a, int16x8_t b, __constrange(1,16) int c); // VSRA.S16 q0,q0,#16
int32x4_t vsraq_n_s32(int32x4_t a, int32x4_t b, __constrange(1,32) int c); // VSRA.S32 q0,q0,#32
int64x2_t vsraq_n_s64(int64x2_t a, int64x2_t b, __constrange(1,64) int c); // VSRA.S64 q0,q0,#64
uint8x16_t vsraq_n_u8(uint8x16_t a, uint8x16_t b, __constrange(1,8) int c); // VSRA.U8 q0,q0,#8
uint16x8_t vsraq_n_u16(uint16x8_t a, uint16x8_t b, __constrange(1,16) int c); // VSRA.U16 q0,q0,#16
uint32x4_t vsraq_n_u32(uint32x4_t a, uint32x4_t b, __constrange(1,32) int c); // VSRA.U32 q0,q0,#32
uint64x2_t vsraq_n_u64(uint64x2_t a, uint64x2_t b, __constrange(1,64) int c); // VSRA.U64 q0,q0,#64
//Vector rounding shift right by constant and accumulate
int8x16_t vrsraq_n_s8(int8x16_t a, int8x16_t b, __constrange(1,8) int c); // VRSRA.S8 q0,q0,#8
int16x8_t vrsraq_n_s16(int16x8_t a, int16x8_t b, __constrange(1,16) int c); // VRSRA.S16 q0,q0,#16
int32x4_t vrsraq_n_s32(int32x4_t a, int32x4_t b, __constrange(1,32) int c); // VRSRA.S32 q0,q0,#32
int64x2_t vrsraq_n_s64(int64x2_t a, int64x2_t b, __constrange(1,64) int c); // VRSRA.S64 q0,q0,#64
uint8x16_t vrsraq_n_u8(uint8x16_t a, uint8x16_t b, __constrange(1,8) int c); // VRSRA.U8 q0,q0,#8
uint16x8_t vrsraq_n_u16(uint16x8_t a, uint16x8_t b, __constrange(1,16) int c); // VRSRA.U16 q0,q0,#16
uint32x4_t vrsraq_n_u32(uint32x4_t a, uint32x4_t b, __constrange(1,32) int c); // VRSRA.U32 q0,q0,#32
uint64x2_t vrsraq_n_u64(uint64x2_t a, uint64x2_t b, __constrange(1,64) int c); // VRSRA.U64 q0,q0,#64
//Vector saturating shift left by constant
int8x16_t vqshlq_n_s8(int8x16_t a, __constrange(0,7) int b); // VQSHL.S8 q0,q0,#0
int16x8_t vqshlq_n_s16(int16x8_t a, __constrange(0,15) int b); // VQSHL.S16 q0,q0,#0
int32x4_t vqshlq_n_s32(int32x4_t a, __constrange(0,31) int b); // VQSHL.S32 q0,q0,#0
int64x2_t vqshlq_n_s64(int64x2_t a, __constrange(0,63) int b); // VQSHL.S64 q0,q0,#0
uint8x16_t vqshlq_n_u8(uint8x16_t a, __constrange(0,7) int b); // VQSHL.U8 q0,q0,#0
uint16x8_t vqshlq_n_u16(uint16x8_t a, __constrange(0,15) int b); // VQSHL.U16 q0,q0,#0
uint32x4_t vqshlq_n_u32(uint32x4_t a, __constrange(0,31) int b); // VQSHL.U32 q0,q0,#0
uint64x2_t vqshlq_n_u64(uint64x2_t a, __constrange(0,63) int b); // VQSHL.U64 q0,q0,#0
//Vector signed->unsigned saturating shift left by constant
uint8x16_t vqshluq_n_s8(int8x16_t a, __constrange(0,7) int b); // VQSHLU.S8 q0,q0,#0
uint16x8_t vqshluq_n_s16(int16x8_t a, __constrange(0,15) int b); // VQSHLU.S16 q0,q0,#0
uint32x4_t vqshluq_n_s32(int32x4_t a, __constrange(0,31) int b); // VQSHLU.S32 q0,q0,#0
uint64x2_t vqshluq_n_s64(int64x2_t a, __constrange(0,63) int b); // VQSHLU.S64 q0,q0,#0
//Vector narrowing shift right by constant
//Vector signed->unsigned narrowing saturating shift right by constant
//Vector signed->unsigned rounding narrowing saturating shift right by constant
//Vector narrowing saturating shift right by constant
//Vector rounding narrowing shift right by constant
//Vector rounding narrowing saturating shift right by constant
//Vector widening shift left by constant
//Shifts with insert
//Vector shift right and insert
int8x16_t vsriq_n_s8(int8x16_t a, int8x16_t b, __constrange(1,8) int c); // VSRI.8 q0,q0,#8
int16x8_t vsriq_n_s16(int16x8_t a, int16x8_t b, __constrange(1,16) int c); // VSRI.16 q0,q0,#16
int32x4_t vsriq_n_s32(int32x4_t a, int32x4_t b, __constrange(1,32) int c); // VSRI.32 q0,q0,#32
int64x2_t vsriq_n_s64(int64x2_t a, int64x2_t b, __constrange(1,64) int c); // VSRI.64 q0,q0,#64
uint8x16_t vsriq_n_u8(uint8x16_t a, uint8x16_t b, __constrange(1,8) int c); // VSRI.8 q0,q0,#8
uint16x8_t vsriq_n_u16(uint16x8_t a, uint16x8_t b, __constrange(1,16) int c); // VSRI.16 q0,q0,#16
uint32x4_t vsriq_n_u32(uint32x4_t a, uint32x4_t b, __constrange(1,32) int c); // VSRI.32 q0,q0,#32
uint64x2_t vsriq_n_u64(uint64x2_t a, uint64x2_t b, __constrange(1,64) int c); // VSRI.64 q0,q0,#64
poly8x16_t vsriq_n_p8(poly8x16_t a, poly8x16_t b, __constrange(1,8) int c); // VSRI.8 q0,q0,#8
poly16x8_t vsriq_n_p16(poly16x8_t a, poly16x8_t b, __constrange(1,16) int c); // VSRI.16 q0,q0,#16
//Vector shift left and insert
int8x16_t vsliq_n_s8(int8x16_t a, int8x16_t b, __constrange(0,7) int c); // VSLI.8 q0,q0,#0
int16x8_t vsliq_n_s16(int16x8_t a, int16x8_t b, __constrange(0,15) int c); // VSLI.16 q0,q0,#0
int32x4_t vsliq_n_s32(int32x4_t a, int32x4_t b, __constrange(0,31) int c); // VSLI.32 q0,q0,#0
int64x2_t vsliq_n_s64(int64x2_t a, int64x2_t b, __constrange(0,63) int c); // VSLI.64 q0,q0,#0
uint8x16_t vsliq_n_u8(uint8x16_t a, uint8x16_t b, __constrange(0,7) int c); // VSLI.8 q0,q0,#0
uint16x8_t vsliq_n_u16(uint16x8_t a, uint16x8_t b, __constrange(0,15) int c); // VSLI.16 q0,q0,#0
uint32x4_t vsliq_n_u32(uint32x4_t a, uint32x4_t b, __constrange(0,31) int c); // VSLI.32 q0,q0,#0
uint64x2_t vsliq_n_u64(uint64x2_t a, uint64x2_t b, __constrange(0,63) int c); // VSLI.64 q0,q0,#0
poly8x16_t vsliq_n_p8(poly8x16_t a, poly8x16_t b, __constrange(0,7) int c); // VSLI.8 q0,q0,#0
poly16x8_t vsliq_n_p16(poly16x8_t a, poly16x8_t b, __constrange(0,15) int c); // VSLI.16 q0,q0,#0
//Loads of a single vector or lane. Perform loads and stores of a single vector of some type.
//Load a single vector from memory
uint8x16_t vld1q_u8(__transfersize(16) uint8_t const * ptr); // VLD1.8 {d0, d1}, [r0]
uint16x8_t vld1q_u16(__transfersize(8) uint16_t const * ptr); // VLD1.16 {d0, d1}, [r0]
uint32x4_t vld1q_u32(__transfersize(4) uint32_t const * ptr); // VLD1.32 {d0, d1}, [r0]
uint64x2_t vld1q_u64(__transfersize(2) uint64_t const * ptr); // VLD1.64 {d0, d1}, [r0]
int8x16_t vld1q_s8(__transfersize(16) int8_t const * ptr); // VLD1.8 {d0, d1}, [r0]
int16x8_t vld1q_s16(__transfersize(8) int16_t const * ptr); // VLD1.16 {d0, d1}, [r0]
int32x4_t vld1q_s32(__transfersize(4) int32_t const * ptr); // VLD1.32 {d0, d1}, [r0]
int64x2_t vld1q_s64(__transfersize(2) int64_t const * ptr); // VLD1.64 {d0, d1}, [r0]
float32x4_t vld1q_f32(__transfersize(4) float32_t const * ptr); // VLD1.32 {d0, d1}, [r0]
poly8x16_t vld1q_p8(__transfersize(16) poly8_t const * ptr); // VLD1.8 {d0, d1}, [r0]
poly16x8_t vld1q_p16(__transfersize(8) poly16_t const * ptr); // VLD1.16 {d0, d1}, [r0]
//Load a single lane from memory
uint8x16_t vld1q_lane_u8(__transfersize(1) uint8_t const * ptr, uint8x16_t vec, __constrange(0,15) int lane); //VLD1.8 {d0[0]}, [r0]
uint16x8_t vld1q_lane_u16(__transfersize(1) uint16_t const * ptr, uint16x8_t vec, __constrange(0,7) int lane); // VLD1.16 {d0[0]}, [r0]
uint32x4_t vld1q_lane_u32(__transfersize(1) uint32_t const * ptr, uint32x4_t vec, __constrange(0,3) int lane); // VLD1.32 {d0[0]}, [r0]
uint64x2_t vld1q_lane_u64(__transfersize(1) uint64_t const * ptr, uint64x2_t vec, __constrange(0,1) int lane); // VLD1.64 {d0}, [r0]
int8x16_t vld1q_lane_s8(__transfersize(1) int8_t const * ptr, int8x16_t vec, __constrange(0,15) int lane); //VLD1.8 {d0[0]}, [r0]
int16x8_t vld1q_lane_s16(__transfersize(1) int16_t const * ptr, int16x8_t vec, __constrange(0,7) int lane); //VLD1.16 {d0[0]}, [r0]
int32x4_t vld1q_lane_s32(__transfersize(1) int32_t const * ptr, int32x4_t vec, __constrange(0,3) int lane); //VLD1.32 {d0[0]}, [r0]
float32x4_t vld1q_lane_f32(__transfersize(1) float32_t const * ptr, float32x4_t vec, __constrange(0,3) int lane); // VLD1.32 {d0[0]}, [r0]
int64x2_t vld1q_lane_s64(__transfersize(1) int64_t const * ptr, int64x2_t vec, __constrange(0,1) int lane); //VLD1.64 {d0}, [r0]
poly8x16_t vld1q_lane_p8(__transfersize(1) poly8_t const * ptr, poly8x16_t vec, __constrange(0,15) int lane); //VLD1.8 {d0[0]}, [r0]
poly16x8_t vld1q_lane_p16(__transfersize(1) poly16_t const * ptr, poly16x8_t vec, __constrange(0,7) int lane); // VLD1.16 {d0[0]}, [r0]
//Load all lanes of vector with same value from memory
uint8x16_t vld1q_dup_u8(__transfersize(1) uint8_t const * ptr); // VLD1.8 {d0[]}, [r0]
uint16x8_t vld1q_dup_u16(__transfersize(1) uint16_t const * ptr); // VLD1.16 {d0[]}, [r0]
uint32x4_t vld1q_dup_u32(__transfersize(1) uint32_t const * ptr); // VLD1.32 {d0[]}, [r0]
int8x16_t vld1q_dup_s8(__transfersize(1) int8_t const * ptr); // VLD1.8 {d0[]}, [r0]
int16x8_t vld1q_dup_s16(__transfersize(1) int16_t const * ptr); // VLD1.16 {d0[]}, [r0]
int32x4_t vld1q_dup_s32(__transfersize(1) int32_t const * ptr); // VLD1.32 {d0[]}, [r0]
float32x4_t vld1q_dup_f32(__transfersize(1) float32_t const * ptr); // VLD1.32 {d0[]}, [r0]
poly8x16_t vld1q_dup_p8(__transfersize(1) poly8_t const * ptr); // VLD1.8 {d0[]}, [r0]
poly16x8_t vld1q_dup_p16(__transfersize(1) poly16_t const * ptr); // VLD1.16 {d0[]}, [r0]
//Store a single vector or lane. Stores all lanes or a single lane of a vector.
//Store a single vector into memory
void vst1q_u8(__transfersize(16) uint8_t * ptr, uint8x16_t val); // VST1.8 {d0, d1}, [r0]
void vst1q_u16(__transfersize(8) uint16_t * ptr, uint16x8_t val); // VST1.16 {d0, d1}, [r0]
void vst1q_u32(__transfersize(4) uint32_t * ptr, uint32x4_t val); // VST1.32 {d0, d1}, [r0]
void vst1q_u64(__transfersize(2) uint64_t * ptr, uint64x2_t val); // VST1.64 {d0, d1}, [r0]
void vst1q_s8(__transfersize(16) int8_t * ptr, int8x16_t val); // VST1.8 {d0, d1}, [r0]
void vst1q_s16(__transfersize(8) int16_t * ptr, int16x8_t val); // VST1.16 {d0, d1}, [r0]
void vst1q_s32(__transfersize(4) int32_t * ptr, int32x4_t val); // VST1.32 {d0, d1}, [r0]
void vst1q_s64(__transfersize(2) int64_t * ptr, int64x2_t val); // VST1.64 {d0, d1}, [r0]
void vst1q_f32(__transfersize(4) float32_t * ptr, float32x4_t val); // VST1.32 {d0, d1}, [r0]
void vst1q_p8(__transfersize(16) poly8_t * ptr, poly8x16_t val); // VST1.8 {d0, d1}, [r0]
void vst1q_p16(__transfersize(8) poly16_t * ptr, poly16x8_t val); // VST1.16 {d0, d1}, [r0]
//Store a lane of a vector into memory
//Loads of an N-element structure
//Load N-element structure from memory
uint8x16x2_t vld2q_u8(__transfersize(32) uint8_t const * ptr); // VLD2.8 {d0, d2}, [r0]
uint16x8x2_t vld2q_u16(__transfersize(16) uint16_t const * ptr); // VLD2.16 {d0, d2}, [r0]
uint32x4x2_t vld2q_u32(__transfersize(8) uint32_t const * ptr); // VLD2.32 {d0, d2}, [r0]
int8x16x2_t vld2q_s8(__transfersize(32) int8_t const * ptr); // VLD2.8 {d0, d2}, [r0]
int16x8x2_t vld2q_s16(__transfersize(16) int16_t const * ptr); // VLD2.16 {d0, d2}, [r0]
int32x4x2_t vld2q_s32(__transfersize(8) int32_t const * ptr); // VLD2.32 {d0, d2}, [r0]
float32x4x2_t vld2q_f32(__transfersize(8) float32_t const * ptr); // VLD2.32 {d0, d2}, [r0]
poly8x16x2_t vld2q_p8(__transfersize(32) poly8_t const * ptr); // VLD2.8 {d0, d2}, [r0]
poly16x8x2_t vld2q_p16(__transfersize(16) poly16_t const * ptr); // VLD2.16 {d0, d2}, [r0]
uint8x16x3_t vld3q_u8(__transfersize(48) uint8_t const * ptr); // VLD3.8 {d0, d2, d4}, [r0]
uint16x8x3_t vld3q_u16(__transfersize(24) uint16_t const * ptr); // VLD3.16 {d0, d2, d4}, [r0]
uint32x4x3_t vld3q_u32(__transfersize(12) uint32_t const * ptr); // VLD3.32 {d0, d2, d4}, [r0]
int8x16x3_t vld3q_s8(__transfersize(48) int8_t const * ptr); // VLD3.8 {d0, d2, d4}, [r0]
int16x8x3_t vld3q_s16(__transfersize(24) int16_t const * ptr); // VLD3.16 {d0, d2, d4}, [r0]
int32x4x3_t vld3q_s32(__transfersize(12) int32_t const * ptr); // VLD3.32 {d0, d2, d4}, [r0]
float32x4x3_t vld3q_f32(__transfersize(12) float32_t const * ptr); // VLD3.32 {d0, d2, d4}, [r0]
poly8x16x3_t vld3q_p8(__transfersize(48) poly8_t const * ptr); // VLD3.8 {d0, d2, d4}, [r0]
poly16x8x3_t vld3q_p16(__transfersize(24) poly16_t const * ptr); // VLD3.16 {d0, d2, d4}, [r0]
uint8x16x4_t vld4q_u8(__transfersize(64) uint8_t const * ptr); // VLD4.8 {d0, d2, d4, d6}, [r0]
uint16x8x4_t vld4q_u16(__transfersize(32) uint16_t const * ptr); // VLD4.16 {d0, d2, d4, d6}, [r0]
uint32x4x4_t vld4q_u32(__transfersize(16) uint32_t const * ptr); // VLD4.32 {d0, d2, d4, d6}, [r0]
int8x16x4_t vld4q_s8(__transfersize(64) int8_t const * ptr); // VLD4.8 {d0, d2, d4, d6}, [r0]
int16x8x4_t vld4q_s16(__transfersize(32) int16_t const * ptr); // VLD4.16 {d0, d2, d4, d6}, [r0]
int32x4x4_t vld4q_s32(__transfersize(16) int32_t const * ptr); // VLD4.32 {d0, d2, d4, d6}, [r0]
float32x4x4_t vld4q_f32(__transfersize(16) float32_t const * ptr); // VLD4.32 {d0, d2, d4, d6}, [r0]
poly8x16x4_t vld4q_p8(__transfersize(64) poly8_t const * ptr); // VLD4.8 {d0, d2, d4, d6}, [r0]
poly16x8x4_t vld4q_p16(__transfersize(32) poly16_t const * ptr); // VLD4.16 {d0, d2, d4, d6}, [r0]
//Load all lanes of N-element structure with same value from memory
//Load a single lane of N-element structure from memory
//the functions below are modified to deal with the error C2719: 'src': formal parameter with __declspec(align('16')) won't be aligned
uint16x8x2_t vld2q_lane_u16_ptr(__transfersize(2) uint16_t const * ptr, uint16x8x2_t * src, __constrange(0,7) int lane); // VLD2.16 {d0[0], d2[0]}, [r0]
uint32x4x2_t vld2q_lane_u32_ptr(__transfersize(2) uint32_t const * ptr, uint32x4x2_t * src, __constrange(0,3) int lane); // VLD2.32 {d0[0], d2[0]}, [r0]
int16x8x2_t vld2q_lane_s16_ptr(__transfersize(2) int16_t const * ptr, int16x8x2_t * src, __constrange(0,7) int lane); // VLD2.16 {d0[0], d2[0]}, [r0]
int32x4x2_t vld2q_lane_s32_ptr(__transfersize(2) int32_t const * ptr, int32x4x2_t * src, __constrange(0,3) int lane); // VLD2.32 {d0[0], d2[0]}, [r0]
float32x4x2_t vld2q_lane_f32_ptr(__transfersize(2) float32_t const * ptr, float32x4x2_t * src, __constrange(0,3) int lane); // VLD2.32 {d0[0], d2[0]}, [r0]
poly16x8x2_t vld2q_lane_p16_ptr(__transfersize(2) poly16_t const * ptr, poly16x8x2_t * src, __constrange(0,7) int lane); // VLD2.16 {d0[0], d2[0]}, [r0]
uint16x8x3_t vld3q_lane_u16_ptr(__transfersize(3) uint16_t const * ptr, uint16x8x3_t * src, __constrange(0,7) int lane); // VLD3.16 {d0[0], d2[0], d4[0]}, [r0]
uint32x4x3_t vld3q_lane_u32_ptr(__transfersize(3) uint32_t const * ptr, uint32x4x3_t * src, __constrange(0,3) int lane); // VLD3.32 {d0[0], d2[0], d4[0]}, [r0]
int16x8x3_t vld3q_lane_s16_ptr(__transfersize(3) int16_t const * ptr, int16x8x3_t * src, __constrange(0,7) int lane); // VLD3.16 {d0[0], d2[0], d4[0]}, [r0]
int32x4x3_t vld3q_lane_s32_ptr(__transfersize(3) int32_t const * ptr, int32x4x3_t * src, __constrange(0,3) int lane); // VLD3.32 {d0[0], d2[0], d4[0]}, [r0]
float32x4x3_t vld3q_lane_f32_ptr(__transfersize(3) float32_t const * ptr, float32x4x3_t * src, __constrange(0,3) int lane); // VLD3.32 {d0[0], d2[0], d4[0]}, [r0]
poly16x8x3_t vld3q_lane_p16_ptr(__transfersize(3) poly16_t const * ptr, poly16x8x3_t * src, __constrange(0,7) int lane); // VLD3.16 {d0[0], d2[0], d4[0]}, [r0]
uint16x8x4_t vld4q_lane_u16_ptr(__transfersize(4) uint16_t const * ptr, uint16x8x4_t * src, __constrange(0,7) int lane); // VLD4.16 {d0[0], d2[0], d4[0], d6[0]}, [r0]
uint32x4x4_t vld4q_lane_u32_ptr(__transfersize(4) uint32_t const * ptr, uint32x4x4_t * src, __constrange(0,3) int lane); // VLD4.32 {d0[0], d2[0], d4[0], d6[0]}, [r0]
int16x8x4_t vld4q_lane_s16_ptr(__transfersize(4) int16_t const * ptr, int16x8x4_t * src, __constrange(0,7) int lane); // VLD4.16 {d0[0], d2[0], d4[0], d6[0]}, [r0]
int32x4x4_t vld4q_lane_s32_ptr(__transfersize(4) int32_t const * ptr, int32x4x4_t * src, __constrange(0,3) int lane); // VLD4.32 {d0[0], d2[0], d4[0], d6[0]}, [r0]
float32x4x4_t vld4q_lane_f32_ptr(__transfersize(4) float32_t const * ptr, float32x4x4_t * src, __constrange(0,3) int lane); // VLD4.32 {d0[0], d2[0], d4[0], d6[0]}, [r0]
poly16x8x4_t vld4q_lane_p16_ptr(__transfersize(4) poly16_t const * ptr, poly16x8x4_t * src, __constrange(0,7) int lane); // VLD4.16 {d0[0], d2[0], d4[0], d6[0]}, [r0]
//Store N-element structure to memory
void vst2q_u8_ptr(__transfersize(32) uint8_t * ptr, uint8x16x2_t * val); // VST2.8 {d0, d2}, [r0]
void vst2q_u16_ptr(__transfersize(16) uint16_t * ptr, uint16x8x2_t * val); // VST2.16 {d0, d2}, [r0]
void vst2q_u32_ptr(__transfersize(8) uint32_t * ptr, uint32x4x2_t * val); // VST2.32 {d0, d2}, [r0]
void vst2q_s8_ptr(__transfersize(32) int8_t * ptr, int8x16x2_t * val); // VST2.8 {d0, d2}, [r0]
void vst2q_s16_ptr(__transfersize(16) int16_t * ptr, int16x8x2_t * val); // VST2.16 {d0, d2}, [r0]
void vst2q_s32_ptr(__transfersize(8) int32_t * ptr, int32x4x2_t * val); // VST2.32 {d0, d2}, [r0]
void vst2q_f32_ptr(__transfersize(8) float32_t * ptr, float32x4x2_t * val); // VST2.32 {d0, d2}, [r0]
void vst2q_p8_ptr(__transfersize(32) poly8_t * ptr, poly8x16x2_t * val); // VST2.8 {d0, d2}, [r0]
void vst2q_p16_ptr(__transfersize(16) poly16_t * ptr, poly16x8x2_t * val); // VST2.16 {d0, d2}, [r0]
void vst3q_u8_ptr(__transfersize(48) uint8_t * ptr, uint8x16x3_t * val); // VST3.8 {d0, d2, d4}, [r0]
void vst3q_u16_ptr(__transfersize(24) uint16_t * ptr, uint16x8x3_t * val); // VST3.16 {d0, d2, d4}, [r0]
void vst3q_u32_ptr(__transfersize(12) uint32_t * ptr, uint32x4x3_t * val); // VST3.32 {d0, d2, d4}, [r0]
void vst3q_s8_ptr(__transfersize(48) int8_t * ptr, int8x16x3_t * val); // VST3.8 {d0, d2, d4}, [r0]
void vst3q_s16_ptr(__transfersize(24) int16_t * ptr, int16x8x3_t * val); // VST3.16 {d0, d2, d4}, [r0]
void vst3q_s32_ptr(__transfersize(12) int32_t * ptr, int32x4x3_t * val); // VST3.32 {d0, d2, d4}, [r0]
void vst3q_f32_ptr(__transfersize(12) float32_t * ptr, float32x4x3_t * val); // VST3.32 {d0, d2, d4}, [r0]
void vst3q_p8_ptr(__transfersize(48) poly8_t * ptr, poly8x16x3_t * val); // VST3.8 {d0, d2, d4}, [r0]
void vst3q_p16_ptr(__transfersize(24) poly16_t * ptr, poly16x8x3_t * val); // VST3.16 {d0, d2, d4}, [r0]
void vst4q_u8_ptr(__transfersize(64) uint8_t * ptr, uint8x16x4_t * val); // VST4.8 {d0, d2, d4, d6}, [r0]
void vst4q_u16_ptr(__transfersize(32) uint16_t * ptr, uint16x8x4_t * val); // VST4.16 {d0, d2, d4, d6}, [r0]
void vst4q_u32_ptr(__transfersize(16) uint32_t * ptr, uint32x4x4_t * val); // VST4.32 {d0, d2, d4, d6}, [r0]
void vst4q_s8_ptr(__transfersize(64) int8_t * ptr, int8x16x4_t * val); // VST4.8 {d0, d2, d4, d6}, [r0]
void vst4q_s16_ptr(__transfersize(32) int16_t * ptr, int16x8x4_t * val); // VST4.16 {d0, d2, d4, d6}, [r0]
void vst4q_s32_ptr(__transfersize(16) int32_t * ptr, int32x4x4_t * val); // VST4.32 {d0, d2, d4, d6}, [r0]
void vst4q_f32_ptr(__transfersize(16) float32_t * ptr, float32x4x4_t * val); // VST4.32 {d0, d2, d4, d6}, [r0]
void vst4q_p8_ptr(__transfersize(64) poly8_t * ptr, poly8x16x4_t * val); // VST4.8 {d0, d2, d4, d6}, [r0]
void vst4q_p16_ptr(__transfersize(32) poly16_t * ptr, poly16x8x4_t * val); // VST4.16 {d0, d2, d4, d6}, [r0]
//Store a single lane of N-element structure to memory
void vst2q_lane_u16_ptr(__transfersize(2) uint16_t * ptr, uint16x8x2_t * val, __constrange(0,7) int lane); // VST2.16{d0[0], d2[0]}, [r0]
void vst2q_lane_u32_ptr(__transfersize(2) uint32_t * ptr, uint32x4x2_t * val, __constrange(0,3) int lane); // VST2.32{d0[0], d2[0]}, [r0]
void vst2q_lane_s16_ptr(__transfersize(2) int16_t * ptr, int16x8x2_t * val, __constrange(0,7) int lane); // VST2.16{d0[0], d2[0]}, [r0]
void vst2q_lane_s32_ptr(__transfersize(2) int32_t * ptr, int32x4x2_t * val, __constrange(0,3) int lane); // VST2.32{d0[0], d2[0]}, [r0]
void vst2q_lane_f32_ptr(__transfersize(2) float32_t * ptr, float32x4x2_t * val, __constrange(0,3) int lane); //VST2.32 {d0[0], d2[0]}, [r0]
void vst2q_lane_p16_ptr(__transfersize(2) poly16_t * ptr, poly16x8x2_t * val, __constrange(0,7) int lane); // VST2.16{d0[0], d2[0]}, [r0]
void vst3q_lane_u16_ptr(__transfersize(3) uint16_t * ptr, uint16x8x3_t * val, __constrange(0,7) int lane); // VST3.16{d0[0], d2[0], d4[0]}, [r0]
void vst3q_lane_u32_ptr(__transfersize(3) uint32_t * ptr, uint32x4x3_t * val, __constrange(0,3) int lane); // VST3.32{d0[0], d2[0], d4[0]}, [r0]
void vst3q_lane_s16_ptr(__transfersize(3) int16_t * ptr, int16x8x3_t * val, __constrange(0,7) int lane); // VST3.16{d0[0], d2[0], d4[0]}, [r0]
void vst3q_lane_s32_ptr(__transfersize(3) int32_t * ptr, int32x4x3_t * val, __constrange(0,3) int lane); // VST3.32{d0[0], d2[0], d4[0]}, [r0]
void vst3q_lane_f32_ptr(__transfersize(3) float32_t * ptr, float32x4x3_t * val, __constrange(0,3) int lane); //VST3.32 {d0[0], d2[0], d4[0]}, [r0]
void vst3q_lane_p16_ptr(__transfersize(3) poly16_t * ptr, poly16x8x3_t * val, __constrange(0,7) int lane); // VST3.16{d0[0], d2[0], d4[0]}, [r0]
void vst4q_lane_u16_ptr(__transfersize(4) uint16_t * ptr, uint16x8x4_t * val, __constrange(0,7) int lane); // VST4.16{d0[0], d2[0], d4[0], d6[0]}, [r0]
void vst4q_lane_u32_ptr(__transfersize(4) uint32_t * ptr, uint32x4x4_t * val, __constrange(0,3) int lane); // VST4.32{d0[0], d2[0], d4[0], d6[0]}, [r0]
void vst4q_lane_s16_ptr(__transfersize(4) int16_t * ptr, int16x8x4_t * val, __constrange(0,7) int lane); // VST4.16{d0[0], d2[0], d4[0], d6[0]}, [r0]
void vst4q_lane_s32_ptr(__transfersize(4) int32_t * ptr, int32x4x4_t * val, __constrange(0,3) int lane); // VST4.32{d0[0], d2[0], d4[0], d6[0]}, [r0]
void vst4q_lane_f32_ptr(__transfersize(4) float32_t * ptr, float32x4x4_t * val, __constrange(0,3) int lane); //VST4.32 {d0[0], d2[0], d4[0], d6[0]}, [r0]
void vst4q_lane_p16_ptr(__transfersize(4) poly16_t * ptr, poly16x8x4_t * val, __constrange(0,7) int lane); // VST4.16{d0[0], d2[0], d4[0], d6[0]}, [r0]
//Extract lanes from a vector and put into a register. These intrinsics extract a single lane (element) from a vector.
uint8_t vgetq_lane_u8(uint8x16_t vec, __constrange(0,15) int lane); // VMOV.U8 r0, d0[0]
uint16_t vgetq_lane_u16(uint16x8_t vec, __constrange(0,7) int lane); // VMOV.U16 r0, d0[0]
uint32_t vgetq_lane_u32(uint32x4_t vec, __constrange(0,3) int lane); // VMOV.32 r0, d0[0]
int8_t vgetq_lane_s8(int8x16_t vec, __constrange(0,15) int lane); // VMOV.S8 r0, d0[0]
int16_t vgetq_lane_s16(int16x8_t vec, __constrange(0,7) int lane); // VMOV.S16 r0, d0[0]
int32_t vgetq_lane_s32(int32x4_t vec, __constrange(0,3) int lane); // VMOV.32 r0, d0[0]
poly8_t vgetq_lane_p8(poly8x16_t vec, __constrange(0,15) int lane); // VMOV.U8 r0, d0[0]
poly16_t vgetq_lane_p16(poly16x8_t vec, __constrange(0,7) int lane); // VMOV.U16 r0, d0[0]
float32_t vgetq_lane_f32(float32x4_t vec, __constrange(0,3) int lane); // VMOV.32 r0, d0[0]
int64_t vgetq_lane_s64(int64x2_t vec, __constrange(0,1) int lane); // VMOV r0,r0,d0
uint64_t vgetq_lane_u64(uint64x2_t vec, __constrange(0,1) int lane); // VMOV r0,r0,d0
//Load a single lane of a vector from a literal. These intrinsics set a single lane (element) within a vector.
uint8x16_t vsetq_lane_u8(uint8_t value, uint8x16_t vec, __constrange(0,15) int lane); // VMOV.8 d0[0],r0
uint16x8_t vsetq_lane_u16(uint16_t value, uint16x8_t vec, __constrange(0,7) int lane); // VMOV.16 d0[0],r0
uint32x4_t vsetq_lane_u32(uint32_t value, uint32x4_t vec, __constrange(0,3) int lane); // VMOV.32 d0[0],r0
int8x16_t vsetq_lane_s8(int8_t value, int8x16_t vec, __constrange(0,15) int lane); // VMOV.8 d0[0],r0
int16x8_t vsetq_lane_s16(int16_t value, int16x8_t vec, __constrange(0,7) int lane); // VMOV.16 d0[0],r0
int32x4_t vsetq_lane_s32(int32_t value, int32x4_t vec, __constrange(0,3) int lane); // VMOV.32 d0[0],r0
poly8x16_t vsetq_lane_p8(poly8_t value, poly8x16_t vec, __constrange(0,15) int lane); // VMOV.8 d0[0],r0
poly16x8_t vsetq_lane_p16(poly16_t value, poly16x8_t vec, __constrange(0,7) int lane); // VMOV.16 d0[0],r0
float32x4_t vsetq_lane_f32(float32_t value, float32x4_t vec, __constrange(0,3) int lane); // VMOV.32 d0[0],r0
int64x2_t vsetq_lane_s64(int64_t value, int64x2_t vec, __constrange(0,1) int lane); // VMOV d0,r0,r0
uint64x2_t vsetq_lane_u64(uint64_t value, uint64x2_t vec, __constrange(0,1) int lane); // VMOV d0,r0,r0
//Initialize a vector from a literal bit pattern.
//Set all lanes to same value
//Load all lanes of vector to the same literal value
uint8x16_t vdupq_n_u8(uint8_t value); // VDUP.8 q0,r0
uint16x8_t vdupq_n_u16(uint16_t value); // VDUP.16 q0,r0
uint32x4_t vdupq_n_u32(uint32_t value); // VDUP.32 q0,r0
int8x16_t vdupq_n_s8(int8_t value); // VDUP.8 q0,r0
int16x8_t vdupq_n_s16(int16_t value); // VDUP.16 q0,r0
int32x4_t vdupq_n_s32(int32_t value); // VDUP.32 q0,r0
poly8x16_t vdupq_n_p8(poly8_t value); // VDUP.8 q0,r0
poly16x8_t vdupq_n_p16(poly16_t value); // VDUP.16 q0,r0
float32x4_t vdupq_n_f32(float32_t value); // VDUP.32 q0,r0
int64x2_t vdupq_n_s64(int64_t value); // VMOV d0,r0,r0
uint64x2_t vdupq_n_u64(uint64_t value); // VMOV d0,r0,r0
uint8x16_t vmovq_n_u8(uint8_t value); // VDUP.8 q0,r0
uint16x8_t vmovq_n_u16(uint16_t value); // VDUP.16 q0,r0
uint32x4_t vmovq_n_u32(uint32_t value); // VDUP.32 q0,r0
int8x16_t vmovq_n_s8(int8_t value); // VDUP.8 q0,r0
int16x8_t vmovq_n_s16(int16_t value); // VDUP.16 q0,r0
int32x4_t vmovq_n_s32(int32_t value); // VDUP.32 q0,r0
poly8x16_t vmovq_n_p8(poly8_t value); // VDUP.8 q0,r0
poly16x8_t vmovq_n_p16(poly16_t value); // VDUP.16 q0,r0
float32x4_t vmovq_n_f32(float32_t value); // VDUP.32 q0,r0
int64x2_t vmovq_n_s64(int64_t value); // VMOV d0,r0,r0
uint64x2_t vmovq_n_u64(uint64_t value); // VMOV d0,r0,r0
//Load all lanes of the vector to the value of a lane of a vector
//Combining vectors. These intrinsics join two 64 bit vectors into a single 128bit vector.
//Splitting vectors. These intrinsics split a 128 bit vector into 2 component 64 bit vectors
//Converting vectors. These intrinsics are used to convert vectors.
//Convert from float
int32x4_t vcvtq_s32_f32(float32x4_t a); // VCVT.S32.F32 q0, q0
uint32x4_t vcvtq_u32_f32(float32x4_t a); // VCVT.U32.F32 q0, q0
int32x4_t vcvtq_n_s32_f32(float32x4_t a, __constrange(1,32) int b); // VCVT.S32.F32 q0, q0, #32
uint32x4_t vcvtq_n_u32_f32(float32x4_t a, __constrange(1,32) int b); // VCVT.U32.F32 q0, q0, #32
//Convert to float
float32x4_t vcvtq_f32_s32(int32x4_t a); // VCVT.F32.S32 q0, q0
float32x4_t vcvtq_f32_u32(uint32x4_t a); // VCVT.F32.U32 q0, q0
float32x4_t vcvtq_n_f32_s32(int32x4_t a, __constrange(1,32) int b); // VCVT.F32.S32 q0, q0, #32
float32x4_t vcvtq_n_f32_u32(uint32x4_t a, __constrange(1,32) int b); // VCVT.F32.U32 q0, q0, #32
//Vector narrow integer
//Vector long move
//Vector saturating narrow integer
//Vector saturating narrow integer signed->unsigned
//Table look up
//Extended table look up intrinsics
//Operations with a scalar value
//Vector multiply accumulate with scalar
//Vector widening multiply accumulate with scalar
//Vector widening saturating doubling multiply accumulate with scalar
//Vector multiply subtract with scalar
//Vector widening multiply subtract with scalar
//Vector widening saturating doubling multiply subtract with scalar
//Vector multiply by scalar
int16x8_t vmulq_n_s16(int16x8_t a, int16_t b); // VMUL.I16 q0,q0,d0[0]
int32x4_t vmulq_n_s32(int32x4_t a, int32_t b); // VMUL.I32 q0,q0,d0[0]
float32x4_t vmulq_n_f32(float32x4_t a, float32_t b); // VMUL.F32 q0,q0,d0[0]
uint16x8_t vmulq_n_u16(uint16x8_t a, uint16_t b); // VMUL.I16 q0,q0,d0[0]
uint32x4_t vmulq_n_u32(uint32x4_t a, uint32_t b); // VMUL.I32 q0,q0,d0[0]
//Vector long multiply with scalar
//Vector long multiply by scalar
//Vector saturating doubling long multiply with scalar
//Vector saturating doubling long multiply by scalar
//Vector saturating doubling multiply high with scalar
int16x8_t vqdmulhq_n_s16(int16x8_t vec1, int16_t val2); // VQDMULH.S16 q0,q0,d0[0]
int32x4_t vqdmulhq_n_s32(int32x4_t vec1, int32_t val2); // VQDMULH.S32 q0,q0,d0[0]
//Vector saturating doubling multiply high by scalar
//Vector saturating rounding doubling multiply high with scalar
int16x8_t vqrdmulhq_n_s16(int16x8_t vec1, int16_t val2); // VQRDMULH.S16 q0,q0,d0[0]
int32x4_t vqrdmulhq_n_s32(int32x4_t vec1, int32_t val2); // VQRDMULH.S32 q0,q0,d0[0]
//Vector rounding saturating doubling multiply high by scalar
//Vector multiply accumulate with scalar
int16x8_t vmlaq_n_s16(int16x8_t a, int16x8_t b, int16_t c); // VMLA.I16 q0, q0, d0[0]
int32x4_t vmlaq_n_s32(int32x4_t a, int32x4_t b, int32_t c); // VMLA.I32 q0, q0, d0[0]
uint16x8_t vmlaq_n_u16(uint16x8_t a, uint16x8_t b, uint16_t c); // VMLA.I16 q0, q0, d0[0]
uint32x4_t vmlaq_n_u32(uint32x4_t a, uint32x4_t b, uint32_t c); // VMLA.I32 q0, q0, d0[0]
float32x4_t vmlaq_n_f32(float32x4_t a, float32x4_t b, float32_t c); // VMLA.F32 q0, q0, d0[0]
//Vector widening multiply accumulate with scalar
//Vector widening saturating doubling multiply accumulate with scalar
//Vector multiply subtract with scalar
int16x8_t vmlsq_n_s16(int16x8_t a, int16x8_t b, int16_t c); // VMLS.I16 q0, q0, d0[0]
int32x4_t vmlsq_n_s32(int32x4_t a, int32x4_t b, int32_t c); // VMLS.I32 q0, q0, d0[0]
uint16x8_t vmlsq_n_u16(uint16x8_t a, uint16x8_t b, uint16_t c); // VMLS.I16 q0, q0, d0[0]
uint32x4_t vmlsq_n_u32(uint32x4_t a, uint32x4_t b, uint32_t c); // VMLS.I32 q0, q0, d0[0]
float32x4_t vmlsq_n_f32(float32x4_t a, float32x4_t b, float32_t c); // VMLS.F32 q0, q0, d0[0]
//Vector widening multiply subtract with scalar
//Vector widening saturating doubling multiply subtract with scalar
//Vector extract
int8x16_t vextq_s8(int8x16_t a, int8x16_t b, __constrange(0,15) int c); // VEXT.8 q0,q0,q0,#0
uint8x16_t vextq_u8(uint8x16_t a, uint8x16_t b, __constrange(0,15) int c); // VEXT.8 q0,q0,q0,#0
poly8x16_t vextq_p8(poly8x16_t a, poly8x16_t b, __constrange(0,15) int c); // VEXT.8 q0,q0,q0,#0
int16x8_t vextq_s16(int16x8_t a, int16x8_t b, __constrange(0,7) int c); // VEXT.16 q0,q0,q0,#0
uint16x8_t vextq_u16(uint16x8_t a, uint16x8_t b, __constrange(0,7) int c); // VEXT.16 q0,q0,q0,#0
poly16x8_t vextq_p16(poly16x8_t a, poly16x8_t b, __constrange(0,7) int c); // VEXT.16 q0,q0,q0,#0
int32x4_t vextq_s32(int32x4_t a, int32x4_t b, __constrange(0,3) int c); // VEXT.32 q0,q0,q0,#0
uint32x4_t vextq_u32(uint32x4_t a, uint32x4_t b, __constrange(0,3) int c); // VEXT.32 q0,q0,q0,#0
int64x2_t vextq_s64(int64x2_t a, int64x2_t b, __constrange(0,1) int c); // VEXT.64 q0,q0,q0,#0
uint64x2_t vextq_u64(uint64x2_t a, uint64x2_t b, __constrange(0,1) int c); // VEXT.64 q0,q0,q0,#0
float32x4_t vextq_f32(float32x4_t a, float32x4_t b, __constrange(0,3) float c); // VEXT.32 q0,q0,q0,#0
//Reverse vector elements (swap endianness). VREVn.m reverses the order of the m-bit lanes within a set that is n bits wide.
int8x16_t vrev64q_s8(int8x16_t vec); // VREV64.8 q0,q0
int16x8_t vrev64q_s16(int16x8_t vec); // VREV64.16 q0,q0
int32x4_t vrev64q_s32(int32x4_t vec); // VREV64.32 q0,q0
uint8x16_t vrev64q_u8(uint8x16_t vec); // VREV64.8 q0,q0
uint16x8_t vrev64q_u16(uint16x8_t vec); // VREV64.16 q0,q0
uint32x4_t vrev64q_u32(uint32x4_t vec); // VREV64.32 q0,q0
poly8x16_t vrev64q_p8(poly8x16_t vec); // VREV64.8 q0,q0
poly16x8_t vrev64q_p16(poly16x8_t vec); // VREV64.16 q0,q0
float32x4_t vrev64q_f32(float32x4_t vec); // VREV64.32 q0,q0
int8x16_t vrev32q_s8(int8x16_t vec); // VREV32.8 q0,q0
int16x8_t vrev32q_s16(int16x8_t vec); // VREV32.16 q0,q0
uint8x16_t vrev32q_u8(uint8x16_t vec); // VREV32.8 q0,q0
uint16x8_t vrev32q_u16(uint16x8_t vec); // VREV32.16 q0,q0
poly8x16_t vrev32q_p8(poly8x16_t vec); // VREV32.8 q0,q0
poly16x8_t vrev32q_p16(poly16x8_t vec); // VREV32.16 q0,q0
int8x16_t vrev16q_s8(int8x16_t vec); // VREV16.8 q0,q0
uint8x16_t vrev16q_u8(uint8x16_t vec); // VREV16.8 q0,q0
poly8x16_t vrev16q_p8(poly8x16_t vec); // VREV16.8 q0,q0
//Other single operand arithmetic
//Absolute: Vd[i] = |Va[i]|
int8x16_t vabsq_s8(int8x16_t a); // VABS.S8 q0,q0
int16x8_t vabsq_s16(int16x8_t a); // VABS.S16 q0,q0
int32x4_t vabsq_s32(int32x4_t a); // VABS.S32 q0,q0
float32x4_t vabsq_f32(float32x4_t a); // VABS.F32 q0,q0
//Saturating absolute: Vd[i] = sat(|Va[i]|)
int8x16_t vqabsq_s8(int8x16_t a); // VQABS.S8 q0,q0
int16x8_t vqabsq_s16(int16x8_t a); // VQABS.S16 q0,q0
int32x4_t vqabsq_s32(int32x4_t a); // VQABS.S32 q0,q0
//Negate: Vd[i] = - Va[i]
int8x16_t vnegq_s8(int8x16_t a); // VNE//q0,q0
int16x8_t vnegq_s16(int16x8_t a); // VNE//q0,q0
int32x4_t vnegq_s32(int32x4_t a); // VNE//q0,q0
float32x4_t vnegq_f32(float32x4_t a); // VNE//q0,q0
//Saturating Negate: sat(Vd[i] = - Va[i])
int8x16_t vqnegq_s8(int8x16_t a); // VQNE//q0,q0
int16x8_t vqnegq_s16(int16x8_t a); // VQNE//q0,q0
int32x4_t vqnegq_s32(int32x4_t a); // VQNE//q0,q0
//Count leading sign bits
int8x16_t vclsq_s8(int8x16_t a); // VCLS.S8 q0,q0
int16x8_t vclsq_s16(int16x8_t a); // VCLS.S16 q0,q0
int32x4_t vclsq_s32(int32x4_t a); // VCLS.S32 q0,q0
//Count leading zeros
int8x16_t vclzq_s8(int8x16_t a); // VCLZ.I8 q0,q0
int16x8_t vclzq_s16(int16x8_t a); // VCLZ.I16 q0,q0
int32x4_t vclzq_s32(int32x4_t a); // VCLZ.I32 q0,q0
uint8x16_t vclzq_u8(uint8x16_t a); // VCLZ.I8 q0,q0
uint16x8_t vclzq_u16(uint16x8_t a); // VCLZ.I16 q0,q0
uint32x4_t vclzq_u32(uint32x4_t a); // VCLZ.I32 q0,q0
//Count number of set bits
uint8x16_t vcntq_u8(uint8x16_t a); // VCNT.8 q0,q0
int8x16_t vcntq_s8(int8x16_t a); // VCNT.8 q0,q0
poly8x16_t vcntq_p8(poly8x16_t a); // VCNT.8 q0,q0
//Reciprocal estimate
float32x4_t vrecpeq_f32(float32x4_t a); // VRECPE.F32 q0,q0
uint32x4_t vrecpeq_u32(uint32x4_t a); // VRECPE.U32 q0,q0
//Reciprocal square root estimate
float32x4_t vrsqrteq_f32(float32x4_t a); // VRSQRTE.F32 q0,q0
uint32x4_t vrsqrteq_u32(uint32x4_t a); // VRSQRTE.U32 q0,q0
//Logical operations
//Bitwise not
int8x16_t vmvnq_s8(int8x16_t a); // VMVN q0,q0
int16x8_t vmvnq_s16(int16x8_t a); // VMVN q0,q0
int32x4_t vmvnq_s32(int32x4_t a); // VMVN q0,q0
uint8x16_t vmvnq_u8(uint8x16_t a); // VMVN q0,q0
uint16x8_t vmvnq_u16(uint16x8_t a); // VMVN q0,q0
uint32x4_t vmvnq_u32(uint32x4_t a); // VMVN q0,q0
poly8x16_t vmvnq_p8(poly8x16_t a); // VMVN q0,q0
//Bitwise and
int8x16_t vandq_s8(int8x16_t a, int8x16_t b); // VAND q0,q0,q0
int16x8_t vandq_s16(int16x8_t a, int16x8_t b); // VAND q0,q0,q0
int32x4_t vandq_s32(int32x4_t a, int32x4_t b); // VAND q0,q0,q0
int64x2_t vandq_s64(int64x2_t a, int64x2_t b); // VAND q0,q0,q0
uint8x16_t vandq_u8(uint8x16_t a, uint8x16_t b); // VAND q0,q0,q0
uint16x8_t vandq_u16(uint16x8_t a, uint16x8_t b); // VAND q0,q0,q0
uint32x4_t vandq_u32(uint32x4_t a, uint32x4_t b); // VAND q0,q0,q0
uint64x2_t vandq_u64(uint64x2_t a, uint64x2_t b); // VAND q0,q0,q0
//Bitwise or
int8x16_t vorrq_s8(int8x16_t a, int8x16_t b); // VORR q0,q0,q0
int16x8_t vorrq_s16(int16x8_t a, int16x8_t b); // VORR q0,q0,q0
int32x4_t vorrq_s32(int32x4_t a, int32x4_t b); // VORR q0,q0,q0
int64x2_t vorrq_s64(int64x2_t a, int64x2_t b); // VORR q0,q0,q0
uint8x16_t vorrq_u8(uint8x16_t a, uint8x16_t b); // VORR q0,q0,q0
uint16x8_t vorrq_u16(uint16x8_t a, uint16x8_t b); // VORR q0,q0,q0
uint32x4_t vorrq_u32(uint32x4_t a, uint32x4_t b); // VORR q0,q0,q0
uint64x2_t vorrq_u64(uint64x2_t a, uint64x2_t b); // VORR q0,q0,q0
//Bitwise exclusive or (EOR or XOR)
int8x16_t veorq_s8(int8x16_t a, int8x16_t b); // VEOR q0,q0,q0
int16x8_t veorq_s16(int16x8_t a, int16x8_t b); // VEOR q0,q0,q0
int32x4_t veorq_s32(int32x4_t a, int32x4_t b); // VEOR q0,q0,q0
int64x2_t veorq_s64(int64x2_t a, int64x2_t b); // VEOR q0,q0,q0
uint8x16_t veorq_u8(uint8x16_t a, uint8x16_t b); // VEOR q0,q0,q0
uint16x8_t veorq_u16(uint16x8_t a, uint16x8_t b); // VEOR q0,q0,q0
uint32x4_t veorq_u32(uint32x4_t a, uint32x4_t b); // VEOR q0,q0,q0
uint64x2_t veorq_u64(uint64x2_t a, uint64x2_t b); // VEOR q0,q0,q0
//Bit Clear
int8x16_t vbicq_s8(int8x16_t a, int8x16_t b); // VBIC q0,q0,q0
int16x8_t vbicq_s16(int16x8_t a, int16x8_t b); // VBIC q0,q0,q0
int32x4_t vbicq_s32(int32x4_t a, int32x4_t b); // VBIC q0,q0,q0
int64x2_t vbicq_s64(int64x2_t a, int64x2_t b); // VBIC q0,q0,q0
uint8x16_t vbicq_u8(uint8x16_t a, uint8x16_t b); // VBIC q0,q0,q0
uint16x8_t vbicq_u16(uint16x8_t a, uint16x8_t b); // VBIC q0,q0,q0
uint32x4_t vbicq_u32(uint32x4_t a, uint32x4_t b); // VBIC q0,q0,q0
uint64x2_t vbicq_u64(uint64x2_t a, uint64x2_t b); // VBIC q0,q0,q0
//Bitwise OR complement
int8x16_t vornq_s8(int8x16_t a, int8x16_t b); // VORN q0,q0,q0
int16x8_t vornq_s16(int16x8_t a, int16x8_t b); // VORN q0,q0,q0
int32x4_t vornq_s32(int32x4_t a, int32x4_t b); // VORN q0,q0,q0
int64x2_t vornq_s64(int64x2_t a, int64x2_t b); // VORN q0,q0,q0
uint8x16_t vornq_u8(uint8x16_t a, uint8x16_t b); // VORN q0,q0,q0
uint16x8_t vornq_u16(uint16x8_t a, uint16x8_t b); // VORN q0,q0,q0
uint32x4_t vornq_u32(uint32x4_t a, uint32x4_t b); // VORN q0,q0,q0
uint64x2_t vornq_u64(uint64x2_t a, uint64x2_t b); // VORN q0,q0,q0
//Bitwise Select
int8x16_t vbslq_s8(uint8x16_t a, int8x16_t b, int8x16_t c); // VBSL q0,q0,q0
int16x8_t vbslq_s16(uint16x8_t a, int16x8_t b, int16x8_t c); // VBSL q0,q0,q0
int32x4_t vbslq_s32(uint32x4_t a, int32x4_t b, int32x4_t c); // VBSL q0,q0,q0
int64x2_t vbslq_s64(uint64x2_t a, int64x2_t b, int64x2_t c); // VBSL q0,q0,q0
uint8x16_t vbslq_u8(uint8x16_t a, uint8x16_t b, uint8x16_t c); // VBSL q0,q0,q0
uint16x8_t vbslq_u16(uint16x8_t a, uint16x8_t b, uint16x8_t c); // VBSL q0,q0,q0
uint32x4_t vbslq_u32(uint32x4_t a, uint32x4_t b, uint32x4_t c); // VBSL q0,q0,q0
uint64x2_t vbslq_u64(uint64x2_t a, uint64x2_t b, uint64x2_t c); // VBSL q0,q0,q0
float32x4_t vbslq_f32(uint32x4_t a, float32x4_t b, float32x4_t c); // VBSL q0,q0,q0
poly8x16_t vbslq_p8(uint8x16_t a, poly8x16_t b, poly8x16_t c); // VBSL q0,q0,q0
poly16x8_t vbslq_p16(uint16x8_t a, poly16x8_t b, poly16x8_t c); // VBSL q0,q0,q0
//Transposition operations
//Transpose elements
int8x16x2_t vtrnq_s8(int8x16_t a, int8x16_t b); // VTRN.8 q0,q0
int16x8x2_t vtrnq_s16(int16x8_t a, int16x8_t b); // VTRN.16 q0,q0
int32x4x2_t vtrnq_s32(int32x4_t a, int32x4_t b); // VTRN.32 q0,q0
uint8x16x2_t vtrnq_u8(uint8x16_t a, uint8x16_t b); // VTRN.8 q0,q0
uint16x8x2_t vtrnq_u16(uint16x8_t a, uint16x8_t b); // VTRN.16 q0,q0
uint32x4x2_t vtrnq_u32(uint32x4_t a, uint32x4_t b); // VTRN.32 q0,q0
float32x4x2_t vtrnq_f32(float32x4_t a, float32x4_t b); // VTRN.32 q0,q0
poly8x16x2_t vtrnq_p8(poly8x16_t a, poly8x16_t b); // VTRN.8 q0,q0
poly16x8x2_t vtrnq_p16(poly16x8_t a, poly16x8_t b); // VTRN.16 q0,q0
//Interleave elements
int8x16x2_t vzipq_s8(int8x16_t a, int8x16_t b); // VZIP.8 q0,q0
int16x8x2_t vzipq_s16(int16x8_t a, int16x8_t b); // VZIP.16 q0,q0
int32x4x2_t vzipq_s32(int32x4_t a, int32x4_t b); // VZIP.32 q0,q0

uint8x16x2_t vzipq_u8(uint8x16_t a, uint8x16_t b); // VZIP.8 q0,q0
uint16x8x2_t vzipq_u16(uint16x8_t a, uint16x8_t b); // VZIP.16 q0,q0
uint32x4x2_t vzipq_u32(uint32x4_t a, uint32x4_t b); // VZIP.32 q0,q0
float32x4x2_t vzipq_f32(float32x4_t a, float32x4_t b); // VZIP.32 q0,q0
poly8x16x2_t vzipq_p8(poly8x16_t a, poly8x16_t b); // VZIP.8 q0,q0
poly16x8x2_t vzipq_p16(poly16x8_t a, poly16x8_t b); // VZIP.16 q0,q0
//De-Interleave elements
int8x16x2_t vuzpq_s8(int8x16_t a, int8x16_t b); // VUZP.8 q0,q0
int16x8x2_t vuzpq_s16(int16x8_t a, int16x8_t b); // VUZP.16 q0,q0
int32x4x2_t vuzpq_s32(int32x4_t a, int32x4_t b); // VUZP.32 q0,q0
uint8x16x2_t vuzpq_u8(uint8x16_t a, uint8x16_t b); // VUZP.8 q0,q0
uint16x8x2_t vuzpq_u16(uint16x8_t a, uint16x8_t b); // VUZP.16 q0,q0
uint32x4x2_t vuzpq_u32(uint32x4_t a, uint32x4_t b); // VUZP.32 q0,q0
float32x4x2_t vuzpq_f32(float32x4_t a, float32x4_t b); // VUZP.32 q0,q0
poly8x16x2_t vuzpq_p8(poly8x16_t a, poly8x16_t b); // VUZP.8 q0,q0
poly16x8x2_t vuzpq_p16(poly16x8_t a, poly16x8_t b); // VUZP.16 q0,q0
]]

local hfile = ""

function wrapFunction1(line)
    local a,b,c,d = string.match(line, "^([%w_]+)%s+([%w_]+)%s*%(%s*([%w_]+)%s+([%w_]+)%s*%)")
    if a ~= nil and b ~= nil and c ~= nil and d ~= nil then
        io.write(a.." ".."np_"..b.."("..c.." "..d..")\n")
        io.write("{\n")
        io.write("\treturn "..b.."("..d..");\n")
        io.write("}\n")
        io.write("\n")
        hfile = hfile.."extern "..a.." ".."np_"..b.."("..c.." "..d..");\n"
        hfile = hfile.."#define "..b.." ".."np_"..b.."\n"
    end
end

function wrapFunction1b(line)
    local a,b,c,d = string.match(line, "^([%w_]+)%s+([%w_]+)%s*%(%s*__transfersize%(%d+%)%s*([%w_]+%s+const%s+%*)%s+([%w_]+)%s*%)")
    if a ~= nil and b ~= nil and c ~= nil and d ~= nil then
        io.write(a.." ".."np_"..b.."("..c.." "..d..")\n")
        io.write("{\n")
        io.write("\treturn "..b.."("..d..");\n")
        io.write("}\n")
        io.write("\n")
        hfile = hfile.."extern "..a.." ".."np_"..b.."("..c.." "..d..");\n"
        hfile = hfile.."#define "..b.." ".."np_"..b.."\n"
    end
end

function wrapFunction2(line)
    local a,b,c,d,e,f = string.match(line, "^([%w_]+)%s+([%w_]+)%s*%(%s*([%w_]+)%s+([%w_]+)%s*,%s*([%w_]+)%s*([%w_]+)%s*%)")
    if a ~= nil and b ~= nil and c ~= nil and d ~= nil and e ~= nil and f ~= nil then
        io.write(a.." ".."np_"..b.."("..c.." "..d..", "..e.." "..f..")\n")
        io.write("{\n")
        io.write("\treturn "..b.."("..d..", "..f..");\n")
        io.write("}\n")
        io.write("\n")
        hfile = hfile.."extern "..a.." ".."np_"..b.."("..c.." "..d..", "..e.." "..f..");\n"
        hfile = hfile.."#define "..b.." ".."np_"..b.."\n"
    end
end

function wrapFunction2b(line)
    local a,b,c,d,e,f = string.match(line, "^([%w_]+)%s+([%w_]+)%s*%(%s*__transfersize%(%d+%)%s*([%w_]+%s+const%s+%*)%s+([%w_]+)%s*,%s*([%w_]+)%s*([%w_]+)%s*%)")
    if a ~= nil and b ~= nil and c ~= nil and d ~= nil and e ~= nil and f ~= nil then
        io.write(a.." ".."np_"..b.."("..c.." "..d..", "..e.." "..f..")\n")
        io.write("{\n")
        io.write("\treturn "..b.."("..d..", "..f..");\n")
        io.write("}\n")
        io.write("\n")
        hfile = hfile.."extern "..a.." ".."np_"..b.."("..c.." "..d..", "..e.." "..f..");\n"
        hfile = hfile.."#define "..b.." ".."np_"..b.."\n"
    end
end

function wrapFunction3(line)
    local a,b,c,d,e,f,g,h = string.match(line, "^([%w_]+)%s+([%w_]+)%s*%(%s*([%w_]+)%s+([%w_]+)%s*,%s*([%w_]+)%s*([%w_]+)%s*%,%s*([%w_]+)%s*([%w_]+)%s*%)")
    if a ~= nil and b ~= nil and c ~= nil and d ~= nil and e ~= nil and f ~= nil and g ~= nil and h ~= nil then
        io.write(a.." ".."np_"..b.."("..c.." "..d..", "..e.." "..f..", "..g.." "..h..")\n")
        io.write("{\n")
        io.write("\treturn "..b.."("..d..", "..f..", "..h..");\n")
        io.write("}\n")
        io.write("\n")
        hfile = hfile.."extern "..a.." ".."np_"..b.."("..c.." "..d..", "..e.." "..f..", "..g.." "..h..");\n"
        hfile = hfile.."#define "..b.." ".."np_"..b.."\n"
    end
end

io.output("NEONvsSSE_layer.c")

for line in string.gmatch(functions, "[^\r\n]+") do
    wrapFunction1(line)
    wrapFunction1b(line)
    wrapFunction2(line)
    wrapFunction2b(line)
    wrapFunction3(line)
end

io.close()

io.output("NEONvsSSE_layer.h")
io.write(hfile)
io.close()
