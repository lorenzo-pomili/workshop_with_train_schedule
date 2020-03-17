open Belt;
open React;

let getFormString: ReactEvent.Form.t => option(string) =
  e => e->ReactEvent.Form.currentTarget##value->Js.nullToOption;

let getFormValue = (e, converter) =>
  e->getFormString->Option.flatMap(converter);

// let getFormValue = e => e->ReactEvent.Form.currentTarget

let s = string;

let mapToElements = (l, mapFun) =>
  List.mapWithIndex(l, mapFun)->List.toArray->array;
