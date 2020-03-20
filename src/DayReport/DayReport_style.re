open Css;

let dayReportContainer = style([display(table)]);

let borderSize = 2;

let buttonWidth = width(px(20 - borderSize));
let buttonBorder = color => border(px(borderSize), solid, color);

let buttonPlus =
  style([
    borderRadius(px(3)),
    display(tableCell),
    cursor(`pointer),
    buttonWidth,
    textAlign(center),
    verticalAlign(middle),
    buttonBorder(rgba(100, 100, 100, 1.)),
    backgroundColor(rgba(200, 200, 200, 1.)),
  ]);

let buttonsContainer =
  style([position(absolute), textAlign(center), marginTop(px(-17))]);

let buttonRemove = style([cursor(`pointer)]);