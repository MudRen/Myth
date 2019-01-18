// Item: /d/wizz/mudring/obj/ring.c
// By mudring@sjsh for xianzi......

#include <ansi.h>
#include <net/dns.h>
#include <armor.h>
inherit F_AUTOLOAD;

inherit FINGER;

int do_coupletalk(string msg);
void create()
{
        string color;
        object ob = this_player();
        if ( ! ob->query("color") ) color = MAG;
        else color = ob->query("color");
        set_name( color + "ˮ�����" NOR, ({ "wedding ring", "ring" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "ֻ");
                set("value", 100000);
            set("no_sell", "����ҲҪ������������Լ����ˣ�"); 
                set("material", "gold");
 //               set("armor_type", "married");
 //               set("armor_prop/armor",1);
                set("no_give","���Ҳ���ˣ�");
                set("no_drop",1);
                set("no_get",1);
        }
        setup();
}

int query_autoload()
{
        return 1;
}

void init()
{
            object ob = environment(); 

                if ( (!ob->query("couple/id") || !ob->query("couple/name")) && !wizardp(ob) ) {
                        ob->delete("married");
                        call_out("lost", 1);
                        return;
                }
                set("long", "������"
                        + (ob->query("gender") == "Ů��"?"�๫":"����")
                        + "�͸���Ķ����������"
// 50                          + (ob->query("gender") == "Ů��"?"��":"��")
                        + "����һ��С�֣���"
                        + (ob->query("gender") == "Ů��"?"����ʯ�� ":"���Ĳ��� ")
                        + ob->query("couple/name") + "����\n");
                wear();
add_action("do_coupletalk", "me");
}

void lost()
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

int do_coupletalk(string msg)
  {
        object me, obj;
        string arg;
        me = this_player();
        if(!me->query("married")) return notify_fail("��������\n");
        obj = find_player(me->query("couple/id"));
        if(!obj || (!wizardp(me) && !me->visible(obj)))
                return notify_fail("��İ������ڲ���....\n");
        if( !msg )
        {
                tell_object(me,sprintf(HIM"���ܵ�˵��ʲô�ɣ�\n" NOR));
        }
        else
        {
                write(HIM "�����ĸ������" + me->query("couple/name") + "��" + msg + "\n" NOR);
                tell_object(obj, sprintf( HIM "���%s���ĸ����㣺%s\n" NOR,obj->query("couple/name"), msg)); 
        }
        return 1;
}
