// suicide.c
// modify by mudring

#include <ansi.h>

inherit F_CLEAN_UP;

private int slow_suicide(object me);
private int halt_suicide(object me);

int main(object me, string arg)
{
    object *inv;
    int i;

    if (me->is_busy())
        return notify_fail("����һ��������û��ɡ�\n");

    inv = deep_inventory(me);
    for (i = 0; i < sizeof(inv); i++)
    {
        if (!userp(inv[i]) && !playerp(inv[i])) continue;
            return notify_fail("�����ϻ��и�������أ��벻��Ҳ��ѽ��\n");
    }

    if (!arg) 
    {
        write("������Ͷ̥��\n");
        return 1;
    }

    if (arg != "-f") 
        return notify_fail("��ɱ�����֣�����Ҫ��Զ����(-f)��������Ͷ̥��\n");

    if (wizardp(me))
        return notify_fail("�벻Ҫ��ɱ����ʦ�ʺţ�лл��\n");
    if (me->query("club_master")) 
        return notify_fail("��Ϊ����쵼����ô����������������\n"); 

    write("��ѡ����Զ��������ɱ��ʽ�������������Ͻ���Զɾ���������\n"
        "���������ȷ���Ļ����������Ĺ������룺");
    input_to("check_password", 1, me, 1);
    return 1;
}

private void check_password(string passwd, object me, int forever)
{
    object link_ob;
    string old_pass;

    link_ob = me->query_temp("link_ob");
    old_pass = link_ob->query("ad_password");
    if (!stringp(old_pass) || crypt(passwd, old_pass) != old_pass)
    {
        write(HIR "���������ע�⣬��ɱ��������������롣\n"NOR);
        return;
    }

    if (forever)
    {
        tell_object(me, HIR "\n�����Ҫ��ɱ�ˣ������ʮ��"
            "���ڲ���ڣ�����������ˡ�\n\n" NOR);
        me->set_temp("suicide/time", time());
        me->set_temp("suicide/last", 0);
        me->set_temp("suicide/from", query_ip_number(me));
        me->start_busy((: slow_suicide, me :),
            (: halt_suicide, me :));
    }
}

private int slow_suicide(object me)
{
    object link_ob;
    int t, s_time;
    string myid, couple;

    if (!objectp(me))
        return 0;

    t = time() - me->query_temp("suicide/time");
    if (t < me->query_temp("suicide/last"))
    {
        me->delete_temp("suicide/");
        return 0;
    }

    if (t < 30)
    {
        if (t - me->query_temp("suicide/last") < 5)
            return 1;

        tell_object(me, HIR "\n�㻹��" + chinese_number(30 - t) +
            "������ϸ����(" HIC "haltֹͣ" HIR ")��\n\n"HIG"        �������߿�վȫ����Ա��Ȱ���벻Ҫ������ɱ!\n" NOR);
        me->set_temp("suicide/last", t / 5 * 5);
        return 1;
    }

    link_ob = me->query_temp("link_ob");
    if (!link_ob || !interactive(me)) return 0;

    log_file("static/suicide",
        sprintf("%s %s commits a suicide from %s\n",
            log_time(), log_id(me),
            me->query_temp("suicide/from")));

    seteuid(getuid());
    write("\n�ðɣ�������:)��\n\n");
    write(HIG"�������,�����񻰻��ǻ�ӭ������!\n"
        HIB"�μ�: 61.141.216.74 8383\n"HIM"�ðɣ�������:( \n");
    CHANNEL_D->do_channel(this_object(), "rumor",
        sprintf("%s��ɱ�ˣ��Ժ�����Ҳ������������ˡ�", me->name()));

    tell_room(environment(me), me->name() +
        "�������ǰ�������̣�������ʧ��...\n", ({me}));

    if (me->query("combat_exp") < 500000)
    {
// suicide not remove name,,, because can recovers...
        NAME_D->remove_name(me->query("name"), me->query("id"));
        rm( link_ob->query_save_file() + __SAVE_EXTENSION__ );
        rm( me->query_save_file() + __SAVE_EXTENSION__ );
    }
    else
    {
        link_ob->save();
        if (!environment(me)->query("no_save") && !me->is_ghost())
            me->set("startroom", base_name(environment(me)));
        if (me->query("club"))
            me->delete("club");

        if (s_time = me->query("suicide_time"))
            me->add("suicide_time", 1);
        else
            me->set("suicide_time", 1);
        if (s_time >= 10)
            s_time = 10;

        me->set("balance",0);
        me->add("potential", - me->query("potential"));
        me->set("daoxing", me->query("daoxing") / 10 * (10-s_time));
        me->set("combat_exp", me->query("combat_exp") / 10 * (10-s_time));
        me->save();

        rename( link_ob->query_save_file() + __SAVE_EXTENSION__, link_ob->query_save_file() + ".s.o" );
        rename( me->query_save_file() + __SAVE_EXTENSION__, me->query_save_file() + ".s.o" );
    }

    myid=me->query("id");

    // remove player home.
    rm( "/data/playerhomes/h_"+myid+ __SAVE_EXTENSION__ );

    // remove mailbox.
    rm( "/data/mail/"+myid[0..0]+"/"+myid+ __SAVE_EXTENSION__ );

    // remove couple's home as well. (the home is registered by the 
    // couple.)
    couple=me->query("coupld/id");
    if(couple)
        rm("/data/mail/"+couple[0..0]+"/"+couple+__SAVE_EXTENSION__);

    destruct(me);

    return 0;
}

private int halt_suicide(object me)
{
    tell_object(me, HIG "�������Ѱ������ͷ��\n" NOR);
    me->delete_temp("suicide");
    return 1;
}

int help (object me)
{
        write(@HELP
ָ���ʽ: suicide [-f]
 
�����Ϊĳ��ԭ���㲻�����, �����ѡ����ɱ.
��ɱ������:
 
suicide    : ����Ͷ̥
suicide -f : ��Զ�ĳ�ȥ�������, ϵͳ��Ҫ����
             ����������ȷ�����.
 
������ѡ�� :)
 
HELP );
        return 1;
}


