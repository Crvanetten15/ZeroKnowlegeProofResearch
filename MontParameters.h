// number of bits in key
#define KEYBITS 1024

// maximal number of words required to store a bint;
// twice the space necessary to store a key, but allows
// for overflow during multiplication, albeit at a cost
// (in space and, to some degree, time)

#define PRIMELEN 64
#define PRIVKEYLEN 128
#define PUBKEYLEN 128

// The number of bytes in a word
#define WORDBYTES 1
#define WORDBITS 8

////////////////////////////////////////////////////////////////////////////
// structures
////////////////////////////////////////////////////////////////////////////

typedef struct Prime
{
  uint8_t value[PRIMELEN];
} Prime;

typedef struct PrivKey
{
  uint8_t value[PRIVKEYLEN];
} PrivKey;

typedef struct PubKey
{
  uint8_t value[PUBKEYLEN];
} PubKey;

Prime p;
Prime q;
PrivKey n;
word_t n1;
PrivKey nprime;
PrivKey r_inver;

/**

    p.value[0] = 0x0B;
    p.value[1] = 0xB8;
    p.value[2] = 0xDC;
    p.value[3] = 0x7A;
    p.value[4] = 0x1E;
    p.value[5] = 0xA8;
    p.value[6] = 0xF4;
    p.value[7] = 0xBA;
    p.value[8] = 0xAA;
    p.value[9] = 0x5F;
    p.value[10] = 0xF0;
    p.value[11] = 0x26;
    p.value[12] = 0xD3;
    p.value[13] = 0xED;
    p.value[14] = 0xF6;
    p.value[15] = 0x6F;

    p.value[16] = 0x82;
    p.value[17] = 0x79;
    p.value[18] = 0x35;
    p.value[19] = 0x11;
    p.value[20] = 0x30;
    p.value[21] = 0x21;
    p.value[22] = 0xD4;
    p.value[23] = 0x44;
    p.value[24] = 0x8A;
    p.value[25] = 0x18;
    p.value[26] = 0xF4;
    p.value[27] = 0x4C;
    p.value[28] = 0xC3;
    p.value[29] = 0x64;
    p.value[30] = 0x72;
    p.value[31] = 0x85;

    p.value[32] = 0x2C;
    p.value[33] = 0x9E;
    p.value[34] = 0x76;
    p.value[35] = 0x98;
    p.value[36] = 0xBE;
    p.value[37] = 0x87;
    p.value[38] = 0x77;
    p.value[39] = 0xCC;
    p.value[40] = 0x46;
    p.value[41] = 0xFF;
    p.value[42] = 0x92;
    p.value[43] = 0x85;
    p.value[44] = 0x47;
    p.value[45] = 0xE4;
    p.value[46] = 0x9E;
    p.value[47] = 0xCD;

    p.value[48] = 0x15;
    p.value[49] = 0xCF;
    p.value[50] = 0xAA;
    p.value[51] = 0x3A;
    p.value[52] = 0x77;
    p.value[53] = 0xDE;
    p.value[54] = 0x6D;
    p.value[55] = 0x4E;
    p.value[56] = 0xCC;
    p.value[57] = 0x20;
    p.value[58] = 0x32;
    p.value[59] = 0xA1;
    p.value[60] = 0x94;
    p.value[61] = 0x85;
    p.value[62] = 0x2A;
    p.value[63] = 0xFD;

    q.value[0] = 0x83;
    q.value[1] = 0x23;
    q.value[2] = 0x2C;
    q.value[3] = 0x6F;
    q.value[4] = 0xFB;
    q.value[5] = 0x08;
    q.value[6] = 0xB1;
    q.value[7] = 0x4B;
    q.value[8] = 0x0A;
    q.value[9] = 0x98;
    q.value[10] = 0x15;
    q.value[11] = 0xB5;
    q.value[12] = 0xEC;
    q.value[13] = 0xD6;
    q.value[14] = 0xCE;

    q.value[15] = 0x2D;
    q.value[16] = 0x6B;
    q.value[17] = 0x8A;
    q.value[18] = 0x75;
    q.value[19] = 0x8A;
    q.value[20] = 0xCC;
    q.value[21] = 0xBA;
    q.value[22] = 0x37;
    q.value[23] = 0xBA;
    q.value[24] = 0x2F;
    q.value[25] = 0xA3;
    q.value[26] = 0xF9;
    q.value[27] = 0x6B;
    q.value[28] = 0xA8;
    q.value[29] = 0xE5;
    q.value[30] = 0xA8;
    q.value[31] = 0xE8;
    q.value[32] = 0x42;
    q.value[33] = 0x71;
    q.value[34] = 0xEB;
    q.value[35] = 0xEC;
    q.value[36] = 0xD5;
    q.value[37] = 0x06;
    q.value[38] = 0xB1;
    q.value[39] = 0x4D;
    q.value[40] = 0xEE;
    q.value[41] = 0x4F;
    q.value[42] = 0x2F;
    q.value[43] = 0x27;
    q.value[44] = 0xBA;
    q.value[45] = 0xB4;
    q.value[46] = 0x0F;
    q.value[47] = 0xEE;

    q.value[48] = 0x65;
    q.value[49] = 0x8A;
    q.value[50] = 0x96;
    q.value[51] = 0xA7;
    q.value[52] = 0xC0;
    q.value[53] = 0xF2;
    q.value[54] = 0x72;
    q.value[55] = 0xFD;
    q.value[56] = 0xA3;
    q.value[57] = 0x6B;
    q.value[58] = 0x49;
    q.value[59] = 0xB3;
    q.value[60] = 0x97;
    q.value[61] = 0x57;
    q.value[62] = 0xB9;
    q.value[63] = 0xC8;

    nprime.value[0] = 0x9f;
    nprime.value[1] = 0x4a;
    nprime.value[2] = 0xb8;
    nprime.value[3] = 0xc7;
    nprime.value[4] = 0xa0;
    nprime.value[5] = 0xea;
    nprime.value[6] = 0x50;
    nprime.value[7] = 0xa3;
    nprime.value[8] = 0x22;
    nprime.value[9] = 0x4d;
    nprime.value[10] = 0xe3;
    nprime.value[11] = 0xd2;
    nprime.value[12] = 0x3e;
    nprime.value[13] = 0xa3;
    nprime.value[14] = 0xd6;
    nprime.value[15] = 0x99;

    nprime.value[16] = 0x0f;
    nprime.value[17] = 0x04;
    nprime.value[18] = 0x02;
    nprime.value[19] = 0xd6;
    nprime.value[20] = 0xd2;
    nprime.value[21] = 0x4a;
    nprime.value[22] = 0x41;
    nprime.value[23] = 0xb9;
    nprime.value[24] = 0x9d;
    nprime.value[25] = 0xa4;
    nprime.value[26] = 0x3c;
    nprime.value[27] = 0xdd;
    nprime.value[28] = 0x3c;
    nprime.value[29] = 0x78;
    nprime.value[30] = 0x5f;
    nprime.value[31] = 0x45;

    nprime.value[32] = 0x61;
    nprime.value[33] = 0x65;
    nprime.value[34] = 0x4e;
    nprime.value[35] = 0xf4;
    nprime.value[36] = 0xcb;
    nprime.value[37] = 0xb1;
    nprime.value[38] = 0xa8;
    nprime.value[39] = 0x7f;
    nprime.value[40] = 0x20;
    nprime.value[41] = 0x1b;
    nprime.value[42] = 0x67;
    nprime.value[43] = 0xf3;
    nprime.value[44] = 0x80;
    nprime.value[45] = 0x85;
    nprime.value[46] = 0x6c;
    nprime.value[47] = 0x21;

    nprime.value[48] = 0x4c;
    nprime.value[49] = 0xd6;
    nprime.value[50] = 0xd9;
    nprime.value[51] = 0x29;
    nprime.value[52] = 0xcd;
    nprime.value[53] = 0x68;
    nprime.value[54] = 0xd4;
    nprime.value[55] = 0x7a;
    nprime.value[56] = 0x4c;
    nprime.value[57] = 0x61;
    nprime.value[58] = 0xd8;
    nprime.value[59] = 0x9d;
    nprime.value[60] = 0xce;
    nprime.value[61] = 0x49;
    nprime.value[62] = 0xbb;
    nprime.value[63] = 0xbb;

    nprime.value[64] = 0x59;
    nprime.value[65] = 0x17;
    nprime.value[66] = 0x1e;
    nprime.value[67] = 0x23;
    nprime.value[68] = 0xef;
    nprime.value[69] = 0x3c;
    nprime.value[70] = 0xff;
    nprime.value[71] = 0x1c;
    nprime.value[72] = 0x65;
    nprime.value[73] = 0xfa;
    nprime.value[74] = 0xce;
    nprime.value[75] = 0x42;
    nprime.value[76] = 0x3f;
    nprime.value[77] = 0x9b;
    nprime.value[78] = 0xce;
    nprime.value[79] = 0x7d;


    nprime.value[80] = 0x47;
    nprime.value[81] = 0x1c;
    nprime.value[82] = 0xe4;
    nprime.value[83] = 0x37;
    nprime.value[84] = 0x93;
    nprime.value[85] = 0x61;
    nprime.value[86] = 0x86;
    nprime.value[87] = 0x53;
    nprime.value[88] = 0x24;
    nprime.value[89] = 0x76;
    nprime.value[90] = 0x74;
    nprime.value[91] = 0x0d;
    nprime.value[92] = 0x8c;
    nprime.value[93] = 0x91;
    nprime.value[94] = 0xab;
    nprime.value[95] = 0xc6;

    nprime.value[96] = 0x8b;
    nprime.value[97] = 0x67;
    nprime.value[98] = 0x1f;
    nprime.value[99] = 0xd5;
    nprime.value[100] = 0xd0;
    nprime.value[101] = 0x18;
    nprime.value[102] = 0x4f;
    nprime.value[103] = 0xf5;
    nprime.value[104] = 0xee;
    nprime.value[105] = 0x27;
    nprime.value[106] = 0x27;
    nprime.value[107] = 0xe3;
    nprime.value[108] = 0x9b;
    nprime.value[109] = 0xd6;
    nprime.value[110] = 0x5b;
    nprime.value[111] = 0x9f;

    nprime.value[112] = 0x30;
    nprime.value[113] = 0x41;
    nprime.value[114] = 0x3d;
    nprime.value[115] = 0x0d;
    nprime.value[116] = 0x1b;
    nprime.value[117] = 0x31;
    nprime.value[118] = 0x43;
    nprime.value[119] = 0x83;
    nprime.value[120] = 0x3a;
    nprime.value[121] = 0x3b;
    nprime.value[122] = 0xad;
    nprime.value[123] = 0x9f;
    nprime.value[124] = 0x3d;
    nprime.value[125] = 0xb8;
    nprime.value[126] = 0x1d;
    nprime.value[127] = 0xb0;

    r_inver.value[0] = 0x67;
    r_inver.value[1] = 0x38;
    r_inver.value[2] = 0xb6;
    r_inver.value[3] = 0xb1;
    r_inver.value[4] = 0x74;
    r_inver.value[5] = 0x24;
    r_inver.value[6] = 0x1d;
    r_inver.value[7] = 0x9c;
    r_inver.value[8] = 0x7b;
    r_inver.value[9] = 0x12;
    r_inver.value[10] = 0x41;
    r_inver.value[11] = 0xed;
    r_inver.value[12] = 0xeb;
    r_inver.value[13] = 0x14;
    r_inver.value[14] = 0x7a;
    r_inver.value[15] = 0x02;

    r_inver.value[16] = 0xcc;
    r_inver.value[17] = 0x62;
    r_inver.value[18] = 0x4c;
    r_inver.value[19] = 0xab;
    r_inver.value[20] = 0xbb;
    r_inver.value[21] = 0xbb;
    r_inver.value[22] = 0xd2;
    r_inver.value[23] = 0xbe;
    r_inver.value[24] = 0xdc;
    r_inver.value[25] = 0x39;
    r_inver.value[26] = 0x09;
    r_inver.value[27] = 0x06;
    r_inver.value[28] = 0xd5;
    r_inver.value[29] = 0x76;
    r_inver.value[30] = 0xc0;
    r_inver.value[31] = 0x0e;

    r_inver.value[32] = 0xc5;
    r_inver.value[33] = 0x10;
    r_inver.value[34] = 0xa9;
    r_inver.value[35] = 0xdf;
    r_inver.value[36] = 0x9a;
    r_inver.value[37] = 0xec;
    r_inver.value[38] = 0x56;
    r_inver.value[39] = 0x1f;
    r_inver.value[40] = 0x78;
    r_inver.value[41] = 0xfa;
    r_inver.value[42] = 0x66;
    r_inver.value[43] = 0xc2;
    r_inver.value[44] = 0x8a;
    r_inver.value[45] = 0xe8;
    r_inver.value[46] = 0xc8;
    r_inver.value[47] = 0x45;

    r_inver.value[48] = 0x56;
    r_inver.value[49] = 0xe3;
    r_inver.value[50] = 0x65;
    r_inver.value[51] = 0xf5;
    r_inver.value[52] = 0x39;
    r_inver.value[53] = 0xd0;
    r_inver.value[54] = 0xcf;
    r_inver.value[55] = 0x41;
    r_inver.value[56] = 0xe9;
    r_inver.value[57] = 0x88;
    r_inver.value[58] = 0x0e;
    r_inver.value[59] = 0xce;
    r_inver.value[60] = 0x2a;
    r_inver.value[61] = 0x62;
    r_inver.value[62] = 0xea;
    r_inver.value[63] = 0x82;

    r_inver.value[64] = 0x12;
    r_inver.value[65] = 0xca;
    r_inver.value[66] = 0xe4;
    r_inver.value[67] = 0xf9;
    r_inver.value[68] = 0x5d;
    r_inver.value[69] = 0x16;
    r_inver.value[70] = 0xbf;
    r_inver.value[71] = 0x75;
    r_inver.value[72] = 0xf4;
    r_inver.value[73] = 0xbd;
    r_inver.value[74] = 0xef;
    r_inver.value[75] = 0x11;
    r_inver.value[76] = 0x69;
    r_inver.value[77] = 0xef;
    r_inver.value[78] = 0x9e;
    r_inver.value[79] = 0x7b;

    r_inver.value[80] = 0x5a;
    r_inver.value[81] = 0xa3;
    r_inver.value[82] = 0xcd;
    r_inver.value[83] = 0x72;
    r_inver.value[84] = 0xd6;
    r_inver.value[85] = 0x93;
    r_inver.value[86] = 0x8d;
    r_inver.value[87] = 0x70;
    r_inver.value[88] = 0xa8;
    r_inver.value[89] = 0x30;
    r_inver.value[90] = 0xea;
    r_inver.value[91] = 0xee;
    r_inver.value[92] = 0x6b;
    r_inver.value[93] = 0xe3;
    r_inver.value[94] = 0x38;
    r_inver.value[95] = 0x24;

    r_inver.value[96] = 0x81;
    r_inver.value[97] = 0xba;
    r_inver.value[98] = 0xdf;
    r_inver.value[99] = 0x06;
    r_inver.value[100] = 0xe2;
    r_inver.value[101] = 0x78;
    r_inver.value[102] = 0x8c;
    r_inver.value[103] = 0xc6;
    r_inver.value[104] = 0xe7;
    r_inver.value[105] = 0xd5;
    r_inver.value[106] = 0xa7;
    r_inver.value[107] = 0x1a;
    r_inver.value[108] = 0x8c;
    r_inver.value[109] = 0x5d;
    r_inver.value[110] = 0x5c;
    r_inver.value[111] = 0x17;

    r_inver.value[112] = 0x13;
    r_inver.value[113] = 0xe2;
    r_inver.value[114] = 0xe1;
    r_inver.value[115] = 0xe6;
    r_inver.value[116] = 0x7e;
    r_inver.value[117] = 0x2c;
    r_inver.value[118] = 0x96;
    r_inver.value[119] = 0x44;
    r_inver.value[120] = 0x04;
    r_inver.value[121] = 0x3a;
    r_inver.value[122] = 0x69;
    r_inver.value[123] = 0x2a;
    r_inver.value[124] = 0x48;
    r_inver.value[125] = 0x65;
    r_inver.value[126] = 0x8f;
    r_inver.value[127] = 0x88;

**/