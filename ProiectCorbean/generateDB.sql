IF NOT EXISTS (SELECT * FROM sys.databases WHERE name = 'OrdersDB')
BEGIN
    CREATE DATABASE OrdersDB;
    PRINT 'Database OrdersDB created successfully.';
END

USE [OrdersDB]
GO

/****** Object:  Table [dbo].[CCDependency]    Script Date: 9/7/2024 7:01:10 AM ******/
SET ANSI_NULLS ON
GO

SET QUOTED_IDENTIFIER ON
GO

CREATE TABLE [dbo].[CCDependency](
	[country] [varchar](10) NOT NULL,
	[continent] [varchar](10) NOT NULL
) ON [PRIMARY]
GO


USE [OrdersDB]
GO

/****** Object:  Table [dbo].[Clients]    Script Date: 9/7/2024 7:03:40 AM ******/
SET ANSI_NULLS ON
GO

SET QUOTED_IDENTIFIER ON
GO

CREATE TABLE [dbo].[Clients](
	[id] [int] NOT NULL,
	[name] [nvarchar](50) NOT NULL,
PRIMARY KEY CLUSTERED 
(
	[id] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO


USE [OrdersDB]
GO

/****** Object:  Table [dbo].[Orders]    Script Date: 9/7/2024 7:04:05 AM ******/
SET ANSI_NULLS ON
GO

SET QUOTED_IDENTIFIER ON
GO

CREATE TABLE [dbo].[Orders](
	[order_id] [int] NOT NULL,
	[client_id] [int] NULL,
	[order_date] [date] NOT NULL,
	[product_id] [int] NULL,
	[confirmed] [bit] NOT NULL
) ON [PRIMARY]
GO


USE [OrdersDB]
GO

/****** Object:  Table [dbo].[Products]    Script Date: 9/7/2024 7:04:34 AM ******/
SET ANSI_NULLS ON
GO

SET QUOTED_IDENTIFIER ON
GO

CREATE TABLE [dbo].[Products](
	[id] [int] NOT NULL,
	[name] [nvarchar](50) NOT NULL,
PRIMARY KEY CLUSTERED 
(
	[id] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO


USE [OrdersDB]
GO

/****** Object:  Table [dbo].[Shipments]    Script Date: 9/7/2024 7:05:00 AM ******/
SET ANSI_NULLS ON
GO

SET QUOTED_IDENTIFIER ON
GO

CREATE TABLE [dbo].[Shipments](
	[shipment_id] [int] IDENTITY(1,1) NOT NULL,
	[order_id] [int] NULL,
	[shipment_date] [date] NOT NULL,
	[ship_type] [nvarchar](20) NULL,
 CONSTRAINT [PK__Shipment__41466E59B91254EE] PRIMARY KEY CLUSTERED 
(
	[shipment_id] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO


