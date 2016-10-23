using System;

using SQLite;

namespace WcfMonoService
{
	[Table("Items")]
	public class Stock {
		[PrimaryKey, AutoIncrement, Column("_id")]
		public int Id { get; set; }
		[MaxLength(8)]
		public string Symbol { get; set; }
		public double Value { get; set; }
	}
}

