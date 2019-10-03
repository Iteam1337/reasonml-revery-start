open Revery;
open Revery.UI;
open Revery.UI.Components;

[@deriving yojson({strict: false})]
type cat = {text: string};

let component = React.component("Cat");

let createElement =
    (~children as _: list(React.syntheticElement), ~catCount: int, ()) =>
  component(hooks => {
    let (text, setText, hooks) = React.Hooks.state("Loading...", hooks);

    let fetchNewCat = () => {
      Fetch.(
        fetch("https://cat-fact.herokuapp.com/facts/random", ())
        |> Lwt.map(
             fun
             | Ok({Response.body, _}) =>
               Response.Body.toString(body)
               |> Yojson.Safe.from_string
               |> cat_of_yojson
               |> (
                 fun
                 | Ok({text}) => text
                 | Error(_e) => "What! No cat text?!"
               )
               |> setText
             | Error(_) => setText("That's an error"),
           )
      );
    };

    let hooks =
      Hooks.effect(
        If((!==), catCount),
        () => {
          fetchNewCat() |> ignore;

          None;
        },
        hooks,
      );

    let hooks =
      Hooks.effect(
        OnMount,
        () => {
          fetchNewCat() |> ignore;

          None;
        },
        hooks,
      );

    let textHeaderStyle =
      Style.[
        color(Colors.salmon),
        fontFamily("Roboto-BoldItalic.ttf"),
        fontSize(18),
        marginBottom(32),
      ];

    let textFactStyle =
      Style.[
        color(Colors.black),
        fontFamily("Roboto-Regular.ttf"),
        fontSize(24),
      ];

    let quoteContainerStyle = Style.[maxWidth(800)];

    (
      hooks,
      <View style=quoteContainerStyle>
        <Text style=textHeaderStyle text="Did you know?" />
        <Text style=textFactStyle text />
      </View>,
    );
  });
