using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace test01
{
    class Program
    {

        const Int32 nbCols = 10000;
        const Int32 nbRows = 10000;

        static double[,] mat = new double[nbCols, nbRows];

        static double getValue(Int32 i, Int32 j)
        {

            if (i > j)
                return (i + j) * Math.Sqrt(i) * Math.Sqrt(j) * Math.Sqrt((i * j) / 3.03) / 3.03;
            else if (i < j)
                return (i + j) * Math.Sqrt(i) * (Math.Sqrt(j) + Math.Sqrt((i * j)) / 3.33) / 3.33;
            else
                return 3.33;

        }

        static void Main(string[] args)
        {

            Stopwatch stopWatch = new Stopwatch();

            stopWatch.Start();

            for (int i = 0; i < nbCols; ++i)
            {
                for (int j = 0; j < nbRows; ++j)
                {
                    mat[i, j] = i / (j + 1) * getValue(i, j) * getValue(2 * i, 3 * j);
                }
            }

            stopWatch.Stop();

            double elapsed = stopWatch.Elapsed.TotalMilliseconds / 1000;

            Console.WriteLine("Elapsed time: " + elapsed + " s");

        }

    }
}

