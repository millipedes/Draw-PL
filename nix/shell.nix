{ pkgs ? import <nixpkgs> {} }:

let
  cmake = pkgs.cmake;
in

pkgs.mkShell {
  name = "myproject-shell";
  buildInputs = [
    pkgs.libpng
    pkgs.freetype
    pkgs.flex
    pkgs.bison
    cmake
    pkgs.gcc
  ];
}
