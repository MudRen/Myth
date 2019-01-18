// cake.c
// idea from xo lib
// rewritten by mudring Sep/18/2002

#include <ansi.h>
#include <localtime.h>
#define REMON 8  // �·ݣ�ʵ���·ݵ���������ּ�1
#define REDAY 28 // ���� ��20��28Ϊֹ
#define REEXP 200000 // ���һ�㽱����С��Ҫ��exp
inherit ITEM;

string *GetName = ({
"��ɳ�±�",
"�����±�",
"Ҭ���±�",
"�����±�",
"֥���±�",
"���±�",
"���±�",
"��Ƥ�±�",
"�����±�",
"��ζ�±�",
"�����±�",
"Ҭ���±�",
"��Ҷ�±�",
"�����±�",
"�����±�",
"�����±�",
});

varargs string GetColor(int flag)
{
    string color;

    if (flag)
        color = COLOR_D->random_color(4);
    else
    {
        if (random(2))
            color = COLOR_D->random_color(4);
        else
            color = COLOR_D->random_color(3);
    }

    return color;
}

string SetName()
{
    int i = random(sizeof(GetName));

    return (GetColor() + GetName[i] + NOR);

}

void create()
{
    string myName;

    myName=SetName();
    set_name( myName, ({ "cake"}) );
    set("long","һ��СС��" + myName + "��������ģ��ճ�¯�������ȵ��أ�\n");
    set_weight(50); // һ��
    if( clonep() ) 
        set_default_object(__FILE__);
    else 
    {
        set("unit", "��");
        set("value", 5000); // 50 silver one
        set("no_sell","����Ķ����ҿɲ�����\n");
        set("no_get","���±��ԣ�����ȥ�ҷ���ɣ�\n");
        set("no_put","���ղذ���ȥ�ҷ���Ҫ��Ʒ��\n");
        set("no_drop","�ٺ�......����Ķ���������ү������ҪӴ��\n");
        set("no_give","�±�������ͣ�song���ɣ���\n");
    }
    set("is_monitored",1);
    setup();
}

void init()
{
        add_action("do_eat", "eat");
        add_action("do_give", "song");
        add_action("do_open", ({"bai", "open"}));
        add_action("do_write", "write");
}


int do_eat(string arg)
{
    object me, what;
    me = this_player();
    what = this_object();

    if (me->is_busy()) return notify_fail("��������æ���أ�\n");
    if (arg != "cake")
        return notify_fail("�����ʲô��cake������\n");

    if (what->query("mudring/have_gaven")) // �����͵�
    {
        tell_object(me,
            HIM"����"+what->query("mudring/gaven_name")+"�͸�������"+
            "��ϸһ����������һ���ǳ�ϸ��С�죬�㲻������OPEN������������\n"NOR);
            return 1;
    }
    tell_object(me,
    MAG"��������������±��������������ţ�WRITE��\n�����ף�����������͵��ˣ�\n"NOR);
    return 1;
}

int do_give(string arg)
{
    object me, who, what;
    string yourname;
        
    me = this_player();
    what = this_object();

    if (me->is_busy()) return notify_fail("��������æ���أ�\n");
    if (! arg)
        return notify_fail("��Ҫ����Ʒ�±���˭����\n");
    if (! objectp(who = present(arg, environment(me))) )
        return notify_fail("����û������ˡ�\n");
    if (arg == me->query("id"))
        return notify_fail("���Լ�����������\n");
    if (! living(who))
        return notify_fail( who->name() + "���ڿɽ��ܲ�����Ķ�����\n" );
    if (who->query("env/no_accept"))
        return notify_fail( who->name() + "���󲻴�Ը����������Ʒ��\n");

    if (what->query("mudring/have_gaven"))  
        return notify_fail("����±��Ǳ����͸����ѽ����\n");

    what->set("mudring/have_gaven",me->query("id"));
    what->set("mudring/gaven_id",me->query("id"));
    what->set("mudring/gaven_name",me->query("name"));
    tell_object(me,"������"+
        what->query("name") + "����Ʒ�͸���" + who->query("name")+"\n"+
        "���ﲻ��һ������������\n");
    tell_object(who, me->query("name") + "��" + me->query("id") + "��"+
        "��һ��" + what->query("name") + "�͸�����Ϊ�����������Ҹ�����\n");

    MONITOR_D->report_debug_object_msg(me, "�����˸�"+what->query("name")+"�� " + getuid(who));
    MONITOR_D->mudring_log("cake", me, " song "+what->query("name")+" to " + getuid(who));
    what->move(who);
    me->start_busy(5);
    return 1;
}

