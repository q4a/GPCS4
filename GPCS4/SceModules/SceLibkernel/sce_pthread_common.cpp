#include "sce_libkernel.h"
#include "Emulator/TLSHandler.h"

LOG_CHANNEL(SceModules.SceLibkernel.pthreadcommon);

#include "sce_pthread_common.h"

MapSlot<pthread_t, isEmptyPthread, isEqualPthread> g_threadSlot(SCE_THREAD_COUNT_MAX);


bool isEmptyPthread(const pthread_t& pt)
{
#ifdef GPCS4_WINDOWS
	return pt.p == NULL && pt.x == 0;
#else
	LOG_FIXME("Not implemented");
	return false;
#endif  //GPCS4_WINDOWS
}

bool isEqualPthread(const pthread_t& lhs, const pthread_t& rhs)
{
#ifdef GPCS4_WINDOWS
	return lhs.p == rhs.p && lhs.x == rhs.x;
#else
	LOG_FIXME("Not implemented");
	return true;
#endif  //GPCS4_WINDOWS
}


void* newThreadWrapper(void* arg)
{
	void* ret = NULL;
	SCE_THREAD_PARAM* param = (SCE_THREAD_PARAM*)arg;
	do 
	{
		if (!param)
		{
			break;
		}

		ScePthread tid = scePthreadSelf();
		LOG_DEBUG("new sce thread created %d", tid);

		PFUNC_PS4_THREAD_ENTRY pSceEntry = (PFUNC_PS4_THREAD_ENTRY)param->entry;
		ret = pSceEntry(param->arg);

		// release tls data
		TLSManager* tlsMgr = TLSManager::GetInstance();
		tlsMgr->notifyThreadExit();

		// do clear
		pthread_t emptyPt = { 0 };
		g_threadSlot.SetItemAt(tid, emptyPt);

	} while (false);
	if (param)
	{
		delete param;
	}
	return ret;
}
