#include<Windows.h>
#include<stdio.h>

#define STATUS_SUCCESS 0x00000000

extern "C" NTSTATUS NTAPI DirectNtAllocateVirtualMemory(
    HANDLE ProcessHandle,
    PVOID* BaseAddress,
    ULONG_PTR ZeroBits,
    PSIZE_T RegionSize,
    ULONG AllocationType,
    ULONG Protect
);

int main(void) {
    NTSTATUS status = 0;
    PVOID baseAddress = nullptr; // 할당될 메모리의 시작 주소
    SIZE_T regionSize = 0x1000;  // 4KB
    ULONG allocationType = MEM_COMMIT | MEM_RESERVE;
    ULONG protect = PAGE_READWRITE;

    // DirectNtAllocateVirtualMemory 호출
    status = DirectNtAllocateVirtualMemory(
        GetCurrentProcess(), // 현재 프로세스의 핸들
        &baseAddress,        // 할당된 메모리 주소
        0,                   // ZeroBits (미사용)
        &regionSize,         // 할당할 메모리 크기
        allocationType,      // 메모리 할당 유형
        protect              // 메모리 보호 유형
    );
        if(status != STATUS_SUCCESS) {
            printf("Memory allocation failed with status: 0x%X\n", status);
            return -1;
        }

    printf("Memory allocated at: %p\n", baseAddress);
    return 0;
}