int do_write(string arg)
{
        object me, what;
        me = this_player();
        what = this_object();

    if (me->is_busy()) return notify_fail("��������æ���أ�\n");
        if (! arg)
            return notify_fail("��Ҫд��ʲô����ף���أ�\n");
/*
        if (me->query("mudring/mooncake"))
            return notify_fail("���Ѿ��͹��±��������ˣ�\n");
*/
/*
        if (strlen(arg) > 60)
            return notify_fail("ף�����ֻ��д��ʮ�����֣�ע���Լ�����Ŷ��\n");
*/
        what->set("mudring/wishes", arg);
/*
        what->set("mudring/gaven_id", me->query("id"));
        what->set("mudring/gaven_name", me->query("name"));
*/
        tell_object(me, "�㽫���е�ף��д��һ��ֽ���ϣ����һ��С��\n");
        tell_object(me, "�㽫"+what->query("name")+"��������һ��С�죬��ֽ�����˽�ȥ��\n");
        tell_object(me, "���"+what->query("name")+"������£��һЩ�����ˣ����������ˣ�\n");
        tell_object(me, "�����ڿ��԰������Ʒ"+what->query("name")+"�͸���song��\n�������͵����ˣ�\n");
                
        me->start_busy(5);
        return 1;
}

int do_open(string arg)
{
    object me, what;
    string color, bless, whoId, whoName;
    mixed lt = localtime(time());

    what = this_object();
    me = this_player();

    if (me->is_busy()) return notify_fail("��������æ���أ�\n");
    if (! arg || arg != "cake")
        return notify_fail("��Ҫ��ʲô��\n");

    whoId = what->query("mudring/gaven_id");
    whoName = what->query("mudring/gaven_name");
    if (! whoId || ! whoName)
        return notify_fail("�Լ�����±�������ʲô��˼�أ�\n");
    bless = RING_DIR"test/format.c"->format_string(what->query("mudring/wishes"), 70, 1);

    color = GetColor(1);
    if (bless)
    {
        tell_object(me,"������ذ����"+what->query("name")+"����������������һ��Сֽ��\n");
        tell_object(me,"��չ��Сֽ������������һ���֣�����չ���Ķ�������......\n");
        tell_object(me,"\n");
        tell_object(me, color +
"�����������������������������������\n" + NOR + GetColor(1)+
"\t"+me->query("name")+"\n"+
NOR+GetColor() +"\n"+bless+"\n"NOR+
"                                                 " + GetColor(1) + whoName + "��" + whoId + "��\n"+
color +"����������������������������������������������������������������������\n"+
"\n"NOR);
/*
        me->delete("mudring/gaven_name");
        me->delete("mudring/gaven_id");
*/
    if (me->query("combat_exp") > REEXP && me->query("mudring/moon_cake") < 5)
    {
        me->add("potential", 2000);
        me->add("mudring/moon_cake", 1);
        tell_object(me,"���Ǳ��������������\n");
        MONITOR_D->report_debug_object_msg(me, "�����˸�"+what->query("name")+"����2000Ǳ�ܣ�");
        MONITOR_D->mudring_log("recake", me, " eat "+what->query("name")+" add pot 2000 ");
    }
    if (lt[LT_MON] == REMON && lt[LT_MDAY] <= REDAY &&
    me->query("mudring/moon_got") < 1 && me->query("combat_exp") > REEXP)
    {
// �����������ｱ��������
// 100n dx����?
        me->add("daoxing", 100000);
        me->add("combat_exp", 20000);
        me->add("mudring/moon_got", 1);
        tell_object(me,"�����Ϊ�����ǿ������\n");
        MONITOR_D->report_debug_object_msg(me, "���õ������ｱ����");
        MONITOR_D->mudring_log("remoon", me, " got moon reward.");
    }
    }
    else
        tell_object(me,"�����������"+what->query("name")+"���������ʲô��û�С�\n");
    what->move("/obj/empty");
    call_out("dest",3);
    me->start_busy(5);
    return 1;
}


void dest()
{
    if (this_object())
        destruct(this_object());
}

