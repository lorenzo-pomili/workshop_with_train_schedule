open Belt;
open Utils;
open ReactUtils;

type t = (float, int);

let newSingleReport = (): t => (0., 0);

[@react.component]
let make = (~data: t, ~inEdit, ~isLast, ~onDataUpdate) => {
  let (w, r) = data;

  <div
    className={
      SingleReport_style.singleReport
      ++ " "
      ++ {
        isLast
          ? SingleReport_style.lastOfReport
          : SingleReport_style.withNeighboring;
      }
      ++ {
        inEdit ? "" : " " ++ SingleReport_style.notInEdit;
      }
    }>
    <div className=SingleReport_style.singleReportTop>
      {inEdit
         ? <input
             value={w->Float.toString}
             className=SingleReport_style.reportInput
             onChange={e =>
               (e->getFormValue(Float.fromString) =?= 0., r)->onDataUpdate
             }
           />
         : {
           w->Float.toString->s;
         }}
    </div>
    <div className=SingleReport_style.singleReportBottom>
      {inEdit
         ? <input
             value={r->Int.toString}
             className=SingleReport_style.reportInput
             onChange={e =>
               (w, e->getFormValue(Int.fromString) =?= 0)->onDataUpdate
             }
           />
         : {
           r->Int.toString->s;
         }}
    </div>
  </div>;
};