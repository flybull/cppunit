
#pragma once

#include <map>
#include <functional>
#include <string>

class impl {
public:
	struct demo {
    	demo(std::string name,
            std::function<void(void)> finit,
            std::function<void(void)> fstart,
            std::function<void(void)> fjoin,
            std::function<void(void)> fstop,
            std::function<void(void)> funinit):
        	name(name), finit(finit), fstart(fstart), fjoin(fjoin), fstop(fstop),funinit(funinit)
    	{
        	impl::instance().regist(*this);
    	}
    	std::string name;
    	std::function<void(void)>  finit;
    	std::function<void(void)>  fstart;
    	std::function<void(void)>  fjoin;
    	std::function<void(void)>  fstop;
    	std::function<void(void)>  funinit;
	};

	inline static impl& instance() {
		static impl self;
		return self;
	}
	inline void regist(const demo& it) {
		map.insert(std::pair<std::string, demo>(it.name, it));
	}
	inline const std::map<std::string, demo>& all() {
		return map;
	}

private:
	std::map<std::string, demo> map;
};

#define impl_step($step) for (auto it : impl::instance().all()) { if(it.second.f##$step) it.second.f##$step();}
