object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 602
  ClientWidth = 901
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 265
    Height = 602
    Align = alLeft
    TabOrder = 0
    object GroupBox1: TGroupBox
      Left = 0
      Top = 0
      Width = 260
      Height = 305
      Caption = 'input control'
      TabOrder = 0
      object Label1: TLabel
        Left = 24
        Top = 40
        Width = 14
        Height = 13
        Caption = 'n='
      end
      object Label2: TLabel
        Left = 13
        Top = 81
        Width = 69
        Height = 13
        Caption = 'range(w(e)) ='
      end
      object Label3: TLabel
        Left = 13
        Top = 132
        Width = 36
        Height = 13
        Caption = 'w(e) = '
      end
      object Label4: TLabel
        Left = 16
        Top = 104
        Width = 42
        Height = 13
        Caption = 'if w(e) >'
      end
      object Label5: TLabel
        Left = 3
        Top = 154
        Width = 62
        Height = 13
        Caption = 'source no. ='
      end
      object Label6: TLabel
        Left = 24
        Top = 16
        Width = 39
        Height = 13
        Caption = 'G=(V.E)'
      end
      object Label7: TLabel
        Left = 56
        Top = 62
        Width = 26
        Height = 13
        Caption = 'n<30'
      end
      object Edit1: TEdit
        Left = 55
        Top = 37
        Width = 121
        Height = 21
        TabOrder = 0
        Text = '10'
      end
      object Edit2: TEdit
        Left = 88
        Top = 73
        Width = 121
        Height = 21
        TabOrder = 1
        Text = '500'
      end
      object Edit3: TEdit
        Left = 64
        Top = 100
        Width = 121
        Height = 21
        TabOrder = 2
        Text = '120'
      end
      object Button1: TButton
        Left = 54
        Top = 215
        Width = 155
        Height = 26
        Caption = 'Generate G'
        TabOrder = 3
        OnClick = Button1Click
      end
      object Edit4: TEdit
        Left = 64
        Top = 127
        Width = 121
        Height = 21
        TabOrder = 4
        Text = '99999'
      end
      object Edit5: TEdit
        Left = 71
        Top = 154
        Width = 121
        Height = 21
        TabOrder = 5
        Text = '0'
      end
    end
    object GroupBox2: TGroupBox
      Left = 0
      Top = 280
      Width = 264
      Height = 377
      Caption = 'shortest path algorithm'
      TabOrder = 1
      object Button2: TButton
        Left = 64
        Top = 81
        Width = 153
        Height = 33
        Caption = 'Single Source All Destination'
        TabOrder = 0
        OnClick = Button2Click
      end
      object Button3: TButton
        Left = 71
        Top = 120
        Width = 121
        Height = 34
        Caption = 'All Pairs'
        TabOrder = 1
        OnClick = Button3Click
      end
      object Button5: TButton
        Left = 71
        Top = 160
        Width = 121
        Height = 33
        Caption = 'Transitive Closure'
        TabOrder = 2
        OnClick = Button5Click
      end
    end
  end
  object Panel2: TPanel
    Left = 265
    Top = 0
    Width = 636
    Height = 602
    Align = alClient
    Caption = 'Panel2'
    TabOrder = 1
    object PageControl1: TPageControl
      Left = 1
      Top = 1
      Width = 634
      Height = 600
      ActivePage = TabSheet1
      Align = alClient
      TabOrder = 0
      object TabSheet1: TTabSheet
        Caption = 'solution'
        object Memo1: TMemo
          Left = 0
          Top = 0
          Width = 626
          Height = 572
          Align = alClient
          Lines.Strings = (
            'Memo1')
          TabOrder = 0
        end
      end
      object TabSheet2: TTabSheet
        Caption = 'graph in adjacent matrix'
        ImageIndex = 1
        ExplicitLeft = 0
        ExplicitTop = 0
        ExplicitWidth = 456
        ExplicitHeight = 535
        object StringGrid1: TStringGrid
          Left = 0
          Top = 0
          Width = 626
          Height = 572
          Align = alClient
          TabOrder = 0
          ExplicitWidth = 456
          ExplicitHeight = 535
        end
      end
      object TabSheet3: TTabSheet
        Caption = 'all pair table'
        ImageIndex = 2
        ExplicitLeft = 0
        ExplicitTop = 0
        ExplicitWidth = 456
        ExplicitHeight = 535
        object StringGrid2: TStringGrid
          Left = 0
          Top = 0
          Width = 626
          Height = 572
          Align = alClient
          TabOrder = 0
          ExplicitWidth = 456
          ExplicitHeight = 535
        end
      end
      object TabSheet4: TTabSheet
        Caption = 'SSAD solution'
        ImageIndex = 3
        ExplicitLeft = 0
        ExplicitTop = 0
        ExplicitWidth = 456
        ExplicitHeight = 535
        object StringGrid3: TStringGrid
          Left = 0
          Top = 0
          Width = 626
          Height = 572
          Align = alClient
          TabOrder = 0
          ExplicitWidth = 456
          ExplicitHeight = 535
        end
      end
      object TabSheet5: TTabSheet
        Caption = 'Transitive Closure'
        ImageIndex = 4
        ExplicitLeft = 0
        ExplicitTop = 0
        ExplicitWidth = 456
        ExplicitHeight = 535
        object StringGrid4: TStringGrid
          Left = 0
          Top = 0
          Width = 626
          Height = 572
          Align = alClient
          TabOrder = 0
          ExplicitWidth = 456
          ExplicitHeight = 535
        end
      end
      object TabSheet6: TTabSheet
        Caption = 'SSAD table'
        ImageIndex = 5
        ExplicitLeft = 0
        ExplicitTop = 0
        ExplicitWidth = 456
        ExplicitHeight = 535
        object StringGrid5: TStringGrid
          Left = 0
          Top = 0
          Width = 626
          Height = 572
          Align = alClient
          TabOrder = 0
          OnDrawCell = StringGrid5DrawCell
          ExplicitWidth = 456
          ExplicitHeight = 535
        end
      end
    end
  end
end
