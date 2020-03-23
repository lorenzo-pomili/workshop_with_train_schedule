// Entry point

[@bs.val] external document: Js.t({..}) = "document";

// We're using raw DOM manipulations here, to avoid making you read
// ReasonReact when you might precisely be trying to learn it for the first
// time through the examples later.
let style = document##createElement("style");
document##head##appendChild(style);
style##innerHTML #= ExampleStyles.style;

let makeContainer = text => {
  let container = document##createElement("div");
  container##className #= "container";

  let title = document##createElement("div");
  title##className #= "containerTitle";
  title##innerText #= text;

  let content = document##createElement("div");
  content##className #= "containerContent";

  let () = container##appendChild(title);
  let () = container##appendChild(content);
  let () = document##body##appendChild(container);

  content;
};

module MockDayReport = {
  // let mockDaySchedule: DaySchedule.t = {
  //   title: "test day schedule",
  //   exercises: [
  //     {
  //       name: Some("test exercise"),
  //       reports: [
  //         [(10., 12), (12., 8), (12., 8)],
  //         [(10., 12), (12., 8), (12., 8)],
  //         [(10., 12), (12., 8), (12., 8)],
  //       ],
  //     },
  //     {
  //       name: Some("test exercise2"),
  //       reports: [
  //         [(10., 12), (12., 8), (12., 8)],
  //         [(10., 12), (12., 8), (12., 8)],
  //         [(10., 12), (12., 8), (12., 8)],
  //       ],
  //     },
  //   ],
  // };

  [@react.component]
  let make = () => {
    let (daySchedule, setDaySchedule) = React.useState(() => mockDaySchedule);
    <DaySchedule
      daySchedule
      onDayScheduleUpdate={ds => setDaySchedule(_ => ds)}
    />;
  };
};

ReactDOMRe.render(<MockDayReport />, makeContainer("test elements")) /* )*/ /* ReactDOMRe.render*/ /*   makeContainer("Reason Using JS Using Reason")*/ /*   <ReasonUsingJSUsingReason />*/;

// All 4 examples.
// ReactDOMRe.render(
//   <BlinkingGreeting> {React.string("Hello!")} </BlinkingGreeting>,
//   makeContainer("Blinking Greeting"),
// );
//
// ReactDOMRe.render(
//   <ReducerFromReactJSDocs />,
//   makeContainer("Reducer From ReactJS Docs"),
// );
//
// ReactDOMRe.render(
//   <FetchedDogPictures />,
//   makeContainer("Fetched Dog Pictures"),
// );
//