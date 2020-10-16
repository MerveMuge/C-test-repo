using System;
using static Some.Namespace.AllMethods;
using OtherWay;

namespace Other.Namespace
{
    class Caller
    {
        public static void Main(string[] args)
        {
            //Some.Namespace somew = Some.eNamespace();
            Console.WriteLine("Call from caller");
            Method2(); // No need to mention AllMethods here

            OtherMethods other = new OtherMethods();
            other.Method3();
        }
    }
}