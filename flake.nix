{
  description = "An environment for the shwompEngine";

  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs/nixos-unstable";
  };

  outputs = { self , nixpkgs ,... }: let
    system = "x86_64-linux";
    pkgs = nixpkgs.legacyPackages.${system};
  in {
    devShells."${system}".default = pkgs.callPackage ./shell.nix { inherit pkgs; };

    packages.${system}.default = let 
      excecutable = "engine";      # CHANGE THIS TO YOUR EXCECUTABLE NAME
    in pkgs.stdenv.mkDerivation {
        name = excecutable;
        description = "A minimalistic game engine";
        src = ./.; 

        buildInputs = with pkgs; [
          gcc
          gnumake
        ] ++ raylibPackages;

        buildPhase = ''
        mkdir -p build
        make -j3
        '';

        installPhase = ''
        mkdir -p $out/bin
        install -t $out/bin build/${excecutable}
        '';
      };
  };
}
