typedef unsigned char   undefined;

typedef pointer32 ImageBaseOffset32;

typedef unsigned char    bool;
typedef unsigned char    byte;
typedef unsigned int    dword;
typedef long long    longlong;
typedef unsigned int    uint;
typedef unsigned long    ulong;
typedef unsigned char    undefined1;
typedef unsigned short    undefined2;
typedef unsigned int    undefined4;
typedef unsigned long long    undefined8;
typedef unsigned short    ushort;
typedef unsigned short    word;
typedef union IMAGE_RESOURCE_DIRECTORY_ENTRY_DirectoryUnion IMAGE_RESOURCE_DIRECTORY_ENTRY_DirectoryUnion, *PIMAGE_RESOURCE_DIRECTORY_ENTRY_DirectoryUnion;

typedef struct IMAGE_RESOURCE_DIRECTORY_ENTRY_DirectoryStruct IMAGE_RESOURCE_DIRECTORY_ENTRY_DirectoryStruct, *PIMAGE_RESOURCE_DIRECTORY_ENTRY_DirectoryStruct;

struct IMAGE_RESOURCE_DIRECTORY_ENTRY_DirectoryStruct {
    dword OffsetToDirectory;
    dword DataIsDirectory;
};

union IMAGE_RESOURCE_DIRECTORY_ENTRY_DirectoryUnion {
    dword OffsetToData;
    struct IMAGE_RESOURCE_DIRECTORY_ENTRY_DirectoryStruct IMAGE_RESOURCE_DIRECTORY_ENTRY_DirectoryStruct;
};

typedef struct tagMSG tagMSG, *PtagMSG;

typedef struct tagMSG MSG;

typedef struct HWND__ HWND__, *PHWND__;

typedef struct HWND__ * HWND;

typedef uint UINT;

typedef uint UINT_PTR;

typedef UINT_PTR WPARAM;

typedef long LONG_PTR;

typedef LONG_PTR LPARAM;

typedef ulong DWORD;

typedef struct tagPOINT tagPOINT, *PtagPOINT;

typedef struct tagPOINT POINT;

typedef long LONG;

struct tagPOINT {
    LONG x;
    LONG y;
};

struct tagMSG {
    HWND hwnd;
    UINT message;
    WPARAM wParam;
    LPARAM lParam;
    DWORD time;
    POINT pt;
};

struct HWND__ {
    int unused;
};

typedef struct tagWNDCLASSA tagWNDCLASSA, *PtagWNDCLASSA;

typedef LONG_PTR LRESULT;

typedef LRESULT (* WNDPROC)(HWND, UINT, WPARAM, LPARAM);

typedef struct HINSTANCE__ HINSTANCE__, *PHINSTANCE__;

typedef struct HINSTANCE__ * HINSTANCE;

typedef struct HICON__ HICON__, *PHICON__;

typedef struct HICON__ * HICON;

typedef HICON HCURSOR;

typedef struct HBRUSH__ HBRUSH__, *PHBRUSH__;

typedef struct HBRUSH__ * HBRUSH;

typedef char CHAR;

typedef CHAR * LPCSTR;

struct HBRUSH__ {
    int unused;
};

struct tagWNDCLASSA {
    UINT style;
    WNDPROC lpfnWndProc;
    int cbClsExtra;
    int cbWndExtra;
    HINSTANCE hInstance;
    HICON hIcon;
    HCURSOR hCursor;
    HBRUSH hbrBackground;
    LPCSTR lpszMenuName;
    LPCSTR lpszClassName;
};

struct HICON__ {
    int unused;
};

struct HINSTANCE__ {
    int unused;
};

typedef struct tagMSG * LPMSG;

typedef struct tagWNDCLASSA WNDCLASSA;

typedef CHAR * LPSTR;

typedef void * HANDLE;

typedef struct IMAGE_DOS_HEADER IMAGE_DOS_HEADER, *PIMAGE_DOS_HEADER;

struct IMAGE_DOS_HEADER {
    char e_magic[2]; // Magic number
    word e_cblp; // Bytes of last page
    word e_cp; // Pages in file
    word e_crlc; // Relocations
    word e_cparhdr; // Size of header in paragraphs
    word e_minalloc; // Minimum extra paragraphs needed
    word e_maxalloc; // Maximum extra paragraphs needed
    word e_ss; // Initial (relative) SS value
    word e_sp; // Initial SP value
    word e_csum; // Checksum
    word e_ip; // Initial IP value
    word e_cs; // Initial (relative) CS value
    word e_lfarlc; // File address of relocation table
    word e_ovno; // Overlay number
    word e_res[4][4]; // Reserved words
    word e_oemid; // OEM identifier (for e_oeminfo)
    word e_oeminfo; // OEM information; e_oemid specific
    word e_res2[10][10]; // Reserved words
    dword e_lfanew; // File address of new exe header
    byte e_program[192]; // Actual DOS program
};

typedef ulong ULONG_PTR;

typedef ULONG_PTR DWORD_PTR;

typedef struct tagPOINT * LPPOINT;

typedef struct HPEN__ HPEN__, *PHPEN__;

typedef struct HPEN__ * HPEN;

struct HPEN__ {
    int unused;
};

typedef struct HDC__ HDC__, *PHDC__;

struct HDC__ {
    int unused;
};

typedef ushort WORD;

typedef void * LPVOID;

typedef HINSTANCE HMODULE;

typedef struct HMENU__ HMENU__, *PHMENU__;

typedef struct HMENU__ * HMENU;

struct HMENU__ {
    int unused;
};

typedef int (* FARPROC)(void);

typedef struct HDC__ * HDC;

typedef struct tagRECT tagRECT, *PtagRECT;

struct tagRECT {
    LONG left;
    LONG top;
    LONG right;
    LONG bottom;
};

typedef WORD ATOM;

typedef struct tagRECT * LPRECT;

typedef void * HGDIOBJ;

typedef int BOOL;

typedef DWORD COLORREF;

typedef struct IMAGE_OPTIONAL_HEADER32 IMAGE_OPTIONAL_HEADER32, *PIMAGE_OPTIONAL_HEADER32;

typedef struct IMAGE_DATA_DIRECTORY IMAGE_DATA_DIRECTORY, *PIMAGE_DATA_DIRECTORY;

struct IMAGE_DATA_DIRECTORY {
    ImageBaseOffset32 VirtualAddress;
    dword Size;
};

struct IMAGE_OPTIONAL_HEADER32 {
    word Magic;
    byte MajorLinkerVersion;
    byte MinorLinkerVersion;
    dword SizeOfCode;
    dword SizeOfInitializedData;
    dword SizeOfUninitializedData;
    ImageBaseOffset32 AddressOfEntryPoint;
    ImageBaseOffset32 BaseOfCode;
    ImageBaseOffset32 BaseOfData;
    pointer32 ImageBase;
    dword SectionAlignment;
    dword FileAlignment;
    word MajorOperatingSystemVersion;
    word MinorOperatingSystemVersion;
    word MajorImageVersion;
    word MinorImageVersion;
    word MajorSubsystemVersion;
    word MinorSubsystemVersion;
    dword Win32VersionValue;
    dword SizeOfImage;
    dword SizeOfHeaders;
    dword CheckSum;
    word Subsystem;
    word DllCharacteristics;
    dword SizeOfStackReserve;
    dword SizeOfStackCommit;
    dword SizeOfHeapReserve;
    dword SizeOfHeapCommit;
    dword LoaderFlags;
    dword NumberOfRvaAndSizes;
    struct IMAGE_DATA_DIRECTORY DataDirectory[16];
};

typedef struct IMAGE_RESOURCE_DIRECTORY_ENTRY_NameStruct IMAGE_RESOURCE_DIRECTORY_ENTRY_NameStruct, *PIMAGE_RESOURCE_DIRECTORY_ENTRY_NameStruct;

struct IMAGE_RESOURCE_DIRECTORY_ENTRY_NameStruct {
    dword NameOffset;
    dword NameIsString;
};

typedef struct IMAGE_FILE_HEADER IMAGE_FILE_HEADER, *PIMAGE_FILE_HEADER;

struct IMAGE_FILE_HEADER {
    word Machine; // 332
    word NumberOfSections;
    dword TimeDateStamp;
    dword PointerToSymbolTable;
    dword NumberOfSymbols;
    word SizeOfOptionalHeader;
    word Characteristics;
};

typedef struct IMAGE_NT_HEADERS32 IMAGE_NT_HEADERS32, *PIMAGE_NT_HEADERS32;

struct IMAGE_NT_HEADERS32 {
    char Signature[4];
    struct IMAGE_FILE_HEADER FileHeader;
    struct IMAGE_OPTIONAL_HEADER32 OptionalHeader;
};

typedef union IMAGE_RESOURCE_DIRECTORY_ENTRY IMAGE_RESOURCE_DIRECTORY_ENTRY, *PIMAGE_RESOURCE_DIRECTORY_ENTRY;

typedef union IMAGE_RESOURCE_DIRECTORY_ENTRY_NameUnion IMAGE_RESOURCE_DIRECTORY_ENTRY_NameUnion, *PIMAGE_RESOURCE_DIRECTORY_ENTRY_NameUnion;

union IMAGE_RESOURCE_DIRECTORY_ENTRY_NameUnion {
    struct IMAGE_RESOURCE_DIRECTORY_ENTRY_NameStruct IMAGE_RESOURCE_DIRECTORY_ENTRY_NameStruct;
    dword Name;
    word Id;
};

union IMAGE_RESOURCE_DIRECTORY_ENTRY {
    union IMAGE_RESOURCE_DIRECTORY_ENTRY_NameUnion NameUnion;
    union IMAGE_RESOURCE_DIRECTORY_ENTRY_DirectoryUnion DirectoryUnion;
};

typedef struct IMAGE_SECTION_HEADER IMAGE_SECTION_HEADER, *PIMAGE_SECTION_HEADER;

typedef union Misc Misc, *PMisc;

typedef enum SectionFlags {
    IMAGE_SCN_TYPE_NO_PAD=8,
    IMAGE_SCN_RESERVED_0001=16,
    IMAGE_SCN_CNT_CODE=32,
    IMAGE_SCN_CNT_INITIALIZED_DATA=64,
    IMAGE_SCN_CNT_UNINITIALIZED_DATA=128,
    IMAGE_SCN_LNK_OTHER=256,
    IMAGE_SCN_LNK_INFO=512,
    IMAGE_SCN_RESERVED_0040=1024,
    IMAGE_SCN_LNK_REMOVE=2048,
    IMAGE_SCN_LNK_COMDAT=4096,
    IMAGE_SCN_GPREL=32768,
    IMAGE_SCN_MEM_16BIT=131072,
    IMAGE_SCN_MEM_PURGEABLE=131072,
    IMAGE_SCN_MEM_LOCKED=262144,
    IMAGE_SCN_MEM_PRELOAD=524288,
    IMAGE_SCN_ALIGN_1BYTES=1048576,
    IMAGE_SCN_ALIGN_2BYTES=2097152,
    IMAGE_SCN_ALIGN_4BYTES=3145728,
    IMAGE_SCN_ALIGN_8BYTES=4194304,
    IMAGE_SCN_ALIGN_16BYTES=5242880,
    IMAGE_SCN_ALIGN_32BYTES=6291456,
    IMAGE_SCN_ALIGN_64BYTES=7340032,
    IMAGE_SCN_ALIGN_128BYTES=8388608,
    IMAGE_SCN_ALIGN_256BYTES=9437184,
    IMAGE_SCN_ALIGN_512BYTES=10485760,
    IMAGE_SCN_ALIGN_1024BYTES=11534336,
    IMAGE_SCN_ALIGN_2048BYTES=12582912,
    IMAGE_SCN_ALIGN_4096BYTES=13631488,
    IMAGE_SCN_ALIGN_8192BYTES=14680064,
    IMAGE_SCN_LNK_NRELOC_OVFL=16777216,
    IMAGE_SCN_MEM_DISCARDABLE=33554432,
    IMAGE_SCN_MEM_NOT_CACHED=67108864,
    IMAGE_SCN_MEM_NOT_PAGED=134217728,
    IMAGE_SCN_MEM_SHARED=268435456,
    IMAGE_SCN_MEM_EXECUTE=536870912,
    IMAGE_SCN_MEM_READ=1073741824,
    IMAGE_SCN_MEM_WRITE=2147483648
} SectionFlags;

union Misc {
    dword PhysicalAddress;
    dword VirtualSize;
};

struct IMAGE_SECTION_HEADER {
    char Name[8];
    union Misc Misc;
    ImageBaseOffset32 VirtualAddress;
    dword SizeOfRawData;
    dword PointerToRawData;
    dword PointerToRelocations;
    dword PointerToLinenumbers;
    word NumberOfRelocations;
    word NumberOfLinenumbers;
    enum SectionFlags Characteristics;
};

typedef struct IMAGE_RESOURCE_DATA_ENTRY IMAGE_RESOURCE_DATA_ENTRY, *PIMAGE_RESOURCE_DATA_ENTRY;

struct IMAGE_RESOURCE_DATA_ENTRY {
    dword OffsetToData;
    dword Size;
    dword CodePage;
    dword Reserved;
};

typedef struct IMAGE_RESOURCE_DIRECTORY IMAGE_RESOURCE_DIRECTORY, *PIMAGE_RESOURCE_DIRECTORY;

struct IMAGE_RESOURCE_DIRECTORY {
    dword Characteristics;
    dword TimeDateStamp;
    word MajorVersion;
    word MinorVersion;
    word NumberOfNamedEntries;
    word NumberOfIdEntries;
};

typedef struct IMAGE_DIRECTORY_ENTRY_EXPORT IMAGE_DIRECTORY_ENTRY_EXPORT, *PIMAGE_DIRECTORY_ENTRY_EXPORT;

struct IMAGE_DIRECTORY_ENTRY_EXPORT {
    dword Characteristics;
    dword TimeDateStamp;
    word MajorVersion;
    word MinorVersion;
    dword Name;
    dword Base;
    dword NumberOfFunctions;
    dword NumberOfNames;
    dword AddressOfFunctions;
    dword AddressOfNames;
    dword AddressOfNameOrdinals;
};

typedef struct _iobuf _iobuf, *P_iobuf;

struct _iobuf {
    char * _ptr;
    int _cnt;
    char * _base;
    int _flag;
    int _file;
    int _charbuf;
    int _bufsiz;
    char * _tmpfname;
};

typedef struct _iobuf FILE;

typedef void (TIMECALLBACK)(UINT, UINT, DWORD_PTR, DWORD_PTR, DWORD_PTR);

typedef TIMECALLBACK * LPTIMECALLBACK;

typedef DWORD MCIERROR;

typedef UINT MMRESULT;

typedef longlong __time64_t;

typedef uint size_t;

typedef __time64_t time_t;




// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void entry(void)

