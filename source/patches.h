#define RF_PATCH( name , tid ) \
  { \
    "region_free_" name, \
    tid, \
    -16, 1, \
    8,  { 0x00, 0x00, 0x55, 0xE3, 0x01, 0x10, 0xA0, 0xE3 }, \
    8, { 0x01, 0x00, 0xA0, 0xE3, 0x1E, 0xFF, 0x2F, 0xE1 } \
  }

#define VER_PATCH(name, tid) \
  { \
    "mset_ver_" name, \
    tid, \
    0, 1, \
    8, (u8*)u"Ver.", \
    8, (u8*)u"+Ldr" \
  }

typedef struct {
	char patch_name[64];
	u64 titleid;
	int offset;
	int count;

    int pattern_size;
	unsigned char pattern[64];

	int patch_size;
	unsigned char patch[64];
} __attribute__((packed)) patch_t;

static patch_t patches_list[] =
{
  {
    "secureinfo_sigchk",
    0x0004013000001702LL,
    0, 1,
    5, { 0x06, 0x46, 0x10, 0x48, 0xFC },
    2, { 0x00, 0x26 }
  },
  {
    "block_updates",
    0x0004013000002C02LL,
    0, 1,
    4, { 0x25, 0x79, 0x0B, 0x99 },
    2, { 0xE3, 0xA0 }
  },
  {
    "block_eshop_updates",
    0x0004013000002C02LL,
    0, 1,
    4, { 0x30, 0xB5, 0xF1, 0xB0 },
    6, { 0x00, 0x20, 0x08, 0x60, 0x70, 0x47 }
  },
  {
    "stop_updates",
    0x0004013000008002LL,
    0, 2,
    4, { 0x0C, 0x18, 0xE1, 0xD8 },
    4, { 0x0B, 0x18, 0x21, 0xC8 }
  },
  RF_PATCH( "usa" , 0x0004003000008F02LL ) , // USA Menu
  RF_PATCH( "jpn" , 0x0004003000008202LL ) , // JPN Menu
  RF_PATCH( "eur" , 0x0004003000009802LL ) , // EUR Menu
  RF_PATCH( "chn" , 0x000400300000A102LL ) , // CHN Menu
  RF_PATCH( "kor" , 0x000400300000A902LL ) , // KOR Menu
  RF_PATCH( "twn" , 0x000400300000B102LL ) , // TWN Menu
};

const static int patches_count = 10;
