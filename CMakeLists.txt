# CMakeList.txt: файл проекта CMake верхнего уровня; проведите глобальную конфигурацию
# и включите сюда подпроекты.
#
cmake_minimum_required (VERSION 3.8)

project ("Cmake laboratory works")
set(MY_PROJECT_VERSION 3.0.0)
message("Version: ${MY_PROJECT_VERSION}")

set(CMAKE_CXX_STANDARD 11)

# Включение горячей перезагрузки для компиляторов MSVC, если поддерживается.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()


# Включите подпроекты.
add_subdirectory ("Lababa7")
#add_subdirectory ("Lababa4")
#add_subdirectory ("Lababa8")

#silly var: $ git commit -m"Fix typo in introduction to user guide"
#pro: git commit -m "the subject" -m "the first line"$'\n'"the second line"$'\n'"the third line"
