# revery-quick-start

---

**Clone and run for a quick way to see Revery in action.**

This is a minimal Revery application to get you started.

The most important file here is:

- `app.re` - This is the core application code, responsible for **creating a window** and **rendering**.

A Revery application also needs these files:

- `esy.json` - [esy configuration]() - lists the OCaml/Reason dependencies.
- `dune` / `dune-project` - build configuration files used by [Dune](https://dune.readthedocs.io/en/latest/).
- `.opam` - metadata used by the build system.

### Build

- `esy install`
- `esy build`

The binary will be in the `_build/install/default/bin` - you can run it like:

- `_build/install/default/bin/App`

or with esy:

- `esy start`

### Releasing

To create packages for distribution, follow these steps:

- `npm install -g revery-packager`

From the `revery-quick-start` folder, run:

- `revery-packager`

Once complete, there will be application packages available in the `_release` folder.

### Resources

- Check out the [official reason docs](https://reasonml.github.io/docs/en/what-and-why) to learn more about reason
- Visit the Reason [discord channel](https://discordapp.com/invite/reasonml) and say hi!

### Next steps

Here's a few challenges to see if you've got the basics:

- Add an Image component (Hint - you'll need to add the resource to the `dune` file, too)
- Respond to user input
- Create a frameless window

### License

[MIT License](LICENSE)

Revery-quick-start also includes some assets (font files, etc) that have their own licensing terms. For these, see [ThirdPartyLicenses.txt](ThirdPartyLicenses.txt)
