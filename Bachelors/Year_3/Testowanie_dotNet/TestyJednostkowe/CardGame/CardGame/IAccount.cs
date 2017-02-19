using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CardGame
{
    public interface IAccount
    {
        double BuyPoints(double currency, double tax);
    }
}