{
  int *piVar1;
  undefined in_CL;
  int iVar2;
  undefined *puVar3;
  undefined2 in_FS;
  
  _DAT_0042005d = DAT_00420059 << 2;
  puVar3 = &DAT_00420c68;
  for (iVar2 = 0x23d8; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  piVar1 = (int *)segment(in_FS,4);
  iVar2 = *piVar1;
  _DAT_00420061 = *(undefined4 *)(iVar2 + -8);
  _DAT_00420065 = *(undefined4 *)(iVar2 + -4);
  DAT_0042303c = iVar2 + -4;
  __ExceptInit((char)_DAT_00420065,(char)iVar2 + -8,in_CL,0);
  _DAT_0042006a = GetModuleHandleA((LPCSTR)0x0);
  __startup();
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void __GetExceptDLLinfo(undefined param_1,undefined param_2,undefined param_3,undefined4 *param_4)

{
  int in_FS_OFFSET;
  
                    // 0x1006e  1  __GetExceptDLLinfo
  _DAT_00420b90 = *(int *)(*(int *)(in_FS_OFFSET + 4) + -8) + 0x24;
  *param_4 = 0x82727349;
  param_4[1] = &DAT_00420b74;
  return;
}



void Shutdown(void)

{
  if (DAT_00421e3c != (int *)0x0) {
    if (DAT_00421e40 != (int *)0x0) {
      (**(code **)(*DAT_00421e40 + 8))();
      DAT_00421e40 = (int *)0x0;
    }
    (**(code **)(*DAT_00421e3c + 8))();
    DAT_00421e3c = (int *)0x0;
  }
  return;
}



void Error_Message(undefined param_1,undefined param_2,undefined param_3,LPCSTR param_4)

{
  MessageBoxA((HWND)0x0,param_4,s_ERROR_004200ac,0);
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void WindowProc(undefined param_1,undefined param_2,undefined param_3,HWND param_4,UINT param_5,
               WPARAM param_6,LPARAM param_7)

{
  int iVar1;
  undefined extraout_CL;
  undefined extraout_CL_00;
  undefined extraout_CL_01;
  undefined extraout_DL;
  undefined extraout_DL_00;
  undefined extraout_DL_01;
  tagPOINT local_14 [2];
  
  iVar1 = param_5 - 2;
  if (iVar1 == 0) {
    Shutdown();
    PostQuitMessage(0);
    param_3 = extraout_CL_01;
    param_2 = extraout_DL_01;
  }
  else if (param_5 == 3) {
    local_14[0].x = 0;
    local_14[0].y = 0;
    ClientToScreen(hWnd_00421e58,local_14);
    _DAT_00421e50 = local_14[0].x;
    _DAT_00421e54 = local_14[0].y;
    iVar1 = local_14[0].y;
    param_3 = extraout_CL;
    param_2 = extraout_DL;
    if (DAT_004200a8 != 0) {
      iVar1 = Update_Screen();
      param_3 = extraout_CL_00;
      param_2 = extraout_DL_00;
    }
  }
  else if (param_5 == 0x1c) {
    _DAT_00421e48 = param_6;
    iVar1 = 0;
  }
  else {
    iVar1 = param_5 - 9999;
  }
  Game_Message((char)iVar1,param_2,param_3,param_5,param_6,param_7);
  DefWindowProcA(param_4,param_5,param_6,param_7);
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void DirectDrawInit(undefined param_1,undefined param_2,undefined param_3,HINSTANCE param_4,
                   int param_5)

{
  HWND hWnd;
  DWORD dwExStyle;
  DWORD dwStyle;
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined extraout_CL;
  undefined extraout_CL_00;
  undefined extraout_CL_01;
  undefined extraout_CL_02;
  undefined extraout_CL_03;
  undefined extraout_CL_04;
  undefined uVar4;
  undefined extraout_DL;
  undefined extraout_DL_00;
  undefined extraout_DL_01;
  undefined extraout_DL_02;
  undefined extraout_DL_03;
  undefined extraout_DL_04;
  undefined uVar5;
  int iVar6;
  int iVar7;
  BOOL bMenu;
  tagPOINT local_b8 [2];
  tagRECT local_a8;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_30;
  WNDCLASSA local_2c;
  
  local_2c.style = 3;
  local_2c.lpfnWndProc = WindowProc;
  local_2c.cbClsExtra = 0;
  local_2c.cbWndExtra = 0;
  local_2c.hInstance = param_4;
  local_2c.hIcon = LoadIconA(param_4,s_BUBBLET_ICON_004200b2);
  local_2c.hCursor = LoadCursorA(param_4,(LPCSTR)0x2);
  local_2c.hbrBackground = (HBRUSH)0x0;
  local_2c.lpszMenuName = &DAT_004200bf;
  local_2c.lpszClassName = &DAT_004200c3;
  RegisterClassA(&local_2c);
  hWnd = CreateWindowExA(0,&DAT_004200c7,s_Bubblet___Shareware__004200cb,0xca0000,0,0,0,0,(HWND)0x0,
                         (HMENU)0x0,param_4,(LPVOID)0x0);
  if (hWnd != (HWND)0x0) {
    hWnd_00421e58 = hWnd;
    SetRect(&local_a8,0,0,0x1ed,0x1a3);
    dwExStyle = GetWindowLongA(hWnd,-0x14);
    bMenu = 0;
    dwStyle = GetWindowLongA(hWnd,-0x10);
    AdjustWindowRectEx(&local_a8,dwStyle,bMenu,dwExStyle);
    uVar1 = GetSystemMetrics(0);
    iVar7 = (int)uVar1 >> 1;
    if (iVar7 < 0) {
      iVar7 = iVar7 + (uint)((uVar1 & 1) != 0);
    }
    iVar2 = local_a8.right - local_a8.left >> 1;
    if (iVar2 < 0) {
      iVar2 = iVar2 + (uint)((local_a8.right - local_a8.left & 1U) != 0);
    }
    uVar1 = GetSystemMetrics(1);
    iVar3 = (int)uVar1 >> 1;
    if (iVar3 < 0) {
      iVar3 = iVar3 + (uint)((uVar1 & 1) != 0);
    }
    iVar6 = local_a8.bottom - local_a8.top >> 1;
    if (iVar6 < 0) {
      iVar6 = iVar6 + (uint)((local_a8.bottom - local_a8.top & 1U) != 0);
    }
    MoveWindow(hWnd,iVar7 - iVar2,iVar3 - iVar6,local_a8.right - local_a8.left,
               local_a8.bottom - local_a8.top,0);
    local_b8[0].x = 0;
    local_b8[0].y = 0;
    ClientToScreen(hWnd,local_b8);
    _DAT_00421e50 = local_b8[0].x;
    _DAT_00421e54 = local_b8[0].y;
    ShowWindow(hWnd,param_5);
    UpdateWindow(hWnd);
    iVar7 = DirectDrawCreate();
    uVar4 = extraout_CL;
    uVar5 = extraout_DL;
    if ((iVar7 == 0) &&
       (iVar7 = (**(code **)(*DAT_00421e3c + 0x50))(), uVar4 = extraout_CL_00,
       uVar5 = extraout_DL_00, iVar7 == 0)) {
      local_98 = 0x6c;
      local_94 = 1;
      local_30 = 0x200;
      iVar7 = (**(code **)(*DAT_00421e3c + 0x18))();
      uVar4 = extraout_CL_01;
      uVar5 = extraout_DL_01;
      if ((iVar7 == 0) &&
         (((iVar7 = (**(code **)(*DAT_00421e3c + 0x10))(), uVar4 = extraout_CL_02,
           uVar5 = extraout_DL_02, iVar7 == 0 &&
           (iVar7 = (**(code **)(*DAT_00421e44 + 0x20))(), uVar4 = extraout_CL_03,
           uVar5 = extraout_DL_03, iVar7 == 0)) &&
          (iVar7 = (**(code **)(*DAT_00421e40 + 0x70))(), uVar4 = extraout_CL_04,
          uVar5 = extraout_DL_04, iVar7 == 0)))) {
        (**(code **)(*DAT_00421e44 + 8))();
        return;
      }
    }
    Error_Message(0xe0,uVar5,uVar4,s_Direct_Draw_Initialisierung_fehl_004200e0);
    DestroyWindow(hWnd);
  }
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

WPARAM WinMain(undefined param_1,undefined param_2,undefined param_3,undefined4 param_4,
              undefined param_5,undefined param_6,undefined4 param_7)

{
  undefined3 in_register_00000001;
  int iVar1;
  MMRESULT MVar2;
  BOOL BVar3;
  undefined extraout_CL;
  undefined extraout_DL;
  MSG local_20;
  
  iVar1 = CONCAT31(in_register_00000001,param_1);
  _DAT_00421e60 = param_4;
  DirectDrawInit(param_1,param_2,param_3,param_4,param_7);
  if (iVar1 == 0) {
    local_20.wParam = 0;
  }
  else {
    MVar2 = timeSetEvent(0x19,0,fptc_004133ba,0,1);
    uTimerID_00421e5c = MVar2;
    CreateOffScreenSurface((char)MVar2,extraout_DL,extraout_CL,DAT_00421e3c,0x1ee,0x1a4);
    DAT_00421e4c = MVar2;
    Game_Init();
    while (BVar3 = GetMessageA(&local_20,(HWND)0x0,0,0), BVar3 != 0) {
      TranslateMessage(&local_20);
      DispatchMessageA(&local_20);
    }
  }
  return local_20.wParam;
}



uint Check_In_Box(uint param_1,uint param_2,uint param_3,uint param_4,uint param_5,uint param_6,
                 uint param_7,uint param_8,uint param_9)

{
  if ((((param_4 < param_8) && (param_8 < param_6)) && (param_5 < param_9)) && (param_9 < param_7))
  {
    return 1;
  }
  return 0;
}



void Update_Button(int param_1,int param_2,int param_3,int param_4)

{
  char cVar1;
  
  if ((DAT_00420118 == 0 || 4 < param_4) &&
     (*(int *)(&DAT_00422d5c + param_4 * 0x20) == DAT_0042010c ||
      *(int *)(&DAT_00422d5c + param_4 * 0x20) == 0xff)) {
    cVar1 = (char)param_4;
    if ((&DAT_00422d58)[param_4 * 8] != 0) {
      PutSurfacePrimary(cVar1 * ' ',0x40,cVar1 * ' ',(&DAT_00422d40)[param_4 * 8],
                        (&DAT_00422d44)[param_4 * 8],*(undefined4 *)(&DAT_00422d54 + param_4 * 0x20)
                       );
      return;
    }
    PutSurfacePrimary(cVar1 * ' ',0x40,cVar1 * ' ',(&DAT_00422d40)[param_4 * 8],
                      (&DAT_00422d44)[param_4 * 8],*(undefined4 *)(&DAT_00422d50 + param_4 * 0x20));
  }
  return;
}



void Draw_Buttons(void)

{
  undefined in_AL;
  undefined in_CL;
  undefined extraout_CL;
  undefined extraout_CL_00;
  undefined extraout_CL_01;
  undefined extraout_CL_02;
  undefined extraout_CL_03;
  undefined extraout_CL_04;
  undefined extraout_CL_05;
  undefined extraout_CL_06;
  undefined extraout_DL;
  undefined extraout_DL_00;
  undefined extraout_DL_01;
  undefined extraout_DL_02;
  undefined extraout_DL_03;
  undefined extraout_DL_04;
  uint in_EDX;
  uint extraout_EDX;
  uint extraout_EDX_00;
  int iVar1;
  bool bVar2;
  undefined uVar3;
  
  iVar1 = 1;
  while( true ) {
    uVar3 = (undefined)in_EDX;
    if (DAT_0042013c < iVar1) break;
    bVar2 = *(int *)(&DAT_00422d5c + iVar1 * 0x20) == 0xff;
    in_EDX = (uint)bVar2;
    in_AL = *(int *)(&DAT_00422d5c + iVar1 * 0x20) == DAT_0042010c || bVar2;
    if ((bool)in_AL) {
      if ((&DAT_00422d58)[iVar1 * 8] == 0) {
        in_AL = PutSurface((char)iVar1 * ' ',bVar2,in_CL,(&DAT_00422d40)[iVar1 * 8],
                           (&DAT_00422d44)[iVar1 * 8],*(undefined4 *)(&DAT_00422d50 + iVar1 * 0x20),
                           DAT_00421e4c);
        in_CL = extraout_CL_00;
        in_EDX = extraout_EDX_00;
      }
      else {
        in_AL = PutSurface((char)iVar1 * ' ',bVar2,in_CL,(&DAT_00422d40)[iVar1 * 8],
                           (&DAT_00422d44)[iVar1 * 8],*(undefined4 *)(&DAT_00422d54 + iVar1 * 0x20),
                           DAT_00421e4c);
        in_CL = extraout_CL;
        in_EDX = extraout_EDX;
      }
    }
    iVar1 = iVar1 + 1;
  }
  if (DAT_00420110 != 0) {
    uVar3 = DAT_0042010c != 0;
    in_AL = DAT_00420110 == 2 && (bool)uVar3;
    if (DAT_00420110 == 2 && (bool)uVar3) {
      in_AL = PutSurface(in_AL,uVar3,in_CL,DAT_00422e00,DAT_00422e04,DAT_00422e10,DAT_00421e4c);
      in_CL = extraout_CL_01;
      uVar3 = extraout_DL;
    }
  }
  if (DAT_00420118 != 0) {
    uVar3 = PutSurfaceCC(in_AL,uVar3,in_CL,DAT_00422d60,DAT_00422d64,DAT_00421e8c,DAT_00421e4c);
    uVar3 = PutSurfaceCC(uVar3,extraout_DL_00,extraout_CL_02,DAT_00422d80,DAT_00422d84,DAT_00421e8c,
                         DAT_00421e4c);
    uVar3 = PutSurfaceCC(uVar3,extraout_DL_01,extraout_CL_03,DAT_00422da0,DAT_00422da4,DAT_00421e8c,
                         DAT_00421e4c);
    uVar3 = PutSurfaceCC(uVar3,extraout_DL_02,extraout_CL_04,DAT_00422dc0,DAT_00422dc4,DAT_00421e8c,
                         DAT_00421e4c);
    uVar3 = PutSurfaceCC(uVar3,extraout_DL_03,extraout_CL_05,DAT_00422de0,DAT_00422de4,DAT_00421e8c,
                         DAT_00421e4c);
    PutSurfaceCC(uVar3,extraout_DL_04,extraout_CL_06,DAT_00422e00,DAT_00422e04,DAT_00421e8c,
                 DAT_00421e4c);
  }
  return;
}



void Update_Screen(void)

{
  undefined in_AL;
  undefined in_CL;
  undefined in_DL;
  
  PutSurfacePrimary(in_AL,in_DL,in_CL,0,0,DAT_00421e4c);
  return;
}



void Create_Game_Screen(void)

{
  undefined in_AL;
  int iVar1;
  undefined in_CL;
  uint param2;
  HDC extraout_ECX;
  undefined in_DL;
  char *param1;
  undefined4 extraout_EDX;
  int iVar2;
  int iVar3;
  int iVar4;
  char local_64 [80];
  undefined4 *local_14;
  HDC local_10;
  int local_c;
  int local_8;
  
  PutSurface(in_AL,in_DL,in_CL,0,0,DAT_00421e88,DAT_00421e4c);
  _sprintf(local_64,param1,param2,(uint)local_64,0x420144);
  DAT_00421e68 = local_64;
  ShowText(DAT_00421e68,extraout_EDX,extraout_ECX,DAT_00421e4c,10,0x160,DAT_00421e68,0xffffff);
  Draw_Buttons();
  iVar4 = 0;
  do {
    iVar3 = 0;
    do {
      if ((&DAT_00421f04)[iVar3 * 0x2a + iVar4 * 6] != 0) {
        iVar1 = iVar3 * 0x30 + 8;
        local_8 = iVar4 * 0x30 + 8;
        if (DAT_00420120 != 0) {
          if ((&DAT_00421f08)[iVar3 * 0x2a + iVar4 * 6] != 0xffff) {
            iVar1 = (&DAT_00421f08)[iVar3 * 0x2a + iVar4 * 6];
          }
          if ((&DAT_00421f0c)[iVar3 * 0x2a + iVar4 * 6] != 0xffff) {
            local_8 = (&DAT_00421f0c)[iVar3 * 0x2a + iVar4 * 6];
          }
        }
        if ((&DAT_00421f04)[iVar3 * 0x2a + iVar4 * 6] == 1) {
          local_14 = &DAT_00421e90;
        }
        if ((&DAT_00421f04)[iVar3 * 0x2a + iVar4 * 6] == 2) {
          local_14 = &DAT_00421e94;
        }
        if ((&DAT_00421f04)[iVar3 * 0x2a + iVar4 * 6] == 3) {
          local_14 = &DAT_00421e98;
        }
        if ((&DAT_00421f04)[iVar3 * 0x2a + iVar4 * 6] == 4) {
          local_14 = &DAT_00421e9c;
        }
        if ((&DAT_00421f04 + iVar3 * 0x2a)[iVar4 * 6] == 5) {
          local_14 = &DAT_00421ea0;
        }
        PutSurfaceClipCC((char)iVar1,(char)local_14,(char)(&DAT_00421f04 + iVar3 * 0x2a),iVar1,
                         local_8,*local_14,DAT_00421e4c,DAT_00421ef4,DAT_00421ef8,DAT_00421efc,
                         DAT_00421f00);
        if ((DAT_0042011c != 0) && ((&DAT_00421f18)[iVar3 * 0x2a + iVar4 * 6] != 0)) {
          if ((&DAT_00421f00)[iVar3 * 0x2a + iVar4 * 6] == 0 && 0 < iVar4 || iVar4 == 0) {
            iVar1 = iVar3 * 0x30 + 7;
            iVar2 = iVar4 * 0x30 + 7;
            local_c = (iVar3 + 1) * 0x30 + 7;
            local_10 = (HDC)(iVar4 * 0x30 + 7);
            DrawLine(iVar1,iVar2,local_10,DAT_00421e4c,iVar1,iVar2,local_c,(int)local_10,0xff);
          }
          if ((&DAT_00421f30)[iVar3 * 0x2a + iVar4 * 6] == 0 && iVar4 < 6 || iVar4 == 6) {
            iVar1 = iVar3 * 0x30 + 7;
            iVar2 = (iVar4 + 1) * 0x30 + 6;
            local_c = (iVar3 + 1) * 0x30 + 7;
            local_10 = (HDC)((iVar4 + 1) * 0x30 + 6);
            DrawLine(iVar1,iVar2,local_10,DAT_00421e4c,iVar1,iVar2,local_c,(int)local_10,0xff);
          }
          if ((&DAT_00421e70)[iVar3 * 0x2a + iVar4 * 6] == 0 && 0 < iVar3 || iVar3 == 0) {
            iVar1 = iVar3 * 0x30 + 7;
            iVar2 = iVar4 * 0x30 + 7;
            local_c = iVar3 * 0x30 + 7;
            local_10 = (HDC)((iVar4 + 1) * 0x30 + 7);
            DrawLine(iVar1,iVar2,local_10,DAT_00421e4c,iVar1,iVar2,local_c,(int)local_10,0xff);
          }
          if ((&DAT_00421fc0)[iVar3 * 0x2a + iVar4 * 6] == 0 && iVar3 < 9 || iVar3 == 9) {
            iVar1 = (iVar3 + 1) * 0x30 + 6;
            iVar2 = iVar4 * 0x30 + 7;
            local_c = (iVar3 + 1) * 0x30 + 6;
            local_10 = (HDC)((iVar4 + 1) * 0x30 + 7);
            DrawLine(iVar1,iVar2,local_10,DAT_00421e4c,iVar1,iVar2,local_c,(int)local_10,0xff);
          }
        }
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < 10);
    iVar4 = iVar4 + 1;
  } while (iVar4 < 7);
  Update_Screen();
  return;
}



void Create_Scores(void)

{
  undefined in_AL;
  undefined uVar1;
  undefined4 uVar2;
  undefined in_CL;
  undefined extraout_CL;
  undefined extraout_CL_00;
  uint param2;
  uint param2_00;
  uint param2_01;
  uint param2_02;
  uint param2_03;
  uint param2_04;
  uint param2_05;
  uint param2_06;
  uint param2_07;
  uint param2_08;
  uint param2_09;
  uint param2_10;
  HDC extraout_ECX;
  HDC extraout_ECX_00;
  HDC extraout_ECX_01;
  HDC extraout_ECX_02;
  HDC extraout_ECX_03;
  HDC extraout_ECX_04;
  HDC extraout_ECX_05;
  HDC extraout_ECX_06;
  HDC extraout_ECX_07;
  HDC extraout_ECX_08;
  HDC extraout_ECX_09;
  HDC extraout_ECX_10;
  HDC extraout_ECX_11;
  undefined in_DL;
  undefined extraout_DL;
  undefined extraout_DL_00;
  char *extraout_EDX;
  char *pcVar3;
  char *param1;
  char *param1_00;
  char *extraout_EDX_00;
  char *param1_01;
  char *param1_02;
  char *extraout_EDX_01;
  char *param1_03;
  char *param1_04;
  char *extraout_EDX_02;
  char *param1_05;
  char *param1_06;
  undefined4 extraout_EDX_03;
  undefined4 extraout_EDX_04;
  undefined4 extraout_EDX_05;
  undefined4 extraout_EDX_06;
  undefined4 extraout_EDX_07;
  undefined4 extraout_EDX_08;
  undefined4 extraout_EDX_09;
  undefined4 extraout_EDX_10;
  undefined4 extraout_EDX_11;
  undefined4 extraout_EDX_12;
  undefined4 extraout_EDX_13;
  undefined4 extraout_EDX_14;
  undefined4 extraout_EDX_15;
  char local_3c4 [80];
  char local_374 [80];
  char local_324 [80];
  char local_2d4 [80];
  char local_284 [80];
  char local_234 [80];
  char local_1e4 [80];
  char local_194 [80];
  char local_144 [80];
  char local_f4 [80];
  char local_a4 [80];
  char local_54 [80];
  
  uVar1 = PutSurface(in_AL,in_DL,in_CL,0,0,DAT_00421e88,DAT_00421e4c);
  uVar1 = PutSurfaceCC(uVar1,extraout_DL,extraout_CL,8,6,DAT_00421e70,DAT_00421e4c);
  PutSurfaceCC(uVar1,extraout_DL_00,extraout_CL_00,0x4b,0x28,DAT_00421e78,DAT_00421e4c);
  pcVar3 = extraout_EDX;
  if (0 < (int)_Str_00421eb0) {
    pcVar3 = (char *)(DAT_00421eb4 % (int)_Str_00421eb0);
  }
  _sprintf(local_54,pcVar3,param2);
  DAT_00422fc0 = local_54;
  _sprintf(local_a4,param1,param2_00);
  DAT_00422fc4 = local_a4;
  _sprintf(local_f4,param1_00,param2_01);
  DAT_00422fc8 = local_f4;
  pcVar3 = extraout_EDX_00;
  if (0 < DAT_00421ebc) {
    pcVar3 = (char *)(DAT_00421ec0 % DAT_00421ebc);
  }
  _sprintf(local_144,pcVar3,param2_02);
  DAT_00422fcc = local_144;
  _sprintf(local_194,param1_01,param2_03);
  DAT_00422fd0 = local_194;
  _sprintf(local_1e4,param1_02,param2_04);
  DAT_00422fd4 = local_1e4;
  pcVar3 = extraout_EDX_01;
  if (0 < DAT_00421ec8) {
    pcVar3 = (char *)(DAT_00421ecc % DAT_00421ec8);
  }
  _sprintf(local_234,pcVar3,param2_05);
  DAT_00422fd8 = local_234;
  _sprintf(local_284,param1_03,param2_06);
  DAT_00422fdc = local_284;
  _sprintf(local_2d4,param1_04,param2_07);
  DAT_00422fe0 = local_2d4;
  pcVar3 = extraout_EDX_02;
  if (0 < DAT_00421ed4) {
    pcVar3 = (char *)(DAT_00421ed8 % DAT_00421ed4);
  }
  _sprintf(local_324,pcVar3,param2_08);
  DAT_00422fe4 = local_324;
  _sprintf(local_374,param1_05,param2_09);
  DAT_00422fe8 = local_374;
  _sprintf(local_3c4,param1_06,param2_10);
  DAT_00422fec = local_3c4;
  uVar2 = ShowTextCenter(DAT_00422fec,extraout_EDX_03,extraout_ECX,DAT_00421e4c,0xf0,0x87,
                         DAT_00422fc0,0);
  uVar2 = ShowTextCenter(uVar2,extraout_EDX_04,extraout_ECX_00,DAT_00421e4c,0x13b,0x87,DAT_00422fc4,
                         0);
  uVar2 = ShowTextCenter(uVar2,extraout_EDX_05,extraout_ECX_01,DAT_00421e4c,0x181,0x87,DAT_00422fc8,
                         0);
  uVar2 = ShowTextCenter(uVar2,extraout_EDX_06,extraout_ECX_02,DAT_00421e4c,0xf0,0xa7,DAT_00422fcc,0
                        );
  uVar2 = ShowTextCenter(uVar2,extraout_EDX_07,extraout_ECX_03,DAT_00421e4c,0x13b,0xa7,DAT_00422fd0,
                         0);
  uVar2 = ShowTextCenter(uVar2,extraout_EDX_08,extraout_ECX_04,DAT_00421e4c,0x181,0xa7,DAT_00422fd4,
                         0);
  uVar2 = ShowTextCenter(uVar2,extraout_EDX_09,extraout_ECX_05,DAT_00421e4c,0xf0,0xc5,DAT_00422fd8,0
                        );
  uVar2 = ShowTextCenter(uVar2,extraout_EDX_10,extraout_ECX_06,DAT_00421e4c,0x13b,0xc5,DAT_00422fdc,
                         0);
  uVar2 = ShowTextCenter(uVar2,extraout_EDX_11,extraout_ECX_07,DAT_00421e4c,0x181,0xc5,DAT_00422fe0,
                         0);
  uVar2 = ShowTextCenter(uVar2,extraout_EDX_12,extraout_ECX_08,DAT_00421e4c,0xf0,0xe5,DAT_00422fe4,0
                        );
  uVar2 = ShowTextCenter(uVar2,extraout_EDX_13,extraout_ECX_09,DAT_00421e4c,0x13b,0xe5,DAT_00422fe8,
                         0);
  uVar2 = ShowTextCenter(uVar2,extraout_EDX_14,extraout_ECX_10,DAT_00421e4c,0x181,0xe5,DAT_00422fec,
                         0);
  DAT_00421e68 = s_Click__Reset__to_clear_the_damn_t_004201a2;
  ShowText(uVar2,extraout_EDX_15,extraout_ECX_11,DAT_00421e4c,10,0x160,
           s_Click__Reset__to_clear_the_damn_t_004201a2,0xffffff);
  Draw_Buttons();
  Update_Screen();
  return;
}



void uint(void)

{
  undefined in_AL;
  undefined uVar1;
  LPCSTR pCVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  char *pcVar5;
  undefined in_CL;
  undefined extraout_CL;
  undefined extraout_CL_00;
  uint param2;
  uint param2_00;
  uint param2_01;
  HDC param2_02;
  uint param2_03;
  HDC extraout_ECX;
  uint param2_04;
  HDC extraout_ECX_00;
  uint param2_05;
  HDC extraout_ECX_01;
  uint param2_06;
  HDC extraout_ECX_02;
  HDC extraout_ECX_03;
  HDC extraout_ECX_04;
  HDC extraout_ECX_05;
  HDC extraout_ECX_06;
  HDC pHVar6;
  HDC extraout_ECX_07;
  HDC extraout_ECX_08;
  undefined in_DL;
  undefined extraout_DL;
  undefined extraout_DL_00;
  char *param1;
  char *param1_00;
  char *param1_01;
  undefined4 extraout_EDX;
  char *param1_02;
  undefined4 extraout_EDX_00;
  char *param1_03;
  undefined4 extraout_EDX_01;
  char *param1_04;
  undefined4 extraout_EDX_02;
  char *param1_05;
  undefined4 extraout_EDX_03;
  undefined4 extraout_EDX_04;
  undefined4 extraout_EDX_05;
  undefined4 extraout_EDX_06;
  undefined4 extraout_EDX_07;
  undefined4 extraout_EDX_08;
  undefined4 extraout_EDX_09;
  char local_194 [80];
  char local_144 [80];
  char local_f4 [80];
  char local_a4 [80];
  char local_54 [80];
  
  uVar1 = PutSurface(in_AL,in_DL,in_CL,0,0,DAT_00421e88,DAT_00421e4c);
  uVar1 = PutSurfaceCC(uVar1,extraout_DL,extraout_CL,8,6,DAT_00421e70,DAT_00421e4c);
  PutSurfaceCC(uVar1,extraout_DL_00,extraout_CL_00,0x87,0x28,DAT_00421e7c,DAT_00421e4c);
  _sprintf(local_54,param1,param2);
  DAT_00422fc0 = local_54;
  _sprintf(local_a4,param1_00,param2_00);
  DAT_00422fc4 = local_a4;
  _sprintf(local_f4,param1_01,param2_01);
  pCVar2 = local_f4;
  pHVar6 = param2_02;
  uVar3 = extraout_EDX;
  DAT_00422fc8 = pCVar2;
  if (DAT_00420134 == 0) {
    _sprintf(local_144,(char *)(DAT_00421eb4 % (int)_Str_00421eb0),(uint)param2_02);
    DAT_00422fcc = local_144;
    _sprintf(local_194,param1_02,param2_03);
    pCVar2 = local_194;
    pHVar6 = extraout_ECX;
    uVar3 = extraout_EDX_00;
    DAT_00422fd0 = pCVar2;
  }
  if (DAT_00420134 == 1) {
    _sprintf(local_144,(char *)(DAT_00421ec0 % DAT_00421ebc),(uint)pHVar6);
    DAT_00422fcc = local_144;
    _sprintf(local_194,param1_03,param2_04);
    pCVar2 = local_194;
    pHVar6 = extraout_ECX_00;
    uVar3 = extraout_EDX_01;
    DAT_00422fd0 = pCVar2;
  }
  if (DAT_00420134 == 2) {
    _sprintf(local_144,(char *)(DAT_00421ecc % DAT_00421ec8),(uint)pHVar6);
    DAT_00422fcc = local_144;
    _sprintf(local_194,param1_04,param2_05);
    pCVar2 = local_194;
    pHVar6 = extraout_ECX_01;
    uVar3 = extraout_EDX_02;
    DAT_00422fd0 = pCVar2;
  }
  if (DAT_00420134 == 3) {
    _sprintf(local_144,(char *)(DAT_00421ed8 % DAT_00421ed4),(uint)pHVar6);
    DAT_00422fcc = local_144;
    _sprintf(local_194,param1_05,param2_06);
    pCVar2 = local_194;
    pHVar6 = extraout_ECX_02;
    uVar3 = extraout_EDX_03;
    DAT_00422fd0 = pCVar2;
  }
  uVar3 = ShowTextCenter(pCVar2,uVar3,pHVar6,DAT_00421e4c,0x14f,0x73,DAT_00422fc0,0);
  uVar3 = ShowTextCenter(uVar3,extraout_EDX_04,extraout_ECX_03,DAT_00421e4c,0x14f,0x92,DAT_00422fc4,
                         0);
  if (DAT_00420128 == 0) {
    uVar4 = ShowTextCenter(uVar3,extraout_EDX_05,extraout_ECX_04,DAT_00421e4c,0x14f,0xb0,
                           DAT_00422fc8,0);
    pHVar6 = extraout_ECX_06;
    uVar3 = extraout_EDX_07;
  }
  else {
    uVar4 = ShowTextCenter(uVar3,extraout_EDX_05,extraout_ECX_04,DAT_00421e4c,0x14f,0xb0,
                           DAT_00422fc8,0xff);
    pHVar6 = extraout_ECX_05;
    uVar3 = extraout_EDX_06;
  }
  uVar3 = ShowTextCenter(uVar4,uVar3,pHVar6,DAT_00421e4c,0x14f,0xd0,DAT_00422fcc,0);
  ShowTextCenter(uVar3,extraout_EDX_08,extraout_ECX_07,DAT_00421e4c,0x14f,0xee,DAT_00422fd0,0);
  if (DAT_00420128 == 0) {
    pcVar5 = s_Game_Over__00420207;
    DAT_00421e68 = s_Game_Over__00420207;
  }
  else {
    pcVar5 = s_You_have_a_new_highscore___004201ec;
    DAT_00421e68 = s_You_have_a_new_highscore___004201ec;
  }
  ShowText(pcVar5,extraout_EDX_09,extraout_ECX_08,DAT_00421e4c,10,0x160,DAT_00421e68,0xffffff);
  Draw_Buttons();
  Update_Screen();
  return;
}



void CreateSetup(void)

{
  undefined in_AL;
  undefined uVar1;
  undefined4 uVar2;
  undefined in_CL;
  undefined extraout_CL;
  undefined extraout_CL_00;
  HDC extraout_ECX;
  HDC extraout_ECX_00;
  HDC extraout_ECX_01;
  HDC extraout_ECX_02;
  HDC extraout_ECX_03;
  HDC extraout_ECX_04;
  HDC extraout_ECX_05;
  HDC pHVar3;
  undefined in_DL;
  undefined extraout_DL;
  undefined extraout_DL_00;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 extraout_EDX_01;
  undefined4 extraout_EDX_02;
  undefined4 extraout_EDX_03;
  undefined4 extraout_EDX_04;
  undefined4 extraout_EDX_05;
  undefined4 uVar4;
  
  uVar1 = PutSurface(in_AL,in_DL,in_CL,0,0,DAT_00421e88,DAT_00421e4c);
  uVar1 = PutSurfaceCC(uVar1,extraout_DL,extraout_CL,8,6,DAT_00421e70,DAT_00421e4c);
  uVar2 = PutSurfaceCC(uVar1,extraout_DL_00,extraout_CL_00,0x49,0x41,DAT_00421e80,DAT_00421e4c);
  pHVar3 = extraout_ECX;
  uVar4 = extraout_EDX;
  if (_Str_00421ee8 == (void *)0x0) {
    uVar2 = PutSurfaceCC((char)uVar2,(char)extraout_EDX,(char)extraout_ECX,99,0x61,DAT_00421e84,
                         DAT_00421e4c);
    pHVar3 = extraout_ECX_00;
    uVar4 = extraout_EDX_00;
  }
  if (_Str_00421ee8 == (void *)0x1) {
    uVar2 = PutSurfaceCC((char)uVar2,(char)uVar4,(char)pHVar3,99,0x7e,DAT_00421e84,DAT_00421e4c);
    pHVar3 = extraout_ECX_01;
    uVar4 = extraout_EDX_01;
  }
  if (_Str_00421ee8 == (void *)0x2) {
    uVar2 = PutSurfaceCC((char)uVar2,(char)uVar4,(char)pHVar3,99,0x9f,DAT_00421e84,DAT_00421e4c);
    pHVar3 = extraout_ECX_02;
    uVar4 = extraout_EDX_02;
  }
  if (_Str_00421ee8 == (void *)0x3) {
    uVar2 = PutSurfaceCC((char)uVar2,(char)uVar4,(char)pHVar3,99,0xbe,DAT_00421e84,DAT_00421e4c);
    pHVar3 = extraout_ECX_03;
    uVar4 = extraout_EDX_03;
  }
  if (DAT_00421eec == 1) {
    uVar2 = PutSurfaceCC((char)uVar2,(char)uVar4,(char)pHVar3,0x117,0x4d,DAT_00421e84,DAT_00421e4c);
    pHVar3 = extraout_ECX_04;
    uVar4 = extraout_EDX_04;
  }
  if (DAT_00421ef0 == 1) {
    uVar2 = PutSurfaceCC((char)uVar2,(char)uVar4,(char)pHVar3,0x118,0x77,DAT_00421e84,DAT_00421e4c);
    pHVar3 = extraout_ECX_05;
    uVar4 = extraout_EDX_05;
  }
  DAT_00421e68 = s_Let_s_change_something____00420212;
  ShowText(uVar2,uVar4,pHVar3,DAT_00421e4c,10,0x160,s_Let_s_change_something____00420212,0xffffff);
  Draw_Buttons();
  Update_Screen();
  return;
}



void Create_Screen(void)

{
  undefined uVar1;
  undefined4 uVar2;
  undefined in_CL;
  undefined extraout_CL;
  undefined extraout_CL_00;
  undefined extraout_CL_01;
  undefined extraout_CL_02;
  undefined extraout_CL_03;
  HDC extraout_ECX;
  HDC extraout_ECX_00;
  HDC extraout_ECX_01;
  HDC extraout_ECX_02;
  HDC extraout_ECX_03;
  HDC extraout_ECX_04;
  HDC extraout_ECX_05;
  HDC extraout_ECX_06;
  HDC extraout_ECX_07;
  HDC extraout_ECX_08;
  HDC extraout_ECX_09;
  HDC extraout_ECX_10;
  HDC extraout_ECX_11;
  HDC extraout_ECX_12;
  HDC extraout_ECX_13;
  HDC extraout_ECX_14;
  HDC extraout_ECX_15;
  HDC extraout_ECX_16;
  HDC extraout_ECX_17;
  HDC extraout_ECX_18;
  HDC extraout_ECX_19;
  HDC extraout_ECX_20;
  HDC extraout_ECX_21;
  HDC extraout_ECX_22;
  HDC extraout_ECX_23;
  HDC extraout_ECX_24;
  HDC extraout_ECX_25;
  HDC extraout_ECX_26;
  HDC extraout_ECX_27;
  HDC extraout_ECX_28;
  HDC extraout_ECX_29;
  HDC extraout_ECX_30;
  HDC extraout_ECX_31;
  HDC extraout_ECX_32;
  HDC extraout_ECX_33;
  HDC extraout_ECX_34;
  HDC extraout_ECX_35;
  HDC extraout_ECX_36;
  HDC extraout_ECX_37;
  HDC extraout_ECX_38;
  HDC extraout_ECX_39;
  HDC extraout_ECX_40;
  HDC extraout_ECX_41;
  HDC extraout_ECX_42;
  HDC extraout_ECX_43;
  HDC extraout_ECX_44;
  HDC extraout_ECX_45;
  HDC extraout_ECX_46;
  HDC extraout_ECX_47;
  HDC extraout_ECX_48;
  HDC extraout_ECX_49;
  HDC extraout_ECX_50;
  HDC extraout_ECX_51;
  HDC extraout_ECX_52;
  HDC extraout_ECX_53;
  HDC extraout_ECX_54;
  HDC extraout_ECX_55;
  undefined in_DL;
  undefined extraout_DL;
  undefined extraout_DL_00;
  undefined extraout_DL_01;
  undefined extraout_DL_02;
  undefined extraout_DL_03;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 extraout_EDX_01;
  undefined4 extraout_EDX_02;
  undefined4 extraout_EDX_03;
  undefined4 extraout_EDX_04;
  undefined4 extraout_EDX_05;
  undefined4 extraout_EDX_06;
  undefined4 extraout_EDX_07;
  undefined4 extraout_EDX_08;
  undefined4 extraout_EDX_09;
  undefined4 extraout_EDX_10;
  undefined4 extraout_EDX_11;
  undefined4 extraout_EDX_12;
  undefined4 extraout_EDX_13;
  undefined4 extraout_EDX_14;
  undefined4 extraout_EDX_15;
  undefined4 extraout_EDX_16;
  undefined4 extraout_EDX_17;
  undefined4 extraout_EDX_18;
  undefined4 extraout_EDX_19;
  undefined4 extraout_EDX_20;
  undefined4 extraout_EDX_21;
  undefined4 extraout_EDX_22;
  undefined4 extraout_EDX_23;
  undefined4 extraout_EDX_24;
  undefined4 extraout_EDX_25;
  undefined4 extraout_EDX_26;
  undefined4 extraout_EDX_27;
  undefined4 extraout_EDX_28;
  undefined4 extraout_EDX_29;
  undefined4 extraout_EDX_30;
  undefined4 extraout_EDX_31;
  undefined4 extraout_EDX_32;
  undefined4 extraout_EDX_33;
  undefined4 extraout_EDX_34;
  undefined4 extraout_EDX_35;
  undefined4 extraout_EDX_36;
  undefined4 extraout_EDX_37;
  undefined4 extraout_EDX_38;
  undefined4 extraout_EDX_39;
  undefined4 extraout_EDX_40;
  undefined4 extraout_EDX_41;
  undefined4 extraout_EDX_42;
  undefined4 extraout_EDX_43;
  undefined4 extraout_EDX_44;
  undefined4 extraout_EDX_45;
  undefined4 extraout_EDX_46;
  undefined4 extraout_EDX_47;
  undefined4 extraout_EDX_48;
  undefined4 extraout_EDX_49;
  undefined4 extraout_EDX_50;
  undefined4 extraout_EDX_51;
  undefined4 extraout_EDX_52;
  undefined4 extraout_EDX_53;
  undefined4 extraout_EDX_54;
  undefined4 extraout_EDX_55;
  
  uVar1 = (undefined)DAT_0042010c;
  switch(DAT_0042010c) {
  case 0:
    uVar1 = PutSurface(uVar1,in_DL,in_CL,0,0,DAT_00421e88,DAT_00421e4c);
    uVar2 = PutSurfaceCC(uVar1,extraout_DL,extraout_CL,0x14,0x32,DAT_00421e6c,DAT_00421e4c);
    DAT_00422fc0 = s_SHAREWARE_VERSION_0042022c;
    DAT_00422fc4 = s_This_is_the_Shareware_Version_of_0042023e;
    DAT_00422fc8 = s_Feel_free_to_distribute_it_how_e_00420268;
    DAT_00422fcc = s_For_the_actual_version_of_Bubble_00420296;
    DAT_00422fd0 = s_www_hobsoft_de_004202cc;
    DAT_00422fd4 = s_Please_support_the_concept_of_Sh_004202db;
    DAT_00422fd8 = &DAT_00420319;
    uVar2 = ShowTextCenter(uVar2,extraout_EDX,extraout_ECX,DAT_00421e4c,400,0x9e,
                           s_SHAREWARE_VERSION_0042022c,0xffffff);
    uVar2 = ShowTextCenter(uVar2,extraout_EDX_00,extraout_ECX_00,DAT_00421e4c,0xfa,200,DAT_00422fc4,
                           0xffffff);
    uVar2 = ShowTextCenter(uVar2,extraout_EDX_01,extraout_ECX_01,DAT_00421e4c,0xfa,0xd7,DAT_00422fc8
                           ,0xffffff);
    uVar2 = ShowTextCenter(uVar2,extraout_EDX_02,extraout_ECX_02,DAT_00421e4c,0xfa,0xf5,DAT_00422fcc
                           ,0xffffff);
    uVar2 = ShowTextCenter(uVar2,extraout_EDX_03,extraout_ECX_03,DAT_00421e4c,0xfa,0x104,
                           DAT_00422fd0,0xffffff);
    uVar2 = ShowTextCenter(uVar2,extraout_EDX_04,extraout_ECX_04,DAT_00421e4c,0xfa,0x127,
                           DAT_00422fd4,0xffffff);
    uVar2 = ShowTextCenter(uVar2,extraout_EDX_05,extraout_ECX_05,DAT_00421e4c,0xfa,0x136,
                           DAT_00422fd8,0xffffff);
    DAT_00421e68 = s_Click__New__to_start_a_new_game__0042031a;
    ShowText(uVar2,extraout_EDX_06,extraout_ECX_06,DAT_00421e4c,10,0x160,
             s_Click__New__to_start_a_new_game__0042031a,0xffffff);
    Draw_Buttons();
    Update_Screen();
    return;
  case 2:
    Create_Game_Screen();
    return;
  case 3:
    DAT_00422fc0 = s_Bubblet_v1_0_0042033b;
    DAT_00422fc4 = s__________________________________00420348;
    DAT_00422fc8 = s_Programming__Daniel_Klein_004203ad;
    DAT_00422fcc = s_Copyright__c__1999_by_House_of_B_004203c7;
    DAT_00422fd0 = s_All_rights_reserved__004203f5;
    DAT_00422fd4 = s__________________________________0042040a;
    DAT_00422fd8 = s_Testers__Martin_Boese__Markus_Ja_0042046f;
    DAT_00422fdc = s_Original_game_created_by_Frank_F_004204a9;
    DAT_0042300c = s_Greetings_to__004204e2;
    DAT_00423010 = s_Heidi_Amling__Daniel_Gerber__Pet_004204f0;
    DAT_00423014 = &DAT_0042051d;
    DAT_00423018 = &DAT_0042054b;
    DAT_0042301c = s_Eva_and_Peter_Weber____hey_ho_Ho_00420581;
    uVar1 = PutSurface(uVar1,in_DL,in_CL,0,0,DAT_00421e88,DAT_00421e4c);
    uVar2 = PutSurfaceCC(uVar1,extraout_DL_00,extraout_CL_00,8,6,DAT_00421e74,DAT_00421e4c);
    uVar2 = ShowText(uVar2,extraout_EDX_07,extraout_ECX_07,DAT_00421e4c,0x32,0x28,DAT_00422fc0,0);
    uVar2 = ShowText(uVar2,extraout_EDX_08,extraout_ECX_08,DAT_00421e4c,0x32,0x37,DAT_00422fc4,0);
    uVar2 = ShowText(uVar2,extraout_EDX_09,extraout_ECX_09,DAT_00421e4c,0x32,0x46,DAT_00422fc8,0);
    uVar2 = ShowText(uVar2,extraout_EDX_10,extraout_ECX_10,DAT_00421e4c,0x32,0x55,DAT_00422fcc,0);
    uVar2 = ShowText(uVar2,extraout_EDX_11,extraout_ECX_11,DAT_00421e4c,0x32,100,DAT_00422fd0,0);
    uVar2 = ShowText(uVar2,extraout_EDX_12,extraout_ECX_12,DAT_00421e4c,0x32,0x73,DAT_00422fd4,0);
    uVar2 = ShowText(uVar2,extraout_EDX_13,extraout_ECX_13,DAT_00421e4c,0x32,0x82,DAT_00422fd8,0);
    uVar2 = ShowText(uVar2,extraout_EDX_14,extraout_ECX_14,DAT_00421e4c,0x32,0x91,DAT_00422fdc,0);
    uVar2 = ShowText(uVar2,extraout_EDX_15,extraout_ECX_15,DAT_00421e4c,0x32,0xbe,DAT_0042300c,0);
    uVar2 = ShowText(uVar2,extraout_EDX_16,extraout_ECX_16,DAT_00421e4c,0x32,0xcd,DAT_00423010,0);
    uVar2 = ShowText(uVar2,extraout_EDX_17,extraout_ECX_17,DAT_00421e4c,0x32,0xdc,DAT_00423014,0);
    uVar2 = ShowText(uVar2,extraout_EDX_18,extraout_ECX_18,DAT_00421e4c,0x32,0xeb,DAT_00423018,0);
    uVar2 = ShowText(uVar2,extraout_EDX_19,extraout_ECX_19,DAT_00421e4c,0x32,0xfa,DAT_0042301c,0);
    DAT_00421e68 = s_The_creators_of_Bubblet____004205ac;
    ShowText(uVar2,extraout_EDX_20,extraout_ECX_20,DAT_00421e4c,10,0x160,
             s_The_creators_of_Bubblet____004205ac,0xffffff);
    Draw_Buttons();
    Update_Screen();
    return;
  case 4:
    CreateSetup();
    return;
  case 5:
    Create_Scores();
    return;
  case 6:
    uVar1 = PutSurface(uVar1,in_DL,in_CL,0,0,DAT_00421e88,DAT_00421e4c);
    DAT_00422fc0 = &DAT_004205c7;
    DAT_00422fc4 = &DAT_004205c8;
    DAT_00422fc8 = &DAT_004205c9;
    DAT_00422fcc = &DAT_004205ca;
    DAT_00422fd0 = &DAT_004205cb;
    DAT_00422fd4 = s_Undo_is_the_only_thing_that_s_no_004205cc;
    DAT_00422fd8 = s_in_the_Shareware_Version_of_Bubb_004205f6;
    DAT_00422fdc = &DAT_0042061f;
    DAT_00422fe0 = s_Please_Register__00420620;
    DAT_00422fe4 = &DAT_00420631;
    DAT_00422fe8 = &DAT_00420632;
    DAT_00422fec = &DAT_00420633;
    DAT_0042300c = &DAT_00420634;
    DAT_00423010 = &DAT_00420635;
    DAT_00423014 = &DAT_00420636;
    DAT_00423018 = &DAT_00420637;
    uVar1 = PutSurface(uVar1,extraout_DL_01,extraout_CL_01,0,0,DAT_00421e88,DAT_00421e4c);
    uVar2 = PutSurfaceCC(uVar1,extraout_DL_02,extraout_CL_02,8,6,DAT_00421e74,DAT_00421e4c);
    uVar2 = ShowTextCenter(uVar2,extraout_EDX_21,extraout_ECX_21,DAT_00421e4c,0xfa,0x28,DAT_00422fc0
                           ,0);
    uVar2 = ShowTextCenter(uVar2,extraout_EDX_22,extraout_ECX_22,DAT_00421e4c,0xfa,0x37,DAT_00422fc4
                           ,0);
    uVar2 = ShowTextCenter(uVar2,extraout_EDX_23,extraout_ECX_23,DAT_00421e4c,0xfa,0x3c,DAT_00422fc8
                           ,0);
    uVar2 = ShowTextCenter(uVar2,extraout_EDX_24,extraout_ECX_24,DAT_00421e4c,0xfa,0x4b,DAT_00422fcc
                           ,0);
    uVar2 = ShowTextCenter(uVar2,extraout_EDX_25,extraout_ECX_25,DAT_00421e4c,0xfa,0x5a,DAT_00422fd0
                           ,0);
    uVar2 = ShowTextCenter(uVar2,extraout_EDX_26,extraout_ECX_26,DAT_00421e4c,0xfa,0x69,DAT_00422fd4
                           ,0);
    uVar2 = ShowTextCenter(uVar2,extraout_EDX_27,extraout_ECX_27,DAT_00421e4c,0xfa,0x78,DAT_00422fd8
                           ,0);
    uVar2 = ShowTextCenter(uVar2,extraout_EDX_28,extraout_ECX_28,DAT_00421e4c,0xfa,0x87,DAT_00422fdc
                           ,0);
    uVar2 = ShowTextCenter(uVar2,extraout_EDX_29,extraout_ECX_29,DAT_00421e4c,0xfa,0x96,DAT_00422fe0
                           ,0);
    uVar2 = ShowTextCenter(uVar2,extraout_EDX_30,extraout_ECX_30,DAT_00421e4c,0xfa,0xa5,DAT_00422fe4
                           ,0);
    uVar2 = ShowTextCenter(uVar2,extraout_EDX_31,extraout_ECX_31,DAT_00421e4c,0xfa,0xb4,DAT_00422fe8
                           ,0);
    uVar2 = ShowTextCenter(uVar2,extraout_EDX_32,extraout_ECX_32,DAT_00421e4c,0xfa,0xc3,DAT_00422fec
                           ,0);
    uVar2 = ShowTextCenter(uVar2,extraout_EDX_33,extraout_ECX_33,DAT_00421e4c,0xfa,0xd7,DAT_0042300c
                           ,0);
    uVar2 = ShowTextCenter(uVar2,extraout_EDX_34,extraout_ECX_34,DAT_00421e4c,0xfa,0xe6,DAT_00423010
                           ,0);
    uVar2 = ShowTextCenter(uVar2,extraout_EDX_35,extraout_ECX_35,DAT_00421e4c,0xfa,0xf5,DAT_00423014
                           ,0);
    uVar2 = ShowTextCenter(uVar2,extraout_EDX_36,extraout_ECX_36,DAT_00421e4c,0xfa,0x104,
                           DAT_00423018,0);
    DAT_00421e68 = s_hehe____00420638;
    ShowText(uVar2,extraout_EDX_37,extraout_ECX_37,DAT_00421e4c,10,0x160,s_hehe____00420638,0xffffff
            );
    Draw_Buttons();
    Update_Screen();
    return;
  case 7:
    DAT_00422fc0 = s_Bubblet_is_Shareware_and_costs_o_00420640;
    DAT_00422fc4 = &DAT_00420670;
    DAT_00422fc8 = s_In_order_to_register_Bubblet_sen_00420671;
    DAT_00422fcc = s__________________________________004206ae;
    DAT_00422fd0 = s_House_of_Bytes_Software_004206d8;
    DAT_00422fd4 = s_c_o_Daniel_Klein_004206f0;
    DAT_00422fd8 = s_Walzenrather_Str__5_00420701;
    DAT_00422fdc = s_53819_Neunkirchen_00420715;
    DAT_00422fe0 = s_Germany_00420727;
    DAT_00422fe4 = s__________________________________0042072f;
    DAT_00422fe8 = s_Please_include_your_E_Mail_Addre_00420759;
    DAT_00422fec = s_The_registered_Version_will_be_s_0042077d;
    DAT_0042300c = s_Once_registered__you_re_register_004207b4;
    DAT_00423010 = s_All_registered_Users_receive_fut_004207e0;
    DAT_00423014 = &DAT_00420821;
    DAT_00423018 = s_Thank_you_for_supporting_the_con_00420822;
    uVar1 = PutSurface(uVar1,in_DL,in_CL,0,0,DAT_00421e88,DAT_00421e4c);
    uVar2 = PutSurfaceCC(uVar1,extraout_DL_03,extraout_CL_03,8,6,DAT_00421e74,DAT_00421e4c);
    uVar2 = ShowTextCenter(uVar2,extraout_EDX_38,extraout_ECX_38,DAT_00421e4c,0xfa,0x28,DAT_00422fc0
                           ,0);
    uVar2 = ShowTextCenter(uVar2,extraout_EDX_39,extraout_ECX_39,DAT_00421e4c,0xfa,0x37,DAT_00422fc4
                           ,0);
    uVar2 = ShowTextCenter(uVar2,extraout_EDX_40,extraout_ECX_40,DAT_00421e4c,0xfa,0x3c,DAT_00422fc8
                           ,0);
    uVar2 = ShowTextCenter(uVar2,extraout_EDX_41,extraout_ECX_41,DAT_00421e4c,0xfa,0x4b,DAT_00422fcc
                           ,0);
    uVar2 = ShowTextCenter(uVar2,extraout_EDX_42,extraout_ECX_42,DAT_00421e4c,0xfa,0x5a,DAT_00422fd0
                           ,0);
    uVar2 = ShowTextCenter(uVar2,extraout_EDX_43,extraout_ECX_43,DAT_00421e4c,0xfa,0x69,DAT_00422fd4
                           ,0);
    uVar2 = ShowTextCenter(uVar2,extraout_EDX_44,extraout_ECX_44,DAT_00421e4c,0xfa,0x78,DAT_00422fd8
                           ,0);
    uVar2 = ShowTextCenter(uVar2,extraout_EDX_45,extraout_ECX_45,DAT_00421e4c,0xfa,0x87,DAT_00422fdc
                           ,0);
    uVar2 = ShowTextCenter(uVar2,extraout_EDX_46,extraout_ECX_46,DAT_00421e4c,0xfa,0x96,DAT_00422fe0
                           ,0);
    uVar2 = ShowTextCenter(uVar2,extraout_EDX_47,extraout_ECX_47,DAT_00421e4c,0xfa,0xa5,DAT_00422fe4
                           ,0);
    uVar2 = ShowTextCenter(uVar2,extraout_EDX_48,extraout_ECX_48,DAT_00421e4c,0xfa,0xb4,DAT_00422fe8
                           ,0);
    uVar2 = ShowTextCenter(uVar2,extraout_EDX_49,extraout_ECX_49,DAT_00421e4c,0xfa,0xc3,DAT_00422fec
                           ,0);
    uVar2 = ShowTextCenter(uVar2,extraout_EDX_50,extraout_ECX_50,DAT_00421e4c,0xfa,0xd7,DAT_0042300c
                           ,0);
    uVar2 = ShowTextCenter(uVar2,extraout_EDX_51,extraout_ECX_51,DAT_00421e4c,0xfa,0xe6,DAT_00423010
                           ,0);
    uVar2 = ShowTextCenter(uVar2,extraout_EDX_52,extraout_ECX_52,DAT_00421e4c,0xfa,0xf5,DAT_00423014
                           ,0);
    uVar2 = ShowTextCenter(uVar2,extraout_EDX_53,extraout_ECX_53,DAT_00421e4c,0xfa,0x104,
                           DAT_00423018,0);
    DAT_00421e68 = s_How_to_register_Bubblet____00420855;
    ShowText(uVar2,extraout_EDX_54,extraout_ECX_54,DAT_00421e4c,10,0x160,
             s_How_to_register_Bubblet____00420855,0xffffff);
    Draw_Buttons();
    Update_Screen();
    return;
  case 8:
    uVar2 = PutSurface(uVar1,in_DL,in_CL,0,0,DAT_00421e88,DAT_00421e4c);
    DAT_00421e68 = s_Mode__HELP_00420870;
    ShowText(uVar2,extraout_EDX_55,extraout_ECX_55,DAT_00421e4c,10,0x160,s_Mode__HELP_00420870,
             0xffffff);
    Draw_Buttons();
    Update_Screen();
    return;
  case 9:
    uint();
  }
  return;
}



void New_Game(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  DAT_00420134 = _Str_00421ee8;
  DAT_00421ee0 = 0;
  DAT_00421ee4 = 0;
  iVar3 = 0;
  do {
    iVar2 = 0;
    do {
      iVar1 = __lrand();
      (&DAT_00421f04)[iVar2 * 0x2a + iVar3 * 6] = iVar1 % 5 + 1;
      (&DAT_00421f08)[iVar2 * 0x2a + iVar3 * 6] = 0xffff;
      (&DAT_00421f0c)[iVar2 * 0x2a + iVar3 * 6] = 0xffff;
      (&DAT_00421f18)[iVar2 * 0x2a + iVar3 * 6] = 0;
      iVar2 = iVar2 + 1;
    } while (iVar2 < 10);
    iVar3 = iVar3 + 1;
  } while (iVar3 < 7);
  return;
}



void change_mode(int param_1,int param_2,int param_3,int param_4,int param_5)

{
  undefined4 uVar1;
  undefined uVar2;
  
  uVar1 = DAT_00420110;
  DAT_00420110 = DAT_0042010c;
  if (param_4 < 6) {
    switch(param_4) {
    case 0:
      DAT_0042010c = 0;
      DAT_00420118 = 0;
      Create_Screen();
      return;
    case 1:
      goto switchD_00411ccf_caseD_1;
    case 2:
      DAT_0042010c = 2;
      DAT_00420118 = 0;
      New_Game();
      Create_Screen();
      return;
    case 3:
      DAT_0042010c = 3;
      DAT_00420118 = 1;
      Create_Screen();
      return;
    case 4:
      DAT_0042010c = 4;
      DAT_00420118 = 1;
      Create_Screen();
      return;
    default:
      DAT_0042010c = 5;
      DAT_00420118 = 1;
      Create_Screen();
      return;
    }
  }
  if (param_4 < 9) {
    if (param_4 != 8) {
      if (param_4 == 6) {
        DAT_0042010c = 6;
        DAT_00420118 = 1;
        Create_Screen();
        return;
      }
      if (param_4 == 7) {
        DAT_0042010c = 7;
        DAT_00420118 = 1;
        Create_Screen();
        return;
      }
      return;
    }
  }
  else {
    if (param_4 == 9) {
      DAT_0042010c = 9;
      DAT_00420118 = 1;
      uVar2 = (undefined)uVar1;
      if (DAT_00420128 == 0) {
        if (DAT_00421eec != 0) {
          mci_PlayWaveWait(uVar2,0,(char)param_3,s_score_00420885);
        }
      }
      else if (DAT_00421eec != 0) {
        mci_PlayWaveWait(uVar2,0,(char)param_3,s_highscore_0042087b);
      }
      Create_Screen();
      return;
    }
    if (param_4 != 0x100) {
      return;
    }
    DAT_0042010c = uVar1;
    DAT_00420118 = 0;
    Create_Screen();
    DAT_00420110 = 0;
  }
switchD_00411ccf_caseD_1:
  return;
}



void Check_Bubble(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6)

{
  int iVar1;
  undefined4 *extraout_ECX;
  undefined4 *extraout_ECX_00;
  undefined4 *extraout_ECX_01;
  undefined4 *puVar2;
  undefined4 *extraout_EDX;
  undefined4 *extraout_EDX_00;
  undefined4 *extraout_EDX_01;
  undefined4 *puVar3;
  
  if ((param_6 != 0) &&
     (puVar2 = &DAT_00421f18 + param_4 * 0x2a,
     (&DAT_00421f04)[param_4 * 0x2a + param_5 * 6] == param_6 && puVar2[param_5 * 6] == 0)) {
    iVar1 = param_5 * 3;
    puVar3 = &DAT_00421f18 + param_4 * 0x2a;
    puVar3[param_5 * 6] = 1;
    if (0 < param_5) {
      iVar1 = param_5 + -1;
      Check_Bubble(iVar1,(int)puVar3,(int)puVar2,param_4,iVar1,param_6);
      puVar2 = extraout_ECX;
      puVar3 = extraout_EDX;
    }
    if (param_5 < 6) {
      iVar1 = param_5 + 1;
      Check_Bubble(iVar1,(int)puVar3,(int)puVar2,param_4,iVar1,param_6);
      puVar2 = extraout_ECX_00;
      puVar3 = extraout_EDX_00;
    }
    if (0 < param_4) {
      iVar1 = param_4 + -1;
      Check_Bubble(iVar1,(int)puVar3,(int)puVar2,iVar1,param_5,param_6);
      puVar2 = extraout_ECX_01;
      puVar3 = extraout_EDX_01;
    }
    if (param_4 < 9) {
      Check_Bubble(iVar1,(int)puVar3,(int)puVar2,param_4 + 1,param_5,param_6);
    }
  }
  return;
}



void Check_Game_Over(void)

{
  int iVar1;
  int in_ECX;
  int extraout_ECX;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  do {
    iVar2 = 0;
    do {
      iVar1 = iVar3 * 3;
      Check_Bubble(iVar1,(int)(&DAT_00421f04 + iVar2 * 0x2a),in_ECX,iVar2,iVar3,
                   (&DAT_00421f04 + iVar2 * 0x2a)[iVar3 * 6]);
      if (1 < iVar1) {
        return;
      }
      iVar2 = iVar2 + 1;
      in_ECX = extraout_ECX;
    } while (iVar2 < 10);
    iVar3 = iVar3 + 1;
  } while (iVar3 < 7);
  return;
}



void Check_Free_Row(int param_1,int param_2,int param_3,int param_4)

{
  if (((((((&DAT_00421f04)[param_4 * 0x2a] == 0 && (&DAT_00421f1c)[param_4 * 0x2a] == 0) &&
         (&DAT_00421f34)[param_4 * 0x2a] == 0) && (&DAT_00421f4c)[param_4 * 0x2a] == 0) &&
       (&DAT_00421f64)[param_4 * 0x2a] == 0) && (&DAT_00421f7c)[param_4 * 0x2a] == 0) &&
      (&DAT_00421f94)[param_4 * 0x2a] == 0) {
    return;
  }
  return;
}



void Fill_Rows(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = param_4;
  if (-1 < param_4) {
    do {
      iVar2 = 0;
      do {
        iVar1 = __lrand(param_1,param_2,param_3);
        (&DAT_00421f04)[iVar3 * 0x2a + iVar2 * 6] = iVar1 % 5 + 1;
        (&DAT_00421f08)[iVar3 * 0x2a + iVar2 * 6] = ((param_4 - iVar3) + 1) * -0x30 + 8;
        (&DAT_00421f0c)[iVar3 * 0x2a + iVar2 * 6] = 0xffff;
        param_1 = iVar2 * 3;
        param_2 = (int)(&DAT_00421f18 + iVar3 * 0x2a);
        param_3 = 0;
        *(undefined4 *)(param_2 + iVar2 * 6 * 4) = 0;
        iVar2 = iVar2 + 1;
      } while (iVar2 < 7);
      iVar3 = iVar3 + -1;
    } while (-1 < iVar3);
  }
  return;
}



void Move_Bubble(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,int param_7
                )

{
  (&DAT_00421f04)[param_4 * 0x2a + param_5 * 6] = (&DAT_00421f04)[param_6 * 0x2a + param_7 * 6];
  (&DAT_00421f08)[param_4 * 0x2a + param_5 * 6] = (&DAT_00421f08)[param_6 * 0x2a + param_7 * 6];
  (&DAT_00421f0c)[param_4 * 0x2a + param_5 * 6] = (&DAT_00421f0c)[param_6 * 0x2a + param_7 * 6];
  (&DAT_00421f10)[param_4 * 0x2a + param_5 * 6] = (&DAT_00421f10)[param_6 * 0x2a + param_7 * 6];
  (&DAT_00421f14)[param_4 * 0x2a + param_5 * 6] = (&DAT_00421f14)[param_6 * 0x2a + param_7 * 6];
  (&DAT_00421f18)[param_4 * 0x2a + param_5 * 6] = (&DAT_00421f18)[param_6 * 0x2a + param_7 * 6];
  (&DAT_00421f04)[param_6 * 0x2a + param_7 * 6] = 0;
  (&DAT_00421f08)[param_6 * 0x2a + param_7 * 6] = 0xffff;
  (&DAT_00421f0c)[param_6 * 0x2a + param_7 * 6] = 0xffff;
  (&DAT_00421f10)[param_6 * 0x2a + param_7 * 6] = 0xffffffff;
  (&DAT_00421f14)[param_6 * 0x2a + param_7 * 6] = 0xffffffff;
  (&DAT_00421f18)[param_6 * 0x2a + param_7 * 6] = 0;
  return;
}



int Count_Bubbles(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  iVar3 = 0;
  do {
    iVar1 = 0;
    do {
      if ((&DAT_00421f04)[iVar1 * 0x2a + iVar3 * 6] != 0) {
        iVar2 = iVar2 + 1;
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 < 10);
    iVar3 = iVar3 + 1;
  } while (iVar3 < 7);
  return iVar2;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void Update_Bubbles(void)

{
  undefined4 *puVar1;
  bool bVar2;
  undefined3 extraout_var;
  int iVar3;
  undefined extraout_CL;
  int extraout_ECX;
  int extraout_ECX_00;
  int extraout_ECX_01;
  int extraout_ECX_02;
  int extraout_ECX_03;
  undefined4 *extraout_ECX_04;
  int extraout_ECX_05;
  int extraout_ECX_06;
  int extraout_ECX_07;
  int extraout_ECX_08;
  undefined4 *extraout_ECX_09;
  int extraout_ECX_10;
  int extraout_ECX_11;
  int extraout_ECX_12;
  undefined4 *extraout_ECX_13;
  int extraout_ECX_14;
  int extraout_ECX_15;
  undefined4 *extraout_ECX_16;
  int extraout_ECX_17;
  undefined4 *extraout_ECX_18;
  undefined4 *extraout_ECX_19;
  int extraout_ECX_20;
  int extraout_ECX_21;
  int extraout_ECX_22;
  int extraout_ECX_23;
  int extraout_ECX_24;
  int extraout_ECX_25;
  undefined4 *extraout_ECX_26;
  int extraout_ECX_27;
  int extraout_ECX_28;
  int extraout_ECX_29;
  int extraout_ECX_30;
  int extraout_ECX_31;
  undefined4 *extraout_ECX_32;
  int extraout_ECX_33;
  int extraout_ECX_34;
  int extraout_ECX_35;
  int extraout_ECX_36;
  undefined4 *extraout_ECX_37;
  int extraout_ECX_38;
  int extraout_ECX_39;
  int extraout_ECX_40;
  undefined4 *extraout_ECX_41;
  int extraout_ECX_42;
  int extraout_ECX_43;
  undefined4 *extraout_ECX_44;
  int extraout_ECX_45;
  undefined4 *extraout_ECX_46;
  undefined4 *extraout_ECX_47;
  int extraout_ECX_48;
  int extraout_ECX_49;
  int extraout_ECX_50;
  int extraout_ECX_51;
  int extraout_ECX_52;
  int extraout_ECX_53;
  undefined4 *extraout_ECX_54;
  int extraout_ECX_55;
  int extraout_ECX_56;
  int extraout_ECX_57;
  int extraout_ECX_58;
  int extraout_ECX_59;
  undefined4 *extraout_ECX_60;
  int extraout_ECX_61;
  int extraout_ECX_62;
  int extraout_ECX_63;
  int extraout_ECX_64;
  undefined4 *extraout_ECX_65;
  int extraout_ECX_66;
  int extraout_ECX_67;
  int extraout_ECX_68;
  undefined4 *extraout_ECX_69;
  int extraout_ECX_70;
  int extraout_ECX_71;
  undefined4 *extraout_ECX_72;
  int extraout_ECX_73;
  undefined4 *extraout_ECX_74;
  undefined4 *extraout_ECX_75;
  int extraout_ECX_76;
  int extraout_ECX_77;
  int extraout_ECX_78;
  int extraout_ECX_79;
  int extraout_ECX_80;
  int extraout_ECX_81;
  undefined4 *extraout_ECX_82;
  undefined4 *extraout_ECX_83;
  int extraout_ECX_84;
  int extraout_ECX_85;
  int extraout_ECX_86;
  int extraout_ECX_87;
  int extraout_ECX_88;
  undefined4 *extraout_ECX_89;
  int extraout_ECX_90;
  int extraout_ECX_91;
  int extraout_ECX_92;
  int extraout_ECX_93;
  undefined4 *extraout_ECX_94;
  int extraout_ECX_95;
  int extraout_ECX_96;
  int extraout_ECX_97;
  undefined4 *extraout_ECX_98;
  int extraout_ECX_99;
  int extraout_ECX_x00100;
  undefined4 *extraout_ECX_x00101;
  int extraout_ECX_x00102;
  undefined4 *extraout_ECX_x00103;
  undefined4 *extraout_ECX_x00104;
  int extraout_ECX_x00105;
  int extraout_ECX_x00106;
  int extraout_ECX_x00107;
  int extraout_ECX_x00108;
  int extraout_ECX_x00109;
  int extraout_ECX_x00110;
  undefined4 *extraout_ECX_x00111;
  undefined4 *extraout_ECX_x00112;
  undefined4 *puVar4;
  int extraout_ECX_x00113;
  int extraout_ECX_x00114;
  int extraout_ECX_x00115;
  undefined extraout_DL;
  int extraout_EDX;
  int extraout_EDX_00;
  int extraout_EDX_01;
  int extraout_EDX_02;
  int extraout_EDX_03;
  undefined4 *extraout_EDX_04;
  int extraout_EDX_05;
  int extraout_EDX_06;
  int extraout_EDX_07;
  int extraout_EDX_08;
  undefined4 *extraout_EDX_09;
  int extraout_EDX_10;
  int extraout_EDX_11;
  int extraout_EDX_12;
  undefined4 *extraout_EDX_13;
  int extraout_EDX_14;
  int extraout_EDX_15;
  undefined4 *extraout_EDX_16;
  int extraout_EDX_17;
  undefined4 *extraout_EDX_18;
  undefined4 *extraout_EDX_19;
  undefined4 *extraout_EDX_20;
  int extraout_EDX_21;
  int extraout_EDX_22;
  int extraout_EDX_23;
  int extraout_EDX_24;
  int extraout_EDX_25;
  int extraout_EDX_26;
  undefined4 *extraout_EDX_27;
  undefined4 *extraout_EDX_28;
  int extraout_EDX_29;
  int extraout_EDX_30;
  int extraout_EDX_31;
  int extraout_EDX_32;
  int extraout_EDX_33;
  undefined4 *extraout_EDX_34;
  int extraout_EDX_35;
  int extraout_EDX_36;
  int extraout_EDX_37;
  int extraout_EDX_38;
  undefined4 *extraout_EDX_39;
  int extraout_EDX_40;
  int extraout_EDX_41;
  int extraout_EDX_42;
  undefined4 *extraout_EDX_43;
  int extraout_EDX_44;
  int extraout_EDX_45;
  undefined4 *extraout_EDX_46;
  int extraout_EDX_47;
  undefined4 *extraout_EDX_48;
  undefined4 *extraout_EDX_49;
  undefined4 *extraout_EDX_50;
  int extraout_EDX_51;
  int extraout_EDX_52;
  int extraout_EDX_53;
  int extraout_EDX_54;
  int extraout_EDX_55;
  int extraout_EDX_56;
  undefined4 *extraout_EDX_57;
  undefined4 *extraout_EDX_58;
  undefined4 *extraout_EDX_59;
  int extraout_EDX_60;
  int extraout_EDX_61;
  int extraout_EDX_62;
  int extraout_EDX_63;
  int extraout_EDX_64;
  undefined4 *extraout_EDX_65;
  int extraout_EDX_66;
  int extraout_EDX_67;
  int extraout_EDX_68;
  int extraout_EDX_69;
  undefined4 *extraout_EDX_70;
  int extraout_EDX_71;
  int extraout_EDX_72;
  int extraout_EDX_73;
  undefined4 *extraout_EDX_74;
  int extraout_EDX_75;
  int extraout_EDX_76;
  undefined4 *extraout_EDX_77;
  int extraout_EDX_78;
  undefined4 *extraout_EDX_79;
  undefined4 *extraout_EDX_80;
  undefined4 *extraout_EDX_81;
  int extraout_EDX_82;
  int extraout_EDX_83;
  int extraout_EDX_84;
  int extraout_EDX_85;
  int extraout_EDX_86;
  int extraout_EDX_87;
  undefined4 *extraout_EDX_88;
  undefined4 *extraout_EDX_89;
  undefined4 *puVar5;
  int extraout_EDX_90;
  int extraout_EDX_91;
  int extraout_EDX_92;
  int extraout_EDX_93;
  int extraout_EDX_94;
  undefined4 *extraout_EDX_95;
  int extraout_EDX_96;
  int extraout_EDX_97;
  int extraout_EDX_98;
  int extraout_EDX_99;
  undefined4 *extraout_EDX_x00100;
  int extraout_EDX_x00101;
  int extraout_EDX_x00102;
  int extraout_EDX_x00103;
  undefined4 *extraout_EDX_x00104;
  int extraout_EDX_x00105;
  int extraout_EDX_x00106;
  undefined4 *extraout_EDX_x00107;
  int extraout_EDX_x00108;
  undefined4 *extraout_EDX_x00109;
  undefined4 *extraout_EDX_x00110;
  undefined4 *extraout_EDX_x00111;
  int extraout_EDX_x00112;
  int extraout_EDX_x00113;
  int extraout_EDX_x00114;
  int extraout_EDX_x00115;
  int extraout_EDX_x00116;
  int extraout_EDX_x00117;
  undefined4 *extraout_EDX_x00118;
  undefined4 *extraout_EDX_x00119;
  int extraout_EDX_x00120;
  int extraout_EDX_x00121;
  int extraout_EDX_x00122;
  int iVar6;
  undefined4 *puVar7;
  int iVar8;
  int unaff_EDI;
  int local_8;
  
  iVar8 = 0;
  do {
    iVar6 = 0;
    do {
      (&DAT_00422c24)[iVar6 * 7 + iVar8] = (&DAT_00421f04)[iVar6 * 0x2a + iVar8 * 6];
      (&DAT_00421f10)[iVar6 * 0x2a + iVar8 * 6] = iVar6;
      (&DAT_00421f14)[iVar6 * 0x2a + iVar8 * 6] = iVar8;
      (&DAT_00421f08)[iVar6 * 0x2a + iVar8 * 6] = iVar6 * 0x30 + 8;
      (&DAT_00421f0c)[iVar6 * 0x2a + iVar8 * 6] = iVar8 * 0x30 + 8;
      puVar4 = &DAT_00421f18 + iVar6 * 0x2a;
      if (puVar4[iVar8 * 6] != 0) {
        (&DAT_00421f18)[iVar6 * 0x2a + iVar8 * 6] = 0;
        (&DAT_00421f04)[iVar6 * 0x2a + iVar8 * 6] = 0;
        (&DAT_00421f08)[iVar6 * 0x2a + iVar8 * 6] = 0xffff;
        puVar4 = &DAT_00421f0c + iVar6 * 0x2a;
        puVar4[iVar8 * 6] = 0xffff;
      }
      puVar5 = (undefined4 *)(iVar8 * 3);
      iVar6 = iVar6 + 1;
    } while (iVar6 < 10);
    iVar8 = iVar8 + 1;
  } while (iVar8 < 7);
  if (DAT_00420134 == 0) {
    iVar8 = 9;
    do {
      local_8 = 0;
      do {
        iVar6 = iVar8 * 0x15;
        if ((&DAT_00421f94)[iVar8 * 0x2a] == 0) {
          Move_Bubble(iVar6,(int)puVar5,(int)puVar4,iVar8,6,iVar8,5);
          Move_Bubble(iVar6,extraout_EDX,extraout_ECX,iVar8,5,iVar8,4);
          Move_Bubble(iVar6,extraout_EDX_00,extraout_ECX_00,iVar8,4,iVar8,3);
          Move_Bubble(iVar6,extraout_EDX_01,extraout_ECX_01,iVar8,3,iVar8,2);
          Move_Bubble(iVar6,extraout_EDX_02,extraout_ECX_02,iVar8,2,iVar8,1);
          Move_Bubble(iVar6,extraout_EDX_03,extraout_ECX_03,iVar8,1,iVar8,0);
          puVar4 = extraout_ECX_04;
          puVar5 = extraout_EDX_04;
        }
        iVar6 = iVar8 * 0x15;
        if ((&DAT_00421f7c)[iVar8 * 0x2a] == 0) {
          Move_Bubble(iVar6,(int)puVar5,(int)puVar4,iVar8,5,iVar8,4);
          Move_Bubble(iVar6,extraout_EDX_05,extraout_ECX_05,iVar8,4,iVar8,3);
          Move_Bubble(iVar6,extraout_EDX_06,extraout_ECX_06,iVar8,3,iVar8,2);
          Move_Bubble(iVar6,extraout_EDX_07,extraout_ECX_07,iVar8,2,iVar8,1);
          Move_Bubble(iVar6,extraout_EDX_08,extraout_ECX_08,iVar8,1,iVar8,0);
          puVar4 = extraout_ECX_09;
          puVar5 = extraout_EDX_09;
        }
        iVar6 = iVar8 * 0x15;
        if ((&DAT_00421f64)[iVar8 * 0x2a] == 0) {
          Move_Bubble(iVar6,(int)puVar5,(int)puVar4,iVar8,4,iVar8,3);
          Move_Bubble(iVar6,extraout_EDX_10,extraout_ECX_10,iVar8,3,iVar8,2);
          Move_Bubble(iVar6,extraout_EDX_11,extraout_ECX_11,iVar8,2,iVar8,1);
          Move_Bubble(iVar6,extraout_EDX_12,extraout_ECX_12,iVar8,1,iVar8,0);
          puVar4 = extraout_ECX_13;
          puVar5 = extraout_EDX_13;
        }
        iVar6 = iVar8 * 0x15;
        if ((&DAT_00421f4c)[iVar8 * 0x2a] == 0) {
          Move_Bubble(iVar6,(int)puVar5,(int)puVar4,iVar8,3,iVar8,2);
          Move_Bubble(iVar6,extraout_EDX_14,extraout_ECX_14,iVar8,2,iVar8,1);
          Move_Bubble(iVar6,extraout_EDX_15,extraout_ECX_15,iVar8,1,iVar8,0);
          puVar4 = extraout_ECX_16;
          puVar5 = extraout_EDX_16;
        }
        iVar6 = iVar8 * 0x15;
        if ((&DAT_00421f34)[iVar8 * 0x2a] == 0) {
          Move_Bubble(iVar6,(int)puVar5,(int)puVar4,iVar8,2,iVar8,1);
          Move_Bubble(iVar6,extraout_EDX_17,extraout_ECX_17,iVar8,1,iVar8,0);
          puVar4 = extraout_ECX_18;
          puVar5 = extraout_EDX_18;
        }
        iVar6 = iVar8 * 0x15;
        if ((&DAT_00421f1c)[iVar8 * 0x2a] == 0) {
          Move_Bubble(iVar6,(int)puVar5,(int)puVar4,iVar8,1,iVar8,0);
          puVar4 = extraout_ECX_19;
          puVar5 = extraout_EDX_19;
        }
        local_8 = local_8 + 1;
      } while (local_8 < 7);
      iVar8 = iVar8 + -1;
    } while (-1 < iVar8);
    local_8 = 9;
    do {
      puVar7 = (undefined4 *)0x9;
      do {
        puVar1 = puVar7;
        Check_Free_Row(iVar6,(int)puVar5,(int)puVar4,(int)puVar7);
        puVar4 = puVar1;
        puVar5 = extraout_EDX_20;
        if (iVar6 != 0) {
          Move_Bubble((int)puVar7 + -1,(int)extraout_EDX_20,(int)puVar4,(int)puVar7,0,
                      (int)puVar7 + -1,0);
          Move_Bubble((int)puVar7 + -1,extraout_EDX_21,extraout_ECX_20,(int)puVar7,1,
                      (int)puVar7 + -1,1);
          Move_Bubble((int)puVar7 + -1,extraout_EDX_22,extraout_ECX_21,(int)puVar7,2,
                      (int)puVar7 + -1,2);
          Move_Bubble((int)puVar7 + -1,extraout_EDX_23,extraout_ECX_22,(int)puVar7,3,
                      (int)puVar7 + -1,3);
          Move_Bubble((int)puVar7 + -1,extraout_EDX_24,extraout_ECX_23,(int)puVar7,4,
                      (int)puVar7 + -1,4);
          Move_Bubble((int)puVar7 + -1,extraout_EDX_25,extraout_ECX_24,(int)puVar7,5,
                      (int)puVar7 + -1,5);
          iVar6 = (int)puVar7 + -1;
          Move_Bubble(iVar6,extraout_EDX_26,extraout_ECX_25,(int)puVar7,6,iVar6,6);
          puVar4 = extraout_ECX_26;
          puVar5 = extraout_EDX_27;
        }
        puVar7 = (undefined4 *)((int)puVar7 + -1);
      } while (0 < (int)puVar7);
      local_8 = local_8 + -1;
    } while (0 < local_8);
    puVar7 = (undefined4 *)0x0;
    Check_Free_Row(iVar6,(int)puVar5,(int)puVar4,0);
    puVar4 = puVar7;
    puVar5 = extraout_EDX_28;
    if (iVar6 != 0) {
      DAT_00421f04 = 0;
      DAT_00421f1c = 0;
      DAT_00421f34 = 0;
      DAT_00421f4c = 0;
      DAT_00421f64 = 0;
      DAT_00421f7c = 0;
      DAT_00421f94 = 0;
    }
  }
  if (DAT_00420134 == 1) {
    iVar8 = 9;
    do {
      local_8 = 0;
      do {
        iVar6 = iVar8 * 0x15;
        if ((&DAT_00421f94)[iVar8 * 0x2a] == 0) {
          Move_Bubble(iVar6,(int)puVar5,(int)puVar4,iVar8,6,iVar8,5);
          Move_Bubble(iVar6,extraout_EDX_29,extraout_ECX_27,iVar8,5,iVar8,4);
          Move_Bubble(iVar6,extraout_EDX_30,extraout_ECX_28,iVar8,4,iVar8,3);
          Move_Bubble(iVar6,extraout_EDX_31,extraout_ECX_29,iVar8,3,iVar8,2);
          Move_Bubble(iVar6,extraout_EDX_32,extraout_ECX_30,iVar8,2,iVar8,1);
          Move_Bubble(iVar6,extraout_EDX_33,extraout_ECX_31,iVar8,1,iVar8,0);
          puVar4 = extraout_ECX_32;
          puVar5 = extraout_EDX_34;
        }
        iVar6 = iVar8 * 0x15;
        if ((&DAT_00421f7c)[iVar8 * 0x2a] == 0) {
          Move_Bubble(iVar6,(int)puVar5,(int)puVar4,iVar8,5,iVar8,4);
          Move_Bubble(iVar6,extraout_EDX_35,extraout_ECX_33,iVar8,4,iVar8,3);
          Move_Bubble(iVar6,extraout_EDX_36,extraout_ECX_34,iVar8,3,iVar8,2);
          Move_Bubble(iVar6,extraout_EDX_37,extraout_ECX_35,iVar8,2,iVar8,1);
          Move_Bubble(iVar6,extraout_EDX_38,extraout_ECX_36,iVar8,1,iVar8,0);
          puVar4 = extraout_ECX_37;
          puVar5 = extraout_EDX_39;
        }
        iVar6 = iVar8 * 0x15;
        if ((&DAT_00421f64)[iVar8 * 0x2a] == 0) {
          Move_Bubble(iVar6,(int)puVar5,(int)puVar4,iVar8,4,iVar8,3);
          Move_Bubble(iVar6,extraout_EDX_40,extraout_ECX_38,iVar8,3,iVar8,2);
          Move_Bubble(iVar6,extraout_EDX_41,extraout_ECX_39,iVar8,2,iVar8,1);
          Move_Bubble(iVar6,extraout_EDX_42,extraout_ECX_40,iVar8,1,iVar8,0);
          puVar4 = extraout_ECX_41;
          puVar5 = extraout_EDX_43;
        }
        iVar6 = iVar8 * 0x15;
        if ((&DAT_00421f4c)[iVar8 * 0x2a] == 0) {
          Move_Bubble(iVar6,(int)puVar5,(int)puVar4,iVar8,3,iVar8,2);
          Move_Bubble(iVar6,extraout_EDX_44,extraout_ECX_42,iVar8,2,iVar8,1);
          Move_Bubble(iVar6,extraout_EDX_45,extraout_ECX_43,iVar8,1,iVar8,0);
          puVar4 = extraout_ECX_44;
          puVar5 = extraout_EDX_46;
        }
        iVar6 = iVar8 * 0x15;
        if ((&DAT_00421f34)[iVar8 * 0x2a] == 0) {
          Move_Bubble(iVar6,(int)puVar5,(int)puVar4,iVar8,2,iVar8,1);
          Move_Bubble(iVar6,extraout_EDX_47,extraout_ECX_45,iVar8,1,iVar8,0);
          puVar4 = extraout_ECX_46;
          puVar5 = extraout_EDX_48;
        }
        iVar6 = iVar8 * 0x15;
        if ((&DAT_00421f1c)[iVar8 * 0x2a] == 0) {
          Move_Bubble(iVar6,(int)puVar5,(int)puVar4,iVar8,1,iVar8,0);
          puVar4 = extraout_ECX_47;
          puVar5 = extraout_EDX_49;
        }
        local_8 = local_8 + 1;
      } while (local_8 < 7);
      iVar8 = iVar8 + -1;
    } while (-1 < iVar8);
    local_8 = 9;
    do {
      puVar7 = (undefined4 *)0x9;
      do {
        puVar1 = puVar7;
        Check_Free_Row(iVar6,(int)puVar5,(int)puVar4,(int)puVar7);
        puVar4 = puVar1;
        puVar5 = extraout_EDX_50;
        if (iVar6 != 0) {
          Move_Bubble((int)puVar7 + -1,(int)extraout_EDX_50,(int)puVar4,(int)puVar7,0,
                      (int)puVar7 + -1,0);
          Move_Bubble((int)puVar7 + -1,extraout_EDX_51,extraout_ECX_48,(int)puVar7,1,
                      (int)puVar7 + -1,1);
          Move_Bubble((int)puVar7 + -1,extraout_EDX_52,extraout_ECX_49,(int)puVar7,2,
                      (int)puVar7 + -1,2);
          Move_Bubble((int)puVar7 + -1,extraout_EDX_53,extraout_ECX_50,(int)puVar7,3,
                      (int)puVar7 + -1,3);
          Move_Bubble((int)puVar7 + -1,extraout_EDX_54,extraout_ECX_51,(int)puVar7,4,
                      (int)puVar7 + -1,4);
          Move_Bubble((int)puVar7 + -1,extraout_EDX_55,extraout_ECX_52,(int)puVar7,5,
                      (int)puVar7 + -1,5);
          iVar6 = (int)puVar7 + -1;
          Move_Bubble(iVar6,extraout_EDX_56,extraout_ECX_53,(int)puVar7,6,iVar6,6);
          puVar4 = extraout_ECX_54;
          puVar5 = extraout_EDX_57;
        }
        puVar7 = (undefined4 *)((int)puVar7 + -1);
      } while (0 < (int)puVar7);
      local_8 = local_8 + -1;
    } while (0 < local_8);
    puVar7 = (undefined4 *)0x9;
    do {
      puVar1 = puVar7;
      Check_Free_Row(iVar6,(int)puVar5,(int)puVar4,(int)puVar7);
      puVar4 = puVar1;
      if (iVar6 != 0) {
        Fill_Rows(iVar6,(int)extraout_EDX_58,(int)puVar4,(int)puVar7);
        puVar4 = puVar7;
        puVar5 = extraout_EDX_59;
        break;
      }
      puVar7 = (undefined4 *)((int)puVar7 + -1);
      iVar6 = 0;
      puVar5 = extraout_EDX_58;
    } while (-1 < (int)puVar7);
  }
  if (DAT_00420134 == 2) {
    iVar8 = 9;
    do {
      local_8 = 0;
      do {
        iVar6 = iVar8 * 0x15;
        if ((&DAT_00421f94)[iVar8 * 0x2a] == 0) {
          Move_Bubble(iVar6,(int)puVar5,(int)puVar4,iVar8,6,iVar8,5);
          Move_Bubble(iVar6,extraout_EDX_60,extraout_ECX_55,iVar8,5,iVar8,4);
          Move_Bubble(iVar6,extraout_EDX_61,extraout_ECX_56,iVar8,4,iVar8,3);
          Move_Bubble(iVar6,extraout_EDX_62,extraout_ECX_57,iVar8,3,iVar8,2);
          Move_Bubble(iVar6,extraout_EDX_63,extraout_ECX_58,iVar8,2,iVar8,1);
          Move_Bubble(iVar6,extraout_EDX_64,extraout_ECX_59,iVar8,1,iVar8,0);
          puVar4 = extraout_ECX_60;
          puVar5 = extraout_EDX_65;
        }
        iVar6 = iVar8 * 0x15;
        if ((&DAT_00421f7c)[iVar8 * 0x2a] == 0) {
          Move_Bubble(iVar6,(int)puVar5,(int)puVar4,iVar8,5,iVar8,4);
          Move_Bubble(iVar6,extraout_EDX_66,extraout_ECX_61,iVar8,4,iVar8,3);
          Move_Bubble(iVar6,extraout_EDX_67,extraout_ECX_62,iVar8,3,iVar8,2);
          Move_Bubble(iVar6,extraout_EDX_68,extraout_ECX_63,iVar8,2,iVar8,1);
          Move_Bubble(iVar6,extraout_EDX_69,extraout_ECX_64,iVar8,1,iVar8,0);
          puVar4 = extraout_ECX_65;
          puVar5 = extraout_EDX_70;
        }
        iVar6 = iVar8 * 0x15;
        if ((&DAT_00421f64)[iVar8 * 0x2a] == 0) {
          Move_Bubble(iVar6,(int)puVar5,(int)puVar4,iVar8,4,iVar8,3);
          Move_Bubble(iVar6,extraout_EDX_71,extraout_ECX_66,iVar8,3,iVar8,2);
          Move_Bubble(iVar6,extraout_EDX_72,extraout_ECX_67,iVar8,2,iVar8,1);
          Move_Bubble(iVar6,extraout_EDX_73,extraout_ECX_68,iVar8,1,iVar8,0);
          puVar4 = extraout_ECX_69;
          puVar5 = extraout_EDX_74;
        }
        iVar6 = iVar8 * 0x15;
        if ((&DAT_00421f4c)[iVar8 * 0x2a] == 0) {
          Move_Bubble(iVar6,(int)puVar5,(int)puVar4,iVar8,3,iVar8,2);
          Move_Bubble(iVar6,extraout_EDX_75,extraout_ECX_70,iVar8,2,iVar8,1);
          Move_Bubble(iVar6,extraout_EDX_76,extraout_ECX_71,iVar8,1,iVar8,0);
          puVar4 = extraout_ECX_72;
          puVar5 = extraout_EDX_77;
        }
        iVar6 = iVar8 * 0x15;
        if ((&DAT_00421f34)[iVar8 * 0x2a] == 0) {
          Move_Bubble(iVar6,(int)puVar5,(int)puVar4,iVar8,2,iVar8,1);
          Move_Bubble(iVar6,extraout_EDX_78,extraout_ECX_73,iVar8,1,iVar8,0);
          puVar4 = extraout_ECX_74;
          puVar5 = extraout_EDX_79;
        }
        iVar6 = iVar8 * 0x15;
        if ((&DAT_00421f1c)[iVar8 * 0x2a] == 0) {
          Move_Bubble(iVar6,(int)puVar5,(int)puVar4,iVar8,1,iVar8,0);
          puVar4 = extraout_ECX_75;
          puVar5 = extraout_EDX_80;
        }
        local_8 = local_8 + 1;
      } while (local_8 < 7);
      iVar8 = iVar8 + -1;
    } while (-1 < iVar8);
    local_8 = 9;
    do {
      puVar7 = (undefined4 *)0x9;
      do {
        puVar1 = puVar7;
        Check_Free_Row(iVar6,(int)puVar5,(int)puVar4,(int)puVar7);
        puVar4 = puVar1;
        puVar5 = extraout_EDX_81;
        if (iVar6 != 0) {
          Move_Bubble((int)puVar7 + -1,(int)extraout_EDX_81,(int)puVar4,(int)puVar7,0,
                      (int)puVar7 + -1,0);
          Move_Bubble((int)puVar7 + -1,extraout_EDX_82,extraout_ECX_76,(int)puVar7,1,
                      (int)puVar7 + -1,1);
          Move_Bubble((int)puVar7 + -1,extraout_EDX_83,extraout_ECX_77,(int)puVar7,2,
                      (int)puVar7 + -1,2);
          Move_Bubble((int)puVar7 + -1,extraout_EDX_84,extraout_ECX_78,(int)puVar7,3,
                      (int)puVar7 + -1,3);
          Move_Bubble((int)puVar7 + -1,extraout_EDX_85,extraout_ECX_79,(int)puVar7,4,
                      (int)puVar7 + -1,4);
          Move_Bubble((int)puVar7 + -1,extraout_EDX_86,extraout_ECX_80,(int)puVar7,5,
                      (int)puVar7 + -1,5);
          iVar6 = (int)puVar7 + -1;
          Move_Bubble(iVar6,extraout_EDX_87,extraout_ECX_81,(int)puVar7,6,iVar6,6);
          puVar4 = extraout_ECX_82;
          puVar5 = extraout_EDX_88;
        }
        puVar7 = (undefined4 *)((int)puVar7 + -1);
      } while (0 < (int)puVar7);
      local_8 = local_8 + -1;
    } while (0 < local_8);
    puVar7 = (undefined4 *)0x0;
    Check_Free_Row(iVar6,(int)puVar5,(int)puVar4,0);
    puVar4 = puVar7;
    if (iVar6 != 0) {
      DAT_00421f04 = 0;
      DAT_00421f1c = 0;
      DAT_00421f34 = 0;
      DAT_00421f4c = 0;
      DAT_00421f64 = 0;
      DAT_00421f7c = 0;
      DAT_00421f94 = 0;
    }
    local_8 = 0;
    do {
      iVar8 = 0;
      do {
        iVar6 = 0;
        do {
          puVar5 = &DAT_00421fac + iVar8 * 0x2a;
          if (puVar5[iVar6 * 6] == 0) {
            Move_Bubble(iVar8 + 1,(int)puVar5,(int)puVar4,iVar8 + 1,iVar6,iVar8,iVar6);
            puVar4 = extraout_ECX_83;
            puVar5 = extraout_EDX_89;
          }
          iVar6 = iVar6 + 1;
        } while (iVar6 < 7);
        iVar8 = iVar8 + 1;
      } while (iVar8 < 9);
      local_8 = local_8 + 1;
    } while (local_8 < 10);
  }
  if (DAT_00420134 == 3) {
    iVar8 = 9;
    do {
      local_8 = 0;
      do {
        iVar6 = iVar8 * 0x15;
        if ((&DAT_00421f94)[iVar8 * 0x2a] == 0) {
          Move_Bubble(iVar6,(int)puVar5,(int)puVar4,iVar8,6,iVar8,5);
          Move_Bubble(iVar6,extraout_EDX_90,extraout_ECX_84,iVar8,5,iVar8,4);
          Move_Bubble(iVar6,extraout_EDX_91,extraout_ECX_85,iVar8,4,iVar8,3);
          Move_Bubble(iVar6,extraout_EDX_92,extraout_ECX_86,iVar8,3,iVar8,2);
          Move_Bubble(iVar6,extraout_EDX_93,extraout_ECX_87,iVar8,2,iVar8,1);
          Move_Bubble(iVar6,extraout_EDX_94,extraout_ECX_88,iVar8,1,iVar8,0);
          puVar4 = extraout_ECX_89;
          puVar5 = extraout_EDX_95;
        }
        iVar6 = iVar8 * 0x15;
        if ((&DAT_00421f7c)[iVar8 * 0x2a] == 0) {
          Move_Bubble(iVar6,(int)puVar5,(int)puVar4,iVar8,5,iVar8,4);
          Move_Bubble(iVar6,extraout_EDX_96,extraout_ECX_90,iVar8,4,iVar8,3);
          Move_Bubble(iVar6,extraout_EDX_97,extraout_ECX_91,iVar8,3,iVar8,2);
          Move_Bubble(iVar6,extraout_EDX_98,extraout_ECX_92,iVar8,2,iVar8,1);
          Move_Bubble(iVar6,extraout_EDX_99,extraout_ECX_93,iVar8,1,iVar8,0);
          puVar4 = extraout_ECX_94;
          puVar5 = extraout_EDX_x00100;
        }
        iVar6 = iVar8 * 0x15;
        if ((&DAT_00421f64)[iVar8 * 0x2a] == 0) {
          Move_Bubble(iVar6,(int)puVar5,(int)puVar4,iVar8,4,iVar8,3);
          Move_Bubble(iVar6,extraout_EDX_x00101,extraout_ECX_95,iVar8,3,iVar8,2);
          Move_Bubble(iVar6,extraout_EDX_x00102,extraout_ECX_96,iVar8,2,iVar8,1);
          Move_Bubble(iVar6,extraout_EDX_x00103,extraout_ECX_97,iVar8,1,iVar8,0);
          puVar4 = extraout_ECX_98;
          puVar5 = extraout_EDX_x00104;
        }
        iVar6 = iVar8 * 0x15;
        if ((&DAT_00421f4c)[iVar8 * 0x2a] == 0) {
          Move_Bubble(iVar6,(int)puVar5,(int)puVar4,iVar8,3,iVar8,2);
          Move_Bubble(iVar6,extraout_EDX_x00105,extraout_ECX_99,iVar8,2,iVar8,1);
          Move_Bubble(iVar6,extraout_EDX_x00106,extraout_ECX_x00100,iVar8,1,iVar8,0);
          puVar4 = extraout_ECX_x00101;
          puVar5 = extraout_EDX_x00107;
        }
        iVar6 = iVar8 * 0x15;
        if ((&DAT_00421f34)[iVar8 * 0x2a] == 0) {
          Move_Bubble(iVar6,(int)puVar5,(int)puVar4,iVar8,2,iVar8,1);
          Move_Bubble(iVar6,extraout_EDX_x00108,extraout_ECX_x00102,iVar8,1,iVar8,0);
          puVar4 = extraout_ECX_x00103;
          puVar5 = extraout_EDX_x00109;
        }
        iVar6 = iVar8 * 0x15;
        if ((&DAT_00421f1c)[iVar8 * 0x2a] == 0) {
          Move_Bubble(iVar6,(int)puVar5,(int)puVar4,iVar8,1,iVar8,0);
          puVar4 = extraout_ECX_x00104;
          puVar5 = extraout_EDX_x00110;
        }
        local_8 = local_8 + 1;
      } while (local_8 < 7);
      iVar8 = iVar8 + -1;
    } while (-1 < iVar8);
    local_8 = 9;
    do {
      puVar7 = (undefined4 *)0x9;
      do {
        puVar1 = puVar7;
        Check_Free_Row(iVar6,(int)puVar5,(int)puVar4,(int)puVar7);
        puVar4 = puVar1;
        puVar5 = extraout_EDX_x00111;
        if (iVar6 != 0) {
          Move_Bubble((int)puVar7 + -1,(int)extraout_EDX_x00111,(int)puVar4,(int)puVar7,0,
                      (int)puVar7 + -1,0);
          Move_Bubble((int)puVar7 + -1,extraout_EDX_x00112,extraout_ECX_x00105,(int)puVar7,1,
                      (int)puVar7 + -1,1);
          Move_Bubble((int)puVar7 + -1,extraout_EDX_x00113,extraout_ECX_x00106,(int)puVar7,2,
                      (int)puVar7 + -1,2);
          Move_Bubble((int)puVar7 + -1,extraout_EDX_x00114,extraout_ECX_x00107,(int)puVar7,3,
                      (int)puVar7 + -1,3);
          Move_Bubble((int)puVar7 + -1,extraout_EDX_x00115,extraout_ECX_x00108,(int)puVar7,4,
                      (int)puVar7 + -1,4);
          Move_Bubble((int)puVar7 + -1,extraout_EDX_x00116,extraout_ECX_x00109,(int)puVar7,5,
                      (int)puVar7 + -1,5);
          iVar6 = (int)puVar7 + -1;
          Move_Bubble(iVar6,extraout_EDX_x00117,extraout_ECX_x00110,(int)puVar7,6,iVar6,6);
          puVar4 = extraout_ECX_x00111;
          puVar5 = extraout_EDX_x00118;
        }
        puVar7 = (undefined4 *)((int)puVar7 + -1);
      } while (0 < (int)puVar7);
      local_8 = local_8 + -1;
    } while (0 < local_8);
    puVar7 = (undefined4 *)0x9;
    do {
      puVar1 = puVar7;
      Check_Free_Row(iVar6,(int)puVar5,(int)puVar4,(int)puVar7);
      puVar4 = puVar1;
      if (iVar6 != 0) {
        Fill_Rows(iVar6,(int)extraout_EDX_x00119,(int)puVar4,(int)puVar7);
        puVar4 = puVar7;
        break;
      }
      puVar7 = (undefined4 *)((int)puVar7 + -1);
      iVar6 = 0;
      puVar5 = extraout_EDX_x00119;
    } while (-1 < (int)puVar7);
    local_8 = 0;
    do {
      iVar8 = 0;
      do {
        iVar6 = 0;
        do {
          if ((&DAT_00421fac + iVar8 * 0x2a)[iVar6 * 6] == 0) {
            Move_Bubble(iVar8 + 1,(int)(&DAT_00421fac + iVar8 * 0x2a),(int)puVar4,iVar8 + 1,iVar6,
                        iVar8,iVar6);
            puVar4 = extraout_ECX_x00112;
          }
          iVar6 = iVar6 + 1;
        } while (iVar6 < 7);
        iVar8 = iVar8 + 1;
      } while (iVar8 < 9);
      local_8 = local_8 + 1;
    } while (local_8 < 10);
  }
  DAT_0042011c = 0;
  DAT_00420130 = 0;
  DAT_00421ee0 = DAT_00421ee0 + DAT_00421eac;
  DAT_00422d3c = DAT_00421eac;
  DAT_00421eac = 0;
  DAT_00420120 = (uint)(DAT_00421ef0 != 0);
  iVar8 = Create_Screen();
  if (DAT_00421eec != 0) {
    bVar2 = mci_PlayWave((char)iVar8,extraout_DL,extraout_CL,&DAT_0042088b);
    iVar8 = CONCAT31(extraout_var,bVar2);
  }
  Check_Game_Over();
  if (iVar8 != 0) {
    iVar3 = 0;
    DAT_00420128 = 0;
    iVar8 = extraout_ECX_x00113;
    iVar6 = extraout_EDX_x00120;
    if (DAT_00420134 == 0) {
      iVar8 = Count_Bubbles();
      if (iVar8 == 4) {
        DAT_00421ee4 = 0x19;
      }
      iVar8 = Count_Bubbles();
      if (iVar8 == 3) {
        DAT_00421ee4 = 0x32;
      }
      iVar8 = Count_Bubbles();
      if (iVar8 == 2) {
        DAT_00421ee4 = 100;
      }
      iVar8 = Count_Bubbles();
      if (iVar8 == 1) {
        DAT_00421ee4 = 200;
      }
      iVar8 = Count_Bubbles();
      if (iVar8 == 0) {
        DAT_00421ee4 = 500;
      }
      _Str_00421eb0 = (void *)((int)_Str_00421eb0 + 1);
      DAT_00421eb4 = DAT_00421eb4 + DAT_00421ee0 + DAT_00421ee4;
      iVar3 = DAT_00421ee0 + DAT_00421ee4;
      iVar8 = extraout_ECX_x00114;
      iVar6 = extraout_EDX_x00121;
      if (DAT_00421eb8 < iVar3) {
        iVar3 = DAT_00421ee0 + DAT_00421ee4;
        DAT_00420128 = 1;
        DAT_00421eb8 = iVar3;
      }
    }
    if (DAT_00420134 == 1) {
      DAT_00421ebc = DAT_00421ebc + 1;
      DAT_00421ec0 = DAT_00421ec0 + DAT_00421ee0 + DAT_00421ee4;
      iVar3 = DAT_00421ee0 + DAT_00421ee4;
      if (DAT_00421ec4 < iVar3) {
        iVar3 = DAT_00421ee0 + DAT_00421ee4;
        DAT_00420128 = 1;
        DAT_00421ec4 = iVar3;
      }
    }
    if (DAT_00420134 == 2) {
      iVar8 = Count_Bubbles();
      if (iVar8 == 4) {
        DAT_00421ee4 = 0x19;
      }
      iVar8 = Count_Bubbles();
      if (iVar8 == 3) {
        DAT_00421ee4 = 0x32;
      }
      iVar8 = Count_Bubbles();
      if (iVar8 == 2) {
        DAT_00421ee4 = 100;
      }
      iVar8 = Count_Bubbles();
      if (iVar8 == 1) {
        DAT_00421ee4 = 200;
      }
      iVar8 = Count_Bubbles();
      if (iVar8 == 0) {
        DAT_00421ee4 = 500;
      }
      DAT_00421ec8 = DAT_00421ec8 + 1;
      DAT_00421ecc = DAT_00421ecc + DAT_00421ee0 + DAT_00421ee4;
      iVar3 = DAT_00421ee0 + DAT_00421ee4;
      iVar8 = extraout_ECX_x00115;
      iVar6 = extraout_EDX_x00122;
      if (DAT_00421ed0 < iVar3) {
        iVar3 = DAT_00421ee0 + DAT_00421ee4;
        DAT_00420128 = 1;
        DAT_00421ed0 = iVar3;
      }
    }
    if (DAT_00420134 == 3) {
      DAT_00421ed4 = DAT_00421ed4 + 1;
      DAT_00421ed8 = DAT_00421ed8 + DAT_00421ee0 + DAT_00421ee4;
      iVar3 = DAT_00421ee0 + DAT_00421ee4;
      if (DAT_00421edc < iVar3) {
        iVar3 = DAT_00421ee0 + DAT_00421ee4;
        DAT_00420128 = 1;
        DAT_00421edc = iVar3;
      }
    }
    _DAT_00420138 = 1;
    if (DAT_00420120 == 0) {
      change_mode(iVar3,iVar6,iVar8,9,unaff_EDI);
    }
    else {
      DAT_00420124 = 1;
    }
  }
  return;
}



void Undo_Move(void)

{
  int iVar1;
  int iVar2;
  
  if (DAT_0042012c != 0) {
    iVar2 = 0;
    do {
      iVar1 = 0;
      do {
        (&DAT_00422594)[iVar1 * 0x2a + iVar2 * 6] = 0;
        (&DAT_00422594)
        [(&DAT_00421f10)[iVar1 * 0x2a + iVar2 * 6] * 0x2a +
         (&DAT_00421f14)[iVar1 * 0x2a + iVar2 * 6] * 6] = (&DAT_00421f04)[iVar1 * 0x2a + iVar2 * 6];
        (&DAT_00422598)
        [(&DAT_00421f10)[iVar1 * 0x2a + iVar2 * 6] * 0x2a +
         (&DAT_00421f14)[iVar1 * 0x2a + iVar2 * 6] * 6] = iVar1 * 0x30 + 8;
        (&DAT_0042259c)
        [(&DAT_00421f10)[iVar1 * 0x2a + iVar2 * 6] * 0x2a +
         (&DAT_00421f14)[iVar1 * 0x2a + iVar2 * 6] * 6] = iVar2 * 0x30 + 8;
        (&DAT_004225a0)
        [(&DAT_00421f10)[iVar1 * 0x2a + iVar2 * 6] * 0x2a +
         (&DAT_00421f14)[iVar1 * 0x2a + iVar2 * 6] * 6] = 0xffffffff;
        (&DAT_004225a4)
        [(&DAT_00421f10)[iVar1 * 0x2a + iVar2 * 6] * 0x2a +
         (&DAT_00421f14)[iVar1 * 0x2a + iVar2 * 6] * 6] = 0xffffffff;
        (&DAT_004225a8)
        [(&DAT_00421f10)[iVar1 * 0x2a + iVar2 * 6] * 0x2a +
         (&DAT_00421f14)[iVar1 * 0x2a + iVar2 * 6] * 6] = 0;
        iVar1 = iVar1 + 1;
      } while (iVar1 < 10);
      iVar2 = iVar2 + 1;
    } while (iVar2 < 7);
    iVar2 = 0;
    do {
      iVar1 = 0;
      do {
        if ((&DAT_00422594)[iVar1 * 0x2a + iVar2 * 6] == 0) {
          (&DAT_00422594)[iVar1 * 0x2a + iVar2 * 6] = (&DAT_00422c24)[iVar1 * 7 + iVar2];
          (&DAT_00422598)[iVar1 * 0x2a + iVar2 * 6] = iVar1 * 0x30 + 8;
          (&DAT_0042259c)[iVar1 * 0x2a + iVar2 * 6] = iVar2 * 0x30 + 8;
          (&DAT_004225a0)[iVar1 * 0x2a + iVar2 * 6] = 0xffffffff;
          (&DAT_004225a4)[iVar1 * 0x2a + iVar2 * 6] = 0xffffffff;
          (&DAT_004225a8)[iVar1 * 0x2a + iVar2 * 6] = 0;
        }
        iVar1 = iVar1 + 1;
      } while (iVar1 < 10);
      iVar2 = iVar2 + 1;
    } while (iVar2 < 7);
    iVar2 = 0;
    do {
      iVar1 = 0;
      do {
        (&DAT_00421f04)[iVar1 * 0x2a + iVar2 * 6] = (&DAT_00422594)[iVar1 * 0x2a + iVar2 * 6];
        (&DAT_00421f08)[iVar1 * 0x2a + iVar2 * 6] = (&DAT_00422598)[iVar1 * 0x2a + iVar2 * 6];
        (&DAT_00421f0c)[iVar1 * 0x2a + iVar2 * 6] = (&DAT_0042259c)[iVar1 * 0x2a + iVar2 * 6];
        (&DAT_00421f10)[iVar1 * 0x2a + iVar2 * 6] = (&DAT_004225a0)[iVar1 * 0x2a + iVar2 * 6];
        (&DAT_00421f14)[iVar1 * 0x2a + iVar2 * 6] = (&DAT_004225a4)[iVar1 * 0x2a + iVar2 * 6];
        (&DAT_00421f18)[iVar1 * 0x2a + iVar2 * 6] = (&DAT_004225a8)[iVar1 * 0x2a + iVar2 * 6];
        iVar1 = iVar1 + 1;
      } while (iVar1 < 10);
      iVar2 = iVar2 + 1;
    } while (iVar2 < 7);
    DAT_00421ee0 = DAT_00421ee0 - DAT_00422d3c;
    DAT_00422d3c = 0;
    DAT_0042012c = 0;
    DAT_00420120 = 1;
    Create_Screen();
  }
  return;
}



void Check_Bubbles_Clicked(byte param_1,byte param_2,byte param_3,byte param_4,byte param_5)

{
  double dVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 unaff_EDI;
  undefined3 in_stack_00000005;
  undefined3 in_stack_00000009;
  
  dVar1 = (double)((_param_4 + -8) / 0x30);
  _floor(SUB84(dVar1,0),(double)CONCAT44(unaff_EDI,(int)((ulonglong)dVar1 >> 0x20)));
  iVar3 = __ftol();
  dVar1 = (double)((_param_5 + -8) / 0x30);
  _floor(SUB84(dVar1,0),(double)CONCAT44(unaff_EDI,(int)((ulonglong)dVar1 >> 0x20)));
  iVar4 = __ftol();
  if ((DAT_0042011c == 0) || ((&DAT_00421f18)[iVar3 * 0x2a + iVar4 * 6] == 0)) {
    iVar6 = 0;
    do {
      iVar5 = 0;
      do {
        iVar2 = iVar6 * 3;
        (&DAT_00421f18)[iVar5 * 0x2a + iVar6 * 6] = 0;
        iVar5 = iVar5 + 1;
      } while (iVar5 < 10);
      iVar6 = iVar6 + 1;
    } while (iVar6 < 7);
    if (DAT_0042011c == 0) {
      iVar6 = iVar4 * 3;
      Check_Bubble(iVar6,(int)(&DAT_00421f04 + iVar3 * 0x2a),iVar2,iVar3,iVar4,
                   (&DAT_00421f04 + iVar3 * 0x2a)[iVar4 * 6]);
      if (1 < iVar6) {
        DAT_0042011c = 1;
        DAT_00421eac = (iVar6 + -1) * iVar6;
        DAT_00420130 = iVar6;
      }
    }
    else {
      DAT_0042011c = 0;
      DAT_00420130 = 0;
      DAT_00421eac = 0;
    }
    Create_Screen();
  }
  else {
    Update_Bubbles();
    DAT_0042012c = 1;
  }
  return;
}



void check_all_bubbles_moved(void)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  do {
    iVar1 = 0;
    do {
      if ((&DAT_00421f08)[iVar1 * 0x2a + iVar2 * 6] != 0xffff ||
          (&DAT_00421f0c)[iVar1 * 0x2a + iVar2 * 6] != 0xffff) {
        return;
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 < 10);
    iVar2 = iVar2 + 1;
  } while (iVar2 < 7);
  return;
}



// fptc parameter of timeSetEvent
// 

void fptc_004133ba(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar2 = 0;
  do {
    iVar1 = 0;
    do {
      iVar3 = iVar1 * 0x30 + 8;
      iVar4 = iVar2 * 0x30 + 8;
      if (iVar3 == (&DAT_00421f08)[iVar1 * 0x2a + iVar2 * 6]) {
        (&DAT_00421f08)[iVar1 * 0x2a + iVar2 * 6] = 0xffff;
      }
      if ((&DAT_00421f0c)[iVar1 * 0x2a + iVar2 * 6] == iVar4) {
        (&DAT_00421f0c)[iVar1 * 0x2a + iVar2 * 6] = 0xffff;
      }
      if ((&DAT_00421f08)[iVar1 * 0x2a + iVar2 * 6] != 0xffff) {
        if ((int)(&DAT_00421f08)[iVar1 * 0x2a + iVar2 * 6] < iVar3) {
          (&DAT_00421f08)[iVar1 * 0x2a + iVar2 * 6] = (&DAT_00421f08)[iVar1 * 0x2a + iVar2 * 6] + 8;
        }
        else {
          (&DAT_00421f08)[iVar1 * 0x2a + iVar2 * 6] = (&DAT_00421f08)[iVar1 * 0x2a + iVar2 * 6] + -8
          ;
        }
      }
      if ((&DAT_00421f0c)[iVar1 * 0x2a + iVar2 * 6] != 0xffff) {
        if ((int)(&DAT_00421f0c)[iVar1 * 0x2a + iVar2 * 6] < iVar4) {
          (&DAT_00421f0c)[iVar1 * 0x2a + iVar2 * 6] = (&DAT_00421f0c)[iVar1 * 0x2a + iVar2 * 6] + 8;
        }
        else {
          (&DAT_00421f0c)[iVar1 * 0x2a + iVar2 * 6] = (&DAT_00421f0c)[iVar1 * 0x2a + iVar2 * 6] + -8
          ;
        }
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 < 10);
    iVar2 = iVar2 + 1;
  } while (iVar2 < 7);
  check_all_bubbles_moved();
  if ((iVar1 != 0) && (DAT_00420120 = 0, DAT_00420124 != 0)) {
    PostMessageA(hWnd_00421e58,999,0,0);
    DAT_00420124 = 0;
  }
  if (DAT_00420120 != 0) {
    Create_Screen();
  }
  return;
}



void Reset_Scores(void)

{
  int iVar1;
  
  iVar1 = MessageBoxA((HWND)0x0,s_Are_you_sure__0042088f,s_Reset_0042089d,0x11001);
  if (iVar1 == 1) {
    _Str_00421eb0 = (void *)0x0;
    DAT_00421eb4 = 0;
    DAT_00421eb8 = 0;
    DAT_00421ebc = 0;
    DAT_00421ec0 = 0;
    DAT_00421ec4 = 0;
    DAT_00421ec8 = 0;
    DAT_00421ecc = 0;
    DAT_00421ed0 = 0;
    DAT_00421ed4 = 0;
    DAT_00421ed8 = 0;
    DAT_00421edc = 0;
  }
  Create_Screen();
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void Execute_Button(int param_1,int param_2,int param_3,int param_4)

{
  int unaff_EBP;
  
  switch(param_4) {
  case 1:
    PostMessageA(hWnd_00421e58,0x10,0,0);
    return;
  case 2:
    change_mode(param_4,param_2,param_3,3,unaff_EBP);
    DAT_00420114 = DAT_00420110;
    return;
  case 3:
    change_mode(param_4,param_2,param_3,4,unaff_EBP);
    return;
  case 4:
    change_mode(param_4,param_2,param_3,5,unaff_EBP);
    return;
  case 5:
    change_mode(param_4,param_2,param_3,2,unaff_EBP);
    return;
  case 6:
    if (DAT_00420134 == 0) {
      _Str_00421eb0 = (void *)((int)_Str_00421eb0 + 1);
    }
    if (DAT_00420134 == 1) {
      DAT_00421ebc = DAT_00421ebc + 1;
    }
    if (DAT_00420134 == 2) {
      DAT_00421ec8 = DAT_00421ec8 + 1;
    }
    if (DAT_00420134 == 3) {
      DAT_00421ed4 = DAT_00421ed4 + 1;
    }
    DAT_00420128 = 0;
    change_mode(0,param_2,param_3,9,unaff_EBP);
    return;
  case 7:
    change_mode(param_4,param_2,param_3,0x100,unaff_EBP);
    return;
  case 8:
    change_mode(param_4,param_2,param_3,0x100,unaff_EBP);
    return;
  case 9:
    change_mode(param_4,param_2,param_3,0x100,unaff_EBP);
    _DAT_00420138 = 0;
    return;
  case 10:
    Reset_Scores();
    return;
  case 0xb:
    change_mode(param_4,param_2,param_3,0,unaff_EBP);
    return;
  case 0xc:
    change_mode(param_4,param_2,param_3,2,unaff_EBP);
    return;
  case 0xd:
    change_mode(param_4,param_2,param_3,7,unaff_EBP);
    return;
  case 0xe:
    change_mode(param_4,param_2,param_3,6,unaff_EBP);
    return;
  case 0xf:
    change_mode(param_4,param_2,param_3,3,unaff_EBP);
    DAT_00420110 = DAT_00420114;
    return;
  case 0x10:
    change_mode(param_4,param_2,param_3,0x100,unaff_EBP);
  }
  return;
}



void Check_Button_Down(undefined param_1,undefined param_2,undefined param_3,uint param_4,
                      uint param_5)

{
  undefined3 in_register_00000001;
  uint uVar1;
  uint uVar2;
  byte extraout_CL;
  undefined3 in_register_00000005;
  uint extraout_ECX;
  undefined3 in_register_00000009;
  uint uVar3;
  uint extraout_EDX;
  uint extraout_EDX_00;
  uint uVar4;
  
  uVar3 = CONCAT31(in_register_00000009,param_2);
  uVar2 = CONCAT31(in_register_00000005,param_3);
  uVar1 = CONCAT31(in_register_00000001,param_1);
  for (uVar4 = 1; (int)uVar4 <= DAT_0042013c; uVar4 = uVar4 + 1) {
    uVar1 = Check_In_Box(uVar4 * 0x20,uVar3,uVar2,(&DAT_00422d40)[uVar4 * 8],
                         (&DAT_00422d44)[uVar4 * 8],(&DAT_00422d48)[uVar4 * 8],
                         (&DAT_00422d4c)[uVar4 * 8],param_4,param_5);
    uVar2 = extraout_ECX;
    uVar3 = extraout_EDX;
    if (uVar1 != 0) {
      uVar3 = (uint)(*(int *)(&DAT_00422d5c + uVar4 * 0x20) == 0xff);
      uVar1 = (uint)(*(int *)(&DAT_00422d5c + uVar4 * 0x20) == DAT_0042010c ||
                    *(int *)(&DAT_00422d5c + uVar4 * 0x20) == 0xff);
      if (uVar1 != 0) {
        uVar3 = (uint)(4 < (int)uVar4);
        uVar1 = (uint)(DAT_00420118 == 0 || 4 < (int)uVar4);
        if (uVar1 != 0) {
          uVar1 = uVar4 * 0x20;
          DAT_00420140 = uVar4;
          (&DAT_00422d58)[uVar4 * 8] = 1;
          uVar2 = uVar4;
          Update_Button(uVar1,uVar3,extraout_ECX,uVar4);
          uVar3 = extraout_EDX_00;
        }
      }
    }
  }
  uVar2 = Check_In_Box(uVar1,uVar3,uVar2,7,7,0x1e6,0x156,param_4,param_5);
  uVar2 = uVar2 & DAT_0042010c == 2;
  if ((uVar2 != 0) && (DAT_00420120 == 0)) {
    Check_Bubbles_Clicked((byte)uVar2,DAT_0042010c == 2,extraout_CL,(byte)param_4,(byte)param_5);
  }
  return;
}



void Check_Button_Up(undefined param_1,undefined param_2,undefined param_3,uint param_4,uint param_5
                    )

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined3 in_register_00000005;
  uint extraout_ECX;
  uint extraout_ECX_00;
  uint extraout_ECX_01;
  uint extraout_ECX_02;
  uint extraout_ECX_03;
  uint extraout_ECX_04;
  uint extraout_ECX_05;
  uint extraout_ECX_06;
  uint extraout_ECX_07;
  uint extraout_ECX_08;
  uint extraout_ECX_09;
  undefined3 in_register_00000009;
  uint extraout_EDX;
  uint uVar4;
  int extraout_EDX_00;
  uint extraout_EDX_01;
  uint extraout_EDX_02;
  uint extraout_EDX_03;
  uint extraout_EDX_04;
  uint extraout_EDX_05;
  uint extraout_EDX_06;
  uint extraout_EDX_07;
  uint extraout_EDX_08;
  uint extraout_EDX_09;
  uint extraout_EDX_10;
  uint extraout_EDX_11;
  
  uVar1 = Check_In_Box(DAT_00420140 * 0x20,CONCAT31(in_register_00000009,param_2),
                       CONCAT31(in_register_00000005,param_3),(&DAT_00422d40)[DAT_00420140 * 8],
                       (&DAT_00422d44)[DAT_00420140 * 8],(&DAT_00422d48)[DAT_00420140 * 8],
                       (&DAT_00422d4c)[DAT_00420140 * 8],param_4,param_5);
  uVar3 = extraout_ECX;
  uVar4 = extraout_EDX;
  if (((uVar1 != 0) &&
      (uVar4 = (uint)(*(int *)(&DAT_00422d5c + DAT_00420140 * 0x20) == 0xff),
      *(int *)(&DAT_00422d5c + DAT_00420140 * 0x20) == DAT_0042010c ||
      *(int *)(&DAT_00422d5c + DAT_00420140 * 0x20) == 0xff)) &&
     (uVar4 = (uint)(4 < (int)DAT_00420140), DAT_00420118 == 0 || 4 < (int)DAT_00420140)) {
    iVar2 = DAT_00420140 * 0x20;
    (&DAT_00422d58)[DAT_00420140 * 8] = 0;
    uVar4 = DAT_00420140;
    Update_Button(iVar2,0,extraout_ECX,DAT_00420140);
    uVar3 = DAT_00420140;
    Execute_Button(iVar2,extraout_EDX_00,uVar4,DAT_00420140);
    uVar4 = extraout_EDX_01;
  }
  DAT_00420140 = 0;
  if (DAT_0042010c == 4) {
    uVar1 = Check_In_Box(0,uVar4,uVar3,0x61,0x65,0xd2,0x78,param_4,param_5);
    uVar3 = extraout_ECX_00;
    uVar4 = extraout_EDX_02;
    if (uVar1 != 0) {
      _Str_00421ee8 = (void *)0x0;
      uVar1 = Create_Screen();
      uVar3 = extraout_ECX_01;
      uVar4 = extraout_EDX_03;
    }
    uVar1 = Check_In_Box(uVar1,uVar4,uVar3,0x61,0x84,0xe5,0x97,param_4,param_5);
    uVar3 = extraout_ECX_02;
    uVar4 = extraout_EDX_04;
    if (uVar1 != 0) {
      _Str_00421ee8 = (void *)0x1;
      uVar1 = Create_Screen();
      uVar3 = extraout_ECX_03;
      uVar4 = extraout_EDX_05;
    }
    uVar1 = Check_In_Box(uVar1,uVar4,uVar3,0x61,0xa3,0xbd,0xb6,param_4,param_5);
    uVar3 = extraout_ECX_04;
    uVar4 = extraout_EDX_06;
    if (uVar1 != 0) {
      _Str_00421ee8 = (void *)0x2;
      uVar1 = Create_Screen();
      uVar3 = extraout_ECX_05;
      uVar4 = extraout_EDX_07;
    }
    uVar1 = Check_In_Box(uVar1,uVar4,uVar3,0x61,0xc2,0xdb,0xd9,param_4,param_5);
    uVar3 = extraout_ECX_06;
    uVar4 = extraout_EDX_08;
    if (uVar1 != 0) {
      _Str_00421ee8 = (void *)0x3;
      uVar1 = Create_Screen();
      uVar3 = extraout_ECX_07;
      uVar4 = extraout_EDX_09;
    }
    uVar1 = Check_In_Box(uVar1,uVar4,uVar3,0x115,0x51,0x1a0,0x65,param_4,param_5);
    uVar3 = extraout_ECX_08;
    uVar4 = extraout_EDX_10;
    if (uVar1 != 0) {
      DAT_00421eec = (uint)(DAT_00421eec == 0);
      uVar1 = Create_Screen();
      uVar3 = extraout_ECX_09;
      uVar4 = extraout_EDX_11;
    }
    uVar3 = Check_In_Box(uVar1,uVar4,uVar3,0x116,0x7c,0x196,0x8f,param_4,param_5);
    if (uVar3 != 0) {
      DAT_00421ef0 = (uint)(DAT_00421ef0 == 0);
      Create_Screen();
    }
  }
  return;
}



void Check_Button_Move(undefined param_1,undefined param_2,undefined param_3,uint param_4,
                      uint param_5,int param_6)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined3 in_register_00000005;
  uint uVar4;
  uint extraout_ECX;
  int extraout_ECX_00;
  uint extraout_EDX;
  uint extraout_EDX_00;
  uint extraout_EDX_01;
  
  uVar4 = CONCAT31(in_register_00000005,param_3);
  uVar3 = (uint)(DAT_00420140 != 0);
  if (param_6 != 1 && DAT_00420140 != 0) {
    iVar1 = DAT_00420140 * 0x20;
    (&DAT_00422d58)[DAT_00420140 * 8] = 0;
    Update_Button(iVar1,0,uVar4,DAT_00420140);
    uVar4 = DAT_00420140;
    DAT_00420140 = 0;
    uVar3 = extraout_EDX;
  }
  if (DAT_00420140 != 0) {
    uVar2 = Check_In_Box(DAT_00420140 * 0x20,uVar3,uVar4,(&DAT_00422d40)[DAT_00420140 * 8],
                         (&DAT_00422d44)[DAT_00420140 * 8],(&DAT_00422d48)[DAT_00420140 * 8],
                         (&DAT_00422d4c)[DAT_00420140 * 8],param_4,param_5);
    uVar3 = extraout_ECX;
    uVar4 = extraout_EDX_00;
    if (uVar2 != 0) {
      iVar1 = DAT_00420140 * 0x20;
      (&DAT_00422d58)[DAT_00420140 * 8] = 1;
      uVar3 = DAT_00420140;
      Update_Button(iVar1,extraout_EDX_00,extraout_ECX,DAT_00420140);
      uVar4 = extraout_EDX_01;
    }
    uVar3 = Check_In_Box(DAT_00420140 * 0x20,uVar4,uVar3,(&DAT_00422d40)[DAT_00420140 * 8],
                         (&DAT_00422d44)[DAT_00420140 * 8],(&DAT_00422d48)[DAT_00420140 * 8],
                         (&DAT_00422d4c)[DAT_00420140 * 8],param_4,param_5);
    if (uVar3 == 0) {
      iVar1 = DAT_00420140 * 0x20;
      (&DAT_00422d58)[DAT_00420140 * 8] = 0;
      Update_Button(iVar1,0,extraout_ECX_00,DAT_00420140);
    }
  }
  return;
}



void Game_Init(void)

{
  undefined uVar1;
  time_t *_Seed;
  int iVar2;
  undefined4 uVar3;
  undefined extraout_CL;
  undefined extraout_CL_00;
  undefined extraout_CL_01;
  undefined extraout_CL_02;
  undefined extraout_CL_03;
  undefined extraout_CL_04;
  undefined extraout_CL_05;
  undefined extraout_CL_06;
  undefined extraout_CL_07;
  undefined extraout_CL_08;
  undefined extraout_CL_09;
  undefined extraout_CL_10;
  undefined extraout_CL_11;
  undefined extraout_CL_12;
  undefined extraout_CL_13;
  undefined extraout_CL_14;
  undefined extraout_CL_15;
  undefined extraout_CL_16;
  undefined extraout_CL_17;
  undefined extraout_CL_18;
  undefined extraout_CL_19;
  undefined extraout_CL_20;
  undefined extraout_CL_21;
  HDC extraout_ECX;
  undefined extraout_DL;
  undefined extraout_DL_00;
  undefined extraout_DL_01;
  undefined extraout_DL_02;
  undefined extraout_DL_03;
  undefined extraout_DL_04;
  undefined extraout_DL_05;
  undefined extraout_DL_06;
  undefined extraout_DL_07;
  undefined extraout_DL_08;
  undefined extraout_DL_09;
  undefined extraout_DL_10;
  undefined extraout_DL_11;
  undefined extraout_DL_12;
  undefined extraout_DL_13;
  undefined extraout_DL_14;
  undefined extraout_DL_15;
  undefined extraout_DL_16;
  undefined extraout_DL_17;
  undefined extraout_DL_18;
  undefined extraout_DL_19;
  undefined extraout_DL_20;
  undefined extraout_DL_21;
  undefined extraout_DL_22;
  undefined extraout_DL_23;
  undefined extraout_DL_24;
  undefined extraout_DL_25;
  undefined extraout_DL_26;
  undefined extraout_DL_27;
  undefined extraout_DL_28;
  undefined extraout_DL_29;
  undefined extraout_DL_30;
  undefined extraout_DL_31;
  undefined extraout_DL_32;
  undefined extraout_DL_33;
  undefined extraout_DL_34;
  undefined extraout_DL_35;
  undefined extraout_DL_36;
  undefined extraout_DL_37;
  undefined extraout_DL_38;
  undefined extraout_DL_39;
  undefined4 extraout_EDX;
  time_t *unaff_EDI;
  undefined uVar4;
  time_t *ptVar5;
  FILE *pFVar6;
  CHAR *pCVar7;
  CHAR local_104 [256];
  
  _Seed = _time((time_t *)0x0,unaff_EDI);
  ptVar5 = _Seed;
  _srand((uint)_Seed);
  FillSurface((char)_Seed,extraout_DL,(char)ptVar5,DAT_00421e4c,0,0,0x1ed,0x1a3,0);
  uVar1 = ShowTextCenter(s_Loading_Bubblet____004208a3,extraout_EDX,extraout_ECX,DAT_00421e4c,0xf5,
                         0xc3,s_Loading_Bubblet____004208a3,0xffffff);
  PutSurfacePrimary(uVar1,extraout_DL_00,extraout_CL,0,0,DAT_00421e4c);
  DAT_00421ef4 = 7;
  DAT_00421ef8 = 7;
  DAT_00421efc = 0x1e6;
  DAT_00421f00 = 0x156;
  _File_00421e64 = _fopen(s_bubblet_cfg_004208b6,&DAT_004208c2);
  _fread(&_Str_00421ee8,0xc,1,_File_00421e64);
  _fread(&_Str_00421eb0,0x30,1,_File_00421e64);
  pFVar6 = _File_00421e64;
  iVar2 = _fclose(_File_00421e64);
  uVar1 = 0x81;
  DAT_00421e90 = LoadSurface((char)iVar2,extraout_DL_01,(char)pFVar6,0x81);
  uVar4 = 0x82;
  DAT_00421e94 = LoadSurface((char)DAT_00421e90,extraout_DL_02,uVar1,0x82);
  uVar1 = 0x83;
  DAT_00421e98 = LoadSurface((char)DAT_00421e94,extraout_DL_03,uVar4,0x83);
  uVar4 = 0x84;
  DAT_00421e9c = LoadSurface((char)DAT_00421e98,extraout_DL_04,uVar1,0x84);
  uVar1 = 0x85;
  DAT_00421ea0 = LoadSurface((char)DAT_00421e9c,extraout_DL_05,uVar4,0x85);
  uVar1 = SetColorKey((char)DAT_00421ea0,extraout_DL_06,uVar1,DAT_00421e90,0);
  uVar1 = SetColorKey(uVar1,extraout_DL_07,extraout_CL_00,DAT_00421e94,0);
  uVar1 = SetColorKey(uVar1,extraout_DL_08,extraout_CL_01,DAT_00421e98,0);
  uVar1 = SetColorKey(uVar1,extraout_DL_09,extraout_CL_02,DAT_00421e9c,0);
  uVar1 = SetColorKey(uVar1,extraout_DL_10,extraout_CL_03,DAT_00421ea0,0);
  uVar4 = 100;
  DAT_00421e88 = LoadSurface(uVar1,extraout_DL_11,extraout_CL_04,100);
  uVar1 = 0x65;
  DAT_00421e74 = LoadSurface((char)DAT_00421e88,extraout_DL_12,uVar4,0x65);
  uVar1 = SetColorKey((char)DAT_00421e74,extraout_DL_13,uVar1,DAT_00421e74,0);
  uVar4 = 0x66;
  DAT_00421e70 = LoadSurface(uVar1,extraout_DL_14,extraout_CL_05,0x66);
  uVar1 = SetColorKey((char)DAT_00421e70,extraout_DL_15,uVar4,DAT_00421e70,0);
  uVar4 = 0x68;
  DAT_00421e78 = LoadSurface(uVar1,extraout_DL_16,extraout_CL_06,0x68);
  uVar1 = SetColorKey((char)DAT_00421e78,extraout_DL_17,uVar4,DAT_00421e78,0xffffff);
  uVar4 = 0x69;
  DAT_00421e7c = LoadSurface(uVar1,extraout_DL_18,extraout_CL_07,0x69);
  uVar1 = SetColorKey((char)DAT_00421e7c,extraout_DL_19,uVar4,DAT_00421e7c,0xffffff);
  uVar4 = 0x6a;
  DAT_00421e80 = LoadSurface(uVar1,extraout_DL_20,extraout_CL_08,0x6a);
  uVar1 = SetColorKey((char)DAT_00421e80,extraout_DL_21,uVar4,DAT_00421e80,0xffffff);
  uVar4 = 0x6b;
  DAT_00421e84 = LoadSurface(uVar1,extraout_DL_22,extraout_CL_09,0x6b);
  uVar1 = SetColorKey((char)DAT_00421e84,extraout_DL_23,uVar4,DAT_00421e84,0xffffff);
  uVar4 = 0x67;
  DAT_00421e6c = LoadSurface(uVar1,extraout_DL_24,extraout_CL_10,0x67);
  uVar1 = SetColorKey((char)DAT_00421e6c,extraout_DL_25,uVar4,DAT_00421e6c,0);
  uVar4 = 0x80;
  DAT_00421e8c = LoadSurface(uVar1,extraout_DL_26,extraout_CL_11,0x80);
  uVar1 = SetColorKey((char)DAT_00421e8c,extraout_DL_27,uVar4,DAT_00421e8c,0xffffff);
  DAT_0042013c = DAT_0042013c + 1;
  uVar4 = 0x6c;
  uVar3 = LoadSurface(uVar1,extraout_DL_28,extraout_CL_12,0x6c);
  iVar2 = DAT_0042013c * 0x20;
  *(undefined4 *)(&DAT_00422d50 + iVar2) = uVar3;
  uVar1 = 0x6d;
  uVar3 = LoadSurface((char)uVar3,(char)iVar2,uVar4,0x6d);
  *(undefined4 *)(&DAT_00422d54 + DAT_0042013c * 0x20) = uVar3;
  (&DAT_00422d40)[DAT_0042013c * 8] = 6;
  (&DAT_00422d44)[DAT_0042013c * 8] = 0x178;
  (&DAT_00422d48)[DAT_0042013c * 8] = (&DAT_00422d40)[DAT_0042013c * 8] + 0x3e;
  (&DAT_00422d4c)[DAT_0042013c * 8] = (&DAT_00422d44)[DAT_0042013c * 8] + 0x26;
  (&DAT_00422d58)[DAT_0042013c * 8] = 0;
  iVar2 = DAT_0042013c * 0x20;
  *(undefined4 *)(&DAT_00422d5c + iVar2) = 0xff;
  DAT_0042013c = DAT_0042013c + 1;
  uVar4 = 0x6e;
  uVar3 = LoadSurface((char)iVar2,0,uVar1,0x6e);
  iVar2 = DAT_0042013c * 0x20;
  *(undefined4 *)(&DAT_00422d50 + iVar2) = uVar3;
  uVar1 = 0x6f;
  uVar3 = LoadSurface((char)uVar3,(char)iVar2,uVar4,0x6f);
  *(undefined4 *)(&DAT_00422d54 + DAT_0042013c * 0x20) = uVar3;
  (&DAT_00422d40)[DAT_0042013c * 8] = 0x4a;
  (&DAT_00422d44)[DAT_0042013c * 8] = 0x178;
  (&DAT_00422d48)[DAT_0042013c * 8] = (&DAT_00422d40)[DAT_0042013c * 8] + 0x3e;
  (&DAT_00422d4c)[DAT_0042013c * 8] = (&DAT_00422d44)[DAT_0042013c * 8] + 0x26;
  (&DAT_00422d58)[DAT_0042013c * 8] = 0;
  iVar2 = DAT_0042013c * 0x20;
  *(undefined4 *)(&DAT_00422d5c + iVar2) = 0xff;
  DAT_0042013c = DAT_0042013c + 1;
  uVar4 = 0x70;
  uVar3 = LoadSurface((char)iVar2,0,uVar1,0x70);
  iVar2 = DAT_0042013c * 0x20;
  *(undefined4 *)(&DAT_00422d50 + iVar2) = uVar3;
  uVar1 = 0x71;
  uVar3 = LoadSurface((char)uVar3,(char)iVar2,uVar4,0x71);
  *(undefined4 *)(&DAT_00422d54 + DAT_0042013c * 0x20) = uVar3;
  (&DAT_00422d40)[DAT_0042013c * 8] = 0x8e;
  (&DAT_00422d44)[DAT_0042013c * 8] = 0x178;
  (&DAT_00422d48)[DAT_0042013c * 8] = (&DAT_00422d40)[DAT_0042013c * 8] + 0x3e;
  (&DAT_00422d4c)[DAT_0042013c * 8] = (&DAT_00422d44)[DAT_0042013c * 8] + 0x26;
  (&DAT_00422d58)[DAT_0042013c * 8] = 0;
  iVar2 = DAT_0042013c * 0x20;
  *(undefined4 *)(&DAT_00422d5c + iVar2) = 0xff;
  DAT_0042013c = DAT_0042013c + 1;
  uVar4 = 0x72;
  uVar3 = LoadSurface((char)iVar2,0,uVar1,0x72);
  iVar2 = DAT_0042013c * 0x20;
  *(undefined4 *)(&DAT_00422d50 + iVar2) = uVar3;
  uVar1 = 0x73;
  uVar3 = LoadSurface((char)uVar3,(char)iVar2,uVar4,0x73);
  *(undefined4 *)(&DAT_00422d54 + DAT_0042013c * 0x20) = uVar3;
  (&DAT_00422d40)[DAT_0042013c * 8] = 0xd2;
  (&DAT_00422d44)[DAT_0042013c * 8] = 0x178;
  (&DAT_00422d48)[DAT_0042013c * 8] = (&DAT_00422d40)[DAT_0042013c * 8] + 0x3e;
  (&DAT_00422d4c)[DAT_0042013c * 8] = (&DAT_00422d44)[DAT_0042013c * 8] + 0x26;
  (&DAT_00422d58)[DAT_0042013c * 8] = 0;
  iVar2 = DAT_0042013c * 0x20;
  *(undefined4 *)(&DAT_00422d5c + iVar2) = 0xff;
  DAT_0042013c = DAT_0042013c + 1;
  uVar4 = 0x74;
  uVar3 = LoadSurface((char)iVar2,0,uVar1,0x74);
  iVar2 = DAT_0042013c * 0x20;
  *(undefined4 *)(&DAT_00422d50 + iVar2) = uVar3;
  uVar1 = 0x75;
  uVar3 = LoadSurface((char)uVar3,(char)iVar2,uVar4,0x75);
  *(undefined4 *)(&DAT_00422d54 + DAT_0042013c * 0x20) = uVar3;
  (&DAT_00422d40)[DAT_0042013c * 8] = 0x116;
  (&DAT_00422d44)[DAT_0042013c * 8] = 0x178;
  (&DAT_00422d48)[DAT_0042013c * 8] = (&DAT_00422d40)[DAT_0042013c * 8] + 0x3e;
  (&DAT_00422d4c)[DAT_0042013c * 8] = (&DAT_00422d44)[DAT_0042013c * 8] + 0x26;
  (&DAT_00422d58)[DAT_0042013c * 8] = 0;
  iVar2 = DAT_0042013c * 0x20;
  *(undefined4 *)(&DAT_00422d5c + iVar2) = 0;
  DAT_0042013c = DAT_0042013c + 1;
  uVar4 = 0x76;
  uVar3 = LoadSurface((char)iVar2,0,uVar1,0x76);
  iVar2 = DAT_0042013c * 0x20;
  *(undefined4 *)(&DAT_00422d50 + iVar2) = uVar3;
  uVar1 = 0x77;
  uVar3 = LoadSurface((char)uVar3,(char)iVar2,uVar4,0x77);
  *(undefined4 *)(&DAT_00422d54 + DAT_0042013c * 0x20) = uVar3;
  (&DAT_00422d40)[DAT_0042013c * 8] = 0x116;
  (&DAT_00422d44)[DAT_0042013c * 8] = 0x178;
  (&DAT_00422d48)[DAT_0042013c * 8] = (&DAT_00422d40)[DAT_0042013c * 8] + 0x3e;
  (&DAT_00422d4c)[DAT_0042013c * 8] = (&DAT_00422d44)[DAT_0042013c * 8] + 0x26;
  (&DAT_00422d58)[DAT_0042013c * 8] = 0;
  iVar2 = DAT_0042013c * 0x20;
  *(undefined4 *)(&DAT_00422d5c + iVar2) = 2;
  DAT_0042013c = DAT_0042013c + 1;
  uVar4 = 0x78;
  uVar3 = LoadSurface((char)iVar2,0,uVar1,0x78);
  iVar2 = DAT_0042013c * 0x20;
  *(undefined4 *)(&DAT_00422d50 + iVar2) = uVar3;
  uVar1 = 0x79;
  uVar3 = LoadSurface((char)uVar3,(char)iVar2,uVar4,0x79);
  *(undefined4 *)(&DAT_00422d54 + DAT_0042013c * 0x20) = uVar3;
  (&DAT_00422d40)[DAT_0042013c * 8] = 0xd7;
  (&DAT_00422d44)[DAT_0042013c * 8] = 0x115;
  (&DAT_00422d48)[DAT_0042013c * 8] = (&DAT_00422d40)[DAT_0042013c * 8] + 0x3e;
  (&DAT_00422d4c)[DAT_0042013c * 8] = (&DAT_00422d44)[DAT_0042013c * 8] + 0x26;
  (&DAT_00422d58)[DAT_0042013c * 8] = 0;
  iVar2 = DAT_0042013c * 0x20;
  *(undefined4 *)(&DAT_00422d5c + iVar2) = 4;
  DAT_0042013c = DAT_0042013c + 1;
  uVar4 = 0x78;
  uVar3 = LoadSurface((char)iVar2,0,uVar1,0x78);
  iVar2 = DAT_0042013c * 0x20;
  *(undefined4 *)(&DAT_00422d50 + iVar2) = uVar3;
  uVar1 = 0x79;
  uVar3 = LoadSurface((char)uVar3,(char)iVar2,uVar4,0x79);
  *(undefined4 *)(&DAT_00422d54 + DAT_0042013c * 0x20) = uVar3;
  (&DAT_00422d40)[DAT_0042013c * 8] = 0xaa;
  (&DAT_00422d44)[DAT_0042013c * 8] = 0x115;
  (&DAT_00422d48)[DAT_0042013c * 8] = (&DAT_00422d40)[DAT_0042013c * 8] + 0x3e;
  (&DAT_00422d4c)[DAT_0042013c * 8] = (&DAT_00422d44)[DAT_0042013c * 8] + 0x26;
  (&DAT_00422d58)[DAT_0042013c * 8] = 0;
  iVar2 = DAT_0042013c * 0x20;
  *(undefined4 *)(&DAT_00422d5c + iVar2) = 3;
  DAT_0042013c = DAT_0042013c + 1;
  uVar4 = 0x78;
  uVar3 = LoadSurface((char)iVar2,0,uVar1,0x78);
  iVar2 = DAT_0042013c * 0x20;
  *(undefined4 *)(&DAT_00422d50 + iVar2) = uVar3;
  uVar1 = 0x79;
  uVar3 = LoadSurface((char)uVar3,(char)iVar2,uVar4,0x79);
  *(undefined4 *)(&DAT_00422d54 + DAT_0042013c * 0x20) = uVar3;
  (&DAT_00422d40)[DAT_0042013c * 8] = 0xb4;
  (&DAT_00422d44)[DAT_0042013c * 8] = 0x115;
  (&DAT_00422d48)[DAT_0042013c * 8] = (&DAT_00422d40)[DAT_0042013c * 8] + 0x3e;
  (&DAT_00422d4c)[DAT_0042013c * 8] = (&DAT_00422d44)[DAT_0042013c * 8] + 0x26;
  (&DAT_00422d58)[DAT_0042013c * 8] = 0;
  iVar2 = DAT_0042013c * 0x20;
  *(undefined4 *)(&DAT_00422d5c + iVar2) = 5;
  DAT_0042013c = DAT_0042013c + 1;
  uVar4 = 0x7c;
  uVar3 = LoadSurface((char)iVar2,0,uVar1,0x7c);
  iVar2 = DAT_0042013c * 0x20;
  *(undefined4 *)(&DAT_00422d50 + iVar2) = uVar3;
  uVar1 = 0x7d;
  uVar3 = LoadSurface((char)uVar3,(char)iVar2,uVar4,0x7d);
  *(undefined4 *)(&DAT_00422d54 + DAT_0042013c * 0x20) = uVar3;
  (&DAT_00422d40)[DAT_0042013c * 8] = 0xfa;
  (&DAT_00422d44)[DAT_0042013c * 8] = 0x115;
  (&DAT_00422d48)[DAT_0042013c * 8] = (&DAT_00422d40)[DAT_0042013c * 8] + 0x3e;
  (&DAT_00422d4c)[DAT_0042013c * 8] = (&DAT_00422d44)[DAT_0042013c * 8] + 0x26;
  (&DAT_00422d58)[DAT_0042013c * 8] = 0;
  iVar2 = DAT_0042013c * 0x20;
  *(undefined4 *)(&DAT_00422d5c + iVar2) = 5;
  DAT_0042013c = DAT_0042013c + 1;
  uVar4 = 0x7a;
  uVar3 = LoadSurface((char)iVar2,0,uVar1,0x7a);
  iVar2 = DAT_0042013c * 0x20;
  *(undefined4 *)(&DAT_00422d50 + iVar2) = uVar3;
  uVar1 = 0x7b;
  uVar3 = LoadSurface((char)uVar3,(char)iVar2,uVar4,0x7b);
  *(undefined4 *)(&DAT_00422d54 + DAT_0042013c * 0x20) = uVar3;
  (&DAT_00422d40)[DAT_0042013c * 8] = 0xb4;
  (&DAT_00422d44)[DAT_0042013c * 8] = 0x115;
  (&DAT_00422d48)[DAT_0042013c * 8] = (&DAT_00422d40)[DAT_0042013c * 8] + 0x3e;
  (&DAT_00422d4c)[DAT_0042013c * 8] = (&DAT_00422d44)[DAT_0042013c * 8] + 0x26;
  (&DAT_00422d58)[DAT_0042013c * 8] = 0;
  iVar2 = DAT_0042013c * 0x20;
  *(undefined4 *)(&DAT_00422d5c + iVar2) = 9;
  DAT_0042013c = DAT_0042013c + 1;
  uVar4 = 0x74;
  uVar3 = LoadSurface((char)iVar2,0,uVar1,0x74);
  iVar2 = DAT_0042013c * 0x20;
  *(undefined4 *)(&DAT_00422d50 + iVar2) = uVar3;
  uVar1 = 0x75;
  uVar3 = LoadSurface((char)uVar3,(char)iVar2,uVar4,0x75);
  *(undefined4 *)(&DAT_00422d54 + DAT_0042013c * 0x20) = uVar3;
  (&DAT_00422d40)[DAT_0042013c * 8] = 0xfa;
  (&DAT_00422d44)[DAT_0042013c * 8] = 0x115;
  (&DAT_00422d48)[DAT_0042013c * 8] = (&DAT_00422d40)[DAT_0042013c * 8] + 0x3e;
  (&DAT_00422d4c)[DAT_0042013c * 8] = (&DAT_00422d44)[DAT_0042013c * 8] + 0x26;
  (&DAT_00422d58)[DAT_0042013c * 8] = 0;
  iVar2 = DAT_0042013c * 0x20;
  *(undefined4 *)(&DAT_00422d5c + iVar2) = 9;
  DAT_0042013c = DAT_0042013c + 1;
  uVar4 = 0x7e;
  uVar3 = LoadSurface((char)iVar2,0,uVar1,0x7e);
  iVar2 = DAT_0042013c * 0x20;
  *(undefined4 *)(&DAT_00422d50 + iVar2) = uVar3;
  uVar1 = 0x7f;
  uVar3 = LoadSurface((char)uVar3,(char)iVar2,uVar4,0x7f);
  *(undefined4 *)(&DAT_00422d54 + DAT_0042013c * 0x20) = uVar3;
  (&DAT_00422d40)[DAT_0042013c * 8] = 0xf0;
  (&DAT_00422d44)[DAT_0042013c * 8] = 0x115;
  (&DAT_00422d48)[DAT_0042013c * 8] = (&DAT_00422d40)[DAT_0042013c * 8] + 0x5c;
  (&DAT_00422d4c)[DAT_0042013c * 8] = (&DAT_00422d44)[DAT_0042013c * 8] + 0x26;
  (&DAT_00422d58)[DAT_0042013c * 8] = 0;
  iVar2 = DAT_0042013c * 0x20;
  *(undefined4 *)(&DAT_00422d5c + iVar2) = 3;
  DAT_0042013c = DAT_0042013c + 1;
  uVar4 = 0x86;
  uVar3 = LoadSurface((char)iVar2,0,uVar1,0x86);
  iVar2 = DAT_0042013c * 0x20;
  *(undefined4 *)(&DAT_00422d50 + iVar2) = uVar3;
  uVar1 = 0x87;
  uVar3 = LoadSurface((char)uVar3,(char)iVar2,uVar4,0x87);
  *(undefined4 *)(&DAT_00422d54 + DAT_0042013c * 0x20) = uVar3;
  (&DAT_00422d40)[DAT_0042013c * 8] = 0x1aa;
  (&DAT_00422d44)[DAT_0042013c * 8] = 0x178;
  (&DAT_00422d48)[DAT_0042013c * 8] = (&DAT_00422d40)[DAT_0042013c * 8] + 0x3e;
  (&DAT_00422d4c)[DAT_0042013c * 8] = (&DAT_00422d44)[DAT_0042013c * 8] + 0x26;
  (&DAT_00422d58)[DAT_0042013c * 8] = 0;
  iVar2 = DAT_0042013c * 0x20;
  *(undefined4 *)(&DAT_00422d5c + iVar2) = 2;
  DAT_0042013c = DAT_0042013c + 1;
  uVar4 = 0x78;
  uVar3 = LoadSurface((char)iVar2,0,uVar1,0x78);
  iVar2 = DAT_0042013c * 0x20;
  *(undefined4 *)(&DAT_00422d50 + iVar2) = uVar3;
  uVar1 = 0x79;
  uVar3 = LoadSurface((char)uVar3,(char)iVar2,uVar4,0x79);
  *(undefined4 *)(&DAT_00422d54 + DAT_0042013c * 0x20) = uVar3;
  (&DAT_00422d40)[DAT_0042013c * 8] = 0xd7;
  (&DAT_00422d44)[DAT_0042013c * 8] = 0x11b;
  (&DAT_00422d48)[DAT_0042013c * 8] = (&DAT_00422d40)[DAT_0042013c * 8] + 0x3e;
  (&DAT_00422d4c)[DAT_0042013c * 8] = (&DAT_00422d44)[DAT_0042013c * 8] + 0x26;
  (&DAT_00422d58)[DAT_0042013c * 8] = 0;
  iVar2 = DAT_0042013c * 0x20;
  *(undefined4 *)(&DAT_00422d5c + iVar2) = 7;
  DAT_0042013c = DAT_0042013c + 1;
  uVar4 = 0x78;
  uVar3 = LoadSurface((char)iVar2,0,uVar1,0x78);
  iVar2 = DAT_0042013c * 0x20;
  *(undefined4 *)(&DAT_00422d50 + iVar2) = uVar3;
  uVar1 = 0x79;
  uVar3 = LoadSurface((char)uVar3,(char)iVar2,uVar4,0x79);
  *(undefined4 *)(&DAT_00422d54 + DAT_0042013c * 0x20) = uVar3;
  (&DAT_00422d40)[DAT_0042013c * 8] = 0xd7;
  (&DAT_00422d44)[DAT_0042013c * 8] = 0x115;
  (&DAT_00422d48)[DAT_0042013c * 8] = (&DAT_00422d40)[DAT_0042013c * 8] + 0x3e;
  (&DAT_00422d4c)[DAT_0042013c * 8] = (&DAT_00422d44)[DAT_0042013c * 8] + 0x26;
  (&DAT_00422d58)[DAT_0042013c * 8] = 0;
  *(undefined4 *)(&DAT_00422d5c + DAT_0042013c * 0x20) = 6;
  mci_OpenWave(0xc5,0,uVar1,s_intro_wav_004208c5,s_intro_004208cf);
  mci_OpenWave(0xd5,extraout_DL_29,extraout_CL_13,s_click_wav_004208d5,s_click_004208df);
  mci_OpenWave(0xe5,extraout_DL_30,extraout_CL_14,s_pop_wav_004208e5,&DAT_004208ed);
  mci_OpenWave(0xf1,extraout_DL_31,extraout_CL_15,s_megapop_wav_004208f1,s_megapop_004208fd);
  mci_OpenWave(5,extraout_DL_32,extraout_CL_16,s_score_wav_00420905,s_score_0042090f);
  mci_OpenWave(0x15,extraout_DL_33,extraout_CL_17,s_higscore_wav_00420915,s_highscore_00420922);
  mci_OpenWave(0x2c,extraout_DL_34,extraout_CL_18,s_sharewar_wav_0042092c,s_shareware_00420939);
  wsprintfA(local_104,s_set__s_time_format_tms_00420943,&DAT_0042095a);
  mci_ExecStr((char)local_104,extraout_DL_35,extraout_CL_19,local_104);
  wsprintfA(local_104,s_seek__s_to_end_0042095e,&DAT_0042096d);
  pCVar7 = local_104;
  mci_ExecStr((char)pCVar7,extraout_DL_36,extraout_CL_20,pCVar7);
  mci_PlayWave(0x71,extraout_DL_37,(char)pCVar7,&DAT_00420971);
  wsprintfA(local_104,s_seek__s_to_start_00420975,&DAT_00420986);
  pCVar7 = local_104;
  mci_ExecStr((char)pCVar7,extraout_DL_38,extraout_CL_21,pCVar7);
  if (DAT_00421eec != 0) {
    mci_PlayWave(0x8a,extraout_DL_39,(char)pCVar7,s_click_0042098a);
  }
  Create_Screen();
  DAT_004200a8 = 1;
  return;
}



void Game_Shutdown(void)

{
  undefined extraout_DL;
  undefined extraout_DL_00;
  undefined extraout_DL_01;
  undefined extraout_DL_02;
  undefined extraout_DL_03;
  undefined extraout_DL_04;
  undefined extraout_DL_05;
  undefined uVar1;
  undefined uVar2;
  FILE *pFVar3;
  
  _File_00421e64 = _fopen(s_bubblet_cfg_00420990,&DAT_0042099c);
  _fwrite(&_Str_00421ee8,0xc,1,_File_00421e64);
  _fwrite(&_Str_00421eb0,0x30,1,_File_00421e64);
  pFVar3 = _File_00421e64;
  _fclose(_File_00421e64);
  uVar1 = 0x9f;
  mci_CloseWave(0x9f,extraout_DL,(char)pFVar3,s_intro_0042099f);
  uVar2 = 0xa5;
  mci_CloseWave(0xa5,extraout_DL_00,uVar1,s_click_004209a5);
  uVar1 = 0xab;
  mci_CloseWave(0xab,extraout_DL_01,uVar2,&DAT_004209ab);
  uVar2 = 0xaf;
  mci_CloseWave(0xaf,extraout_DL_02,uVar1,s_megapop_004209af);
  uVar1 = 0xb7;
  mci_CloseWave(0xb7,extraout_DL_03,uVar2,s_score_004209b7);
  uVar2 = 0xbd;
  mci_CloseWave(0xbd,extraout_DL_04,uVar1,s_highscore_004209bd);
  mci_CloseWave(199,extraout_DL_05,uVar2,s_shareware_004209c7);
  timeKillEvent(uTimerID_00421e5c);
  return;
}



void Game_Reload(void)

{
  return;
}



void Game_Message(undefined param_1,undefined param_2,undefined param_3,int param_4,
                 undefined4 param_5,uint param_6)

{
  undefined uVar1;
  undefined3 in_register_00000005;
  undefined3 in_register_00000009;
  int unaff_EBP;
  
  uVar1 = (undefined)param_6;
  if (param_4 < 0x202) {
    if (param_4 == 0x201) {
      Check_Button_Down(uVar1,param_2,param_3,param_6 & 0xffff,param_6 >> 0x10);
      return;
    }
    if (param_4 != 1) {
      if (param_4 == 0xf) {
        if (DAT_004200a8 != 0) {
          Update_Screen();
          return;
        }
      }
      else {
        if (param_4 != 0x10) {
          if (param_4 != 0x200) {
            return;
          }
          Check_Button_Move(uVar1,param_2,param_3,param_6 & 0xffff,param_6 >> 0x10,param_5);
          return;
        }
        Game_Shutdown();
      }
    }
    return;
  }
  if (param_4 == 0x202) {
    Check_Button_Up(uVar1,param_2,param_3,param_6 & 0xffff,param_6 >> 0x10);
    return;
  }
  if (param_4 != 999) {
    if (param_4 != 9999) {
      return;
    }
    Game_Reload();
    return;
  }
  change_mode(0,CONCAT31(in_register_00000009,param_2),CONCAT31(in_register_00000005,param_3),9,
              unaff_EBP);
  return;
}



void CreateOffScreenSurface
               (undefined param_1,undefined param_2,undefined param_3,int *param_4,
               undefined4 param_5,undefined4 param_6)

{
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_c;
  
  _memset(&local_74,0,0x6c);
  local_74 = 0x6c;
  local_70 = 7;
  local_c = 0x40;
  local_68 = param_5;
  local_6c = param_6;
  (**(code **)(*param_4 + 0x18))();
  return;
}



void DDCopyBitmap(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
                 int param_7)

{
  HDC hdc;
  HGDIOBJ h;
  int iVar1;
  HDC local_8;
  
  hdc = CreateCompatibleDC((HDC)0x0);
  h = SelectObject(hdc,(HGDIOBJ)param_5);
  iVar1 = (**(code **)(*(int *)param_4 + 0x44))();
  if (iVar1 == 0) {
    BitBlt(local_8,0,0,param_6,param_7,hdc,0,0,0xcc0020);
    (**(code **)(*(int *)param_4 + 0x68))();
  }
  SelectObject(hdc,h);
  DeleteDC(hdc);
  return;
}



int DDLoadBitmap(undefined param_1,undefined param_2,undefined param_3,undefined4 param_4,
                LPCSTR param_5)

{
  HANDLE h;
  HMODULE hInst;
  BOOL BVar1;
  undefined extraout_CL;
  undefined extraout_CL_00;
  int extraout_ECX;
  undefined extraout_DL;
  undefined extraout_DL_00;
  int extraout_EDX;
  UINT type;
  int iVar2;
  int cy;
  UINT fuLoad;
  undefined local_1c [4];
  int local_18;
  int local_14;
  
  h = LoadImageA((HINSTANCE)0x0,param_5,0,0,0,0x2010);
  if (h == (HANDLE)0x0) {
    fuLoad = 0x2000;
    cy = 0;
    iVar2 = 0;
    type = 0;
    hInst = GetModuleHandleA((LPCSTR)0x0);
    h = LoadImageA(hInst,param_5,type,iVar2,cy,fuLoad);
  }
  if (h == (HANDLE)0x0) {
    iVar2 = 0;
  }
  else {
    iVar2 = GetObjectA(h,0x18,local_1c);
    CreateOffScreenSurface((char)iVar2,extraout_DL,extraout_CL,param_4,local_18,local_14);
    if (iVar2 != 0) {
      DDCopyBitmap(iVar2,extraout_EDX,extraout_ECX,iVar2,(int)h,local_18,local_14);
    }
    BVar1 = DeleteObject(h);
    if (iVar2 == 0) {
      Error_Message((char)BVar1,extraout_DL_00,extraout_CL_00,
                    s_Fehler_beim_laden_eines_Bildes__004209d4);
    }
  }
  return iVar2;
}



int DDReLoadBitmap(undefined param_1,undefined param_2,undefined param_3,int param_4,LPCSTR param_5)

{
  HMODULE hInst;
  HGDIOBJ ho;
  HGDIOBJ pvVar1;
  int extraout_ECX;
  int extraout_ECX_00;
  int extraout_EDX;
  int extraout_EDX_00;
  LPCSTR name;
  UINT type;
  int iVar2;
  int iVar3;
  UINT fuLoad;
  
  fuLoad = 0x2000;
  iVar3 = 0;
  iVar2 = 0;
  type = 0;
  name = param_5;
  hInst = GetModuleHandleA((LPCSTR)0x0);
  ho = LoadImageA(hInst,name,type,iVar2,iVar3,fuLoad);
  iVar2 = extraout_ECX;
  iVar3 = extraout_EDX;
  if (ho == (HANDLE)0x0) {
    ho = LoadImageA((HINSTANCE)0x0,param_5,0,0,0,0x2010);
    iVar2 = extraout_ECX_00;
    iVar3 = extraout_EDX_00;
  }
  if (ho == (HGDIOBJ)0x0) {
    OutputDebugStringA(s_handle_is_null_004209f4);
    pvVar1 = (HGDIOBJ)0x80004005;
  }
  else {
    pvVar1 = ho;
    DDCopyBitmap((int)ho,iVar3,iVar2,param_4,(int)ho,0,0);
    if (pvVar1 != (HGDIOBJ)0x0) {
      OutputDebugStringA(s_ddcopybitmap_failed_00420a04);
    }
    DeleteObject(ho);
  }
  return (int)pvVar1;
}



void LoadSurface(undefined param_1,undefined param_2,undefined param_3,undefined4 param_4)

{
  DDLoadBitmap(param_1,param_2,param_3,DAT_00421e3c,param_4);
  return;
}



void ReLoadSurface(undefined param_1,undefined param_2,undefined param_3,undefined4 param_4,
                  undefined4 param_5)

{
  DDReLoadBitmap(param_1,param_2,param_3,param_4,param_5);
  return;
}



void PutSurface(undefined param_1,undefined param_2,undefined param_3,int param_4,int param_5,
               int *param_6,int *param_7)

{
  int iVar1;
  undefined4 local_ec [2];
  uint local_e4;
  uint local_e0;
  undefined4 local_80 [2];
  int local_78;
  int local_74;
  tagRECT local_14;
  
  _memset(local_80,0,0x6c);
  local_80[0] = 0x6c;
  (**(code **)(*param_6 + 0x58))();
  _memset(local_ec,0,0x6c);
  local_ec[0] = 0x6c;
  (**(code **)(*param_7 + 0x58))();
  if ((uint)(local_74 + param_4) < local_e0 && (uint)(local_78 + param_5) < local_e4) {
    SetRect(&local_14,param_4,param_5,local_74 + param_4,local_78 + param_5);
  }
  else {
    SetRect(&local_14,param_4,param_5,local_e0,local_e4);
  }
  iVar1 = (**(code **)(*param_6 + 0x60))();
  if (iVar1 == -0x7789fe3e) {
    PostMessageA(hWnd_00421e58,9999,0,0);
  }
  iVar1 = (**(code **)(*param_7 + 0x60))();
  if (iVar1 == -0x7789fe3e) {
    PostMessageA(hWnd_00421e58,9999,0,0);
  }
  iVar1 = (**(code **)(*param_7 + 0x14))();
  if (iVar1 == -0x7ff8ffa9) {
    Beep(1000,100);
  }
  return;
}



void PutSurfaceCC(undefined param_1,undefined param_2,undefined param_3,int param_4,int param_5,
                 int *param_6,int *param_7)

{
  int iVar1;
  undefined4 local_ec [2];
  uint local_e4;
  uint local_e0;
  undefined4 local_80 [2];
  int local_78;
  int local_74;
  tagRECT local_14;
  
  _memset(local_80,0,0x6c);
  local_80[0] = 0x6c;
  (**(code **)(*param_6 + 0x58))();
  _memset(local_ec,0,0x6c);
  local_ec[0] = 0x6c;
  (**(code **)(*param_7 + 0x58))();
  if ((uint)(local_74 + param_4) < local_e0 && (uint)(local_78 + param_5) < local_e4) {
    SetRect(&local_14,param_4,param_5,local_74 + param_4,local_78 + param_5);
    iVar1 = (**(code **)(*param_6 + 0x60))();
    if (iVar1 == -0x7789fe3e) {
      PostMessageA(hWnd_00421e58,9999,0,0);
    }
    iVar1 = (**(code **)(*param_7 + 0x60))();
    if (iVar1 == -0x7789fe3e) {
      PostMessageA(hWnd_00421e58,9999,0,0);
    }
    iVar1 = (**(code **)(*param_7 + 0x14))();
    if (iVar1 == -0x7ff8ffa9) {
      Beep(1000,100);
    }
  }
  return;
}



void PutSurfaceClipCC(undefined param_1,undefined param_2,undefined param_3,int param_4,int param_5,
                     int *param_6,int *param_7,int param_8,int param_9,int param_10,int param_11)

{
  int iVar1;
  int iVar2;
  undefined4 local_ec [27];
  undefined4 local_80 [2];
  int local_78;
  int local_74;
  tagRECT local_14;
  
  _memset(local_80,0,0x6c);
  local_80[0] = 0x6c;
  (**(code **)(*param_6 + 0x58))();
  _memset(local_ec,0,0x6c);
  local_ec[0] = 0x6c;
  (**(code **)(*param_7 + 0x58))();
  iVar1 = param_4 + local_74;
  iVar2 = param_5 + local_78;
  if (((param_8 < param_4 && param_9 < param_5) && iVar1 < param_10) && iVar2 < param_11) {
    SetRect(&local_14,param_4,param_5,local_74 + param_4,local_78 + param_5);
    iVar1 = (**(code **)(*param_6 + 0x60))();
    if (iVar1 == -0x7789fe3e) {
      PostMessageA(hWnd_00421e58,9999,0,0);
    }
    iVar1 = (**(code **)(*param_7 + 0x60))();
    if (iVar1 == -0x7789fe3e) {
      PostMessageA(hWnd_00421e58,9999,0,0);
    }
    iVar1 = (**(code **)(*param_7 + 0x14))();
  }
  else {
    SetRect(&local_14,param_4,param_5,local_74 + param_4,local_78 + param_5);
    if (param_4 < param_8) {
      local_14.left = local_14.left + (param_8 - param_4);
    }
    if (param_5 < param_9) {
      local_14.top = local_14.top + (param_9 - param_5);
    }
    if (param_10 < iVar1) {
      local_14.right = local_14.right - (iVar1 - param_10);
    }
    if (param_11 < iVar2) {
      local_14.bottom = local_14.bottom - (iVar2 - param_11);
    }
    iVar1 = (**(code **)(*param_6 + 0x60))();
    if (iVar1 == -0x7789fe3e) {
      PostMessageA(hWnd_00421e58,9999,0,0);
    }
    iVar1 = (**(code **)(*param_7 + 0x60))();
    if (iVar1 == -0x7789fe3e) {
      PostMessageA(hWnd_00421e58,9999,0,0);
    }
    iVar1 = (**(code **)(*param_7 + 0x14))();
  }
  if (iVar1 == -0x7ff8ffa9) {
    Beep(1000,100);
  }
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void PutSurfacePrimary(undefined param_1,undefined param_2,undefined param_3,int param_4,int param_5
                      ,int *param_6)

{
  int iVar1;
  undefined4 local_ec [2];
  uint local_e4;
  uint local_e0;
  undefined4 local_80 [2];
  int local_78;
  int local_74;
  tagRECT local_14;
  
  _memset(local_80,0,0x6c);
  local_80[0] = 0x6c;
  (**(code **)(*param_6 + 0x58))();
  _memset(local_ec,0,0x6c);
  local_ec[0] = 0x6c;
  (**(code **)(*DAT_00421e40 + 0x58))();
  if ((uint)(local_74 + param_4) < local_e0 && (uint)(local_78 + param_5) < local_e4) {
    SetRect(&local_14,param_4 + _DAT_00421e50,param_5 + _DAT_00421e54,
            local_74 + param_4 + _DAT_00421e50,local_78 + param_5 + _DAT_00421e54);
  }
  else {
    SetRect(&local_14,param_4 + _DAT_00421e50,param_5 + _DAT_00421e54,local_e0 + _DAT_00421e50,
            local_e4 + _DAT_00421e54);
  }
  iVar1 = (**(code **)(*param_6 + 0x60))();
  if (iVar1 == -0x7789fe3e) {
    PostMessageA(hWnd_00421e58,9999,0,0);
  }
  iVar1 = (**(code **)(*DAT_00421e40 + 0x60))();
  if (iVar1 == -0x7789fe3e) {
    PostMessageA(hWnd_00421e58,9999,0,0);
  }
  iVar1 = (**(code **)(*DAT_00421e40 + 0x14))();
  if (iVar1 == -0x7ff8ffa9) {
    Beep(1000,100);
  }
  return;
}



void FillSurface(undefined param_1,undefined param_2,undefined param_3,int *param_4,int param_5,
                int param_6,int param_7,int param_8,undefined4 param_9)

{
  int iVar1;
  tagRECT local_14;
  
  SetRect(&local_14,param_5,param_6,param_7,param_8);
  iVar1 = (**(code **)(*param_4 + 0x14))();
  if (iVar1 == -0x7ff8ffa9) {
    Beep(1000,100);
  }
  return;
}



void ShowText(undefined4 param_1,undefined4 param_2,HDC param_3,int *param_4,int param_5,int param_6
             ,LPCSTR param_7,COLORREF param_8)

{
  int c;
  
  (**(code **)(*param_4 + 0x44))();
  SetBkMode(param_3,1);
  SetBkColor(param_3,1);
  SetTextColor(param_3,param_8);
  SetTextAlign(param_3,0);
  c = lstrlenA(param_7);
  TextOutA(param_3,param_5,param_6,param_7,c);
  (**(code **)(*param_4 + 0x68))();
  return;
}



void ShowTextCenter(undefined4 param_1,undefined4 param_2,HDC param_3,int *param_4,int param_5,
                   int param_6,LPCSTR param_7,COLORREF param_8)

{
  int c;
  
  (**(code **)(*param_4 + 0x44))();
  SetBkMode(param_3,1);
  SetBkColor(param_3,1);
  SetTextColor(param_3,param_8);
  SetTextAlign(param_3,6);
  c = lstrlenA(param_7);
  TextOutA(param_3,param_5,param_6,param_7,c);
  (**(code **)(*param_4 + 0x68))();
  return;
}



uint ColorMatch(undefined param_1,undefined param_2,undefined param_3,int *param_4,COLORREF param_5)

{
  int iVar1;
  uint uVar2;
  uint *local_54;
  uint local_24;
  HDC local_c;
  COLORREF local_8;
  
  uVar2 = 0xffffffff;
  if ((param_5 != 0xffffffff) && (iVar1 = (**(code **)(*param_4 + 0x44))(), iVar1 == 0)) {
    local_8 = GetPixel(local_c,0,0);
    SetPixel(local_c,0,0,param_5);
    (**(code **)(*param_4 + 0x68))();
  }
  do {
    iVar1 = (**(code **)(*param_4 + 100))();
  } while (iVar1 == -0x7789fde4);
  if (iVar1 == 0) {
    uVar2 = *local_54;
    if (local_24 < 0x20) {
      uVar2 = uVar2 & (1 << ((byte)local_24 & 0x1f)) - 1U;
    }
    (**(code **)(*param_4 + 0x80))();
  }
  if ((param_5 != 0xffffffff) && (iVar1 = (**(code **)(*param_4 + 0x44))(), iVar1 == 0)) {
    SetPixel(local_c,0,0,local_8);
    (**(code **)(*param_4 + 0x68))();
  }
  return uVar2;
}



void SetColorKey(undefined param_1,undefined param_2,undefined param_3,int *param_4,
                undefined4 param_5)

{
  ColorMatch(param_1,param_2,param_3,param_4,param_5);
  (**(code **)(*param_4 + 0x74))();
  return;
}



void DrawLine(undefined4 param_1,undefined4 param_2,HDC param_3,int *param_4,int param_5,int param_6
             ,int param_7,int param_8,COLORREF param_9)

{
  int iVar1;
  HPEN h;
  HGDIOBJ h_00;
  undefined extraout_CL;
  undefined extraout_DL;
  
  iVar1 = (**(code **)(*param_4 + 0x44))();
  if (iVar1 != 0) {
    Error_Message((char)iVar1,extraout_DL,extraout_CL,&DAT_00420a19);
  }
  h = CreatePen(0,0,param_9);
  h_00 = SelectObject(param_3,h);
  MoveToEx(param_3,param_5,param_6,(LPPOINT)0x0);
  LineTo(param_3,param_7,param_8);
  SelectObject(param_3,h_00);
  DeleteObject(h);
  (**(code **)(*param_4 + 0x68))();
  return;
}



void mci_ExecStr(undefined param_1,undefined param_2,undefined param_3,LPCSTR param_4)

{
  DAT_00423038 = mciSendStringA(param_4,(LPSTR)0x0,0,(HWND)0x0);
  if (DAT_00423038 != 0) {
    return;
  }
  return;
}



bool mci_OpenWave(undefined param_1,undefined param_2,undefined param_3,undefined4 param_4,
                 undefined4 param_5)

{
  CHAR local_104 [256];
  
  wsprintfA(local_104,s_open__s_type_waveaudio_alias__s_00420a2c,param_4,param_5);
  DAT_00423038 = mciSendStringA(local_104,(LPSTR)0x0,0,(HWND)0x0);
  return DAT_00423038 == 0;
}



bool mci_CloseWave(undefined param_1,undefined param_2,undefined param_3,undefined4 param_4)

{
  CHAR local_104 [256];
  
  wsprintfA(local_104,s_close__s_00420a4c,param_4);
  DAT_00423038 = mciSendStringA(local_104,(LPSTR)0x0,0,(HWND)0x0);
  return DAT_00423038 == 0;
}



bool mci_PlayWave(undefined param_1,undefined param_2,undefined param_3,undefined4 param_4)

{
  CHAR local_104 [256];
  
  wsprintfA(local_104,s_play__s_from_0_00420a55,param_4);
  DAT_00423038 = mciSendStringA(local_104,(LPSTR)0x0,0,(HWND)0x0);
  return DAT_00423038 == 0;
}



bool mci_PlayWaveWait(undefined param_1,undefined param_2,undefined param_3,undefined4 param_4)

{
  CHAR local_104 [256];
  
  wsprintfA(local_104,s_play__s_from_0_wait_00420a64,param_4);
  DAT_00423038 = mciSendStringA(local_104,(LPSTR)0x0,0,(HWND)0x0);
  return DAT_00423038 == 0;
}



bool mci_StopWave(undefined param_1,undefined param_2,undefined param_3,undefined4 param_4)

{
  CHAR local_104 [256];
  
  wsprintfA(local_104,s_stop__s_00420a78,param_4);
  DAT_00423038 = mciSendStringA(local_104,(LPSTR)0x0,0,(HWND)0x0);
  return DAT_00423038 == 0;
}



undefined4 mci_PlayCD(void)

{
  undefined4 uVar1;
  CHAR local_104 [256];
  
  wsprintfA(local_104,s_open_cdaudio_00420a80);
  DAT_00423038 = mciSendStringA(local_104,(LPSTR)0x0,0,(HWND)0x0);
  if (DAT_00423038 == 0) {
    wsprintfA(local_104,s_play_cdaudio_00420a8d);
    DAT_00423038 = mciSendStringA(local_104,(LPSTR)0x0,0,(HWND)0x0);
    if (DAT_00423038 == 0) {
      wsprintfA(local_104,s_close_cdaudio_00420a9a);
      DAT_00423038 = mciSendStringA(local_104,(LPSTR)0x0,0,(HWND)0x0);
      if (DAT_00423038 == 0) {
        uVar1 = 1;
      }
      else {
        uVar1 = 0;
      }
    }
    else {
      uVar1 = 0;
    }
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



undefined4 mci_PlayCDTrack(undefined param_1,undefined param_2,undefined param_3,undefined4 param_4)

{
  undefined4 uVar1;
  CHAR local_104 [256];
  
  wsprintfA(local_104,s_open_cdaudio_00420aa8);
  DAT_00423038 = mciSendStringA(local_104,(LPSTR)0x0,0,(HWND)0x0);
  if (DAT_00423038 == 0) {
    wsprintfA(local_104,s_set_cdaudio_time_format_track_00420ab5);
    DAT_00423038 = mciSendStringA(local_104,(LPSTR)0x0,0,(HWND)0x0);
    if (DAT_00423038 == 0) {
      wsprintfA(local_104,s_play_cdaudio_from__u_to__u_00420ad3,param_4,param_4);
      DAT_00423038 = mciSendStringA(local_104,(LPSTR)0x0,0,(HWND)0x0);
      if (DAT_00423038 == 0) {
        wsprintfA(local_104,s_close_cdaudio_00420aee);
        DAT_00423038 = mciSendStringA(local_104,(LPSTR)0x0,0,(HWND)0x0);
        if (DAT_00423038 == 0) {
          uVar1 = 1;
        }
        else {
          uVar1 = 0;
        }
      }
      else {
        uVar1 = 0;
      }
    }
    else {
      uVar1 = 0;
    }
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



void mci_PlayCDFromTrack(undefined param_1,undefined param_2,undefined param_3,undefined4 param_4)

{
  CHAR local_104 [256];
  
  wsprintfA(local_104,s_open_cdaudio_00420afc);
  DAT_00423038 = mciSendStringA(local_104,(LPSTR)0x0,0,(HWND)0x0);
  if (DAT_00423038 == 0) {
    wsprintfA(local_104,s_set_cdaudio_time_format_track_00420b09);
    DAT_00423038 = mciSendStringA(local_104,(LPSTR)0x0,0,(HWND)0x0);
    if (DAT_00423038 == 0) {
      wsprintfA(local_104,s_play_cdaudio_from__u_00420b27,param_4);
      DAT_00423038 = mciSendStringA(local_104,(LPSTR)0x0,0,(HWND)0x0);
      if (DAT_00423038 == 0) {
        wsprintfA(local_104,s_close_cdaudio_00420b3c);
        DAT_00423038 = mciSendStringA(local_104,(LPSTR)0x0,0,(HWND)0x0);
      }
    }
  }
  return;
}



undefined4 mci_StopCD(void)

{
  undefined4 uVar1;
  CHAR local_104 [256];
  
  wsprintfA(local_104,s_open_cdaudio_00420b4a);
  DAT_00423038 = mciSendStringA(local_104,(LPSTR)0x0,0,(HWND)0x0);
  if (DAT_00423038 == 0) {
    wsprintfA(local_104,s_stop_cdaudio_00420b57);
    DAT_00423038 = mciSendStringA(local_104,(LPSTR)0x0,0,(HWND)0x0);
    if (DAT_00423038 == 0) {
      wsprintfA(local_104,s_close_cdaudio_00420b64);
      DAT_00423038 = mciSendStringA(local_104,(LPSTR)0x0,0,(HWND)0x0);
      if (DAT_00423038 == 0) {
        uVar1 = 1;
      }
      else {
        uVar1 = 0;
      }
    }
    else {
      uVar1 = 0;
    }
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



void __InitExceptBlock(int param_1,undefined param_2,undefined param_3,undefined1 param_4)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int unaff_EBP;
  undefined2 in_FS;
  
  puVar2 = (undefined4 *)(unaff_EBP + *(int *)(param_1 + 4));
  puVar2[2] = param_1;
  puVar2[3] = &param_4;
  puVar2[1] = &DAT_00415b1c;
  puVar2[4] = 0;
  *(undefined4 *)((int)puVar2 + 0x12) = 0;
  puVar2[7] = *DAT_0042303c;
  puVar1 = (undefined4 *)segment(in_FS,0);
  *puVar2 = *puVar1;
  puVar1 = (undefined4 *)segment(in_FS,0);
  *puVar1 = puVar2;
  return;
}



undefined4 set_terminate(undefined param_1,undefined param_2,undefined param_3,int param_4)

{
  undefined4 uVar1;
  int in_FS_OFFSET;
  
  uVar1 = *(undefined4 *)(*(int *)(*(int *)(in_FS_OFFSET + 4) + -8) + 8);
  if (param_4 != 0) {
    *(int *)(*(int *)(*(int *)(in_FS_OFFSET + 4) + -8) + 8) = param_4;
  }
  return uVar1;
}



void ___call_terminate(void)

{
  undefined in_CL;
  undefined in_DL;
  undefined1 unaff_DI;
  int in_FS_OFFSET;
  
  __InitExceptBlock(0x420c38,in_DL,in_CL,unaff_DI);
  _flushall();
  (**(code **)(*(int *)(*(int *)(in_FS_OFFSET + 4) + -8) + 8))();
                    // WARNING: Subroutine does not return
  _abort();
}



undefined4 set_unexpected(undefined param_1,undefined param_2,undefined param_3,int param_4)

{
  undefined4 uVar1;
  int in_FS_OFFSET;
  
  uVar1 = *(undefined4 *)(*(int *)(*(int *)(in_FS_OFFSET + 4) + -8) + 0xc);
  if (param_4 != 0) {
    *(int *)(*(int *)(*(int *)(in_FS_OFFSET + 4) + -8) + 0xc) = param_4;
  }
  return uVar1;
}



void __GetPolymorphicDTC(undefined param_1,undefined param_2,undefined param_3,int param_4,
                        undefined4 param_5)

{
  if (param_4 == 0) {
    return;
  }
  return;
}



void __ExceptInit(undefined param_1,undefined param_2,undefined param_3,int param_4)

{
  HMODULE hModule;
  undefined extraout_CL;
  undefined extraout_CL_00;
  undefined extraout_DL;
  undefined extraout_DL_00;
  undefined extraout_DL_01;
  FARPROC pFVar1;
  int in_FS_OFFSET;
  bool bVar2;
  uint local_c;
  int local_8;
  
  bVar2 = param_4 == 0;
  if (param_4 == 0) {
    if (DAT_00420058 != '\0') {
      pFVar1 = (FARPROC)0x0;
      hModule = GetModuleHandleA((LPCSTR)0x0);
      param_3 = extraout_CL;
      param_2 = extraout_DL;
      if (hModule != (HMODULE)0x0) {
        pFVar1 = GetProcAddress(hModule,s___GetExceptDLLinfo_00420c50);
        param_3 = extraout_CL_00;
        param_2 = extraout_DL_00;
      }
      if (pFVar1 != (FARPROC)0x0) {
        param_3 = SUB41(&local_c,0);
        (*pFVar1)();
        param_2 = extraout_DL_01;
        if ((0x82727348 < local_c) && (local_c < 0x8272735a)) {
          param_4 = local_8;
        }
      }
    }
    if (param_4 == 0) {
      __GetExceptDLLinfoInternal((char)&local_c,param_2,param_3,&local_c);
      param_4 = local_8;
    }
  }
  else {
    *(undefined **)(param_4 + 8) = &LAB_004158ec;
    *(undefined **)(param_4 + 0xc) = &LAB_00415965;
  }
  *(int *)(*(int *)(in_FS_OFFSET + 4) + -8) = param_4;
  if (bVar2) {
    DAT_0042303c = *(int *)(in_FS_OFFSET + 4) + -4;
  }
  *(undefined4 *)(*(int *)(in_FS_OFFSET + 4) + -4) = 0;
  *(undefined4 *)(*(int *)(*(int *)(in_FS_OFFSET + 4) + -8) + 4) = 0;
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void __GetExceptDLLinfoInternal
               (undefined param_1,undefined param_2,undefined param_3,undefined4 *param_4)

{
  int in_FS_OFFSET;
  
  _DAT_00420b90 = *(int *)(*(int *)(in_FS_OFFSET + 4) + -8) + 0x24;
  *param_4 = 0x82727349;
  param_4[1] = &DAT_00420b74;
  return;
}



undefined4 __matherr(undefined param_1,undefined param_2,undefined param_3,int *param_4)

{
  if (*param_4 == 4) {
    param_4[6] = 0;
    param_4[7] = 0;
    return 1;
  }
  if (*param_4 == 5) {
    return 1;
  }
  return 0;
}



FILE * __cdecl _fopen(char *_Filename,char *_Mode)

{
  FILE *pFVar1;
  
                    // WARNING: Could not recover jumptable at 0x00415afe. Too many branches
                    // WARNING: Treating indirect jump as call
  pFVar1 = _fopen(_Filename,_Mode);
  return pFVar1;
}



size_t __cdecl _fread(void *_DstBuf,size_t _ElementSize,size_t _Count,FILE *_File)

{
  size_t sVar1;
  
                    // WARNING: Could not recover jumptable at 0x00415b04. Too many branches
                    // WARNING: Treating indirect jump as call
  sVar1 = _fread(_DstBuf,_ElementSize,_Count,_File);
  return sVar1;
}



double * __cdecl _floor(double *__return_storage_ptr__,double _X)

{
  double *pdVar1;
  
                    // WARNING: Could not recover jumptable at 0x00415b0a. Too many branches
                    // WARNING: Treating indirect jump as call
  pdVar1 = _floor(__return_storage_ptr__,_X);
  return pdVar1;
}



time_t * __cdecl _time(time_t *__return_storage_ptr__,time_t *_Time)

{
  time_t *ptVar1;
  
                    // WARNING: Could not recover jumptable at 0x00415b10. Too many branches
                    // WARNING: Treating indirect jump as call
  ptVar1 = _time(__return_storage_ptr__,_Time);
  return ptVar1;
}



void __lrand(void)

{
                    // WARNING: Could not recover jumptable at 0x00415b22. Too many branches
                    // WARNING: Treating indirect jump as call
  __lrand();
  return;
}



void __cdecl _srand(uint _Seed)

{
                    // WARNING: Could not recover jumptable at 0x00415b28. Too many branches
                    // WARNING: Treating indirect jump as call
  _srand(_Seed);
  return;
}



int __cdecl _fclose(FILE *_File)

{
  int iVar1;
  
                    // WARNING: Could not recover jumptable at 0x00415b2e. Too many branches
                    // WARNING: Treating indirect jump as call
  iVar1 = _fclose(_File);
  return iVar1;
}



void * __cdecl _memset(void *_Dst,int _Val,size_t _Size)

{
  void *pvVar1;
  
                    // WARNING: Could not recover jumptable at 0x00415b34. Too many branches
                    // WARNING: Treating indirect jump as call
  pvVar1 = _memset(_Dst,_Val,_Size);
  return pvVar1;
}



void __ftol(void)

{
                    // WARNING: Could not recover jumptable at 0x00415b3a. Too many branches
                    // WARNING: Treating indirect jump as call
  __ftol();
  return;
}



int __cdecl _flushall(void)

{
  int iVar1;
  
                    // WARNING: Could not recover jumptable at 0x00415b40. Too many branches
                    // WARNING: Treating indirect jump as call
  iVar1 = _flushall();
  return iVar1;
}



void __startup(void)

{
                    // WARNING: Could not recover jumptable at 0x00415b46. Too many branches
                    // WARNING: Treating indirect jump as call
  __startup();
  return;
}



void __cdecl _abort(void)

{
                    // WARNING: Could not recover jumptable at 0x00415b4c. Too many branches
                    // WARNING: Subroutine does not return
                    // WARNING: Treating indirect jump as call
  _abort();
  return;
}



size_t __cdecl _fwrite(void *_Str,size_t _Size,size_t _Count,FILE *_File)

{
  size_t sVar1;
  
                    // WARNING: Could not recover jumptable at 0x00415b52. Too many branches
                    // WARNING: Treating indirect jump as call
  sVar1 = _fwrite(_Str,_Size,_Count,_File);
  return sVar1;
}



int __cdecl _sprintf(char *_Dest,char *_Format,...)

{
  int iVar1;
  
                    // WARNING: Could not recover jumptable at 0x00415b58. Too many branches
                    // WARNING: Treating indirect jump as call
  iVar1 = _sprintf(_Dest,_Format);
  return iVar1;
}



HMODULE __stdcall GetModuleHandleA(LPCSTR lpModuleName)

{
  HMODULE pHVar1;
  
                    // WARNING: Could not recover jumptable at 0x00415b5e. Too many branches
                    // WARNING: Treating indirect jump as call
  pHVar1 = GetModuleHandleA(lpModuleName);
  return pHVar1;
}



int __stdcall lstrlenA(LPCSTR lpString)

{
  int iVar1;
  
                    // WARNING: Could not recover jumptable at 0x00415b64. Too many branches
                    // WARNING: Treating indirect jump as call
  iVar1 = lstrlenA(lpString);
  return iVar1;
}



void __stdcall OutputDebugStringA(LPCSTR lpOutputString)

{
                    // WARNING: Could not recover jumptable at 0x00415b6a. Too many branches
                    // WARNING: Treating indirect jump as call
  OutputDebugStringA(lpOutputString);
  return;
}



BOOL __stdcall Beep(DWORD dwFreq,DWORD dwDuration)

{
  BOOL BVar1;
  
                    // WARNING: Could not recover jumptable at 0x00415b70. Too many branches
                    // WARNING: Treating indirect jump as call
  BVar1 = Beep(dwFreq,dwDuration);
  return BVar1;
}



FARPROC __stdcall GetProcAddress(HMODULE hModule,LPCSTR lpProcName)

{
  FARPROC pFVar1;
  
                    // WARNING: Could not recover jumptable at 0x00415b76. Too many branches
                    // WARNING: Treating indirect jump as call
  pFVar1 = GetProcAddress(hModule,lpProcName);
  return pFVar1;
}



int __stdcall GetSystemMetrics(int nIndex)

{
  int iVar1;
  
                    // WARNING: Could not recover jumptable at 0x00415b7c. Too many branches
                    // WARNING: Treating indirect jump as call
  iVar1 = GetSystemMetrics(nIndex);
  return iVar1;
}



BOOL __stdcall GetMessageA(LPMSG lpMsg,HWND hWnd,UINT wMsgFilterMin,UINT wMsgFilterMax)

{
  BOOL BVar1;
  
                    // WARNING: Could not recover jumptable at 0x00415b82. Too many branches
                    // WARNING: Treating indirect jump as call
  BVar1 = GetMessageA(lpMsg,hWnd,wMsgFilterMin,wMsgFilterMax);
  return BVar1;
}



LRESULT __stdcall DispatchMessageA(MSG *lpMsg)

{
  LRESULT LVar1;
  
                    // WARNING: Could not recover jumptable at 0x00415b88. Too many branches
                    // WARNING: Treating indirect jump as call
  LVar1 = DispatchMessageA(lpMsg);
  return LVar1;
}



BOOL __stdcall DestroyWindow(HWND hWnd)

{
  BOOL BVar1;
  
                    // WARNING: Could not recover jumptable at 0x00415b8e. Too many branches
                    // WARNING: Treating indirect jump as call
  BVar1 = DestroyWindow(hWnd);
  return BVar1;
}



LRESULT __stdcall DefWindowProcA(HWND hWnd,UINT Msg,WPARAM wParam,LPARAM lParam)

{
  LRESULT LVar1;
  
                    // WARNING: Could not recover jumptable at 0x00415b94. Too many branches
                    // WARNING: Treating indirect jump as call
  LVar1 = DefWindowProcA(hWnd,Msg,wParam,lParam);
  return LVar1;
}



HWND __stdcall
CreateWindowExA(DWORD dwExStyle,LPCSTR lpClassName,LPCSTR lpWindowName,DWORD dwStyle,int X,int Y,
               int nWidth,int nHeight,HWND hWndParent,HMENU hMenu,HINSTANCE hInstance,LPVOID lpParam
               )

{
  HWND pHVar1;
  
                    // WARNING: Could not recover jumptable at 0x00415b9a. Too many branches
                    // WARNING: Treating indirect jump as call
  pHVar1 = CreateWindowExA(dwExStyle,lpClassName,lpWindowName,dwStyle,X,Y,nWidth,nHeight,hWndParent,
                           hMenu,hInstance,lpParam);
  return pHVar1;
}



BOOL __stdcall ClientToScreen(HWND hWnd,LPPOINT lpPoint)

{
  BOOL BVar1;
  
                    // WARNING: Could not recover jumptable at 0x00415ba0. Too many branches
                    // WARNING: Treating indirect jump as call
  BVar1 = ClientToScreen(hWnd,lpPoint);
  return BVar1;
}



BOOL __stdcall AdjustWindowRectEx(LPRECT lpRect,DWORD dwStyle,BOOL bMenu,DWORD dwExStyle)

{
  BOOL BVar1;
  
                    // WARNING: Could not recover jumptable at 0x00415ba6. Too many branches
                    // WARNING: Treating indirect jump as call
  BVar1 = AdjustWindowRectEx(lpRect,dwStyle,bMenu,dwExStyle);
  return BVar1;
}



LONG __stdcall GetWindowLongA(HWND hWnd,int nIndex)

{
  LONG LVar1;
  
                    // WARNING: Could not recover jumptable at 0x00415bac. Too many branches
                    // WARNING: Treating indirect jump as call
  LVar1 = GetWindowLongA(hWnd,nIndex);
  return LVar1;
}



int __cdecl wsprintfA(LPSTR param_1,LPCSTR param_2,...)

{
  int iVar1;
  
                    // WARNING: Could not recover jumptable at 0x00415bb2. Too many branches
                    // WARNING: Treating indirect jump as call
  iVar1 = wsprintfA(param_1,param_2);
  return iVar1;
}



BOOL __stdcall TranslateMessage(MSG *lpMsg)

{
  BOOL BVar1;
  
                    // WARNING: Could not recover jumptable at 0x00415bb8. Too many branches
                    // WARNING: Treating indirect jump as call
  BVar1 = TranslateMessage(lpMsg);
  return BVar1;
}



BOOL __stdcall ShowWindow(HWND hWnd,int nCmdShow)

{
  BOOL BVar1;
  
                    // WARNING: Could not recover jumptable at 0x00415bbe. Too many branches
                    // WARNING: Treating indirect jump as call
  BVar1 = ShowWindow(hWnd,nCmdShow);
  return BVar1;
}



BOOL __stdcall SetRect(LPRECT lprc,int xLeft,int yTop,int xRight,int yBottom)

{
  BOOL BVar1;
  
                    // WARNING: Could not recover jumptable at 0x00415bc4. Too many branches
                    // WARNING: Treating indirect jump as call
  BVar1 = SetRect(lprc,xLeft,yTop,xRight,yBottom);
  return BVar1;
}



ATOM __stdcall RegisterClassA(WNDCLASSA *lpWndClass)

{
  ATOM AVar1;
  
                    // WARNING: Could not recover jumptable at 0x00415bca. Too many branches
                    // WARNING: Treating indirect jump as call
  AVar1 = RegisterClassA(lpWndClass);
  return AVar1;
}



void __stdcall PostQuitMessage(int nExitCode)

{
                    // WARNING: Could not recover jumptable at 0x00415bd0. Too many branches
                    // WARNING: Treating indirect jump as call
  PostQuitMessage(nExitCode);
  return;
}



BOOL __stdcall PostMessageA(HWND hWnd,UINT Msg,WPARAM wParam,LPARAM lParam)

{
  BOOL BVar1;
  
                    // WARNING: Could not recover jumptable at 0x00415bd6. Too many branches
                    // WARNING: Treating indirect jump as call
  BVar1 = PostMessageA(hWnd,Msg,wParam,lParam);
  return BVar1;
}



BOOL __stdcall MoveWindow(HWND hWnd,int X,int Y,int nWidth,int nHeight,BOOL bRepaint)

{
  BOOL BVar1;
  
                    // WARNING: Could not recover jumptable at 0x00415bdc. Too many branches
                    // WARNING: Treating indirect jump as call
  BVar1 = MoveWindow(hWnd,X,Y,nWidth,nHeight,bRepaint);
  return BVar1;
}



int __stdcall MessageBoxA(HWND hWnd,LPCSTR lpText,LPCSTR lpCaption,UINT uType)

{
  int iVar1;
  
                    // WARNING: Could not recover jumptable at 0x00415be2. Too many branches
                    // WARNING: Treating indirect jump as call
  iVar1 = MessageBoxA(hWnd,lpText,lpCaption,uType);
  return iVar1;
}



HANDLE __stdcall LoadImageA(HINSTANCE hInst,LPCSTR name,UINT type,int cx,int cy,UINT fuLoad)

{
  HANDLE pvVar1;
  
                    // WARNING: Could not recover jumptable at 0x00415be8. Too many branches
                    // WARNING: Treating indirect jump as call
  pvVar1 = LoadImageA(hInst,name,type,cx,cy,fuLoad);
  return pvVar1;
}



HICON __stdcall LoadIconA(HINSTANCE hInstance,LPCSTR lpIconName)

{
  HICON pHVar1;
  
                    // WARNING: Could not recover jumptable at 0x00415bee. Too many branches
                    // WARNING: Treating indirect jump as call
  pHVar1 = LoadIconA(hInstance,lpIconName);
  return pHVar1;
}



BOOL __stdcall UpdateWindow(HWND hWnd)

{
  BOOL BVar1;
  
                    // WARNING: Could not recover jumptable at 0x00415bf4. Too many branches
                    // WARNING: Treating indirect jump as call
  BVar1 = UpdateWindow(hWnd);
  return BVar1;
}



HCURSOR __stdcall LoadCursorA(HINSTANCE hInstance,LPCSTR lpCursorName)

{
  HCURSOR pHVar1;
  
                    // WARNING: Could not recover jumptable at 0x00415bfa. Too many branches
                    // WARNING: Treating indirect jump as call
  pHVar1 = LoadCursorA(hInstance,lpCursorName);
  return pHVar1;
}



MMRESULT __stdcall
timeSetEvent(UINT uDelay,UINT uResolution,LPTIMECALLBACK fptc,DWORD_PTR dwUser,UINT fuEvent)

{
  MMRESULT MVar1;
  
                    // WARNING: Could not recover jumptable at 0x00415c00. Too many branches
                    // WARNING: Treating indirect jump as call
  MVar1 = timeSetEvent(uDelay,uResolution,fptc,dwUser,fuEvent);
  return MVar1;
}



MMRESULT __stdcall timeKillEvent(UINT uTimerID)

{
  MMRESULT MVar1;
  
                    // WARNING: Could not recover jumptable at 0x00415c06. Too many branches
                    // WARNING: Treating indirect jump as call
  MVar1 = timeKillEvent(uTimerID);
  return MVar1;
}



MCIERROR __stdcall
mciSendStringA(LPCSTR lpstrCommand,LPSTR lpstrReturnString,UINT uReturnLength,HWND hwndCallback)

{
  MCIERROR MVar1;
  
                    // WARNING: Could not recover jumptable at 0x00415c0c. Too many branches
                    // WARNING: Treating indirect jump as call
  MVar1 = mciSendStringA(lpstrCommand,lpstrReturnString,uReturnLength,hwndCallback);
  return MVar1;
}



void DirectDrawCreate(void)

{
                    // WARNING: Could not recover jumptable at 0x00415c12. Too many branches
                    // WARNING: Treating indirect jump as call
  DirectDrawCreate();
  return;
}



BOOL __stdcall MoveToEx(HDC hdc,int x,int y,LPPOINT lppt)

{
  BOOL BVar1;
  
                    // WARNING: Could not recover jumptable at 0x00415c18. Too many branches
                    // WARNING: Treating indirect jump as call
  BVar1 = MoveToEx(hdc,x,y,lppt);
  return BVar1;
}



BOOL __stdcall LineTo(HDC hdc,int x,int y)

{
  BOOL BVar1;
  
                    // WARNING: Could not recover jumptable at 0x00415c1e. Too many branches
                    // WARNING: Treating indirect jump as call
  BVar1 = LineTo(hdc,x,y);
  return BVar1;
}



BOOL __stdcall BitBlt(HDC hdc,int x,int y,int cx,int cy,HDC hdcSrc,int x1,int y1,DWORD rop)

{
  BOOL BVar1;
  
                    // WARNING: Could not recover jumptable at 0x00415c24. Too many branches
                    // WARNING: Treating indirect jump as call
  BVar1 = BitBlt(hdc,x,y,cx,cy,hdcSrc,x1,y1,rop);
  return BVar1;
}



COLORREF __stdcall GetPixel(HDC hdc,int x,int y)

{
  COLORREF CVar1;
  
                    // WARNING: Could not recover jumptable at 0x00415c2a. Too many branches
                    // WARNING: Treating indirect jump as call
  CVar1 = GetPixel(hdc,x,y);
  return CVar1;
}



int __stdcall GetObjectA(HANDLE h,int c,LPVOID pv)

{
  int iVar1;
  
                    // WARNING: Could not recover jumptable at 0x00415c30. Too many branches
                    // WARNING: Treating indirect jump as call
  iVar1 = GetObjectA(h,c,pv);
  return iVar1;
}



BOOL __stdcall TextOutA(HDC hdc,int x,int y,LPCSTR lpString,int c)

{
  BOOL BVar1;
  
                    // WARNING: Could not recover jumptable at 0x00415c36. Too many branches
                    // WARNING: Treating indirect jump as call
  BVar1 = TextOutA(hdc,x,y,lpString,c);
  return BVar1;
}



BOOL __stdcall DeleteObject(HGDIOBJ ho)

{
  BOOL BVar1;
  
                    // WARNING: Could not recover jumptable at 0x00415c3c. Too many branches
                    // WARNING: Treating indirect jump as call
  BVar1 = DeleteObject(ho);
  return BVar1;
}



COLORREF __stdcall SetTextColor(HDC hdc,COLORREF color)

{
  COLORREF CVar1;
  
                    // WARNING: Could not recover jumptable at 0x00415c42. Too many branches
                    // WARNING: Treating indirect jump as call
  CVar1 = SetTextColor(hdc,color);
  return CVar1;
}



UINT __stdcall SetTextAlign(HDC hdc,UINT align)

{
  UINT UVar1;
  
                    // WARNING: Could not recover jumptable at 0x00415c48. Too many branches
                    // WARNING: Treating indirect jump as call
  UVar1 = SetTextAlign(hdc,align);
  return UVar1;
}



BOOL __stdcall DeleteDC(HDC hdc)

{
  BOOL BVar1;
  
                    // WARNING: Could not recover jumptable at 0x00415c4e. Too many branches
                    // WARNING: Treating indirect jump as call
  BVar1 = DeleteDC(hdc);
  return BVar1;
}



COLORREF __stdcall SetPixel(HDC hdc,int x,int y,COLORREF color)

{
  COLORREF CVar1;
  
                    // WARNING: Could not recover jumptable at 0x00415c54. Too many branches
                    // WARNING: Treating indirect jump as call
  CVar1 = SetPixel(hdc,x,y,color);
  return CVar1;
}



int __stdcall SetBkMode(HDC hdc,int mode)

{
  int iVar1;
  
                    // WARNING: Could not recover jumptable at 0x00415c5a. Too many branches
                    // WARNING: Treating indirect jump as call
  iVar1 = SetBkMode(hdc,mode);
  return iVar1;
}



HPEN __stdcall CreatePen(int iStyle,int cWidth,COLORREF color)

{
  HPEN pHVar1;
  
                    // WARNING: Could not recover jumptable at 0x00415c60. Too many branches
                    // WARNING: Treating indirect jump as call
  pHVar1 = CreatePen(iStyle,cWidth,color);
  return pHVar1;
}



COLORREF __stdcall SetBkColor(HDC hdc,COLORREF color)

{
  COLORREF CVar1;
  
                    // WARNING: Could not recover jumptable at 0x00415c66. Too many branches
                    // WARNING: Treating indirect jump as call
  CVar1 = SetBkColor(hdc,color);
  return CVar1;
}



HGDIOBJ __stdcall SelectObject(HDC hdc,HGDIOBJ h)

{
  HGDIOBJ pvVar1;
  
                    // WARNING: Could not recover jumptable at 0x00415c6c. Too many branches
                    // WARNING: Treating indirect jump as call
  pvVar1 = SelectObject(hdc,h);
  return pvVar1;
}



HDC __stdcall CreateCompatibleDC(HDC hdc)

{
  HDC pHVar1;
  
                    // WARNING: Could not recover jumptable at 0x00415c72. Too many branches
                    // WARNING: Treating indirect jump as call
  pHVar1 = CreateCompatibleDC(hdc);
  return pHVar1;
}


