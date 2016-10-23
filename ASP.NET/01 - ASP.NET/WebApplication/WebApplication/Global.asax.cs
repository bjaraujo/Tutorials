using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Optimization;
using System.Web.Routing;
using System.Web.Security;
using System.Web.SessionState;

namespace WebApplication
{
    public class Global : HttpApplication
    {

        public static ServiceReference1.MyServiceClient wcfClient;

        void Application_Start(object sender, EventArgs e)
        {
            // Code that runs on application startup
            RouteConfig.RegisterRoutes(RouteTable.Routes);
            BundleConfig.RegisterBundles(BundleTable.Bundles);

            wcfClient = new ServiceReference1.MyServiceClient("WSDualHttpBinding_IMyService");

        }

        void Application_End(object sender, EventArgs e)
        {

            wcfClient.Close();

        }

    }
}