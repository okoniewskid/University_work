using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CardGame
{
    public class Card
    {
        public int CardCost { get; set; }
        public string CardName { get; set; }
        public int CardPrice { get; set; }
        public string CardText { get; set; }

        private Card()
        {
        }

        public Card(int cost, string name, int price, string text)
        {
            CardCost = cost;
            CardName = name;
            CardPrice = price;
            CardText = text;
        }
    }
}
