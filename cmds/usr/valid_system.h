// system busy.
int valid_system(object me)
{
    if (!wizardp(me) && userp(me))
    {
        if (uptime() - me->query_temp("system_busy") < 5)
            return notify_fail("ϵͳæ�����Ժ�\n");
    }
    me->set_temp("system_busy", uptime());
    return 1;
}
