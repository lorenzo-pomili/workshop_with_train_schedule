open Belt;
open React;
open ReactUtils;

let updateHandler = (newSingleReport, report, index) =>
  report->List.mapWithIndex((i, sR) => {index === i ? newSingleReport : sR});

type t = list(SingleReport.t);

let newDayReport: t = [SingleReport.newSingleReport];

[@react.component]
let make = (~report: t, ~onSelection, ~inEdit, ~onReportUpdate, ~onRemove) => {
  <div onClick=onSelection className=DayReport_style.dayReportContainer>
    {inEdit
       ? <div className=DayReport_style.buttonsContainer>
           <div
             className=DayReport_style.buttonRemove onClick={_e => onRemove()}>
             <svg
               viewBox="0 0 500 500"
               style={ReactDOMRe.Style.make(~width="10px", ())}>
               <path
                 fill="#000000"
                 d="
                M100 0 L250 200 L400 0
                L500 100 L300 250 L500 400
                L400 500 L250 300 L100 500
                L0 400 L200 250 L0 100 Z
              "
               />
             </svg>
           </div>
         </div>
       : null}
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