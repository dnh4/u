#include <windows.h>
#include <string>
#include <locale>
#include <codecvt>

extern "C" __declspec(dllexport) void ConvertToUpperCase(wchar_t* inputString, wchar_t* outputString, int maxLength)
{
    // Convert inputString to uppercase
    std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
    std::wstring wideInput = inputString;
    std::wstring wideOutput;

    std::locale loc;
    for (wchar_t c : wideInput)
    {
        wideOutput += std::toupper(c, loc);
    }

    // Copy the uppercase string to the output buffer
    wcsncpy_s(outputString, maxLength, wideOutput.c_str(), _TRUNCATE);
}
