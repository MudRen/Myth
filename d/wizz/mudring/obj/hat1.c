// greenhat.c

#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create()
{
        set_name(GRN"��ñ��"NOR, ({ "hat", "maozi" }) );
        set_weight(100000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("treasure", 1);
                set("unit", "��");
                set("long","����һ���˼����µ�ñ�ӣ�������ʱ����ֻ�ô�������\n");
                set("material", "hat");
                set("wear_msg","$N�ܲ���Ը�ش���һ��$n��\n");
                set("remove_msg","$N�ܿ��ֵ�ժ��һ��$n��\n");
                set("armor_prop/armor", 1);
        }
        setup();
}

void init()
{
        add_action ("do_give", "give");
}

int do_give(string arg)
{
        object me, ob, who;
        string wiz, obs, whos;

        me = this_player();
        if (sscanf(arg, "%s to %s", obs, whos) != 2) return 0;
        if (obs != "hat" && obs != "maozi") return 0;
  
        ob = present ("hat", me);
        if (!ob) write ("�ÿ���������û���ͱ���"GRN"��ñ��"NOR"��������\n");
        who = find_player(whos);
        if (!who) write ("û������ˡ�\n");
        if (ob && who) {
                ob->move (who);
                message_vision ("$N�͸�$nһ��"GRN"��ñ��"NOR"����\n", me, who);
        }
        return 1;
}


