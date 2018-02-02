unit Unit1;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, ExtCtrls, StdCtrls;

type
  TForm1 = class(TForm)
    btnStart: TButton;
    timer: TTimer;
    lblCounter: TLabel;
    procedure btnStartClick(Sender: TObject);
    procedure timerTimer(Sender: TObject);
    procedure FormMouseDown(Sender: TObject; Button: TMouseButton;
      Shift: TShiftState; X, Y: Integer);
    procedure FormCreate(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  Form1: TForm1;
  x1, y1 : integer;
  counter : integer;
  clickCounter : integer;
  showCounter : integer;
  b : boolean;

implementation

{$R *.dfm}


procedure TForm1.btnStartClick(Sender: TObject);
begin
timer.Enabled:= true;
lblCounter.Caption := '0';
counter := 0;
showCounter := 0;
clickCounter := 0;
btnStart.Caption := 'Заного';
end;

procedure TForm1.timerTimer(Sender: TObject);
var
  sz : integer;
begin
  if (showCounter >= 10) then
    begin
      canvas.Brush.Color := clWhite;
      canvas.Pen.Color := clWhite;
      canvas.Rectangle(0, 0, 500, 500);
      timer.Enabled:= false;
      MessageBox(handle,
       PChar('Попаданий:' +
              inttostr(counter) +
              #13#10'Выстрелов:' +
              inttostr(clickCounter) +
              #13#10'Процент попаданий: ' +
              inttostr(counter * 100 div clickCounter) +
              '%' +
              #13#10'-----------------' +
              #13#10'Количество баллов: ' +
              inttostr(counter * 10 - clickCounter * 1) +
              #13#10'Макисмум баллов - 100'),
       PChar('ГХаме овер'),
       MB_OK + MB_ICONINFORMATION);
       BtnStart.Caption:= 'Старт';
    end
  else
    begin
      b := false;
      showCounter := showCounter + 1;
      canvas.Brush.Color := clWhite;
      canvas.Pen.Color := clWhite;
      canvas.Rectangle(0, 0, 500, 500);
      canvas.Pen.Color := clBlack;
      canvas.Brush.Color := clRed;
      sz:= 50;
      x1 := random(450);
      y1 := random(450);
      canvas.Ellipse(x1, y1, x1 + sz, y1 + sz);
    end;
end;




procedure TForm1.FormMouseDown(Sender: TObject; Button: TMouseButton;
  Shift: TShiftState; X, Y: Integer);
begin
  clickCounter := clickCounter + 1;
  if (b = false) and ((X >= x1) and (X <= x1 + 50)) and ((Y >= y1) and (Y <= y1 + 50)) then
    begin
      b := true;
      counter:= counter + 1;
      lblCounter.Caption := inttostr(counter);
      canvas.Brush.Color := clLime;
      canvas.Ellipse(x1, y1, x1 + 50, y1 + 50);
    end;
end;

procedure TForm1.FormCreate(Sender: TObject);
begin
randomize;
clickCounter := 0;
counter := 0;
showCounter := 0;
end;

end.
