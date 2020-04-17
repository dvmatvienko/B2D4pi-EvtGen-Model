#ifndef EVTSTATUS_HH
#define EVTSTATUS_HH

class EvtStatus {
  public:
    static void setRejectFlag()
    {
        int* temp = rejectFlag();
        *temp = 1;
        return;
    }
    static void initRejectFlag()
    {
        int* temp = rejectFlag();
        *temp = 0;
        return;
    }
    static int* rejectFlag()
    {
        static int rejectEvent = 0;
        return &rejectEvent;
    }
    static int getRejectFlag()
    {
        int* temp = rejectFlag();
        return *temp;
    }
};

#endif
