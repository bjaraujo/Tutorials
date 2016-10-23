using System;
using SQLite;
using NLog;

namespace WcfMonoService
{
    public class MyService : IMyService
    {

		private static Logger logger = LogManager.GetCurrentClassLogger();

		string dbPath = "data.db";

		public void PopulateData()
		{

			try
			{

				var db = new SQLiteConnection (dbPath);

				db.CreateTable<Stock> ();

				if (db.Table<Stock> ().Count() == 0) {
					// only insert the data if it doesn't already exist
					Stock newStock = new Stock ();
					newStock.Symbol = "AAPL";
					newStock.Value = 540.23;
					db.Insert (newStock);
					newStock = new Stock ();
					newStock.Symbol = "GOOG";
					newStock.Value = 834.02;
					db.Insert (newStock);
					newStock = new Stock ();
					newStock.Symbol = "MSFT";
					newStock.Value = 54.97;
					db.Insert (newStock);
				}

				db.Close ();

			}
			catch (Exception ex)
			{
				logger.Error(ex.Message);
			}

		}

		public double GetStockValue(string aSymbol)
        {

			double aValue = 0;

			try
			{

				var db = new SQLiteConnection (dbPath);

				var aQuery = db.Table<Stock>().Where(s => s.Symbol.Equals(aSymbol));

				Stock aStock = aQuery.FirstOrDefault();

				db.Close ();

				if (aStock != null)
					aValue = aStock.Value;
				else
					logger.Warn("Symbol not found!");

			}
			catch (Exception ex)
			{
				logger.Error(ex.Message);
			}

			return aValue;

        }
    }
}

