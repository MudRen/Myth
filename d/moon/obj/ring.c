// ring.c
// for marry
// written by mudring

#include <ansi.h>
#include <armor.h>

inherit F_AUTOLOAD;
inherit FINGER;

int CoupleTalk(string msg);

void create()
{
    string color;
    object ob = this_player();

    color = ob->query("color")?ob->query("color"):MAG;

    set_name( color + "ˮ�����"NOR, ({"wedding ring", "ring"}));
    set_weight(100);
    if (clonep())
        set_default_object(__FILE__);
    else
    {
        set("gift_modify/per", 4);
        set("unit", "ֻ");
        set("value", 100000);
        set("material", "gold");
        set("armor_prop/armor", 1);
        set("no_sell", "����ҲҪ������������Լ����ˣ�\n"); 
        set("no_give","���Ҳ���ˣ�\n");
        set("no_copy",1);
        set("no_drop",1);
        set("no_get",1);
    }

    setup();
}

void init()
{
    object ob = environment(); 

    if ((!ob->query("couple/id") || !ob->query("couple/name"))
        && !wizardp(ob))
    {
        ob->delete("married");
        call_out("LostRing", 1);
        return;
    }

    set("long", MAG"\n������"
        + (ob->query("gender") == "Ů��"?"�ɷ�":"����")
        + "�ڻ����ʱ�������ϵĽ���ָ\n����"
        + "����"
        + (ob->query("gender") == "Ů��"?"��":"��")
        + "�����֣���"
        + ob->query("couple/name") + "��\n"NOR);

    wear();

    add_action("CoupleTalk", "me");
}

// can use me verb talk
int CoupleTalk(string msg)
{
    object me;
    object obj;

    me = this_player();

    if (!me->query("married"))
        return notify_fail("��������\n");

    if (me->query("sen") < 200)
        return notify_fail("�´���Ҫ���������Ҫ����\n");

    obj = find_player(me->query("couple/id"));

    if (!obj || (!wizardp(me) && !me->visible(obj)))
        return notify_fail("��İ������ڲ���....\n");

    if (!msg)
    {
        tell_object(me,sprintf(HIM"���ܵ�˵��ʲô�ɣ�\n" NOR));
    }
    else
    {
        me->receive_damage("sen", 20);
        write(HIM "�����ĸ������" + me->query("couple/name") + "��" + msg + "\n" NOR);
        tell_object(obj, sprintf(HIM "���%s���ĸ����㣺%s\n" NOR,
            obj->query("couple/name"), msg)); 
    }

    return 1;
}

void LostRing()
{
    object ob = environment();

    if (userp(ob))
        tell_object(ob, HIB "\n����Լ������һ������Ҫ�Ķ�����ʧ�ˣ�\n\n" NOR);

    destruct(this_object());
}

int unequip()
{
    object ob = environment();

    if (userp(ob) && ob->query("couple/id") && ob->query("couple/name"))
        return notify_fail("�㲻��ж����Ķ������\n");

    return ::unequip();
}

int query_autoload() { return 1; }

