// party.c

#include <ansi.h>
#include <getconfig.h>

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

int sort_hatred(string id1, string id2, mapping hatred);
int sort_member(string id1, string id2);
int show_party_info(object me, string arg);
int show_party_member(object me, string arg);
int show_party_hatred(object me, string arg);
int dismiss_party(object me, string arg);

int main(object me, string arg)
{
        object *obs;
        string fname;
        string *args;

        if (! arg) arg = "info";
        args = explode(arg, " ");
        if (sizeof(args) > 1)
                arg = implode(args[1..<1], " ");
        else
                arg = 0;

        switch (args[0])
        {
        case "info":
                // ��ʾ���ɵ���Ϣ
                return show_party_info(me, arg);

        case "member":
                return show_party_member(me, arg);

        case "dismiss":
                return dismiss_party(me, arg);

        case "top":
                return __DIR__"top"->main(me, "party");

        case "hatred":
                // ��ʾ���ɵĳ���
                return show_party_hatred(me, arg);

        case "out":
                if (! stringp(fname = me->query("party/party_name")))
                        return notify_fail("�����ڻ�û�м����κΰ����ء�\n");

                if (me->query_temp("pending/out_party"))
                {
                        // ���ɵ������½�
                        PARTY_D->add_party_fame(fname, -PARTY_D->query_party_fame(fname) / 10);
                        CHANNEL_D->do_channel(this_object(), "rumor",
                                "��˵" + me->name(1) + "(" + me->query("id") +
                                ")���޷��ˣ��Ѿ�����" + fname + "��ȥ��");
                        me->delete_temp("pending/out_party");

                        // ������û��ڰ����е���Ϣ
                        UPDATE_D->clear_user_data(me->query("id"), "party");
                        return 1;
                }

                write("�������Ҫ���������Ľ���������������ή��" + fname + "��������\n"
                      YEL "�����ȷ���ˣ���������һ�� fparty out ���\n" NOR);
                me->set_temp("pending/out_party", 1);
                return 1;
        }

        write("��Ч�Ĳ�����\n");
        return 1;
}

// ������ҺͲ���ѡ����ɵ�����
mixed select_party(object me, string arg)
{
        string fam;
        object ob;

        if (! wizardp(me))
                // only wizard can show every party's list
                fam = 0;
        else
        if (stringp(arg) && arg != "")
        {
                if (! arrayp(PARTY_D->query("member/" + fam)))
                        fam = 0;
                else
                        fam = arg;

                if (! stringp(fam) && objectp(ob = UPDATE_D->global_find_player(arg)))
                {
                        // û�� arg ������ɣ��鿴�Ƿ��и����
                        fam = ob->query("party/party_name");
                        UPDATE_D->global_destruct_player(ob);
                        if (! stringp(fam))
                                return notify_fail("��������û�кͱ��˽�ɰ��ɡ�\n");
                }

                if (! stringp(fam))
                        return notify_fail("û�������ң����ܲ�����صİ��ɡ�\n");
        }

        if (! fam)
        {
                // select my party
                if (! stringp(fam = me->query("party/party_name")))
                        return notify_fail("�����ڻ�û�м����κΰ����ء���\n");
        }

        return fam;
}

// ��ʾ���ɵĳ���
int show_party_hatred(object me, string arg)
{
        mapping hatred;
        string fam;
        string *ids;
        mixed *data;
        string msg;
        string st;
        int count;
        int i;

        if (! stringp(fam = select_party(me, arg)))
                return 0;

        hatred = PARTY_D->query_party_hatred(fam);
        if (! mapp(hatred) || ! sizeof(hatred))
        {
                write(fam + "����û��ʲô���ˡ�\n");
                return 1;
        }

        ids = keys(hatred) - ({ 0 });
        ids = sort_array(ids, (: sort_hatred :), hatred);

        count = 0;
        msg = WHT "Ŀǰ" + fam + "�ڽ����ϵĳ�ж���\n" NOR
              HIY "��������������������������������\n" NOR;
        for (i = 0; i < sizeof(ids) && count < 30; i++)
        {
                data = hatred[ids[i]];
                if (! arrayp(data) || sizeof(data) < 2 ||
                    ! stringp(data[0]) || ! intp(data[1]))
                        continue;

                st = sprintf("%s(%s%s%s)", data[0], YEL, ids[i], NOR);
                msg += sprintf("%2d. %-34s  %s%-9d%s\n",
                               ++count, st, HIR, data[1], NOR);
        }

        msg += HIY "��������������������������������\n" NOR;
        if (i < sizeof(ids))
                msg += WHT "�����ϵĵ���̫�࣬���Ծ�����\n" NOR;
        else
                msg += WHT "Ŀǰһ����" + chinese_number(i) +
                       "�ˡ�\n" NOR;
        write(msg);
        return 1;
}

