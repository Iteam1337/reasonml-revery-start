open Revery;
open Revery.Math;
open Revery.UI;
open Revery.UI.Components;

let init = app => {
  let _ignore = Revery.Log.listen((_, msg) => print_endline("LOG: " ++ msg));

  let win =
    App.createWindow(
      app,
      ~createOptions=WindowCreateOptions.create(~width=1024, ~height=640, ()),
      "Cat Fact App!",
    );

  let element = <Main />;

  let _ignore = Revery_Lwt.startEventLoop();

  let _ignore = UI.start(win, element);
  ();
};

App.start(init);
