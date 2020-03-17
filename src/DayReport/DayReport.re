open Belt;
open React;
open ReactUtils;

let updateHandler = (newSingleReport, report, index) =>
  report->List.mapWithIndex((i, sR) => {index === i ? newSingleReport : sR});

type t = list(SingleReport.t);

let newDayReport = (): t => [SingleReport.newSingleReport()];

[@react.component]
let make = (~report: t, ~onSelection, ~inEdit, ~onReportUpdate) => {
  <div onClick=onSelection className=DayReport_style.dayReportContainer>
    {report->mapToElements((i, r) => {
       <SingleReport
         key={i->Int.toString}
         isLast={i == report->List.length - 1}
         data=r
         inEdit
         onDataUpdate={x => x->updateHandler(report, i)->onReportUpdate}
       />
     })}
    {inEdit
       ? <div
           className=DayReport_style.buttonPlus
           onClick={_ => onReportUpdate(report @ [(0., 0)])}>
           <span> "+"->s </span>
         </div>
       : null}
  </div>;
};