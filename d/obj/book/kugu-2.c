//Cracked by Roath
// �ݹǵ�������Ѫ�顽2
// pickle 9/8/97
#include <ansi.h>
inherit F_UNIQUE;
inherit ITEM;

void init();
void dry(object book);
void create()
{
        set_name("�հ��ʱ�", ({"zhang ben", "zhangben", "book", "shu", "zhang",}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
	set("long",
	"һ���հ׵��ʱ�����һ��͵����ûʲô������\n");
        set("material", "paper");
        set("value", 0);
	set("name_recognized", "�ݹǵ�����");
	set("��", 2);
	set("no_drop", 1);
	set("no_put", 1);
        set("skill", ([
                        "name": "kugu-blade",
                        "exp_required": 50000,
                        "sen_cost": 35,
                        "difficulty": 40,
                        "max_skill": 120,
]) );
        }
	setup();
}

void init()
{
    ::init();
    add_action("do_read", "read");
    add_action("do_read", "study");
    add_action("do_cut", "cut");
    add_action("do_cut", "ge");
    add_action("do_stain", "stain");
    add_action("do_stain", "ran");
    add_action("do_stain", "jin");
}
int do_read(string arg)
{
    object me=this_player(), book=this_object();
    if (!id(arg)) return 0;
    if( environment(book)!=me ) return notify_fail("��Ҫ����������\n");
    if (!book->query("stained"))
    {
        message_vision("$N����"+book->query("name")+"�����о���һ�����\n", this_player());
        tell_object(this_player(), "�հ׵�С������ʲô�ɿ��ģ�\n");
        return 1;
    }
    if (me->query_skill("kugu-blade", 1) < 80)
    {
        tell_object(me, "��Ŀݹǵ���Ϊ�����������������ϵ��书��\n");
        return 1;
    }
    return 0;
}
int do_cut(string arg)
{
    object weapon, me=this_player();

    weapon=me->query_temp("apply/weapon");
    if (!weapon) weapon=me->query_temp("weapon");
    if (!weapon)
        return notify_fail("��ʲô���\n");
    if(weapon->query("id") != "bi shou")
        return notify_fail("����ֲ���Ҫ��ɱ��������ذ�װɡ�\n");
    if (arg != "me" && arg != me->query("id"))
        return notify_fail("�����˭��Ѫ��\n");
    me->receive_wound("kee", random(me->query("str")*me->query("max_kee")/100));
    message_vision("$N��������"+weapon->query("name")+"���ڸ첲�ϸ��˸�С���ӡ�\n", me);
    return 1;
}
int do_stain(string arg)
{
    object book=this_object(),me=this_player();
    if(me->query("eff_kee")>=me->query("max_kee"))
        return notify_fail("�������Լ���Ѫ�ȽϺá�\n");
    if(!id(arg)) return notify_fail("��ҪȾʲô��\n");
    message_vision("$N���˿ڵ�ѪȾ����"+book->query("name")+"��\n", me);
    tell_object(me, book->query("name")+"�Ͻ����Գ���ͼ�κ�С�֡�\n");
    remove_call_out("dry");
    call_out("dry", 300, book);
    book->add("stained", 1);
    book->set_name(RED"��Ѫ�顽"NOR, ({"xue shu", "xueshu", "blood book", "book", "shu"}));
    book->set("long",
"һ������ɫ��С���ӣ����滭����������ȥ�����Ρ�\n");
    return 1;
}
void dry(object book)
{
    book->delete("stained");
    tell_object(environment(book), book->query("name")+"�������ˣ��ֱ�����ʱ����ӡ�\n");
    book->set_name("�հ��ʱ�", ({"zhang ben", "zhangben", "book", "shu", "zhang",}));
    book->set("long",
	"һ���հ׵��ʱ�����һ��͵����ûʲô������\n");
    return;
}
