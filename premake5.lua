-- Define names
local solutionName = "SFML Template"
local projectName = "SFML Hello World"
local libraries = "C:/Dev/Lib"

-- Define directories
local rootDir 	= os.getcwd()
local projDir 	= rootDir .. "/" .. projectName
local outputdir = "%{cfg.buildcfg}-%{cfg.architecture}"

workspace (solutionName)
	architecture "x86_64"
	configurations { "Debug", "Release" }
	startproject (projectName)
	project (projectName)
	location (projDir)
	kind "ConsoleApp"
	language "C++"
    cppdialect "C++20"
    targetdir (rootDir .. "/bin/" .. outputdir .. "/%{prj.name}")
    objdir (rootDir .. "/bin-int/" .. outputdir .. "/%{prj.name}")
    systemversion "latest"
	
	files { 
		projDir .. "/src/**.**"
	}
	

	filter "configurations:*"
		defines { "SFML_STATIC" }
		includedirs { 
			libraries .. "/SFML-2.6*/include",
		}

		libdirs { 
			libraries .. "/SFML-2.6*/lib" 
		}

		links {
			"opengl32.lib",
			"freetype.lib",
			"winmm.lib",
			"gdi32.lib",
			"flac.lib",
			"vorbisenc.lib",
			"vorbisfile.lib",
			"vorbis.lib",
			"ogg.lib",
			"ws2_32.lib"
		}
	
	filter "configurations:Debug"
		defines { "DEBUG" }
		symbols "On"

		links {	
			"sfml-graphics-s-d.lib",
			"sfml-window-s-d.lib",
			"sfml-system-s-d.lib",
			"sfml-audio-s-d.lib",
			"sfml-network-s-d.lib"
		}

		
	filter "configurations:Release"
		defines { "NDEBUG" }
		optimize "On"
		symbols "Off"

		links {	
			"sfml-graphics-s.lib",
			"sfml-window-s.lib",
			"sfml-system-s.lib",
			"sfml-audio-s.lib",
			"sfml-network-s.lib"
		}