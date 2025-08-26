using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace MathLibrary
{
    public interface BaseMath
    {
        int Add(int x, int y);
        int Substract(int x, int y);
    }
    public class Math : BaseMath
    {
        public int Add(int x, int y)
        {
            return x + y;
        }

        public int Substract(int x, int y)
        {
            return x - y;
        }
    }
}

// Type of project: Class Library (.NET Framework 4.7.2)