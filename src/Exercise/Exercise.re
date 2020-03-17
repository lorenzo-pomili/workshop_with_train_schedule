open Belt;
open React;
open ReactUtils;

let updateHandler = (newReport, reports, index) =>
  reports->List.mapWithIndex((i, sR) => {index === i ? newReport : sR});

type t = {
  name: string,
  reports: list(DayReport.t),
};

let onAddReport = (exercise, setSelectedReport, onExercisUpdate) => {
  setSelectedReport(_s => Some(exercise.reports->List.length));
  onExercisUpdate({
    ...exercise,
    reports: exercise.reports @ [DayReport.newDayReport()],
  });
};

[@react.component]
let make = (~exercise: t, ~onExercisUpdate) => {
  let (selectedReport, setSelectedReport) = useState(() => None);

  <div className=Exercise_style.exerciseContainer>
    <div className=Exercise_style.exerciseName> exercise.name->s </div>
    {exercise.reports
     ->mapToElements((i, report) => {
         <div key={i->Int.toString} className=Exercise_style.dayReport>
           <DayReport
             report
             inEdit={selectedReport == Some(i)}
             onSelection={_e => setSelectedReport(_s => Some(i))}
             onReportUpdate={newReport =>
               onExercisUpdate({
                 ...exercise,
                 reports: newReport->updateHandler(exercise.reports, i),
               })
             }
           />
         </div>
       })}
    <div
      className=Exercise_style.addDayReportButton
      onClick={_e =>
        onAddReport(exercise, setSelectedReport, onExercisUpdate)
      }>
      <span className=Exercise_style.addDayReportSpan>
        <svg
          viewBox="0 0 500 500"
          style={ReactDOMRe.Style.make(~width="10px", ())}>
          <path fill="#000000" d="M500 250 L0 500 L0 0 Z" />
        </svg>
      </span>
    </div>
  </div>;
};