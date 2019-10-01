open Revery;
open Revery.UI;
open Revery.UI.Components;

let component = React.component("CatButton");

let createElement =
    (~children as _: list(React.syntheticElement), ~handleClick, ()) =>
  component(hooks => {
    let wrapperStyle =
      Style.[
        backgroundColor(Colors.salmon),
        border(~width=2, ~color=Colors.salmon),
        marginTop(32),
        alignSelf(`FlexStart),
      ];

    let textHeaderStyle =
      Style.[
        color(Colors.white),
        fontFamily("Roboto-Regular.ttf"),
        fontSize(18),
      ];

    (
      hooks,
      <Clickable onClick=handleClick>
        <View style=wrapperStyle>
          <Padding padding=12>
            <Text
              style=textHeaderStyle
              text="I did not! Tell me another one!"
            />
          </Padding>
        </View>
      </Clickable>,
    );
  });
