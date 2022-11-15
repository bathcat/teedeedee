#include <random>
#include <cmath>
#include <functional>

namespace pi
{

    namespace internal
    {
        float getSize(const float x, const float y)
        {
            const auto x2 = pow(x, 2);
            const auto y2 = pow(y, 2);
            return pow(x2 + y2, 0.5);
        }

    }

    float approximatePi(std::function<float()> next)
    {
        const auto n = 100000;

        auto hits = 0;
        for (int i = 0; i < n; ++i)
        {
            const auto x = next()*2 - 1;
            const auto y = next()*2 - 1;
            const auto r = internal::getSize(x, y);
            if (r <= 1.0)
            {
                hits++;
            }
        }
        return ((float)hits / (float)n) * 4;
    }

    float approximatePi()
    {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<> rand(0.0, 1.0);
        std::function<float()> next = [&](){return rand(gen);};
        
        return approximatePi(next);
    }

}
