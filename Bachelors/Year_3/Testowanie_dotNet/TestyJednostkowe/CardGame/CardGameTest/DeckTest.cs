using System;
using System.Collections;
using System.ComponentModel;
using System.Runtime.Remoting.Messaging;
using CardGame;
using CardGame.Fakes;
using Microsoft.QualityTools.Testing.Fakes;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using static Microsoft.VisualStudio.TestTools.UnitTesting.CollectionAssert;

namespace CardGameTest
{
    [TestClass]
    public class DeckTest
    {
        [TestMethod]
        public void TestAddCard()
        {
            Player player = new Player("Adam", 1000);
            Deck deck = new Deck("talia", player);
            Card card = new Card(3, "Kowal", 200, "To jest tekst karty");

            deck.AddCard(card);

            Contains(deck.Cards, card);
        }

        [TestMethod]
        public void TestRemoveCard()
        {
            Player player = new Player("Adam", 1000);
            Deck deck = new Deck("talia", player);

            Card card = new Card(3, "Kowal", 200, "To jest tekst karty");
            Card card2 = new Card(32, "Kowal2", 2020, "To jest tekst karty");

            deck.AddCard(card);
            deck.AddCard(card2);

            deck.RemoveCard(card2);

            Contains(deck.Cards, card);
            DoesNotContain(deck.Cards, card2);
        }

        [TestMethod]
        public void TestCheckCompletion()
        {
            using (ShimsContext.Create())
            {
                ShimDeck.DeckCompletion = () => { return true; };
                Player player = new Player("Adam", 1000);
                Deck deck = new Deck("talia", player);

                Assert.AreNotEqual(Deck.DeckCompletion(), false);
            }
        }
    }
}
