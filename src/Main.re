open Revery;
open Revery.Math;
open Revery.UI;
open Revery.UI.Components;

let component = React.component("Main");

let createElement = (~children as _: list(React.syntheticElement), ()) =>
  component(hooks => {
    let (catCount, setCatCount, hooks) = React.Hooks.state(0, hooks);

    let containerStyle =
      Style.[
        backgroundColor(Colors.linen),
        position(`Absolute),
        justifyContent(`Center),
        alignItems(`Center),
        bottom(0),
        top(0),
        left(0),
        right(0),
      ];

    (
      hooks,
      <View style=containerStyle>
        <Padding padding=32>
          <Cat catCount />
          <CatButton handleClick={() => setCatCount(catCount + 1)} />
        </Padding>
      </View>,
    );
  });
