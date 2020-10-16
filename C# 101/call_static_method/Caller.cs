using System;
using static Some.Namespace.AllMethods;

namespace Other.Namespace
{
    class Caller
    {
        public static void Main(string[] args)
        {
            Console.WriteLine("Call from caller");
            Method2(); // No need to mention AllMethods here
        }
    }
}