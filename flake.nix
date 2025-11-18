{
  description = "A Nix Flake providing a development environment for Chisel";

  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-25.05";
    flake-utils.url = "github:numtide/flake-utils";
  };

  outputs = { self, nixpkgs, flake-utils, ... }:
    flake-utils.lib.eachDefaultSystem (system:
      let
        pkgs = import nixpkgs { inherit system; };
        packages = with pkgs; [
          mill
          verilator
          circt
          gtkwave
          python3
        ];
      in {
        devShells = {
          default = pkgs.mkShell { name = "chisel"; inherit packages; };
        };
      });
}
