<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="Test.aspx.cs" Inherits="Test.Test" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
    <div>
    
    </div>
        <asp:GridView ID="GridView1" runat="server" AutoGenerateColumns="False" DataSourceID="SqlDataSource1">
            <Columns>
                <asp:BoundField DataField="s_id" HeaderText="s_id" SortExpression="s_id" />
                <asp:BoundField DataField="s_fname" HeaderText="s_fname" SortExpression="s_fname" />
                <asp:BoundField DataField="s_lname" HeaderText="s_lname" SortExpression="s_lname" />
            </Columns>
        </asp:GridView>
        <asp:SqlDataSource ID="SqlDataSource1" runat="server" ConnectionString="<%$ ConnectionStrings:StudentConnectionString %>" SelectCommand="SELECT * FROM [student_detail]"></asp:SqlDataSource>
    </form>
</body>
</html>
