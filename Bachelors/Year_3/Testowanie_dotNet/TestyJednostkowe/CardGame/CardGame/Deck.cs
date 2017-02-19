using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CardGame
{
    public class Deck
    {
        public int Id { get; set; }
        public string Name { get; set; }
        public Player Owner { get; set; }
        public ArrayList Cards = new ArrayList();
        private Deck()
        {
        }

        public Deck(string name, Player player)
        {
            Name = name;
            Owner = player;
        }

        public void AddCard(Card card)
        {
            Cards.Add(card);
        }

        public void RemoveCard(Card card)
        {
            Cards.Remove(card);
        }

        public static bool DeckCompletion()
        {
            return false;
        }
    }
}
