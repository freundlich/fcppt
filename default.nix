let pkgs = import <nixpkgs> {};
    stdenv = pkgs.gcc9Stdenv;
    metal = stdenv.mkDerivation rec {
      pname = "metal";
      version = "2.1.1";

      src = pkgs.fetchFromGitHub {
        owner = "brunocodutra";
        repo = "metal";
        rev = "v${version}";
        sha256 = "07n1aqyaixbd66l24km5ip3pkmidkx9m3saygf7cfp6vvbgmi42l";
      };

      nativeBuildInputs = [ pkgs.cmake ];
      buildInputs = [  ];

      cmakeFlags = [ ];

      enableParallelBuilding = true;
    };
in stdenv.mkDerivation rec {
  name = "fcppt-master";

  src = ./.;

  nativeBuildInputs = [ pkgs.cmake ];
  buildInputs = [ pkgs.boost pkgs.catch2 metal ];

  cmakeFlags = [ "-DCMAKE_SKIP_BUILD_RPATH=false" "-DENABLE_BOOST=true" "-DENABLE_EXAMPLES=true" "-DENABLE_CATCH=true" "-DENABLE_TEST=true" ];

  enableParallelBuilding = true;

  doCheck = true;

  meta = with pkgs.stdenv.lib; {
    description = "Freundlich's C++ toolkit";
    longDescription = ''
      Freundlich's C++ Toolkit (fcppt) is a collection of libraries that aim to improve general C++ code through better typing and functional programming.
    '';
    homepage = https://fcppt.org;
    license = licenses.boost;
    maintainers = with maintainers; [ pmiddend ];
    platforms = platforms.linux;
  };
}
