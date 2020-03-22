open Belt;
open Utils;
open ReactUtils;

type t = {
  title: string,
  exercises: list(Exercise.t),
};

let onAddExercise = (onDayScheduleUpdate, daySchedule) =>
  confirm("Are you sure to add new exercise?")
    ? onDayScheduleUpdate({
        ...daySchedule,
        exercises: daySchedule.exercises @ [Exercise.newExercise],
      })
    : ();

[@react.component]
let make = (~daySchedule: t, ~onDayScheduleUpdate) => {
  <div>
    <div> daySchedule.title->s </div>
    {daySchedule.exercises
     ->mapToElements((i, exercise) => {
         <div
           key={i->Int.toString} className=DaySchedule_style.exerciseContainer>
           <Exercise
             exercise
             onExercisUpdate={newExercise =>
               onDayScheduleUpdate({
                 ...daySchedule,
                 exercises:
                   daySchedule.exercises
                   ->List.mapWithIndex((idx, e) => {
                       idx === i ? newExercise : e
                     }),
               })
             }
           />
         </div>
       })}
    <div className=DaySchedule_style.buttonsContainer>
      <div
        className=DaySchedule_style.buttonsAddExercise
        onClick={_e => onAddExercise(onDayScheduleUpdate, daySchedule)}>
        <svg
          viewBox="0 0 500 300"
          style={ReactDOMRe.Style.make(~width="30px", ())}>
          <path
            fill="#000000"
            d="
                M0 0 L250 300 L500 0 Z
              "
          />
          <path
            fill="#CCCCCC"
            d="
                M10 10 L250 290 L490 10 Z
              "
          />
          <path
            fill="#000000"
            d="
                M230 25 L270 25 L270 105 L350 105
                L350 145 L270 145 L270 225 L230 225
                L230 145 L150 145 L150 105 L230 105 Z
              "
          />
        </svg>
      </div>
    </div>
  </div>;
};