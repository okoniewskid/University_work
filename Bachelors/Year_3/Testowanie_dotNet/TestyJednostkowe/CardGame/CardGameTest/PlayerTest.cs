using System;
using CardGame;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace CardGameTest
{
    [TestClass]
    public class PlayerTest
    {
        public TestContext TestContext { get; set; }

        [TestMethod]
        public void TestBuyCard()
        {
            int startPoints = 900;
            int cardCost = 500;
            int expected = 400;
            Player player = new Player("Adam", startPoints);

            player.BuyCard(cardCost);

            Assert.AreEqual(expected, player.Points, 0, "Something wrong");
        }

        [TestMethod]
        [DeploymentItem("CardGameTest\\TestData.xml")]
        [DataSource("Microsoft.VisualStudio.TestTools.DataSource.XML",
                   @"C:\Users\dokoniewski\Documents\Visual Studio 2015\Projects\CardGame\CardGameTest\\TestData.xml",
                   "add",
                    DataAccessMethod.Sequential)]
        public void TestBuyCardDb()
        {
            var target = new Player();

            double currency = Convert.ToDouble(TestContext.DataRow["firstNumber"]);
            double tax = Convert.ToDouble(TestContext.DataRow["secondNumber"]);
            double expected = Convert.ToDouble(TestContext.DataRow["expected"]);

            double actual = target.BuyPoints(currency, tax);

            Assert.AreEqual(expected, actual, "x:<{0}> y:<{1}>",new object[] { currency, tax });
        }

        [TestMethod]
        [ExpectedException(typeof(System.OverflowException))]
        public void TestBuyCardWithNoPoints()
        {
            int startPoints = 0;
            int cardCost = 700;

            Player player = new Player("Adam", startPoints);
            player.BuyCard(cardCost);
        }

        [TestMethod]
        public void TestSellCard()
        {
            int startPoints = 1500;
            int cardCost = 700;
            int expected = 2200;

            Player player = new Player("Adam", startPoints);
            player.SellCard(cardCost);

            Assert.AreEqual(expected, player.Points, 0, "Something wrong");
        }

        [TestMethod]
        public void BuyPoints()
        {
            IAccount account =
                new CardGame.Fakes.StubIAccount()
                {
                    BuyPointsDoubleDouble = (double a, double b) =>
                    {
                        return a - b;
                    }
                };
            
            Assert.AreEqual(5, account.BuyPoints(8,3));
            Assert.AreEqual(50.50, account.BuyPoints(51, 0.50));
        }
    }
}
