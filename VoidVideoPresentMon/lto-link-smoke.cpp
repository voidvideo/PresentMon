#include "PresentData/PresentMonTraceConsumer.hpp"
#include "PresentData/PresentMonTraceSession.hpp"

int main()
{
    PMTraceConsumer consumer{16};
    PMTraceSession session;
    session.mPMConsumer = &consumer;
    return session.mPMConsumer == &consumer ? 0 : 1;
}
