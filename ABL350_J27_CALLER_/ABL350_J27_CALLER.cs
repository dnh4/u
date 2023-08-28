using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Runtime.InteropServices;

class ABL350_J27_CALLER_
{
   // Import the DLL function
    [DllImport("ABL350_J27.DLL", CallingConvention = CallingConvention.Cdecl)]
    public static extern void ConvertToUpperCase(string inputString, string outputString, int maxLength);

    static void Main(string[] args)
    {
        try
        {
            Console.Write("Enter a Unicode string: ");
            string inputString = Console.ReadLine();

            int maxLength = 2 * (inputString.Length + 1); // Allocate enough space for wide characters
            string outputString = new string('\0', maxLength); // Initialize the output buffer

            ConvertToUpperCase(inputString, outputString, maxLength);

            Console.WriteLine("Uppercase output: " + outputString);
        }
        catch (Exception ex)
        {
            Console.WriteLine("An error occurred: " + ex.Message);
        }
    }
}
