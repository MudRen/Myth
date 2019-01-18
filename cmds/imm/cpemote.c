// cpemote.c
// created by doing
//add log by mudring@sjsh

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
                return notify_fail("���鶯��(" + to + ")�Ѿ����ڣ����ܸ��ǡ�\n");

        toemote = allocate_mapping(sizeof(emote));
        ks = keys(emote);
        for (i = 0; i < sizeof(ks); i++)
                toemote[ks[i]] = emote[ks[i]];

        EMOTE_D->set_emote(to, toemote);
        printf("���鶯��(%s)���Ƶ���(%s)��\n", from, to);
        log_file("cmds/edemote",
                sprintf("%s(%s) cpemote %s to %s on %s.\n", 
                me->name(1), geteuid(me), from, to, ctime(time()) ) );

        return 1;
}

int help(object me)
{
        write(@HELP
ָ���ʽ : cpemote <from> <to>

������ԭ��Ϊ <from> �ı��鶯�ʸ��Ƴ�Ϊ����Ϊ <to> ���±�
�鶯�ʡ�ע�⣺ԭ�ȱ��벻�ܴ�����Ϊ <to> �ı��鶯�ʣ��ò�����
�ܸ���ԭ���Ѿ����ڵı��鶯�ʡ�

���ڱ��鶯�ʻ��ڰ汾ͬ��ʱ���£����ֻ�а汾����վ����ܹ�ʹ
��������

see also��edemote��rnemote
HELP );
        return 1;
}