// ��ʾĳһ�������е���Ա
int show_party_member(object me, string arg)
{
        string *member;
        string id;
        object user;
        string msg;
        int n;

        if (! arg)
        {
                if (! stringp(arg = me->query("party/party_name")))
                        return notify_fail("�����ڻ�û�м����κ�һ�������ء�\n");
        }

	if (! arrayp(member = PARTY_D->query_members(arg)))
        {
                write("���ڽ�����û��(" + arg + ")����ֺš�\n");
                return 1;
        }

        if (sizeof(member) < 1)
                return notify_fail(arg + "�����˶�ϡ�䡣\n");

        if (! wizardp(me))
        {
                if (me->query("jing") < 50)
                        return notify_fail("�����ھ��񲻼ã��޷�������Щ��Ϣ��\n");

                if (me->is_busy())
                        return notify_fail("��������æ��û��ʱ�������Щ��Ϣ��\n");

                me->receive_damage("jing", 50);
                me->start_busy(3);
        }

        msg = "";
        n = 0;
        foreach (id in member)
        {
                user = UPDATE_D->global_find_player(id);
                if (! objectp(user))
                        continue;

                n++;
                msg += user->short(1) + "\n";
                UPDATE_D->global_destruct_player(user);
        }

        if (msg == "")
                return notify_fail(arg + "�����˶�ϡ�䡣\n");

        write(arg + "Ŀǰ������" + chinese_number(n) + "�ˣ�\n" + msg);
        return 1;
}

// ��ʾ�����е���Ϣ
int show_party_info(object me, string arg)
{
        string fam;
        object  ob;
        string  msg;
        string pro;
        string *member;
        string  id;

        if (! stringp(fam = select_party(me, arg)))
                return 0;

        if (fam == me->query("party/party_name"))
                pro = "��";
        else
                pro = fam;

	if (! arrayp(member = PARTY_D->query_members(fam)))
        {
                write("���ڽ�����û��(" + fam + ")����ֺš�\n");
                return 1;
        }

        if (sizeof(member) < 1)
                return notify_fail(pro + "����û��һ����Ա��\n");

        msg = pro + "����" + LOCAL_MUD_NAME() + "�İ��ɳ�Ա���У�\n\n";
        member = sort_array(member, (: sort_member :));
        foreach (id in member)
        {
                msg += sprintf(WHT "%-10s  ", id);
                if (objectp(ob = find_player(id)))
                        msg += sprintf(HIY "����   "
                                       NOR WHT "���飺" HIC "%-9d "
                                       NOR WHT "������" HIW "%-8d "
                                       NOR WHT "������" HIY "%-8d\n" NOR,
                                       ob->query("combat_exp"),
                                       ob->query("score"),
                                       ob->query("weiwang"));
                else
                        msg += HIR "������\n" NOR;
        }

        msg += sprintf("\n����%s��һ����%sλ���ɳ�Ա���ڽ����Ͼ��� %s%d%s ��������\n",
                       fam, chinese_number(sizeof(member)),
                       HIY, PARTY_D->query_party_fame(fam), NOR);
        write(msg);

	return 1;
}

// ��ʾĳһ�������е���Ա
int dismiss_party(object me, string arg)
{
        string *member;
        string id;
        object user;
        string msg;
        int n;

        if (wiz_level(me) < wiz_level("(arch)"))
                return notify_fail("���Ȩ�޲���������ǿ�н�ɢ���ɡ�\n");

        if (! arg)
                return notify_fail("��Ҫ��ɢ�ĸ����ɣ�\n");

	if (! arrayp(member = PARTY_D->query_members(arg)))
        {
                write("���ڽ�����û��(" + arg + ")����ֺš�\n");
                return 1;
        }

        write("��ǿ�н�ɢ��" + arg + "��\n");
        PARTY_D->dismiss_party(arg);
        return 1;
}


// �����еĳ�޶�������
int sort_hatred(string id1, string id2, mapping hatred)
{
        mixed *d1, *d2;

        if (! arrayp(d1 = hatred[id1]) || sizeof(d1) < 2 || ! intp(d1[1]))
                return 1;

        if (! arrayp(d2 = hatred[id2]) || sizeof(d2) < 2 || ! intp(d2[1]))
                return -1;

        return d2[1] - d1[1];
}

// �������е����н����Ա����
int sort_member(string id1, string id2)
{
        object ob1, ob2;

        ob1 = find_player(id1);
        ob2 = find_player(id2);
        if (! objectp(ob1) && ! objectp(ob2))
                return strcmp(id2, id1);

        if (objectp(ob1) && objectp(ob2))
                return ob2->query("combat_exp") - ob1->query("combat_exp");

        if (objectp(ob1))
                return -1;

        return 1;
}

int help(object me)
{
   	write(@HELP
ָ���ʽ: fparty info [���] | hatred [���] | member [��������] | top

�鿴Ŀǰ�����İ��ɵĸ�����Ϣ�����У�

info   ���鿴�����е������Ա״̬��������
hatred ���鿴���ɵĳ�޶���
member ���鿴ĳ�����ɵĳ�Ա��
top    ���鿴������ɵ�����������

��ʦ���Բ鿴�������ɵ���Ϣ��ֻ��Ҫ�����������ϰ��ɵ����ֻ�
�ǰ����е���ҡ�������ʦ����ʹ�� fparty dismiss ����ǿ�н�ɢ
һ�����ɡ�

see also: team (�������)
HELP );
   	return 1;
}
