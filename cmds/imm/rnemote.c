// rnemote.c
// create by doing
// add log by mudring@sjsh

inherit F_CLEAN_UP;

int help(object me);

int main(object me, string arg)
{
        string from, to;
        mapping emote;
        mapping toemote;
        int i;
        string *ks;

        if (! SECURITY_D->valid_grant(me, "(wizard)"))
                return 0;

        seteuid(getuid());

        if (! arg || sscanf(arg, "%s %s", from, to) != 2)
                return help(me);

        emote = EMOTE_D->query_emote(from);
        if (! emote || ! sizeof(emote))
                return notify_fail("û��(" + from + ")������鶯�ʡ�\n");

        if ((toemote = EMOTE_D->query_emote(to)) && sizeof(toemote))
                return notify_fail("���鶯��(" + to + ")�Ѿ����ڣ����ܸĳɸ����֡�\n");

        EMOTE_D->set_emote(to, emote);
        EMOTE_D->delete_emote(from);
        write(sprintf("���鶯��(%s)����Ϊ(%s)��\n", from, to));
        log_file("cmds/edemote",
                sprintf("%s(%s) rnemote %s to %s on %s.\n", 
                me->name(1), geteuid(me), from, to, ctime(time()) ) );

        return 1;
}

int help(object me)
{
        write(@HELP
ָ���ʽ : rnemote <from> <to>

�����ԭ��Ϊ <from> �� emote �ĳ�����Ϊ <to> ���� emote��
ע�⣺ԭ�ȱ��벻�ܴ�����Ϊ <to> �ı��鶯�ʡ�

���ڱ��鶯�ʻ��ڰ汾ͬ��ʱ���£����ֻ�а汾����վ����ܹ�ʹ
��������

see also��edemote��cpemote
HELP );
        return 1;
}

