open Css;

let borderColor = rgba(0, 0, 0, 1.);

let singleReport = style([display(inlineBlock)]);
let withNeighboring = style([borderRight(px(1), solid, borderColor)]);

let reportInput = style([width(px(22))]);
let singleReportTop = style([borderBottom(px(1), solid, borderColor)]);
let singleReportBottom = style([]);
let lastOfReport =
  style([borderRight(px(3), solid, borderColor), marginRight(px(3))]);

let notInEdit = style([cursor(`pointer)]);