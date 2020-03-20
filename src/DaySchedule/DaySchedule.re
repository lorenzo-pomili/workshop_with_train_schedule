open Belt;
open ReactUtils;

type t = {
  title: string,
  exercises: list(Exercise.t),
};

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
  </div>;
};