using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CardGame
{
    public class Player : IAccount
    {
        public string Nick { get; set; }
        public int Points { get; set; }

        public Player()
        {
        }
        public Player(string nick, int points)
        {
            Nick = nick;
            Points = points;
        }
        
        public void BuyCard(int cost)
        {
            if (cost > Points)
                throw new OverflowException();
            Points -= cost;
        }

        public void SellCard(int cost)
        {
            Points += cost;
        }

        public double BuyPoints(double currency, double tax)
        {
            return currency - tax;
        }
    }
}
