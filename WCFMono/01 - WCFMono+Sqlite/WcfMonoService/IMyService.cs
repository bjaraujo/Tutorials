using System;
using System.ServiceModel;
using System.ServiceModel.Web;

namespace WcfMonoService
{
    [ServiceContract]
    public interface IMyService
    {
		[OperationContract]
		void PopulateData();

		[OperationContract, WebGet]
		double GetStockValue(string aSymbol);
    }
}

