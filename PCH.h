#pragma once

#include "RE/Skyrim.h"
#include "SKSE/SKSE.h"

//we are not making nasa sw, so stfu
#pragma warning( disable : 4100 ) 
#pragma warning( disable : 4244 )

using namespace std::literals;

#define PAPYRUSFUNCHANDLE RE::StaticFunctionTag*
#define PAPYRUSUNHOOKFPSALL 0

#define ROUND(x) std::lround(x)

#define USETASK 1

//1=ON,0=OFF
#define LOGGING 1

#if(LOGGING != 0)
    #include <spdlog/sinks/basic_file_sink.h>
    #define LOG(...)    {if (IWW::Config::GetSingleton()->GetVariable<int>("General.Logging",1) >= 2) SKSE::log::info(__VA_ARGS__);}
    #define WARN(...)   {if (IWW::Config::GetSingleton()->GetVariable<int>("General.Logging",1) >= 1) SKSE::log::warn(__VA_ARGS__);}
    #define ERROR(...)  {SKSE::log::error(__VA_ARGS__);}
    #define DEBUG(...)  {SKSE::log::debug(__VA_ARGS__);}
#else
    #define LOG(...)  {}
    #define ERROR(...){}
    #define ERROR(...){}
    #define DEBUG(...){}
#endif

#define SINGLETONHEADER(cname)                          \
        public:                                         \
            cname(cname &) = delete;                    \
            void operator=(const cname &) = delete;     \
            static cname* GetSingleton();               \
        protected:                                      \
            cname(){}                                   \
            ~cname(){}                                  \
            static cname* _this;

#define SINGLETONBODY(cname)                            \
        cname * cname::_this = new cname;               \
        cname * cname::GetSingleton(){return _this;}

