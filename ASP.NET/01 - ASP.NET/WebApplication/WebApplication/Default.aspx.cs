using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace WebApplication
{
    public partial class _Default : Page
    {
        
        public string googleValue;

        protected void Page_Load(object sender, EventArgs e)
        {

            googleValue = "Google stock value is: " + Global.wcfClient.GetStockValue("GOOG");

        }
    }
}