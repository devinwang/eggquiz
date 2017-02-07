using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace EggQuiz
{

    class EggQuiz
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Result: {0}",
                new EggQuiz().GetResultOfQuiz());
        }

        public int GetResultOfQuiz()
        {
            IRule[] rules = RuleFactory();
            for (int i = 1; i < 1000000; i++)
            {
                if (rules.All(x => x.IsMatch(i)))
                    return i;
            }
            return 0;
        }

        public IRule[] RuleFactory()
        {
            IRule[] rets = new IRule[]
            {
            new Rule1(), new Rule2(), new Rule3(), new Rule4(),
            new Rule5(), new Rule6(), new Rule7(), new Rule8(),
            new Rule9()
            };
            return rets;
        }
    }

    interface IRule
    {
        bool IsMatch(int NumberOfEgg);
    }

    public class Rule1 : IRule{
        public bool IsMatch(int NumberOfEgg)
        {
            return true;
        }
    }
    public class Rule2 : IRule
    {
        public bool IsMatch(int NumberOfEgg)
        {
            return NumberOfEgg%2 == 1;
        }
    }
    public class Rule3 : IRule
    {
        public bool IsMatch(int NumberOfEgg)
        {
            return NumberOfEgg % 3 == 0;
        }
    }
    public class Rule4 : IRule
    {
        public bool IsMatch(int NumberOfEgg)
        {
            return NumberOfEgg % 4 == 1;
        }
    }
    public class Rule5 : IRule
    {
        public bool IsMatch(int NumberOfEgg)
        {
            return NumberOfEgg % 5 == 5-1;
        }
    }
    public class Rule6 : IRule
    {
        public bool IsMatch(int NumberOfEgg)
        {
            return NumberOfEgg % 6 == 3;
        }
    }
    public class Rule7 : IRule
    {
        public bool IsMatch(int NumberOfEgg)
        {
            return NumberOfEgg % 7 == 0;
        }
    }
    public class Rule8 : IRule
    {
        public bool IsMatch(int NumberOfEgg)
        {
            return NumberOfEgg % 8 == 1;
        }
    }
    public class Rule9 : IRule
    {
        public bool IsMatch(int NumberOfEgg)
        {
            return NumberOfEgg % 9 == 0;
        }
    }

}
