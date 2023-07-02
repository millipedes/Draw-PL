{ pkgs ? import <nixpkgs> {} }:

let
  cmake = pkgs.cmake;
in

pkgs.mkShell {
  name = "myproject-shell";
  buildInputs = [
    pkgs.libpng
    pkgs.freetype
    cmake
    pkgs.gcc
  ];
}
