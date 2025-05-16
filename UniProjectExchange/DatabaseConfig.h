#pragma once

using namespace System;

public ref class DatabaseConfig abstract sealed
{
public:
    static initonly String^ ConnectionString =
        "Data Source=PANI\\SQLEXPRESS;Initial Catalog=UniProjectExchange;Integrated Security=True;TrustServerCertificate=True;";
};