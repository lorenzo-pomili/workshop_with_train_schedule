open Css;

let exerciseContainer = style([display(`table)]);
let exerciseName =
  style([
    display(`tableCell),
    width(px(75)),
    verticalAlign(middle),
    paddingRight(3->px),
  ]);

let addDayReportButton =
  style([
    borderRadius(px(3)),
    display(tableCell),
    cursor(`pointer),
    textAlign(center),
    verticalAlign(middle),
  ]);

let addDayReportSpan =
  style([
    padding(px(1)),
    marginLeft(px(3)),
    border(px(1), solid, rgba(100, 100, 100, 1.)),
    backgroundColor(rgba(200, 200, 200, 1.)),
  ]);

let dayReport = style([display(tableCell)]);